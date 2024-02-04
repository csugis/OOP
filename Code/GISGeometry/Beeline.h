// Beeline.h: interface for the CBeeline class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEELINE_H__93C60662_960D_433E_99E4_2623CDC6D39C__INCLUDED_)
#define AFX_BEELINE_H__93C60662_960D_433E_99E4_2623CDC6D39C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry.h"

//##ModelId=4918445C02AF
class CBeeline : public CGeometry  
{
	PointStruct m_ptStart,m_ptEnd;
public:
	//##ModelId=4918445C02B1
	CBeeline() {SetGeoType(geoTypeLine);};
	//�������캯��
	CBeeline(const CBeeline&) {}//����ʵ��
	//��ֵ���������
	CBeeline& operator= (const CBeeline&) {return *this;}//����ʵ��
	//##ModelId=4918445C02B2
	virtual ~CBeeline();
	//##ModelId=4918445C02B4
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//����ʵ��
	//##ModelId=4918445C02BF
	void Move(const PointStruct& off) {}//����ʵ��
	// �Ƶ���ת
	void Rotate(const PointStruct& pt,double angle) {}//����ʵ��
	// ����
	void Zoom(float scale) {}//����ʵ��
	//##ModelId=4918445C02C1
	void GetRect(PointStruct& min, PointStruct& max) const {}//����ʵ��
	//##ModelId=4918445C02C5
	void PutToFile(ofstream&) const {}//����ʵ��
	//##ModelId=4918445C02C8
	void GetFromFile(ifstream&) {}//����ʵ��
	// ȡ�����
	double Area(void) const {return 0.0;}
	// ȡ�ó���
	double Length(void) const {return 0.0;}//����ʵ��
	//���Ի�ȡ����
	//##ModelId=4918445C02CA
	void GetStartPoint(PointStruct& pt) const {pt=m_ptStart;}
	//##ModelId=4918445C02CD
	void GetEndPoint(PointStruct& pt) const {pt=m_ptEnd;}
	//�������ú���
	//##ModelId=4918445C02D0
	void SetStartPoint(const PointStruct& pt) {m_ptStart=pt;}
	//##ModelId=4918445C02D2
	void SetEndPoint(const PointStruct& pt) {m_ptEnd=pt;}
};

#endif // !defined(AFX_BEELINE_H__93C60662_960D_433E_99E4_2623CDC6D39C__INCLUDED_)
