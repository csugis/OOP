#pragma once
#include "object.h"
#include "geometry.h"
/*
<LatLonAltBox>（必需）
描述通过地理坐标和海拔高度定义的关注区域的范围框。默认值和必需
字段如下：*/


class LatLonAltBox :
	public Object
{
/*
<altitudeMode> 或 <gx:altitudeMode>
<altitudeMode> 可能的值有 clampToGround、relativeToGround 和 
absolute。<gx:altitudeMode> 可能的值有 clampToSeaFloor 和 
relativeToSeaFloor。另请参见 <LatLonBox>。*/
	AltitudeMode altitudeMode;
//<minAltitude>
//以米表示（并受海拔高度模式规范的影响）。
	float minAltitude;
//<maxAltitude>
//以米表示（并受海拔高度模式规范的影响）。
	float maxAltitude;
//<north>（必需）
//指定范围框北边缘的纬度，以 0 到 ±90 的十进制度数表示。
	double north;
//<south>（必需）
//指定范围框南边缘的纬度，以 0 到 ±90 的十进制度数表示。
	double south;
//<east>（必需）
//指定范围框东边缘的经度，以 0 到 ±180 的十进制度数表示。
	double east;
//<west>（必需）
//指定范围框西边缘的经度，以 0 到 ±180 的十进制度数表示。
	double west;
public:
	virtual bool IsAbstract(void) {return false;}
	AltitudeMode getAltitudeMode(void) {return altitudeMode;}
	void setAltitudeMode(AltitudeMode mode = clampToGround) 
										{altitudeMode = mode;}
	void operator ()(double n,double s, double e, double w,
		float minalt=0, float maxalt=0)
				{
					north = n; south = s; east = e; west = w;
					minAltitude = minalt; maxAltitude = maxalt;
				}
	double getNorth(void)const {return north;}
	double getSouth(void)const {return south;}
	double getEast(void)const {return east;}
	double getWest(void)const {return west;}
	float getMinAltitude(void)const {return minAltitude;}
	float getMaxAltitude(void)const {return maxAltitude;}
	LatLonAltBox(void);
	virtual ~LatLonAltBox(void);
};
