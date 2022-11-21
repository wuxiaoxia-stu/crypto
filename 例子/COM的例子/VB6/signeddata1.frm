VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3885
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5220
   LinkTopic       =   "Form1"
   ScaleHeight     =   3885
   ScaleWidth      =   5220
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   735
      Left            =   1800
      TabIndex        =   1
      Top             =   2760
      Width           =   1575
   End
   Begin VB.TextBox Text1 
      Height          =   1935
      Left            =   840
      TabIndex        =   0
      Top             =   360
      Width           =   3255
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim signObj As New NetcaPkiLib.SignedData
Dim util As New NetcaPkiLib.Utilities
Dim cert As New NetcaPkiLib.Certificate
Dim tbs() As Byte
Dim signature() As Byte

tbs = util.Encode("123", NetcaPkiLib.NETCAPKI_CP_UTF8)

cert.Decode Text1.Text
If signObj.SetSignCertificate(cert, "") = False Then
    MsgBox "设置签名证书失败"
    Exit Sub
End If
signObj.SetSignAlgorithm -1, NetcaPkiLib.NETCAPKI_ALGORITHM_SHA1WITHRSA

signObj.Detached = True

signature = signObj.Sign(tbs)
MsgBox "签名成功"

Dim sign2Obj As New NetcaPkiLib.SignedData

If sign2Obj.DetachedVerify(tbs, signature) Then
    MsgBox "验证签名证书成功"
Else
    MsgBox "验证签名证书失败"
    Exit Sub
End If

sign2Obj.GetSignCertificate().Display
End Sub
