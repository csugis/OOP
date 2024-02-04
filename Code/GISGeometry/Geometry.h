// Geometry.h: interface for the CGeometry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOMETRY_H__9CA85D2A_AD9C_400B_A1F8_CB3E8A313D0E__INCLUDED_)
#define AFX_GEOMETRY_H__9CA85D2A_AD9C_400B_A1F8_CB3E8A313D0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <fstream>
using namespace std;
//点结构
//##ModelId=4918445C01AD
typedef struct tagPoint
{
	tagPoint(float fX=0.0f,float fY=0.0f){
		x=fX;	y=fY;
	}
	float x;
	float y;
//	float z;
}PointStruct;

//图形元素类型定义
//1 线段 2 折线 3 多边形 4 圆周 5 圆 6 弧段 7注记
//##ModelId=4918445C01B6
enum enumGeometryType{
	//##ModelId=4918445C01B8
	geoTypeUndefined = 0,
	//##ModelId=4918445C01B9
	geoTypeLine = 1,
	//##ModelId=4918445C01C5
	geoTypePolyline = 2,
	//##ModelId=4918445C01C6
	geoTypePolygon = 3,
	//##ModelId=4918445C01C7
	geoTypeCircle = 4,
	//##ModelId=4918445C01C8
	geoTypeRound = 5,
	//##ModelId=4918445C01C9
	geoTypeArc = 6,
	//##ModelId=4918445C01CA
	geoTypeLabel = 7
};

bool operator == (const PointStruct&, const PointStruct&);

class CGeometry;
ifstream& operator >> (ifstream&, CGeometry&);
ofstream& operator << (ofstream&, const CGeometry&);

const double PI=3.1415926;
const float  step=10.0;

//##ModelId=4918445C01D4
class CGeometry  
{
	//##ModelId=4918445C01E4
	short	m_sColorPen;	//笔色
	//##ModelId=4918445C01E5
	short	m_sColorBrush;	//填充刷颜色
	//##ModelId=4918445C01E6
	short	m_sLineWidth;	//线宽（像素）
	//##ModelId=4918445C01E7
	short	m_sLineType;	//线型（像素）
	//##ModelId=4918445C01F4
	short	m_sLayer;		//所处层
	//##ModelId=4918445C01F5
	int		m_idOnly;		//图形元素唯一的识别号
	//##ModelId=4918445C01F6
	bool	m_bDelete;				//是否处于删除状态
	//##ModelId=4918445C01F7
	unsigned char m_cType;	//图形元素类型
	//##ModelId=4918445C0240
	friend ifstream& operator >> (ifstream&, CGeometry&);
	//##ModelId=4918445C0244
	friend ofstream& operator << (ofstream&, const CGeometry&);
protected:
	//##ModelId=4918445C0203
	void SetGeoType(unsigned char type) {m_cType=type;}
public:
	//##ModelId=4918445C0205
	CGeometry():m_sColorPen(1),m_sColorBrush(1),m_sLineWidth(1),m_sLineType(1),
		m_sLayer(-1),m_idOnly(-1),m_bDelete(false),m_cType(geoTypeUndefined) {}
	//拷贝构造函数
	CGeometry(const CGeometry&) {}//自行实现
	//赋值运算符重载
	CGeometry& operator= (const CGeometry&) {return *this;}//自行实现
	//##ModelId=4918445C0206
	virtual ~CGeometry();
	//##ModelId=4918445C0208
	virtual double DistanceToPoint(const PointStruct&) const = 0;
	// 平移
	virtual void Move(const PointStruct& off) = 0;
	// 绕点旋转
	virtual void Rotate(const PointStruct& pt,double angle) = 0;
	// 缩放
	virtual void Zoom(float scale) = 0;
	//##ModelId=4918445C020E
	virtual void GetRect(PointStruct& min, PointStruct& max) const = 0;
	// 取得面积
	virtual double Area(void) const = 0;
	// 取得长度
	virtual double Length(void) const = 0;
	CGeometry& operator++( )	{//重载运算符++
		Move(PointStruct(step,step));
		return *this;
	}
	CGeometry& operator--( )	{//重载运算符--
		Move(PointStruct(-step,-step));
		return *this;
	}
    CGeometry& operator + (PointStruct pt){ //重载运算符+
		Move(pt);
		return *this;
	}
    CGeometry& operator - (PointStruct pt){//重载运算符-
		Move(PointStruct(-pt.x,-pt.y));
		return *this;
	}
	//##ModelId=4918445C0212
	virtual void PutToFile(ofstream& outfile) const {outfile<<(*this);}
	//##ModelId=4918445C0215
	virtual void GetFromFile(ifstream& infile) {infile>>(*this);}
	//属性获取函数
	//##ModelId=4918445C0218
	bool IsDelete(void) const {return m_bDelete;}
	//##ModelId=4918445C021B
	short GetPenColor(void) const {return m_sColorPen;}
	//##ModelId=4918445C021E
	short GetBrushColor(void) const {return m_sColorBrush;}
	//##ModelId=4918445C0221
	short GetLineWidth(void) const {return m_sLineWidth;}
	//##ModelId=4918445C0224
	short GetLineType(void) const {return m_sLineType;}
	//##ModelId=4918445C0227
	short GetLayerIndex(void) const {return m_sLayer;}
	//##ModelId=4918445C022A
	int GetID(void) const {return m_idOnly;}
	//##ModelId=4918445C022D
	unsigned char GetGeoType(void) const {return m_cType;}
	//属性设置函数
	//##ModelId=4918445C0230
	void Delete(void) {m_bDelete=true;}
	//##ModelId=4918445C0232
	void UnDelete(void) {m_bDelete=false;}
	//##ModelId=4918445C0234
	void SetPenColor(short clr) {m_sColorPen=clr;}
	//##ModelId=4918445C0236
	void SetBrushColor(short clr) {m_sColorBrush=clr;}
	//##ModelId=4918445C0238
	void SetLineWidth(short width) {m_sLineWidth=width;}
	//##ModelId=4918445C023A
	void SetLineType(short type) {m_sLineType=type;}
	//##ModelId=4918445C023C
	void SetLayerIndex(short index) {m_sLayer=index;}
	//##ModelId=4918445C023E
	void SetID(int id) {m_idOnly=id;}
};


#endif // !defined(AFX_GEOMETRY_H__9CA85D2A_AD9C_400B_A1F8_CB3E8A313D0E__INCLUDED_)
