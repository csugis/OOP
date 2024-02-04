// Geometry.h: interface for the CGeometry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOMETRY_H__9CA85D2A_AD9C_400B_A1F8_CB3E8A313D0E__INCLUDED_)
#define AFX_GEOMETRY_H__9CA85D2A_AD9C_400B_A1F8_CB3E8A313D0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <fstream>
#include <vector>
using namespace std;
//点结构
typedef struct POINTSTRU
{
	float x;
	float y;
//	float z;
	POINTSTRU& operator = (const CPoint&pt)
	{
		x=pt.x;
		y=pt.y;
		return *this;
	}
}PointStruct;

bool operator == (const PointStruct&, const PointStruct&);
bool operator > (const PointStruct&, const PointStruct&);
bool operator < (const PointStruct&, const PointStruct&);

//图形元素类型定义
//1 线段 2 折线 3 多边形 4 圆周 5 圆 6 弧段 7注记
enum enumGeometryType{
	geoTypeUndefined = 0,
	geoTypeLine = 1,
	geoTypePolyline = 2,
	geoTypePolygon = 3,
	geoTypeCircle = 4,
	geoTypeRound = 5,
	geoTypeArc = 6,
	geoTypeLabel = 7
};



//颜色结构
//typedef struct COLORSTRU
//{
//	int r;
//	int g;
//	int b;
//	COLORSTRU& operator = (const COLORREF& clr)
//	{
//		r=GetRValue(clr);
//		g=GetGValue(clr);
//		b=GetGValue(clr);
//		return *this;
//	}
//}ColorStruct;

//ifstream& operator >> (ifstream&, ColorStruct&);
//ofstream& operator << (ofstream&, const ColorStruct&);

//class CColorTable{
//	vector<ColorStruct> m_vClrs;
//	ColorStruct m_clrInvalid;//错误返回使用
//public:
//	CColorTable(){}
//	~CColorTable(){DeleteColors();}
//	//颜色表管理函数
//	int GetColorNum(void) {return m_vClrs.size();}
//	ColorStruct& GetColor(short index){
//		if(index>=0&&index<GetColorNum()){
//			return m_vClrs[index];} 
//		return m_clrInvalid;}
//	//修改颜色值
//	void ModColor(int index, ColorStruct& clr) {}//自行实现
//	//插入一个颜色值
//	void InsertColors(ColorStruct& clr) {m_vClrs.push_back(clr);}
//	void InsertColors(int index, ColorStruct& pt) {}//自行实现
//	//删除一个颜色值
//	void DeleteColors(int index) {}//自行实现
//	//删除所有颜色值
//	void DeleteColors(void) {m_vClrs.clear();}
//	//从文件中读取颜色表
//	void OpenClrTable(const char* szFileName="colors.txt");
//	//保存颜色表到文件中
//	void SaveClrTable(const char* szFileName="colors.txt");
//};

class CGeometry;
ifstream& operator >> (ifstream&, CGeometry&);
ofstream& operator << (ofstream&, const CGeometry&);

class CGeometry
{
	COLORREF m_sColorPen;	//笔色
	COLORREF m_sColorBrush;	//填充刷颜色
	short	 m_sLineWidth;	//线宽（像素）
	short	 m_sLineType;	//线型（像素）
	short	 m_sLayer;		//所处层
	int		 m_idOnly;		//图形元素唯一的识别号
	bool	 m_bDelete;				//是否处于删除状态
	unsigned char m_cType;	//图形元素类型
	bool     m_bSelected;	//图形是否被选中
	friend ifstream& operator >> (ifstream&, CGeometry&);
	friend ofstream& operator << (ofstream&, const CGeometry&);
	friend class CLayer;
	void SetID(int id) {m_idOnly=id;}
protected:
	void SetGeoType(unsigned char type) {m_cType=type;}
public:
	CGeometry():m_sColorPen(1),m_sColorBrush(1),m_sLineWidth(1),m_sLineType(1),
		m_sLayer(-1),m_idOnly(-1),m_bDelete(false),m_cType(geoTypeUndefined),
		m_bSelected(false) {}
	virtual ~CGeometry();
	virtual double DistanceToPoint(const PointStruct&) const = 0;
	virtual void Move(const PointStruct& off) = 0;
	virtual void MoveTo(const PointStruct& pt) = 0;
	virtual void GetRect(PointStruct& min, PointStruct& max) const = 0;
	virtual void Draw(CDC* pDC);
	virtual void PutToFile(ofstream& outfile) const {outfile<<(*this);}
	virtual void GetFromFile(ifstream& infile) {infile>>(*this);}
	//属性获取函数
	bool IsDelete(void) const {return m_bDelete;}
	COLORREF GetPenColor(void) const {return m_sColorPen;}
	COLORREF GetBrushColor(void) const {return m_sColorBrush;}
	short GetLineWidth(void) const {return m_sLineWidth;}
	short GetLineType(void) const {return m_sLineType;}
	short GetLayerIndex(void) const {return m_sLayer;}
	int GetID(void) const {return m_idOnly;}
	unsigned char GetGeoType(void) const {return m_cType;}
	bool IsSelected(void) const {return m_bSelected;}
	//属性设置函数
	void Delete(void) {m_bDelete=true;}
	void UnDelete(void) {m_bDelete=false;}
	void SetPenColor(COLORREF clr) {m_sColorPen=clr;}
	void SetBrushColor(COLORREF clr) {m_sColorBrush=clr;}
	void SetLineWidth(short width) {m_sLineWidth=width;}
	void SetLineType(short type) {m_sLineType=type;}
	void SetLayerIndex(short index) {m_sLayer=index;}
	void UnSelect(void) {m_bSelected=false;}
	void Select() {m_bSelected=true;}
};


#endif // !defined(AFX_GEOMETRY_H__9CA85D2A_AD9C_400B_A1F8_CB3E8A313D0E__INCLUDED_)
