Option Explicit

Dim builder
Dim util
Dim xml

set builder=CreateObject("NETCA_XMLCOM.Factory")
set util=CreateObject("NetcaPki.Utilities")

Const NETCAPKI_CP_UTF8=65001


Function LoadXML()
	Dim fs
	Dim data
	Dim str
	Dim xml
	set fs=CreateObject("LittleUtils.BinaryFile")
	data=fs.Read("signature.xml")
	str=util.Decode(data,NETCAPKI_CP_UTF8)
	set xml=builder.CreateXMLDocumentObject()
	xml.LoadXML str
	Set LoadXML=xml
end Function


Const NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS		=1
Const NETCA_XMLCOM_SIGNATURE_C14N_WITH_COMMENTS			=2
Const NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITHOUT_COMMETNTS   =3
Const NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITH_COMMENTS  	=4
Const NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITHOUT_COMMETNTS   	=6
Const NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITH_COMMENTS   		=7



const NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA1			= &H41
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA256		= &H44
Const NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA512		= &H46
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM2_SM3			= &H53

const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA1			= 1
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256			= 4
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA512			= 6
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM3			= 8

const NETCA_XMLCOM_SIGNATURE_TRANSFORM_BASE64			= &H10
const NETCA_XMLCOM_SIGNATURE_TRANSFORM_XPATH_FILTER		= &H20
const NETCA_XMLCOM_SIGNATURE_TRANSFORM_ENVELOPED_SIGNATURE	= &H30

Function GetC14NAlgoName(algo)
	Select Case algo
		Case NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS
			GetC14NAlgoName = "XMLC14N"
		Case NETCA_XMLCOM_SIGNATURE_C14N_WITH_COMMENTS
			GetC14NAlgoName = "XMLC14N With Comments"
		Case NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITHOUT_COMMETNTS
			GetC14NAlgoName = "EXC XMLC14N"
		Case NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITH_COMMENTS
			GetC14NAlgoName = "XMLC14N With Comments"
		Case NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITHOUT_COMMETNTS
			GetC14NAlgoName = "XMLC14N V1.1"
		Case NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITH_COMMENTS
			GetC14NAlgoName = "XMLC14N V1.1 With Comments"
		Case Else
			GetC14NAlgoName =" Unknown XML C14N Algo (" & CSTR(algo) & ")"
	End Select

End Function

Function GetHashAlgoName(algo)
	Select Case algo
		Case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA1
			GetHashAlgoName = "SHA1"
		Case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256
			GetHashAlgoName = "SHA256"
		Case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA512
			GetHashAlgoName = "SHA512"
		Case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM3
			GetHashAlgoName = "SM3"
		Case Else
			GetHashAlgoName =" Unknown Hash Algo (" & CSTR(algo) & ")"
	End Select
End Function


Function GetSignAlgoName(algo)
	Select Case algo
		Case NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA1
			GetSignAlgoName = "SHA1WithRSA"
		Case NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA256
			GetSignAlgoName = "SHA256WithRSA"
		Case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM2_SM3
			GetSignAlgoName = "SM3WithSM2"
		Case Else
			GetSignAlgoName =" Unknown Sign Algo (" & CSTR(algo) & ")"
	End Select
End Function


Function GetTransformAlgoName(algo)
	Select Case algo
		Case NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS
			GetTransformAlgoName = "XMLC14N"
		Case NETCA_XMLCOM_SIGNATURE_C14N_WITH_COMMENTS
			GetTransformAlgoName = "XMLC14N With Comments"
		Case NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITHOUT_COMMETNTS
			GetTransformAlgoName = "EXC XMLC14N"
		Case NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITH_COMMENTS
			GetTransformAlgoName = "XMLC14N With Comments"
		Case NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITHOUT_COMMETNTS
			GetTransformAlgoName = "XMLC14N V1.1"
		Case NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITH_COMMENTS
			GetTransformAlgoName = "XMLC14N V1.1 With Comments"
		Case NETCA_XMLCOM_SIGNATURE_TRANSFORM_BASE64
			GetTransformAlgoName = "Base64"
		Case NETCA_XMLCOM_SIGNATURE_TRANSFORM_XPATH_FILTER
			GetTransformAlgoName = "XPath Filter"
		Case NETCA_XMLCOM_SIGNATURE_TRANSFORM_ENVELOPED_SIGNATURE
			GetTransformAlgoName = "Enveloped Signature"
		Case Else
			GetTransformAlgoName =" Unknown Transform Algo (" & CSTR(algo) & ")"
	End Select

