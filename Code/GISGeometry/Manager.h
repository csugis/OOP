// Manager.h: interface for the CManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGER_H__36E48F48_477D_4B72_9B2C_FABEC5EC6096__INCLUDED_)
#define AFX_MANAGER_H__36E48F48_477D_4B72_9B2C_FABEC5EC6096__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

//颜色结构
typedef struct tagClr
{
//	tagClr(int nR=0,int nG=0,int nB=0){
//		r = nR;	g = nG;	b = nB;
//	}
	int r;
	int g;
	int b;
}ColorStruct;

void writeclr(ofstream &outfile, const ColorStruct* pClrs,long num);
void writeclr(ofstream &outfile, const ColorStruct& clr, long no);
void readclr(ifstream &infile,long& num);
void readclr(ifstream &infile,ColorStruct* pClrs);
void readclr(ifstream &infile,ColorStruct& clr,long no);
void insertclr(fstream &file,long no,const ColorStruct* pClrs,long num);

ifstream& operator >> (ifstream&, ColorStruct&);
ofstream& operator << (ofstream&, const ColorStruct&);

//##ModelId=4918445C008C
class CManager  
{
	//##ModelId=4918445C009D
	vector<CLayer*> m_vMaps;
	//##ModelId=4918445C00A4
	vector<ColorStruct> m_vClrs;
	//##ModelId=4918445C00AC
	ColorStruct m_clrInvalid;//错误返回使用
public:
	//##ModelId=4918445C00B0
	CManager();
	//##ModelId=4918445C00B1
	virtual ~CManager() {DeleteLayers(); DeleteColors();}
	//属性获取函数
	//##ModelId=4918445C00B3
	int GetLayerNum(void) const {return m_vMaps.size();}
	//##ModelId=4918445C00B6
	CLayer* GetLayer(int index) {
		if(index>=0&&index<GetLayerNum()){
			return m_vMaps[index];} 
		return NULL;}
	//##ModelId=4918445C00BC
	CLayer* GetLayerByID(short id){
		for(int i=0; i<GetLayerNum(); i++){
			if(m_vMaps[i]->GetID()==id){
				return m_vMaps[i];}} 
		return NULL;}
	//##ModelId=4918445C00BE
	int GetColorNum(void) const {return m_vClrs.size();}
	//##ModelId=4918445C00C1
	ColorStruct& GetColor(short index){
		if(index>=0&&index<GetColorNum()){
			return m_vClrs[index];} 
		return m_clrInvalid;}
	//属性设置函数
	//插入一个图层
	//##ModelId=4918445C00C3
	void InsertLayers(CLayer* layer) {m_vMaps.push_back(layer);}
	//##ModelId=4918445C00C5
	void InsertLayers(int index, CLayer* layer) {
		if(index>=0&&index<GetLayerNum()){
			m_vMaps.insert(m_vMaps.begin()+index,layer);}
		else InsertLayers(layer);}
	//删除一个图层
	//##ModelId=4918445C00CD
	void DeleteLayers(int index) {
		if(index>=0&&index<GetLayerNum()){
			CLayer *p=m_vMaps[index];
			if(p!=NULL) delete p;
			m_vMaps.erase(m_vMaps.begin()+index);}}
	//删除所有图层
	//##ModelId=4918445C00CF
	void DeleteLayers(void) {
		for(int i=0; i<GetLayerNum(); i++){
			CLayer* p=m_vMaps[i];
			if(p!=NULL) delete p;}
		m_vMaps.clear();}
	//从文件中读取一个图层
	//##ModelId=4918445C00D1
	void OpenMap(const char* szFileName);
	//保存一个图层到文件中
	//##ModelId=4918445C00D3
	void SaveMap(int index, const char* szFileName);
	//##ModelId=4918445C00DB
	void SaveMapByID(short id, const char* szFileName){
		for(int i=0; i<GetLayerNum(); i++){
			if(m_vMaps[i]->GetID()==id){
				SaveMap(i,szFileName); break;}}}
	//修改颜色值
	//##ModelId=4918445C00DE
	void ModColor(int index, ColorStruct& clr) {}//自行实现
	//插入一个颜色值
	//##ModelId=4918445C00E1
	void InsertColors(ColorStruct& clr) {m_vClrs.push_back(clr);}
	//##ModelId=4918445C00E3
	void InsertColors(int index, ColorStruct& pt) {}//自行实现
	//删除一个颜色值
	//##ModelId=4918445C00EC
	void DeleteColors(int index) {}//自行实现
	//删除所有颜色值
	//##ModelId=4918445C00EE
	void DeleteColors(void) {m_vClrs.clear();}
	//从文件中读取颜色表
	//##ModelId=4918445C00F0
	void OpenClrTable(const char* szFileName="colors.txt");
	//保存颜色表到文件中
	//##ModelId=4918445C00F2
	void SaveClrTable(const char* szFileName="colors.txt");
};

#endif // !defined(AFX_MANAGER_H__36E48F48_477D_4B72_9B2C_FABEC5EC6096__INCLUDED_)
