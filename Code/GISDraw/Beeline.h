// Beeline.h: interface for the CBeeline class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEELINE_H__93C60662_960D_433E_99E4_2623CDC6D39C__INCLUDED_)
#define AFX_BEELINE_H__93C60662_960D_433E_99E4_2623CDC6D39C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry.h"

class CBeeline : public CGeometry  
{
	PointStruct m_ptStart,m_ptEnd;
public:
	CBeeline() {SetGeoType(geoTypeLine);};
	virtual ~CBeeline();
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//自行实现
	void Move(const PointStruct& off) {}//自行实现
	void MoveTo(const PointStruct& pt) {}//自行实现
	void GetRect(PointStruct& min, PointStruct& max) const {}//自行实现
	void Draw(CDC* pDC) {}//自行实现
	void PutToFile(ofstream&) const {}//自行实现
	void GetFromFile(ifstream&) {}//自行实现
	//属性获取函数
	void GetStartPoint(PointStruct& pt) const {pt=m_ptStart;}
	void GetEndPoint(PointStruct& pt) const {pt=m_ptEnd;}
	//属性设置函数
	void SetStartPoint(const PointStruct& pt) {m_ptStart=pt;}
	void SetEndPoint(const PointStruct& pt) {m_ptEnd=pt;}
};

#endif // !defined(AFX_BEELINE_H__93C60662_960D_433E_99E4_2623CDC6D39C__INCLUDED_)
