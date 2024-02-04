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
	//���Ի�ȡ����
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
	//�������ú���
	//����һ��ͼ��
	void InsertLayers(CLayer* layer);
	void InsertLayers(int index, CLayer* layer);
	//ɾ��һ��ͼ��
	void DeleteLayers(int index) {
		if(index>=0&&index<GetLayerNum()){
			CLayer *p=m_vMaps[index];
			if(p!=NULL) delete p;
			m_vMaps.erase(m_vMaps.begin()+index);}}
	//ɾ������ͼ��
	void DeleteLayers(void) {
		for(int i=0; i<GetLayerNum(); i++){
			CLayer* p=m_vMaps[i];
			if(p!=NULL) delete p;}
		m_vMaps.clear(); m_lMaxLyrID=0;}
	//���ļ��ж�ȡһ��ͼ��
	void OpenMap(const char* szFileName);
	//����һ��ͼ�㵽�ļ���
	void SaveMap(int index);
	void SaveMapByID(short id){
		for(int i=0; i<GetLayerNum(); i++){
			if(m_vMaps[i]->GetID()==id){
				SaveMap(i); break;}}}
	//����һ��ͼ�ε�ĳһͼ��,���index=0����뵽����ͼ��
	void InsertGeometryToLayer(CGeometry* pGeo, int index=-1);
};

#endif // !defined(AFX_MANAGER_H__36E48F48_477D_4B72_9B2C_FABEC5EC6096__INCLUDED_)
