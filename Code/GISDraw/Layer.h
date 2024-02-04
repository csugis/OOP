// Layer.h: interface for the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAYER_H__7101C2A4_4970_4984_88C6_0DBB818E94AA__INCLUDED_)
#define AFX_LAYER_H__7101C2A4_4970_4984_88C6_0DBB818E94AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
using namespace std;

#include "Geometry.h"
class CManager;
class CLayer  
{	
	vector<CGeometry*> m_vGeometry;
	unsigned char m_cType;//图形元素类型
	short m_sLayerID;
	CString m_sFileName;
	long m_lMaxGeoID;
	friend class CManager;
	void SetID(short id) {m_sLayerID=id;}
protected:
	//从文件中导入图形元素
	void GetFromFile(ifstream&);
	//导出图形元素到文本文件中
	void PutToFile(ofstream&);
public:
	CLayer():m_sFileName(""),m_sLayerID(-1),m_lMaxGeoID(0) {};
	virtual ~CLayer() {DeleteGeometry();};
	void Draw(CDC *pDC); 
	CGeometry* Search(const PointStruct& pt, double radius, bool bSelDel=FALSE) const;
	//属性获取函数
	int GetGeometryNum(void) const {return m_vGeometry.size();} 
	unsigned char GetGeometryType(void) const {return m_cType;}
	int GetGeometryID(int index) const{
		if(index>=0&&index<GetGeometryNum()){
			CGeometry* p=m_vGeometry[index]; return p->GetID();}
		else return NULL;}
	CGeometry* GetGeometry(int index) const{
		if(index>=0&&index<GetGeometryNum()){
			return m_vGeometry[index];}
		else return NULL;}
	CGeometry* GetGeometryByID(int id){
		for(int i=0; i<GetGeometryNum(); i++){
			CGeometry* p=m_vGeometry[i];
			if(p!=NULL && p->GetID()==id) {
				return p; break;}}
		return NULL;}
	short GetID() const {return m_sLayerID;}
	CString& GetFileName() {return m_sFileName;}
	//属性设置函数
	void SetGeometryType(unsigned char type) {m_cType=type;}
	//修改图形元素
	void ModGeometry(int index, CGeometry* geometry){
		if(geometry->GetGeoType()!=GetGeometryType()) return;
		if(index>=0&&index<GetGeometryNum()){
			CGeometry* p=m_vGeometry[index]; if(p!=NULL) delete p;
			m_vGeometry[index]=geometry;}}
	void ModGeometry(CGeometry *geometry){//使用指针自带id
		if(geometry->GetGeoType()!=GetGeometryType()) return;
		for(int i=0; i<GetGeometryNum(); i++){
			CGeometry* p=m_vGeometry[i];
			if(p!=NULL && p->GetID()==geometry->GetID()) {
				delete p; m_vGeometry[i]=geometry; break;}}}
	//插入图形元素
	void InsertGeometry(CGeometry* geometry);
	//插入图形元素
	void InsertGeometry(int index, CGeometry* geometry);
	//删除一个图形元素
	void DeleteGeometry(int index) {
		if(index>=0&&index<GetGeometryNum()){
			CGeometry* p=m_vGeometry[index];
			if(p!=NULL) delete p;
			m_vGeometry.erase(m_vGeometry.begin()+index);}}
	void DeleteGeometryByID(int id) {
		for(int i=0; i<GetGeometryNum(); i++){
			CGeometry* p=m_vGeometry[i];
			if(p!=NULL && p->GetID()==id) {
				delete p; break;}}}
	//删除所有图形元素
	void DeleteGeometry(void) {
		for(int i=0; i<GetGeometryNum(); i++){
			CGeometry* p=m_vGeometry[i];
			if(p!=NULL) delete p;}
		m_vGeometry.clear();}
	//从文件中导入图形元素
	void GetFromFile(LPCTSTR pszFileName);
	//导出图形元素到文本文件中
	void PutToFile();

};

#endif // !defined(AFX_LAYER_H__7101C2A4_4970_4984_88C6_0DBB818E94AA__INCLUDED_)
