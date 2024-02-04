// Label.h: interface for the CLabel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LABEL_H__B3A44D96_5858_4506_B96C_D2D6EA13E969__INCLUDED_)
#define AFX_LABEL_H__B3A44D96_5858_4506_B96C_D2D6EA13E969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry.h"
#include <string>
using namespace std;

//##ModelId=4918445C014C
class CLabel : public CGeometry  
{
	//##ModelId=4918445C0159
	PointStruct m_ptXY;
	//##ModelId=4918445C015D
	float m_fLblAngle;		//标注角度
	//##ModelId=4918445C015E
	float m_fChAngle;		//字体旋转角度
	//##ModelId=4918445C0167
	float m_fTextHeight;	//字体高度
	//##ModelId=4918445C0168
	float m_fTextWidth;	//字体宽度
	//##ModelId=4918445C0169
	float m_fOffWidth;	//间隔宽度
	//##ModelId=4918445C016A
	unsigned char m_cTextFont;	//字体
	//##ModelId=4918445C0178
	string m_strText;		//标注的文本信息
public:
	//##ModelId=4918445C017C
	CLabel() {SetGeoType(geoTypeLabel);};
	//拷贝构造函数
	CLabel(const CLabel&) {}//自行实现
	//赋值运算符重载
	CLabel& operator= (const CLabel&) {return *this;}//自行实现
	//##ModelId=4918445C017D
	virtual ~CLabel();
	//##ModelId=4918445C017F
	double DistanceToPoint(const PointStruct& pt) const {return 0.0;}//自行实现
	//##ModelId=4918445C0182
	void Move(const PointStruct& off) {}//自行实现
	// 绕点旋转
	void Rotate(const PointStruct& pt,double angle) {}//自行实现
	// 缩放
	void Zoom(float scale) {}//自行实现
	//##ModelId=4918445C0184
	void GetRect(PointStruct& min, PointStruct& max) const {}//自行实现
	// 取得面积
	double Area(void) const {return 0.0;}
	// 取得长度
	double Length(void) const {return 0.0;}
	//##ModelId=4918445C0188
	void PutToFile(ofstream&) const {}//自行实现
	//##ModelId=4918445C018B
	void GetFromFile(ifstream&) {}//自行实现
	//属性获取函数
	//##ModelId=4918445C018D
	void GetCoord(PointStruct& pt) const {pt=m_ptXY;}
	//##ModelId=4918445C0190
	void GetFontInfo(unsigned char& font, float& width, float& height, 
		float& off, float& angle) const{
		font=m_cTextFont; width=m_fTextWidth; height=m_fTextHeight;
		off=m_fOffWidth; angle=m_fChAngle;}
	//##ModelId=4918445C0198
	long GetTextLength(void) const {return m_strText.length();}
	//##ModelId=4918445C019B
	void GetLabelInfo(char* buf, long size, float& angle) const{
		for(long i=0;i<size,i<GetTextLength();i++) buf[i]=m_strText[i];
		angle=m_fLblAngle;}
	//属性设置函数
	//##ModelId=4918445C01A0
	void SetCoord(const PointStruct& pt) {m_ptXY=pt;}
	//##ModelId=4918445C01A2
	void SetFontInfo(unsigned char font, float width, float height,
		float off, float angle){
		m_cTextFont=font; m_fTextWidth=width; m_fTextHeight=height;
		m_fOffWidth=off; m_fChAngle=angle;}
	//##ModelId=4918445C01AA
	void SetLabelInfo(const char* buf, float angle){
		m_strText=buf; m_fLblAngle=angle;}
};

#endif // !defined(AFX_LABEL_H__B3A44D96_5858_4506_B96C_D2D6EA13E969__INCLUDED_)
