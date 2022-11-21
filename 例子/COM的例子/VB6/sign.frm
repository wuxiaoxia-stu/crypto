VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3645
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3645
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   735
      Left            =   1920
      TabIndex        =   1
      Top             =   2760
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   2055
      Left            =   720
      TabIndex        =   0
      Top             =   360
      Width           =   3375
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim cert As New NetcaPkiLib.Certificate
Dim util As New NetcaPkiLib.Utilities

Dim algo As Long
Dim tbs() As Byte
Dim sign() As Byte

cert.Decode Text1.Text
algo = NetcaPkiLib.NETCAPKI_ALGORITHM_SHA1WITHRSA
tbs = util.Encode("你好,NETCA", NetcaPkiLib.NETCAPKI_CP_UTF8)
sign = cert.sign(algo, tbs)

MsgBox "签名成功"

If cert.Verify(algo, tbs, sign) Then
    MsgBox "验证签名成功"
Else
    MsgBox "验证签名失败"
End If

End Sub
