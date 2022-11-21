VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4365
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   4365
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "加密"
      Height          =   615
      Left            =   1680
      TabIndex        =   1
      Top             =   3480
      Width           =   1455
   End
   Begin VB.TextBox Text1 
      Height          =   2535
      Left            =   360
      TabIndex        =   0
      Top             =   600
      Width           =   3975
   End
   Begin VB.Label Label1 
      Caption         =   "请输入加密证书Base64编码内容："
      Height          =   255
      Left            =   360
      TabIndex        =   2
      Top             =   120
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
Dim util As New NetcaPkiLib.Utilities
Dim data() As Byte
Dim cipher() As Byte

cert.Decode Text1.Text
data = util.Encode("你好,NETCA", NetcaPkiLib.NETCAPKI_CP_UTF8)
cipher = cert.Encrypt(NetcaPkiLib.NETCAPKI_ALGORITHM_RSA_PKCS1_V1_5_ENC, data)

MsgBox "加密成功"
End Sub
