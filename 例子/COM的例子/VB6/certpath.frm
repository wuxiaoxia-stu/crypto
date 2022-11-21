VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4845
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4845
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   615
      Left            =   1680
      TabIndex        =   1
      Top             =   2280
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   1695
      Left            =   960
      TabIndex        =   0
      Top             =   360
      Width           =   2775
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim cert As New NetcaPkiLib.Certificate
Dim certPath As New NetcaPkiLib.certPath
Dim i As Long
Dim count As Long

cert.Decode Text1.Text
If certPath.Build(cert) = False Then
    MsgBox "构造证书链失败"
    Exit Sub
End If

count = certPath.GetCertificateCount

For i = 1 To count
    certPath.GetCertificate(i).Display
Next


End Sub
