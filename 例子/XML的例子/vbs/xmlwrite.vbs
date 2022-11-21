Option Explicit 

Dim builder
Dim xml
Dim node
Dim root
Dim attr
Dim text
Dim item
Dim cur
Dim name
Dim value

set builder=CreateObject("NETCA_XMLCOM.Factory")

set root=builder.CreateXMLNodeObject()

root.NewElementNode "form"

set xml=builder.CreateXMLDocumentObject()

xml.NewXML root

set attr=root.NewAttributeNode("xml:id","form1",Nothing)

set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf & "  ")

Set cur=root.AddChild(text)


set item=builder.CreateXMLNodeObject()
item.NewElementNode "item"

set cur=cur.AddNextSibling(item)

Set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf & "    ")

set cur=cur.AddChild(text)

set name=builder.CreateXMLNodeObject()
name.NewElementNode "name"

Set cur=cur.AddNextSibling(name)

Set text=builder.CreateXMLNodeObject()
text.NewTextNode("abcd")

name.AddChild text

Set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf & "    ")

Set cur=cur.AddNextSibling(text)

set value=builder.CreateXMLNodeObject()
value.NewElementNode "value"

Set cur=cur.AddNextSibling(value)

Set text=builder.CreateXMLNodeObject()
text.NewTextNode("ÄãºÃ")

value.AddChild text

set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf & "  ")

cur.AddNextSibling text

set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf & "  ")

set cur=item.AddNextSibling(text)

set item=builder.CreateXMLNodeObject()
item.NewElementNode "item"

set cur=cur.AddNextSibling(item)


Set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf & "    ")

set cur=cur.AddChild(text)

set name=builder.CreateXMLNodeObject()
name.NewElementNode "name"

Set cur=cur.AddNextSibling(name)

Set text=builder.CreateXMLNodeObject()
text.NewTextNode("efg")

name.AddChild text

Set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf & "    ")

Set cur=cur.AddNextSibling(text)

set value=builder.CreateXMLNodeObject()
value.NewElementNode "value"

Set cur=cur.AddNextSibling(value)

Set text=builder.CreateXMLNodeObject()
text.NewTextNode("hello")

value.AddChild text

set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf & "  ")

cur.AddNextSibling text


set text=builder.CreateXMLNodeObject()
text.NewTextNode(vblf)

set cur=item.AddNextSibling(text)

Wscript.echo xml.Encode


