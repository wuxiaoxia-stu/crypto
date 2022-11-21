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
      Left            =   1560
      TabIndex        =   0
      Top             =   1200
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()

Dim device As New NetcaPkiLib.device
Dim util As New NetcaPkiLib.Utilities

Dim hashValue() As Byte
Dim data() As Byte

data = util.Encode("abc", NetcaPkiLib.NETCAPKI_CP_UTF8)
hashValue = device.Hash(NetcaPkiLib.NETCAPKI_ALGORITHM_SHA256, data)

MsgBox util.BinaryToHex(hashValue)

End Sub
