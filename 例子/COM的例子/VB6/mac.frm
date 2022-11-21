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
      Height          =   855
      Left            =   1440
      TabIndex        =   0
      Top             =   1200
      Width           =   1575
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

Dim key() As Byte
Dim data() As Byte
Dim macValue() As Byte

key = util.Encode("Jefe", NetcaPkiLib.NETCAPKI_CP_UTF8)
data = util.Encode("what do ya want for nothing?", NetcaPkiLib.NETCAPKI_CP_UTF8)

macValue = device.Mac(NetcaPkiLib.NETCAPKI_ALGORITHM_HMAC_SHA256, key, data)

MsgBox util.BinaryToHex(macValue)

End Sub
