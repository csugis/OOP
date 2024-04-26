#pragma once
#include "object.h"
#include "coord.h"
#include <memory>
#include <typeinfo>
#include <cassert>
/*
<Geometry>
语法
<!-- abstract element; do not create -->
<!-- Geometry id="ID" -->                 <!-- Point,LineString,LinearRing,
                                               Polygon,MultiGeometry,Model -->
<!-- /Geometry -->
说明
这是一个抽象元素，不能直接用在 KML 文件中。它为所有派生 Geometry 
对象提供占位符对象。
*/

enum AltitudeMode{clampToGround,relativeToGround,absolute};
enum geoType
{
	geoNull = 0,
	geoPoint = 1,
	geoLineString = 2,
	geoLineRing = 3,
	geoPolygon = 4,
	geoMulti = 5
};

class Geometry :
	public Object
{
/*
<extrude>
布尔值。指定是否用线将该点连到地面。要凸出 Point，<altitudeMode> 
必须为 relativeToGround、relativeToSeaFloor 或 absolute。该点向
地球中心凸出。
*/
	bool extrude;
/*
<tessellate>
布尔值。指定是否允许 LineString 依从地形。要启用拼贴地形，海拔
高度模式必须为 clampToGround 或 clampToSeaFloor。较大的
LineStrings 应启用拼贴地形，这样它们会依从地球的曲率铺设（否则
它们会进入地下而被隐藏）。
*/
	bool tessellate;
/*
<altitudeMode>
指定如何解释 <coordinates> 元素中的“海拔高度”分量。可能的值包括
clampToGround -（默认值）指示忽略海拔高度规范（例如，在
<coordinates> 标签中）。
relativeToGround - 设置元素以特定位置实际地面高度为基准的海拔高度。
例如，如果某位置的地面高度正好与海平面齐平，某点的海拔高度设置为
9 米，则在该模式下点地标高度的图标高度是 9 米。但是，如果在地面
高度为高于海平面 10 米的位置上设置相同的坐标，则坐标高度是 19 米。
该模式的一个典型应用就是放置电线杆或滑雪缆索。
absolute - 设置坐标以海平面为基准的海拔高度，而不管该元素下地形的
实际高度如何。例如，如果您用“absolute”海拔高度模式将坐标的海拔
高度设置为 10 米，那么当下面的地形也高于海平面 10 米时，点地标的
图标看上去就在地平面上。如果地形高于海平面 3 米，则地标会高于该
地形 7 米。该模式的典型应用是放置飞机。
*/
	AltitudeMode	altitudeMode;
public:
	virtual geoType getGeoType() const = 0;
	virtual bool IsAbstract(void) = 0;
	bool IsTessellate(void) {return tessellate;}
	void setTessellate(bool tes=true) {tessellate = tes;}
	bool IsExtrude(void) {return extrude;}
	void setExtrude(bool ext=false){extrude = ext;}
	AltitudeMode getAltitudeMode(void) {return altitudeMode;}
	void setAltitudeMode(AltitudeMode mode = clampToGround) 
										{altitudeMode = mode;}
	Geometry(void);
	virtual ~Geometry(void);
	virtual Geometry* Clone() const = 0;
};
