Option Explicit 


Function GetValue(node,name)
	Dim nameNode
	Dim valueNode
	Dim textNode
	Set nameNode=node.GetFirstElementChild()
	Set textNode=nameNode.FirstChild
	if textNode.Value<>name then
		GetValue=""
		exit Function
	end if
	Set valueNode=nameNode.SkipIgnoreNode()
	Set textNode=valueNode.FirstChild
	GetValue=textNode.Value
end Function

Dim builder
Dim xml
Dim node
Dim root
Dim nodeList
Dim str
Dim value

str="<?xml version=" & chr(34) &"1.0" & chr(34) & " encoding=" & chr(34) &"UTF-8" & chr(34)& "?>" & vblf & _
"<form xml:id=" & chr(34) &"form1" & chr(34) &">" & vblf & _
"  <item>" & vblf & _
"    <name>abcd</name>" & vblf & _
"    <value>ÄãºÃ</value>" & vblf & _
"  </item>" & vblf & _
"  <item>" & vblf & _
"    <name>efg</name>" & vblf & _
"    <value>hello</value>" & vblf & _
"  </item>" & vblf & _
"</form>"

set builder=CreateObject("NETCA_XMLCOM.Factory")

set xml=builder.CreateXMLDocumentObject()
xml.LoadXML str

set root=xml.GetRootElementNode

set nodeList=root.GetElementList("item")

for each node in nodeList
	value=GetValue(node,"abcd")
	if value<>"" then
		Wscript.echo value
	end if
next

