// Curve.h: interface for the CCurve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURVE_H__3CE1957B_9BCC_4541_B93B_C81FCC60F64C__INCLUDED_)
#define AFX_CURVE_H__3CE1957B_9BCC_4541_B93B_C81FCC60F64C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry.h"
#include <vector>
using namespace std;

class CCurve;
ifstream& operator >> (ifstream&, CCurve&);
ofstream& operator << (ofstream&, const CCurve&);

//##ModelId=4918445C0251
class CCurve : public CGeometry  
{
	//##ModelId=4918445C0256
	vector<PointStruct> m_vPoints;
	//##ModelId=4918445C0261
	bool				m_bFill;
	//##ModelId=4918445C02A1
	friend ifstream& operator >> (ifstream&, CCurve&);
	//##ModelId=4918445C02A5
	friend ofstream& operator << (ofstream&, const CCurve&);
public:
	//##ModelId=4918445C0262
	CCurve():m_bFill(false) {SetGeoType(geoTypePolyline);};
	//拷贝构造函数
	CCurve(const CCurve&) {}//自行实现
	//赋值运算符重载
	CCurve& operator= (const CCurve&) {return *this;}//自行实现
	//##ModelId=4918445C0263
	virtual ~CCurve();
	//##ModelId=4918445C0265
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//自行实现
	//##ModelId=4918445C0268
	void Move(const PointStruct& off) {}//自行实现
	// 绕点旋转
	void Rotate(const PointStruct& pt,double angle) {}//自行实现
	// 缩放
	void Zoom(float scale) {}//自行实现
	//##ModelId=4918445C026A
	void GetRect(PointStruct& min, PointStruct& max) const {}//自行实现
	// 取得面积
	double Area(void) const {return 0.0;}//自行实现
	// 取得长度
	double Length(void) const {return 0.0;}//自行实现
	//##ModelId=4918445C0273
	void PutToFile(ofstream&) const;
	//##ModelId=4918445C0276
	void GetFromFile(ifstream&);
	//属性获取函数
	//##ModelId=4918445C0278
	bool IsClose(void) const {//判断是否闭合
		if(GetPointsNum()==0) return true;
		else return m_vPoints[0]==m_vPoints[GetPointsNum()-1]?true:false;}
	//##ModelId=4918445C027B
	bool IsFill(void) const {return IsClose()?m_bFill:false;}
	//##ModelId=4918445C027E
	int GetPointsNum(void) const {return m_vPoints.size();}
	//##ModelId=4918445C0281
	PointStruct& GetPoints(int index) {
		if(index>=0&&index<GetPointsNum()){
			return m_vPoints[index];}}
	//下标运算符的重载
	PointStruct& operator[] ( int index)	{
		return GetPoints(index);
	}
	//##ModelId=4918445C0283
	void GetPoints(PointStruct *pPoints) const;//数组由调用者申请
	//属性设置函数
	//##ModelId=4918445C0286
	void Fill(void) {SetGeoType((m_bFill=IsClose())?geoTypePolygon:geoTypePolyline);}
	//##ModelId=4918445C0288
	void UnFill(void) {m_bFill=false; SetGeoType(geoTypePolyline);}
	//##ModelId=4918445C028A
	void Close(void) {if(!IsClose()){
		PointStruct pt=m_vPoints[0];
		InsertPoints(pt);}}
	//设置折线点坐标
	//##ModelId=4918445C028C
	void SetCurvePoints(PointStruct* pPoints, int num);
	//修改点坐标
	//##ModelId=4918445C0292
	void ModPoint(int index, PointStruct& pt) {}//自行实现
	//插入一个点
	//##ModelId=4918445C0295
	void InsertPoints(PointStruct& pt) {m_vPoints.push_back(pt);}
	//##ModelId=4918445C0297
	void InsertPoints(int index, PointStruct& pt) {}//自行实现
	//删除一个点
	//##ModelId=4918445C029A
	void DeletePoints(int index) {}//自行实现
	//删除所有点
	//##ModelId=4918445C029F
	void DeletePoints(void) {m_vPoints.clear();}
};

#endif // !defined(AFX_CURVE_H__3CE1957B_9BCC_4541_B93B_C81FCC60F64C__INCLUDED_)
