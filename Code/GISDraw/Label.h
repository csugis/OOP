// Label.h: interface for the CLabel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LABEL_H__B3A44D96_5858_4506_B96C_D2D6EA13E969__INCLUDED_)
#define AFX_LABEL_H__B3A44D96_5858_4506_B96C_D2D6EA13E969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry.h"
#include <string>
using namespace std;

class CLabel : public CGeometry  
{
	PointStruct m_ptXY;
	float m_fLblAngle;		//��ע�Ƕ�
	float m_fChAngle;		//������ת�Ƕ�
	float m_fTextHeight;	//����߶�
	float m_fTextWidth;	//�������
	float m_fOffWidth;	//�������
	unsigned char m_cTextFont;	//����
	string m_strText;		//��ע���ı���Ϣ
public:
	CLabel() {SetGeoType(geoTypeLabel);};
	virtual ~CLabel();
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//����ʵ��
	void Move(const PointStruct& off) {}//����ʵ��
	void MoveTo(const PointStruct& pt) {}//����ʵ��
	void GetRect(PointStruct& min, PointStruct& max) const {}//����ʵ��
	void Draw(CDC* pDC) {}//����ʵ��
	void PutToFile(ofstream&) const {}//����ʵ��
	void GetFromFile(ifstream&) {}//����ʵ��
	//���Ի�ȡ����
	void GetCoord(PointStruct& pt) const {pt=m_ptXY;}
	void GetFontInfo(unsigned char& font, float& width, float& height, 
		float& off, float& angle) const{
		font=m_cTextFont; width=m_fTextWidth; height=m_fTextHeight;
		off=m_fOffWidth; angle=m_fChAngle;}
	long GetTextLength(void) const {return m_strText.length();}
	void GetLabelInfo(char* buf, long size, float& angle) const{
		for(long i=0;i<size,i<GetTextLength();i++) buf[i]=m_strText[i];
		angle=m_fLblAngle;}
	//�������ú���
	void SetCoord(const PointStruct& pt) {m_ptXY=pt;}
	void SetFontInfo(unsigned char font, float width, float height,
		float off, float angle){
		m_cTextFont=font; m_fTextWidth=width; m_fTextHeight=height;
		m_fOffWidth=off; m_fChAngle=angle;}
	void SetLabelInfo(const char* buf, float angle){
		m_strText=buf; m_fLblAngle=angle;}
};

#endif // !defined(AFX_LABEL_H__B3A44D96_5858_4506_B96C_D2D6EA13E969__INCLUDED_)