End Function

Sub PrintTransform(tran)
	Wscript.Echo "Transform Algo: " & GetTransformAlgoName(tran.Algorithm)
ENd Sub

Sub PrintTransforms(trans)
	Dim i
	Dim tran
	Dim count
	
	count=trans.Count

	for i=1 to count
		Set tran=trans(i)
		Wscript.Echo "Transform " & CSTR(i) & ":"
		PrintTransform tran
	next

End Sub

Sub PrintReference(ref)
	Dim id
	Dim trans
	id=ref.Id

	if len(id)<>0 then
		Wscript.Echo "Id: " & id
	End if
	Wscript.Echo "URI: " & ref.URI
	Wscript.Echo "Hash Algo: " & GetHashAlgoName(ref.DigestMethod)
	Wscript.Echo "Hash Value: " &  util.BinaryToHex(ref.DigestValue)

	Set trans=ref.Transforms
	if Not(trans Is Nothing) Then
		PrintTransforms trans
	End if
End Sub

Sub PrintReferences(refs)
	Dim i
	Dim count
	Dim ref

	count=refs.Count
	for i=1 to count
		Set ref=refs(i)
		Wscript.Echo "Reference " & CSTR(i) & ":"
		PrintReference ref
	next

End Sub


Sub PrintSignatureTimeStampInfo(xmlsign)
	Dim i
	Dim Count
	Count=xmlsign.GetSignatureTimestampCount()

	for i=1 to Count
		if xmlsign.VerifySignatureTimestamp(i) Then
			Wscript.Echo "VerifySignatureTimestamp " & CSTR(i) & ": OK" 
			Wscript.Echo "SignatureTimestamp " & CSTR(i) & ": " & xmlsign.GetSignatureTimestamp()
		Else
			Wscript.Echo "VerifySignatureTimestamp " & CSTR(i) & ": Fail"  
		End if
	Next

End Sub


Sub PrintCounterSignInfo(xmlsign)
	Dim i
	Dim Count
	Count=xmlsign.GetCounterSignCount()
	for i=1 to Count
		if xmlsign.VerifyCounterSign(i) Then
			Wscript.Echo "VerifyCounterSign " & CSTR(i) & ": OK" 
		Else
			Wscript.Echo "VerifyCounterSign " & CSTR(i) & ": Fail"  
		End if
	Next
End Sub

Sub PrintXMLSignInfo(xmlsign)
	dim c14nalgo
	Dim signalgo
	DIm id
	
	c14nalgo=xmlsign.CanonicalizationMethod
	Wscript.Echo "C14N Algo: " & GetC14NAlgoName(c14nalgo)

	signalgo=xmlsign.SignatureMethod
	Wscript.Echo "Sign Algo: " & GetSignAlgoName(signalgo)

	PrintReferences xmlsign.References

	id=xmlsign.SignatureValueId
	if len(id)<>0 Then
		Wscript.Echo "SignatureValue Id: " & id
	End if

	if xmlsign.HasSigningTime Then
		Wscript.Echo "SigningTime: " & CStr(xmlsign.SigningTime)
	End if

	if xmlsign.HasSigningCertAttribute Then
		Wscript.Echo "Has SigningCert Attribute"
	End if

	PrintSignatureTimeStampInfo xmlsign
	PrintCounterSignInfo xmlsign
end Sub

Dim root
Dim nodeList
Dim signNode
Dim xmlsign
Dim i

Set xml=LoadXML()
set root=xml.GetRootElementNode
set nodeList=root.GetElementList("Signature","http://www.w3.org/2000/09/xmldsig#")

i=1
for each  signNode in nodeList
	set xmlsign=builder.CreateXMLSignatureObject()
	xmlsign.Verify signNode
	Wscript.Echo "verify " & cstr(i) & " ok"
	PrintXMLSignInfo xmlsign
	i=i+1
	Wscript.Echo vbcrlf
next




