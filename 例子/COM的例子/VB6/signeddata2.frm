VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5685
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6405
   LinkTopic       =   "Form1"
   ScaleHeight     =   5685
   ScaleWidth      =   6405
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "签名"
      Height          =   495
      Left            =   2520
      TabIndex        =   6
      Top             =   4920
      Width           =   1215
   End
   Begin VB.TextBox Text3 
      Height          =   375
      IMEMode         =   3  'DISABLE
      Left            =   1680
      PasswordChar    =   "*"
      TabIndex        =   5
      Top             =   3960
      Width           =   3975
   End
   Begin VB.TextBox Text2 
      Height          =   1575
      Left            =   1680
      TabIndex        =   3
      Top             =   2160
      Width           =   3975
   End
   Begin VB.TextBox Text1 
      Height          =   1575
      Left            =   1680
      TabIndex        =   0
      Top             =   240
      Width           =   3855
   End
   Begin VB.Label Label3 
      Caption         =   "密码："
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   4080
      Width           =   1335
   End
   Begin VB.Label Label2 
      Caption         =   "证书："
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   2280
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "签名："
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   360
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim signObj As New NetcaPkiLib.SignedData
Dim cert As New NetcaPkiLib.Certificate
Dim tbs() As Byte
Dim signature() As Byte

tbs = signObj.Verify(Text1.Text, True)
cert.Decode Text2.Text

If signObj.SetSignCertificate(cert, Text3.Text) = False Then
    MsgBox "设置签名证书失败"
    Exit Sub
End If
signObj.SetSignAlgorithm -1, NetcaPkiLib.NETCAPKI_ALGORITHM_SHA1WITHRSA

signature = signObj.CoSign
MsgBox "签名成功"

End Sub
