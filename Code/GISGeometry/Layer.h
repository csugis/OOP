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

//##ModelId=4918445C00FA
class CLayer  
{	
	//##ModelId=4918445C010B
	vector<CGeometry*> m_vGeometry;
	//##ModelId=4918445C010F
	unsigned char m_cType;//图形元素类型
	//##ModelId=4918445C0110
	short m_sLayerID;
public:
	//##ModelId=4918445C0119
	CLayer() {};
	//##ModelId=4918445C011A
	virtual ~CLayer() {DeleteGeometry();};
	//属性获取函数
	//##ModelId=4918445C011C
	int GetGeometryNum(void) const {return m_vGeometry.size();} 
	//##ModelId=4918445C011F
	unsigned char GetGeometryType(void) const {return m_cType;}
	//##ModelId=4918445C0122
	int GetGeometryID(int index) const{
		if(index>=0&&index<GetGeometryNum()){
			CGeometry* p=m_vGeometry[index]; return p->GetID();}
		else return NULL;}
	//##ModelId=4918445C0125
	CGeometry* GetGeometry(int index) const{
		if(index>=0&&index<GetGeometryNum()){
			return m_vGeometry[index];}
		else return NULL;}
	//##ModelId=4918445C0128
	CGeometry* GetGeometryByID(int id){
		for(int i=0; i<GetGeometryNum(); i++){
			CGeometry* p=m_vGeometry[i];
			if(p!=NULL && p->GetID()==id) {
				return p; break;}}
		return NULL;}
	//##ModelId=4918445C012A
	short GetID() const {return m_sLayerID;}
	//属性设置函数
	//##ModelId=4918445C012C
	void SetID(short id) {m_sLayerID=id;}
	//##ModelId=4918445C012E
	void SetGeometryType(unsigned char type) {m_cType=type;}
	//修改图形元素
	//##ModelId=4918445C0130
	void ModGeometry(int index, CGeometry* geometry){
		if(geometry->GetGeoType()!=GetGeometryType()) return;
		if(index>=0&&index<GetGeometryNum()){
			CGeometry* p=m_vGeometry[index]; if(p!=NULL) delete p;
			m_vGeometry[index]=geometry;}}
	//##ModelId=4918445C0133
	void ModGeometry(CGeometry *geometry){//使用指针自带id
		if(geometry->GetGeoType()!=GetGeometryType()) return;
		for(int i=0; i<GetGeometryNum(); i++){
			CGeometry* p=m_vGeometry[i];
			if(p!=NULL && p->GetID()==geometry->GetID()) {
				delete p; m_vGeometry[i]=geometry; break;}}}
	//插入图形元素
	//##ModelId=4918445C0138
	void InsertGeometry(CGeometry* geometry){
		if(geometry->GetGeoType()!=GetGeometryType()) return;
		m_vGeometry.push_back(geometry);}
	//插入图形元素
	//##ModelId=4918445C013A
	void InsertGeometry(int index, CGeometry* geometry){
		if(geometry->GetGeoType()!=GetGeometryType()) return;
		if(index>=0&&index<GetGeometryNum()){
			m_vGeometry.insert(m_vGeometry.begin()+index,geometry);}
		else InsertGeometry(geometry);}
	//删除一个图形元素
	//##ModelId=4918445C013D
	void DeleteGeometry(int index) {
		if(index>=0&&index<GetGeometryNum()){
			CGeometry* p=m_vGeometry[index];
			if(p!=NULL) delete p;
			m_vGeometry.erase(m_vGeometry.begin()+index);}}
	//##ModelId=4918445C013F
	void DeleteGeometryByID(int id) {
		for(int i=0; i<GetGeometryNum(); i++){
			CGeometry* p=m_vGeometry[i];
			if(p!=NULL && p->GetID()==id) {
				delete p; break;}}}
	//删除所有图形元素
	//##ModelId=4918445C0141
	void DeleteGeometry(void) {
		for(int i=0; i<GetGeometryNum(); i++){
			CGeometry* p=m_vGeometry[i];
			if(p!=NULL) delete p;}
		m_vGeometry.clear();}
	//从文件中导入图形元素
	//##ModelId=4918445C0148
	void GetFromFile(ifstream&);
	//导出图形元素到文本文件中
	//##ModelId=4918445C014A
	void PutToFile(ofstream&);
};

#endif // !defined(AFX_LAYER_H__7101C2A4_4970_4984_88C6_0DBB818E94AA__INCLUDED_)
