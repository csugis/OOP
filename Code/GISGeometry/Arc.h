// Arc.h: interface for the CArc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARC_H__F958FC28_79CD_4FDB_B98D_798742BB4BF3__INCLUDED_)
#define AFX_ARC_H__F958FC28_79CD_4FDB_B98D_798742BB4BF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Round.h"
class CArc;
ifstream& operator >> (ifstream&, CArc&);
ofstream& operator << (ofstream&, const CArc&);

//##ModelId=4918445C02D4
class CArc : public CRound  
{
	float m_fStart,m_fEnd;
	//##ModelId=4918445C02FA
	friend ifstream& operator >> (ifstream&, CArc&);
	//##ModelId=4918445C02FF
	friend ofstream& operator << (ofstream&, const CArc&);
public:
	//##ModelId=4918445C02DF
	CArc() {UnFill(); SetGeoType(geoTypeArc);}
	//�������캯��
	CArc(const CArc&) {}//����ʵ��
	//��ֵ���������
	CArc& operator= (const CArc&) {return *this;}//����ʵ��
	//##ModelId=4918445C02E0
	virtual ~CArc();
	//##ModelId=4918445C02E2
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//����ʵ��
	//##ModelId=4918445C02E5
	void Move(const PointStruct& off) {CRound::Move(off);}
	// �Ƶ���ת
	void Rotate(const PointStruct& pt,double angle) {}//����ʵ��
	// ����
	void Zoom(float scale) {}//����ʵ��
	//##ModelId=4918445C02E7
	void GetRect(PointStruct& min, PointStruct& max) const {}//����ʵ��
	// ȡ�����
	double Area(void) const {return 0.0;}
	// ȡ�ó���
	double Length(void) const {return 0.0;}//����ʵ��
	//##ModelId=4918445C02EE
	void PutToFile(ofstream&) const;
	//##ModelId=4918445C02F1
	void GetFromFile(ifstream&);
	//���Ի�ȡ����
	//##ModelId=4918445C02F3
	void GetRange(float& s,float& e) const {s=m_fStart; e=m_fEnd;}
	//�������ú���
	//##ModelId=4918445C02F7
	void SetRange(float s,float e) {m_fStart=s; m_fEnd=e;}
};

#endif // !defined(AFX_ARC_H__F958FC28_79CD_4FDB_B98D_798742BB4BF3__INCLUDED_)
