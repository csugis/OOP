#pragma once
#include "geometry.h"
#include "tArray.h"
#include "point.h"
#include "linestring.h"
#include "polygon.h"
/*
<MultiGeometry>
语法
<MultiGeometry id="ID">
  <!-- specific to MultiGeometry -->
  <!-- 0 or more Geometry elements -->
</MultiGeometry>
说明
与同一地图项关联的 0 个或多个基本几何图形的容器。
请注意：不推荐使用 <GeometryCollection> 标签，而应使用 
<MultiGeometry>。
*/
class MultiGeometry :
	public Geometry
{
/*
MultiGeometry 特有的元素
0 个或多个 <Geometry> 元素
*/
	tArray<Point> points;
	tArray<LineString> lines;
	tArray<Poly> polygons;
public:
	virtual ostream& output( ostream& out);
	tArray<Point>& getPoints(void){return points;}
	tArray<LineString>& getLineStrings(void){return lines;}
	tArray<Poly>& getPolygons(void){return polygons;}
	void setPoints(tArray<Point>& ps)
				{
					points = ps;
					for(int i = 0; i < points.getSize(); i++)
						points[i].setParentNode(this);
				}
	void setLines(tArray<LineString>& ls) 
				{
					lines = ls;
					for(int i = 0; i < lines.getSize(); i++)
						lines[i].setParentNode(this);
				}
	void setPolygons(tArray<Poly>& polys)
				{
					polygons = polys;
					for(int i = 0; i < polygons.getSize(); i++)
					{
						polygons[i].setParentNode(this);
					}
				}
	virtual bool IsAbstract(void) {return false;}
	MultiGeometry(void);
	virtual ~MultiGeometry(void);
};

ostream& operator << ( ostream& , MultiGeometry& );