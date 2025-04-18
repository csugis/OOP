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

class CCurve : public CGeometry  
{
	vector<PointStruct> m_vPoints;
	bool				m_bFill;
	PointStruct         m_ptInvalid; 
	friend ifstream& operator >> (ifstream&, CCurve&);
	friend ofstream& operator << (ofstream&, const CCurve&);
public:
	CCurve():m_bFill(false) {SetGeoType(geoTypePolyline);};
	virtual ~CCurve();
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//自行实现
	void Move(const PointStruct& off) {}//自行实现
	void MoveTo(const PointStruct& pt) {}//自行实现
	void GetRect(PointStruct& min, PointStruct& max) const {}//自行实现
	void Draw(CDC* pDC);
	void PutToFile(ofstream&) const;
	void GetFromFile(ifstream&);
	//属性获取函数
//	bool IsClose(void) const {//判断是否闭合
//		if(GetPointsNum()==0) return true;
//		else return m_vPoints[0]==m_vPoints[GetPointsNum()-1]?true:false;}
	bool IsFill(void) const {return /*IsClose()?*/m_bFill/*:false*/;}
	int GetPointsNum(void) const {return m_vPoints.size();}
	PointStruct& GetPoints(int index){
		if(index>=0&&index<GetPointsNum()){
			return m_vPoints[index];}
		return m_ptInvalid;}
	void GetPoints(PointStruct *pPoints) const;//数组由调用者申请
	//属性设置函数
	void Fill(void) {m_bFill=true; SetGeoType(/*(m_bFill=IsClose())?*/geoTypePolygon/*:geoTypePolyline*/);}
	void UnFill(void) {m_bFill=false; SetGeoType(geoTypePolyline);}
//	void Close(void) {if(!IsClose()){
//		PointStruct pt=m_vPoints[0];
//		InsertPoints(pt);}}
	//设置折线点坐标
	void SetCurvePoints(PointStruct* pPoints, int num);
	//修改点坐标
	void ModPoint(int index, PointStruct& pt) {}//自行实现
	//插入一个点
	void InsertPoints(PointStruct& pt) {m_vPoints.push_back(pt);}
	void InsertPoints(int index, PointStruct& pt) {}//自行实现
	//删除一个点
	void DeletePoints(int index) {}//自行实现
	//删除所有点
	void DeletePoints(void) {m_vPoints.clear();}
};

#endif // !defined(AFX_CURVE_H__3CE1957B_9BCC_4541_B93B_C81FCC60F64C__INCLUDED_)
