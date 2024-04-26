#pragma once
#include <string>
using namespace std;

#include "object.h"
/*
<Feature>
�﷨
<!-- abstract element; do not create -->
<!-- Feature id="ID" -->                <!-- Document,Folder,
                                             NetworkLink,Placemark,
                                             GroundOverlay,PhotoOverlay,ScreenOverlay -->
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
  <TimePrimitive>...</TimePrimitive>    <!-- TimeStamp or TimeSpan -->
  <styleUrl>...</styleUrl>              <!-- anyURI -->
  <StyleSelector>...</StyleSelector>
  <Region>...</Region>
  <Metadata>...</Metadata>              <!-- deprecated in KML 2.2 -->
  <ExtendedData>...</ExtendedData>      <!-- new in KML 2.2 -->
<-- /Feature -->
˵��
����һ������Ԫ�أ�����ֱ������ KML �ļ��С�
*/
class Feature :
	public Object
{
/*
<name>
����ά�鿴������ʾΪ����ı�ǩ���û�������ı�
�����磬���� Placemark��Folder �� NetworkLink ���ı�����
*/
	string name;
/*
<visibility>
����ֵ��ָ���ڵ�һ�������ͼ��ʱ�Ƿ�����ά�鿴���л��Ƹõ�ͼ�
Ҫ�õ�ͼ��ɼ����õ�ͼ������и���� <visibility> ��ǩҲ������
����Ϊ 1���� Google �����б���ͼ�У�ÿ����ͼ���һ����ѡ��
ʹ�û����Կ��Ƶ�ͼ��Ŀɼ��ԡ�
*/
	bool visibility;
/*
<open>
����ֵ��ָ����һ�����롰λ�á����ʱ��Document �� Folder ����ʾ
״̬�ǹرջ��Ǵ򿪡�0=��£��Ĭ�ϣ���1=չ��������μ� 
<ListStyle>����Ԫ��ֻ������ Document��Folder �� NetworkLink��
*/
	bool open;
/*
<description>
˵�����ݿ�����ʾ���û��ṩ���ı���
֧������ <description> Ԫ�ص����ݴ� Google ���� 4.3 ����Ϊ 5.0��
�����г���ÿ���汾���е���Ϣ���Լ������汾��ͨ����Ϣ��
Google ���� 5.0
Google ���� 5.0 ֧�ִ��ı����ݣ��Լ�˵�����ݿ��������� HTML ��
JavaScript��˵����ǩ�������� WebKit ��Դ���������������֣�
�����������κλ��� WebKit ���������һ����ʾ��
��������
ͨ�������������ļ������ӡ�����Է�ֹ�������������ϵͳ��
�����������ݡ������ϣ������������ص��ļ�ϵͳ���з��ʣ���ѡ��
ʹ��ƫ�� > ����ر����ݿ���ʱ����ļ��͸������ݡ�ͨ����������
�ļ�ϵͳ��ͼƬ�ļ������ӣ���������� <img> ��ǩ�У���
��ʹ���ڱ����ļ�ϵͳ�ϣ�Ҳ���Է���ѹ��Ϊ KMZ �ļ������ݡ�
��ȫ���� Cookie�������� iFrame �����������ݽ������û��ȡ�� 
Cookie�����ù���û���κ����������
���� Doctype ������
HTML
HTML ͨ���������κ� WebKit �������һ�����֡�
��Ŀ�������ֱ��д�� KML �� HTML ��ʱ�����Ժ��ԣ����д�������
����򿪣�����Ŀ������Ϊ _blank һ������������ָ����Ŀ�ꡣ
���ǣ������� iFrame �е� HTML������ͨ�� JavaScript �� DHTML 
��̬���ɵ� HTML����ʹ�� target=��_self����ΪĬ��ֵ������ָ����
֧������Ŀ�ꡣ
���ܴ� iFrame �а����� HTML ��λ�� KMZ �ļ������ݡ�����ê������
�� ;flyto ������
*/
	string description;
/*
<styleUrl>
Document �ж���� <Style> �� <StyleMap> ����ַ���������ʽ��
ͬһ���ļ��У���ʹ�� # ���á��������ʽ���ⲿ�ļ��ж��壬��ʹ��
�� # ���õ�������ַ��ʾ������
<styleUrl>#myIconStyleID</styleUrl>
<styleUrl>http://someserver.com/somestylefile.xml#restaurant</styleUrl>
<styleUrl>eateries.kml#my-lunch-spot</styleUrl>
*/
	string styleUrl;
//<Region>
//�� Region �����ĵ�ͼ��ͼ���ͼ��ֻ�ڸ����򼤻�ʱ���ơ���μ� <Region>��
	//Region region;
public:
	//Region& getRegion(void) {return region;}
	//void setRegion(Region& r) {region = r;}
	string& getStyleUrl(void) {return styleUrl;}
	void setStyleUrl(string& style) {styleUrl = style;}
	string& getName(void) {return name;}
	string& getDescription(void) {return description;}
	bool IsVisible(void) {return visibility;}
	bool IsOpen(void) {return open;}
	void setName(string& na) {name = na;} 
	void setDescrription(string& des){description = des;}
	void setVisibility(bool vis = true) {visibility = vis;}
	void setOpen(bool op = true) {open = op;}
	virtual bool IsAbstract(void) = 0;
	Feature(void);
	virtual ~Feature(void);
};
