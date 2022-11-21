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

str="<?xml version=" & chr(34) & "1.0"& chr(34) &" encoding=" & chr(34) & "UTF-8"& chr(34) &"?>" & vblf & _
"<ds:Signature xmlns:ds=" & chr(34) & "http://www.w3.org/2000/09/xmldsig#" & chr(34) & " Id=" & chr(34) & "signatureId" & chr(34) & ">" & vblf & _
"<ds:SignedInfo>" & vblf & _
"<ds:CanonicalizationMethod Algorithm=" & chr(34) & "http://www.w3.org/TR/2001/REC-xml-c14n-20010315" & chr(34) & "/>" & vblf & _
"<ds:SignatureMethod Algorithm=" & chr(34) & "http://www.w3.org/2001/04/xmldsig-more#rsa-sha256" & chr(34) & "/>" & vblf & _
"<ds:Reference URI=" & chr(34) &"#object" & chr(34) & ">"  & vblf & _
"<ds:Transforms>" & vblf & _
"<ds:Transform Algorithm=" & chr(34) & "http://www.w3.org/2000/09/xmldsig#base64" & chr(34) & "/>" & vblf & _
"</ds:Transforms>" & vblf & _
"<ds:DigestMethod Algorithm=" & chr(34) & "http://www.w3.org/2001/04/xmlenc#sha256" & chr(34) & "/>" & vblf & _
"<ds:DigestValue>iNQmb9TmM40TuEX88olXnSCciXgjuSF9o+Fhk28DFYk=</ds:DigestValue>" & vblf & _
"</ds:Reference>" & vblf & _
"</ds:SignedInfo>" & vblf & _
"<ds:SignatureValue Id=" & chr(34) & "signatureValueId" & chr(34) & ">dpp5jyMSDzzpgaRz/dNyi3YcwH9Qt8daHQCotMkGBPdYM/527dKtCtkbMNyCPWNsO7M7uTKysOE71hgyGDYSnsMBJOK2oI10d93fXzM9Cvu5U4Gf7V0biMyhCuE1pEq9fS9kTQkur4OD4a6kUsf15pTHEoEpTgVsIGjyvFM79Xg=</ds:SignatureValue>" & vblf & _
"<ds:KeyInfo>" & vblf & _
"<ds:X509Data>" & vblf & _
"<ds:X509Certificate>MIIERjCCAy6gAwIBAgIQN3wH3QzqCgUKivMTYCqnrTANBgkqhkiG9w0BAQUFADB7" & vblf & _
"MQswCQYDVQQGEwJDTjEkMCIGA1UEChMbTkVUQ0EgQ2VydGlmaWNhdGUgQXV0aG9y" & vblf & _
"aXR5MR8wHQYDVQQLExZPcmdhbml6YXRpb24gQ2xhc3NBIENBMSUwIwYDVQQDExxO" & vblf & _
"RVRDQSBPcmdhbml6YXRpb24gQ2xhc3NBIENBMB4XDTExMTEyMDE2MDAwMFoXDTE2" & vblf & _
"MTEyMTE1NTk1OVowgagxCzAJBgNVBAYTAkNOMRIwEAYDVQQIEwlHdWFuZ2Rvbmcx" & vblf & _
"KTAnBgNVBAceIF5/Xd5eAl5/Xd5ZJ5BTUxcAMQAzADhT9wA3gfMAOGl8MSMwIQYD" & vblf & _
"VQQKHhpef04cdwF1NVtQVUZSoYuki8FnCZZQUWxT+DEVMBMGA1UEAx4MjXVlTwAo" & vblf & _
"AE8AQQApMR4wHAYJKoZIhvcNAQkBFg96aGFvbWluQGNuY2Eub2EwgZ8wDQYJKoZI" & vblf & _
"hvcNAQEBBQADgY0AMIGJAoGBAJQ7kueKKUEpulET2bspxeu0CsYGKIyFNHmCbOqt" & vblf & _
"N5k+ykUR7SSJj1RwkcMuEEtLVsCtCyeZvRzA3wE8stUJgJ8Z33+M0nljdeE2s72U" & vblf & _
"AauB9F6TZNWuyN9OALhpl6ly+zLce8iu3hakDi5tgT0rqcSEJK404M1SJCz7z0PM" & vblf & _
"/GFFAgMBAAGjggEaMIIBFjAfBgNVHSMEGDAWgBQtCUOC+UpXaoQmsHX3s6vU+dzB" & vblf & _
"bzAdBgNVHQ4EFgQUV4FLSHUaR3wK6Ih0Z8n2Nemhf9cwVwYDVR0gBFAwTjBMBgor" & vblf & _
"BgEEAYGSSAEKMD4wPAYIKwYBBQUHAgEWMGh0dHA6Ly93d3cuY25jYS5uZXQvY3Mv" & vblf & _
"a25vd2xlZGdlL3doaXRlcGFwZXIvY3BzLzAaBgNVHREEEzARgQ96aGFvbWluQGNu" & vblf & _
"Y2Eub2EwDAYDVR0TAQH/BAIwADAOBgNVHQ8BAf8EBAMCBsAwQQYDVR0fBDowODA2" & vblf & _
"oDSgMoYwaHR0cDovL2NsYXNzYWNhMS5jbmNhLm5ldC9jcmwvT3JnYW5pemF0aW9u" & vblf & _
"Q0EuY3JsMA0GCSqGSIb3DQEBBQUAA4IBAQAMdAeILBXA6FKxOs7dQYatDaNhjVVi" & vblf & _
"bDftdGhimHyMr/ZuIL/dBGxhvL0JPG+eBE4OG2r3A3VGllLGp1nJCyyM7/wT3UE8" & vblf & _
"m5bsz/H6CUXPnmCepXqNLZ1pVaavN7teWqAfQv4DdOHTEmIRw8i3qazAzOv4VvbK" & vblf & _
"8kdLJsaB8JnITsYDGbAEKJ6xbTanYvPulPue678qWHIDwMlc/Cq669BUgEBGhOGi" & vblf & _
"1XR4/FiUHEx6VvbMHfOhws+WYEHEjoipsNH4ks3TBFrfAVVrsuT8Zab4kFmX6U60" & vblf & _
"wwIgGP/0dVEANA+YLPnyxa8j2iahhMHvtxc1EnKGVnGO/cg1aEu+GcPZ</ds:X509Certificate>" & vblf & _
"</ds:X509Data>" & vblf & _
"</ds:KeyInfo><ds:Object Id=" & chr(34) & "object" & chr(34) & ">YWJjZA==</ds:Object>" & vblf & _
"</ds:Signature>"

