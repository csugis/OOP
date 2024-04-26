#pragma once
#include "object.h"
#include "coord.h"
#include <memory>
#include <typeinfo>
#include <cassert>
/*
<Geometry>
�﷨
<!-- abstract element; do not create -->
<!-- Geometry id="ID" -->                 <!-- Point,LineString,LinearRing,
                                               Polygon,MultiGeometry,Model -->
<!-- /Geometry -->
˵��
����һ������Ԫ�أ�����ֱ������ KML �ļ��С���Ϊ�������� Geometry 
�����ṩռλ������
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
����ֵ��ָ���Ƿ����߽��õ��������档Ҫ͹�� Point��<altitudeMode> 
����Ϊ relativeToGround��relativeToSeaFloor �� absolute���õ���
��������͹����
*/
	bool extrude;
/*
<tessellate>
����ֵ��ָ���Ƿ����� LineString ���ӵ��Ρ�Ҫ����ƴ�����Σ�����
�߶�ģʽ����Ϊ clampToGround �� clampToSeaFloor���ϴ��
LineStrings Ӧ����ƴ�����Σ��������ǻ����ӵ�����������裨����
���ǻ������¶������أ���
*/
	bool tessellate;
/*
<altitudeMode>
ָ����ν��� <coordinates> Ԫ���еġ����θ߶ȡ����������ܵ�ֵ����
clampToGround -��Ĭ��ֵ��ָʾ���Ժ��θ߶ȹ淶�����磬��
<coordinates> ��ǩ�У���
relativeToGround - ����Ԫ�����ض�λ��ʵ�ʵ���߶�Ϊ��׼�ĺ��θ߶ȡ�
���磬���ĳλ�õĵ���߶������뺣ƽ����ƽ��ĳ��ĺ��θ߶�����Ϊ
9 �ף����ڸ�ģʽ�µ�ر�߶ȵ�ͼ��߶��� 9 �ס����ǣ�����ڵ���
�߶�Ϊ���ں�ƽ�� 10 �׵�λ����������ͬ�����꣬������߶��� 19 �ס�
��ģʽ��һ������Ӧ�þ��Ƿ��õ��߸˻�ѩ������
absolute - ���������Ժ�ƽ��Ϊ��׼�ĺ��θ߶ȣ������ܸ�Ԫ���µ��ε�
ʵ�ʸ߶���Ρ����磬������á�absolute�����θ߶�ģʽ������ĺ���
�߶�����Ϊ 10 �ף���ô������ĵ���Ҳ���ں�ƽ�� 10 ��ʱ����ر��
ͼ�꿴��ȥ���ڵ�ƽ���ϡ�������θ��ں�ƽ�� 3 �ף���ر����ڸ�
���� 7 �ס���ģʽ�ĵ���Ӧ���Ƿ��÷ɻ���
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
