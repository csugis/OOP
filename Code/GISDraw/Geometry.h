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
//��ṹ
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

//ͼ��Ԫ�����Ͷ���
//1 �߶� 2 ���� 3 ����� 4 Բ�� 5 Բ 6 ���� 7ע��
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



//��ɫ�ṹ
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
//	ColorStruct m_clrInvalid;//���󷵻�ʹ��
//public:
//	CColorTable(){}
//	~CColorTable(){DeleteColors();}
//	//��ɫ�������
//	int GetColorNum(void) {return m_vClrs.size();}
//	ColorStruct& GetColor(short index){
//		if(index>=0&&index<GetColorNum()){
//			return m_vClrs[index];} 
//		return m_clrInvalid;}
//	//�޸���ɫֵ
//	void ModColor(int index, ColorStruct& clr) {}//����ʵ��
//	//����һ����ɫֵ
//	void InsertColors(ColorStruct& clr) {m_vClrs.push_back(clr);}
//	void InsertColors(int index, ColorStruct& pt) {}//����ʵ��
//	//ɾ��һ����ɫֵ
//	void DeleteColors(int index) {}//����ʵ��
//	//ɾ��������ɫֵ
//	void DeleteColors(void) {m_vClrs.clear();}
//	//���ļ��ж�ȡ��ɫ��
//	void OpenClrTable(const char* szFileName="colors.txt");
//	//������ɫ���ļ���
//	void SaveClrTable(const char* szFileName="colors.txt");
//};

class CGeometry;
ifstream& operator >> (ifstream&, CGeometry&);
ofstream& operator << (ofstream&, const CGeometry&);

class CGeometry
{
	COLORREF m_sColorPen;	//��ɫ
	COLORREF m_sColorBrush;	//���ˢ��ɫ
	short	 m_sLineWidth;	//�߿����أ�
	short	 m_sLineType;	//���ͣ����أ�
	short	 m_sLayer;		//������
	int		 m_idOnly;		//ͼ��Ԫ��Ψһ��ʶ���
	bool	 m_bDelete;				//�Ƿ���ɾ��״̬
	unsigned char m_cType;	//ͼ��Ԫ������
	bool     m_bSelected;	//ͼ���Ƿ�ѡ��
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
	//���Ի�ȡ����
	bool IsDelete(void) const {return m_bDelete;}
	COLORREF GetPenColor(void) const {return m_sColorPen;}
	COLORREF GetBrushColor(void) const {return m_sColorBrush;}
	short GetLineWidth(void) const {return m_sLineWidth;}
	short GetLineType(void) const {return m_sLineType;}
	short GetLayerIndex(void) const {return m_sLayer;}
	int GetID(void) const {return m_idOnly;}
	unsigned char GetGeoType(void) const {return m_cType;}
	bool IsSelected(void) const {return m_bSelected;}
	//�������ú���
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