Dim builder
Dim xml
Dim root
Dim nodeList
Dim signNode
Dim xmlsign
Dim ref
Dim refs
Dim signCert
Dim param

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

xmlsign.Verify signNode
Wscript.Echo "verify ok"

signCert=GetSignCert()

param="{" & _
	chr(34) & "C14NAlgo" & chr(34) & ":" & chr(34) & "C14N" & chr(34) & ","  & _
	chr(34) & "SignAlgo" & chr(34) & ":" & chr(34) & "Sha256WithRSA" & chr(34) & ","  & _
	chr(34) & "References" & chr(34) & ":"  & _
		"["  & _
			"{" & _
			chr(34) & "HashAlgo" & chr(34) & ":" & chr(34) & "Sha512" & chr(34) & ","  & _
			chr(34) & "URI" & chr(34) & ":" & chr(34) & "#signedSignaturePropertiesId" & chr(34)   & _
			"}" & _
		"]," & _	
		chr(34) & "XAdES" & chr(34) & ":"  & _
			"{"  & _
			chr(34) & "HasSigningTime" & chr(34) & ":true,"  & _
			chr(34) & "SignedSignaturePropertiesId" & chr(34) & ":" & chr(34) & "signedSignaturePropertiesId" & chr(34) & ","  & _
			chr(34) & "SigningCertificate" & chr(34) & ":" & _
				"{"  & _
				chr(34) & "HashAlgo" & chr(34) & ":" & chr(34) & "Sha256" & chr(34) & _
				"}"   & _
			"}" & _
		"}"

xmlsign.CounterSign signNode,signCert, param,NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256

Wscript.Echo xml.Encode


