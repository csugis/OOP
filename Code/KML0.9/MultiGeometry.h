#pragma once
#include "geometry.h"
#include "tArray.h"
#include "point.h"
#include "linestring.h"
#include "polygon.h"
/*
<MultiGeometry>
�﷨
<MultiGeometry id="ID">
  <!-- specific to MultiGeometry -->
  <!-- 0 or more Geometry elements -->
</MultiGeometry>
˵��
��ͬһ��ͼ������� 0 ��������������ͼ�ε�������
��ע�⣺���Ƽ�ʹ�� <GeometryCollection> ��ǩ����Ӧʹ�� 
<MultiGeometry>��
*/
class MultiGeometry :
	public Geometry
{
/*
MultiGeometry ���е�Ԫ��
0 ������ <Geometry> Ԫ��
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