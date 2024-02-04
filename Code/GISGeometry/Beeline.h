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
	//拷贝构造函数
	CBeeline(const CBeeline&) {}//自行实现
	//赋值运算符重载
	CBeeline& operator= (const CBeeline&) {return *this;}//自行实现
	//##ModelId=4918445C02B2
	virtual ~CBeeline();
	//##ModelId=4918445C02B4
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//自行实现
	//##ModelId=4918445C02BF
	void Move(const PointStruct& off) {}//自行实现
	// 绕点旋转
	void Rotate(const PointStruct& pt,double angle) {}//自行实现
	// 缩放
	void Zoom(float scale) {}//自行实现
	//##ModelId=4918445C02C1
	void GetRect(PointStruct& min, PointStruct& max) const {}//自行实现
	//##ModelId=4918445C02C5
	void PutToFile(ofstream&) const {}//自行实现
	//##ModelId=4918445C02C8
	void GetFromFile(ifstream&) {}//自行实现
	// 取得面积
	double Area(void) const {return 0.0;}
	// 取得长度
	double Length(void) const {return 0.0;}//自行实现
	//属性获取函数
	//##ModelId=4918445C02CA
	void GetStartPoint(PointStruct& pt) const {pt=m_ptStart;}
	//##ModelId=4918445C02CD
	void GetEndPoint(PointStruct& pt) const {pt=m_ptEnd;}
	//属性设置函数
	//##ModelId=4918445C02D0
	void SetStartPoint(const PointStruct& pt) {m_ptStart=pt;}
	//##ModelId=4918445C02D2
	void SetEndPoint(const PointStruct& pt) {m_ptEnd=pt;}
};

#endif // !defined(AFX_BEELINE_H__93C60662_960D_433E_99E4_2623CDC6D39C__INCLUDED_)
