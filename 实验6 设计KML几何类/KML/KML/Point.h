#pragma once
#include "geometry.h"
/*
<Point>
语法
<Point id="ID">
  <!-- specific to Point -->
  <extrude>0</extrude>                        <!-- boolean -->
  <altitudeMode>clampToGround</altitudeMode>  
	      <!-- kml:altitudeModeEnum: clampToGround, relativeToGround, or absolute -->
        <!-- or, substitute gx:altitudeMode: clampToSeaFloor, relativeToSeaFloor -->
  <coordinates>...</coordinates>              <!-- lon,lat[,alt] -->
</Point>
说明
用经度、纬度和（可选）海拔高度定义的地理位置。地标中包含点时，点
本身会判断地标名称和图标的位置。点凸出时，可用线将它连接到地面。
该“绳索”使用当前的 LineStyle。

示例
<Point>
  <coordinates>-90.86948943473118,48.25450093195546</coordinates>
</Point>
*/

class Point :
	public Geometry
{
/*
<coordinates>（必需）
由经度、纬度和海拔高度（按此顺序）的浮点值组成的单个元组。经度和纬度值的单位是度，其中
“经度”≥ −180 且 <= 180
“纬度”≥ −90 且 ≤ 90
“海拔高度”值（可选）高出海平面（以米表示）
在描述坐标的三个值之间不要留空格。
*/
	Coord coordinates;
//	friend ostream& operator << ( ostream& , Point& ); 
//	friend istream& operator >> ( istream& , Point& );
public:
	virtual ostream& output( ostream& out);
	virtual bool IsAbstract(void) {return false;};
	double getLongitude(void) {return coordinates.getLongitude();}
	double getLatitude(void) {return coordinates.getLatitude();}
	double getAltitude(void) {return coordinates.getAltitude();}
	void setLongitude(double lon) {coordinates.setLongitude(lon);}
	void setLatitude(double lat) {coordinates.setLatitude(lat);}
	void setAltitude(double alt) {coordinates.setAltitude(alt);}
	void operator ()(double lon, double lat, double alt = 0)
									{coordinates(lon,lat,alt);}
	Point(void);
	virtual ~Point(void);
};
ostream& operator << ( ostream& , Point& ); 
//istream& operator >> ( istream& , Point& );
