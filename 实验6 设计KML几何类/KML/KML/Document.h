#pragma once
#include "container.h"
#include "Placemark.h"
#include "tArray.h"
/*
<Document>
�﷨
<Document id="ID">
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

  <!-- specific to Document -->
  <!-- 0 or more Schema elements -->
  <!-- 0 or more Feature elements -->
</Document>
˵��
Document ����������ʽ��������������� KML �ļ�ʹ�á�������ʽ����
����Ҫ��Ԫ�ء�������ʹ�ù�����ʽ������Ҫ��ѭ���²��裺
�� Document �ж���������ʽ��Ϊÿ����ʽָ��Ψһ�� ID��
��ָ���ĵ�ͼ��� StyleMap �У��� <styleUrl> Ԫ��������ʽ ID��
��ע�⣬������ʽ������ Document �еĵ�ͼ�����̳С�
*/
class Document :
	public Container
{
	tArray<Placemark> marks;
public:
	tArray<Placemark>& getPlacemarks(void) {return marks;}
	void setPlacemarks(tArray<Placemark>& pms)
	{
		marks = pms;
		for(int i=0; i< marks.getSize(); i++)
		{
			marks[i].setParentNode(this);
		}
	}
	virtual bool IsAbstract(void) {return false;};
	Document(void);
	virtual ~Document(void);
};

ostream& operator << ( ostream& , Document& );