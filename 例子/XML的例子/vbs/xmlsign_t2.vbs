Option Explicit

Function GetSignCert()
	Const ForReading = 1
	Dim fso
	Dim stream
	Set fso = CreateObject("Scripting.FileSystemObject")
	Set stream=fso.OpenTextFile("test.cer",ForReading)
	GetSignCert=stream.ReadAll()
	stream.Close
End Function


Dim str

str="<?xml version=" & chr(34) &"1.0" & chr(34) & " encoding=" & chr(34) &"UTF-8" & chr(34)& "?>" & vblf & _
"<form xml:id=" & chr(34) &"form1" & chr(34) &">" & vblf & _
"  <item xml:id=" & chr(34) & "item1" & chr(34) &">" & vblf & _
"    <name>abcd</name>" & vblf & _
"    <value>ÄãºÃ</value>" & vblf & _
"  </item>" & vblf & _
"  <item xml:id=" & chr(34) & "item2" & chr(34) &">" & vblf & _
"    <name>efg</name>" & vblf & _
"    <value>hello</value>" & vblf & _
"  </item>" & vblf & _
"<ds:Signature xmlns:ds=" & chr(34) & "http://www.w3.org/2000/09/xmldsig#" & chr(34) & "/>" & vblf & _
"</form>"

Dim builder
Dim xml
Dim root
Dim nodeList
Dim signNode
Dim xmlsign
Dim ref
Dim refs
Dim signCert

Const NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS		=1
Const NETCA_XMLCOM_SIGNATURE_C14N_WITH_COMMENTS			=2

const NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA1			= &H41
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA256		= &H44
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM2_SM3			= &H53

const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA1			= 1
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256			= 4
const NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM3			= 8

const NETCA_XMLCOM_SIGNATURE_TRANSFORM_BASE64			= &H10
const NETCA_XMLCOM_SIGNATURE_TRANSFORM_XPATH_FILTER		= &H20
const NETCA_XMLCOM_SIGNATURE_TRANSFORM_ENVELOPED_SIGNATURE	= &H30

set builder=CreateObject("NETCA_XMLCOM.Factory")

set xml=builder.CreateXMLDocumentObject()
xml.LoadXML str




set root=xml.GetRootElementNode
set nodeList=root.GetElementList("Signature","http://www.w3.org/2000/09/xmldsig#")

set signNode=nodeList(1)

set xmlsign=builder.CreateXMLSignatureObject()

xmlsign.CanonicalizationMethod=NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS
xmlsign.SignatureMethod=NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA256


set ref=builder.CreateReferenceObject()
ref.DigestMethod=NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256
ref.URI="#item1"

set refs=builder.CreateReferencesObject()
refs.Add ref


set ref=builder.CreateReferenceObject()
ref.DigestMethod=NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256
ref.URI="#signedSignaturePropertiesId"

refs.Add ref


xmlsign.References=refs
xmlsign.HasSigningTime=true
xmlsign.SignedSignaturePropertiesId="signedSignaturePropertiesId"
xmlsign.SetSigningCertificateInfo NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256
signCert=GetSignCert()
xmlsign.Sign signNode, signCert

xmlsign.AddSignatureTimestamp signNode, "https://classatsa.cnca.net/tsa.asp", NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA1

Wscript.Echo xml.Encode

Wscript.Echo xmlsign.SigningTime

Wscript.Echo xmlsign.GetSignatureTimestamp
