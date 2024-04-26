#pragma once
#include "geometry.h"
#include "tArray.h"
/*
<LineString>
�﷨
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
˵��
����һ�����������߶Ρ��� <LineStyle> ָ����ɫ����ɫģʽ���߿�
͹�� LineString ʱ�����߻����쵽�����ϣ��γ�һ���е���ǽ����ʵ�
����Ρ���͹���� LineString���߱����ʹ�õ�ǰ�� LineStyle����͹��
���ֻ�ʹ�õ�ǰ�� PolyStyle����μ� KML �̳����˽� LineStrings
����paths������ʾ����
*/
class LineString :
	public Geometry
{
protected:
/*
<coordinates>�����裩
��������������Ԫ�飬ÿ�����ɡ����ȡ�����γ�ȡ��͡����θ߶ȡ�
�ĸ���ֵ��ɡ������θ߶ȡ������ǿ�ѡ�ġ���Ԫ������ո񡣲�Ҫ
��Ԫ���м���ո�
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