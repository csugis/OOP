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

class CArc : public CRound  
{
	float m_fStart,m_fEnd;
	friend ifstream& operator >> (ifstream&, CArc&);
	friend ofstream& operator << (ofstream&, const CArc&);
public:
	CArc() {UnFill(); SetGeoType(geoTypeArc);};
	virtual ~CArc();
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//自行实现
	void Move(const PointStruct& off) {CRound::Move(off);}
	void MoveTo(const PointStruct& pt) {}//自行实现
	void GetRect(PointStruct& min, PointStruct& max) const {}//自行实现
	void Draw(CDC* pDC);
	void PutToFile(ofstream&) const;
	void GetFromFile(ifstream&);
	//属性获取函数
	void GetRange(float& s,float& e) const {s=m_fStart; e=m_fEnd;}
	//属性设置函数
	void SetRange(float s,float e) {m_fStart=s; m_fEnd=e;}
};

#endif // !defined(AFX_ARC_H__F958FC28_79CD_4FDB_B98D_798742BB4BF3__INCLUDED_)
