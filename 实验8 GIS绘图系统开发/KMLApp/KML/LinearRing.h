#pragma once
#include "geometry.h"
#include "LineString.h"
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
	public LineString
{
/*
<coordinates>�����裩
�ĸ�������Ԫ�飬ÿ�����ɡ����ȡ�����γ�ȡ��͡����θ߶ȡ���
����ֵ��ɡ������θ߶ȡ������ǿ�ѡ�ġ���Ҫ��Ԫ���м���ո����
һ���������͵�һ��������ͬ������ֻ����ʮ���ƶ�����ʾ��
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