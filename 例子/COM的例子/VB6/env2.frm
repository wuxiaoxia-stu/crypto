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
      Height          =   615
      Left            =   1680
      TabIndex        =   1
      Top             =   2160
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   1575
      Left            =   840
      TabIndex        =   0
      Top             =   360
      Width           =   3015
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim env As New netcapkilib.EnvelopedData

Dim clear0() As Byte


'------------------------------------构造数字信封成功
Dim cipher() As Byte


Dim cert As New netcapkilib.Certificate
Dim util As New netcapkilib.Utilities

cert.Decode Text1.Text
env.EncryptAlgorithm = netcapkilib.NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC
env.AddCert cert

clear0 = util.Encode("123", netcapkilib.NETCAPKI_CP_UTF8)
cipher = env.Encrypt(clear0)
MsgBox "构造数字信封成功"


'--------------------------




'------------------------------------解密
Dim clear() As Byte
clear = env.Decrypt(cipher)

MsgBox "解密成功"

env.GetDecryptCertificate().Display
'--------------------------------------
End Sub
