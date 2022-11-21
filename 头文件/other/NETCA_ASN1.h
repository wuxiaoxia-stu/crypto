#ifndef NETCA_ASN1_INCLUDE_H
#define NETCA_ASN1_INCLUDE_H

#include "NETCA_ASN1_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

#define NETCA_ASN1_LENGTH_INDEFINITE	-1L
#define NETCA_ASN1_LENGTH_ERROR			-2L


#define NETCA_ASN1_TAGCLASS_UNIVERSAL	0x00
#define NETCA_ASN1_TAGCLASS_APPLICATION	0x40
#define NETCA_ASN1_TAGCLASS_CONTEXT		0x80
#define NETCA_ASN1_TAGCLASS_PRIVATE		0xC0

#define NETCA_ASN1_TAG_PRIMITIVE		0x00
#define NETCA_ASN1_TAG_CONSTRUCTED		0x20


#define NETCA_ASN1_TAG_BOOLEAN			0x01
#define NETCA_ASN1_TAG_INTEGER			0x02
#define NETCA_ASN1_TAG_BITSTRING		0x03
#define NETCA_ASN1_TAG_OCTETSTRING		0x04
#define NETCA_ASN1_TAG_NULL				0x05
#define NETCA_ASN1_TAG_OID				0x06
#define NETCA_ASN1_TAG_OBJECTDESC		0x07
#define NETCA_ASN1_TAG_EXTERNAL			0x08
#define NETCA_ASN1_TAG_INSTANCEOF		0x08
#define NETCA_ASN1_TAG_REAL				0x09
#define NETCA_ASN1_TAG_ENUM				0x0A
#define NETCA_ASN1_TAG_EMBEDDEDPDV		0x0B
#define NETCA_ASN1_TAG_UTF8STRING		0x0C
#define NETCA_ASN1_TAG_ROID				0x0D
#define NETCA_ASN1_TAG_TIME				0x0E
#define NETCA_ASN1_TAG_SEQUENCE			0x10
#define NETCA_ASN1_TAG_SEQUENCEOF		0x10
#define NETCA_ASN1_TAG_SET				0x11
#define NETCA_ASN1_TAG_SETOF			0x11
#define NETCA_ASN1_TAG_NUMERICSTRING	0x12
#define NETCA_ASN1_TAG_PRINTABLESTRING	0x13
#define NETCA_ASN1_TAG_TELETEXSTRING	0x14
#define NETCA_ASN1_TAG_VIDEOTEXSTRING	0x15
#define NETCA_ASN1_TAG_IA5STRING		0x16
#define NETCA_ASN1_TAG_UTCTIME			0x17
#define NETCA_ASN1_TAG_GENTIME			0x18
#define NETCA_ASN1_TAG_GRAPHICSTRING	0x19
#define NETCA_ASN1_TAG_VISIBLESTRING	0x1A
#define NETCA_ASN1_TAG_GENERALSTRING	0x1B
#define NETCA_ASN1_TAG_UNIVERSALSTRING	0x1C
#define NETCA_ASN1_TAG_BMPSTRING		0x1E
#define NETCA_ASN1_TAG_DATE				0x1F
#define NETCA_ASN1_TAG_TIMEOFDATE		0x20
#define NETCA_ASN1_TAG_DATETIME			0x21
#define NETCA_ASN1_TAG_DURATION			0x22

#define NETCA_ASN1_POS_FROM_START		1
#define NETCA_ASN1_POS_FROM_CURRENT		2

#define NETCA_ASN1_TYPE_EOC						0
#define NETCA_ASN1_TYPE_BOOLEAN					1
#define NETCA_ASN1_TYPE_INTEGER					2
#define NETCA_ASN1_TYPE_BIT_STRING				3
#define NETCA_ASN1_TYPE_OCTET_STRING			4
#define NETCA_ASN1_TYPE_NULL					5
#define NETCA_ASN1_TYPE_OID						6
#define NETCA_ASN1_TYPE_ENUM					7
#define NETCA_ASN1_TYPE_STRING					8
#define NETCA_ASN1_TYPE_UTF8_STRING				9
#define NETCA_ASN1_TYPE_NUMERIC_STRING			10
#define NETCA_ASN1_TYPE_PRINTABLE_STRING		11
#define NETCA_ASN1_TYPE_TELETEX_STRING			12
#define NETCA_ASN1_TYPE_VIDEOTEX_STRING			13
#define NETCA_ASN1_TYPE_IA5_STRING				14
#define NETCA_ASN1_TYPE_GRAPHIC_STRING			15
#define NETCA_ASN1_TYPE_VISIBLE_STRING			16
#define NETCA_ASN1_TYPE_GENERAL_STRING			17
#define NETCA_ASN1_TYPE_UNIVERSAL_STRING		18
#define NETCA_ASN1_TYPE_BMP_STRING				19
#define NETCA_ASN1_TYPE_X509_TIME				20
#define NETCA_ASN1_TYPE_UTCTIME					21
#define NETCA_ASN1_TYPE_GENTIME					22
#define NETCA_ASN1_TYPE_ANY						23
#define NETCA_ASN1_TYPE_SEQUENCEOF_ANY			24
#define NETCA_ASN1_TYPE_SEQUENCEOF_ANY_NOTEMPTY	25
#define NETCA_ASN1_TYPE_SETOF_ANY				26
#define NETCA_ASN1_TYPE_SETOF_ANY_NOTEMPTY		27
#define NETCA_ASN1_TYPE_X500_CONTEXT			28
#define NETCA_ASN1_TYPE_X500_ATTRTYPE_DISTVALUE	29
#define NETCA_ASN1_TYPE_PKIX_ATTRTYPEANDVALUE	30
#define NETCA_ASN1_TYPE_X500_RDN				31
#define NETCA_ASN1_TYPE_X500_NAME				32
#define NETCA_ASN1_TYPE_X509_ALGOID				33
#define NETCA_ASN1_TYPE_X509_VALIDITY			34
#define NETCA_ASN1_TYPE_X509_SUBJECT_PUBKEY_INFO	35
#define NETCA_ASN1_TYPE_X509_EXTENSION			36
#define NETCA_ASN1_TYPE_X509_EXTENSIONS			37
#define NETCA_ASN1_TYPE_X509_TBSCERTIFICATE		38
#define NETCA_ASN1_TYPE_X509_CERTIFICATE		39
#define NETCA_ASN1_TYPE_X509_TBSCRL				40
#define NETCA_ASN1_TYPE_X509_CRL				41
#define NETCA_ASN1_TYPE_X500_ATTRIBUTE			42
#define NETCA_ASN1_TYPE_PKCS_ATTRIBUTE			43
#define NETCA_ASN1_TYPE_PKCS_ATTRIBUTES			44
#define NETCA_ASN1_TYPE_PKCS10_CERTREQINFO		45
#define NETCA_ASN1_TYPE_PKCS10_CERTREQ			46
#define NETCA_ASN1_TYPE_X500_DIRECTORY_STRING	47
#define NETCA_ASN1_TYPE_X500_UUIDPAIR			48
#define NETCA_ASN1_TYPE_X500_POSTALADDRESS		49
#define NETCA_ASN1_TYPE_X500_TELEXNUMBER		50
#define NETCA_ASN1_TYPE_X500_NAMEANDOPTIONALUID	51
#define NETCA_ASN1_TYPE_PKCS9_STRING			52
#define NETCA_ASN1_TYPE_SMIMECAPABILITY			53
#define NETCA_ASN1_TYPE_SMIMECAPABILITIES		54
#define NETCA_ASN1_TYPE_X509_CERTPAIR			55
#define NETCA_ASN1_TYPE_PKCS1_RSAPUBLICKEY		56
#define NETCA_ASN1_TYPE_DIGESTINFO				57
#define NETCA_ASN1_TYPE_DSS_SIGVALUE			58
#define NETCA_ASN1_TYPE_ECDSA_SIGVALUE			59
#define NETCA_ASN1_TYPE_DSS_PARAMS				60
#define NETCA_ASN1_TYPE_INSTANCEOF_TYPEID		61
#define NETCA_ASN1_TYPE_X509_EDIPARTYNAME		62
#define NETCA_ASN1_TYPE_X509_GENERALNAME		63
#define NETCA_ASN1_TYPE_X509_GENERALNAMES		64
#define NETCA_ASN1_TYPE_X509_AKID				65
#define NETCA_ASN1_TYPE_X509_EXKEYUSAGE			66
#define NETCA_ASN1_TYPE_X509_PRIVKEYUSAGEPERIOD	67
#define NETCA_ASN1_TYPE_X509_POLICYQUALIFIERINFO	68
#define NETCA_ASN1_TYPE_X509_POLICYINFO			69
#define NETCA_ASN1_TYPE_X509_CERTPOLICIES		70
#define NETCA_ASN1_TYPE_PKIX_DISPLAYTEXT		71
#define NETCA_ASN1_TYPE_PKIX_NOTICEREF			72
#define NETCA_ASN1_TYPE_PKIX_USERNOTICE			73
#define NETCA_ASN1_TYPE_X509_POLICY_MAPPINGS	74
#define NETCA_ASN1_TYPE_X509_SUBJECT_DIRATTRS	75
#define NETCA_ASN1_TYPE_X509_BASIC_CONSTRAINTS	76
#define NETCA_ASN1_TYPE_X509_GENERAL_SUBTREE	77
#define NETCA_ASN1_TYPE_X509_GENERAL_SUBTREES	78
#define NETCA_ASN1_TYPE_X509_NAMEFORMS			79
#define NETCA_ASN1_TYPE_X509_NAME_CONSTRAINTS	80
#define NETCA_ASN1_TYPE_PKIX_NAME_CONSTRAINTS	81
#define NETCA_ASN1_TYPE_X509_POLICY_CONSTRAINTS	82
#define NETCA_ASN1_TYPE_X509_DPNAME				83
#define NETCA_ASN1_TYPE_X509_DISTPOINT			84
#define NETCA_ASN1_TYPE_X509_CRLDP				85
#define NETCA_ASN1_TYPE_PKIX_ACCESS_DESP		86
#define NETCA_ASN1_TYPE_PKIX_AIA				87
#define NETCA_ASN1_TYPE_PKIX_IDP				88
#define NETCA_ASN1_TYPE_X509_AAIDP				89
#define NETCA_ASN1_TYPE_RELATIVE_OID			90
#define NETCA_ASN1_TYPE_NETCA_OLDCERTTHUMBS		91
#define NETCA_ASN1_TYPE_CRL_REVOKEDCERTITEM		92
#define NETCA_ASN1_TYPE_NETCA_CERTSTORE_PRIVKEYATTR		93
#define NETCA_ASN1_TYPE_NETCA_CERTSTORE_ATTR			94
#define NETCA_ASN1_TYPE_NETCA_CERTSTORE_ATTRLIST		95
#define NETCA_ASN1_TYPE_NETCA_CERTSTORE_CERTWITHATTR		96
#define NETCA_ASN1_TYPE_NETCA_CERTSTORE				97
#define NETCA_ASN1_TYPE_NETCA_CERTSTORE_PRIVKEYATTR_KEYID	98
#define NETCA_ASN1_TYPE_PKCS1_RSAPRIVATEKEY		99
#define NETCA_ASN1_TYPE_PKCS1_RSAES_OAEP_PARAMS	100
#define NETCA_ASN1_TYPE_PKCS1_RSASSA_PSS_PARAMS	101
#define NETCA_ASN1_TYPE_PKCS3_DH_PARAMETER		102
#define NETCA_ASN1_TYPE_PKCS8_PRIVATEKEY_INFO	103
#define NETCA_ASN1_TYPE_PKCS8_ENC_PRIVATEKEY_INFO	104
#define NETCA_ASN1_TYPE_PKCS5_PBKDF2_PARAMS		105
#define NETCA_ASN1_TYPE_PKCS5_PBEPARAM			106
#define NETCA_ASN1_TYPE_PKCS5_PBES2_PARAMS		107
#define NETCA_ASN1_TYPE_PKCS5_PBMAC1_PARAMS		108
#define NETCA_ASN1_TYPE_RC2CBC_PARAM			109
#define NETCA_ASN1_TYPE_RC5CBC_PARAM			110
#define NETCA_ASN1_TYPE_PKCS7_CONTENT_INFO		111
#define NETCA_ASN1_TYPE_PKCS12_MACDATA			112
#define NETCA_ASN1_TYPE_PKCS12_PFX				113
#define NETCA_ASN1_TYPE_PKCS12_AUTHSAFE			114
#define NETCA_ASN1_TYPE_PKCS12_SAFEBAG			115
#define NETCA_ASN1_TYPE_PKCS12_SAFEBAGS			116
#define NETCA_ASN1_TYPE_PKCS12_CERTBAG			117
#define NETCA_ASN1_TYPE_PKCS12_CRLBAG			118
#define NETCA_ASN1_TYPE_PKCS12_SECRETBAG		119
#define NETCA_ASN1_TYPE_PKCS12_PBEPARAMS		120
#define NETCA_ASN1_TYPE_PKCS7_DIGESTEDDATA		121
#define NETCA_ASN1_TYPE_PKCS7_ISSUERANDSN		122
#define NETCA_ASN1_TYPE_CMS_SIGNERID			123
#define NETCA_ASN1_TYPE_CMS_SIGNERINFO			124
#define NETCA_ASN1_TYPE_CMS_SIGNERINFOS			125
#define NETCA_ASN1_TYPE_CMS_ALGOIDS				126
#define NETCA_ASN1_TYPE_CMS_OTHERCERTFORMAT		127
#define NETCA_ASN1_TYPE_CMS_OTHERREVINFOFORMAT	128
#define NETCA_ASN1_TYPE_CMS_CERTCHOICE			129
#define NETCA_ASN1_TYPE_CMS_REVINFOCHOICE		130
#define NETCA_ASN1_TYPE_CMS_CERTSET				131
#define NETCA_ASN1_TYPE_CMS_REVINFOS			132
#define NETCA_ASN1_TYPE_PKCS7_SIGNEDDATA		133
#define NETCA_ASN1_TYPE_CMS_SIGNEDDATA			134
#define NETCA_ASN1_TYPE_X500DNVALUEWITHCONTEXTITEM		135
#define NETCA_ASN1_TYPE_X500ATTRVALUEWITHCONTEXTITEM	136
#define NETCA_ASN1_TYPE_X509_POLICYQUALIFIERINFOS	137
#define NETCA_ASN1_TYPE_PKIX_NOTICENUMBERS		138
#define NETCA_ASN1_TYPE_X509_POLICY_MAPPING		139
#define NETCA_ASN1_TYPE_CRL_REVOKEDCERTS		140
#define NETCA_ASN1_TYPE_X500_CONTEXTLIST		141
#define NETCA_ASN1_TYPE_X500DNVALUESWITHCONTEXT	142
#define NETCA_ASN1_TYPE_X500ATTRVALUESWITHCONTEXT	143
#define NETCA_ASN1_TYPE_PKCS1_OTHERPRIMEINFO	144
#define NETCA_ASN1_TYPE_PKCS1_OTHERPRIMEINFOS	145
#define NETCA_ASN1_TYPE_PKCS5_PBKDF2_PARAMS_SALT	146
#define NETCA_ASN1_TYPE_CMS_ENCAPSULTED_CONTENT_INFO	147
#define NETCA_ASN1_TYPE_CMS_ENCRYPTED_CONTENT_INFO	148
#define NETCA_ASN1_TYPE_CMS_ENCRYPTED_DATA		149
#define NETCA_ASN1_TYPE_CMS_ORIGINATORINFO		150
#define NETCA_ASN1_TYPE_CMS_KEYTRANSRECIPIENTINFO		151
#define NETCA_ASN1_TYPE_CMS_ORGIDORKEY			152
#define NETCA_ASN1_TYPE_CMS_OTHERKEYATTRIBUTE	153
#define NETCA_ASN1_TYPE_CMS_RECIPIENTKEYID		154
#define NETCA_ASN1_TYPE_CMS_KEYAGREERECIPIENTID	155
#define NETCA_ASN1_TYPE_CMS_RECIPIENTENCKEY		156
#define NETCA_ASN1_TYPE_CMS_RECIPIENTENCKEYS	157
#define NETCA_ASN1_TYPE_CMS_KEYAGREERECIPIENTINFO		158
#define NETCA_ASN1_TYPE_CMS_KEKRECIPIENTINFO	159
#define NETCA_ASN1_TYPE_CMS_PWDRECIPIENTINFO	160
#define NETCA_ASN1_TYPE_CMS_OTHERRECIPIENTINFO	161
#define NETCA_ASN1_TYPE_CMS_RECIPIENTINFO		162
#define NETCA_ASN1_TYPE_CMS_RECIPIENTINFOS		163
#define NETCA_ASN1_TYPE_CMS_ENVELOPEDDATA		164
#define NETCA_ASN1_TYPE_CMS_AUTHDATA			165
#define NETCA_ASN1_TYPE_DH_KEYSPECINFO			166
#define NETCA_ASN1_TYPE_DH_OTHERINFO			167
#define NETCA_ASN1_TYPE_OCSP_CERTID				168
#define NETCA_ASN1_TYPE_OCSP_REQUEST			169
#define NETCA_ASN1_TYPE_OCSP_REQUESTLIST		170
#define NETCA_ASN1_TYPE_OCSP_TBSREQUEST			171
#define NETCA_ASN1_TYPE_OCSP_SIGNATURE			172
#define NETCA_ASN1_TYPE_OCSP_OCSPREQUEST		173
#define NETCA_ASN1_TYPE_OCSP_RESPONSEBYTES		174
#define NETCA_ASN1_TYPE_OCSP_OCSPRESPONSE		175
#define NETCA_ASN1_TYPE_OCSP_RESPONDERID		176
#define NETCA_ASN1_TYPE_OCSP_REVOKEDINFO		177
#define NETCA_ASN1_TYPE_OCSP_CERTSTATUS			178
#define NETCA_ASN1_TYPE_OCSP_SINGLERESPONSE		179
#define NETCA_ASN1_TYPE_OCSP_RESPONSES			180
#define NETCA_ASN1_TYPE_OCSP_RESPONSEDATA		181
#define NETCA_ASN1_TYPE_OCSP_BASICOCSPRESPONSE	182
#define NETCA_ASN1_TYPE_OCSP_CRLID				183
#define NETCA_ASN1_TYPE_OCSP_SERVICELOCATOR		184
#define NETCA_ASN1_TYPE_OCSP_PREFERSIGNALGO		185
#define NETCA_ASN1_TYPE_TSP_MESSAGE_IMPRINT		186
#define NETCA_ASN1_TYPE_TSP_TIMESTAMPREQ		187
#define NETCA_ASN1_TYPE_PKIFREETEXT				188
#define NETCA_ASN1_TYPE_TSP_PKISTATUSINFO		189
#define NETCA_ASN1_TYPE_TSP_TIMESTAMPRESP		190
#define NETCA_ASN1_TYPE_TSP_ACCURACY			191
#define NETCA_ASN1_TYPE_TSP_TSTINFO				192
#define NETCA_ASN1_TYPE_ESSISSUERSERIAL			193
#define NETCA_ASN1_TYPE_ESSCERTID				194
#define NETCA_ASN1_TYPE_ESSCERTIDV2				195
#define NETCA_ASN1_TYPE_ESSCERTIDS				196
#define NETCA_ASN1_TYPE_ESSCERTIDV2S			197
#define NETCA_ASN1_TYPE_X509_POLICYINFOS		198
#define NETCA_ASN1_TYPE_ESSSIGNINGCERT			199
#define NETCA_ASN1_TYPE_ESSSIGNINGCERTV2		200
#define NETCA_ASN1_TYPE_ECPKPARAMETERS			201
#define NETCA_ASN1_TYPE_ECPRIVATEKEY			202
#define NETCA_ASN1_TYPE_SM2CIPHER				203
#define NETCA_ASN1_TYPE_SM2ENVELOPEDKEYPAIR		204
#define NETCA_ASN1_TYPE_RSAENVELOPEDKEYPAIR		205
#define NETCA_ASN1_TYPE_INNERENVELOPEDKEYPAIR	206
#define NETCA_ASN1_TYPE_ENVELOPEDKEYPAIR		207
#define NETCA_ASN1_TYPE_SPCINDIRECTDATACONTENT	208
#define NETCA_ASN1_TYPE_SPCSERIALIZEDOBJECT		209
#define NETCA_ASN1_TYPE_SPCSTRING				210
#define NETCA_ASN1_TYPE_SPCLINK					211
#define NETCA_ASN1_TYPE_SPCPEIMAGEDATA			212
#define NETCA_ASN1_TYPE_SPCSPOPUSINFO			213
#define NETCA_ASN1_TYPE_SPCATTRTYPEANDOPTVALUE	214
#define NETCA_ASN1_TYPE_AUTHENTICODE_TIMESTAMPREQ	215
#define NETCA_ASN1_TYPE_SMIME_ENCRYPTION_KEY_PREFERENCE	216
#define NETCA_ASN1_TYPE_IDENTITYCODE			217
#define NETCA_ASN1_TYPE_DHSIGSTATIC				218
#define NETCA_ASN1_TYPE_TYPE_OF_BIOMETRICDATA	219
#define NETCA_ASN1_TYPE_BIOMETRICDATA			220
#define NETCA_ASN1_TYPE_QCSTATEMENT				221
#define NETCA_ASN1_TYPE_QCSTATEMENTS			222
#define NETCA_ASN1_TYPE_NAMEREGISTRATIONAUTHORITIES	223
#define NETCA_ASN1_TYPE_SEMANTICSINFORMATION	224
#define NETCA_ASN1_TYPE_OTHERHASHALGANDVALUE	225
#define NETCA_ASN1_TYPE_OTHERHASH				226
#define NETCA_ASN1_TYPE_OTHERCERTID				227
#define NETCA_ASN1_TYPE_OTHERCERTIDS			228
#define NETCA_ASN1_TYPE_OTHERSIGNINGCERT		229
#define NETCA_ASN1_TYPE_SIGNATUREPOLICYID		230
#define NETCA_ASN1_TYPE_SIGNATUREPOLICYIDENTIFIER	231
#define NETCA_ASN1_TYPE_COMMITMENTTYPEINDICATION	232
#define NETCA_ASN1_TYPE_SIGNERLOCATION			233
#define NETCA_ASN1_TYPE_CRLIDENTIFIER			234
#define NETCA_ASN1_TYPE_CRLVALIDATEDID			235
#define NETCA_ASN1_TYPE_CRLVALIDATEDIDS			236
#define NETCA_ASN1_TYPE_CRLLISTID				237
#define NETCA_ASN1_TYPE_OCSPIDENTIFER			238
#define NETCA_ASN1_TYPE_OCSPRESPONSESID			239
#define NETCA_ASN1_TYPE_OCSPRESPONSESIDS		240
#define NETCA_ASN1_TYPE_OCSPLISTID				241
#define NETCA_ASN1_TYPE_OTHERREVREFS			242
#define NETCA_ASN1_TYPE_CRLOCSPREF				243
#define NETCA_ASN1_TYPE_COMPLETEREVOCATIONREFS	244
#define NETCA_ASN1_TYPE_X509_CERTIFICATES		245
#define NETCA_ASN1_TYPE_X509_CRLS				246
#define NETCA_ASN1_TYPE_BASICOCSPRESPONSES		247
#define NETCA_ASN1_TYPE_OTHERREVVALS			248
#define NETCA_ASN1_TYPE_REVOCATIONVALUES		249
#define NETCA_ASN1_TYPE_OCTET_STRINGS			250
#define NETCA_ASN1_TYPE_ATSHASHINDEX			251
#define NETCA_ASN1_TYPE_OBJECTDIGESTINFO		252
#define NETCA_ASN1_TYPE_AC_ISSUERSERIAL			253
#define NETCA_ASN1_TYPE_HOLDER			 		254
#define NETCA_ASN1_TYPE_AC_V2FORM		 		255
#define NETCA_ASN1_TYPE_ATTCERTISSUER	 		256
#define NETCA_ASN1_TYPE_ATTCERTVALIDITYPERIOD	257
#define NETCA_ASN1_TYPE_AC_ATTRIBUTES			258
#define NETCA_ASN1_TYPE_ATTRIBUTECERTIFICATEINFO	259
#define NETCA_ASN1_TYPE_ATTRIBUTECERTIFICATE	260
#define NETCA_ASN1_TYPE_SIGNERATTRIBUTE_ITEM	261
#define NETCA_ASN1_TYPE_SIGNERATTRIBUTE			262
#define NETCA_ASN1_TYPE_CONTENTREFERENCE		263
#define NETCA_ASN1_TYPE_CONTENTHINTS			264
#define NETCA_ASN1_TYPE_ERS_ALGOIDS				265
#define NETCA_ASN1_TYPE_ERS_CRYPTOINFOS		 	266
#define NETCA_ASN1_TYPE_ERS_ATTRIBUTES			267
#define NETCA_ASN1_TYPE_ERS_ENCRYPTIONINFO		268
#define NETCA_ASN1_TYPE_ERS_PARTIALHASHTREE		269
#define NETCA_ASN1_TYPE_ERS_SEQOF_PARTIALHASHTREE	270
#define NETCA_ASN1_TYPE_ERS_ARCHIVETIMESTAMP	271
#define NETCA_ASN1_TYPE_ERS_EVIDENCERECORD		272
#define NETCA_ASN1_TYPE_ERS_ARCHIVETIMESTAMPCHAIN	273
#define NETCA_ASN1_TYPE_ERS_ARCHIVETIMESTAMPSEQUENCE	274
#define NETCA_ASN1_TYPE_POEVALUE				275
#define NETCA_ASN1_TYPE_LONGTERMVALIDATION		276
#define NETCA_ASN1_TYPE_AC_TARGETCERT			277
#define NETCA_ASN1_TYPE_AC_TARGET				278
#define NETCA_ASN1_TYPE_AC_TARGETS				279
#define NETCA_ASN1_TYPE_AC_IETFATTRSYNTAX		280
#define NETCA_ASN1_TYPE_AC_IETFATTRSYNTAX_VALUE	281
#define NETCA_ASN1_TYPE_AC_IETFATTRSYNTAX_VALUES	282
#define NETCA_ASN1_TYPE_AC_SVCEAUTHINFO			283
#define NETCA_ASN1_TYPE_AC_ROLESYNTAX			284
#define NETCA_ASN1_TYPE_AC_SECURITYCATEGORY		285
#define NETCA_ASN1_TYPE_AC_SECURITYCATEGORIES	286
#define NETCA_ASN1_TYPE_AC_CLEARANCE			287
#define NETCA_ASN1_TYPE_ACCLEARATTRS			288
#define NETCA_ASN1_TYPE_AC_SEQOFTARGETS			289
#define NETCA_ASN1_TYPE_AC_ATTRSPEC				290
#define NETCA_ASN1_TYPE_AC_AACONTROLS			291
#define NETCA_ASN1_TYPE_ECC_CMS_SHAREDINFO		292
#define NETCA_ASN1_TYPE_OCSP_PREFERSIGNALGOS	293
#define NETCA_ASN1_TYPE_ADOBE_OTHERREVINFO	294
#define NETCA_ASN1_TYPE_ADOBE_OTHERREVINFOS	295
#define NETCA_ASN1_TYPE_ADOBE_CRLS	296
#define NETCA_ASN1_TYPE_ADOBE_OCSPRESPONSES	297
#define NETCA_ASN1_TYPE_ADOBE_REVOCATIONINFOARCHIVAL	298
#define NETCA_ASN1_TYPE_NETCA_IDENTIFICATION_ITEM		299
#define NETCA_ASN1_TYPE_NETCA_IDENTIFICATION_ITEMS		300
#define NETCA_ASN1_TYPE_ECCENVELOPEDKEYPAIR		301
#define NETCA_ASN1_TYPE_ATSHASHINDEXV3			302
#define NETCA_ASN1_TYPE_OTHER_ATTRIBUTE_CERTIFICATE		303
#define NETCA_ASN1_TYPE_CADES_CERTIFIED_ATTRIBUTES_V2_ITEM		304
#define NETCA_ASN1_TYPE_CADES_CERTIFIED_ATTRIBUTES_V2		305
#define NETCA_ASN1_TYPE_CADES_SIGNED_ASSERTION		306
#define NETCA_ASN1_TYPE_CADES_SIGNED_ASSERTIONS		307
#define NETCA_ASN1_TYPE_CADES_SIGNER_ATTRIBUTE_V2	308
#define NETCA_ASN1_TYPE_CADES_SP_DOC_SPECTIFICATION	309
#define NETCA_ASN1_TYPE_CADES_SIGNATURE_POLICY_DOCUMENT	310
#define NETCA_ASN1_TYPE_CADES_SIGNATURE_POLICY_STORE	311
#define NETCA_ASN1_TYPE_LDAP_ATTRIBUTE_VALUE_ASSERTION	312
#define NETCA_ASN1_TYPE_LDAP_REFERRAL	313
#define NETCA_ASN1_TYPE_LDAP_PARTIAL_ATTRIBUTE	314
#define NETCA_ASN1_TYPE_LDAP_ATTRIBUTE	315
#define NETCA_ASN1_TYPE_LDAP_RESULT		316
#define NETCA_ASN1_TYPE_LDAP_CONTROL	317
#define NETCA_ASN1_TYPE_LDAP_CONTROLS	318
#define NETCA_ASN1_TYPE_LDAP_SASL_CREDENTIALS	319
#define NETCA_ASN1_TYPE_LDAP_AUTHENTICATION_CHOICE	320
#define NETCA_ASN1_TYPE_LDAP_BIND_REQUEST		321
#define NETCA_ASN1_TYPE_LDAP_BIND_RESPONSE		322
#define NETCA_ASN1_TYPE_LDAP_UNBIND_REQUEST		323
#define NETCA_ASN1_TYPE_LDAP_SUBSTRING	324
#define NETCA_ASN1_TYPE_LDAP_SUBSTRINGS	325
#define NETCA_ASN1_TYPE_LDAP_SUBSTRING_FILTER	326
#define NETCA_ASN1_TYPE_LDAP_MATCHING_RULE_ASSERTION	327
#define NETCA_ASN1_TYPE_LDAP_FILTER	328
#define NETCA_ASN1_TYPE_LDAP_FILTERS	329
#define NETCA_ASN1_TYPE_LDAP_ATTRIBUTE_SELECTION	330
#define NETCA_ASN1_TYPE_LDAP_SEARCH_REQUEST	331
#define NETCA_ASN1_TYPE_LDAP_PARTIAL_ATTRIBUTE_LIST	332
#define NETCA_ASN1_TYPE_LDAP_SEARCH_RESULT_ENTRY	333
#define NETCA_ASN1_TYPE_LDAP_SEARCH_RESULT_REFERENCE	334
#define NETCA_ASN1_TYPE_LDAP_SEARCH_RESULT_DONE	335
#define NETCA_ASN1_TYPE_LDAP_CHANGE	336
#define NETCA_ASN1_TYPE_LDAP_CHANGES	337
#define NETCA_ASN1_TYPE_LDAP_MODIFY_REQUEST	338
#define NETCA_ASN1_TYPE_LDAP_MODIFY_RESPONSE	339
#define NETCA_ASN1_TYPE_LDAP_ATTRIBUTE_LIST		340
#define NETCA_ASN1_TYPE_LDAP_ADD_REQUEST	341
#define NETCA_ASN1_TYPE_LDAP_ADD_RESPONSE	342
#define NETCA_ASN1_TYPE_LDAP_DEL_REQUEST	343
#define NETCA_ASN1_TYPE_LDAP_DEL_RESPONSE	344
#define NETCA_ASN1_TYPE_LDAP_MODIFYDN_REQUEST	345
#define NETCA_ASN1_TYPE_LDAP_MODIFYDN_RESPONSE	346
#define NETCA_ASN1_TYPE_LDAP_COMPARE_REQUEST	347
#define NETCA_ASN1_TYPE_LDAP_COMPARE_RESPONSE	348
#define NETCA_ASN1_TYPE_LDAP_ABANDON_REQUEST	349
#define NETCA_ASN1_TYPE_LDAP_EXTENDED_REQUEST	350
#define NETCA_ASN1_TYPE_LDAP_EXTENDED_RESPONSE	351
#define NETCA_ASN1_TYPE_LDAP_INTERMEDIATE_RESPONSE	352
#define NETCA_ASN1_TYPE_LDAP_MESSAGE	353
#define NETCA_ASN1_TYPE_SETOF_OCTET_STRING				354
#define NETCA_ASN1_TYPE_PKCS7_SIGNED_AND_ENVELOPED_DATA	355
#define NETCA_ASN1_TYPE_SCVP_ISSUER_SERIAL				356
#define NETCA_ASN1_TYPE_SCVP_CERTID						357
#define NETCA_ASN1_TYPE_SCVP_PKC_REFERENCE				358
#define NETCA_ASN1_TYPE_SCVP_AC_REFERENCE				359
#define NETCA_ASN1_TYPE_SCVP_CERT_REFERENCE				360
#define NETCA_ASN1_TYPE_SCVP_PKC_REFERENCES				361
#define NETCA_ASN1_TYPE_SCVP_AC_REFERENCES				362
#define NETCA_ASN1_TYPE_SCVP_CERT_REFERENCES			363
#define NETCA_ASN1_TYPE_SCVP_CERTCHECKS					364
#define NETCA_ASN1_TYPE_SCVP_WANTBACK					365
#define NETCA_ASN1_TYPE_SCVP_VALIDATION_POL_REF			366
#define NETCA_ASN1_TYPE_SCVP_VALIDATION_ALG				367
#define NETCA_ASN1_TYPE_SCVP_NAME_VALIDATION_ALG_PARMS	368
#define NETCA_ASN1_TYPE_SCVP_RESPONSE_FLAGS				369
#define NETCA_ASN1_TYPE_SCVP_OTHER_REV_INFO				370
#define NETCA_ASN1_TYPE_SCVP_REVOCATION_INFO			371
#define NETCA_ASN1_TYPE_SCVP_REVOCATION_INFOS			372
#define NETCA_ASN1_TYPE_SCVP_USER_POLICY_SET			373
#define NETCA_ASN1_TYPE_SCVP_TRUST_ANCHORS				374
#define NETCA_ASN1_TYPE_SCVP_KEY_USAGES					375
#define NETCA_ASN1_TYPE_SCVP_EXTENDED_KEY_USAGES		376
#define NETCA_ASN1_TYPE_SCVP_VALIDATION_POLICY			377
#define NETCA_ASN1_TYPE_SCVP_CERT_BUNDLE				378
#define NETCA_ASN1_TYPE_SCVP_QUERY						379
#define NETCA_ASN1_TYPE_SCVP_CVREQUEST					380
#define NETCA_ASN1_TYPE_SCVP_RESPONSE_STATUS			381
#define NETCA_ASN1_TYPE_SCVP_HASH_VALUE					382
#define NETCA_ASN1_TYPE_SCVP_REQUEST_REFERENCE			383
#define NETCA_ASN1_TYPE_SCVP_REPLY_CHECK				384
#define NETCA_ASN1_TYPE_SCVP_REPLY_CHECKS				385
#define NETCA_ASN1_TYPE_SCVP_REPLY_WANTBACK				386
#define NETCA_ASN1_TYPE_SCVP_REPLY_WANTBACKS			387
#define NETCA_ASN1_TYPE_SCVP_CERT_BUNDLES				388
#define NETCA_ASN1_TYPE_SCVP_RESPONSES					389
#define NETCA_ASN1_TYPE_SCVP_VALIDATION_ERRORS			390
#define NETCA_ASN1_TYPE_SCVP_CERT_REPLY					391
#define NETCA_ASN1_TYPE_SCVP_REPLY_OBJECTS				392
#define NETCA_ASN1_TYPE_SCVP_CVRESPONSE					393
#define NETCA_ASN1_TYPE_SCVP_VAL_POL_REQUEST			394
#define NETCA_ASN1_TYPE_SEQ_OF_OID						395
#define NETCA_ASN1_TYPE_SEQ_OF_OID_NOTEMPTY				396
#define NETCA_ASN1_TYPE_SEQ_OF_ALGOID					397
#define NETCA_ASN1_TYPE_SCVP_KEYAGREE_PUBLICKEY			398
#define NETCA_ASN1_TYPE_SCVP_KEYAGREE_PUBLICKEYS		399
#define NETCA_ASN1_TYPE_SCVP_VAL_POL_RESPONSE			400
#define NETCA_ASN1_TYPE_CMS_ALGORITHM_PROTECTION		401
#define NETCA_ASN1_TYPE_SES_EXT_DATA		            402
#define NETCA_ASN1_TYPE_SES_EXT_DATAS		            403
#define NETCA_ASN1_TYPE_SES_HEADER  		            404
#define NETCA_ASN1_TYPE_SES_ESPROPERTY_INFO             405
#define NETCA_ASN1_TYPE_SES_ESPICTURE_INFO              406
#define NETCA_ASN1_TYPE_SES_SEAL_INFO                   407
#define NETCA_ASN1_TYPE_SES_SIGN_INFO                   408
#define NETCA_ASN1_TYPE_SES_SESEAL_TBS                  409
#define NETCA_ASN1_TYPE_SES_SESEAL                      410
#define NETCA_ASN1_TYPE_SES_TBS_SIGN                    411
#define NETCA_ASN1_TYPE_SES_SIGNATURE                   412
#define NETCA_ASN1_TYPE_GB_SES_CERT_DIGEST_OBJ          413
#define NETCA_ASN1_TYPE_GB_SES_CERT_DIGEST_LIST         414
#define NETCA_ASN1_TYPE_GB_SES_ESPROPERTY_INFO          415
#define NETCA_ASN1_TYPE_GB_SES_SEAL_INFO                416
#define NETCA_ASN1_TYPE_GB_SES_SESEAL		            417
#define NETCA_ASN1_TYPE_GB_SES_TBS_SIGN                 418
#define NETCA_ASN1_TYPE_GB_SES_SIGNATURE                419
#define NETCA_ASN1_TYPE_SCVP_REV_INFO_WANT_BACK         420

