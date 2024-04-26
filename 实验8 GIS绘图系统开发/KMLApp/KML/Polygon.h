#pragma once
#include "geometry.h"
#include "LinearRing.h"
#include "tArray.h"
/*
<Polygon>
�﷨
<Polygon id="ID">
  <!-- specific to Polygon -->
  <extrude>0</extrude>                       <!-- boolean -->
  <tessellate>0</tessellate>                 <!-- boolean -->
  <altitudeMode>clampToGround</altitudeMode> 
        <!-- kml:altitudeModeEnum: clampToGround, relativeToGround, or absolute -->
        <!-- or, substitute gx:altitudeMode: clampToSeaFloor, relativeToSeaFloor -->
  <outerBoundaryIs>
    <LinearRing>
      <coordinates>...</coordinates>         <!-- lon,lat[,alt] -->
    </LinearRing>
  </outerBoundaryIs>
  <innerBoundaryIs>
    <LinearRing>
      <coordinates>...</coordinates>         <!-- lon,lat[,alt] -->
    </LinearRing>
  </innerBoundaryIs>
</Polygon>
˵��
Polygon ������߽�� 0 �������ڱ߽綨��ġ����߽������� 
LinearRing ����ġ�͹�������ʱ�����ı߽�����ӵ����棬�γɶ���
�Ķ���Σ��������е�����������塣͹���Ķ���λ�ʹ�� 
<PolyStyle> ��Ϊ���ǵ���ɫ����ɫģʽ����䡣
��ע�⣺�� Google �����У����С�clampToGround���� <altitudeMode>
�� Polygon ���Ӵ�Բ�������С�clampToGround���� <altitudeMode> ��
LinearRing���Զ�����������γ�ȵ����ߡ�
*/
class Polygon :
	public Geometry
{
/*
<outerBoundaryIs>�����裩
���� <LinearRing> Ԫ�ء�
*/
	LinearRing outerBoundary;
/*
<innerBoundaryIs>
���� <LinearRing> Ԫ�ء�һ�� Polygon ���԰������<innerBoundaryIs> 
Ԫ�أ���ЩԪ�ؿ����� Polygon �ڴ�������пڡ�
*/
	tArray<LinearRing> innerBoundary;
public:
	virtual geoType getGeoType() const { return geoPolygon; };

	Polygon& operator = (Polygon&);
	virtual ostream& output( ostream& out);
	virtual bool IsAbstract(void) {return false;};
	LinearRing& getOuterBoundary(void){return outerBoundary;}
	tArray<LinearRing>& getInnerBoundary(void)
									{return innerBoundary;}
	void setOuterBoundary(LinearRing& outer)
						{
							outerBoundary = outer;
							outerBoundary.setParentNode(this);
						}
    void setInnerBoundary(tArray<LinearRing>& inner)
			{
				innerBoundary = inner;
				for(int i = 0; i< innerBoundary.getSize(); i++)
					innerBoundary[i].setParentNode(this);
			}
	Polygon(void);
	Polygon(const Polygon&);
	virtual ~Polygon(void);
	virtual Geometry* Clone() const;
};
typedef class Polygon Poly;
ostream& operator << ( ostream& , Poly& );
