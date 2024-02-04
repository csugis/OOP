// Manager.h: interface for the CManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGER_H__36E48F48_477D_4B72_9B2C_FABEC5EC6096__INCLUDED_)
#define AFX_MANAGER_H__36E48F48_477D_4B72_9B2C_FABEC5EC6096__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CManager;
CArchive& operator << (CArchive&, CManager&);
CArchive& operator >> (CArchive&, CManager&);

class CManager  
{
	vector<CLayer*> m_vMaps;
	long m_lMaxLyrID;
	friend CArchive& operator << (CArchive&, CManager&);
	friend CArchive& operator >> (CArchive&, CManager&);
public:
	CManager();
	virtual ~CManager() {DeleteLayers(); }
	void Draw(CDC *pDC); 
	//属性获取函数
	int GetLayerNum(void) const {return m_vMaps.size();}
	CLayer* GetLayer(int index) {
		if(index>=0&&index<GetLayerNum()){
			return m_vMaps[index];} 
		return NULL;}
	CLayer* GetLayerByID(short id){
		for(int i=0; i<GetLayerNum(); i++){
			if(m_vMaps[i]->GetID()==id){
				return m_vMaps[i];}} 
		return NULL;}
	CLayer* GetLayerByType(unsigned char type){
		for(int i=0; i<GetLayerNum(); i++){
			if(m_vMaps[i]->GetGeometryType()==type){
				return m_vMaps[i];}} 
		return NULL;}
	//属性设置函数
	//插入一个图层
	void InsertLayers(CLayer* layer);
	void InsertLayers(int index, CLayer* layer);
	//删除一个图层
	void DeleteLayers(int index) {
		if(index>=0&&index<GetLayerNum()){
			CLayer *p=m_vMaps[index];
			if(p!=NULL) delete p;
			m_vMaps.erase(m_vMaps.begin()+index);}}
	//删除所有图层
	void DeleteLayers(void) {
		for(int i=0; i<GetLayerNum(); i++){
			CLayer* p=m_vMaps[i];
			if(p!=NULL) delete p;}
		m_vMaps.clear(); m_lMaxLyrID=0;}
	//从文件中读取一个图层
	void OpenMap(const char* szFileName);
	//保存一个图层到文件中
	void SaveMap(int index);
	void SaveMapByID(short id){
		for(int i=0; i<GetLayerNum(); i++){
			if(m_vMaps[i]->GetID()==id){
				SaveMap(i); break;}}}
	//插入一个图形到某一图层,如果index=0则插入到合适图层
	void InsertGeometryToLayer(CGeometry* pGeo, int index=-1);
};

#endif // !defined(AFX_MANAGER_H__36E48F48_477D_4B72_9B2C_FABEC5EC6096__INCLUDED_)
