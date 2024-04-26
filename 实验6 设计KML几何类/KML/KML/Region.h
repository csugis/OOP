#pragma once
#include "object.h"
#include "LatLonAltBox.h"
#include "Lod.h"
/*
<Region>
�﷨
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
˵��
�����������Χ��(<LatLonAltBox>)���˿��������õ�������ͺ���
�߶ȶ���Ĺ�ע���򡣴��⣬Region ��������LOD����ϸ���𣩳̶ȡ�
(<Lod>)��������Ͷ�����Ļ��С��������������ȷ��Χ����Χ����
�û���Ұ�ڲ������� LOD Ҫ��ʱ������ͻ���Ϊ�����ڼ��״̬��
����������Ķ���ֻ�ڸ����򼤻�ʱ���ơ��� <viewRefreshMode> �� 
onRegion ʱ��Link �� Icon ֻ�����򼤻�ʱ���롣��μ���KML ���⡱
ҳ�й��� Regions �Ĳ��֣����˽���ϸ��Ϣ���� Container �� 
NetworkLink �Ĳ�νṹ�У��ü���ʹ�ò�νṹ����ӽ����ϼ�����
����
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
