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
      Left            =   1440
      TabIndex        =   0
      Top             =   960
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim ts As New NetcaPkiLib.TimeStamp
Dim device As New NetcaPkiLib.device
Dim util As New NetcaPkiLib.Utilities

Dim algo As Long
Dim hashValue() As Byte
Dim resp As Long

algo = NetcaPkiLib.NETCAPKI_ALGORITHM_SHA1
hashValue = device.Hash(algo, util.Encode("123", NetcaPkiLib.NETCAPKI_CP_UTF8))

ts.TsaUrl = "https://classatsa.cnca.net/tsa.asp"
ts.HashAlgorithm = algo
ts.MessageImprint = hashValue
resp = ts.GetTSPResponse

If resp = NetcaPkiLib.NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTED Or resp = NetcaPkiLib.NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS Then
    MsgBox ts.GetTime
Else
    MsgBox "获取时间戳出错"
End If




End Sub
