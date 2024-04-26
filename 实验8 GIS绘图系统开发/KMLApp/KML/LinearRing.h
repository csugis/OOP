#pragma once
#include "geometry.h"
#include "LineString.h"
#include "tArray.h"
/*
<LinearRing>
语法
<LinearRing id="ID">
  <!-- specific to LinearRing -->
  <extrude>0</extrude>                       <!-- boolean -->
  <tessellate>0</tessellate>                 <!-- boolean -->
  <altitudeMode>clampToGround</altitudeMode> 
    <!-- kml:altitudeModeEnum: clampToGround, relativeToGround, or absolute -->
    <!-- or, substitute gx:altitudeMode: clampToSeaFloor, relativeToSeaFloor -->
  <coordinates>...</coordinates>             <!-- lon,lat[,alt] tuples --> 
</LinearRing>
说明
定义闭合的线条字符串，通常是多边形的外边界。也可以将 LinearRing
用作多边形的内边界，来在多边形中创建孔。多边形可包含多个用作
内边界的 <LinearRing> 元素。
请注意：在 Google 地球中，带有“clampToGround”的 <altitudeMode>
的 Polygon 依从大圆，而带有“clampToGround”的 <altitudeMode> 的
LinearRing（自动）依从连续纬度的连线。
*/
class LinearRing :
	public LineString
{
/*
<coordinates>（必需）
四个或更多的元组，每个都由“经度”、“纬度”和“海拔高度”的
浮点值组成。“海拔高度”分量是可选的。不要在元组中加入空格。最后
一个坐标必须和第一个坐标相同。坐标只能用十进制度数表示。
*/

public:
	virtual geoType getGeoType() const { return geoLineRing; };
	virtual ostream& output( ostream& out);
	virtual bool IsAbstract(void) {return false;};
	LinearRing(void);
	virtual ~LinearRing(void);
	virtual Geometry* Clone() const;
};

ostream& operator << ( ostream& , LinearRing& );