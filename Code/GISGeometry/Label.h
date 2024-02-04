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

//##ModelId=4918445C014C
class CLabel : public CGeometry  
{
	//##ModelId=4918445C0159
	PointStruct m_ptXY;
	//##ModelId=4918445C015D
	float m_fLblAngle;		//��ע�Ƕ�
	//##ModelId=4918445C015E
	float m_fChAngle;		//������ת�Ƕ�
	//##ModelId=4918445C0167
	float m_fTextHeight;	//����߶�
	//##ModelId=4918445C0168
	float m_fTextWidth;	//������
	//##ModelId=4918445C0169
	float m_fOffWidth;	//������
	//##ModelId=4918445C016A
	unsigned char m_cTextFont;	//����
	//##ModelId=4918445C0178
	string m_strText;		//��ע���ı���Ϣ
public:
	//##ModelId=4918445C017C
	CLabel() {SetGeoType(geoTypeLabel);};
	//�������캯��
	CLabel(const CLabel&) {}//����ʵ��
	//��ֵ���������
	CLabel& operator= (const CLabel&) {return *this;}//����ʵ��
	//##ModelId=4918445C017D
	virtual ~CLabel();
	//##ModelId=4918445C017F
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//����ʵ��
	//##ModelId=4918445C0182
	void Move(const PointStruct& off) {}//����ʵ��
	// �Ƶ���ת
	void Rotate(const PointStruct& pt,double angle) {}//����ʵ��
	// ����
	void Zoom(float scale) {}//����ʵ��
	//##ModelId=4918445C0184
	void GetRect(PointStruct& min, PointStruct& max) const {}//����ʵ��
	// ȡ�����
	double Area(void) const {return 0.0;}
	// ȡ�ó���
	double Length(void) const {return 0.0;}
	//##ModelId=4918445C0188
	void PutToFile(ofstream&) const {}//����ʵ��
	//##ModelId=4918445C018B
	void GetFromFile(ifstream&) {}//����ʵ��
	//���Ի�ȡ����
	//##ModelId=4918445C018D
	void GetCoord(PointStruct& pt) const {pt=m_ptXY;}
	//##ModelId=4918445C0190
	void GetFontInfo(unsigned char& font, float& width, float& height, 
		float& off, float& angle) const{
		font=m_cTextFont; width=m_fTextWidth; height=m_fTextHeight;
		off=m_fOffWidth; angle=m_fChAngle;}
	//##ModelId=4918445C0198
	long GetTextLength(void) const {return m_strText.length();}
	//##ModelId=4918445C019B
	void GetLabelInfo(char* buf, long size, float& angle) const{
		for(long i=0;i<size,i<GetTextLength();i++) buf[i]=m_strText[i];
		angle=m_fLblAngle;}
	//�������ú���
	//##ModelId=4918445C01A0
	void SetCoord(const PointStruct& pt) {m_ptXY=pt;}
	//##ModelId=4918445C01A2
	void SetFontInfo(unsigned char font, float width, float height,
		float off, float angle){
		m_cTextFont=font; m_fTextWidth=width; m_fTextHeight=height;
		m_fOffWidth=off; m_fChAngle=angle;}
	//##ModelId=4918445C01AA
	void SetLabelInfo(const char* buf, float angle){
		m_strText=buf; m_fLblAngle=angle;}
};

#endif // !defined(AFX_LABEL_H__B3A44D96_5858_4506_B96C_D2D6EA13E969__INCLUDED_)
