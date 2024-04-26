#pragma once
#include "feature.h"
#include "Geometry.h"
/*
<Placemark>
语法
<Placemark id="ID">
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

  <!-- specific to Placemark element -->
  <Geometry>...</Geometry>
</Placemark>
说明
地标是具有相关几何图形的地图项。在 Google 地球中，地标显示为
“位置”面板中的列表项。点地标具有关联的图标，该图标会在三维
查看器中的地球上做点的标记。（在 Google 地球三维查看器中，点地标
是您可以点击或滚动的唯一对象。其他几何图形对象在三维查看器中没有
图标。要使用户在三维查看器中有对象可以点击，需要创建 
MultiGeometry 对象，后者包含点和其他几何图形对象。）
*/
class Placemark :
	public Feature
{
//地标特有的元素
//0 个或 1 个 <Geometry> 元素
	Geometry * pGeometry;
public:
	virtual ostream& output( ostream& out);
	Geometry* getGeometry(void) {return pGeometry;}
	void setGeometry(Geometry* pGeo)
							{
								pGeometry = pGeo;
								pGeometry->setParentNode(this);
							}
	virtual bool IsAbstract(void) {return false;};
	Placemark& operator = (Placemark& mark);
	Placemark(Placemark& mark);
	Placemark(void);
	virtual ~Placemark(void);
};

ostream& operator << ( ostream& , Placemark& );