#pragma once
#include "container.h"
#include "Placemark.h"
#include "tArray.h"
/*
<Document>
语法
<Document id="ID">
  <!-- inherited from Feature element -->
  <name>...</name>                      <!-- string -->
  <visibility>1</visibility>            <!-- boolean -->
  <open>0</open>                        <!-- boolean -->
  <atom:author>...<atom:author>         <!-- xmlns:atom -->
  <atom:link>...</atom:link>            <!-- xmlns:atom -->
  <address>...</address>                <!-- string -->
  <xal:AddressDetails>...</xal:AddressDetails>  <!-- xmlns:xal -->
  <phoneNumber>...</phoneNumber>        <!-- string -->
  <Snippet maxLines="2">...</Snippet>   <!-- string -->
  <description>...</description>        <!-- string -->
  <AbstractView>...</AbstractView>      <!-- Camera or LookAt -->
  <TimePrimitive>...</TimePrimitive>
  <styleUrl>...</styleUrl>              <!-- anyURI -->
  <StyleSelector>...</StyleSelector>
  <Region>...</Region>
  <Metadata>...</Metadata>              <!-- deprecated in KML 2.2 -->
  <ExtendedData>...</ExtendedData>      <!-- new in KML 2.2 -->

  <!-- specific to Document -->
  <!-- 0 or more Schema elements -->
  <!-- 0 or more Feature elements -->
</Document>
说明
Document 是特征和样式的容器。如果您的 KML 文件使用“共享样式”，
则需要该元素。建议您使用共享样式，它需要遵循以下步骤：
在 Document 中定义所有样式。为每个样式指定唯一的 ID。
在指定的地图项或 StyleMap 中，用 <styleUrl> 元素引用样式 ID。
请注意，共享样式不会由 Document 中的地图项来继承。
*/
class Document :
	public Container
{
	tArray<Placemark> marks;
public:
	tArray<Placemark>& getPlacemarks(void) {return marks;}
	void setPlacemarks(tArray<Placemark>& pms)
	{
		marks = pms;
		for(int i=0; i< marks.getSize(); i++)
		{
			marks[i].setParentNode(this);
		}
	}
	virtual bool IsAbstract(void) {return false;};
	Document(void);
	virtual ~Document(void);
};

ostream& operator << ( ostream& , Document& );