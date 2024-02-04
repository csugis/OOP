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
	//�������캯��
	CCurve(const CCurve&) {}//����ʵ��
	//��ֵ���������
	CCurve& operator= (const CCurve&) {return *this;}//����ʵ��
	//##ModelId=4918445C0263
	virtual ~CCurve();
	//##ModelId=4918445C0265
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//����ʵ��
	//##ModelId=4918445C0268
	void Move(const PointStruct& off) {}//����ʵ��
	// �Ƶ���ת
	void Rotate(const PointStruct& pt,double angle) {}//����ʵ��
	// ����
	void Zoom(float scale) {}//����ʵ��
	//##ModelId=4918445C026A
	void GetRect(PointStruct& min, PointStruct& max) const {}//����ʵ��
	// ȡ�����
	double Area(void) const {return 0.0;}//����ʵ��
	// ȡ�ó���
	double Length(void) const {return 0.0;}//����ʵ��
	//##ModelId=4918445C0273
	void PutToFile(ofstream&) const;
	//##ModelId=4918445C0276
	void GetFromFile(ifstream&);
	//���Ի�ȡ����
	//##ModelId=4918445C0278
	bool IsClose(void) const {//�ж��Ƿ�պ�
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
	//�±������������
	PointStruct& operator[] ( int index)	{
		return GetPoints(index);
	}
	//##ModelId=4918445C0283
	void GetPoints(PointStruct *pPoints) const;//�����ɵ���������
	//�������ú���
	//##ModelId=4918445C0286
	void Fill(void) {SetGeoType((m_bFill=IsClose())?geoTypePolygon:geoTypePolyline);}
	//##ModelId=4918445C0288
	void UnFill(void) {m_bFill=false; SetGeoType(geoTypePolyline);}
	//##ModelId=4918445C028A
	void Close(void) {if(!IsClose()){
		PointStruct pt=m_vPoints[0];
		InsertPoints(pt);}}
	//�������ߵ�����
	//##ModelId=4918445C028C
	void SetCurvePoints(PointStruct* pPoints, int num);
	//�޸ĵ�����
	//##ModelId=4918445C0292
	void ModPoint(int index, PointStruct& pt) {}//����ʵ��
	//����һ����
	//##ModelId=4918445C0295
	void InsertPoints(PointStruct& pt) {m_vPoints.push_back(pt);}
	//##ModelId=4918445C0297
	void InsertPoints(int index, PointStruct& pt) {}//����ʵ��
	//ɾ��һ����
	//##ModelId=4918445C029A
	void DeletePoints(int index) {}//����ʵ��
	//ɾ�����е�
	//##ModelId=4918445C029F
	void DeletePoints(void) {m_vPoints.clear();}
};

#endif // !defined(AFX_CURVE_H__3CE1957B_9BCC_4541_B93B_C81FCC60F64C__INCLUDED_)
