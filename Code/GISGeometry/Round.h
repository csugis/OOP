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

//##ModelId=4918445B02F1
class CRound : public CGeometry  
{
	//##ModelId=4918445B037B
	PointStruct m_ptXY;
	//##ModelId=4918445B038C
	float m_fRadius;
	//##ModelId=4918445C0000
	bool m_bFill;
	//##ModelId=4918445C0061
	friend ifstream& operator >> (ifstream&, CRound&);
	//##ModelId=4918445C006F
	friend ofstream& operator << (ofstream&, const CRound&);
public:
	//##ModelId=4918445C0001
	CRound():m_bFill(false) {SetGeoType(geoTypeCircle);};
	//拷贝构造函数
	CRound(const CRound&) {}//自行实现
	//赋值运算符重载
	CRound& operator= (const CRound&) {return *this;}//自行实现
	//##ModelId=4918445C0002
	virtual ~CRound();
	//##ModelId=4918445C000F
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//自行实现
	//##ModelId=4918445C0012
	void Move(const PointStruct& off) {}//自行实现
	// 绕点旋转
	void Rotate(const PointStruct& pt,double angle) {}//自行实现
	// 缩放
	void Zoom(float scale) {}//自行实现
	//##ModelId=4918445C001F
	void GetRect(PointStruct& min, PointStruct& max) const {}//自行实现
	// 取得面积
	double Area(void) const {
		if(IsFill())	return PI*m_fRadius*m_fRadius;
		else	return 0.0;}
	// 取得长度
	double Length(void) const {return 2*PI*m_fRadius;}
	//##ModelId=4918445C0023
	void PutToFile(ofstream&) const;
	//##ModelId=4918445C002F
	void GetFromFile(ifstream&);
	//属性获取函数
	//##ModelId=4918445C0031
	void GetCenter(PointStruct& pt) const {pt=m_ptXY;}
	//##ModelId=4918445C003E
	float GetRadius(void) const {return m_fRadius;}
	//##ModelId=4918445C0041
	bool IsFill(void) const {return m_bFill;}
	//属性设置函数
	//##ModelId=4918445C004E
	void SetCenter(const PointStruct& pt) {m_ptXY=pt;}
	//##ModelId=4918445C0050
	void SetRadius(float r) {m_fRadius=r;}
	//##ModelId=4918445C005D
	void Fill(void) {m_bFill=true; SetGeoType(geoTypeRound);}
	//##ModelId=4918445C005F
	void UnFill(void) {m_bFill=false; SetGeoType(geoTypeCircle);}
};

#endif // !defined(AFX_ROUND_H__A68A459B_C95C_4916_8338_9DC30220FC9E__INCLUDED_)
