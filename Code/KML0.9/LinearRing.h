#pragma once
#include "geometry.h"
#include "tArray.h"
/*
<LinearRing>
�﷨
<LinearRing id="ID">
  <!-- specific to LinearRing -->
  <extrude>0</extrude>                       <!-- boolean -->
  <tessellate>0</tessellate>                 <!-- boolean -->
  <altitudeMode>clampToGround</altitudeMode> 
    <!-- kml:altitudeModeEnum: clampToGround, relativeToGround, or absolute -->
    <!-- or, substitute gx:altitudeMode: clampToSeaFloor, relativeToSeaFloor -->
  <coordinates>...</coordinates>             <!-- lon,lat[,alt] tuples --> 
</LinearRing>
˵��
����պϵ������ַ�����ͨ���Ƕ���ε���߽硣Ҳ���Խ� LinearRing
��������ε��ڱ߽磬���ڶ�����д����ס�����οɰ����������
�ڱ߽�� <LinearRing> Ԫ�ء�
��ע�⣺�� Google �����У����С�clampToGround���� <altitudeMode>
�� Polygon ���Ӵ�Բ�������С�clampToGround���� <altitudeMode> ��
LinearRing���Զ�����������γ�ȵ����ߡ�
*/
class LinearRing :
	public Geometry
{
/*
<coordinates>�����裩
�ĸ�������Ԫ�飬ÿ�����ɡ����ȡ�����γ�ȡ��͡����θ߶ȡ���
����ֵ��ɡ������θ߶ȡ������ǿ�ѡ�ġ���Ҫ��Ԫ���м���ո����
һ���������͵�һ��������ͬ������ֻ����ʮ���ƶ�����ʾ��
*/
	tArray<Coord> coordinates;

public:
	virtual ostream& output( ostream& out);
	virtual bool IsAbstract(void) {return false;};
	void setCoordinates(tArray<Coord>& pa){coordinates = pa;}
	tArray<Coord>& getCoordinates(void) {return coordinates;}
	LinearRing(void);
	virtual ~LinearRing(void);
};

ostream& operator << ( ostream& , LinearRing& );