#pragma once
#include <string>
using namespace std;

#include "object.h"
/*
<Feature>
语法
<!-- abstract element; do not create -->
<!-- Feature id="ID" -->                <!-- Document,Folder,
                                             NetworkLink,Placemark,
                                             GroundOverlay,PhotoOverlay,ScreenOverlay -->
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
  <TimePrimitive>...</TimePrimitive>    <!-- TimeStamp or TimeSpan -->
  <styleUrl>...</styleUrl>              <!-- anyURI -->
  <StyleSelector>...</StyleSelector>
  <Region>...</Region>
  <Metadata>...</Metadata>              <!-- deprecated in KML 2.2 -->
  <ExtendedData>...</ExtendedData>      <!-- new in KML 2.2 -->
<-- /Feature -->
说明
这是一个抽象元素，不能直接用在 KML 文件中。
*/
class Feature :
	public Object
{
/*
<name>
在三维查看器中显示为对象的标签的用户定义的文本
（例如，用于 Placemark、Folder 或 NetworkLink 的文本）。
*/
	string name;
/*
<visibility>
布尔值。指定在第一次载入地图项时是否在三维查看器中绘制该地图项。
要让地图项可见，该地图项的所有父项的 <visibility> 标签也都必须
设置为 1。在 Google 地球列表视图中，每个地图项都有一个复选框，
使用户可以控制地图项的可见性。
*/
	bool visibility;
/*
<open>
布尔值。指定第一次载入“位置”面板时，Document 或 Folder 的显示
状态是关闭还是打开。0=收拢（默认），1=展开。另请参见 
<ListStyle>。该元素只适用于 Document、Folder 和 NetworkLink。
*/
	bool open;
/*
<description>
说明气泡框中显示的用户提供的文本。
支持用于 <description> 元素的内容从 Google 地球 4.3 更改为 5.0。
下面列出了每个版本特有的信息，以及两个版本的通用信息。
Google 地球 5.0
Google 地球 5.0 支持纯文本内容，以及说明气泡框中完整的 HTML 和
JavaScript。说明标签的内容由 WebKit 开源网络浏览器引擎呈现，
并可以像在任何基于 WebKit 的浏览器中一样显示。
常规限制
通常不允许到本地文件的链接。这可以防止恶意代码损害您的系统或
访问您的数据。如果您希望允许对您本地的文件系统进行访问，则选择
使用偏好 > 允许地标气泡框访问本地文件和个人数据。通常允许到本地
文件系统的图片文件的链接（如果包含在 <img> 标签中）。
即使是在本地文件系统上，也可以访问压缩为 KMZ 文件的内容。
完全禁用 Cookie（包含由 iFrame 中所包含内容进行设置或读取的 
Cookie）。该规则没有任何例外情况。
忽略 Doctype 声明。
HTML
HTML 通常像它在任何 WebKit 浏览器中一样呈现。
当目标包含在直接写入 KML 的 HTML 中时，可以忽略；所有此类链接
都会打开，就像将目标设置为 _blank 一样。忽略所有指定的目标。
但是，包含在 iFrame 中的 HTML，或者通过 JavaScript 或 DHTML 
动态生成的 HTML，会使用 target=“_self”作为默认值。可以指定和
支持其他目标。
不能从 iFrame 中包含的 HTML 定位到 KMZ 文件的内容、本地锚点链接
和 ;flyto 方法。
*/
	string description;
/*
<styleUrl>
Document 中定义的 <Style> 或 <StyleMap> 的网址。如果该样式在
同一个文件中，请使用 # 引用。如果该样式在外部文件中定义，请使用
带 # 引用的完整网址。示例包括
<styleUrl>#myIconStyleID</styleUrl>
<styleUrl>http://someserver.com/somestylefile.xml#restaurant</styleUrl>
<styleUrl>eateries.kml#my-lunch-spot</styleUrl>
*/
	string styleUrl;
//<Region>
//与 Region 关联的地图项和几何图形只在该区域激活时绘制。请参见 <Region>。
	//Region region;
public:
	//Region& getRegion(void) {return region;}
	//void setRegion(Region& r) {region = r;}
	string& getStyleUrl(void) {return styleUrl;}
	void setStyleUrl(string& style) {styleUrl = style;}
	string& getName(void) {return name;}
	string& getDescription(void) {return description;}
	bool IsVisible(void) {return visibility;}
	bool IsOpen(void) {return open;}
	void setName(string& na) {name = na;} 
	void setDescrription(string& des){description = des;}
	void setVisibility(bool vis = true) {visibility = vis;}
	void setOpen(bool op = true) {open = op;}
	virtual bool IsAbstract(void) = 0;
	Feature(void);
	virtual ~Feature(void);
};
