#pragma once
#include "feature.h"
/*
<Container>
�﷨
<!-- abstract element; do not create -->
<!-- Container id="ID" -->              <!-- Document,Folder -->                 
  <!-- inherited from Feature element -->
  <name>...</name>                      <!-- string -->
  <visibility>1</visibility>            <!-- boolean -->
  <open>0</open>                        <!-- boolean -->
  <address>...</address>                <!-- string -->
  <AddressDetails xmlns="urn:oasis:names:tc:ciq:xsdschema:xAL:2.0">...
      </AddressDetails>                 <!-- string -->
  <phoneNumber>...</phoneNumber>        <!-- string -->
  <Snippet maxLines="2">...</Snippet>   <!-- string -->
  <description>...</description>        <!-- string -->
  <AbstractView>...</AbstractView>      <!-- LookAt or Camera -->
  <TimePrimitive>...</TimePrimitive>
  <styleUrl>...</styleUrl>              <!-- anyURI -->
  <StyleSelector>...</StyleSelector>
  <Region>...</Region>
  <Metadata>...</Metadata>
  <atom:author>...<atom:author>   <!-- xmlns:atom="http://www.w3.org/2005/Atom" -->
  <atom:link>...</atom:link>

  <!-- specific to Container --> 
  <!-- 0 or more Features --> 
<!-- /Container -->
˵��
����һ������Ԫ�أ�����ֱ������ KML �ļ��С�Container Ԫ�ذ���
һ��������ͼ�����������Ƕ�ײ�νṹ��
*/
class Container :
	public Feature
{
public:
	virtual bool IsAbstract(void) = 0;
	Container(void);
	virtual ~Container(void);
};
