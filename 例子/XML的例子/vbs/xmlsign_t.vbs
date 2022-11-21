Option Explicit

Dim str



Dim builder
Dim xml
Dim root
Dim nodeList
Dim signNode
Dim xmlsign
Dim ref
Dim refs

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


str="<?xml version=" & chr(34) & "1.0" & chr(34) & " encoding=" & chr(34) &"UTF-8" & chr(34) & "?>" & vblf & _
"<ds:Signature xmlns:ds=" & chr(34) &"http://www.w3.org/2000/09/xmldsig#" &chr(34) &" Id=" &chr(34) & "_F9F36F07-475E-38F4-BD08-FCE4ACA5A72F" & chr(34) & ">" & vblf & _
"<ds:SignedInfo>" & vblf & _
"<ds:CanonicalizationMethod Algorithm=" & chr(34) &"http://www.w3.org/TR/2001/REC-xml-c14n-20010315" & chr(34) & "/>" & vblf & _
"<ds:SignatureMethod Algorithm=" & chr(34) & "http://www.w3.org/2000/09/xmldsig#rsa-sha1" & chr(34) & "/>" & vblf & _
"<ds:Reference URI=" & chr(34) & "#object" & chr(34) & ">"& vblf  & _
"<ds:Transforms>" & vblf & _
"<ds:Transform Algorithm=" & chr(34) & "http://www.w3.org/2000/09/xmldsig#base64" & chr(34) & "/>" & vblf & _
"</ds:Transforms>" & vblf & _
"<ds:DigestMethod Algorithm=" & chr(34) & "http://www.w3.org/2000/09/xmldsig#sha1" & chr(34) & "/>" & vblf & _
"<ds:DigestValue>gf6L/odXbD7LIkJvjleEc4KRes8=</ds:DigestValue>"& vblf  & _
"</ds:Reference>"& vblf  & _
"<ds:Reference URI="& chr(34) & "#signatureprop" & chr(34) & ">"& vblf  & _
"<ds:DigestMethod Algorithm=" & chr(34) & "http://www.w3.org/2000/09/xmldsig#sha1" & chr(34) & "/>"& vblf  & _
"<ds:DigestValue>1VDy+Df3FsiIxUdRP9wHXijHxA8=</ds:DigestValue>"& vblf  & _
"</ds:Reference>"& vblf  & _
"</ds:SignedInfo>"& vblf  & _
"<ds:SignatureValue>CoF3Pbd3up37aCHLaJ4KsEGY3WWG1qLjiXWVfj3JClXfJ7PJEw7p4gkYeUrHNXGblFKHP7GEW0k9O4RDTJbWvTczYmBMyPA+cmFMqxQ/5Q8bI/CYBipmXHTI1ChD/zjEBUFfS3bMnYIvi2DUsMGNsVRPF6YxCvnK2X1Bgg6Fkx4=</ds:SignatureValue>" & vblf & _
"<ds:KeyInfo>"& vblf  & _
"<ds:X509Data>"& vblf  & _
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
"</ds:KeyInfo>" & vblf & _
"<ds:Object Id=" & chr(34) & "object" & chr(34) & ">YWJjZA==</ds:Object>" & vblf & _
"<ds:Object>" & vblf & _
"<xa:QualifyingProperties xmlns:xa=" & chr(34) & "http://uri.etsi.org/01903/v1.3.2#" & chr(34) & " Target=" & chr(34) &"#_F9F36F07-475E-38F4-BD08-FCE4ACA5A72F" & chr(34) &">" & vblf & _
"<xa:SignedProperties>" & vblf & _
"<xa:SignedSignatureProperties Id=" & chr(34) & "signatureprop" & chr(34) & ">" & vblf & _
"<xa:SigningTime>2012-12-19T06:32:18Z</xa:SigningTime>" & vblf & _
"<xa:SigningCertificate>" & vblf & _
"<xa:Cert>" & vblf & _
"<xa:CertDigest>" & vblf & _
"<ds:DigestMethod Algorithm="& chr(34) & "http://www.w3.org/2001/04/xmlenc#sha512" & chr(34) & "/>" & vblf & _
"<ds:DigestValue>Gbbq1Rocl3CeugoZ4ZNH4rIPwPseJr2zVOd16jlNguurCUdZyC0n7IuaCjQNmw+DdIQUX7wUArflzn9EIvzNXw==</ds:DigestValue>" & vblf & _
"</xa:CertDigest>" & vblf & _
"<xa:IssuerSerial>" & vblf & _
"<ds:X509IssuerName>CN=NETCA Organization ClassA CA,OU=Organization ClassA CA,O=NETCA Certificate Authority,C=CN</ds:X509IssuerName>" & vblf & _
"<ds:X509SerialNumber>73751544068916588926062945532501469101</ds:X509SerialNumber>" & vblf & _
"</xa:IssuerSerial>" & vblf & _
"</xa:Cert>" & vblf & _
"</xa:SigningCertificate>" & vblf & _
"</xa:SignedSignatureProperties>" & vblf & _
"</xa:SignedProperties></xa:QualifyingProperties>" & vblf & _
"</ds:Object>" & vblf & _
"</ds:Signature>"

set builder=CreateObject("NETCA_XMLCOM.Factory")

set xml=builder.CreateXMLDocumentObject()
xml.LoadXML str


set root=xml.GetRootElementNode
set nodeList=root.GetElementList("Signature","http://www.w3.org/2000/09/xmldsig#")

set signNode=nodeList(1)

set xmlsign=builder.CreateXMLSignatureObject()
xmlsign.Verify signNode
Wscript.Echo "verify ok"

xmlsign.AddSignatureTimestamp signNode, "https://classatsa.cnca.net/tsa.asp", NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA1

Wscript.Echo xml.Encode

Wscript.Echo xmlsign.GetSignatureTimestamp
