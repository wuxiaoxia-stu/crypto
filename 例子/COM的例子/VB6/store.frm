VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   735
      Left            =   1320
      TabIndex        =   0
      Top             =   1080
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim store As New NetcaPkiLib.store
Dim cert As NetcaPkiLib.Certificate
Dim nowTime As Date

Dim i As Long
Dim count As Long

store.Open NetcaPkiLib.NETCAPKI_CERT_STORE_TYPE_CURRENT_USER, NetcaPkiLib.NETCAPKI_CERT_STORE_NAME_MY
count = store.GetCertificateCount

nowTime = Now

For i = 1 To count
    Set cert = store.GetCertificate(i)
    If cert.ValidFromDate <= nowTime And cert.ValidToDate >= nowTime And (cert.KeyUsage And (NetcaPkiLib.NETCAPKI_KEYUSAGE_DIGITALSIGNATURE Or NetcaPkiLib.NETCAPKI_KEYUSAGE_NONREPUDIATION)) <> 0 Then
        cert.Display
    End If
Next
store.Close
End Sub


