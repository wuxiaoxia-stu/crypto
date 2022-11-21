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
"<ds:Signature xmlns:ds=" & chr(34) & "http://www.w3.org/2000/09/xmldsig#" & chr(34) & ">" & vblf & _
"<ds:Object Id=" & chr(34) &"object" & chr(34) & ">YWJjZA==</ds:Object>" & vblf & _
"</ds:Signature>"

Dim builder
Dim xml
Dim root
Dim nodeList
Dim signNode
Dim xmlsign
Dim ref
Dim refs
Dim transform
Dim transforms
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



set transform=builder.CreateTransformObject()
transform.Algorithm=NETCA_XMLCOM_SIGNATURE_TRANSFORM_BASE64

set transforms=builder.CreateTransformsObject()
transforms.Add transform

set ref=builder.CreateReferenceObject()
ref.DigestMethod=NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256
ref.URI="#object"
ref.Transforms=transforms

set refs=builder.CreateReferencesObject()
refs.Add ref

xmlsign.References=refs

signCert=GetSignCert()
xmlsign.Sign signNode, signCert


Wscript.Echo xml.Encode


