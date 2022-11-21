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
      Height          =   975
      Left            =   1680
      TabIndex        =   0
      Top             =   1080
      Width           =   1335
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
    Dim cipher() As Byte
    
    key = util.HexToBinary("000102030405060708090a0b0c0d0e0f")
    data = util.HexToBinary("00112233445566778899aabbccddeeff")
    
    cipher = device.Encrypt(NetcaPkiLib.NETCAPKI_ALGORITHM_AES_ECB, key, Empty, NetcaPkiLib.NETCAPKI_PADDING_NONE, data)
    
    Dim clear() As Byte
    clear = device.Decrypt(NetcaPkiLib.NETCAPKI_ALGORITHM_AES_ECB, key, Empty, NetcaPkiLib.NETCAPKI_PADDING_NONE, cipher)
    
    If util.ByteArrayCompare(data, clear) Then
        MsgBox "加密成功"
    Else
        MsgBox "加密失败"
    End If
End Sub
