#pragma once
#include "geometry.h"
#include "tArray.h"
/*
<LineString>
语法
<LineString id="ID">
  <!-- specific to LineString -->
  <extrude>0</extrude>                   <!-- boolean -->
  <tessellate>0</tessellate>             <!-- boolean -->
  <altitudeMode>clampToGround</altitudeMode> 
      <!-- kml:altitudeModeEnum: clampToGround, relativeToGround, or absolute -->
        <!-- or, substitute gx:altitudeMode: clampToSeaFloor, relativeToSeaFloor -->
			<!-- or, substitute gx:altitudeMode: clampToSeaFloor, relativeToSeaFloor -->
  <coordinates>...</coordinates>         <!-- lon,lat[,alt] -->
</LineString>
说明
定义一组连起来的线段。用 <LineStyle> 指定颜色、颜色模式和线宽。
凸出 LineString 时，该线会延伸到地面上，形成一个有点像墙或篱笆的
多边形。对凸出的 LineString，线本身会使用当前的 LineStyle，而凸出
部分会使用当前的 PolyStyle。请参见 KML 教程以了解 LineStrings
（或“paths”）的示例。
*/
class LineString :
	public Geometry
{
protected:
/*
<coordinates>（必需）
两个或更多的坐标元组，每个都由“经度”、“纬度”和“海拔高度”
的浮点值组成。“海拔高度”分量是可选的。在元组间加入空格。不要
在元组中加入空格
*/
	tArray<Coord> coordinates;
//	friend ostream& operator << ( ostream& , LineString& ); 
public:
	virtual geoType getGeoType() const { return geoLineString; };
	virtual ostream& output( ostream& out);
	virtual bool IsAbstract(void) {return false;};
	void setCoordinates(tArray<Coord>& pa){coordinates = pa;}
	tArray<Coord>& getCoordinates(void) {return coordinates;}
	LineString(void);
	virtual ~LineString(void);
	virtual Geometry* Clone() const;
};

ostream& operator << ( ostream& , LineString& ); 