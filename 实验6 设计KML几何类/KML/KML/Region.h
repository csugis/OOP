#pragma once
#include "object.h"
#include "LatLonAltBox.h"
#include "Lod.h"
/*
<Region>
语法
<Region id="ID"> 
  <LatLonAltBox> 
    <north></north>                            <!-- required; kml:angle90 -->
    <south></south>                            <!-- required; kml:angle90 --> 
    <east></east>                              <!-- required; kml:angle180 -->
    <west></west>                              <!-- required; kml:angle180 -->
    <minAltitude>0</minAltitude>               <!-- float -->
    <maxAltitude>0</maxAltitude>               <!-- float -->
    <altitudeMode>clampToGround</altitudeMode> 
        <!-- kml:altitudeModeEnum: clampToGround, relativeToGround, or absolute -->
        <!-- or, substitute gx:altitudeMode: clampToSeaFloor, relativeToSeaFloor --> 
  </LatLonAltBox> 
  <Lod>
    <minLodPixels>0</minLodPixels>             <!-- float -->
    <maxLodPixels>-1</maxLodPixels>            <!-- float -->
    <minFadeExtent>0</minFadeExtent>           <!-- float --> 
    <maxFadeExtent>0</maxFadeExtent>           <!-- float -->
  </Lod>
</Region> 
说明
区域包含“范围框”(<LatLonAltBox>)，此框描述了用地理坐标和海拔
高度定义的关注区域。此外，Region 还包含“LOD（详细级别）程度”
(<Lod>)，它根据投射的屏幕大小定义相关区域的正确范围。范围框在
用户视野内并且满足 LOD 要求时，区域就会视为“处于激活”状态。
与区域关联的对象只在该区域激活时绘制。当 <viewRefreshMode> 是 
onRegion 时，Link 或 Icon 只在区域激活时载入。请参见“KML 主题”
页中关于 Regions 的部分，以了解详细信息。在 Container 或 
NetworkLink 的层次结构中，该计算使用层次结构中最接近“上级”的
区域。
*/
class Region :
	public Object
{
	LatLonAltBox box;
	Lod lod;
public:
	virtual bool IsAbstract(void) {return false;}
	Region(void);
	virtual ~Region(void);
};
