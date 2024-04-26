#pragma once
#include "object.h"
/*
<Lod>
��Lod���ǡ�Level of Detail������д��<LOD> ��������Ļ�ϵ�Ͷ������
����ﵽ���ʱ�Ż���Ϊ�����ڼ��״̬��ͬʱ����ָ�������ڵ���
����͸������͸�����͵������Ӳ�͸����͸�����������ݶȴ�С����Щ������ֱ�۱�ʾ����ͼ��
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
<minLodPixels>�����裩
����Ļ���ر�ʾ�Ĳ���ֵ����ʾָ������ɼ��Է�Χ�����ޡ�
Google ������Ͷ�䵽��Ļ�ռ�ʱ���������С��Ȼ�����������������
ƽ������������˵����������������Σ��ӵ����������Ϸ���������
δ��б����ò���ֵ����Ͷ������Ŀ�ȣ�������ò���ֵ��
<minLodPixels> �� <maxLodPixels> ����������ڣ����� 
<LatLonAltBox> ����ͼ�У��������򽫻ᱻ������δ�ﵽ�����ƣ�
��صļ���ͼ�α�ᱻ��Ϊ�����û��ӵ�̫Զ�������޷����ơ�
*/
	float minLodPixels;
/*
<maxLodPixels>
����Ļ���ر�ʾ�Ĳ���ֵ����ʾָ������ɼ��Է�Χ�����ޡ�Ĭ��ֵ -1 
��ʾ��������޴󡱡�
*/
	float maxLodPixels;
/*
<minFadeExtent>
����ͼ�δ���ȫ��͸������ȫ͸������ľ��롣��һ�ݶ�ֵ����Ļ
��������ʾ��Ӧ���� LOD���ɼ��ԣ������ޡ�
*/
	float minFadeExtent;
/*
<maxFadeExtent>
����ͼ�δ���ȫ͸������ȫ��͸������ľ��롣��һ�ݶ�ֵ����Ļ
��������ʾ��Ӧ���� LOD���ɼ��ԣ������ޡ�
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
