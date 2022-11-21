VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3630
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3630
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   615
      Left            =   1680
      TabIndex        =   1
      Top             =   2760
      Width           =   975
   End
   Begin VB.TextBox Text1 
      Height          =   2055
      Left            =   720
      TabIndex        =   0
      Top             =   360
      Width           =   3135
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim env As New netcapkilib.EnvelopedData
Dim cert As New netcapkilib.Certificate
Dim util As New netcapkilib.Utilities

Dim clear() As Byte
Dim cipher() As Byte

cert.Decode Text1.Text
env.EncryptAlgorithm = netcapkilib.NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC
env.AddCert cert

clear = util.Encode("123", netcapkilib.NETCAPKI_CP_UTF8)
cipher = env.Encrypt(clear)
'Text1.Text = env.Encrypt(clear, netcapkilib.NETCAPKI_CMS_ENCODE_BASE64)
MsgBox "构造数字信封成功"
End Sub
