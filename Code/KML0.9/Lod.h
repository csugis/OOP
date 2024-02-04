#pragma once
#include "object.h"
/*
<Lod>
“Lod”是“Level of Detail”的缩写。<LOD> 描述了屏幕上的投射区域
必须达到多大时才会视为“处于激活”状态。同时它还指定了用于淡入
（从透明到不透明）和淡出（从不透明到透明）的像素梯度大小。这些参数的直观表示见下图。
<Lod>
  <minLodPixels>256</minLodPixels>
  <maxLodPixels>-1</maxLodPixels>
  <minFadeExtent>0</minFadeExtent>
  <maxFadeExtent>0</maxFadeExtent>
</Lod>
*/

class Lod :
	public Object
{
/*
<minLodPixels>（必需）
以屏幕像素表示的测量值，表示指定区域可见性范围的下限。
Google 地球在投射到屏幕空间时计算区域大小。然后它计算区域面积的
平方根（举例来说，如果区域是正方形，视点在区域正上方，且区域
未倾斜，则该测量值等于投射区域的宽度）。如果该测量值在
<minLodPixels> 和 <maxLodPixels> 定义的限制内（并且 
<LatLonAltBox> 在视图中），该区域将会被激活。如果未达到该限制，
相关的几何图形便会被视为距离用户视点太远，以致无法绘制。
*/
	float minLodPixels;
/*
<maxLodPixels>
以屏幕像素表示的测量值，表示指定区域可见性范围的上限。默认值 -1 
表示“激活到无限大”。
*/
	float maxLodPixels;
/*
<minFadeExtent>
几何图形从完全不透明到完全透明渐变的距离。这一梯度值以屏幕
像素数表示，应用于 LOD（可见性）的下限。
*/
	float minFadeExtent;
/*
<maxFadeExtent>
几何图形从完全透明到完全不透明渐变的距离。这一梯度值以屏幕
像素数表示，应用于 LOD（可见性）的上限。
*/
	float maxFadeExtent;
public:
	void operator ()(float minLod,float maxLod,
		float minFade,float maxFade)
		{
			minLodPixels = minLod; maxLodPixels = maxLod;
			minFadeExtent = minFade; maxFadeExtent = maxFade;
		}

	float getMinLodPixels(void)const {return minLodPixels;}
	float getMaxLodPixels(void)const {return maxLodPixels;}
	float getMinFadeExtent(void)const {return minFadeExtent;}
	float getMaxFadeExtent(void)const {return maxFadeExtent;}
	virtual bool IsAbstract(void) {return false;}
	Lod(void);
	virtual ~Lod(void);
};
