#pragma once
#include "geometry.h"
#include "LinearRing.h"
#include "tArray.h"
/*
<Polygon>
语法
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
说明
Polygon 是用外边界和 0 个或多个内边界定义的。而边界又是由 
LinearRing 定义的。凸出多边形时，它的边界会连接到地面，形成额外
的多边形，看起来有点像建筑物或箱体。凸出的多边形会使用 
<PolyStyle> 作为它们的颜色、颜色模式和填充。
请注意：在 Google 地球中，带有“clampToGround”的 <altitudeMode>
的 Polygon 依从大圆，而带有“clampToGround”的 <altitudeMode> 的
LinearRing（自动）依从连续纬度的连线。
*/
class Polygon :
	public Geometry
{
/*
<outerBoundaryIs>（必需）
包含 <LinearRing> 元素。
*/
	LinearRing outerBoundary;
/*
<innerBoundaryIs>
包含 <LinearRing> 元素。一个 Polygon 可以包含多个<innerBoundaryIs> 
元素，这些元素可以在 Polygon 内创建多个切口。
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
