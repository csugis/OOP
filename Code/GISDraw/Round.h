// Round.h: interface for the CRound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROUND_H__A68A459B_C95C_4916_8338_9DC30220FC9E__INCLUDED_)
#define AFX_ROUND_H__A68A459B_C95C_4916_8338_9DC30220FC9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry.h"

class CRound;
ifstream& operator >> (ifstream&, CRound&);
ofstream& operator << (ofstream&, const CRound&);

class CRound : public CGeometry  
{
	PointStruct m_ptXY;
	float m_fRadius;
	bool m_bFill;
	friend ifstream& operator >> (ifstream&, CRound&);
	friend ofstream& operator << (ofstream&, const CRound&);
public:
	CRound():m_bFill(false) {SetGeoType(geoTypeCircle);};
	virtual ~CRound();
	double DistanceToPoint(const PointStruct& pt) const;//自行实现
	void Move(const PointStruct& off);
	void MoveTo(const PointStruct& pt);
	void GetRect(PointStruct& min, PointStruct& max) const;
	void Draw(CDC* pDC);
	void PutToFile(ofstream&) const;
	void GetFromFile(ifstream&);
	//属性获取函数
	void GetCenter(PointStruct& pt) const {pt=m_ptXY;}
	float GetRadius(void) const {return m_fRadius;}
	bool IsFill(void) const {return m_bFill;}
	//属性设置函数
	void SetCenter(const PointStruct& pt) {m_ptXY=pt;}
	void SetRadius(float r) {m_fRadius=r;}
	void Fill(void) {m_bFill=true; SetGeoType(geoTypeRound);}
	void UnFill(void) {m_bFill=false; SetGeoType(geoTypeCircle);}
};

#endif // !defined(AFX_ROUND_H__A68A459B_C95C_4916_8338_9DC30220FC9E__INCLUDED_)