const char *NETCAAPI netca_asn1_version(void);

int NETCAAPI netca_asn1_encode_identifier(NETCA_STREAM stream,int typeclass,int isprimitive,long tagnumber,long *writelen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_decode_identifier(NETCA_STREAM stream,int *typeclass,int *isprimitive,long *tagnumber,long *readlen,NETCA_ERR_CTX errctx);
long NETCAAPI netca_asn1_identifier_length(long tagnumber);

int NETCAAPI netca_asn1_encode_length(NETCA_STREAM stream,long length,long *writelen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_decode_length(NETCA_STREAM stream,long *length,long *readlen,NETCA_ERR_CTX errctx);
long NETCAAPI netca_asn1_length_length(long length);

int NETCAAPI netca_asn1_decode_eoc_length(NETCA_STREAM stream,long *readlen,NETCA_ERR_CTX errctx);

void NETCAAPI netca_asn1_value_free(long type,void *value);
long NETCAAPI netca_asn1_content_length(long type,void *value);
long NETCAAPI netca_asn1_length(long type,void *value);
int NETCAAPI netca_asn1_encode_content(NETCA_STREAM stream,long type,void *value,long length,long *writelen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_decode_content(NETCA_STREAM stream,long type,void **value,int isprimitive,long length,long *readlen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_encode(NETCA_STREAM stream,long type,void *value,long *writelen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_decode(NETCA_STREAM stream,long type,void **value,long *readlen,NETCA_ERR_CTX errctx);
void NETCAAPI netca_asn1_encode_puterr(NETCA_ERR_CTX errctx,long type,const char *file,int linno);
void NETCAAPI netca_asn1_decode_puterr(NETCA_ERR_CTX errctx,long type,const char *file,int linno);

NETCA_Data_Blob NETCAAPI netca_asn1_mem_encode(long type,void *value);
long NETCAAPI netca_asn1_mem_decode(const unsigned char *data,long dataLen,long type,void **value);

NETCA_Data_Blob NETCAAPI netca_asn1_encodejson(NETCA_JSON json);
NETCA_JSON NETCAAPI netca_asn1_tojson(const unsigned char *data,long dataLen);

NETCA_ASN1_Boolean_Ptr NETCAAPI netca_asn1_boolean_true(void);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_asn1_boolean_false(void);
int NETCAAPI netca_asn1_boolean_istrue(NETCA_ASN1_Boolean_Ptr boolvalue);
int NETCAAPI netca_asn1_boolean_getvalue(NETCA_ASN1_Boolean_Ptr boolvalue,int *value);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_asn1_boolean_new(int value);


NETCA_ASN1_Integer_Ptr NETCAAPI netca_asn1_integer_value(long value);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_asn1_integer_new(const unsigned char *buf,long buflen);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_asn1_unsigned_integer_new(const unsigned char *buf,long buflen);
int NETCAAPI netca_asn1_integer_equals(NETCA_ASN1_Integer_Ptr int1,NETCA_ASN1_Integer_Ptr int2);
int NETCAAPI netca_asn1_integer_get(NETCA_ASN1_Integer_Ptr value,unsigned char *buf);
long NETCAAPI netca_asn1_integer_getlength(NETCA_ASN1_Integer_Ptr value);
int NETCAAPI netca_asn1_integer_getlong(NETCA_ASN1_Integer_Ptr value,long *longvalue);
NETCA_BigInteger NETCAAPI netca_asn1_integer_getbigintger(NETCA_ASN1_Integer_Ptr value);
int NETCAAPI netca_asn1_integer_encodecmp(NETCA_ASN1_Integer_Ptr int1,NETCA_ASN1_Integer_Ptr int2);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_asn1_integer_newbigint(NETCA_BigInteger bn);

NETCA_ASN1_Enum_Ptr NETCAAPI netca_asn1_enum_value(long value);
int NETCAAPI netca_asn1_enum_getlong(NETCA_ASN1_Enum_Ptr value,long *longvalue);

NETCA_ASN1_BitString_Ptr NETCAAPI netca_asn1_bitstring_new(int unusedbits,const unsigned char *buf,long buflen);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_asn1_bitstring_newbits(const int *bits,long bitslen);
int NETCAAPI netca_asn1_bitstring_getunusedbits(NETCA_ASN1_BitString_Ptr bitstr,int *unusedbits);
int NETCAAPI netca_asn1_bitstring_getbit(NETCA_ASN1_BitString_Ptr bitstr,int n);
int NETCAAPI netca_asn1_bitstring_get(NETCA_ASN1_BitString_Ptr bitstr,int pos,unsigned char *data,long datalen,long *readlen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_bitstring_getall(NETCA_ASN1_BitString_Ptr bitstr,unsigned char *data);
int NETCAAPI netca_asn1_decode_bitstring_content_ex(NETCA_STREAM stream,NETCA_STREAM outstream,NETCA_ASN1_BitString_Ptr *bitstr,int isprimitive,long length,long *readlen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_decode_bitstring_ex(NETCA_STREAM stream,NETCA_STREAM outstream,NETCA_ASN1_BitString_Ptr *bitstr,long *readlen,NETCA_ERR_CTX errctx);
long NETCAAPI netca_asn1_bitstring_getlength(NETCA_ASN1_BitString_Ptr bitstr);
int NETCAAPI netca_asn1_bitstring_getobject(NETCA_ASN1_BitString_Ptr bitstr,int type,void **object,NETCA_ERR_CTX errctx);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_asn1_bitstring_newbitset(NETCA_BitSet bitset);
NETCA_BitSet NETCAAPI netca_asn1_bitstring_getbitset(NETCA_ASN1_BitString_Ptr bitstr);

NETCA_ASN1_OctetString_Ptr NETCAAPI netca_asn1_octetstring_new(const unsigned char *buf,long buflen);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_asn1_octetstring_newstream(const NETCA_STREAM stream);
int NETCAAPI netca_asn1_octetstring_get(NETCA_ASN1_OctetString_Ptr octetstr,int pos,unsigned char *data,long datalen,long *readlen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_octetstring_getall(NETCA_ASN1_OctetString_Ptr octetstr,unsigned char *data);
long NETCAAPI netca_asn1_octetstring_getlength(NETCA_ASN1_OctetString_Ptr octetstr);
int NETCAAPI netca_asn1_decode_octetstring_content_ex(NETCA_STREAM stream,NETCA_STREAM outstream,NETCA_ASN1_OctetString_Ptr *octetstr,int isprimitive,long length,long *readlen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_decode_octetstring_ex(NETCA_STREAM stream,NETCA_STREAM outstream,NETCA_ASN1_OctetString_Ptr *octetstr,long *readlen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_octetstring_getobject(NETCA_ASN1_OctetString_Ptr str,int type,void **object,NETCA_ERR_CTX errctx);
NETCA_Data_Blob NETCAAPI netca_asn1_octetstring_getblob(NETCA_ASN1_OctetString_Ptr str);

int NETCAAPI netca_asn1_encode_octetstring_init(NETCA_STREAM stream);
int NETCAAPI netca_asn1_encode_octetstring_update(NETCA_STREAM stream,const unsigned char *data,long datalen);
int NETCAAPI netca_asn1_encode_octetstring_end(NETCA_STREAM stream);

int NETCAAPI netca_asn1_decode_octetstring_update(NETCA_ASN1_OctetString_Decode_Ctx ctx,NETCA_STREAM outputstream,const unsigned char *data,long datalen,long *remlen);
int NETCAAPI netca_asn1_decode_octetstring_content_update(NETCA_ASN1_OctetString_Decode_Ctx ctx,NETCA_STREAM outputstream,const unsigned char *data,long datalen,long *remlen);
int NETCAAPI netca_asn1_decode_octetstring_isfinish(NETCA_ASN1_OctetString_Decode_Ctx ctx);
NETCA_ASN1_OctetString_Decode_Ctx NETCAAPI netca_asn1_decode_octetstring_ctx_new(void);
void NETCAAPI netca_asn1_decode_octetstring_ctx_free(NETCA_ASN1_OctetString_Decode_Ctx ctx);
int NETCAAPI netca_asn1_decode_octetstring_ctx_setstate(NETCA_ASN1_OctetString_Decode_Ctx ctx,int isprimitive,long length);
long NETCAAPI netca_asn1_decode_octetstring_ctx_getencodelength(NETCA_ASN1_OctetString_Decode_Ctx ctx);

NETCA_ASN1_String_Ptr NETCAAPI netca_asn1_string_new(const unsigned char *buf,long buflen);
int NETCAAPI netca_asn1_string_get(NETCA_ASN1_String_Ptr str,unsigned char *data);
long NETCAAPI netca_asn1_string_getlength(NETCA_ASN1_String_Ptr str);


NETCA_ASN1_OID_Ptr NETCAAPI netca_asn1_oid_new(const char *oid);
const char * NETCAAPI netca_asn1_oid_getstring(NETCA_ASN1_OID_Ptr oid);

NETCA_ASN1_RelativeOid_Ptr NETCAAPI netca_asn1_relative_oid_new(const char *roid);
const char * NETCAAPI netca_asn1_relative_oid_getstring(NETCA_ASN1_RelativeOid_Ptr roid);

NETCA_ASN1_Any_Ptr NETCAAPI netca_asn1_any_new(int typeclass,int isprimitive,long tagnumber,long length,const unsigned char *data,long datalen);
int NETCAAPI netca_asn1_decode_any_ex(NETCA_STREAM stream,NETCA_STREAM outstream,NETCA_ASN1_Any_Ptr *any,long *readlen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_any_gettypeclass(NETCA_ASN1_Any_Ptr any,int *typeclass);
int NETCAAPI netca_asn1_any_isprimitive(NETCA_ASN1_Any_Ptr any,int *isprimitive);
int NETCAAPI netca_asn1_any_gettagnumber(NETCA_ASN1_Any_Ptr any,long *tagnumber);
int NETCAAPI netca_asn1_any_getcontent(NETCA_ASN1_Any_Ptr any,int pos,unsigned char *data,long datalen,long *readlen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_any_getobject(NETCA_ASN1_Any_Ptr any,int type,void **object,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_any_toobject(NETCA_ASN1_Any_Ptr any,int type,void **object,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_any_contenttoobject(NETCA_ASN1_Any_Ptr any,int type,void **object,NETCA_ERR_CTX errctx);
long NETCAAPI netca_asn1_any_getcontentlength(NETCA_ASN1_Any_Ptr any);
NETCA_ASN1_Any_Ptr NETCAAPI netca_asn1_objecttoany(int type,void *object);
int NETCAAPI netca_asn1_any_iseoc(NETCA_ASN1_Any_Ptr any);


NETCA_ASN1_ANY_Decode_Ctx NETCAAPI netca_asn1_decode_any_ctx_new(void);
int NETCAAPI netca_asn1_decode_any_update(NETCA_ASN1_ANY_Decode_Ctx ctx,const unsigned char *data,long datalen,long *remlen);
void NETCAAPI netca_asn1_decode_any_ctx_free(NETCA_ASN1_ANY_Decode_Ctx ctx);
int NETCAAPI netca_asn1_decode_any_isfinish(NETCA_ASN1_ANY_Decode_Ctx ctx);
int NETCAAPI netca_asn1_decode_any_identifier_length(NETCA_ASN1_ANY_Decode_Ctx ctx,int first,const unsigned char *data,long datalen,int *typeclass,int *isprimitive,long *tagnumber,long *length,long *remlen);
int NETCAAPI netca_asn1_decode_any_ctx_toobject(NETCA_ASN1_ANY_Decode_Ctx ctx,int type,void **object);
int NETCAAPI netca_asn1_decode_any_ctx_iseoc(NETCA_ASN1_ANY_Decode_Ctx ctx);

void *NETCAAPI netca_asn1_dupobject(int type,void *object,NETCA_ERR_CTX errctx);

NETCA_ASN1_Time_Ptr NETCAAPI netca_asn1_time_new(int year,int month,int day,int hour,int minute,int second,long ns);
NETCA_ASN1_Time_Ptr NETCAAPI netca_asn1_gentime_new(int year,int month,int day,int hour,int minute,int second,long ns);
NETCA_ASN1_Time_Ptr NETCAAPI netca_asn1_utctime_new(int year,int month,int day,int hour,int minute,int second);
NETCA_Time NETCAAPI netca_asn1_time_getutctime(NETCA_ASN1_Time_Ptr time);
#define NETCA_TIME_FLAG_TYPE_UTC	0
#define NETCA_TIME_FLAG_TYPE_GEN	1
#define NETCA_TIME_FLAG_TYPE_X509	2
#define NETCA_TIME_FLAG_TYPE_MASK	15
#define NETCA_TIME_FLAG_USENS		16
NETCA_ASN1_Time_Ptr NETCAAPI netca_asn1_time_newutctime(NETCA_Time time,int flag);


NETCA_ASN1_List_Ptr NETCAAPI netca_asn1_list_new(void);
int NETCAAPI netca_asn1_list_put(NETCA_ASN1_List_Ptr list,void *item);
int NETCAAPI netca_asn1_list_getsize(NETCA_ASN1_List_Ptr list);
int NETCAAPI netca_asn1_list_get(NETCA_ASN1_List_Ptr list,int index,void **item);
void NETCAAPI netca_asn1_list_free(NETCA_ASN1_List_Ptr list,int type);
void *NETCAAPI netca_asn1_list_delete(NETCA_ASN1_List_Ptr list,int index);

int NETCAAPI netca_x500RDN_sort(NETCA_ASN1_List_Ptr rdn);
int NETCAAPI netca_x500attribute_sort(NETCA_X500Attribute_Ptr attr);
int  NETCAAPI netca_asn1_pkcs10attributes_sort(NETCA_ASN1_List_Ptr attrs);

NETCA_ASN1_OID_Ptr NETCAAPI netca_x500context_gettype(NETCA_X500Context_Ptr context);
NETCA_ASN1_List_Ptr NETCAAPI netca_x500context_getvalues(NETCA_X500Context_Ptr context);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_x500context_getfallback(NETCA_X500Context_Ptr context);
NETCA_X500Context_Ptr NETCAAPI netca_x500context_new(NETCA_ASN1_OID_Ptr type,NETCA_ASN1_List_Ptr values,NETCA_ASN1_Boolean_Ptr fallback);

int NETCAAPI netca_x500dnvalueswithcontextitem_hasdistvalue(NETCA_X500DNValuesWithContextItem_Ptr item);
NETCA_ASN1_Any_Ptr NETCAAPI netca_x500dnvalueswithcontextitem_getdistvalue(NETCA_X500DNValuesWithContextItem_Ptr item);
NETCA_ASN1_List_Ptr NETCAAPI netca_x500dnvalueswithcontextitem_getcontexts(NETCA_X500DNValuesWithContextItem_Ptr item);
NETCA_X500DNValuesWithContextItem_Ptr NETCAAPI netca_x500dnvalueswithcontextitem_new(NETCA_ASN1_Any_Ptr distvalue,NETCA_ASN1_List_Ptr contexts);


NETCA_ASN1_OID_Ptr NETCAAPI netca_x500attrtypedistval_gettype(NETCA_X500AttrTypeDistVal_Ptr val);
NETCA_ASN1_Any_Ptr NETCAAPI netca_x500attrtypedistval_getvalue(NETCA_X500AttrTypeDistVal_Ptr val);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_x500attrtypedistval_getprimedist(NETCA_X500AttrTypeDistVal_Ptr val);
int NETCAAPI netca_x500attrtypedistval_hascontext(NETCA_X500AttrTypeDistVal_Ptr val);
NETCA_ASN1_List_Ptr NETCAAPI netca_x500attrtypedistval_getcontext(NETCA_X500AttrTypeDistVal_Ptr val);
NETCA_X500AttrTypeDistVal_Ptr NETCAAPI netca_pkixattrtypeval_new(NETCA_ASN1_OID_Ptr type, NETCA_ASN1_Any_Ptr value);
NETCA_X500AttrTypeDistVal_Ptr NETCAAPI netca_x500attrtypedistval_new(NETCA_ASN1_OID_Ptr type, NETCA_ASN1_Any_Ptr value,NETCA_ASN1_Boolean_Ptr primedist,NETCA_ASN1_List_Ptr context);

NETCA_ASN1_List_Ptr NETCAAPI netca_x500name_getdn(NETCA_X500Name_Ptr name);
NETCA_X500Name_Ptr NETCAAPI netca_x500name_new(void);
int NETCAAPI netca_x500name_addrdn(NETCA_X500Name_Ptr name,NETCA_ASN1_List_Ptr rdn,int copy);
int NETCAAPI netca_x500name_sort(NETCA_X500Name_Ptr name);

NETCA_ASN1_Any_Ptr NETCAAPI netca_x500attrvalueswithcontextitem_getvalue(NETCA_X500AttrValuesWithContextItem_Ptr item);
NETCA_ASN1_List_Ptr NETCAAPI netca_x500attrvalueswithcontextitem_getcontexts(NETCA_X500AttrValuesWithContextItem_Ptr item);

NETCA_X500Attribute_Ptr NETCAAPI netca_x500attribute_new(NETCA_ASN1_OID_Ptr type,NETCA_ASN1_List_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_x500attribute_gettype(NETCA_X500Attribute_Ptr attr);
NETCA_ASN1_List_Ptr NETCAAPI netca_x500attribute_getvalue(NETCA_X500Attribute_Ptr attr);
int NETCAAPI netca_x500attribute_hascontext(NETCA_X500Attribute_Ptr attr);
NETCA_ASN1_List_Ptr NETCAAPI netca_x500attribute_getcontext(NETCA_X500Attribute_Ptr attr);

NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_x509algoid_new_without_param(NETCA_ASN1_OID_Ptr algorithm);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_x509algoid_new(NETCA_ASN1_OID_Ptr algorithm,int paramtype,void *param);
NETCA_ASN1_OID_Ptr NETCAAPI netca_x509algoid_getalgo(NETCA_X509AlgorithmIdentifier_Ptr algoid);
int NETCAAPI netca_x509algoid_hasparam(NETCA_X509AlgorithmIdentifier_Ptr algoid);
NETCA_ASN1_Any_Ptr NETCAAPI netca_x509algoid_getparam(NETCA_X509AlgorithmIdentifier_Ptr algoid);
int NETCAAPI netca_x509algoid_isnullparam(NETCA_X509AlgorithmIdentifier_Ptr algoid);

NETCA_X509Validity_Ptr NETCAAPI netca_x509validity_new(NETCA_ASN1_Time_Ptr notbefore,NETCA_ASN1_Time_Ptr notafter);
NETCA_ASN1_Time_Ptr NETCAAPI netca_x509validity_getnotbefore(NETCA_X509Validity_Ptr val);
NETCA_ASN1_Time_Ptr NETCAAPI netca_x509validity_getnotafter(NETCA_X509Validity_Ptr val);

NETCA_X509SubjectPublicKeyInfo_Ptr NETCAAPI netca_x509subjpubkeyinfo_new(NETCA_X509AlgorithmIdentifier_Ptr algo,NETCA_ASN1_BitString_Ptr pubkey);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_x509subjpubkeyinfo_getalgo(NETCA_X509SubjectPublicKeyInfo_Ptr info);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_x509subjpubkeyinfo_getpubkey(NETCA_X509SubjectPublicKeyInfo_Ptr info);

NETCA_X509Extension_Ptr NETCAAPI netca_x509extension_create(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_Boolean_Ptr critical,int valuetype,void *value);
NETCA_X509Extension_Ptr NETCAAPI netca_x509extension_new(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_Boolean_Ptr critical,NETCA_ASN1_OctetString_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_x509extension_getid(NETCA_X509Extension_Ptr ext);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_x509extension_getcritical(NETCA_X509Extension_Ptr ext);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_x509extension_getvalue(NETCA_X509Extension_Ptr ext);

NETCA_X509TBSCertificate_Ptr NETCAAPI netca_x509TBSCertificate_new(NETCA_ASN1_Integer_Ptr version,NETCA_ASN1_Integer_Ptr serialNumber,
	NETCA_X509AlgorithmIdentifier_Ptr signaturealgo,NETCA_X500Name_Ptr issuer,NETCA_X509Validity_Ptr validity,
	NETCA_X500Name_Ptr subject,NETCA_X509SubjectPublicKeyInfo_Ptr subjectPublicKeyInfo,
	NETCA_ASN1_BitString_Ptr issuerUniqueIdentifier,NETCA_ASN1_BitString_Ptr subjectUniqueIdentifier,
	NETCA_ASN1_List_Ptr extensions);

NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_x509pubkeycert_create(NETCA_X509TBSCertificate_Ptr tbs,NETCA_ASN1_BitString_Ptr signature);

NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_x509pubkeycert_new(const unsigned char *data,long datalen,NETCA_ERR_CTX errctx);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509pubkeycert_getversion(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509pubkeycert_getserialno(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_x509pubkeycert_getinnersignalgo(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_X500Name_Ptr NETCAAPI netca_x509pubkeycert_getissuer(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_X509Validity_Ptr NETCAAPI netca_x509pubkeycert_getvalidity(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_X500Name_Ptr NETCAAPI netca_x509pubkeycert_getsubject(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_X509SubjectPublicKeyInfo_Ptr NETCAAPI netca_x509pubkeycert_getpubkey(NETCA_X509PubKeyCertificate_Ptr cert);
int NETCAAPI netca_x509pubkeycert_hasissueruid(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_x509pubkeycert_getissueruid(NETCA_X509PubKeyCertificate_Ptr cert);
int NETCAAPI netca_x509pubkeycert_hassubjectuid(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_x509pubkeycert_getsubjectuid(NETCA_X509PubKeyCertificate_Ptr cert);
int NETCAAPI netca_x509pubkeycert_hasexts(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509pubkeycert_getexts(NETCA_X509PubKeyCertificate_Ptr cert);
int NETCAAPI netca_x509pubkeycert_gettbsocts(NETCA_X509PubKeyCertificate_Ptr cert,unsigned char *data,long *datalen);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_x509pubkeycert_getsignalgo(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_x509pubkeycert_getsignvalue(NETCA_X509PubKeyCertificate_Ptr cert);

NETCA_X509RevokedCertificate_Ptr NETCAAPI netca_x509revcertinfo_new(NETCA_ASN1_Integer_Ptr serialNumber,NETCA_ASN1_Time_Ptr revocationDate,NETCA_ASN1_List_Ptr crlEntryExtensions);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509revcertinfo_getserilano(NETCA_X509RevokedCertificate_Ptr rev);
NETCA_ASN1_Time_Ptr NETCAAPI netca_x509revcertinfo_getrevdate(NETCA_X509RevokedCertificate_Ptr rev);
int NETCAAPI netca_x509revcertinfo_hasexts(NETCA_X509RevokedCertificate_Ptr rev);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509revcertinfo_getexts(NETCA_X509RevokedCertificate_Ptr rev);


NETCA_X509TBSCertList_Ptr NETCAAPI netca_x509TBSCertList_new(NETCA_ASN1_Integer_Ptr version,NETCA_X509AlgorithmIdentifier_Ptr signaturealgo,
						NETCA_X500Name_Ptr issuer,NETCA_ASN1_Time_Ptr thisUpdate,NETCA_ASN1_Time_Ptr nextUpdate,
						NETCA_ASN1_List_Ptr revokedCertificates,int cpoyrevcerts,NETCA_ASN1_List_Ptr crlExtensions);

NETCA_X509CRL_Ptr NETCAAPI netca_x509crl_create(NETCA_X509TBSCertList_Ptr tbs,NETCA_ASN1_BitString_Ptr signature);

NETCA_X509CRL_Ptr NETCAAPI netca_x509crl_new(const unsigned char *data,long datalen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_x509crl_hasversion(NETCA_X509CRL_Ptr crl);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509crl_getversion(NETCA_X509CRL_Ptr crl);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_x509crl_getinnersignalgo(NETCA_X509CRL_Ptr crl);
NETCA_X500Name_Ptr NETCAAPI netca_x509crl_getissuer(NETCA_X509CRL_Ptr crl);
NETCA_ASN1_Time_Ptr NETCAAPI netca_x509crl_getthisupdate(NETCA_X509CRL_Ptr crl);
int NETCAAPI netca_x509crl_hasnextupdate(NETCA_X509CRL_Ptr crl);
NETCA_ASN1_Time_Ptr NETCAAPI netca_x509crl_getnextupdate(NETCA_X509CRL_Ptr crl);
int NETCAAPI netca_x509crl_hasrevcerts(NETCA_X509CRL_Ptr crl);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509crl_getrevcerts(NETCA_X509CRL_Ptr crl);
int NETCAAPI netca_x509crl_hasexts(NETCA_X509CRL_Ptr crl);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509crl_getexts(NETCA_X509CRL_Ptr crl);
int NETCAAPI netca_x509crl_gettbsocts(NETCA_X509CRL_Ptr crl,unsigned char *data,long *datalen);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_x509crl_getsignalgo(NETCA_X509CRL_Ptr crl);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_x509crl_getsignvalue(NETCA_X509CRL_Ptr crl);

NETCA_PKCS10_CertReqInfo_Ptr NETCAAPI netca_pkcs10certreqinfo_new(NETCA_ASN1_Integer_Ptr version,
	NETCA_X500Name_Ptr subject,NETCA_X509SubjectPublicKeyInfo_Ptr subjectPKInfo,NETCA_ASN1_List_Ptr attributes);
NETCA_PKCS10_CertReq_Ptr NETCAAPI netca_pkcs10certreq_create(NETCA_PKCS10_CertReqInfo_Ptr tbs,NETCA_X509AlgorithmIdentifier_Ptr algoid,NETCA_ASN1_BitString_Ptr signature);

NETCA_PKCS10_CertReq_Ptr NETCAAPI netca_pkcs10certreq_new(const unsigned char *data,long datalen,NETCA_ERR_CTX errctx);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs10certreq_getversion(NETCA_PKCS10_CertReq_Ptr certreq);
NETCA_X500Name_Ptr NETCAAPI netca_pkcs10certreq_getsubject(NETCA_PKCS10_CertReq_Ptr certreq);
NETCA_X509SubjectPublicKeyInfo_Ptr NETCAAPI netca_pkcs10certreq_getpubkey(NETCA_PKCS10_CertReq_Ptr certreq);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkcs10certreq_getattrs(NETCA_PKCS10_CertReq_Ptr certreq);
int NETCAAPI netca_pkcs10certreq_hasattrs(NETCA_PKCS10_CertReq_Ptr certreq);
int NETCAAPI netca_pkcs10certreq_gettbsocts(NETCA_PKCS10_CertReq_Ptr certreq,unsigned char *data,long *datalen);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs10certreq_getsignalgo(NETCA_PKCS10_CertReq_Ptr certreq);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_pkcs10certreq_getsignvalue(NETCA_PKCS10_CertReq_Ptr certreq);

NETCA_X500DirectoryString_Ptr NETCAAPI netca_x500dirstring_new(long tagnum,NETCA_ASN1_String_Ptr str);
int NETCAAPI netca_x500dirstring_gettype(NETCA_X500DirectoryString_Ptr str,long *type);
NETCA_ASN1_String_Ptr NETCAAPI netca_x500dirstring_getstring(NETCA_X500DirectoryString_Ptr str);

NETCA_X500UUIDPair_Ptr NETCAAPI netca_x500uuidpair_new(const unsigned char * issueruuid,const unsigned char *subjectuuid);
int NETCAAPI netca_x500uuidpair_getissueruuid(NETCA_X500UUIDPair_Ptr pair,unsigned char *uuid);
int NETCAAPI netca_x500uuidpair_getsubjectuuid(NETCA_X500UUIDPair_Ptr pair,unsigned char *uuid);

NETCA_X500TelexNumber_Ptr NETCAAPI netca_x500telexnum_new(NETCA_ASN1_String_Ptr telexnum,NETCA_ASN1_String_Ptr coutrycode,NETCA_ASN1_String_Ptr answerback);
NETCA_ASN1_String_Ptr NETCAAPI netca_x500telexnum_gettelexnum(NETCA_X500TelexNumber_Ptr num);
NETCA_ASN1_String_Ptr NETCAAPI netca_x500telexnum_getcoutrycode(NETCA_X500TelexNumber_Ptr num);
NETCA_ASN1_String_Ptr NETCAAPI netca_x500telexnum_getanswerback(NETCA_X500TelexNumber_Ptr num);

NETCA_X500NameAndOptionalUID_Ptr NETCAAPI netca_x500nameandoptuid_new(NETCA_ASN1_List_Ptr name,NETCA_ASN1_BitString_Ptr uid);
NETCA_ASN1_List_Ptr NETCAAPI netca_x500nameandoptuid_getname(NETCA_X500NameAndOptionalUID_Ptr name);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_x500nameandoptuid_getuid(NETCA_X500NameAndOptionalUID_Ptr name);

NETCA_PKCS9_String_Ptr NETCAAPI netca_pkcs9string_new(long tagnum,NETCA_ASN1_String_Ptr str);
int NETCAAPI netca_pkcs9string_gettype(NETCA_PKCS9_String_Ptr str,long *type);
NETCA_ASN1_String_Ptr NETCAAPI netca_pkcs9string_getstring(NETCA_PKCS9_String_Ptr str);

NETCA_X509CertificatePair_Ptr NETCAAPI netca_x509certpair_new(NETCA_X509PubKeyCertificate_Ptr issuedtothisca,NETCA_X509PubKeyCertificate_Ptr issuedbythisca);
NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_x509certpair_getissuedtothisca(NETCA_X509CertificatePair_Ptr pair);
NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_x509certpair_getissuedbythisca(NETCA_X509CertificatePair_Ptr pair);

NETCA_PKCS1_RSAPublicKey_Ptr NETCAAPI netca_rsapubkey_new(NETCA_ASN1_Integer_Ptr modulus,NETCA_ASN1_Integer_Ptr pubexponent);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_rsapubkey_getmodulus(NETCA_PKCS1_RSAPublicKey_Ptr rsa);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_rsapubkey_getpubexponent(NETCA_PKCS1_RSAPublicKey_Ptr rsa);

NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcsdigistinfo_getalgo(NETCA_PKCS_DigestInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcsdigistinfo_getdigest(NETCA_PKCS_DigestInfo_Ptr info);
NETCA_PKCS_DigestInfo_Ptr NETCAAPI netca_pkcsdigistinfo_new(NETCA_X509AlgorithmIdentifier_Ptr algo,NETCA_ASN1_OctetString_Ptr digst);

NETCA_DSS_SigValue_Ptr NETCAAPI netca_dsssignvalue_new(NETCA_ASN1_Integer_Ptr r,NETCA_ASN1_Integer_Ptr s);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_dsssignvalue_getr(NETCA_DSS_SigValue_Ptr dsssign);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_dsssignvalue_gets(NETCA_DSS_SigValue_Ptr dsssign);

NETCA_DSS_Parms_Ptr NETCAAPI netca_dssparam_new(NETCA_ASN1_Integer_Ptr p,NETCA_ASN1_Integer_Ptr q,NETCA_ASN1_Integer_Ptr g);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_dssparam_getp(NETCA_DSS_Parms_Ptr dssparam);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_dssparam_getq(NETCA_DSS_Parms_Ptr dssparam);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_dssparam_getg(NETCA_DSS_Parms_Ptr dssparam);

NETCA_ASN1_Instanceof_TypeId_Ptr NETCAAPI netca_instanceoftypeid_new(NETCA_ASN1_OID_Ptr oid,NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_instanceoftypeid_getid(NETCA_ASN1_Instanceof_TypeId_Ptr type);
NETCA_ASN1_Any_Ptr NETCAAPI netca_instanceoftypeid_gettype(NETCA_ASN1_Instanceof_TypeId_Ptr type);

NETCA_X509_EDIPartyName_Ptr NETCAAPI netca_x509edipartyname_new(NETCA_X500DirectoryString_Ptr  nameassigner,NETCA_X500DirectoryString_Ptr partyname);
NETCA_X500DirectoryString_Ptr NETCAAPI netca_x509edipartyname_getnameassigner(NETCA_X509_EDIPartyName_Ptr name);
NETCA_X500DirectoryString_Ptr NETCAAPI netca_x509edipartyname_getpartyname(NETCA_X509_EDIPartyName_Ptr name);

NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509generalname_new_othername(NETCA_ASN1_Instanceof_TypeId_Ptr othername);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509generalname_new_rfc822name(NETCA_ASN1_String_Ptr rfc822name);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509generalname_new_dnsname(NETCA_ASN1_String_Ptr dnsname);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509generalname_new_dirname(NETCA_X500Name_Ptr dirname);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509generalname_new_ediname(NETCA_X509_EDIPartyName_Ptr ediname);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509generalname_new_uri(NETCA_ASN1_String_Ptr uri);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509generalname_new_ip(NETCA_ASN1_OctetString_Ptr ip);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509generalname_new_regid(NETCA_ASN1_OID_Ptr regid);
int NETCAAPI netca_x509generalname_gettype(NETCA_X509_GeneralName_Ptr name,long *type);
NETCA_ASN1_Instanceof_TypeId_Ptr NETCAAPI netca_x509generalname_getothername(NETCA_X509_GeneralName_Ptr name);
NETCA_ASN1_String_Ptr NETCAAPI netca_x509generalname_getrfc822name(NETCA_X509_GeneralName_Ptr name);
NETCA_ASN1_String_Ptr NETCAAPI netca_x509generalname_getdnsname(NETCA_X509_GeneralName_Ptr name);
NETCA_X500Name_Ptr NETCAAPI netca_x509generalname_getdirname(NETCA_X509_GeneralName_Ptr name);
NETCA_X509_EDIPartyName_Ptr NETCAAPI netca_x509generalname_getediname(NETCA_X509_GeneralName_Ptr name);
NETCA_ASN1_String_Ptr NETCAAPI netca_x509generalname_geturi(NETCA_X509_GeneralName_Ptr name);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_x509generalname_getip(NETCA_X509_GeneralName_Ptr name);
NETCA_ASN1_OID_Ptr NETCAAPI netca_x509generalname_getregid(NETCA_X509_GeneralName_Ptr name);

NETCA_X509_AuthorityKeyIdentifier_Ptr NETCAAPI netca_x509akid_new(NETCA_ASN1_OctetString_Ptr keyid,NETCA_ASN1_List_Ptr issuerissuer,NETCA_ASN1_Integer_Ptr issuercertsn);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_x509akid_getkeyid(NETCA_X509_AuthorityKeyIdentifier_Ptr akid);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509akid_getissuerissuer(NETCA_X509_AuthorityKeyIdentifier_Ptr akid);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509akid_getissuercertsn(NETCA_X509_AuthorityKeyIdentifier_Ptr akid);

NETCA_ASN1_Time_Ptr NETCAAPI netca_x509privkeyperiod_getnotbefore(NETCA_X509_PrivKeyUsagePeriod_Ptr period);
NETCA_ASN1_Time_Ptr NETCAAPI netca_x509privkeyperiod_getnotafter(NETCA_X509_PrivKeyUsagePeriod_Ptr period);
NETCA_X509_PrivKeyUsagePeriod_Ptr NETCAAPI netca_x509privkeyperiod_new(NETCA_ASN1_Time_Ptr notbefore,NETCA_ASN1_Time_Ptr notafter);

NETCA_ASN1_OID_Ptr NETCAAPI netca_x509polqualifierinfo_getid(NETCA_X509_PolicyQualifierInfo_Ptr info);
NETCA_ASN1_Any_Ptr NETCAAPI netca_x509polqualifierinfo_getqualifier(NETCA_X509_PolicyQualifierInfo_Ptr info);
NETCA_X509_PolicyQualifierInfo_Ptr NETCAAPI netca_x509polqualifierinfo_new(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_Any_Ptr qualifier);

NETCA_ASN1_OID_Ptr NETCAAPI netca_x509policyinfo_getid(NETCA_X509_PolicyInformation_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509policyinfo_getqualifiers(NETCA_X509_PolicyInformation_Ptr info);
NETCA_X509_PolicyInformation_Ptr NETCAAPI netca_x509policyinfo_new(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_List_Ptr qualifiers);

int NETCAAPI netca_pkixdisplaytext_gettype(NETCA_PKIX_DisplayText_Ptr text,long *type);
NETCA_ASN1_String_Ptr NETCAAPI netca_pkixdisplaytext_getstring(NETCA_PKIX_DisplayText_Ptr text);
NETCA_PKIX_DisplayText_Ptr NETCAAPI netca_pkixdisplaytext_new(long tagnum,NETCA_ASN1_String_Ptr str);

NETCA_PKIX_DisplayText_Ptr NETCAAPI netca_pkixnoticeref_getorg(NETCA_PKIX_NoticeReference_Ptr ref);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkixnoticeref_getnums(NETCA_PKIX_NoticeReference_Ptr ref);
NETCA_PKIX_NoticeReference_Ptr  NETCAAPI netca_pkixnoticeref_new(NETCA_PKIX_DisplayText_Ptr org,NETCA_ASN1_List_Ptr nums);

NETCA_PKIX_NoticeReference_Ptr NETCAAPI netca_pkixusernotice_getref(NETCA_PKIX_UserNotice_Ptr notice);
NETCA_PKIX_DisplayText_Ptr NETCAAPI netca_pkixusernotice_gettext(NETCA_PKIX_UserNotice_Ptr notice);
NETCA_PKIX_UserNotice_Ptr NETCAAPI netca_pkixusernotice_new(NETCA_PKIX_NoticeReference_Ptr ref,NETCA_PKIX_DisplayText_Ptr text);

NETCA_ASN1_OID_Ptr NETCAAPI netca_x509policymapping_getissuerpolicy(NETCA_X509_PolicyMapping_Ptr map);
NETCA_ASN1_OID_Ptr NETCAAPI netca_x509policymapping_getsubjectpolicy(NETCA_X509_PolicyMapping_Ptr map);
NETCA_X509_PolicyMapping_Ptr NETCAAPI netca_x509policymapping_new(NETCA_ASN1_OID_Ptr issuerpolicy,NETCA_ASN1_OID_Ptr subjectpolicy);


NETCA_X509_BasicConstraints_Ptr NETCAAPI netca_x509basicconstraints_new(NETCA_ASN1_Boolean_Ptr isca,NETCA_ASN1_Integer_Ptr pathlen);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_x509basicconstraints_getisca(NETCA_X509_BasicConstraints_Ptr bc);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509basicconstraints_getlen(NETCA_X509_BasicConstraints_Ptr bc);

NETCA_X509_GeneralName_Ptr NETCAAPI netca_x509gensubtree_getbase(NETCA_X509_GeneralSubtree_Ptr tree);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509gensubtree_getmin(NETCA_X509_GeneralSubtree_Ptr tree);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509gensubtree_getmax(NETCA_X509_GeneralSubtree_Ptr tree);
NETCA_X509_GeneralSubtree_Ptr NETCAAPI netca_x509gensubtree_new(NETCA_X509_GeneralName_Ptr base,NETCA_ASN1_Integer_Ptr min,NETCA_ASN1_Integer_Ptr max);

NETCA_ASN1_BitString_Ptr NETCAAPI netca_x509nameforms_getbasic(NETCA_X509_NameForms_Ptr forms);
NETCA_ASN1_List_Ptr  NETCAAPI netca_x509nameforms_getother(NETCA_X509_NameForms_Ptr forms);
NETCA_X509_NameForms_Ptr NETCAAPI netca_x509nameforms_new(NETCA_ASN1_BitString_Ptr basic,NETCA_ASN1_List_Ptr other);

NETCA_ASN1_List_Ptr NETCAAPI netca_x509namecons_getpermit(NETCA_X509_NameConstraints_Ptr namecons);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509namecons_getexclude(NETCA_X509_NameConstraints_Ptr namecons);
NETCA_X509_NameForms_Ptr NETCAAPI netca_x509namecons_getreqforms(NETCA_X509_NameConstraints_Ptr namecons);
NETCA_X509_NameConstraints_Ptr NETCAAPI netca_x509namecons_new(NETCA_ASN1_List_Ptr permit,NETCA_ASN1_List_Ptr exclude,NETCA_X509_NameForms_Ptr reqforms);

NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509polcons_getreqexppol(NETCA_X509_PolicyConstraints_Ptr polcons);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_x509polcons_getinhibitpolmap(NETCA_X509_PolicyConstraints_Ptr polcons);
NETCA_X509_PolicyConstraints_Ptr NETCAAPI netca_x509polcons_new(NETCA_ASN1_Integer_Ptr reqexppol,NETCA_ASN1_Integer_Ptr inhibitpolmap);

int NETCAAPI netca_x509distpointname_gettype(NETCA_X509_DistributionPointName_Ptr dpname,long *type);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509distpointname_getfullname(NETCA_X509_DistributionPointName_Ptr dpname);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509distpointname_getrelname(NETCA_X509_DistributionPointName_Ptr dpname);
NETCA_X509_DistributionPointName_Ptr NETCAAPI netca_x509distpointname_new_fullname(NETCA_ASN1_List_Ptr fullname);
NETCA_X509_DistributionPointName_Ptr NETCAAPI netca_x509distpointname_new_relname(NETCA_ASN1_List_Ptr relname);

NETCA_X509_DistributionPointName_Ptr NETCAAPI netca_x509distpoint_getname(NETCA_X509_DistributionPoint_Ptr distpoint);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_x509distpoint_getreason(NETCA_X509_DistributionPoint_Ptr distpoint);
NETCA_ASN1_List_Ptr NETCAAPI netca_x509distpoint_getcrlissuer(NETCA_X509_DistributionPoint_Ptr distpoint);
NETCA_X509_DistributionPoint_Ptr NETCAAPI netca_x509distpoint_new(NETCA_X509_DistributionPointName_Ptr dpname,NETCA_ASN1_BitString_Ptr reason,NETCA_ASN1_List_Ptr crlissuer);


NETCA_ASN1_OID_Ptr NETCAAPI netca_pkixaccessdesp_getmethod(NETCA_PKIX_AccessDescription_Ptr desp);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_pkixaccessdesp_getlocate(NETCA_PKIX_AccessDescription_Ptr desp);
NETCA_PKIX_AccessDescription_Ptr NETCAAPI netca_pkixaccessdesp_new(NETCA_ASN1_OID_Ptr method,NETCA_X509_GeneralName_Ptr locate);

NETCA_X509_DistributionPointName_Ptr NETCAAPI netca_pkixidp_getdpname(NETCA_PKIX_IssuingDistributionPoint_Ptr idp);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_pkixidp_getonlycacert(NETCA_PKIX_IssuingDistributionPoint_Ptr idp);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_pkixidp_getonlyusercert(NETCA_PKIX_IssuingDistributionPoint_Ptr idp);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_pkixidp_getonlyattrcert(NETCA_PKIX_IssuingDistributionPoint_Ptr idp);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_pkixidp_getonlysomereason(NETCA_PKIX_IssuingDistributionPoint_Ptr idp);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_pkixidp_getindirectCRL(NETCA_PKIX_IssuingDistributionPoint_Ptr idp);
NETCA_PKIX_IssuingDistributionPoint_Ptr NETCAAPI netca_pkixidp_new(NETCA_X509_DistributionPointName_Ptr dpname,NETCA_ASN1_Boolean_Ptr onlycacert,NETCA_ASN1_Boolean_Ptr onlyusercert,NETCA_ASN1_BitString_Ptr onlysomereason,NETCA_ASN1_Boolean_Ptr indirectCRL);
NETCA_PKIX_IssuingDistributionPoint_Ptr NETCAAPI netca_pkixidp_new2(NETCA_X509_DistributionPointName_Ptr dpname,NETCA_ASN1_Boolean_Ptr onlycacert,NETCA_ASN1_Boolean_Ptr onlyusercert,NETCA_ASN1_BitString_Ptr onlysomereason,NETCA_ASN1_Boolean_Ptr indirectCRL,NETCA_ASN1_Boolean_Ptr onlyContainsAttributeCerts);

NETCA_X509_DistributionPointName_Ptr NETCAAPI netca_x509aaidp_getdpname(NETCA_X509_AAIssuingDistPoint_Ptr aaidp);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_x509aaidp_getcontaacert(NETCA_X509_AAIssuingDistPoint_Ptr aaidp);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_x509aaidp_getcontuserattrcert(NETCA_X509_AAIssuingDistPoint_Ptr aaidp);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_x509aaidp_getcontsoacert(NETCA_X509_AAIssuingDistPoint_Ptr aaidp);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_x509aaidp_getonlysomereason(NETCA_X509_AAIssuingDistPoint_Ptr aaidp);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_x509aaidp_getindirectCRL(NETCA_X509_AAIssuingDistPoint_Ptr aaidp);
NETCA_X509_AAIssuingDistPoint_Ptr NETCAAPI netca_x509aaidp_new(NETCA_X509_DistributionPointName_Ptr dpname,NETCA_ASN1_Boolean_Ptr contaacert,NETCA_ASN1_Boolean_Ptr contuserattrcert,NETCA_ASN1_Boolean_Ptr contsoacert,NETCA_ASN1_BitString_Ptr onlysomereason,NETCA_ASN1_Boolean_Ptr indirectCRL);


NETCA_ASN1_Integer_Ptr NETCAAPI netca_certstore_attr_gettype(NETCA_ASN1_CertStore_Attribute_Ptr attr);
NETCA_ASN1_Any_Ptr NETCAAPI netca_certstore_attr_getvalue(NETCA_ASN1_CertStore_Attribute_Ptr attr);
NETCA_ASN1_CertStore_Attribute_Ptr NETCAAPI netca_certstore_attr_new(NETCA_ASN1_Integer_Ptr type,NETCA_ASN1_Any_Ptr value);

int NETCAAPI netca_certstore_keyid_gettype(NETCA_ASN1_CertStore_KeyId_Ptr keyid);
NETCA_ASN1_String_Ptr NETCAAPI netca_certstore_keyid_getkeyid(NETCA_ASN1_CertStore_KeyId_Ptr keyid);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_certstore_keyid_getalgoid(NETCA_ASN1_CertStore_KeyId_Ptr keyid);
NETCA_ASN1_CertStore_KeyId_Ptr NETCAAPI netca_certstore_keyid_newkeyid(NETCA_ASN1_String_Ptr keyid);
NETCA_ASN1_CertStore_KeyId_Ptr NETCAAPI netca_certstore_keyid_newalgoid(NETCA_X509AlgorithmIdentifier_Ptr algoid);



NETCA_ASN1_String_Ptr NETCAAPI netca_certstore_privkeyattr_getprovider(NETCA_ASN1_CertStore_PrivKeyAttribute_Ptr attr);
NETCA_ASN1_String_Ptr NETCAAPI netca_certstore_privkeyattr_getsubprovider(NETCA_ASN1_CertStore_PrivKeyAttribute_Ptr attr);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_certstore_privkeyattr_getkeytype(NETCA_ASN1_CertStore_PrivKeyAttribute_Ptr attr);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_certstore_privkeyattr_getflag(NETCA_ASN1_CertStore_PrivKeyAttribute_Ptr attr);
NETCA_ASN1_CertStore_KeyId_Ptr NETCAAPI netca_certstore_privkeyattr_getkeyid(NETCA_ASN1_CertStore_PrivKeyAttribute_Ptr attr);
NETCA_ASN1_CertStore_PrivKeyAttribute_Ptr NETCAAPI netca_certstore_privkeyattr_new(NETCA_ASN1_String_Ptr provider,
										   NETCA_ASN1_String_Ptr subprovider,
										   NETCA_ASN1_Integer_Ptr keytype,
										   NETCA_ASN1_Integer_Ptr flag,
										   NETCA_ASN1_CertStore_KeyId_Ptr keyid);


NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_certstore_certwithattr_getcert(NETCA_ASN1_CertStore_CertWithAttribute_Ptr cert);
NETCA_ASN1_List_Ptr NETCAAPI netca_certstore_certwithattr_getattrlist(NETCA_ASN1_CertStore_CertWithAttribute_Ptr cert);
NETCA_ASN1_CertStore_CertWithAttribute_Ptr NETCAAPI netca_certstore_certwithattr_new(NETCA_X509PubKeyCertificate_Ptr cert,NETCA_ASN1_List_Ptr attrlist);

NETCA_PKCS1_OtherPrimeInfo_Ptr NETCAAPI netca_pkcs1otherprimeinfo_new(NETCA_ASN1_Integer_Ptr prime,NETCA_ASN1_Integer_Ptr exponent,
																	  NETCA_ASN1_Integer_Ptr coefficient);
NETCA_ASN1_Integer_Ptr  NETCAAPI netca_pkcs1otherprimeinfo_getprime(NETCA_PKCS1_OtherPrimeInfo_Ptr info);
NETCA_ASN1_Integer_Ptr  NETCAAPI netca_pkcs1otherprimeinfo_getexponent(NETCA_PKCS1_OtherPrimeInfo_Ptr info);
NETCA_ASN1_Integer_Ptr  NETCAAPI netca_pkcs1otherprimeinfo_getcoefficient(NETCA_PKCS1_OtherPrimeInfo_Ptr info);

NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getversion(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getmodulus(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getpublicexponent(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getprivateexponent(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getprime1(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getprime2(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getexponent1(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getexponent2(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsaprivkey_getcoefficient(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkcs1rsaprivkey_getotherprimeinfos(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
int NETCAAPI netca_pkcs1rsaprivkey_hasotherprimeinfos(NETCA_PKCS1_RSAPrivateKey_Ptr privkey);
NETCA_PKCS1_RSAPrivateKey_Ptr NETCAAPI netca_pkcs1rsaprivkey_new(NETCA_ASN1_Integer_Ptr modulus,NETCA_ASN1_Integer_Ptr publicexponent,
																NETCA_ASN1_Integer_Ptr privateexponent,NETCA_ASN1_Integer_Ptr prime1,
																NETCA_ASN1_Integer_Ptr prime2,NETCA_ASN1_Integer_Ptr exponent1,
																NETCA_ASN1_Integer_Ptr exponent2,NETCA_ASN1_Integer_Ptr coefficient,
																NETCA_ASN1_List_Ptr otherprimeinfos);


NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs1rsassapssprarams_gethashalgorithm(NETCA_PKCS1_RSASSA_PSS_prarams_Ptr param);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs1rsassapssprarams_getmaskgenalgorithm(NETCA_PKCS1_RSASSA_PSS_prarams_Ptr param);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsassapssprarams_getsaltlen(NETCA_PKCS1_RSASSA_PSS_prarams_Ptr param);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs1rsassapssprarams_gettrailerfield(NETCA_PKCS1_RSASSA_PSS_prarams_Ptr param);
NETCA_PKCS1_RSASSA_PSS_prarams_Ptr NETCAAPI netca_pkcs1rsassapssprarams_new(NETCA_X509AlgorithmIdentifier_Ptr hashalgo,NETCA_X509AlgorithmIdentifier_Ptr maskgenalgo,
																			NETCA_ASN1_Integer_Ptr saltlen, NETCA_ASN1_Integer_Ptr trailerfield);

NETCA_PKCS1_RSAES_OAEP_prarams_Ptr NETCAAPI netca_pkcs1rsaesoaepprarams_new(NETCA_X509AlgorithmIdentifier_Ptr hashalgo,
																			NETCA_X509AlgorithmIdentifier_Ptr maskgenalgo,
																			NETCA_X509AlgorithmIdentifier_Ptr psourcealgo);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs1rsaesoaepprarams_getmaskgenalgorithm(NETCA_PKCS1_RSAES_OAEP_prarams_Ptr param);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs1rsaesoaepprarams_gethashalgorithm(NETCA_PKCS1_RSAES_OAEP_prarams_Ptr param);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs1rsaesoaepprarams_getpsourcealgorithm(NETCA_PKCS1_RSAES_OAEP_prarams_Ptr param);

NETCA_PKCS3_DHParameter_Ptr netca_pkcs3dhpraram_new(NETCA_ASN1_Integer_Ptr prime,NETCA_ASN1_Integer_Ptr base,NETCA_ASN1_Integer_Ptr privvaluelen);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs3dhpraram_getprime(NETCA_PKCS3_DHParameter_Ptr param);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs3dhpraram_getbase(NETCA_PKCS3_DHParameter_Ptr param);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs3dhpraram_getprivvaluelen(NETCA_PKCS3_DHParameter_Ptr param);
int NETCAAPI netca_pkcs3dhpraram_hasprivvaluelen(NETCA_PKCS3_DHParameter_Ptr param);

NETCA_PKCS8_PrivateKeyInfo_Ptr netca_pkcs8privatekeyinfo_new(NETCA_ASN1_Integer_Ptr version,NETCA_X509AlgorithmIdentifier_Ptr privkeyalgo,
															 NETCA_ASN1_OctetString_Ptr privkey,NETCA_ASN1_List_Ptr attrs);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs8privatekeyinfo_getversion(NETCA_PKCS8_PrivateKeyInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs8privatekeyinfo_getprivkeyalgo(NETCA_PKCS8_PrivateKeyInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs8privatekeyinfo_getprivkey(NETCA_PKCS8_PrivateKeyInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkcs8privatekeyinfo_getattrs(NETCA_PKCS8_PrivateKeyInfo_Ptr info);
int NETCAAPI netca_pkcs8privatekeyinfo_hasattrs(NETCA_PKCS8_PrivateKeyInfo_Ptr info);

NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs8encprivatekeyinfo_getencalgo(NETCA_PKCS8_EncryptedPrivateKeyInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs8encprivatekeyinfo_getencdata(NETCA_PKCS8_EncryptedPrivateKeyInfo_Ptr info);
NETCA_PKCS8_EncryptedPrivateKeyInfo_Ptr NETCAAPI netca_pkcs8encprivatekeyinfo_new(NETCA_X509AlgorithmIdentifier_Ptr encalgo,NETCA_ASN1_OctetString_Ptr encdata);

NETCA_PKCS5_PBKDF2_params_salt_Ptr NETCAAPI netca_pkcs5pbkdf2paramssalt_newvalue(NETCA_ASN1_OctetString_Ptr value);
NETCA_PKCS5_PBKDF2_params_salt_Ptr NETCAAPI netca_pkcs5pbkdf2paramssalt_newother(NETCA_X509AlgorithmIdentifier_Ptr other);
int NETCAAPI netca_pkcs5pbkdf2paramssalt_gettype(NETCA_PKCS5_PBKDF2_params_salt_Ptr salt);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs5pbkdf2paramssalt_getvalue(NETCA_PKCS5_PBKDF2_params_salt_Ptr salt);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs5pbkdf2paramssalt_getother(NETCA_PKCS5_PBKDF2_params_salt_Ptr salt);


NETCA_PKCS5_PBKDF2_params_Ptr  NETCAAPI netca_pkcs5pbkdf2params_new( NETCA_PKCS5_PBKDF2_params_salt_Ptr salt,
																	NETCA_ASN1_Integer_Ptr iterationCount,NETCA_ASN1_Integer_Ptr keyLength,
																	NETCA_X509AlgorithmIdentifier_Ptr prf);
NETCA_PKCS5_PBKDF2_params_salt_Ptr  NETCAAPI netca_pkcs5pbkdf2params_getsalt( NETCA_PKCS5_PBKDF2_params_Ptr param);
NETCA_ASN1_Integer_Ptr  NETCAAPI netca_pkcs5pbkdf2params_getitercount( NETCA_PKCS5_PBKDF2_params_Ptr param);
NETCA_ASN1_Integer_Ptr  NETCAAPI netca_pkcs5pbkdf2params_getkeylen( NETCA_PKCS5_PBKDF2_params_Ptr param);
int  NETCAAPI netca_pkcs5pbkdf2params_haskeylen( NETCA_PKCS5_PBKDF2_params_Ptr param);
NETCA_X509AlgorithmIdentifier_Ptr  NETCAAPI netca_pkcs5pbkdf2params_getprf( NETCA_PKCS5_PBKDF2_params_Ptr param);

NETCA_PKCS5_PBEParameter_Ptr NETCAAPI netca_pkcs5pbeparam_new(NETCA_ASN1_OctetString_Ptr salt,NETCA_ASN1_Integer_Ptr itercount);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs5pbeparam_getsalt(NETCA_PKCS5_PBEParameter_Ptr param);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs5pbeparam_getitercount(NETCA_PKCS5_PBEParameter_Ptr param);


NETCA_PKCS5_PBES2_params_Ptr NETCAAPI netca_pkcs5pbes2params_new(NETCA_X509AlgorithmIdentifier_Ptr keyderivfunc,
																 NETCA_X509AlgorithmIdentifier_Ptr encscheme);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs5pbes2params_getkeyderivfunc(NETCA_PKCS5_PBES2_params_Ptr param);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs5pbes2params_getencscheme(NETCA_PKCS5_PBES2_params_Ptr param);

NETCA_PKCS5_PBMAC1_params_Ptr NETCAAPI netca_pkcs5pbmac1params_new(NETCA_X509AlgorithmIdentifier_Ptr keyderivfunc,
																 NETCA_X509AlgorithmIdentifier_Ptr authscheme);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs5pbmac1params_getkeyderivfunc(NETCA_PKCS5_PBMAC1_params_Ptr param);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs5pbmac1params_getauthscheme(NETCA_PKCS5_PBMAC1_params_Ptr param);

NETCA_PKCS5_RC2_CBC_Parameter_Ptr NETCAAPI netca_pkcs5rc2cbcparameter_new(NETCA_ASN1_Integer_Ptr version,NETCA_ASN1_OctetString_Ptr iv);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs5rc2cbcparameter_getversion(NETCA_PKCS5_RC2_CBC_Parameter_Ptr param);
int NETCAAPI netca_pkcs5rc2cbcparameter_hasversion(NETCA_PKCS5_RC2_CBC_Parameter_Ptr param);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs5rc2cbcparameter_getiv(NETCA_PKCS5_RC2_CBC_Parameter_Ptr param);

NETCA_PKCS5_RC5_CBC_Parameter_Ptr NETCAAPI netca_pkcs5rc5cbcparameter_new(NETCA_ASN1_Integer_Ptr version,
																		  NETCA_ASN1_Integer_Ptr rounds,
																		  NETCA_ASN1_Integer_Ptr blockbits,
																		  NETCA_ASN1_OctetString_Ptr iv);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs5rc5cbcparameter_getversion(NETCA_PKCS5_RC5_CBC_Parameter_Ptr param);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs5rc5cbcparameter_getrounds(NETCA_PKCS5_RC5_CBC_Parameter_Ptr param);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs5rc5cbcparameter_getblockbits(NETCA_PKCS5_RC5_CBC_Parameter_Ptr param);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs5rc5cbcparameter_getiv(NETCA_PKCS5_RC5_CBC_Parameter_Ptr param);
int NETCAAPI netca_pkcs5rc5cbcparameter_hasiv(NETCA_PKCS5_RC5_CBC_Parameter_Ptr param);

NETCA_PKCS7_ContentInfo_Ptr NETCAAPI netca_pkcs7contentinfo_new(NETCA_ASN1_OID_Ptr contenttype,
																NETCA_ASN1_Any_Ptr content);
NETCA_ASN1_OID_Ptr NETCAAPI netca_pkcs7contentinfo_getcontenttype(NETCA_PKCS7_ContentInfo_Ptr info);
NETCA_ASN1_Any_Ptr NETCAAPI netca_pkcs7contentinfo_getcontent(NETCA_PKCS7_ContentInfo_Ptr info);
int NETCAAPI netca_pkcs7contentinfo_hascontent(NETCA_PKCS7_ContentInfo_Ptr info);


NETCA_PKCS7_DigestedData_Ptr NETCAAPI netca_pkcs7digesteddata_new(NETCA_ASN1_Integer_Ptr version,
																  NETCA_X509AlgorithmIdentifier_Ptr digestalgo,
																  NETCA_PKCS7_ContentInfo_Ptr contentinfo,
																  NETCA_ASN1_OctetString_Ptr digest);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs7digesteddata_getversion(NETCA_PKCS7_DigestedData_Ptr data);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_pkcs7digesteddata_getdigestalgo(NETCA_PKCS7_DigestedData_Ptr data);
NETCA_PKCS7_ContentInfo_Ptr NETCAAPI netca_pkcs7digesteddata_getcontentinfo(NETCA_PKCS7_DigestedData_Ptr data);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs7digesteddata_getdigest(NETCA_PKCS7_DigestedData_Ptr data);

NETCA_PKCS12_MacData_Ptr  NETCAAPI netca_pkcs12macdata_new(NETCA_PKCS_DigestInfo_Ptr digest,NETCA_ASN1_OctetString_Ptr salt,
															  NETCA_ASN1_Integer_Ptr itercount);
NETCA_PKCS_DigestInfo_Ptr NETCAAPI netca_pkcs12macdata_getmac(NETCA_PKCS12_MacData_Ptr mac);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs12macdata_getsalt(NETCA_PKCS12_MacData_Ptr mac);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs12macdata_getitercount(NETCA_PKCS12_MacData_Ptr mac);

NETCA_PKCS12_PFX_Ptr  NETCAAPI netca_pkcs12pfx_new(NETCA_ASN1_Integer_Ptr version,NETCA_PKCS7_ContentInfo_Ptr authsafe,
												   NETCA_PKCS12_MacData_Ptr mac);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs12pfx_getversion(NETCA_PKCS12_PFX_Ptr pfx);
NETCA_PKCS7_ContentInfo_Ptr NETCAAPI netca_pkcs12pfx_getauthsafe(NETCA_PKCS12_PFX_Ptr pfx);
NETCA_PKCS12_MacData_Ptr NETCAAPI netca_pkcs12pfx_getmac(NETCA_PKCS12_PFX_Ptr pfx);
int NETCAAPI netca_pkcs12pfx_hasmac(NETCA_PKCS12_PFX_Ptr pfx);


NETCA_PKCS12_SafeBag_Ptr NETCAAPI netca_pkcs12safebag_new(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_Any_Ptr value,NETCA_ASN1_List_Ptr attrs);
NETCA_ASN1_OID_Ptr NETCAAPI netca_pkcs12safebag_getid(NETCA_PKCS12_SafeBag_Ptr bag);
NETCA_ASN1_Any_Ptr NETCAAPI netca_pkcs12safebag_getvalue(NETCA_PKCS12_SafeBag_Ptr bag);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkcs12safebag_getattrs(NETCA_PKCS12_SafeBag_Ptr bag);
int NETCAAPI netca_pkcs12safebag_hasattrs(NETCA_PKCS12_SafeBag_Ptr bag);

NETCA_PKCS12_CertBag_Ptr NETCAAPI netca_pkcs12certbag_new(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_pkcs12certbag_getid(NETCA_PKCS12_CertBag_Ptr bag);
NETCA_ASN1_Any_Ptr NETCAAPI netca_pkcs12certbag_getvalue(NETCA_PKCS12_CertBag_Ptr bag);

NETCA_PKCS12_CRLBag_Ptr NETCAAPI netca_pkcs12crlbag_new(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_pkcs12crlbag_getid(NETCA_PKCS12_CRLBag_Ptr bag);
NETCA_ASN1_Any_Ptr NETCAAPI netca_pkcs12crlbag_getvalue(NETCA_PKCS12_CRLBag_Ptr bag);

NETCA_PKCS12_SecretBag_Ptr NETCAAPI netca_pkcs12secretbag_new(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_pkcs12secretbag_getid(NETCA_PKCS12_SecretBag_Ptr bag);
NETCA_ASN1_Any_Ptr NETCAAPI netca_pkcs12secretbag_getvalue(NETCA_PKCS12_SecretBag_Ptr bag);

NETCA_PKCS12_PbeParams_Ptr NETCAAPI netca_pkcs12pbeparams_new(NETCA_ASN1_OctetString_Ptr salt,NETCA_ASN1_Integer_Ptr itercount);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_pkcs12pbeparams_getsalt(NETCA_PKCS12_PbeParams_Ptr param);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs12pbeparams_getitercount(NETCA_PKCS12_PbeParams_Ptr param);

NETCA_CMS_EncapsulatedContentInfo_Ptr  NETCAAPI netca_cmsencapsulatedcontentinfo_new(NETCA_ASN1_OID_Ptr contenttype,NETCA_ASN1_OctetString_Ptr content);
NETCA_ASN1_OID_Ptr  NETCAAPI netca_cmsencapsulatedcontentinfo_getcontenttype(NETCA_CMS_EncapsulatedContentInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr  NETCAAPI netca_cmsencapsulatedcontentinfo_getcontent(NETCA_CMS_EncapsulatedContentInfo_Ptr info);


NETCA_CMS_IssuerAndSerialNumber_Ptr  NETCAAPI netca_cmsissuerandsn_new(NETCA_X500Name_Ptr issuer,NETCA_ASN1_Integer_Ptr sn);
NETCA_X500Name_Ptr NETCAAPI netca_cmsissuerandsn_getissuer(NETCA_CMS_IssuerAndSerialNumber_Ptr issuersn);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmsissuerandsn_getsn(NETCA_CMS_IssuerAndSerialNumber_Ptr issuersn);

NETCA_CMS_SignerIdentifier_Ptr NETCAAPI netca_cmssignerid_newissuersn(NETCA_CMS_IssuerAndSerialNumber_Ptr issuersn);
NETCA_CMS_SignerIdentifier_Ptr NETCAAPI netca_cmssignerid_newsubkeyid(NETCA_ASN1_OctetString_Ptr keyid);
int NETCAAPI netca_cmssignerid_gettype(NETCA_CMS_SignerIdentifier_Ptr sid);
NETCA_CMS_IssuerAndSerialNumber_Ptr NETCAAPI netca_cmssignerid_getissuersn(NETCA_CMS_SignerIdentifier_Ptr sid);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmssignerid_getkeyid(NETCA_CMS_SignerIdentifier_Ptr sid);


NETCA_CMS_SignerInfo_Ptr NETCAAPI netca_cmssignerinfo_new(NETCA_ASN1_Integer_Ptr version,
														  NETCA_CMS_SignerIdentifier_Ptr sid,
														  NETCA_X509AlgorithmIdentifier_Ptr digestalgo,
														  NETCA_ASN1_List_Ptr signattrs,
														  NETCA_X509AlgorithmIdentifier_Ptr signalgo,
														  NETCA_ASN1_OctetString_Ptr signature,
														  NETCA_ASN1_List_Ptr unsignattrs);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmssignerinfo_getversion(NETCA_CMS_SignerInfo_Ptr signerinfo);
NETCA_CMS_SignerIdentifier_Ptr NETCAAPI netca_cmssignerinfo_getsid(NETCA_CMS_SignerInfo_Ptr signerinfo);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmssignerinfo_getdigestalgo(NETCA_CMS_SignerInfo_Ptr signerinfo);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmssignerinfo_getsignattrs(NETCA_CMS_SignerInfo_Ptr signerinfo);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmssignerinfo_getsignalgo(NETCA_CMS_SignerInfo_Ptr signerinfo);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmssignerinfo_getsignature(NETCA_CMS_SignerInfo_Ptr signerinfo);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmssignerinfo_getunsignattrs(NETCA_CMS_SignerInfo_Ptr signerinfo);
int NETCAAPI netca_cmssignerinfo_hassignattrs(NETCA_CMS_SignerInfo_Ptr signerinfo);
int NETCAAPI netca_cmssignerinfo_hasunsignattrs(NETCA_CMS_SignerInfo_Ptr signerinfo);

NETCA_CMS_OtherCertificateFormat_Ptr NETCAAPI netca_cmsothercertformat_new(NETCA_ASN1_OID_Ptr othercertformat,NETCA_ASN1_Any_Ptr othercert);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cmsothercertformat_getformat(NETCA_CMS_OtherCertificateFormat_Ptr cert);
NETCA_ASN1_Any_Ptr NETCAAPI netca_cmsothercertformat_getothercert(NETCA_CMS_OtherCertificateFormat_Ptr cert);

NETCA_CMS_OtherCertificateFormat_Ptr NETCAAPI netca_cmsothercertformat_new(NETCA_ASN1_OID_Ptr othercertformat,NETCA_ASN1_Any_Ptr othercert);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cmsothercertformat_getformat(NETCA_CMS_OtherCertificateFormat_Ptr cert);
NETCA_ASN1_Any_Ptr NETCAAPI netca_cmsothercertformat_getothercert(NETCA_CMS_OtherCertificateFormat_Ptr cert);

NETCA_CMS_OtherRevocationInfoFormat_Ptr NETCAAPI netca_cmsotherrevinfoformat_new(NETCA_ASN1_OID_Ptr otherrevinfoformat,NETCA_ASN1_Any_Ptr otherrevinfo);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cmsotherrevinfoformat_getformat(NETCA_CMS_OtherRevocationInfoFormat_Ptr revinfo);
NETCA_ASN1_Any_Ptr NETCAAPI netca_cmsotherrevinfoformat_getotherrevinfo(NETCA_CMS_OtherRevocationInfoFormat_Ptr revinfo);


NETCA_CMS_CertificateChoices_Ptr NETCAAPI netca_cmscertchoice_newx509pubkeycert(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_CMS_CertificateChoices_Ptr NETCAAPI netca_cmscertchoice_newothercert(NETCA_CMS_OtherCertificateFormat_Ptr cert);
NETCA_CMS_CertificateChoices_Ptr NETCAAPI netca_cmscertchoice_newv2attrcert(NETCA_ASN1_AttributeCertificate_Ptr cert);
int NETCAAPI netca_cmscertchoice_gettype(NETCA_CMS_CertificateChoices_Ptr cert);
NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_cmscertchoice_getx509pubkeycert(NETCA_CMS_CertificateChoices_Ptr cert);
NETCA_CMS_OtherCertificateFormat_Ptr NETCAAPI netca_cmscertchoice_getothercert(NETCA_CMS_CertificateChoices_Ptr cert);
NETCA_ASN1_AttributeCertificate_Ptr NETCAAPI netca_cmscertchoice_getv2attrcert(NETCA_CMS_CertificateChoices_Ptr cert);


NETCA_CMS_RevocationInfoChoice_Ptr NETCAAPI netca_cmsrevinfochoice_newcrl(NETCA_X509CRL_Ptr crl);
NETCA_CMS_RevocationInfoChoice_Ptr NETCAAPI netca_cmsrevinfochoice_newotherrevinfo(NETCA_CMS_OtherRevocationInfoFormat_Ptr otherinfo);
int NETCAAPI netca_cmsrevinfochoice_gettype(NETCA_CMS_RevocationInfoChoice_Ptr info);
NETCA_X509CRL_Ptr NETCAAPI netca_cmsrevinfochoice_getcrl(NETCA_CMS_RevocationInfoChoice_Ptr info);
NETCA_CMS_OtherRevocationInfoFormat_Ptr NETCAAPI netca_cmsrevinfochoice_getotherrevinfo(NETCA_CMS_RevocationInfoChoice_Ptr info);

NETCA_CMS_SignedData_Ptr NETCAAPI netca_pkcs7signeddata_new(NETCA_ASN1_Integer_Ptr version,NETCA_ASN1_List_Ptr digestalgos,
															NETCA_PKCS7_ContentInfo_Ptr contentinfo,NETCA_ASN1_List_Ptr certs,
															NETCA_ASN1_List_Ptr crls,NETCA_ASN1_List_Ptr signerinfos);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_pkcs7signeddata_getversion(NETCA_CMS_SignedData_Ptr signeddata);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkcs7signeddata_getdigestalgos(NETCA_CMS_SignedData_Ptr signeddata);
NETCA_PKCS7_ContentInfo_Ptr NETCAAPI netca_pkcs7signeddata_getcontentinfo(NETCA_CMS_SignedData_Ptr signeddata);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkcs7signeddata_getcerts(NETCA_CMS_SignedData_Ptr signeddata);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkcs7signeddata_getcrls(NETCA_CMS_SignedData_Ptr signeddata);
NETCA_ASN1_List_Ptr NETCAAPI netca_pkcs7signeddata_getsignerinfos(NETCA_CMS_SignedData_Ptr signeddata);
int NETCAAPI netca_pkcs7signeddata_hascerts(NETCA_CMS_SignedData_Ptr signeddata);
int NETCAAPI netca_pkcs7signeddata_hascrls(NETCA_CMS_SignedData_Ptr signeddata);
//int NETCAAPI netca_asn1_encode(NETCA_STREAM stream,long type,void *value,long *writelen,NETCA_ERR_CTX errctx);
int NETCAAPI netca_asn1_decode_pkcs7signeddata(NETCA_STREAM stream,NETCA_CMS_SignedData_Ptr *signeddata,long *readlen,NETCA_ERR_CTX errctx);
NETCA_CMS_SignedData_Ptr NETCAAPI netca_pkcs7signeddata_new0(NETCA_ASN1_Integer_Ptr version,NETCA_ASN1_List_Ptr digestalgos,
															NETCA_PKCS7_ContentInfo_Ptr contentinfo,NETCA_ASN1_List_Ptr certs,
															NETCA_ASN1_List_Ptr crls,NETCA_ASN1_List_Ptr signerinfos);
int NETCAAPI netca_pkcs7signeddata_gettype(NETCA_CMS_SignedData_Ptr signeddata);
long NETCAAPI netca_pkcs7signeddata_getcontentinfooffset(NETCA_CMS_SignedData_Ptr signeddata);
long NETCAAPI netca_pkcs7signeddata_getcontentinfoendoffset(NETCA_CMS_SignedData_Ptr signeddata);
long NETCAAPI netca_pkcs7signeddata_getsignerinfosoffset(NETCA_CMS_SignedData_Ptr signeddata);


NETCA_CMS_EncryptedContentInfo_Ptr NETCAAPI netca_cmsencryptedcontentinfo_new(NETCA_ASN1_OID_Ptr contentType,
																			  NETCA_X509AlgorithmIdentifier_Ptr algo,
																			  NETCA_ASN1_OctetString_Ptr encryptedContent);
NETCA_CMS_EncryptedContentInfo_Ptr NETCAAPI netca_sm2_cmsencryptedcontentinfo_new(NETCA_ASN1_OID_Ptr contentType,
																			  NETCA_X509AlgorithmIdentifier_Ptr algo,
																			  NETCA_ASN1_OctetString_Ptr encryptedContent,
																			  NETCA_ASN1_OctetString_Ptr sharedInfo1,
																			  NETCA_ASN1_OctetString_Ptr sharedInfo2);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cmsencryptedcontentinfo_gettype(NETCA_CMS_EncryptedContentInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmsencryptedcontentinfo_getalgo(NETCA_CMS_EncryptedContentInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmsencryptedcontentinfo_getenccontent(NETCA_CMS_EncryptedContentInfo_Ptr info);
int NETCAAPI netca_cmsencryptedcontentinfo_hasenccontent(NETCA_CMS_EncryptedContentInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmsencryptedcontentinfo_getsharedinfo1(NETCA_CMS_EncryptedContentInfo_Ptr info);
int NETCAAPI netca_cmsencryptedcontentinfo_hassharedinfo1(NETCA_CMS_EncryptedContentInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmsencryptedcontentinfo_getsharedinfo2(NETCA_CMS_EncryptedContentInfo_Ptr info);
int NETCAAPI netca_cmsencryptedcontentinfo_hassharedinfo2(NETCA_CMS_EncryptedContentInfo_Ptr info);

NETCA_CMS_EncryptedData_Ptr NETCAAPI netca_cmsencrypteddata_new(NETCA_ASN1_Integer_Ptr version,
																NETCA_CMS_EncryptedContentInfo_Ptr encinfo,
																NETCA_ASN1_List_Ptr attr);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmsencrypteddata_getversion(NETCA_CMS_EncryptedData_Ptr encdata);
NETCA_CMS_EncryptedContentInfo_Ptr NETCAAPI netca_cmsencrypteddata_getencinfo(NETCA_CMS_EncryptedData_Ptr encdata);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmsencrypteddata_getattrs(NETCA_CMS_EncryptedData_Ptr encdata);
int NETCAAPI netca_cmsencrypteddata_hasattrs(NETCA_CMS_EncryptedData_Ptr encdata);

NETCA_CMS_OriginatorInfo_Ptr  NETCAAPI netca_cmsoriginatorinfo_new(NETCA_ASN1_List_Ptr certs,NETCA_ASN1_List_Ptr crls);
int NETCAAPI netca_cmsoriginatorinfo_hascerts(NETCA_CMS_OriginatorInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmsoriginatorinfo_getcerts(NETCA_CMS_OriginatorInfo_Ptr info);
int NETCAAPI netca_cmsoriginatorinfo_hascrls(NETCA_CMS_OriginatorInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmsoriginatorinfo_getcrls(NETCA_CMS_OriginatorInfo_Ptr info);


NETCA_CMS_KeyTransRecipientInfo_Ptr NETCAAPI netca_cmskeytransrecipientinfo_new(NETCA_ASN1_Integer_Ptr version,
																				NETCA_CMS_RecipientIdentifier_Ptr rid,
																				NETCA_X509AlgorithmIdentifier_Ptr keyEncryptionAlgorithm,
																				NETCA_ASN1_OctetString_Ptr encryptedKey);

NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmskeytransrecipientinfo_getversion(NETCA_CMS_KeyTransRecipientInfo_Ptr info);
NETCA_CMS_RecipientIdentifier_Ptr NETCAAPI netca_cmskeytransrecipientinfo_getrid(NETCA_CMS_KeyTransRecipientInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmskeytransrecipientinfo_getencalgo(NETCA_CMS_KeyTransRecipientInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmskeytransrecipientinfo_getenckey(NETCA_CMS_KeyTransRecipientInfo_Ptr info);

NETCA_CMS_OriginatorIdentifierOrKey_Ptr NETCAAPI netca_cmsorgidorkey_newissuersn(NETCA_CMS_IssuerAndSerialNumber_Ptr issuersn);
NETCA_CMS_OriginatorIdentifierOrKey_Ptr NETCAAPI netca_cmsorgidorkey_newsubkeyid(NETCA_ASN1_OctetString_Ptr keyid);
NETCA_CMS_OriginatorIdentifierOrKey_Ptr NETCAAPI netca_cmsorgidorkey_neworgkey(NETCA_X509SubjectPublicKeyInfo_Ptr key);
int NETCAAPI netca_cmsorgidorkey_gettype(NETCA_CMS_OriginatorIdentifierOrKey_Ptr id);
NETCA_CMS_IssuerAndSerialNumber_Ptr NETCAAPI netca_cmsorgidorkey_getissuersn(NETCA_CMS_OriginatorIdentifierOrKey_Ptr id);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmsorgidorkey_getsubkeyid(NETCA_CMS_OriginatorIdentifierOrKey_Ptr id);
NETCA_X509SubjectPublicKeyInfo_Ptr NETCAAPI netca_cmsorgidorkey_getorgkey(NETCA_CMS_OriginatorIdentifierOrKey_Ptr id);


NETCA_CMS_OtherKeyAttribute_Ptr NETCAAPI netca_cmsotherkeyattr_new(NETCA_ASN1_OID_Ptr id,NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cmsotherkeyattr_getattrid(NETCA_CMS_OtherKeyAttribute_Ptr attr);
int  NETCAAPI netca_cmsotherkeyattr_hasattrvalue(NETCA_CMS_OtherKeyAttribute_Ptr attr);
NETCA_ASN1_Any_Ptr NETCAAPI netca_cmsotherkeyattr_getattrvalue(NETCA_CMS_OtherKeyAttribute_Ptr attr);


NETCA_CMS_RecipientKeyIdentifier_Ptr NETCAAPI netca_cmsrecipientkeyid_new(NETCA_ASN1_OctetString_Ptr keyid,
																		  NETCA_ASN1_Time_Ptr date,NETCA_CMS_OtherKeyAttribute_Ptr attr);

NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmsrecipientkeyid_getsubkeyid(NETCA_CMS_RecipientKeyIdentifier_Ptr id);
NETCA_ASN1_Time_Ptr NETCAAPI netca_cmsrecipientkeyid_getdate(NETCA_CMS_RecipientKeyIdentifier_Ptr id);
int NETCAAPI netca_cmsrecipientkeyid_hasdate(NETCA_CMS_RecipientKeyIdentifier_Ptr id);
NETCA_CMS_OtherKeyAttribute_Ptr NETCAAPI netca_cmsrecipientkeyid_getotherattr(NETCA_CMS_RecipientKeyIdentifier_Ptr id);
int NETCAAPI netca_cmsrecipientkeyid_hasotherattr(NETCA_CMS_RecipientKeyIdentifier_Ptr id);


NETCA_CMS_KeyAgreeRecipientIdentifier_Ptr NETCAAPI netca_cmskeyagreerecipientid_newissuersn(NETCA_CMS_IssuerAndSerialNumber_Ptr issuersn);
NETCA_CMS_KeyAgreeRecipientIdentifier_Ptr NETCAAPI netca_cmskeyagreerecipientid_newrkeyid(NETCA_CMS_RecipientKeyIdentifier_Ptr rkeyid);
int NETCAAPI netca_cmskeyagreerecipientid_gettype(NETCA_CMS_KeyAgreeRecipientIdentifier_Ptr id);
NETCA_CMS_IssuerAndSerialNumber_Ptr NETCAAPI netca_cmskeyagreerecipientid_getissuersn(NETCA_CMS_KeyAgreeRecipientIdentifier_Ptr id);
NETCA_CMS_RecipientKeyIdentifier_Ptr NETCAAPI netca_cmskeyagreerecipientid_getrkeyid(NETCA_CMS_KeyAgreeRecipientIdentifier_Ptr id);

NETCA_CMS_RecipientEncryptedKey_Ptr NETCAAPI netca_cmsrecipientenckey_new(NETCA_CMS_KeyAgreeRecipientIdentifier_Ptr id,
																NETCA_ASN1_OctetString_Ptr encryptedKey);
NETCA_CMS_KeyAgreeRecipientIdentifier_Ptr NETCAAPI netca_cmsrecipientenckey_getid(NETCA_CMS_RecipientEncryptedKey_Ptr key);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmsrecipientenckey_getenckey(NETCA_CMS_RecipientEncryptedKey_Ptr key);

NETCA_CMS_KeyAgreeRecipientInfo_Ptr NETCAAPI netca_cmskeyagreerecipientinfo_new(NETCA_ASN1_Integer_Ptr version,
																				NETCA_CMS_OriginatorIdentifierOrKey_Ptr originator,
																				NETCA_ASN1_OctetString_Ptr ukm,
																				NETCA_X509AlgorithmIdentifier_Ptr keyEncryptionAlgorithm,
																				NETCA_ASN1_List_Ptr recipientEncryptedKeys);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmskeyagreerecipientinfo_getversion(NETCA_CMS_KeyAgreeRecipientInfo_Ptr info);
NETCA_CMS_OriginatorIdentifierOrKey_Ptr NETCAAPI netca_cmskeyagreerecipientinfo_getoriginator(NETCA_CMS_KeyAgreeRecipientInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmskeyagreerecipientinfo_getukm(NETCA_CMS_KeyAgreeRecipientInfo_Ptr info);
int NETCAAPI netca_cmskeyagreerecipientinfo_hasukm(NETCA_CMS_KeyAgreeRecipientInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmskeyagreerecipientinfo_getencalgo(NETCA_CMS_KeyAgreeRecipientInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmskeyagreerecipientinfo_getenckeys(NETCA_CMS_KeyAgreeRecipientInfo_Ptr info);

NETCA_CMS_KEKRecipientInfo_Ptr NETCAAPI netca_cmskekrecipientinfo_new(NETCA_ASN1_Integer_Ptr version,
																	  NETCA_CMS_KEKIdentifier_Ptr kekid,
																	  NETCA_X509AlgorithmIdentifier_Ptr keyEncryptionAlgorithm,
																	  NETCA_ASN1_OctetString_Ptr encryptedKey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmskekrecipientinfo_getversion(NETCA_CMS_KEKRecipientInfo_Ptr info);
NETCA_CMS_KEKIdentifier_Ptr NETCAAPI netca_cmskekrecipientinfo_getkekid(NETCA_CMS_KEKRecipientInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmskekrecipientinfo_getencalgo(NETCA_CMS_KEKRecipientInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmskekrecipientinfo_getenckey(NETCA_CMS_KEKRecipientInfo_Ptr info);


NETCA_CMS_PasswordRecipientInfo_Ptr NETCAAPI netca_cmspwdrecipientinfo_new(NETCA_ASN1_Integer_Ptr version,
																		   NETCA_X509AlgorithmIdentifier_Ptr keyDerivationAlgorithm,
																		   NETCA_X509AlgorithmIdentifier_Ptr keyEncryptionAlgorithm,
																		   NETCA_ASN1_OctetString_Ptr encryptedKey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmspwdrecipientinfo_getversion(NETCA_CMS_PasswordRecipientInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmspwdrecipientinfo_getderivalgo(NETCA_CMS_PasswordRecipientInfo_Ptr info);
int NETCAAPI netca_cmspwdrecipientinfo_hasderivalgo(NETCA_CMS_PasswordRecipientInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmspwdrecipientinfo_getencalgo(NETCA_CMS_PasswordRecipientInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmspwdrecipientinfo_getenckey(NETCA_CMS_PasswordRecipientInfo_Ptr info);


NETCA_CMS_OtherRecipientInfo_Ptr NETCAAPI netca_cmsotherrecipientinfo_new(NETCA_ASN1_OID_Ptr type,NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cmsotherrecipientinfo_gettype(NETCA_CMS_OtherRecipientInfo_Ptr info);
NETCA_ASN1_Any_Ptr NETCAAPI netca_cmsotherrecipientinfo_getvalue(NETCA_CMS_OtherRecipientInfo_Ptr info);


NETCA_CMS_RecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_newktri(NETCA_CMS_KeyTransRecipientInfo_Ptr ktri);
NETCA_CMS_RecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_newkari(NETCA_CMS_KeyAgreeRecipientInfo_Ptr kari);
NETCA_CMS_RecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_newkekri(NETCA_CMS_KEKRecipientInfo_Ptr kekri);
NETCA_CMS_RecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_newpwri(NETCA_CMS_PasswordRecipientInfo_Ptr pwri);
NETCA_CMS_RecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_newori(NETCA_CMS_OtherRecipientInfo_Ptr ori);
int NETCAAPI netca_cmsrecipientinfo_gettype(NETCA_CMS_RecipientInfo_Ptr info);
NETCA_CMS_KeyTransRecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_getktri( NETCA_CMS_RecipientInfo_Ptr info);
NETCA_CMS_KeyAgreeRecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_getkari( NETCA_CMS_RecipientInfo_Ptr info);
NETCA_CMS_KEKRecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_getkekri( NETCA_CMS_RecipientInfo_Ptr info);
NETCA_CMS_PasswordRecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_getpwri( NETCA_CMS_RecipientInfo_Ptr info);
NETCA_CMS_OtherRecipientInfo_Ptr NETCAAPI netca_cmsrecipientinfo_getori( NETCA_CMS_RecipientInfo_Ptr info);

NETCA_CMS_EnvelopedData_Ptr NETCAAPI netca_cmsenvelopeddata_new(NETCA_ASN1_Integer_Ptr version,
																NETCA_CMS_OriginatorInfo_Ptr originator,
																NETCA_ASN1_List_Ptr recipientinfos,
																NETCA_CMS_EncryptedContentInfo_Ptr encryptedContentInfo,
																NETCA_ASN1_List_Ptr unprotectedAttrs);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmsenvelopeddata_getversion(NETCA_CMS_EnvelopedData_Ptr env);
NETCA_CMS_OriginatorInfo_Ptr NETCAAPI netca_cmsenvelopeddata_getoriginator(NETCA_CMS_EnvelopedData_Ptr env);
int NETCAAPI netca_cmsenvelopeddata_hasoriginator(NETCA_CMS_EnvelopedData_Ptr env);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmsenvelopeddata_getrecipinfos(NETCA_CMS_EnvelopedData_Ptr env);
NETCA_CMS_EncryptedContentInfo_Ptr NETCAAPI netca_cmsenvelopeddata_getencinfo(NETCA_CMS_EnvelopedData_Ptr env);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmsenvelopeddata_getattrs(NETCA_CMS_EnvelopedData_Ptr env);
int NETCAAPI netca_cmsenvelopeddata_hasattrs(NETCA_CMS_EnvelopedData_Ptr env);



NETCA_CMS_AuthenticatedData_Ptr NETCAAPI netca_cmsauthdata_new(NETCA_ASN1_Integer_Ptr version,
														NETCA_CMS_OriginatorInfo_Ptr originator,
														NETCA_ASN1_List_Ptr recipientinfos,
														NETCA_X509AlgorithmIdentifier_Ptr macalgo,
														NETCA_X509AlgorithmIdentifier_Ptr hashalgo,
														NETCA_CMS_EncapsulatedContentInfo_Ptr encapinfo,
														NETCA_ASN1_List_Ptr authattrs,
														NETCA_ASN1_OctetString_Ptr mac,
														NETCA_ASN1_List_Ptr unauthattrs);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cmsauthdata_getversion(NETCA_CMS_AuthenticatedData_Ptr auth);
NETCA_CMS_OriginatorInfo_Ptr NETCAAPI netca_cmsauthdata_getoriginator(NETCA_CMS_AuthenticatedData_Ptr auth);
int NETCAAPI netca_cmsauthdata_hasoriginator(NETCA_CMS_AuthenticatedData_Ptr auth);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmsauthdata_getrecipinfos(NETCA_CMS_AuthenticatedData_Ptr auth);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmsauthdata_getmacalgo(NETCA_CMS_AuthenticatedData_Ptr auth);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmsauthdata_gethashalgo(NETCA_CMS_AuthenticatedData_Ptr auth);
int NETCAAPI netca_cmsauthdata_hashashalgo(NETCA_CMS_AuthenticatedData_Ptr auth);
NETCA_CMS_EncapsulatedContentInfo_Ptr NETCAAPI netca_cmsauthdata_getencapinfo(NETCA_CMS_AuthenticatedData_Ptr auth);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmsauthdata_getauthatrrs(NETCA_CMS_AuthenticatedData_Ptr auth);
int NETCAAPI netca_cmsauthdata_hasauthatrrs(NETCA_CMS_AuthenticatedData_Ptr auth);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cmsauthdata_getmac(NETCA_CMS_AuthenticatedData_Ptr auth);
NETCA_ASN1_List_Ptr NETCAAPI netca_cmsauthdata_getunauthatrrs(NETCA_CMS_AuthenticatedData_Ptr auth);
int NETCAAPI netca_cmsauthdata_hasunauthatrrs(NETCA_CMS_AuthenticatedData_Ptr auth);


NETCA_DH_KeySpecificInfo_Ptr NETCAAPI netca_dhkeyspecinfo_new(NETCA_ASN1_OID_Ptr algorithm,NETCA_ASN1_OctetString_Ptr counter);
NETCA_ASN1_OID_Ptr NETCAAPI netca_dhkeyspecinfo_getalgo(NETCA_DH_KeySpecificInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_dhkeyspecinfo_getcount(NETCA_DH_KeySpecificInfo_Ptr info);


NETCA_DH_OtherInfo_Ptr NETCAAPI netca_dhotherinfo_new(NETCA_DH_KeySpecificInfo_Ptr keyspec,NETCA_ASN1_OctetString_Ptr partyAInfo,
													  NETCA_ASN1_OctetString_Ptr suppPubInfo);
NETCA_DH_KeySpecificInfo_Ptr NETCAAPI netca_dhotherinfo_getkeyspec(NETCA_DH_OtherInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_dhotherinfo_getpartyainfo(NETCA_DH_OtherInfo_Ptr info);
int NETCAAPI netca_dhotherinfo_haspartyainfo(NETCA_DH_OtherInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_dhotherinfo_getsupppubinfo(NETCA_DH_OtherInfo_Ptr info);


NETCA_ASN1_OCSP_CertID_Ptr NETCAAPI netca_ocsp_certid_new(NETCA_X509AlgorithmIdentifier_Ptr hashAlgorithm,
														  NETCA_ASN1_OctetString_Ptr issuerNameHash,
														  NETCA_ASN1_OctetString_Ptr issuerKeyHash,
														  NETCA_ASN1_Integer_Ptr serialNumber);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_ocsp_certid_gethashalgo(NETCA_ASN1_OCSP_CertID_Ptr certid);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ocsp_certid_getissuernamehash(NETCA_ASN1_OCSP_CertID_Ptr certid);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ocsp_certid_getissuerkeyhash(NETCA_ASN1_OCSP_CertID_Ptr certid);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ocsp_certid_getsn(NETCA_ASN1_OCSP_CertID_Ptr certid);


NETCA_ASN1_OCSP_Request_Ptr NETCAAPI netca_ocsp_request_new(NETCA_ASN1_OCSP_CertID_Ptr reqCert,
														  NETCA_ASN1_List_Ptr singleRequestExtensions);
NETCA_ASN1_OCSP_CertID_Ptr NETCAAPI netca_ocsp_request_getcertid(NETCA_ASN1_OCSP_Request_Ptr req);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsp_request_getexts(NETCA_ASN1_OCSP_Request_Ptr req);


NETCA_ASN1_OCSP_TBSRequest_Ptr NETCAAPI netca_ocsp_tbsrequest_new(NETCA_ASN1_Integer_Ptr version,
														  NETCA_X509_GeneralName_Ptr requestorName,
														  NETCA_ASN1_List_Ptr requestList,
														  NETCA_ASN1_List_Ptr requestExtensions);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ocsp_tbsrequest_getversion(NETCA_ASN1_OCSP_TBSRequest_Ptr tbs);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_ocsp_tbsrequest_getname(NETCA_ASN1_OCSP_TBSRequest_Ptr tbs);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsp_tbsrequest_getreqlist(NETCA_ASN1_OCSP_TBSRequest_Ptr tbs);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsp_tbsrequest_getexts(NETCA_ASN1_OCSP_TBSRequest_Ptr tbs);


NETCA_ASN1_OCSP_Signature_Ptr NETCAAPI netca_ocsp_signature_new(NETCA_X509AlgorithmIdentifier_Ptr signatureAlgorithm,
																NETCA_ASN1_BitString_Ptr signature,
																NETCA_ASN1_List_Ptr certs);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_ocsp_signature_getsignalgo(NETCA_ASN1_OCSP_Signature_Ptr sign);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_ocsp_signature_getsignature(NETCA_ASN1_OCSP_Signature_Ptr sign);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsp_signature_getcerts(NETCA_ASN1_OCSP_Signature_Ptr sign);


NETCA_ASN1_OCSP_OCSPRequest_Ptr NETCAAPI netca_ocsp_ocsprequest_new(NETCA_ASN1_OCSP_TBSRequest_Ptr tbs,
																NETCA_ASN1_OCSP_Signature_Ptr signature);
NETCA_ASN1_OCSP_TBSRequest_Ptr NETCAAPI netca_ocsp_ocsprequest_gettbs(NETCA_ASN1_OCSP_OCSPRequest_Ptr req);
NETCA_ASN1_OCSP_Signature_Ptr NETCAAPI netca_ocsp_ocsprequest_getsignature(NETCA_ASN1_OCSP_OCSPRequest_Ptr req);


NETCA_ASN1_OCSP_ResponseBytes_Ptr NETCAAPI netca_ocsp_responsebytes_new(NETCA_ASN1_OID_Ptr responseType,
																		NETCA_ASN1_OctetString_Ptr response);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ocsp_responsebytes_gettype(NETCA_ASN1_OCSP_ResponseBytes_Ptr bytes);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ocsp_responsebytes_getresponse(NETCA_ASN1_OCSP_ResponseBytes_Ptr bytes);

NETCA_ASN1_OCSP_OCSPResponse_Ptr NETCAAPI netca_ocsp_ocspresponse_new(NETCA_ASN1_Enum_Ptr responseStatus,
																	  NETCA_ASN1_OCSP_ResponseBytes_Ptr responseBytes);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_ocsp_ocspresponse_getstatus(NETCA_ASN1_OCSP_OCSPResponse_Ptr resp);
NETCA_ASN1_OCSP_ResponseBytes_Ptr NETCAAPI netca_ocsp_ocspresponse_getresponse(NETCA_ASN1_OCSP_OCSPResponse_Ptr resp);

NETCA_ASN1_OCSP_ResponderID_Ptr NETCAAPI netca_ocsp_responderid_newname(NETCA_X500Name_Ptr name);
NETCA_ASN1_OCSP_ResponderID_Ptr NETCAAPI netca_ocsp_responderid_newkeyhash(NETCA_ASN1_OctetString_Ptr keyhash);
int NETCAAPI  netca_ocsp_responderid_gettype(NETCA_ASN1_OCSP_ResponderID_Ptr id);
NETCA_X500Name_Ptr NETCAAPI  netca_ocsp_responderid_getname(NETCA_ASN1_OCSP_ResponderID_Ptr id);
NETCA_ASN1_OctetString_Ptr NETCAAPI  netca_ocsp_responderid_getkeyhash(NETCA_ASN1_OCSP_ResponderID_Ptr id);


NETCA_ASN1_OCSP_RevokedInfo_Ptr NETCAAPI netca_ocsp_revokedinfo_new(NETCA_ASN1_Time_Ptr revocationTime,
																	  NETCA_ASN1_Enum_Ptr revocationReason);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ocsp_revokedinfo_gettime(NETCA_ASN1_OCSP_RevokedInfo_Ptr info);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_ocsp_revokedinfo_getreason(NETCA_ASN1_OCSP_RevokedInfo_Ptr info);

NETCA_ASN1_OCSP_CertStatus_Ptr NETCAAPI netca_ocsp_certstatus_newgood(void);
NETCA_ASN1_OCSP_CertStatus_Ptr NETCAAPI netca_ocsp_certstatus_newrevoked(NETCA_ASN1_OCSP_RevokedInfo_Ptr revinfo);
NETCA_ASN1_OCSP_CertStatus_Ptr NETCAAPI netca_ocsp_certstatus_newunknown(void);
int NETCAAPI netca_ocsp_certstatus_gettype(NETCA_ASN1_OCSP_CertStatus_Ptr status);
NETCA_ASN1_OCSP_RevokedInfo_Ptr NETCAAPI netca_ocsp_certstatus_getrevoked(NETCA_ASN1_OCSP_CertStatus_Ptr status);


NETCA_ASN1_OCSP_SingleResponse_Ptr NETCAAPI netca_ocsp_singleresponse_new(NETCA_ASN1_OCSP_CertID_Ptr certID,
																	  NETCA_ASN1_OCSP_CertStatus_Ptr certStatus,
																	  NETCA_ASN1_Time_Ptr thisUpdate,
																	  NETCA_ASN1_Time_Ptr nextUpdate,
																	  NETCA_ASN1_List_Ptr singleExtensions);
NETCA_ASN1_OCSP_CertID_Ptr NETCAAPI netca_ocsp_singleresponse_getcertid(NETCA_ASN1_OCSP_SingleResponse_Ptr resp);
NETCA_ASN1_OCSP_CertStatus_Ptr NETCAAPI netca_ocsp_singleresponse_getcertstatus(NETCA_ASN1_OCSP_SingleResponse_Ptr resp);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ocsp_singleresponse_getthisupdate(NETCA_ASN1_OCSP_SingleResponse_Ptr resp);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ocsp_singleresponse_getnextupdate(NETCA_ASN1_OCSP_SingleResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsp_singleresponse_getexts(NETCA_ASN1_OCSP_SingleResponse_Ptr resp);



NETCA_ASN1_OCSP_ResponseData_Ptr NETCAAPI netca_ocsp_responsedata_new(NETCA_ASN1_Integer_Ptr version,
																	  NETCA_ASN1_OCSP_ResponderID_Ptr responderID,
																	  NETCA_ASN1_Time_Ptr producedAt,
																	  NETCA_ASN1_List_Ptr responses,
																	  NETCA_ASN1_List_Ptr responseExtensions);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ocsp_responsedata_getversion(NETCA_ASN1_OCSP_ResponseData_Ptr data);
NETCA_ASN1_OCSP_ResponderID_Ptr NETCAAPI netca_ocsp_responsedata_getrespid(NETCA_ASN1_OCSP_ResponseData_Ptr data);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ocsp_responsedata_getproducedat(NETCA_ASN1_OCSP_ResponseData_Ptr data);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsp_responsedata_getresponses(NETCA_ASN1_OCSP_ResponseData_Ptr data);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsp_responsedata_getexts(NETCA_ASN1_OCSP_ResponseData_Ptr data);


NETCA_ASN1_OCSP_BasicOCSPResponse_Ptr NETCAAPI netca_ocsp_basicocspresponse_new(NETCA_ASN1_OCSP_ResponseData_Ptr tbsResponseData,
																	  NETCA_X509AlgorithmIdentifier_Ptr signatureAlgorithm,
																	  NETCA_ASN1_BitString_Ptr signature,
																	  NETCA_ASN1_List_Ptr certs);
NETCA_ASN1_OCSP_ResponseData_Ptr NETCAAPI netca_ocsp_basicocspresponse_gettbs(NETCA_ASN1_OCSP_BasicOCSPResponse_Ptr resp);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_ocsp_basicocspresponse_getsignalgo(NETCA_ASN1_OCSP_BasicOCSPResponse_Ptr resp);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_ocsp_basicocspresponse_getsignature(NETCA_ASN1_OCSP_BasicOCSPResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsp_basicocspresponse_getcerts(NETCA_ASN1_OCSP_BasicOCSPResponse_Ptr resp);
int NETCAAPI netca_ocsp_basicocspresponse_gettbsocts(NETCA_ASN1_OCSP_BasicOCSPResponse_Ptr resp,unsigned char *data,long *datalen);

NETCA_ASN1_OCSP_CrlID_Ptr NETCAAPI netca_ocsp_crlid_new(NETCA_ASN1_String_Ptr crlUrl,
														NETCA_ASN1_Integer_Ptr crlNum,
														NETCA_ASN1_Time_Ptr crlTime);
NETCA_ASN1_String_Ptr NETCAAPI netca_ocsp_crlid_geturl(NETCA_ASN1_OCSP_CrlID_Ptr crlid);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ocsp_crlid_getnum(NETCA_ASN1_OCSP_CrlID_Ptr crlid);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ocsp_crlid_gettime(NETCA_ASN1_OCSP_CrlID_Ptr crlid);


NETCA_ASN1_TSP_TimeStampReq_Ptr NETCAAPI netca_tsp_timestampreq_new(NETCA_ASN1_Integer_Ptr version,
														NETCA_ASN1_TSP_MessageImprint_Ptr messageImprint,
														NETCA_ASN1_OID_Ptr reqPolicy,
														NETCA_ASN1_Integer_Ptr nonce,
														NETCA_ASN1_Boolean_Ptr certReq,
														NETCA_ASN1_List_Ptr extensions);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_timestampreq_getversion(NETCA_ASN1_TSP_TimeStampReq_Ptr req);
NETCA_ASN1_TSP_MessageImprint_Ptr NETCAAPI netca_tsp_timestampreq_getmessageimprint(NETCA_ASN1_TSP_TimeStampReq_Ptr req);
NETCA_ASN1_OID_Ptr NETCAAPI netca_tsp_timestampreq_getpolicy(NETCA_ASN1_TSP_TimeStampReq_Ptr req);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_timestampreq_getnonce(NETCA_ASN1_TSP_TimeStampReq_Ptr req);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_tsp_timestampreq_getcertreq(NETCA_ASN1_TSP_TimeStampReq_Ptr req);
NETCA_ASN1_List_Ptr NETCAAPI netca_tsp_timestampreq_getexts(NETCA_ASN1_TSP_TimeStampReq_Ptr req);


NETCA_ASN1_TSP_PKIStatusInfo_Ptr NETCAAPI netca_tsp_pkistatusinfo_new(NETCA_ASN1_Integer_Ptr status,
																	  NETCA_ASN1_List_Ptr statusString,
																	  NETCA_ASN1_BitString_Ptr failInfo);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_pkistatusinfo_getstatus(NETCA_ASN1_TSP_PKIStatusInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_tsp_pkistatusinfo_getstatusstring(NETCA_ASN1_TSP_PKIStatusInfo_Ptr info);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_tsp_pkistatusinfo_getfailinfo(NETCA_ASN1_TSP_PKIStatusInfo_Ptr info);


NETCA_ASN1_TSP_TimeStampResp_Ptr NETCAAPI netca_tsp_timestampresp_new(NETCA_ASN1_TSP_PKIStatusInfo_Ptr status,
																	  NETCA_PKCS7_ContentInfo_Ptr timeStampToken);
NETCA_ASN1_TSP_PKIStatusInfo_Ptr NETCAAPI netca_tsp_timestampresp_getstatus(NETCA_ASN1_TSP_TimeStampResp_Ptr resp);
NETCA_PKCS7_ContentInfo_Ptr NETCAAPI netca_tsp_timestampresp_gettoken(NETCA_ASN1_TSP_TimeStampResp_Ptr resp);


NETCA_ASN1_TSP_Accuracy_Ptr NETCAAPI netca_tsp_accuracy_new(NETCA_ASN1_Integer_Ptr seconds,
																	  NETCA_ASN1_Integer_Ptr millis,
																	  NETCA_ASN1_Integer_Ptr micros);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_accuracy_getseconds(NETCA_ASN1_TSP_Accuracy_Ptr accurary);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_accuracy_getmillis(NETCA_ASN1_TSP_Accuracy_Ptr accurary);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_accuracy_getmicros(NETCA_ASN1_TSP_Accuracy_Ptr accurary);


NETCA_ASN1_TSP_TSTInfo_Ptr NETCAAPI netca_tsp_tstinfo_new(NETCA_ASN1_Integer_Ptr version,
														   NETCA_ASN1_OID_Ptr policy,
														   NETCA_ASN1_TSP_MessageImprint_Ptr messageImprint,
														   NETCA_ASN1_Integer_Ptr serialNumber,
														   NETCA_ASN1_Time_Ptr genTime,
														   NETCA_ASN1_TSP_Accuracy_Ptr accuracy,
														   NETCA_ASN1_Boolean_Ptr ordering,
														   NETCA_ASN1_Integer_Ptr nonce,
														   NETCA_X509_GeneralName_Ptr tsaname,
														   NETCA_ASN1_List_Ptr extensions);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_tstinfo_getversion(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_ASN1_OID_Ptr NETCAAPI netca_tsp_tstinfo_getpolicy(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_ASN1_TSP_MessageImprint_Ptr NETCAAPI netca_tsp_tstinfo_getmessageimprint(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_tstinfo_getsn(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_ASN1_Time_Ptr NETCAAPI netca_tsp_tstinfo_getgentime(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_ASN1_TSP_Accuracy_Ptr NETCAAPI netca_tsp_tstinfo_getaccuracy(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_tsp_tstinfo_getordering(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_tsp_tstinfo_getnonce(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_tsp_tstinfo_gettsaname(NETCA_ASN1_TSP_TSTInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_tsp_tstinfo_getexts(NETCA_ASN1_TSP_TSTInfo_Ptr info);


NETCA_ASN1_ESSIssuerSerial_Ptr NETCAAPI netca_ess_issuerserial_new(NETCA_ASN1_List_Ptr issuer,
														   NETCA_ASN1_Integer_Ptr serialNumber);
NETCA_ASN1_List_Ptr NETCAAPI netca_ess_issuerserial_getissuer(NETCA_ASN1_ESSIssuerSerial_Ptr issuersn);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ess_issuerserial_getsn(NETCA_ASN1_ESSIssuerSerial_Ptr issuersn);

NETCA_ASN1_ESSCertID_Ptr NETCAAPI netca_ess_certid_new(NETCA_ASN1_OctetString_Ptr certhash,
														   NETCA_ASN1_ESSIssuerSerial_Ptr issuersn);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ess_certid_getcerthash(NETCA_ASN1_ESSCertID_Ptr certid);
NETCA_ASN1_ESSIssuerSerial_Ptr NETCAAPI netca_ess_certid_getissuersn(NETCA_ASN1_ESSCertID_Ptr certid);


NETCA_ASN1_ESSCertIDV2_Ptr NETCAAPI netca_ess_certidv2_new(NETCA_X509AlgorithmIdentifier_Ptr hashAlgorithm,
													   NETCA_ASN1_OctetString_Ptr certhash,
													   NETCA_ASN1_ESSIssuerSerial_Ptr issuersn);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_ess_certidv2_getcerthashalgo(NETCA_ASN1_ESSCertIDV2_Ptr certid);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ess_certidv2_getcerthash(NETCA_ASN1_ESSCertIDV2_Ptr certid);
NETCA_ASN1_ESSIssuerSerial_Ptr NETCAAPI netca_ess_certidv2_getissuersn(NETCA_ASN1_ESSCertIDV2_Ptr certid);


NETCA_ASN1_ESSSigningCertificate_Ptr NETCAAPI netca_ess_signingcertificate_new(NETCA_ASN1_List_Ptr certs,
													   NETCA_ASN1_List_Ptr policies);
NETCA_ASN1_ESSSigningCertificate_Ptr NETCAAPI netca_ess_signingcertificatev2_new(NETCA_ASN1_List_Ptr certs,
													   NETCA_ASN1_List_Ptr policies);
NETCA_ASN1_List_Ptr NETCAAPI netca_ess_signingcertificate_getcerts(NETCA_ASN1_ESSSigningCertificate_Ptr cert);
NETCA_ASN1_List_Ptr NETCAAPI netca_ess_signingcertificate_getpolicies(NETCA_ASN1_ESSSigningCertificate_Ptr cert);


NETCA_EcpkParameters_Ptr NETCAAPI netca_ecpkparameters_new_namedcurve(NETCA_ASN1_OID_Ptr namedcurve);
NETCA_EcpkParameters_Ptr NETCAAPI netca_ecpkparameters_new_implicitlyca(void);
int NETCAAPI netca_ecpkparameters_gettype(NETCA_EcpkParameters_Ptr param,long *type);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ecpkparameters_namedcurve(NETCA_EcpkParameters_Ptr param);


NETCA_ECPrivateKey_Ptr NETCAAPI netca_ecprivatekey_new(NETCA_ASN1_Integer_Ptr version,NETCA_ASN1_OctetString_Ptr privateKey,
												NETCA_EcpkParameters_Ptr parameters,NETCA_ASN1_BitString_Ptr publicKey);
NETCA_ECPrivateKey_Ptr NETCAAPI netca_ecprivatekey_newsm2(NETCA_ASN1_Integer_Ptr version,NETCA_ASN1_Integer_Ptr privateKey,
												NETCA_EcpkParameters_Ptr parameters,NETCA_ASN1_BitString_Ptr publicKey);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ecprivatekey_getversion(NETCA_ECPrivateKey_Ptr key);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ecprivatekey_getprivkey(NETCA_ECPrivateKey_Ptr key);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ecprivatekey_getsm2privkey(NETCA_ECPrivateKey_Ptr key);
int NETCAAPI netca_ecprivatekey_issm2privkey(NETCA_ECPrivateKey_Ptr key);
NETCA_EcpkParameters_Ptr NETCAAPI netca_ecprivatekey_getparam(NETCA_ECPrivateKey_Ptr key);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_ecprivatekey_getpubkey(NETCA_ECPrivateKey_Ptr key);

NETCA_SM2Cipher_Ptr NETCAAPI netca_sm2cipher_new(NETCA_ASN1_Integer_Ptr x,NETCA_ASN1_Integer_Ptr y,
												 NETCA_ASN1_OctetString_Ptr hash,NETCA_ASN1_OctetString_Ptr cipherText);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_sm2cipher_getx(NETCA_SM2Cipher_Ptr cipher);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_sm2cipher_gety(NETCA_SM2Cipher_Ptr cipher);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_sm2cipher_gethash(NETCA_SM2Cipher_Ptr cipher);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_sm2cipher_getciphertext(NETCA_SM2Cipher_Ptr cipher);


NETCA_SM2EnvelopedKey_Ptr NETCAAPI netca_sm2envelopedkey_new(NETCA_X509AlgorithmIdentifier_Ptr symAlgID,
															 NETCA_SM2Cipher_Ptr symEncryptedKey,
															 NETCA_ASN1_BitString_Ptr sm2PublicKey,
															 NETCA_ASN1_BitString_Ptr sm2EncryptedPrivateKey);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_sm2envelopedkey_getsymalgid(NETCA_SM2EnvelopedKey_Ptr key);
NETCA_SM2Cipher_Ptr NETCAAPI netca_sm2envelopedkey_getsymencryptedkey(NETCA_SM2EnvelopedKey_Ptr key);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_sm2envelopedkey_getsm2publickey(NETCA_SM2EnvelopedKey_Ptr key);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_sm2envelopedkey_getsm2encryptedprivatekey(NETCA_SM2EnvelopedKey_Ptr key);

NETCA_RSAEnvelopedKeyPair_Ptr NETCAAPI netca_rsaenvelopedkeypair_new(NETCA_X509AlgorithmIdentifier_Ptr symAlgID,
															 NETCA_ASN1_OctetString_Ptr symEncryptedKey,
															 NETCA_PKCS1_RSAPublicKey_Ptr rsaPublicKey,
															 NETCA_ASN1_OctetString_Ptr rsaEncryptedPrivateKey);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_rsaenvelopedkeypair_getsymalgid(NETCA_RSAEnvelopedKeyPair_Ptr key);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_rsaenvelopedkeypair_getsymencryptedkey(NETCA_RSAEnvelopedKeyPair_Ptr key);
NETCA_PKCS1_RSAPublicKey_Ptr NETCAAPI netca_rsaenvelopedkeypair_getrsapublickey(NETCA_RSAEnvelopedKeyPair_Ptr key);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_rsaenvelopedkeypair_getrsaencryptedprivatekey(NETCA_RSAEnvelopedKeyPair_Ptr key);

NETCA_ECCEnvelopedKey_Ptr NETCAAPI netca_eccenvelopedkeypair_new(NETCA_X509AlgorithmIdentifier_Ptr symAlgID,
															 NETCA_X509SubjectPublicKeyInfo_Ptr originatorKey,
															 NETCA_X509AlgorithmIdentifier_Ptr hashAlgo,
															 NETCA_ASN1_ECC_CMS_SharedInfo_Ptr sharedInfo,
															 NETCA_ASN1_OctetString_Ptr encryptedKey,
															 NETCA_ASN1_OctetString_Ptr eccPublicKey,
															 NETCA_ASN1_OctetString_Ptr eccEncryptedPrivateKey);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_eccenvelopedkeypair_getsymalgid(NETCA_ECCEnvelopedKey_Ptr key);
NETCA_X509SubjectPublicKeyInfo_Ptr NETCAAPI netca_eccenvelopedkeypair_getoriginatorkey(NETCA_ECCEnvelopedKey_Ptr key);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_eccenvelopedkeypair_gethashalgo(NETCA_ECCEnvelopedKey_Ptr key);
NETCA_ASN1_ECC_CMS_SharedInfo_Ptr NETCAAPI netca_eccenvelopedkeypair_getsharedinfo(NETCA_ECCEnvelopedKey_Ptr key);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_eccenvelopedkeypair_getencryptedkey(NETCA_ECCEnvelopedKey_Ptr key);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_eccenvelopedkeypair_geteccpublickey(NETCA_ECCEnvelopedKey_Ptr key);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_eccenvelopedkeypair_geteccencryptedprivatekey(NETCA_ECCEnvelopedKey_Ptr key);


NETCA_InnerEnvelopedKeyPair_Ptr NETCAAPI netca_innerenvelopedkeypair_newrsa(NETCA_RSAEnvelopedKeyPair_Ptr rsa);
NETCA_InnerEnvelopedKeyPair_Ptr NETCAAPI netca_innerenvelopedkeypair_newsm2(NETCA_SM2EnvelopedKey_Ptr sm2);
NETCA_InnerEnvelopedKeyPair_Ptr NETCAAPI netca_innerenvelopedkeypair_newecc(NETCA_ECCEnvelopedKey_Ptr ecc);
long NETCAAPI netca_innerenvelopedkeypair_gettype(NETCA_InnerEnvelopedKeyPair_Ptr key);
NETCA_RSAEnvelopedKeyPair_Ptr NETCAAPI netca_innerenvelopedkeypair_getrsa(NETCA_InnerEnvelopedKeyPair_Ptr key);
NETCA_SM2EnvelopedKey_Ptr NETCAAPI netca_innerenvelopedkeypair_getsm2(NETCA_InnerEnvelopedKeyPair_Ptr key);
NETCA_ECCEnvelopedKey_Ptr NETCAAPI netca_innerenvelopedkeypair_getecc(NETCA_InnerEnvelopedKeyPair_Ptr key);


NETCA_EnvelopedKeyPair_Ptr NETCAAPI netca_envelopedkeypair_new(NETCA_X509SubjectPublicKeyInfo_Ptr signPubKey,
															 NETCA_InnerEnvelopedKeyPair_Ptr envkeyPair);
NETCA_X509SubjectPublicKeyInfo_Ptr NETCAAPI netca_envelopedkeypair_getsignpubkey(NETCA_EnvelopedKeyPair_Ptr key);
NETCA_InnerEnvelopedKeyPair_Ptr NETCAAPI netca_envelopedkeypair_getenvkeypair(NETCA_EnvelopedKeyPair_Ptr key);

NETCA_ASN1_SpcIndirectDataContent_Ptr NETCAAPI netca_spcindirectdatacontent_new(NETCA_ASN1_SpcAttributeTypeAndOptionalValue_Ptr data,
															 NETCA_PKCS_DigestInfo_Ptr messageDigest);
NETCA_ASN1_SpcAttributeTypeAndOptionalValue_Ptr NETCAAPI netca_spcindirectdatacontent_getdata(NETCA_ASN1_SpcIndirectDataContent_Ptr content);
NETCA_PKCS_DigestInfo_Ptr NETCAAPI netca_spcindirectdatacontent_getmessagedigest(NETCA_ASN1_SpcIndirectDataContent_Ptr content);

NETCA_ASN1_SpcSerializedObject_Ptr NETCAAPI netca_spcserialzedobject_new(NETCA_ASN1_OctetString_Ptr classId,
															 NETCA_ASN1_OctetString_Ptr serializedData);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_spcserialzedobject_getclassid(NETCA_ASN1_SpcSerializedObject_Ptr obj);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_spcserialzedobject_getserializeddata(NETCA_ASN1_SpcSerializedObject_Ptr obj);

NETCA_ASN1_SpcString_Ptr NETCAAPI netca_spcstring_new(int type,NETCA_ASN1_String_Ptr str);
int NETCAAPI netca_spcstring_gettype(NETCA_ASN1_SpcString_Ptr str);
NETCA_ASN1_String_Ptr NETCAAPI netca_spcstring_getstring(NETCA_ASN1_SpcString_Ptr str);


NETCA_ASN1_SpcLink_Ptr NETCAAPI netca_spclink_newurl(NETCA_ASN1_String_Ptr url);
NETCA_ASN1_SpcLink_Ptr NETCAAPI netca_spclink_newmoniker(NETCA_ASN1_SpcSerializedObject_Ptr moniker);
NETCA_ASN1_SpcLink_Ptr NETCAAPI netca_spclink_newfile(NETCA_ASN1_SpcString_Ptr file);
int NETCAAPI netca_spclink_gettype(NETCA_ASN1_SpcLink_Ptr link);
NETCA_ASN1_String_Ptr NETCAAPI netca_spclink_geturl(NETCA_ASN1_SpcLink_Ptr link);
NETCA_ASN1_SpcSerializedObject_Ptr NETCAAPI netca_spclink_getmoniker(NETCA_ASN1_SpcLink_Ptr link);
NETCA_ASN1_SpcString_Ptr NETCAAPI netca_spclink_getfile(NETCA_ASN1_SpcLink_Ptr link);


NETCA_ASN1_SpcPeImageData_Ptr NETCAAPI netca_spcpeimagedata_new(NETCA_ASN1_BitString_Ptr flag,NETCA_ASN1_SpcLink_Ptr file);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_spcpeimagedata_getflag(NETCA_ASN1_SpcPeImageData_Ptr data);
NETCA_ASN1_SpcLink_Ptr NETCAAPI netca_spcpeimagedata_getfile(NETCA_ASN1_SpcPeImageData_Ptr data);

NETCA_ASN1_SpcSpOpusInfo_Ptr NETCAAPI netca_spcspopusinfo_new(NETCA_ASN1_SpcString_Ptr programName,NETCA_ASN1_SpcLink_Ptr moreInfo);
NETCA_ASN1_SpcString_Ptr NETCAAPI netca_spcspopusinfo_getprogramname(NETCA_ASN1_SpcSpOpusInfo_Ptr info);
NETCA_ASN1_SpcLink_Ptr NETCAAPI netca_spcspopusinfo_getmoreinfo(NETCA_ASN1_SpcSpOpusInfo_Ptr info);


NETCA_ASN1_SpcAttributeTypeAndOptionalValue_Ptr NETCAAPI netca_spcattrtypeandoptvalue_new(NETCA_ASN1_OID_Ptr type,NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_spcattrtypeandoptvalue_gettype(NETCA_ASN1_SpcAttributeTypeAndOptionalValue_Ptr attr);
NETCA_ASN1_Any_Ptr NETCAAPI netca_spcattrtypeandoptvalue_getvalue(NETCA_ASN1_SpcAttributeTypeAndOptionalValue_Ptr attr);
int NETCAAPI netca_spcattrtypeandoptvalue_hasvalue(NETCA_ASN1_SpcAttributeTypeAndOptionalValue_Ptr attr);

NETCA_ASN1_Authenticode_TimestampReq_Ptr NETCAAPI netca_authenticode_timestampreq_new(NETCA_ASN1_OID_Ptr timeStampAlgorithm,
									NETCA_ASN1_List_Ptr attrs,NETCA_PKCS7_ContentInfo_Ptr content);
NETCA_ASN1_OID_Ptr NETCAAPI netca_authenticode_timestampreq_getalgo(NETCA_ASN1_Authenticode_TimestampReq_Ptr req);
NETCA_ASN1_List_Ptr NETCAAPI netca_authenticode_timestampreq_getattrs(NETCA_ASN1_Authenticode_TimestampReq_Ptr req);
NETCA_PKCS7_ContentInfo_Ptr NETCAAPI netca_authenticode_timestampreq_getcontent(NETCA_ASN1_Authenticode_TimestampReq_Ptr req);
int NETCAAPI netca_authenticode_timestampreq_hasattrs(NETCA_ASN1_Authenticode_TimestampReq_Ptr req);


NETCA_ASN1_SMIMEEncryptionKeyPreference_Ptr NETCAAPI netca_smimeencryptionkeypreference_newissuerandsn(NETCA_CMS_IssuerAndSerialNumber_Ptr issuerandsn);
NETCA_ASN1_SMIMEEncryptionKeyPreference_Ptr NETCAAPI netca_smimeencryptionkeypreference_newreceipentkeyid(NETCA_CMS_RecipientKeyIdentifier_Ptr id);
NETCA_ASN1_SMIMEEncryptionKeyPreference_Ptr NETCAAPI netca_smimeencryptionkeypreference_newsubjectaltkeyid(NETCA_ASN1_OctetString_Ptr id);
int NETCAAPI netca_smimeencryptionkeypreference_gettype(NETCA_ASN1_SMIMEEncryptionKeyPreference_Ptr prefernce);
NETCA_CMS_IssuerAndSerialNumber_Ptr NETCAAPI netca_smimeencryptionkeypreference_getissuerandsn(NETCA_ASN1_SMIMEEncryptionKeyPreference_Ptr prefernce);
NETCA_CMS_RecipientKeyIdentifier_Ptr NETCAAPI netca_smimeencryptionkeypreference_getreceipentkeyid(NETCA_ASN1_SMIMEEncryptionKeyPreference_Ptr prefernce);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_smimeencryptionkeypreference_getsubjectaltkeyid(NETCA_ASN1_SMIMEEncryptionKeyPreference_Ptr prefernce);

NETCA_ASN1_IdentityCode_Ptr NETCAAPI netca_identitycode_newresidentercardnumber(NETCA_ASN1_String_Ptr number);
NETCA_ASN1_IdentityCode_Ptr NETCAAPI netca_identitycode_newmilitaryofficercardnumber(NETCA_ASN1_String_Ptr number);
NETCA_ASN1_IdentityCode_Ptr NETCAAPI netca_identitycode_newpassportnumber(NETCA_ASN1_String_Ptr number);
int NETCAAPI netca_identitycode_gettype(NETCA_ASN1_IdentityCode_Ptr code);
NETCA_ASN1_String_Ptr NETCAAPI netca_identitycode_getresidentercardnumber(NETCA_ASN1_IdentityCode_Ptr code);
NETCA_ASN1_String_Ptr NETCAAPI netca_identitycode_getmilitaryofficercardnumber(NETCA_ASN1_IdentityCode_Ptr code);
NETCA_ASN1_String_Ptr NETCAAPI netca_identitycode_getpassportnumber(NETCA_ASN1_IdentityCode_Ptr code);


NETCA_ASN1_DhSigStatic_Ptr NETCAAPI netca_dhsigstatic_new(NETCA_CMS_IssuerAndSerialNumber_Ptr issuerAndSerial,NETCA_ASN1_OctetString_Ptr hashValue);
NETCA_CMS_IssuerAndSerialNumber_Ptr NETCAAPI netca_dhsigstatic_getissuerandserial(NETCA_ASN1_DhSigStatic_Ptr dhsig);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_dhsigstatic_gethashvalue(NETCA_ASN1_DhSigStatic_Ptr dhsig);

NETCA_ASN1_TypeOfBiometricData_Ptr NETCAAPI netca_typeofbiometricdata_newpredefined(NETCA_ASN1_Integer_Ptr pre);
NETCA_ASN1_TypeOfBiometricData_Ptr NETCAAPI netca_typeofbiometricdata_newoid(NETCA_ASN1_OID_Ptr oid);
int NETCAAPI netca_typeofbiometricdata_gettype(NETCA_ASN1_TypeOfBiometricData_Ptr type);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_typeofbiometricdata_getpredefined(NETCA_ASN1_TypeOfBiometricData_Ptr type);
NETCA_ASN1_OID_Ptr NETCAAPI netca_typeofbiometricdata_getoid(NETCA_ASN1_TypeOfBiometricData_Ptr type);

NETCA_ASN1_BiometricData_Ptr NETCAAPI netca_biometricdata_new(NETCA_ASN1_TypeOfBiometricData_Ptr typeOfBiometricData,
															  NETCA_X509AlgorithmIdentifier_Ptr hashAlgorithm,
															  NETCA_ASN1_OctetString_Ptr biometricDataHash,
															  NETCA_ASN1_String_Ptr sourceDataUri);
NETCA_ASN1_TypeOfBiometricData_Ptr NETCAAPI netca_biometricdata_gettype(NETCA_ASN1_BiometricData_Ptr biodata);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_biometricdata_gethashalgorithm(NETCA_ASN1_BiometricData_Ptr biodata);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_biometricdata_gethashvalue(NETCA_ASN1_BiometricData_Ptr biodata);
NETCA_ASN1_String_Ptr NETCAAPI netca_biometricdata_geturi(NETCA_ASN1_BiometricData_Ptr biodata);


NETCA_ASN1_SemanticsInformation_Ptr NETCAAPI netca_semanticsinformation_new(NETCA_ASN1_OID_Ptr semanticsIdentifier,
																			NETCA_ASN1_List_Ptr nameRegistrationAuthorities);
NETCA_ASN1_OID_Ptr NETCAAPI netca_semanticsinformation_getsemanticsIdentifier(NETCA_ASN1_SemanticsInformation_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_semanticsinformation_getnameregauthorities(NETCA_ASN1_SemanticsInformation_Ptr info);


NETCA_ASN1_OtherHash_Ptr NETCAAPI netca_otherhash_newsha1(NETCA_ASN1_OctetString_Ptr sha1Hash);
NETCA_ASN1_OtherHash_Ptr NETCAAPI netca_otherhash_newother(NETCA_PKCS_DigestInfo_Ptr otherHash);
int NETCAAPI netca_otherhash_gettype(NETCA_ASN1_OtherHash_Ptr otherHash);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_otherhash_getsha1(NETCA_ASN1_OtherHash_Ptr otherHash);
NETCA_PKCS_DigestInfo_Ptr NETCAAPI netca_otherhash_getother(NETCA_ASN1_OtherHash_Ptr otherHash);

NETCA_ASN1_OtherCertID_Ptr NETCAAPI netca_othercertid_new(NETCA_ASN1_OtherHash_Ptr otherCertHash,
														  NETCA_ASN1_ESSIssuerSerial_Ptr issuerSerial);
NETCA_ASN1_OtherHash_Ptr NETCAAPI netca_othercertid_getcerthash(NETCA_ASN1_OtherCertID_Ptr certid);
NETCA_ASN1_ESSIssuerSerial_Ptr NETCAAPI netca_othercertid_getissuerserial(NETCA_ASN1_OtherCertID_Ptr certid);

NETCA_ASN1_OtherSigningCertificate_Ptr NETCAAPI netca_othersigningcert_new(NETCA_ASN1_List_Ptr certs,
														  NETCA_ASN1_List_Ptr policies);
NETCA_ASN1_List_Ptr NETCAAPI netca_othersigningcert_getcerts(NETCA_ASN1_OtherSigningCertificate_Ptr cert);
NETCA_ASN1_List_Ptr NETCAAPI netca_othersigningcert_getpolicies(NETCA_ASN1_OtherSigningCertificate_Ptr cert);

NETCA_ASN1_SignaturePolicyId_Ptr NETCAAPI netca_signaturepolicyid_new(NETCA_ASN1_OID_Ptr sigPolicyId,
														  NETCA_PKCS_DigestInfo_Ptr sigPolicyHash,
														  NETCA_ASN1_List_Ptr sigPolicyQualifiers);
NETCA_ASN1_OID_Ptr NETCAAPI netca_signaturepolicyid_getid(NETCA_ASN1_SignaturePolicyId_Ptr id);
NETCA_PKCS_DigestInfo_Ptr NETCAAPI netca_signaturepolicyid_gethash(NETCA_ASN1_SignaturePolicyId_Ptr id);
NETCA_ASN1_List_Ptr NETCAAPI netca_signaturepolicyid_getqualifiers(NETCA_ASN1_SignaturePolicyId_Ptr id);


NETCA_ASN1_SignaturePolicyIdentifier_Ptr NETCAAPI netca_signaturepolicyidentifier_newid(NETCA_ASN1_SignaturePolicyId_Ptr id);
NETCA_ASN1_SignaturePolicyIdentifier_Ptr NETCAAPI netca_signaturepolicyidentifier_newimplied(void);
int NETCAAPI netca_signaturepolicyidentifier_gettype(NETCA_ASN1_SignaturePolicyIdentifier_Ptr id);
NETCA_ASN1_SignaturePolicyId_Ptr NETCAAPI netca_signaturepolicyidentifier_getid(NETCA_ASN1_SignaturePolicyIdentifier_Ptr id);


NETCA_ASN1_CommitmentTypeIndication_Ptr NETCAAPI netca_commitmenttypeindication_new(NETCA_ASN1_OID_Ptr commitmentTypeId,
														  				  NETCA_ASN1_List_Ptr commitmentTypeQualifier);
NETCA_ASN1_OID_Ptr NETCAAPI netca_commitmenttypeindication_getid(NETCA_ASN1_CommitmentTypeIndication_Ptr indication);
NETCA_ASN1_List_Ptr NETCAAPI netca_commitmenttypeindication_getqualifiers(NETCA_ASN1_CommitmentTypeIndication_Ptr indication);


NETCA_ASN1_SignerLocation_Ptr NETCAAPI netca_signerlocation_new(NETCA_X500DirectoryString_Ptr countryName,
																NETCA_X500DirectoryString_Ptr localityName,
														  		NETCA_ASN1_List_Ptr postalAdddress);
NETCA_X500DirectoryString_Ptr NETCAAPI netca_signerlocation_getcountryname(NETCA_ASN1_SignerLocation_Ptr location);
NETCA_X500DirectoryString_Ptr NETCAAPI netca_signerlocation_getlocalityname(NETCA_ASN1_SignerLocation_Ptr location);
NETCA_ASN1_List_Ptr NETCAAPI netca_signerlocation_getpostaladdress(NETCA_ASN1_SignerLocation_Ptr location);

NETCA_ASN1_CrlIdentifier_Ptr NETCAAPI netca_crlidentifier_new(NETCA_X500Name_Ptr crlissuer,
										NETCA_ASN1_Time_Ptr crlIssuedTime,
										NETCA_ASN1_Integer_Ptr crlNumber);
NETCA_X500Name_Ptr NETCAAPI netca_crlidentifier_getcrlissuer(NETCA_ASN1_CrlIdentifier_Ptr id);
NETCA_ASN1_Time_Ptr NETCAAPI netca_crlidentifier_getcrlissuedtime(NETCA_ASN1_CrlIdentifier_Ptr id);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_crlidentifier_getcrlnumber(NETCA_ASN1_CrlIdentifier_Ptr id);


NETCA_ASN1_CrlValidatedID_Ptr NETCAAPI netca_crlvalidatedid_new(NETCA_ASN1_OtherHash_Ptr crlHash,
										NETCA_ASN1_CrlIdentifier_Ptr crlIdentifier);
NETCA_ASN1_OtherHash_Ptr NETCAAPI netca_crlvalidatedid_getcrlhash(NETCA_ASN1_CrlValidatedID_Ptr id);
NETCA_ASN1_CrlIdentifier_Ptr NETCAAPI netca_crlvalidatedid_getcrlid(NETCA_ASN1_CrlValidatedID_Ptr id);

NETCA_ASN1_CRLListID_Ptr NETCAAPI netca_crllistid_new(NETCA_ASN1_List_Ptr crls);
NETCA_ASN1_List_Ptr NETCAAPI netca_crllistid_getcrls(NETCA_ASN1_CRLListID_Ptr id);

NETCA_ASN1_OcspIdentifier_Ptr NETCAAPI netca_ocspidentifier_new(NETCA_ASN1_OCSP_ResponderID_Ptr ocspResponderID,
										NETCA_ASN1_Time_Ptr producedAt);
NETCA_ASN1_OCSP_ResponderID_Ptr NETCAAPI netca_ocspidentifier_getocsprespid(NETCA_ASN1_OcspIdentifier_Ptr id);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ocspidentifier_getproducedat(NETCA_ASN1_OcspIdentifier_Ptr id);


NETCA_ASN1_OcspResponsesID_Ptr NETCAAPI netca_ocspresponsesid_new(NETCA_ASN1_OcspIdentifier_Ptr ocspIdentifier,
										NETCA_ASN1_OtherHash_Ptr ocspRepHash);
NETCA_ASN1_OcspIdentifier_Ptr NETCAAPI netca_ocspresponsesid_getid(NETCA_ASN1_OcspResponsesID_Ptr id);
NETCA_ASN1_OtherHash_Ptr NETCAAPI netca_ocspresponsesid_gethash(NETCA_ASN1_OcspResponsesID_Ptr id);


NETCA_ASN1_OcspListID_Ptr NETCAAPI netca_ocsplistid_new(NETCA_ASN1_List_Ptr ocspResponses);
NETCA_ASN1_List_Ptr NETCAAPI netca_ocsplistid_getocspresponses(NETCA_ASN1_OcspListID_Ptr id);

NETCA_ASN1_OtherRevRefs_Ptr NETCAAPI netca_otherrevrefs_new(NETCA_ASN1_OID_Ptr otherRevRefType,
										NETCA_ASN1_Any_Ptr otherRevRefs);
NETCA_ASN1_OID_Ptr NETCAAPI netca_otherrevrefs_gettype(NETCA_ASN1_OtherRevRefs_Ptr ref);
NETCA_ASN1_Any_Ptr NETCAAPI netca_otherrevrefs_getvalue(NETCA_ASN1_OtherRevRefs_Ptr ref);


NETCA_ASN1_CrlOcspRef_Ptr NETCAAPI netca_crlocspref_new(NETCA_ASN1_CRLListID_Ptr crlids,
										NETCA_ASN1_OcspListID_Ptr ocspids,
										NETCA_ASN1_OtherRevRefs_Ptr other);
NETCA_ASN1_CRLListID_Ptr NETCAAPI netca_crlocspref_getcrl(NETCA_ASN1_CrlOcspRef_Ptr ref);
NETCA_ASN1_OcspListID_Ptr NETCAAPI netca_crlocspref_getocsp(NETCA_ASN1_CrlOcspRef_Ptr ref);
NETCA_ASN1_OtherRevRefs_Ptr NETCAAPI netca_crlocspref_getother(NETCA_ASN1_CrlOcspRef_Ptr ref);


NETCA_ASN1_OtherRevVals_Ptr NETCAAPI netca_otherrevvals_new(NETCA_ASN1_OID_Ptr otherRevValType,
										NETCA_ASN1_Any_Ptr otherRevVals);
NETCA_ASN1_OID_Ptr NETCAAPI netca_otherrevvals_gettype(NETCA_ASN1_OtherRevVals_Ptr other);
NETCA_ASN1_Any_Ptr NETCAAPI netca_otherrevvals_getvalue(NETCA_ASN1_OtherRevVals_Ptr other);


NETCA_ASN1_RevocationValues_Ptr NETCAAPI netca_revocationvalues_new(NETCA_ASN1_List_Ptr crlVals,
										NETCA_ASN1_List_Ptr ocspVals,
										NETCA_ASN1_OtherRevVals_Ptr otherRevVals
										);
NETCA_ASN1_List_Ptr NETCAAPI netca_revocationvalues_getcrls(NETCA_ASN1_RevocationValues_Ptr rev);
NETCA_ASN1_List_Ptr NETCAAPI netca_revocationvalues_getocsps(NETCA_ASN1_RevocationValues_Ptr rev);
NETCA_ASN1_OtherRevVals_Ptr NETCAAPI netca_revocationvalues_getother(NETCA_ASN1_RevocationValues_Ptr rev);


NETCA_ASN1_ATSHashIndex_Ptr NETCAAPI netca_atshashindex_new(NETCA_X509AlgorithmIdentifier_Ptr hashIndAlgorithm,
										NETCA_ASN1_List_Ptr certificatesHashIndex,
										NETCA_ASN1_List_Ptr crlsHashIndex,
										NETCA_ASN1_List_Ptr unsignedAttrsHashIndex
										);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_atshashindex_gethashalgo(NETCA_ASN1_ATSHashIndex_Ptr index);
NETCA_ASN1_List_Ptr NETCAAPI netca_atshashindex_getcertshash(NETCA_ASN1_ATSHashIndex_Ptr index);
NETCA_ASN1_List_Ptr NETCAAPI netca_atshashindex_getcrlshash(NETCA_ASN1_ATSHashIndex_Ptr index);
NETCA_ASN1_List_Ptr NETCAAPI netca_atshashindex_getunsignedattrshash(NETCA_ASN1_ATSHashIndex_Ptr index);

NETCA_ASN1_ObjectDigestInfo_Ptr NETCAAPI netca_objectdigestinfo_new(NETCA_ASN1_Enum_Ptr digestedObjectType,
										NETCA_ASN1_OID_Ptr otherObjectTypeID,
										NETCA_X509AlgorithmIdentifier_Ptr digestAlgorithm,
										NETCA_ASN1_BitString_Ptr objectDigest
										);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_objectdigestinfo_gettype(NETCA_ASN1_ObjectDigestInfo_Ptr info);
NETCA_ASN1_OID_Ptr NETCAAPI netca_objectdigestinfo_gettypeid(NETCA_ASN1_ObjectDigestInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_objectdigestinfo_getalgo(NETCA_ASN1_ObjectDigestInfo_Ptr info);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_objectdigestinfo_getdigest(NETCA_ASN1_ObjectDigestInfo_Ptr info);


NETCA_ASN1_ACIssuerSerial_Ptr NETCAAPI netca_acissuerserial_new(NETCA_ASN1_List_Ptr issuer,
										NETCA_ASN1_Integer_Ptr serial,
										NETCA_ASN1_BitString_Ptr issuerUID
										);
NETCA_ASN1_List_Ptr NETCAAPI netca_acissuerserial_getissuer(NETCA_ASN1_ACIssuerSerial_Ptr issuersn);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_acissuerserial_getserial(NETCA_ASN1_ACIssuerSerial_Ptr issuersn);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_acissuerserial_getissueruid(NETCA_ASN1_ACIssuerSerial_Ptr issuersn);


NETCA_ASN1_Holder_Ptr NETCAAPI netca_holder_new(NETCA_ASN1_ACIssuerSerial_Ptr baseCertificateID,
				NETCA_ASN1_List_Ptr entityName,
				NETCA_ASN1_ObjectDigestInfo_Ptr objectDigestInfo
										);
NETCA_ASN1_ACIssuerSerial_Ptr NETCAAPI netca_holder_getbasecertid(NETCA_ASN1_Holder_Ptr holder);
NETCA_ASN1_List_Ptr NETCAAPI netca_holder_getbaseentityname(NETCA_ASN1_Holder_Ptr holder);
NETCA_ASN1_ObjectDigestInfo_Ptr NETCAAPI netca_holder_getobjectdigestinfo(NETCA_ASN1_Holder_Ptr holder);


NETCA_ASN1_AC_V2Form_Ptr NETCAAPI netca_acv2form_new(NETCA_ASN1_List_Ptr issuerName,
				NETCA_ASN1_ACIssuerSerial_Ptr baseCertificateID,
				NETCA_ASN1_ObjectDigestInfo_Ptr objectDigestInfo
										);
NETCA_ASN1_ACIssuerSerial_Ptr NETCAAPI netca_acv2form_getbasecertid(NETCA_ASN1_AC_V2Form_Ptr v2);
NETCA_ASN1_List_Ptr NETCAAPI netca_acv2form_getissuername(NETCA_ASN1_AC_V2Form_Ptr v2);
NETCA_ASN1_ObjectDigestInfo_Ptr NETCAAPI netca_acv2form_getobjectdigestinfo(NETCA_ASN1_AC_V2Form_Ptr v2);

NETCA_ASN1_AttCertIssuer_Ptr NETCAAPI netca_attcertissuer_newv1(NETCA_ASN1_List_Ptr v1);
NETCA_ASN1_AttCertIssuer_Ptr NETCAAPI netca_attcertissuer_newv2(NETCA_ASN1_AC_V2Form_Ptr v2);
int NETCAAPI netca_attcertissuer_gettype(NETCA_ASN1_AttCertIssuer_Ptr issuer);
NETCA_ASN1_List_Ptr NETCAAPI netca_attcertissuer_getv1(NETCA_ASN1_AttCertIssuer_Ptr issuer);
NETCA_ASN1_AC_V2Form_Ptr NETCAAPI netca_attcertissuer_getv2(NETCA_ASN1_AttCertIssuer_Ptr issuer);

NETCA_ASN1_AttCertValidityPeriod_Ptr NETCAAPI netca_attcertvalidityperiod_new(NETCA_ASN1_Time_Ptr notbefore,
				NETCA_ASN1_Time_Ptr notafter);
NETCA_ASN1_Time_Ptr NETCAAPI netca_attcertvalidityperiod_getnotbefore(NETCA_ASN1_AttCertValidityPeriod_Ptr validity);
NETCA_ASN1_Time_Ptr NETCAAPI netca_attcertvalidityperiod_getnotafter(NETCA_ASN1_AttCertValidityPeriod_Ptr validity);

NETCA_ASN1_AttributeCertificateInfo_Ptr NETCAAPI netca_attributecertificateinfo_new(NETCA_ASN1_Integer_Ptr version,
	NETCA_ASN1_Holder_Ptr holder,
	NETCA_ASN1_AttCertIssuer_Ptr issuer,
	NETCA_X509AlgorithmIdentifier_Ptr signature,
	NETCA_ASN1_Integer_Ptr serialNumber,
	NETCA_ASN1_AttCertValidityPeriod_Ptr attrCertValidityPeriod,
	NETCA_ASN1_List_Ptr attributes,
	NETCA_ASN1_BitString_Ptr issuerUniqueID,
	NETCA_ASN1_List_Ptr extensions);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_attributecertificateinfo_getversion(NETCA_ASN1_AttributeCertificateInfo_Ptr info);
NETCA_ASN1_Holder_Ptr NETCAAPI netca_attributecertificateinfo_getholder(NETCA_ASN1_AttributeCertificateInfo_Ptr info);
NETCA_ASN1_AttCertIssuer_Ptr NETCAAPI netca_attributecertificateinfo_getissuer(NETCA_ASN1_AttributeCertificateInfo_Ptr info);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_attributecertificateinfo_getsignaturealgo(NETCA_ASN1_AttributeCertificateInfo_Ptr info);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_attributecertificateinfo_getserialnumber(NETCA_ASN1_AttributeCertificateInfo_Ptr info);
NETCA_ASN1_AttCertValidityPeriod_Ptr NETCAAPI netca_attributecertificateinfo_getvalidity(NETCA_ASN1_AttributeCertificateInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_attributecertificateinfo_getattributes(NETCA_ASN1_AttributeCertificateInfo_Ptr info);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_attributecertificateinfo_getissueruniqueid(NETCA_ASN1_AttributeCertificateInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_attributecertificateinfo_getextensions(NETCA_ASN1_AttributeCertificateInfo_Ptr info);

NETCA_ASN1_AttributeCertificate_Ptr NETCAAPI netca_attributecertificate_new(NETCA_ASN1_AttributeCertificateInfo_Ptr acinfo, NETCA_ASN1_BitString_Ptr signature);
int NETCAAPI netca_attributecertificate_gettbsocts(NETCA_ASN1_AttributeCertificate_Ptr cert, unsigned char *data, long *datalen);
NETCA_ASN1_AttributeCertificateInfo_Ptr NETCAAPI netca_attributecertificate_getacinfo(NETCA_ASN1_AttributeCertificate_Ptr cert);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_attributecertificate_getsignalgo(NETCA_ASN1_AttributeCertificate_Ptr cert);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_attributecertificate_getsignvalue(NETCA_ASN1_AttributeCertificate_Ptr cert);


NETCA_ASN1_SignerAttributeItem_Ptr NETCAAPI netca_signerattributeitem_newattr(NETCA_ASN1_List_Ptr attrs);
NETCA_ASN1_SignerAttributeItem_Ptr NETCAAPI netca_signerattributeitem_newattrcert(NETCA_ASN1_AttributeCertificate_Ptr cert);
int NETCAAPI netca_signerattributeitem_gettype(NETCA_ASN1_SignerAttributeItem_Ptr item);
NETCA_ASN1_List_Ptr NETCAAPI netca_signerattributeitem_getattr(NETCA_ASN1_SignerAttributeItem_Ptr item);
NETCA_ASN1_AttributeCertificate_Ptr NETCAAPI netca_signerattributeitem_getattrcert(NETCA_ASN1_SignerAttributeItem_Ptr item);

NETCA_ASN1_ContentReference_Ptr NETCAAPI netca_contentreference_new(NETCA_ASN1_OID_Ptr contentType,
																	NETCA_ASN1_OctetString_Ptr signedContentIdentifier,
																	NETCA_ASN1_OctetString_Ptr originatorSignatureValue);
NETCA_ASN1_OID_Ptr NETCAAPI netca_contentreference_getcontenttype(NETCA_ASN1_ContentReference_Ptr ref);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_contentreference_getsigncontentid(NETCA_ASN1_ContentReference_Ptr ref);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_contentreference_getsignvalue(NETCA_ASN1_ContentReference_Ptr ref);

NETCA_ASN1_ContentHints_Ptr NETCAAPI netca_contenthints_new(NETCA_ASN1_String_Ptr contentDescription,NETCA_ASN1_OID_Ptr contentType);
NETCA_ASN1_String_Ptr NETCAAPI netca_contenthints_getdecription(NETCA_ASN1_ContentHints_Ptr hints);
NETCA_ASN1_OID_Ptr NETCAAPI netca_contenthints_gettype(NETCA_ASN1_ContentHints_Ptr hints);


NETCA_ASN1_ERS_EncryptionInfo_Ptr NETCAAPI netca_ers_encryptioninfo_new(NETCA_ASN1_OID_Ptr type,NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ers_encryptioninfo_gettype(NETCA_ASN1_ERS_EncryptionInfo_Ptr info);
NETCA_ASN1_Any_Ptr NETCAAPI netca_ers_encryptioninfo_getvalue(NETCA_ASN1_ERS_EncryptionInfo_Ptr info);


NETCA_ASN1_ERS_ArchiveTimeStamp_Ptr NETCAAPI netca_ers_archivetimestamp_new(NETCA_X509AlgorithmIdentifier_Ptr digestAlgorithm,
								NETCA_ASN1_List_Ptr attributes,
								NETCA_ASN1_List_Ptr reducedHashtree,
								NETCA_PKCS7_ContentInfo_Ptr timeStamp);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_ers_encryptioninfo_getdigestalgorithm(NETCA_ASN1_ERS_ArchiveTimeStamp_Ptr arch);
NETCA_ASN1_List_Ptr NETCAAPI netca_ers_encryptioninfo_getattributes(NETCA_ASN1_ERS_ArchiveTimeStamp_Ptr arch);
NETCA_ASN1_List_Ptr NETCAAPI netca_ers_encryptioninfo_getreducedhashtree(NETCA_ASN1_ERS_ArchiveTimeStamp_Ptr arch);
NETCA_PKCS7_ContentInfo_Ptr NETCAAPI netca_ers_encryptioninfo_gettimestamp(NETCA_ASN1_ERS_ArchiveTimeStamp_Ptr arch);

NETCA_ASN1_ERS_EvidenceRecord_Ptr NETCAAPI netca_ers_evidencerecord_new(NETCA_ASN1_Integer_Ptr version,
	NETCA_ASN1_List_Ptr digestAlgorithms,
	NETCA_ASN1_List_Ptr cryptoInfos,
	NETCA_ASN1_ERS_EncryptionInfo_Ptr encryptionInfo,
	NETCA_ASN1_List_Ptr archiveTimeStampSequence);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ers_evidencerecord_getversion(NETCA_ASN1_ERS_EvidenceRecord_Ptr er);
NETCA_ASN1_List_Ptr NETCAAPI netca_ers_evidencerecord_getdigestalgorithms(NETCA_ASN1_ERS_EvidenceRecord_Ptr er);
NETCA_ASN1_List_Ptr NETCAAPI netca_ers_evidencerecord_getcryptoinfos(NETCA_ASN1_ERS_EvidenceRecord_Ptr er);
NETCA_ASN1_ERS_EncryptionInfo_Ptr NETCAAPI netca_ers_evidencerecord_getencryptioninfo(NETCA_ASN1_ERS_EvidenceRecord_Ptr er);
NETCA_ASN1_List_Ptr NETCAAPI netca_ers_evidencerecord_getarchivetimestampseq(NETCA_ASN1_ERS_EvidenceRecord_Ptr er);


NETCA_ASN1_PoeValue_Ptr NETCAAPI netca_poevalue_newtimestamp(NETCA_PKCS7_ContentInfo_Ptr timeStamp);
NETCA_ASN1_PoeValue_Ptr NETCAAPI netca_poevalue_newevidencerecord(NETCA_ASN1_ERS_EvidenceRecord_Ptr er);
int NETCAAPI netca_poevalue_gettype(NETCA_ASN1_PoeValue_Ptr value);
NETCA_PKCS7_ContentInfo_Ptr NETCAAPI netca_poevalue_gettimestamp(NETCA_ASN1_PoeValue_Ptr value);
NETCA_ASN1_ERS_EvidenceRecord_Ptr NETCAAPI netca_poevalue_getevidencerecord(NETCA_ASN1_PoeValue_Ptr value);

NETCA_ASN1_LongTermValidation_Ptr NETCAAPI netca_longtermvalidation_new(NETCA_ASN1_Time_Ptr poeDate,
	NETCA_ASN1_PoeValue_Ptr poeValue,
	NETCA_ASN1_List_Ptr extraCertificates,
	NETCA_ASN1_List_Ptr extraRevocation);
NETCA_ASN1_Time_Ptr NETCAAPI  netca_longtermvalidation_getpoedate(NETCA_ASN1_LongTermValidation_Ptr validation);
NETCA_ASN1_PoeValue_Ptr NETCAAPI  netca_longtermvalidation_getpoevalue(NETCA_ASN1_LongTermValidation_Ptr validation);
NETCA_ASN1_List_Ptr NETCAAPI  netca_longtermvalidation_getextracerts(NETCA_ASN1_LongTermValidation_Ptr validation);
NETCA_ASN1_List_Ptr NETCAAPI  netca_longtermvalidation_getextrarevocation(NETCA_ASN1_LongTermValidation_Ptr validation);

NETCA_ASN1_ACTargetCert_Ptr NETCAAPI netca_ac_targetcert_new(NETCA_ASN1_ACIssuerSerial_Ptr targetCertificate,
	NETCA_X509_GeneralName_Ptr targetName,
	NETCA_ASN1_ObjectDigestInfo_Ptr certDigestInfo);
NETCA_ASN1_ACIssuerSerial_Ptr NETCAAPI netca_ac_targetcert_gettargetcert(NETCA_ASN1_ACTargetCert_Ptr cert);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_ac_targetcert_gettargetname(NETCA_ASN1_ACTargetCert_Ptr cert);
NETCA_ASN1_ObjectDigestInfo_Ptr NETCAAPI netca_ac_targetcert_getcertdigestinfo(NETCA_ASN1_ACTargetCert_Ptr cert);


NETCA_ASN1_ACTarget_Ptr NETCAAPI netca_ac_target_newname(NETCA_X509_GeneralName_Ptr name);
NETCA_ASN1_ACTarget_Ptr NETCAAPI netca_ac_target_newgroup(NETCA_X509_GeneralName_Ptr group);
NETCA_ASN1_ACTarget_Ptr NETCAAPI netca_ac_target_newcert(NETCA_ASN1_ACTargetCert_Ptr cert);
int NETCAAPI netca_ac_target_gettype(NETCA_ASN1_ACTarget_Ptr target);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_ac_target_getname(NETCA_ASN1_ACTarget_Ptr target);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_ac_target_getgroup(NETCA_ASN1_ACTarget_Ptr target);
NETCA_ASN1_ACTargetCert_Ptr NETCAAPI netca_ac_target_getcert(NETCA_ASN1_ACTarget_Ptr target);


NETCA_ASN1_ACIetfAttrSyntaxValue_Ptr NETCAAPI netca_ac_ietfattrsyntaxvalue_newoctets(NETCA_ASN1_OctetString_Ptr octets);
NETCA_ASN1_ACIetfAttrSyntaxValue_Ptr NETCAAPI netca_ac_ietfattrsyntaxvalue_newoid(NETCA_ASN1_OID_Ptr oid);
NETCA_ASN1_ACIetfAttrSyntaxValue_Ptr NETCAAPI netca_ac_ietfattrsyntaxvalue_newutf8(NETCA_ASN1_String_Ptr utf8);
int NETCAAPI netca_ac_ietfattrsyntaxvalue_gettype(NETCA_ASN1_ACIetfAttrSyntaxValue_Ptr value);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ac_ietfattrsyntaxvalue_getoctets(NETCA_ASN1_ACIetfAttrSyntaxValue_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ac_ietfattrsyntaxvalue_getoid(NETCA_ASN1_ACIetfAttrSyntaxValue_Ptr value);
NETCA_ASN1_String_Ptr NETCAAPI netca_ac_ietfattrsyntaxvalue_getutf8(NETCA_ASN1_ACIetfAttrSyntaxValue_Ptr value);


NETCA_ASN1_ACIetfAttrSyntax_Ptr NETCAAPI netca_ac_ietfattrsyntax_new(NETCA_ASN1_List_Ptr policyAuthority,
	NETCA_ASN1_List_Ptr values);
NETCA_ASN1_List_Ptr NETCAAPI netca_ac_ietfattrsyntax_getpolicyauth(NETCA_ASN1_ACIetfAttrSyntax_Ptr ietfattr);
NETCA_ASN1_List_Ptr NETCAAPI netca_ac_ietfattrsyntax_getvalues(NETCA_ASN1_ACIetfAttrSyntax_Ptr ietfattr);

NETCA_ASN1_ACSvceAuthInfo_Ptr NETCAAPI netca_ac_svceauthinfo_new(NETCA_X509_GeneralName_Ptr service,
	NETCA_X509_GeneralName_Ptr ident,NETCA_ASN1_OctetString_Ptr authInfo);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_ac_svceauthinfo_getservice(NETCA_ASN1_ACSvceAuthInfo_Ptr info);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_ac_svceauthinfo_getident(NETCA_ASN1_ACSvceAuthInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ac_svceauthinfo_getauthinfo(NETCA_ASN1_ACSvceAuthInfo_Ptr info);

NETCA_ASN1_ACRoleSyntax_Ptr NETCAAPI netca_ac_rolesyntax_new(NETCA_ASN1_List_Ptr roleAuthority,
	NETCA_X509_GeneralName_Ptr roleName);
NETCA_ASN1_List_Ptr NETCAAPI netca_ac_rolesyntax_getauthority(NETCA_ASN1_ACRoleSyntax_Ptr role);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_ac_rolesyntax_getname(NETCA_ASN1_ACRoleSyntax_Ptr role);

NETCA_ASN1_ACSecurityCategory_Ptr NETCAAPI netca_ac_securitycategory_new(NETCA_ASN1_OID_Ptr type,
	NETCA_ASN1_Any_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ac_securitycategory_gettype(NETCA_ASN1_ACSecurityCategory_Ptr cat);
NETCA_ASN1_Any_Ptr NETCAAPI netca_ac_securitycategory_getvalue(NETCA_ASN1_ACSecurityCategory_Ptr cat);


NETCA_ASN1_ACClearance_Ptr NETCAAPI netca_ac_clearance_new(NETCA_ASN1_OID_Ptr policyId,
	NETCA_ASN1_BitString_Ptr classList, NETCA_ASN1_List_Ptr securityCategories);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ac_clearance_getpolicyid(NETCA_ASN1_ACClearance_Ptr clearance);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_ac_securitycategory_getclasslist(NETCA_ASN1_ACClearance_Ptr clearance);
NETCA_ASN1_List_Ptr NETCAAPI netca_ac_securitycategory_getsecuritycategories(NETCA_ASN1_ACClearance_Ptr clearance);

NETCA_ASN1_ACClearAttrs_Ptr NETCAAPI netca_acclearattrs_new(NETCA_X509_GeneralName_Ptr acIssuer,
	NETCA_ASN1_Integer_Ptr acSerial, NETCA_ASN1_List_Ptr attrs);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_acclearattrs_getissuer(NETCA_ASN1_ACClearAttrs_Ptr attrs);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_acclearattrs_getserial(NETCA_ASN1_ACClearAttrs_Ptr attrs);
NETCA_ASN1_List_Ptr NETCAAPI netca_acclearattrs_getattrs(NETCA_ASN1_ACClearAttrs_Ptr attrs);

NETCA_ASN1_ACAAControls_Ptr NETCAAPI netca_ac_aacontrols_new(NETCA_ASN1_Integer_Ptr pathLenConstraint,
	NETCA_ASN1_List_Ptr permittedAttrs,
	NETCA_ASN1_List_Ptr excludedAttrs,
	NETCA_ASN1_Boolean_Ptr permitUnSpecified);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ac_aacontrols_getpathlencontraint(NETCA_ASN1_ACAAControls_Ptr ctrl);
NETCA_ASN1_List_Ptr NETCAAPI netca_ac_aacontrols_getpermittedattrs(NETCA_ASN1_ACAAControls_Ptr ctrl);
NETCA_ASN1_List_Ptr NETCAAPI netca_ac_aacontrols_getexcludedattrs(NETCA_ASN1_ACAAControls_Ptr ctrl);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_ac_aacontrols_getpermitunspecified(NETCA_ASN1_ACAAControls_Ptr ctrl);

NETCA_ASN1_ECC_CMS_SharedInfo_Ptr NETCAAPI netca_ecccmssharedinfo_new(NETCA_X509AlgorithmIdentifier_Ptr keyInfo,
	NETCA_ASN1_OctetString_Ptr entityUInfo,NETCA_ASN1_OctetString_Ptr suppPubInfo);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_ecccmssharedinfo_getkeyinfo(NETCA_ASN1_ECC_CMS_SharedInfo_Ptr sharedinfo);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ecccmssharedinfo_getentityuinfo(NETCA_ASN1_ECC_CMS_SharedInfo_Ptr sharedinfo);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ecccmssharedinfo_getsupppubinfo(NETCA_ASN1_ECC_CMS_SharedInfo_Ptr sharedinfo);
	
NETCA_ASN1_OCSP_PreferredSignatureAlgorithm_Ptr NETCAAPI netca_ocsp_preferredsignalgo_new(
														NETCA_X509AlgorithmIdentifier_Ptr sigIdentifier,
														NETCA_X509AlgorithmIdentifier_Ptr pubKeyAlgIdentifier);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_ocsp_preferredsignalgo_getsignalgo(NETCA_ASN1_OCSP_PreferredSignatureAlgorithm_Ptr algo);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_ocsp_preferredsignalgo_getpubkeyalgo(NETCA_ASN1_OCSP_PreferredSignatureAlgorithm_Ptr algo);

NETCA_ASN1_Adobe_OtherRevInfo_Ptr NETCAAPI netca_adobe_otherrevinfo_new(NETCA_ASN1_OID_Ptr type,NETCA_ASN1_OctetString_Ptr value);														
NETCA_ASN1_OID_Ptr NETCAAPI netca_adobe_otherrevinfo_gettype(NETCA_ASN1_Adobe_OtherRevInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_adobe_otherrevinfo_getvalue(NETCA_ASN1_Adobe_OtherRevInfo_Ptr info);

NETCA_ASN1_Adobe_RevocationInfoArchival_Ptr NETCAAPI netca_adobe_revocationinfoarchival_new(NETCA_ASN1_List_Ptr crl,NETCA_ASN1_List_Ptr ocsp,NETCA_ASN1_List_Ptr otherRevInfo);														
NETCA_ASN1_List_Ptr NETCAAPI netca_adobe_revocationinfoarchival_getcrl(NETCA_ASN1_Adobe_RevocationInfoArchival_Ptr archival);
NETCA_ASN1_List_Ptr NETCAAPI netca_adobe_revocationinfoarchival_getocsp(NETCA_ASN1_Adobe_RevocationInfoArchival_Ptr archival);
NETCA_ASN1_List_Ptr NETCAAPI netca_adobe_revocationinfoarchival_getotherrevinfo(NETCA_ASN1_Adobe_RevocationInfoArchival_Ptr archival);


NETCA_ASN1_NETCA_IdentificationItem_Ptr NETCAAPI netca_netcaidentificationitem_new(NETCA_ASN1_Integer_Ptr type,NETCA_ASN1_Integer_Ptr encode,NETCA_ASN1_OctetString_Ptr value);														
NETCA_ASN1_Integer_Ptr NETCAAPI netca_netcaidentificationitem_gettype(NETCA_ASN1_NETCA_IdentificationItem_Ptr item);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_netcaidentificationitem_getencode(NETCA_ASN1_NETCA_IdentificationItem_Ptr item);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_netcaidentificationitem_getvalue(NETCA_ASN1_NETCA_IdentificationItem_Ptr item);

NETCA_ASN1_ATSHashIndexV3_Ptr NETCAAPI netca_atshashindexv3_new(NETCA_X509AlgorithmIdentifier_Ptr hashIndAlgorithm,
										NETCA_ASN1_List_Ptr certificatesHashIndex,
										NETCA_ASN1_List_Ptr crlsHashIndex,
										NETCA_ASN1_List_Ptr unsignedAttrsHashIndex
										);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_atshashindexv3_gethashalgo(NETCA_ASN1_ATSHashIndexV3_Ptr index);
NETCA_ASN1_List_Ptr NETCAAPI netca_atshashindexv3_getcertshash(NETCA_ASN1_ATSHashIndexV3_Ptr index);
NETCA_ASN1_List_Ptr NETCAAPI netca_atshashindexv3_getcrlshash(NETCA_ASN1_ATSHashIndexV3_Ptr index);
NETCA_ASN1_List_Ptr NETCAAPI netca_atshashindexv3_getunsignedattrshash(NETCA_ASN1_ATSHashIndexV3_Ptr index);

NETCA_ASN1_CAdES_OtherAttributeCertificate_Ptr NETCAAPI netca_cadesotherattributecertificate_new(NETCA_ASN1_OID_Ptr otherAttributeCertID,NETCA_ASN1_Any_Ptr otherAttributeCert);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cadesotherattributecertificate_getotherattrcertid(NETCA_ASN1_CAdES_OtherAttributeCertificate_Ptr cert);
NETCA_ASN1_Any_Ptr NETCAAPI netca_cadesotherattributecertificate_getotherattrcert(NETCA_ASN1_CAdES_OtherAttributeCertificate_Ptr cert);

NETCA_ASN1_CAdES_CertifiedAttributesV2Item_Ptr NETCAAPI netca_cadescertifiedattributesv2item_newattrcert(NETCA_ASN1_AttributeCertificate_Ptr attrCert);
NETCA_ASN1_CAdES_CertifiedAttributesV2Item_Ptr NETCAAPI netca_cadescertifiedattributesv2item_newotherattrcert(NETCA_ASN1_CAdES_OtherAttributeCertificate_Ptr otherAttrCert);
long NETCAAPI netca_cadescertifiedattributesv2item_gettype(NETCA_ASN1_CAdES_CertifiedAttributesV2Item_Ptr item);
NETCA_ASN1_AttributeCertificate_Ptr NETCAAPI netca_cadescertifiedattributesv2item_getattrcert(NETCA_ASN1_CAdES_CertifiedAttributesV2Item_Ptr item);
NETCA_ASN1_CAdES_OtherAttributeCertificate_Ptr NETCAAPI netca_cadescertifiedattributesv2item_getotherattrcert(NETCA_ASN1_CAdES_CertifiedAttributesV2Item_Ptr item);

NETCA_ASN1_CAdES_SignedAssertion_Ptr NETCAAPI netca_cadessignedassertion_new(NETCA_ASN1_OID_Ptr signedAssertionID,NETCA_ASN1_Any_Ptr signedAssertion);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cadessignedassertion_getsignedassertionid(NETCA_ASN1_CAdES_SignedAssertion_Ptr signedAssertion);
NETCA_ASN1_Any_Ptr NETCAAPI netca_cadessignedassertion_getsignedassertion(NETCA_ASN1_CAdES_SignedAssertion_Ptr signedAssertion);

NETCA_ASN1_CAdES_SignerAttributeV2_Ptr NETCAAPI netca_cadessignerattributev2_new(NETCA_ASN1_List_Ptr claimedAttributes,NETCA_ASN1_List_Ptr certifiedAttributesV2,NETCA_ASN1_List_Ptr signedAssertions);
NETCA_ASN1_List_Ptr NETCAAPI netca_cadessignerattributev2_getclaimedattributes(NETCA_ASN1_CAdES_SignerAttributeV2_Ptr attr);
NETCA_ASN1_List_Ptr NETCAAPI netca_cadessignerattributev2_getcertifiedattributesv2(NETCA_ASN1_CAdES_SignerAttributeV2_Ptr attr);
NETCA_ASN1_List_Ptr NETCAAPI netca_cadessignerattributev2_getsignedassertions(NETCA_ASN1_CAdES_SignerAttributeV2_Ptr attr);

NETCA_ASN1_CAdES_SPDocSpecification_Ptr NETCAAPI netca_cadesspdocspecification_newoid(NETCA_ASN1_OID_Ptr oid);
NETCA_ASN1_CAdES_SPDocSpecification_Ptr NETCAAPI netca_cadesspdocspecification_newuri(NETCA_ASN1_String_Ptr uri);
long NETCAAPI netca_cadesspdocspecification_gettype(NETCA_ASN1_CAdES_SPDocSpecification_Ptr spec);
NETCA_ASN1_OID_Ptr NETCAAPI netca_cadesspdocspecification_getoid(NETCA_ASN1_CAdES_SPDocSpecification_Ptr spec);
NETCA_ASN1_String_Ptr NETCAAPI netca_cadesspdocspecification_geturi(NETCA_ASN1_CAdES_SPDocSpecification_Ptr spec);

NETCA_ASN1_CAdES_SignaturePolicyDocument_Ptr NETCAAPI netca_cadessignaturepolicydocument_newencoded(NETCA_ASN1_OctetString_Ptr sigPolicyEncoded);
NETCA_ASN1_CAdES_SignaturePolicyDocument_Ptr NETCAAPI netca_cadessignaturepolicydocument_newlocaluri(NETCA_ASN1_String_Ptr uri);
long NETCAAPI netca_cadessignaturepolicydocument_gettype(NETCA_ASN1_CAdES_SignaturePolicyDocument_Ptr doc);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_cadessignaturepolicydocument_getencoded(NETCA_ASN1_CAdES_SignaturePolicyDocument_Ptr doc);
NETCA_ASN1_String_Ptr NETCAAPI netca_cadessignaturepolicydocument_getlocaluri(NETCA_ASN1_CAdES_SignaturePolicyDocument_Ptr doc);

NETCA_ASN1_CAdES_SignaturePolicyStore_Ptr NETCAAPI netca_cadessignaturepolicystore_new(NETCA_ASN1_CAdES_SPDocSpecification_Ptr spec,NETCA_ASN1_CAdES_SignaturePolicyDocument_Ptr doc);
NETCA_ASN1_CAdES_SPDocSpecification_Ptr NETCAAPI netca_cadessignaturepolicystore_getdocspec(NETCA_ASN1_CAdES_SignaturePolicyStore_Ptr store);
NETCA_ASN1_CAdES_SignaturePolicyDocument_Ptr NETCAAPI netca_cadessignaturepolicystore_getdoc(NETCA_ASN1_CAdES_SignaturePolicyStore_Ptr store);




NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr NETCAAPI netca_ldapattributevalueassertion_new(NETCA_ASN1_OctetString_Ptr desc,NETCA_ASN1_OctetString_Ptr value);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapattributevalueassertion_getdesc(NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr attr);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapattributevalueassertion_getvalue(NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr attr);


NETCA_ASN1_LDAP_Attribute_Ptr NETCAAPI netca_ldapattribute_new(NETCA_ASN1_OctetString_Ptr type,NETCA_ASN1_List_Ptr value);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapattribute_gettype(NETCA_ASN1_LDAP_Attribute_Ptr attr);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapattribute_getvalue(NETCA_ASN1_LDAP_Attribute_Ptr attr);


NETCA_ASN1_LDAPResult_Ptr NETCAAPI netca_ldapresult_new(NETCA_ASN1_Enum_Ptr resultCode,NETCA_ASN1_OctetString_Ptr matchedDN,NETCA_ASN1_OctetString_Ptr diagnosticMessage,NETCA_ASN1_List_Ptr referral);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_ldapresult_getresultcode(NETCA_ASN1_LDAPResult_Ptr result);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapresult_getmatcheddn(NETCA_ASN1_LDAPResult_Ptr result);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapresult_getdiagnosticmessage(NETCA_ASN1_LDAPResult_Ptr result);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapresult_getreferral(NETCA_ASN1_LDAPResult_Ptr result);


NETCA_ASN1_LDAP_Control_Ptr NETCAAPI netca_ldapcontrol_new(NETCA_ASN1_OctetString_Ptr type,NETCA_ASN1_Boolean_Ptr criticality,NETCA_ASN1_OctetString_Ptr value);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapcontrol_gettype(NETCA_ASN1_LDAP_Control_Ptr control);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_ldapcontrol_getcriticality(NETCA_ASN1_LDAP_Control_Ptr control);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapcontrol_getvalue(NETCA_ASN1_LDAP_Control_Ptr control);

NETCA_ASN1_LDAP_SaslCredentials_Ptr NETCAAPI netca_ldapsaslcredentials_new(NETCA_ASN1_OctetString_Ptr mechanism,NETCA_ASN1_OctetString_Ptr credentials);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapsaslcredentials_getmechanism(NETCA_ASN1_LDAP_SaslCredentials_Ptr saslcredentials);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapsaslcredentials_getcredentials(NETCA_ASN1_LDAP_SaslCredentials_Ptr saslcredentials);

NETCA_ASN1_LDAP_AuthenticationChoice_Ptr NETCAAPI netca_ldapauthenticationchoice_newsimple(NETCA_ASN1_OctetString_Ptr simple);
NETCA_ASN1_LDAP_AuthenticationChoice_Ptr NETCAAPI netca_ldapauthenticationchoice_newsasl(NETCA_ASN1_LDAP_SaslCredentials_Ptr sasl);
int NETCAAPI netca_ldapauthenticationchoice_gettype(NETCA_ASN1_LDAP_AuthenticationChoice_Ptr auth);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapauthenticationchoice_getsimple(NETCA_ASN1_LDAP_AuthenticationChoice_Ptr auth);
NETCA_ASN1_LDAP_SaslCredentials_Ptr NETCAAPI netca_ldapauthenticationchoice_getsasl(NETCA_ASN1_LDAP_AuthenticationChoice_Ptr auth);

NETCA_ASN1_LDAP_BindRequest_Ptr NETCAAPI netca_ldapbindrequest_new(NETCA_ASN1_Integer_Ptr version,NETCA_ASN1_OctetString_Ptr name,NETCA_ASN1_LDAP_AuthenticationChoice_Ptr authentication);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ldapbindrequest_getversion(NETCA_ASN1_LDAP_BindRequest_Ptr req);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapbindrequest_getname(NETCA_ASN1_LDAP_BindRequest_Ptr req);
NETCA_ASN1_LDAP_AuthenticationChoice_Ptr NETCAAPI netca_ldapbindrequest_getauthentication(NETCA_ASN1_LDAP_BindRequest_Ptr req);


NETCA_ASN1_LDAP_BindResponse_Ptr NETCAAPI netca_ldapbindresponse_new(NETCA_ASN1_Enum_Ptr resultCode,NETCA_ASN1_OctetString_Ptr matchedDN,NETCA_ASN1_OctetString_Ptr diagnosticMessage,NETCA_ASN1_List_Ptr referral,NETCA_ASN1_OctetString_Ptr serverSaslCreds);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_ldapbindresponse_getresultcode(NETCA_ASN1_LDAP_BindResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapbindresponse_getmatcheddn(NETCA_ASN1_LDAP_BindResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapbindresponse_getdiagnosticmessage(NETCA_ASN1_LDAP_BindResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapbindresponse_getreferral(NETCA_ASN1_LDAP_BindResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapbindresponse_getserversaslcreds(NETCA_ASN1_LDAP_BindResponse_Ptr resp);

NETCA_ASN1_LDAP_Substring_Ptr NETCAAPI netca_ldapsubstring_newinitial(NETCA_ASN1_OctetString_Ptr initial);
NETCA_ASN1_LDAP_Substring_Ptr NETCAAPI netca_ldapsubstring_newany(NETCA_ASN1_OctetString_Ptr any);
NETCA_ASN1_LDAP_Substring_Ptr NETCAAPI netca_ldapsubstring_newfinal(NETCA_ASN1_OctetString_Ptr final);
int NETCAAPI netca_ldapsubstring_gettype(NETCA_ASN1_LDAP_Substring_Ptr str);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapsubstring_getinitial(NETCA_ASN1_LDAP_Substring_Ptr str);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapsubstring_getany(NETCA_ASN1_LDAP_Substring_Ptr str);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapsubstring_getfinal(NETCA_ASN1_LDAP_Substring_Ptr str);

NETCA_ASN1_LDAP_SubstringFilter_Ptr NETCAAPI netca_ldapsubstringfilter_new(NETCA_ASN1_OctetString_Ptr type,NETCA_ASN1_List_Ptr substrings);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapsubstringfilter_gettype(NETCA_ASN1_LDAP_SubstringFilter_Ptr filter);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapsubstringfilter_getsubstrings(NETCA_ASN1_LDAP_SubstringFilter_Ptr filter);


NETCA_ASN1_LDAP_MatchingRuleAssertion_Ptr NETCAAPI netca_ldapmatchingruleassertion_new(NETCA_ASN1_OctetString_Ptr matchingRule,NETCA_ASN1_OctetString_Ptr type,NETCA_ASN1_OctetString_Ptr matchValue,NETCA_ASN1_Boolean_Ptr dnAttributes);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapmatchingruleassertion_getmatchingrule(NETCA_ASN1_LDAP_MatchingRuleAssertion_Ptr assertion);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapmatchingruleassertion_gettype(NETCA_ASN1_LDAP_MatchingRuleAssertion_Ptr assertion);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapmatchingruleassertion_getmatchvalue(NETCA_ASN1_LDAP_MatchingRuleAssertion_Ptr assertion);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_ldapmatchingruleassertion_getdnattributes(NETCA_ASN1_LDAP_MatchingRuleAssertion_Ptr assertion);


NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newand(NETCA_ASN1_List_Ptr andFilter);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newor(NETCA_ASN1_List_Ptr orFilter);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newnot(NETCA_ASN1_LDAP_Filter_Ptr notFilter);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newequalitymatch(NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr equalityMatch);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newsubstrings(NETCA_ASN1_LDAP_SubstringFilter_Ptr substrings);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newgreaterorequal(NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr greaterOrEqual);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newlessorequal(NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr lessOrEqual);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newpresent(NETCA_ASN1_OctetString_Ptr present);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newapproxmatch(NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr approxMatch);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_newextensiblematch(NETCA_ASN1_LDAP_MatchingRuleAssertion_Ptr extensibleMatch);
int NETCAAPI netca_ldapfilter_gettype(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapfilter_getand(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapfilter_getor(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapfilter_getnot(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr NETCAAPI netca_ldapfilter_getequalitymatch(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_LDAP_SubstringFilter_Ptr NETCAAPI netca_ldapfilter_getsubstrings(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr NETCAAPI netca_ldapfilter_getgreaterorequal(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr NETCAAPI netca_ldapfilter_getlessorequal(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapfilter_getpresent(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr NETCAAPI netca_ldapfilter_getapproxmatch(NETCA_ASN1_LDAP_Filter_Ptr filter);
NETCA_ASN1_LDAP_MatchingRuleAssertion_Ptr NETCAAPI netca_ldapfilter_getextensiblematch(NETCA_ASN1_LDAP_Filter_Ptr filter);


NETCA_ASN1_LDAP_SearchRequest_Ptr NETCAAPI netca_ldapsearchrequest_new(NETCA_ASN1_OctetString_Ptr baseObject,
																		NETCA_ASN1_Enum_Ptr scope,
																		NETCA_ASN1_Enum_Ptr derefAliases,
																		NETCA_ASN1_Integer_Ptr sizeLimit,
																		NETCA_ASN1_Integer_Ptr timeLimit,
																		NETCA_ASN1_Boolean_Ptr typesOnly,
																		NETCA_ASN1_LDAP_Filter_Ptr filter,
																		NETCA_ASN1_List_Ptr attributes);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapsearchrequest_getbaseobject(NETCA_ASN1_LDAP_SearchRequest_Ptr req);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_ldapsearchrequest_getscope(NETCA_ASN1_LDAP_SearchRequest_Ptr req);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_ldapsearchrequest_getderefaliases(NETCA_ASN1_LDAP_SearchRequest_Ptr req);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ldapsearchrequest_getsizelimit(NETCA_ASN1_LDAP_SearchRequest_Ptr req);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ldapsearchrequest_gettimelimit(NETCA_ASN1_LDAP_SearchRequest_Ptr req);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_ldapsearchrequest_gettypesonly(NETCA_ASN1_LDAP_SearchRequest_Ptr req);
NETCA_ASN1_LDAP_Filter_Ptr NETCAAPI netca_ldapsearchrequest_getfilter(NETCA_ASN1_LDAP_SearchRequest_Ptr req);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapsearchrequest_getattributes(NETCA_ASN1_LDAP_SearchRequest_Ptr req);


NETCA_ASN1_LDAP_SearchResultEntry_Ptr NETCAAPI netca_ldapsearchresultentry_new(NETCA_ASN1_OctetString_Ptr objectName,NETCA_ASN1_List_Ptr attributes);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapsearchresultentry_getobjectname(NETCA_ASN1_LDAP_SearchResultEntry_Ptr entry);	
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapsearchresultentry_getattributes(NETCA_ASN1_LDAP_SearchResultEntry_Ptr entry);	

NETCA_ASN1_LDAP_Change_Ptr NETCAAPI netca_ldapchange_new(NETCA_ASN1_Enum_Ptr operation,NETCA_ASN1_LDAP_Attribute_Ptr modification);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_ldapchange_getoperation(NETCA_ASN1_LDAP_Change_Ptr change);	
NETCA_ASN1_LDAP_Attribute_Ptr NETCAAPI netca_ldapchange_getmodification(NETCA_ASN1_LDAP_Change_Ptr change);	


NETCA_ASN1_LDAP_ModifyRequest_Ptr NETCAAPI netca_ldapmodifyrequest_new(NETCA_ASN1_OctetString_Ptr object,NETCA_ASN1_List_Ptr changes);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapmodifyrequest_getobject(NETCA_ASN1_LDAP_ModifyRequest_Ptr req);	
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapmodifyrequest_getchanges(NETCA_ASN1_LDAP_ModifyRequest_Ptr req);

NETCA_ASN1_LDAP_AddRequest_Ptr NETCAAPI netca_ldapaddrequest_new(NETCA_ASN1_OctetString_Ptr entry,NETCA_ASN1_List_Ptr attributes);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapaddrequest_getentry(NETCA_ASN1_LDAP_AddRequest_Ptr req);	
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapaddrequest_getattributes(NETCA_ASN1_LDAP_AddRequest_Ptr req);

NETCA_ASN1_LDAP_ModifyDNRequest_Ptr NETCAAPI netca_ldapmodifydnrequest_new(NETCA_ASN1_OctetString_Ptr entry,NETCA_ASN1_OctetString_Ptr newrdn,NETCA_ASN1_Boolean_Ptr deleteoldrdn,NETCA_ASN1_OctetString_Ptr newSuperior);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapmodifydnrequest_getentry(NETCA_ASN1_LDAP_ModifyDNRequest_Ptr req);	
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapmodifydnrequest_getnewrdn(NETCA_ASN1_LDAP_ModifyDNRequest_Ptr req);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_ldapmodifydnrequest_getdeleteoldrdn(NETCA_ASN1_LDAP_ModifyDNRequest_Ptr req);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapmodifydnrequest_getnewsuperior(NETCA_ASN1_LDAP_ModifyDNRequest_Ptr req);


NETCA_ASN1_LDAP_CompareRequest_Ptr NETCAAPI netca_ldapcomparerequest_new(NETCA_ASN1_OctetString_Ptr entry,NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr ava);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapcomparerequest_getentry(NETCA_ASN1_LDAP_CompareRequest_Ptr req);	
NETCA_ASN1_LDAP_AttributeValueAssertion_Ptr NETCAAPI netca_ldapcomparerequest_getava(NETCA_ASN1_LDAP_CompareRequest_Ptr req);

NETCA_ASN1_LDAP_ExtendedRequest_Ptr NETCAAPI netca_ldapextendedrequest_new(NETCA_ASN1_OctetString_Ptr requestName,NETCA_ASN1_OctetString_Ptr requestValue);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapextendedrequest_getrequestname(NETCA_ASN1_LDAP_ExtendedRequest_Ptr req);	
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapextendedrequest_getrequestvalue(NETCA_ASN1_LDAP_ExtendedRequest_Ptr req);

NETCA_ASN1_LDAP_ExtendedResponse_Ptr NETCAAPI netca_ldapextendedresponse_new(NETCA_ASN1_Enum_Ptr resultCode,NETCA_ASN1_OctetString_Ptr matchedDN,NETCA_ASN1_OctetString_Ptr diagnosticMessage,NETCA_ASN1_List_Ptr referral,NETCA_ASN1_OctetString_Ptr responseName,NETCA_ASN1_OctetString_Ptr responseValue);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_ldapextendedresponse_getresultcode(NETCA_ASN1_LDAP_ExtendedResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapextendedresponse_getmatcheddn(NETCA_ASN1_LDAP_ExtendedResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapextendedresponse_getdiagnosticmessage(NETCA_ASN1_LDAP_ExtendedResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapextendedresponse_getreferral(NETCA_ASN1_LDAP_ExtendedResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapextendedresponse_getresponsename(NETCA_ASN1_LDAP_ExtendedResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapextendedresponse_getresponsevalue(NETCA_ASN1_LDAP_ExtendedResponse_Ptr resp);

NETCA_ASN1_LDAP_IntermediateResponse_Ptr NETCAAPI netca_ldapintermediateresponse_new(NETCA_ASN1_OctetString_Ptr responseName,NETCA_ASN1_OctetString_Ptr responseValue);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapintermediateresponse_getresponsename(NETCA_ASN1_LDAP_IntermediateResponse_Ptr resp);	
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapintermediateresponse_getresponsevalue(NETCA_ASN1_LDAP_IntermediateResponse_Ptr resp);

NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newbindrequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_BindRequest_Ptr bindRequest,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newbindresponse(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_BindResponse_Ptr bindResponse,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newunbindrequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newsearchrequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_SearchRequest_Ptr searchRequest,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newsearchresentry(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_SearchResultEntry_Ptr searchResEntry,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newsearchresdone(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAPResult_Ptr searchResDone,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newsearchresref(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_List_Ptr searchResRef,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newmodifyrequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_ModifyRequest_Ptr modifyRequest,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newmodifyresponse(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAPResult_Ptr modifyResponse,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newaddrequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_AddRequest_Ptr addRequest,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newaddresponse(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAPResult_Ptr addResponse,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newdelrequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_OctetString_Ptr delRequest,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newdelresponse(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAPResult_Ptr delResponse,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newmoddnrequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_ModifyDNRequest_Ptr modDNRequest,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newmoddnresponse(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAPResult_Ptr modDNResponse,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newcomparerequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_CompareRequest_Ptr compareRequest,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newcompareresponse(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAPResult_Ptr compareResponse,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newabandonrequest(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_Integer_Ptr abandonRequest,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newextendedreq(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_ExtendedRequest_Ptr extendedReq,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newextendedresp(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_ExtendedResponse_Ptr extendedresp,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_LDAPMessage_Ptr NETCAAPI netca_ldapmessage_newintermediateresponse(NETCA_ASN1_Integer_Ptr messageID,NETCA_ASN1_LDAP_IntermediateResponse_Ptr intermediateResponse,NETCA_ASN1_List_Ptr controls);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ldapmessage_getmessageid(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapmessage_getcontrols(NETCA_ASN1_LDAPMessage_Ptr msg);
int NETCAAPI netca_ldapmessage_gettype(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_BindRequest_Ptr NETCAAPI netca_ldapmessage_getbindrequest(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_BindResponse_Ptr NETCAAPI netca_ldapmessage_getbindresponse(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_SearchRequest_Ptr NETCAAPI netca_ldapmessage_getsearchrequest(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_SearchResultEntry_Ptr NETCAAPI netca_ldapmessage_getsearchresentry(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAPResult_Ptr NETCAAPI netca_ldapmessage_getsearchresdone(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_List_Ptr NETCAAPI netca_ldapmessage_getsearchresref(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_ModifyRequest_Ptr NETCAAPI netca_ldapmessage_getmodifyrequest(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAPResult_Ptr NETCAAPI netca_ldapmessage_getmodifyresponse(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_AddRequest_Ptr NETCAAPI netca_ldapmessage_getaddrequest(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAPResult_Ptr NETCAAPI netca_ldapmessage_getaddresponse(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ldapmessage_getdelrequest(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAPResult_Ptr NETCAAPI netca_ldapmessage_getdelresponse(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_ModifyDNRequest_Ptr NETCAAPI netca_ldapmessage_getmoddnrequest(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAPResult_Ptr NETCAAPI netca_ldapmessage_getmoddnresponse(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_CompareRequest_Ptr NETCAAPI netca_ldapmessage_getcomparerequest(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAPResult_Ptr NETCAAPI netca_ldapmessage_getcompareresponse(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ldapmessage_getabandonrequest(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_ExtendedRequest_Ptr NETCAAPI netca_ldapmessage_getextendedreq(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_ExtendedResponse_Ptr NETCAAPI netca_ldapmessage_getextendedresp(NETCA_ASN1_LDAPMessage_Ptr msg);
NETCA_ASN1_LDAP_IntermediateResponse_Ptr NETCAAPI netca_ldapmessage_getintermediateresponse(NETCA_ASN1_LDAPMessage_Ptr msg);


NETCA_PKCS7_SignedAndEnvelopedData_Ptr NETCAAPI netca_signedandenvelopeddata_new(
	NETCA_ASN1_Integer_Ptr version,NETCA_ASN1_List_Ptr recipientInfos,
	NETCA_ASN1_List_Ptr digestAlgorithms,NETCA_CMS_EncryptedContentInfo_Ptr encryptedContentInfo,
	NETCA_ASN1_List_Ptr certificates,NETCA_ASN1_List_Ptr crls,NETCA_ASN1_List_Ptr signerInfos);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_signedandenvelopeddata_getversion(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);
NETCA_ASN1_List_Ptr NETCAAPI netca_signedandenvelopeddata_getrecipientinfos(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);
NETCA_ASN1_List_Ptr NETCAAPI netca_signedandenvelopeddata_getdigestalgorithms(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);
NETCA_CMS_EncryptedContentInfo_Ptr NETCAAPI netca_signedandenvelopeddata_getencryptedcontentinfo(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);
int NETCAAPI netca_signedandenvelopeddata_hascertificates(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);
NETCA_ASN1_List_Ptr NETCAAPI netca_signedandenvelopeddata_getcertificates(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);
int NETCAAPI netca_signedandenvelopeddata_hascrls(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);
NETCA_ASN1_List_Ptr NETCAAPI netca_signedandenvelopeddata_getcrls(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);
NETCA_ASN1_List_Ptr NETCAAPI netca_signedandenvelopeddata_getsignerinfos(NETCA_PKCS7_SignedAndEnvelopedData_Ptr data);


NETCA_ASN1_SCVPIssuerSerial_Ptr NETCAAPI netca_scvpissuerserial_new(NETCA_ASN1_List_Ptr issuer,NETCA_ASN1_Integer_Ptr serialNumber);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpissuerserial_getissuer(NETCA_ASN1_SCVPIssuerSerial_Ptr issuersn);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpissuerserial_getserial(NETCA_ASN1_SCVPIssuerSerial_Ptr issuersn);

NETCA_ASN1_SCVPCertID_Ptr NETCAAPI netca_scvpcertid_new(NETCA_ASN1_OctetString_Ptr certHash,NETCA_ASN1_SCVPIssuerSerial_Ptr issuerSerial,NETCA_X509AlgorithmIdentifier_Ptr hashAlgorithm);
NETCA_ASN1_SCVPIssuerSerial_Ptr NETCAAPI netca_scvpcertid_getcerthash(NETCA_ASN1_SCVPCertID_Ptr certId);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvpcertid_getissuerserial(NETCA_ASN1_SCVPCertID_Ptr certId);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_scvpcertid_gethashalgorithm(NETCA_ASN1_SCVPCertID_Ptr certId);

NETCA_ASN1_SCVP_PKCReference_Ptr NETCAAPI netca_scvppkcreference_new_cert(NETCA_X509PubKeyCertificate_Ptr cert);
NETCA_ASN1_SCVP_PKCReference_Ptr NETCAAPI netca_scvppkcreference_new_pkcref(NETCA_ASN1_SCVPCertID_Ptr pkcref);
int NETCAAPI netca_scvppkcreference_gettype(NETCA_ASN1_SCVP_PKCReference_Ptr ref);
NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_scvppkcreference_getcert(NETCA_ASN1_SCVP_PKCReference_Ptr ref);
NETCA_ASN1_SCVPCertID_Ptr NETCAAPI netca_scvppkcreference_getpkcref(NETCA_ASN1_SCVP_PKCReference_Ptr ref);

NETCA_ASN1_SCVP_ACReference_Ptr NETCAAPI netca_scvpacreference_new_attrcert(NETCA_ASN1_AttributeCertificate_Ptr cert);
NETCA_ASN1_SCVP_ACReference_Ptr NETCAAPI netca_scvpacreference_new_acref(NETCA_ASN1_SCVPCertID_Ptr acref);
int NETCAAPI netca_scvpacreference_gettype(NETCA_ASN1_SCVP_PKCReference_Ptr ref);
NETCA_ASN1_AttributeCertificate_Ptr NETCAAPI netca_scvpacreference_getattrcert(NETCA_ASN1_SCVP_ACReference_Ptr ref);
NETCA_ASN1_SCVPCertID_Ptr NETCAAPI netca_scvpacreference_getacref(NETCA_ASN1_SCVP_ACReference_Ptr ref);

NETCA_ASN1_SCVP_CertReference_Ptr NETCAAPI netca_scvpcertreference_new_pkc(NETCA_ASN1_SCVP_PKCReference_Ptr pkc);
NETCA_ASN1_SCVP_CertReference_Ptr NETCAAPI netca_scvpcertreference_new_ac(NETCA_ASN1_SCVP_ACReference_Ptr ac);
int NETCAAPI netca_scvpcertreference_gettype(NETCA_ASN1_SCVP_CertReference_Ptr ref);
NETCA_ASN1_SCVP_PKCReference_Ptr NETCAAPI netca_scvpcertreference_getpkc(NETCA_ASN1_SCVP_CertReference_Ptr ref);
NETCA_ASN1_SCVP_ACReference_Ptr NETCAAPI netca_scvpcertreference_getac(NETCA_ASN1_SCVP_CertReference_Ptr ref);


NETCA_ASN1_SCVP_CertReferences_Ptr NETCAAPI netca_scvpcertreferences_new_pkcrefs(NETCA_ASN1_List_Ptr pkcrefs);
NETCA_ASN1_SCVP_CertReferences_Ptr NETCAAPI netca_scvpcertreference_new_acrefs(NETCA_ASN1_List_Ptr acrefs);
int NETCAAPI netca_scvpcertreferences_gettype(NETCA_ASN1_SCVP_CertReferences_Ptr refs);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcertreferences_getpkcrefs(NETCA_ASN1_SCVP_CertReferences_Ptr refs);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcertreferences_getacrefs(NETCA_ASN1_SCVP_CertReferences_Ptr refs);


NETCA_ASN1_SCVP_ValidationPolRef_Ptr NETCAAPI netca_scvpvalidationpolref_new(NETCA_ASN1_OID_Ptr valpolid,NETCA_ASN1_Any_Ptr valpolparams);
NETCA_ASN1_OID_Ptr NETCAAPI netca_scvpvalidationpolref_getvalpolid(NETCA_ASN1_SCVP_ValidationPolRef_Ptr ref);
int NETCAAPI netca_scvpvalidationpolref_hasvalpolparams(NETCA_ASN1_SCVP_ValidationPolRef_Ptr ref);
NETCA_ASN1_Any_Ptr NETCAAPI netca_scvpvalidationpolref_getvalpolparams(NETCA_ASN1_SCVP_ValidationPolRef_Ptr ref);

NETCA_ASN1_SCVP_ValidationAlg_Ptr NETCAAPI netca_scvpvalidationalg_new(NETCA_ASN1_OID_Ptr valalgid,NETCA_ASN1_Any_Ptr parameters);
NETCA_ASN1_OID_Ptr NETCAAPI netca_scvpvalidationalg_getvalalgid(NETCA_ASN1_SCVP_ValidationAlg_Ptr alg);
int NETCAAPI netca_scvpvalidationalg_hasparameters(NETCA_ASN1_SCVP_ValidationAlg_Ptr alg);
NETCA_ASN1_Any_Ptr NETCAAPI netca_scvpvalidationalg_getparameters(NETCA_ASN1_SCVP_ValidationAlg_Ptr alg);

NETCA_ASN1_SCVP_NameValidationAlgParms_Ptr NETCAAPI netca_scvpnamevalidationalgparms_new(NETCA_ASN1_OID_Ptr namecompalgid,NETCA_ASN1_List_Ptr validationnames);
NETCA_ASN1_OID_Ptr NETCAAPI netca_scvpnamevalidationalgparms_getnamecompalgid(NETCA_ASN1_SCVP_NameValidationAlgParms_Ptr parms);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpnamevalidationalgparms_getvalidationnames(NETCA_ASN1_SCVP_NameValidationAlgParms_Ptr parms);


NETCA_ASN1_SCVP_ResponseFlags_Ptr  NETCAAPI netca_scvpresponseflags_new(NETCA_ASN1_Boolean_Ptr fullRequestInResponse,NETCA_ASN1_Boolean_Ptr responseValidationPolByRef,
																		NETCA_ASN1_Boolean_Ptr protectResponse,NETCA_ASN1_Boolean_Ptr cachedResponse);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_scvpresponseflags_getfullrequestinresponse(NETCA_ASN1_SCVP_ResponseFlags_Ptr flags);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_scvpresponseflags_getresponsevalidationpolbyref(NETCA_ASN1_SCVP_ResponseFlags_Ptr flags);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_scvpresponseflags_getprotectresponse(NETCA_ASN1_SCVP_ResponseFlags_Ptr flags);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_scvpresponseflags_getcachedresponse(NETCA_ASN1_SCVP_ResponseFlags_Ptr flags);


NETCA_ASN1_SCVP_OtherRevInfo_Ptr  NETCAAPI netca_scvpotherrevinfo_new(NETCA_ASN1_OID_Ptr m_riType,NETCA_ASN1_Any_Ptr riValue);
NETCA_ASN1_OID_Ptr  NETCAAPI netca_scvpotherrevinfo_getritype(NETCA_ASN1_SCVP_OtherRevInfo_Ptr info);
NETCA_ASN1_Any_Ptr  NETCAAPI netca_scvpotherrevinfo_getrivalue(NETCA_ASN1_SCVP_OtherRevInfo_Ptr info);


NETCA_ASN1_SCVP_RevocationInfo_Ptr NETCAAPI netca_scvprevocationinfo_new_crl(NETCA_X509CRL_Ptr crl);
NETCA_ASN1_SCVP_RevocationInfo_Ptr NETCAAPI netca_scvprevocationinfo_new_deltacrl(NETCA_X509CRL_Ptr delta_crl);
NETCA_ASN1_SCVP_RevocationInfo_Ptr NETCAAPI netca_scvprevocationinfo_new_ocsp(NETCA_ASN1_OCSP_OCSPResponse_Ptr ocsp);
NETCA_ASN1_SCVP_RevocationInfo_Ptr NETCAAPI netca_scvprevocationinfo_new_other(NETCA_ASN1_SCVP_OtherRevInfo_Ptr other);
int NETCAAPI netca_scvprevocationinfo_gettype(NETCA_ASN1_SCVP_RevocationInfo_Ptr info);
NETCA_X509CRL_Ptr NETCAAPI netca_scvprevocationinfo_getcrl(NETCA_ASN1_SCVP_RevocationInfo_Ptr info);
NETCA_X509CRL_Ptr NETCAAPI netca_scvprevocationinfo_getdeltacrl(NETCA_ASN1_SCVP_RevocationInfo_Ptr info);
NETCA_ASN1_OCSP_OCSPResponse_Ptr NETCAAPI netca_scvprevocationinfo_getocsp(NETCA_ASN1_SCVP_RevocationInfo_Ptr info);
NETCA_ASN1_SCVP_OtherRevInfo_Ptr NETCAAPI netca_scvprevocationinfo_getother(NETCA_ASN1_SCVP_RevocationInfo_Ptr info);


NETCA_ASN1_SCVP_ValidationPolicy_Ptr  NETCAAPI netca_scvpvalidationpolicy_new(NETCA_ASN1_SCVP_ValidationPolRef_Ptr validationpolref,
					NETCA_ASN1_SCVP_ValidationAlg_Ptr validationalg,NETCA_ASN1_List_Ptr userpolicyset,
					NETCA_ASN1_Boolean_Ptr inhibitpolicymapping,NETCA_ASN1_Boolean_Ptr requireexplicitpolicy,
					NETCA_ASN1_Boolean_Ptr inhibitanypolicy,NETCA_ASN1_List_Ptr trustanchors,
					NETCA_ASN1_List_Ptr keyusages,NETCA_ASN1_List_Ptr extendedkeyusages,
					NETCA_ASN1_List_Ptr specifiedkeyusages);
NETCA_ASN1_SCVP_ValidationPolRef_Ptr NETCAAPI netca_scvpvalidationpolicy_getvalidationpolref(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_hasvalidationalg(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_SCVP_ValidationAlg_Ptr NETCAAPI netca_scvpvalidationpolicy_getvalidationalg(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_hasuserpolicyset(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalidationpolicy_getuserpolicyset(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_hasinhibitpolicymapping(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_scvpvalidationpolicy_getinhibitpolicymapping(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_hasrequireexplicitpolicy(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_scvpvalidationpolicy_getrequireexplicitpolicy(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_hasinhibitanypolicy(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_scvpvalidationpolicy_getinhibitanypolicy(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_hastrustanchors(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalidationpolicy_gettrustanchors(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_haskeyusages(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalidationpolicy_getkeyusages(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_hasextendedkeyusages(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalidationpolicy_getextendedkeyusages(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
int NETCAAPI netca_scvpvalidationpolicy_hasspecifiedkeyusages(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalidationpolicy_getspecifiedkeyusages(NETCA_ASN1_SCVP_ValidationPolicy_Ptr policy);


NETCA_ASN1_SCVP_Query_Ptr  NETCAAPI netca_scvpquery_new(NETCA_ASN1_SCVP_CertReferences_Ptr queriedcerts,
						NETCA_ASN1_List_Ptr checks,NETCA_ASN1_List_Ptr wantback,NETCA_ASN1_SCVP_ValidationPolicy_Ptr validationpolicy,
						NETCA_ASN1_SCVP_ResponseFlags_Ptr responseflags,NETCA_ASN1_OctetString_Ptr servercontextinfo,
						NETCA_ASN1_Time_Ptr validationtime,NETCA_ASN1_List_Ptr intermediatecerts,
						NETCA_ASN1_List_Ptr revinfos,NETCA_ASN1_Time_Ptr producedat,NETCA_ASN1_List_Ptr queryextensions);
NETCA_ASN1_SCVP_CertReferences_Ptr NETCAAPI netca_scvpquery_getqueriedcerts(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpquery_getchecks(NETCA_ASN1_SCVP_Query_Ptr query);
int NETCAAPI netca_scvpquery_haswantback(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpquery_getwantback(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_SCVP_ValidationPolicy_Ptr NETCAAPI netca_scvpquery_getvalidationpolicy(NETCA_ASN1_SCVP_Query_Ptr query);
int NETCAAPI netca_scvpquery_hasresponseflags(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_SCVP_ResponseFlags_Ptr NETCAAPI netca_scvpquery_getresponseflags(NETCA_ASN1_SCVP_Query_Ptr query);
int NETCAAPI netca_scvpquery_hasservercontextinfo(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvpquery_getservercontextinfo(NETCA_ASN1_SCVP_Query_Ptr query);
int NETCAAPI netca_scvpquery_hasvalidationtime(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_Time_Ptr NETCAAPI netca_scvpquery_getvalidationtime(NETCA_ASN1_SCVP_Query_Ptr query);
int NETCAAPI netca_scvpquery_hasintermediatecerts(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpquery_getintermediatecerts(NETCA_ASN1_SCVP_Query_Ptr query);
int NETCAAPI netca_scvpquery_hasrevinfos(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpquery_getrevinfos(NETCA_ASN1_SCVP_Query_Ptr query);
int NETCAAPI netca_scvpquery_hasproducedat(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_Time_Ptr NETCAAPI netca_scvpquery_getproducedat(NETCA_ASN1_SCVP_Query_Ptr query);
int NETCAAPI netca_scvpquery_hasqueryextensions(NETCA_ASN1_SCVP_Query_Ptr query);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpquery_getqueryextensions(NETCA_ASN1_SCVP_Query_Ptr query);


NETCA_ASN1_SCVP_CVRequest_Ptr  NETCAAPI netca_scvpcvrequest_new(NETCA_ASN1_Integer_Ptr cvrequestversion,
	NETCA_ASN1_SCVP_Query_Ptr query,NETCA_ASN1_List_Ptr requestorref,
	NETCA_ASN1_OctetString_Ptr requestnonce,NETCA_X509_GeneralName_Ptr requestorname,
	NETCA_X509_GeneralName_Ptr respondername,NETCA_ASN1_List_Ptr requestextensions,
	NETCA_X509AlgorithmIdentifier_Ptr signaturealg,NETCA_ASN1_OID_Ptr hashalg,
	NETCA_ASN1_String_Ptr requestortext);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpcvrequest_getcvrequestversion(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_ASN1_SCVP_Query_Ptr NETCAAPI netca_scvpcvrequest_getquery(NETCA_ASN1_SCVP_CVRequest_Ptr req);
int NETCAAPI netca_scvpcvrequest_hasrequestorref(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcvrequest_getrequestorref(NETCA_ASN1_SCVP_CVRequest_Ptr req);
int NETCAAPI netca_scvpcvrequest_hasrequestnonce(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvpcvrequest_getrequestnonce(NETCA_ASN1_SCVP_CVRequest_Ptr req);
int NETCAAPI netca_scvpcvrequest_hasrequestorname(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_scvpcvrequest_getrequestorname(NETCA_ASN1_SCVP_CVRequest_Ptr req);
int NETCAAPI netca_scvpcvrequest_hasrespondername(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_X509_GeneralName_Ptr NETCAAPI netca_scvpcvrequest_getrespondername(NETCA_ASN1_SCVP_CVRequest_Ptr req);
int NETCAAPI netca_scvpcvrequest_hasrequestextensions(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcvrequest_getrequestextensions(NETCA_ASN1_SCVP_CVRequest_Ptr req);
int NETCAAPI netca_scvpcvrequest_hassignaturealg(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_scvpcvrequest_getsignaturealg(NETCA_ASN1_SCVP_CVRequest_Ptr req);
int NETCAAPI netca_scvpcvrequest_hashashalg(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_ASN1_OID_Ptr NETCAAPI netca_scvpcvrequest_gethashalg(NETCA_ASN1_SCVP_CVRequest_Ptr req);
int NETCAAPI netca_scvpcvrequest_hasrequestortext(NETCA_ASN1_SCVP_CVRequest_Ptr req);
NETCA_ASN1_String_Ptr NETCAAPI netca_scvpcvrequest_getrequestortext(NETCA_ASN1_SCVP_CVRequest_Ptr req);


NETCA_ASN1_SCVP_ResponseStatus_Ptr  NETCAAPI netca_scvpresponsestatus_new(NETCA_ASN1_Enum_Ptr statuscode,NETCA_ASN1_String_Ptr errormessage);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_scvpresponsestatus_getstatuscode(NETCA_ASN1_SCVP_ResponseStatus_Ptr status);
int NETCAAPI netca_scvpresponsestatus_haserrormessage(NETCA_ASN1_SCVP_ResponseStatus_Ptr status);
NETCA_ASN1_String_Ptr NETCAAPI netca_scvpresponsestatus_geterrormessage(NETCA_ASN1_SCVP_ResponseStatus_Ptr status);


NETCA_ASN1_SCVP_HashValue_Ptr  NETCAAPI netca_scvphashvalue_new(NETCA_X509AlgorithmIdentifier_Ptr algorithm,NETCA_ASN1_OctetString_Ptr value);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_scvphashvalue_getalgorithm(NETCA_ASN1_SCVP_HashValue_Ptr hashvalue);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvphashvalue_getvalue(NETCA_ASN1_SCVP_HashValue_Ptr hashvalue);


NETCA_ASN1_SCVP_RequestReference_Ptr NETCAAPI netca_scvprequestreference_new_requesthash(NETCA_ASN1_SCVP_HashValue_Ptr requesthash);
NETCA_ASN1_SCVP_RequestReference_Ptr NETCAAPI netca_scvprequestreference_new_fullrequest(NETCA_ASN1_SCVP_CVRequest_Ptr fullrequest);
int NETCAAPI netca_scvprequestreference_gettype(NETCA_ASN1_SCVP_RequestReference_Ptr ref);
NETCA_ASN1_SCVP_HashValue_Ptr NETCAAPI netca_scvprequestreference_getrequesthash(NETCA_ASN1_SCVP_RequestReference_Ptr ref);
NETCA_ASN1_SCVP_CVRequest_Ptr NETCAAPI netca_scvprequestreference_getfullrequest(NETCA_ASN1_SCVP_RequestReference_Ptr ref);

NETCA_ASN1_SCVP_ReplyCheck_Ptr  NETCAAPI netca_scvpreplycheck_new(NETCA_ASN1_OID_Ptr check,NETCA_ASN1_Integer_Ptr status);
NETCA_ASN1_OID_Ptr NETCAAPI netca_scvpreplycheck_getcheck(NETCA_ASN1_SCVP_ReplyCheck_Ptr replycheck);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpreplycheck_getstatus(NETCA_ASN1_SCVP_ReplyCheck_Ptr replycheck);

NETCA_ASN1_SCVP_ReplyWantBack_Ptr  NETCAAPI netca_scvpreplywantback_new(NETCA_ASN1_OID_Ptr wb,NETCA_ASN1_OctetString_Ptr value);
NETCA_ASN1_OID_Ptr NETCAAPI netca_scvpreplywantback_getwb(NETCA_ASN1_SCVP_ReplyWantBack_Ptr replywantback);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvpreplywantback_getvalue(NETCA_ASN1_SCVP_ReplyWantBack_Ptr replywantback);


NETCA_ASN1_SCVP_CertReply_Ptr  NETCAAPI netca_scvpcertreply_new(NETCA_ASN1_SCVP_CertReference_Ptr cert,
																NETCA_ASN1_Enum_Ptr replystatus,
																NETCA_ASN1_Time_Ptr replyvaltime,
																NETCA_ASN1_List_Ptr replychecks,
																NETCA_ASN1_List_Ptr replywantbacks,
																NETCA_ASN1_List_Ptr validationerrors,
																NETCA_ASN1_Time_Ptr nextupdate,
																NETCA_ASN1_List_Ptr certreplyextensions);
NETCA_ASN1_SCVP_CertReference_Ptr NETCAAPI netca_scvpcertreply_getcert(NETCA_ASN1_SCVP_CertReply_Ptr reply);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_scvpcertreply_getreplystatus(NETCA_ASN1_SCVP_CertReply_Ptr reply);
NETCA_ASN1_Time_Ptr NETCAAPI netca_scvpcertreply_getreplyvaltime(NETCA_ASN1_SCVP_CertReply_Ptr reply);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcertreply_getreplychecks(NETCA_ASN1_SCVP_CertReply_Ptr reply);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcertreply_getreplywantbacks(NETCA_ASN1_SCVP_CertReply_Ptr reply);
int NETCAAPI netca_scvpcertreply_hasvalidationerrors(NETCA_ASN1_SCVP_CertReply_Ptr reply);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcertreply_getvalidationerrors(NETCA_ASN1_SCVP_CertReply_Ptr reply);
int NETCAAPI netca_scvpcertreply_hasnextupdate(NETCA_ASN1_SCVP_CertReply_Ptr reply);
NETCA_ASN1_Time_Ptr NETCAAPI netca_scvpcertreply_getnextupdate(NETCA_ASN1_SCVP_CertReply_Ptr reply);
int NETCAAPI netca_scvpcertreply_hascertreplyextensions(NETCA_ASN1_SCVP_CertReply_Ptr reply);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcertreply_getcertreplyextensions(NETCA_ASN1_SCVP_CertReply_Ptr reply);

NETCA_ASN1_SCVP_CVResponse_Ptr  NETCAAPI netca_scvpcvresponse_new(NETCA_ASN1_Integer_Ptr cvresponseversion,
																NETCA_ASN1_Integer_Ptr serverconfigurationid,
																NETCA_ASN1_Time_Ptr producedat,
																NETCA_ASN1_SCVP_ResponseStatus_Ptr responsestatus,
																NETCA_ASN1_SCVP_ValidationPolicy_Ptr respvalidationpolicy,
																NETCA_ASN1_SCVP_RequestReference_Ptr requestref,
																NETCA_ASN1_List_Ptr requestorref,
																NETCA_ASN1_List_Ptr requestorname,
																NETCA_ASN1_List_Ptr replyobjects,
																NETCA_ASN1_OctetString_Ptr respnonce,
																NETCA_ASN1_OctetString_Ptr servercontextinfo,
																NETCA_ASN1_List_Ptr cvresponseextensions,
																NETCA_ASN1_String_Ptr requestortext);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpcvresponse_getcvresponseversion(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpcvresponse_getserverconfigurationid(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_Time_Ptr NETCAAPI netca_scvpcvresponse_getproducedat(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_SCVP_ResponseStatus_Ptr NETCAAPI netca_scvpcvresponse_getresponsestatus(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hasrespvalidationpolicy(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_SCVP_ValidationPolicy_Ptr NETCAAPI netca_scvpcvresponse_getrespvalidationpolicy(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hasrequestref(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_SCVP_RequestReference_Ptr NETCAAPI netca_scvpcvresponse_getrequestref(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hasrequestorref(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcvresponse_getrequestorref(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hasrequestorname(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcvresponse_getrequestorname(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hasreplyobjects(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcvresponse_getreplyobjects(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hasrespnonce(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvpcvresponse_getrespnonce(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hasservercontextinfo(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvpcvresponse_getservercontextinfo(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hascvresponseextensions(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpcvresponse_getcvresponseextensions(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
int NETCAAPI netca_scvpcvresponse_hasrequestortext(NETCA_ASN1_SCVP_CVResponse_Ptr resp);
NETCA_ASN1_String_Ptr NETCAAPI netca_scvpcvresponse_getrequestortext(NETCA_ASN1_SCVP_CVResponse_Ptr resp);

NETCA_ASN1_SCVP_ValPolRequest_Ptr  NETCAAPI netca_scvpvalpolrequest_new(NETCA_ASN1_Integer_Ptr vprequestversion,
																NETCA_ASN1_OctetString_Ptr requestnonce);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpvalpolrequest_getvprequestversion(NETCA_ASN1_SCVP_ValPolRequest_Ptr req);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvpvalpolrequest_getrequestnonce(NETCA_ASN1_SCVP_ValPolRequest_Ptr req);


NETCA_ASN1_SCVP_KeyAgreePublicKey_Ptr  NETCAAPI netca_scvpkeyagreepublickey_new(NETCA_X509AlgorithmIdentifier_Ptr algorithm,
																NETCA_ASN1_BitString_Ptr publickey,
																NETCA_X509AlgorithmIdentifier_Ptr macalgorithm,
																NETCA_X509AlgorithmIdentifier_Ptr kdf);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_scvpkeyagreepublickey_getalgorithm(NETCA_ASN1_SCVP_KeyAgreePublicKey_Ptr key);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_scvpkeyagreepublickey_getpublickey(NETCA_ASN1_SCVP_KeyAgreePublicKey_Ptr key);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_scvpkeyagreepublickey_getmacalgorithm(NETCA_ASN1_SCVP_KeyAgreePublicKey_Ptr key);
int NETCAAPI netca_scvpkeyagreepublickey_haskdf(NETCA_ASN1_SCVP_KeyAgreePublicKey_Ptr key);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_scvpkeyagreepublickey_getkdf(NETCA_ASN1_SCVP_KeyAgreePublicKey_Ptr key);


NETCA_ASN1_SCVP_ValPolResponse_Ptr  NETCAAPI netca_scvpvalpolresponse_new(NETCA_ASN1_Integer_Ptr vpresponseversion,
																		  NETCA_ASN1_Integer_Ptr maxcvrequestversion,
																		  NETCA_ASN1_Integer_Ptr maxvprequestversion,
																		  NETCA_ASN1_Integer_Ptr serverconfigurationid,
																		  NETCA_ASN1_Time_Ptr thisupdate,
																		  NETCA_ASN1_Time_Ptr nextupdate,
																		  NETCA_ASN1_List_Ptr supportedchecks,
																		  NETCA_ASN1_List_Ptr supportedwantbacks,
																		  NETCA_ASN1_List_Ptr validationpolicies,
																		  NETCA_ASN1_List_Ptr validationalgs,
																		  NETCA_ASN1_List_Ptr authpolicies,
																		  NETCA_ASN1_Enum_Ptr responsetypes,
																		  NETCA_ASN1_SCVP_ValidationPolicy_Ptr defaultpolicyvalues,
																		  NETCA_ASN1_BitString_Ptr revocationinfotypes,
																		  NETCA_ASN1_List_Ptr signaturegeneration,
																		  NETCA_ASN1_List_Ptr signatureverification,
																		  NETCA_ASN1_List_Ptr hashalgorithms,
																		  NETCA_ASN1_List_Ptr serverpublickeys,
																		  NETCA_ASN1_Integer_Ptr clockskew,
																		  NETCA_ASN1_OctetString_Ptr requestnonce);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpvalpolresponse_getvpresponseversion(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpvalpolresponse_getmaxcvrequestversion(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpvalpolresponse_getmaxvprequestversion(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpvalpolresponse_getserverconfigurationid(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_Time_Ptr NETCAAPI netca_scvpvalpolresponse_getthisupdate(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
int NETCAAPI netca_scvpvalpolresponse_hasnextupdate(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_Time_Ptr NETCAAPI netca_scvpvalpolresponse_getnextupdate(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_getsupportedchecks(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_getsupportedwantbacks(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_getvalidationpolicies(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_getvalidationalgs(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_getauthpolicies(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_Enum_Ptr NETCAAPI netca_scvpvalpolresponse_getresponsetypes(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_SCVP_ValidationPolicy_Ptr NETCAAPI netca_scvpvalpolresponse_getdefaultpolicyvalues(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_scvpvalpolresponse_getrevocationinfotypes(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_getsignaturegeneration(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_getsignatureverification(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_gethashalgorithms(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
int NETCAAPI netca_scvpvalpolresponse_hasserverpublickeys(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvpvalpolresponse_getserverpublickeys(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_scvpvalpolresponse_getclockskew(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
int NETCAAPI netca_scvpvalpolresponse_hasrequestnonce(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_scvpvalpolresponse_getrequestnonce(NETCA_ASN1_SCVP_ValPolResponse_Ptr resp);


NETCA_ASN1_SCVP_RevInfoWantBack_Ptr  NETCAAPI netca_scvprevinfowantback_new(NETCA_ASN1_List_Ptr revocationInfo,
																NETCA_ASN1_List_Ptr extraCerts);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvprevinfowantback_getrevocationinfo(NETCA_ASN1_SCVP_RevInfoWantBack_Ptr revInfo);
NETCA_ASN1_List_Ptr NETCAAPI netca_scvprevinfowantback_getextracerts(NETCA_ASN1_SCVP_RevInfoWantBack_Ptr revInfo);
int NETCAAPI netca_scvprevinfowantback_hasextracerts(NETCA_ASN1_SCVP_RevInfoWantBack_Ptr revInfo);


NETCA_ASN1_CMSAlgorithmProtection_Ptr  NETCAAPI netca_cmsalgorithmprotection_newsign(NETCA_X509AlgorithmIdentifier_Ptr digestAlgorithm,
																				NETCA_X509AlgorithmIdentifier_Ptr signatureAlgorithm);
NETCA_ASN1_CMSAlgorithmProtection_Ptr  NETCAAPI netca_cmsalgorithmprotection_newmac(NETCA_X509AlgorithmIdentifier_Ptr digestAlgorithm,
																				NETCA_X509AlgorithmIdentifier_Ptr macAlgorithm);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmsalgorithmprotection_getdigestalgorithm(NETCA_ASN1_CMSAlgorithmProtection_Ptr protection);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmsalgorithmprotection_getsignaturealgorithm(NETCA_ASN1_CMSAlgorithmProtection_Ptr protection);
NETCA_X509AlgorithmIdentifier_Ptr NETCAAPI netca_cmsalgorithmprotection_getmacalgorithm(NETCA_ASN1_CMSAlgorithmProtection_Ptr protection);


NETCA_ASN1_SES_ExtData_Ptr  NETCAAPI netca_ses_extdata_new(NETCA_ASN1_OID_Ptr extnId, NETCA_ASN1_Boolean_Ptr critical, NETCA_ASN1_OctetString_Ptr extnValue);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ses_extdata_getextnid(NETCA_ASN1_SES_ExtData_Ptr ext);
NETCA_ASN1_Boolean_Ptr NETCAAPI netca_ses_extdata_getcritical(NETCA_ASN1_SES_ExtData_Ptr ext);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ses_extdata_getextnvalue(NETCA_ASN1_SES_ExtData_Ptr ext);


NETCA_ASN1_SES_Header_Ptr  NETCAAPI netca_ses_header_new(NETCA_ASN1_String_Ptr id, NETCA_ASN1_Integer_Ptr version, NETCA_ASN1_String_Ptr vid);
NETCA_ASN1_String_Ptr NETCAAPI netca_ses_header_getid(NETCA_ASN1_SES_Header_Ptr header);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ses_header_geversion(NETCA_ASN1_SES_Header_Ptr header);
NETCA_ASN1_String_Ptr NETCAAPI netca_ses_header_getvid(NETCA_ASN1_SES_Header_Ptr header);


NETCA_ASN1_SES_ESPropertyInfo_Ptr  NETCAAPI netca_ses_espropertyinfo_new(NETCA_ASN1_Integer_Ptr type, NETCA_ASN1_String_Ptr name, NETCA_ASN1_List_Ptr certList,
    NETCA_ASN1_Time_Ptr createDate, NETCA_ASN1_Time_Ptr validStart, NETCA_ASN1_Time_Ptr validEnd);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ses_espropertyinfo_gettype(NETCA_ASN1_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_String_Ptr NETCAAPI netca_ses_espropertyinfo_getname(NETCA_ASN1_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_ses_espropertyinfo_getcertlist(NETCA_ASN1_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ses_espropertyinfo_getcreatedate(NETCA_ASN1_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ses_espropertyinfo_getvalidstart(NETCA_ASN1_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_Time_Ptr NETCAAPI netca_ses_espropertyinfo_getvalidend(NETCA_ASN1_SES_ESPropertyInfo_Ptr info);


NETCA_ASN1_SES_ESPictureInfo_Ptr  NETCAAPI netca_ses_espictureinfo_new(NETCA_ASN1_String_Ptr type, NETCA_ASN1_OctetString_Ptr data, NETCA_ASN1_Integer_Ptr width, NETCA_ASN1_Integer_Ptr heigth);
NETCA_ASN1_String_Ptr NETCAAPI netca_ses_espictureinfo_gettype(NETCA_ASN1_SES_ESPictureInfo_Ptr info);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ses_espictureinfo_getdata(NETCA_ASN1_SES_ESPictureInfo_Ptr info);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ses_espictureinfo_getwidth(NETCA_ASN1_SES_ESPictureInfo_Ptr info);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ses_espictureinfo_getheigth(NETCA_ASN1_SES_ESPictureInfo_Ptr info);


NETCA_ASN1_SES_SealInfo_Ptr  NETCAAPI netca_ses_sealinfo_new(NETCA_ASN1_SES_Header_Ptr header, NETCA_ASN1_String_Ptr esId,
    NETCA_ASN1_SES_ESPropertyInfo_Ptr property, NETCA_ASN1_SES_ESPictureInfo_Ptr picture, NETCA_ASN1_List_Ptr extDatas);
NETCA_ASN1_SES_Header_Ptr NETCAAPI netca_ses_sealinfo_getheader(NETCA_ASN1_SES_SealInfo_Ptr info);
NETCA_ASN1_String_Ptr NETCAAPI netca_ses_sealinfo_getesid(NETCA_ASN1_SES_SealInfo_Ptr info);
NETCA_ASN1_SES_ESPropertyInfo_Ptr NETCAAPI netca_ses_sealinfo_getproperty(NETCA_ASN1_SES_SealInfo_Ptr info);
NETCA_ASN1_SES_ESPictureInfo_Ptr NETCAAPI netca_ses_sealinfo_getpicture(NETCA_ASN1_SES_SealInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_ses_sealinfo_getextdatas(NETCA_ASN1_SES_SealInfo_Ptr info);

NETCA_ASN1_SES_SignInfo_Ptr  NETCAAPI netca_ses_signinfo_new(NETCA_ASN1_OctetString_Ptr cert, NETCA_ASN1_OID_Ptr signatureAlgorithm, NETCA_ASN1_BitString_Ptr signData);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ses_signinfo_getcert(NETCA_ASN1_SES_SignInfo_Ptr info);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ses_signinfo_getsignaturealgorithm(NETCA_ASN1_SES_SignInfo_Ptr info);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_ses_signinfo_getsigndata(NETCA_ASN1_SES_SignInfo_Ptr info);

NETCA_ASN1_SES_SESealTbs_Ptr  NETCAAPI netca_ses_sesealtbs_new(NETCA_ASN1_SES_SealInfo_Ptr esealInfo,NETCA_ASN1_OctetString_Ptr cert, NETCA_ASN1_OID_Ptr signatureAlgorithm);
NETCA_ASN1_SES_SealInfo_Ptr NETCAAPI netca_ses_sesealtbs_getesealinfo(NETCA_ASN1_SES_SESealTbs_Ptr tbs);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ses_sesealtbs_getcert(NETCA_ASN1_SES_SESealTbs_Ptr tbs);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ses_sesealtbs_getsignaturealgorithm(NETCA_ASN1_SES_SESealTbs_Ptr tbs);

NETCA_ASN1_SES_SESeal_Ptr  NETCAAPI netca_ses_seseal_new(NETCA_ASN1_SES_SealInfo_Ptr esealInfo, NETCA_ASN1_SES_SignInfo_Ptr signInfo);
NETCA_ASN1_SES_SealInfo_Ptr NETCAAPI netca_ses_seseal_getesealinfo(NETCA_ASN1_SES_SESeal_Ptr seal);
NETCA_ASN1_SES_SignInfo_Ptr NETCAAPI netca_ses_seseal_getsigninfo(NETCA_ASN1_SES_SESeal_Ptr seal);


NETCA_ASN1_SES_TBS_Sign_Ptr  NETCAAPI netca_ses_tbssign_new(NETCA_ASN1_Integer_Ptr version, 
    NETCA_ASN1_SES_SESeal_Ptr eseal, NETCA_ASN1_BitString_Ptr timeInfo, NETCA_ASN1_BitString_Ptr dataHash,
    NETCA_ASN1_String_Ptr propertyInfo, NETCA_ASN1_OctetString_Ptr cert, NETCA_ASN1_OID_Ptr signatureAlgorithm);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_ses_tbssign_getversion(NETCA_ASN1_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_SES_SESeal_Ptr NETCAAPI netca_ses_tbssign_geteseal(NETCA_ASN1_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_ses_tbssign_gettimeinfo(NETCA_ASN1_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_ses_tbssign_getdatahash(NETCA_ASN1_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_String_Ptr NETCAAPI netca_ses_tbssign_getpropertyinfo(NETCA_ASN1_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ses_tbssign_getcert(NETCA_ASN1_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_OID_Ptr NETCAAPI netca_ses_tbssign_getsignaturealgorithm(NETCA_ASN1_SES_TBS_Sign_Ptr tbs);

NETCA_ASN1_SES_Signature_Ptr  NETCAAPI netca_ses_signature_new(NETCA_ASN1_SES_TBS_Sign_Ptr toSign,NETCA_ASN1_BitString_Ptr signature);
NETCA_ASN1_SES_TBS_Sign_Ptr NETCAAPI netca_ses_signature_gettosign(NETCA_ASN1_SES_Signature_Ptr sign);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_ses_signature_getsignature(NETCA_ASN1_SES_Signature_Ptr sign);

NETCA_ASN1_GB_SES_CertDigestObj_Ptr  NETCAAPI netca_ses_certdigestobj_new(NETCA_ASN1_String_Ptr type,NETCA_ASN1_OctetString_Ptr value);
NETCA_ASN1_String_Ptr NETCAAPI netca_ses_certdigestobj_gettype(NETCA_ASN1_GB_SES_CertDigestObj_Ptr obj);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_ses_certdigestobj_getvalue(NETCA_ASN1_GB_SES_CertDigestObj_Ptr obj);


NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr  NETCAAPI netca_gb_ses_espropertyinfo_newcert(NETCA_ASN1_Integer_Ptr type, NETCA_ASN1_String_Ptr name, NETCA_ASN1_List_Ptr certList,
    NETCA_ASN1_Time_Ptr createDate, NETCA_ASN1_Time_Ptr validStart, NETCA_ASN1_Time_Ptr validEnd);
NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr  NETCAAPI netca_gb_ses_espropertyinfo_newcertdigest(NETCA_ASN1_Integer_Ptr type, NETCA_ASN1_String_Ptr name, NETCA_ASN1_List_Ptr certList,
    NETCA_ASN1_Time_Ptr createDate, NETCA_ASN1_Time_Ptr validStart, NETCA_ASN1_Time_Ptr validEnd);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_gb_ses_espropertyinfo_gettype(NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_String_Ptr NETCAAPI netca_gb_ses_espropertyinfo_getname(NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr info);
int NETCAAPI netca_gb_ses_espropertyinfo_getcertlistype(NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_gb_ses_espropertyinfo_getcertlist(NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_gb_ses_espropertyinfo_getcertdigestlist(NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_Time_Ptr NETCAAPI netca_gb_ses_espropertyinfo_getcreatedate(NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_Time_Ptr NETCAAPI netca_gb_ses_espropertyinfo_getvalidstart(NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr info);
NETCA_ASN1_Time_Ptr NETCAAPI netca_gb_ses_espropertyinfo_getvalidend(NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr info);

NETCA_ASN1_GB_SES_SealInfo_Ptr  NETCAAPI netca_gb_ses_sealinfo_new(NETCA_ASN1_SES_Header_Ptr header, NETCA_ASN1_String_Ptr esId,
    NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr property, NETCA_ASN1_SES_ESPictureInfo_Ptr picture, NETCA_ASN1_List_Ptr extDatas);
NETCA_ASN1_SES_Header_Ptr NETCAAPI netca_gb_ses_sealinfo_getheader(NETCA_ASN1_GB_SES_SealInfo_Ptr info);
NETCA_ASN1_String_Ptr NETCAAPI netca_gb_ses_sealinfo_getesid(NETCA_ASN1_GB_SES_SealInfo_Ptr info);
NETCA_ASN1_GB_SES_ESPropertyInfo_Ptr NETCAAPI netca_gb_ses_sealinfo_getproperty(NETCA_ASN1_GB_SES_SealInfo_Ptr info);
NETCA_ASN1_SES_ESPictureInfo_Ptr NETCAAPI netca_gb_ses_sealinfo_getpicture(NETCA_ASN1_GB_SES_SealInfo_Ptr info);
NETCA_ASN1_List_Ptr NETCAAPI netca_gb_ses_sealinfo_getextdatas(NETCA_ASN1_GB_SES_SealInfo_Ptr info);

NETCA_ASN1_GB_SES_SESeal_Ptr  NETCAAPI netca_gb_ses_seal_new(NETCA_ASN1_GB_SES_SealInfo_Ptr eSealInfo, NETCA_ASN1_OctetString_Ptr cert,
    NETCA_ASN1_OID_Ptr signAlgID, NETCA_ASN1_BitString_Ptr signedValue);
NETCA_ASN1_GB_SES_SealInfo_Ptr NETCAAPI netca_gb_ses_seal_getesealinfo(NETCA_ASN1_GB_SES_SESeal_Ptr seseal);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_gb_ses_seal_getcert(NETCA_ASN1_GB_SES_SESeal_Ptr seseal);
NETCA_ASN1_OID_Ptr NETCAAPI netca_gb_ses_seal_getsignalgid(NETCA_ASN1_GB_SES_SESeal_Ptr seseal);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_gb_ses_seal_getsignedvalue(NETCA_ASN1_GB_SES_SESeal_Ptr seseal);

NETCA_ASN1_GB_SES_TBS_Sign_Ptr  NETCAAPI netca_gb_ses_tbssign_new(NETCA_ASN1_Integer_Ptr version, 
    NETCA_ASN1_GB_SES_SESeal_Ptr eseal, NETCA_ASN1_Time_Ptr timeInfo, NETCA_ASN1_BitString_Ptr dataHash,
    NETCA_ASN1_String_Ptr propertyInfo, NETCA_ASN1_List_Ptr extDatas);
NETCA_ASN1_Integer_Ptr NETCAAPI netca_gb_ses_tbssign_getversion(NETCA_ASN1_GB_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_GB_SES_SESeal_Ptr NETCAAPI netca_gb_ses_tbssign_geteseal(NETCA_ASN1_GB_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_Time_Ptr NETCAAPI netca_gb_ses_tbssign_gettimeinfo(NETCA_ASN1_GB_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_gb_ses_tbssign_getdatahash(NETCA_ASN1_GB_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_String_Ptr NETCAAPI netca_ses_gb_tbssign_getpropertyinfo(NETCA_ASN1_GB_SES_TBS_Sign_Ptr tbs);
NETCA_ASN1_List_Ptr NETCAAPI netca_gb_ses_tbssign_getextdatas(NETCA_ASN1_GB_SES_TBS_Sign_Ptr tbs);

NETCA_ASN1_GB_SES_Signature_Ptr NETCAAPI netca_gb_ses_signature_new(NETCA_ASN1_GB_SES_TBS_Sign_Ptr toSign, 
    NETCA_ASN1_OctetString_Ptr cert, NETCA_ASN1_OID_Ptr signatureAlgID,
    NETCA_ASN1_BitString_Ptr signature, NETCA_ASN1_BitString_Ptr timestamp);
NETCA_ASN1_GB_SES_TBS_Sign_Ptr NETCAAPI netca_gb_ses_signature_gettosign(NETCA_ASN1_GB_SES_Signature_Ptr sign);
NETCA_ASN1_OctetString_Ptr NETCAAPI netca_gb_ses_signature_getcert(NETCA_ASN1_GB_SES_Signature_Ptr sign);
NETCA_ASN1_OID_Ptr NETCAAPI netca_gb_ses_signature_getsignaturealgid(NETCA_ASN1_GB_SES_Signature_Ptr sign);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_gb_ses_signature_getsignature(NETCA_ASN1_GB_SES_Signature_Ptr sign);
NETCA_ASN1_BitString_Ptr NETCAAPI netca_gb_ses_signature_gettimestamp(NETCA_ASN1_GB_SES_Signature_Ptr sign);

#ifdef __cplusplus
}
#endif
#endif

