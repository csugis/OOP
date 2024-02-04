#pragma once
#include "feature.h"
#include "Geometry.h"
/*
<Placemark>
�﷨
<Placemark id="ID">
  <!-- inherited from Feature element -->
  <name>...</name>                      <!-- string -->
  <visibility>1</visibility>            <!-- boolean -->
  <open>0</open>                        <!-- boolean -->
  <atom:author>...<atom:author>         <!-- xmlns:atom -->
  <atom:link>...</atom:link>            <!-- xmlns:atom -->
  <address>...</address>                <!-- string -->
  <xal:AddressDetails>...</xal:AddressDetails>  <!-- xmlns:xal -->
  <phoneNumber>...</phoneNumber>        <!-- string -->
  <Snippet maxLines="2">...</Snippet>   <!-- string -->
  <description>...</description>        <!-- string -->
  <AbstractView>...</AbstractView>      <!-- Camera or LookAt -->
  <TimePrimitive>...</TimePrimitive>
  <styleUrl>...</styleUrl>              <!-- anyURI -->
  <StyleSelector>...</StyleSelector>
  <Region>...</Region>
  <Metadata>...</Metadata>              <!-- deprecated in KML 2.2 -->
  <ExtendedData>...</ExtendedData>      <!-- new in KML 2.2 -->

  <!-- specific to Placemark element -->
  <Geometry>...</Geometry>
</Placemark>
˵��
�ر��Ǿ�����ؼ���ͼ�εĵ�ͼ��� Google �����У��ر���ʾΪ
��λ�á�����е��б����ر���й�����ͼ�꣬��ͼ�������ά
�鿴���еĵ���������ı�ǡ����� Google ������ά�鿴���У���ر�
�������Ե���������Ψһ������������ͼ�ζ�������ά�鿴����û��
ͼ�ꡣҪʹ�û�����ά�鿴�����ж�����Ե������Ҫ���� 
MultiGeometry ���󣬺��߰��������������ͼ�ζ��󡣣�
*/
class Placemark :
	public Feature
{
//�ر����е�Ԫ��
//0 ���� 1 �� <Geometry> Ԫ��
	Geometry * pGeometry;
public:
	virtual ostream& output( ostream& out);
	Geometry* getGeometry(void) {return pGeometry;}
	void setGeometry(Geometry* pGeo)
							{
								pGeometry = pGeo;
								pGeometry->setParentNode(this);
							}
	virtual bool IsAbstract(void) {return false;};
	Placemark& operator = (Placemark& mark);
	Placemark(Placemark& mark);
	Placemark(void);
	virtual ~Placemark(void);
};

ostream& operator << ( ostream& , Placemark& );