#pragma once
#include "object.h"
#include "geometry.h"
/*
<LatLonAltBox>�����裩
����ͨ����������ͺ��θ߶ȶ���Ĺ�ע����ķ�Χ��Ĭ��ֵ�ͱ���
�ֶ����£�*/


class LatLonAltBox :
	public Object
{
/*
<altitudeMode> �� <gx:altitudeMode>
<altitudeMode> ���ܵ�ֵ�� clampToGround��relativeToGround �� 
absolute��<gx:altitudeMode> ���ܵ�ֵ�� clampToSeaFloor �� 
relativeToSeaFloor������μ� <LatLonBox>��*/
	AltitudeMode altitudeMode;
//<minAltitude>
//���ױ�ʾ�����ܺ��θ߶�ģʽ�淶��Ӱ�죩��
	float minAltitude;
//<maxAltitude>
//���ױ�ʾ�����ܺ��θ߶�ģʽ�淶��Ӱ�죩��
	float maxAltitude;
//<north>�����裩
//ָ����Χ�򱱱�Ե��γ�ȣ��� 0 �� ��90 ��ʮ���ƶ�����ʾ��
	double north;
//<south>�����裩
//ָ����Χ���ϱ�Ե��γ�ȣ��� 0 �� ��90 ��ʮ���ƶ�����ʾ��
	double south;
//<east>�����裩
//ָ����Χ�򶫱�Ե�ľ��ȣ��� 0 �� ��180 ��ʮ���ƶ�����ʾ��
	double east;
//<west>�����裩
//ָ����Χ������Ե�ľ��ȣ��� 0 �� ��180 ��ʮ���ƶ�����ʾ��
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
