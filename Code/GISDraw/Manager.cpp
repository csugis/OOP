// Manager.cpp: implementation of the CManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Manager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CManager::CManager():m_lMaxLyrID(0)
{

}


//���ļ��ж�ȡһ��ͼ��
void CManager::OpenMap(const char* szFileName)
{
	CLayer *layer = new CLayer;
	layer->GetFromFile(szFileName);
	InsertLayers(layer);
}
//����һ��ͼ�㵽�ļ���
void CManager::SaveMap(int index)
{
	if(index>=0&&index<GetLayerNum())
	{
		GetLayer(index)->PutToFile();
	}
}
void CManager::Draw(CDC *pDC)
{
	for(int i=0; i<GetLayerNum(); i++)
	{
		GetLayer(i)->Draw(pDC);
	}
}
//����һ��ͼ��
void CManager::InsertLayers(CLayer* layer) 
{
	if(layer->GetID() <= 0)
	{
		if(m_lMaxLyrID==0)
		{
			for(int i=0;i<GetLayerNum();i++)
			{
				if(m_lMaxLyrID<GetLayer(i)->GetID())
					m_lMaxLyrID=GetLayer(i)->GetID();
			}
		}
		m_lMaxLyrID++;
		layer->SetID(m_lMaxLyrID);	
	}
	m_vMaps.push_back(layer);
}
void CManager::InsertLayers(int index, CLayer* layer) 
{
	if(index>=0&&index<GetLayerNum())
	{
		if(layer->GetID() <= 0)
		{
			if(m_lMaxLyrID==0)
			{
				for(int i=0;i<GetLayerNum();i++)
				{
					if(m_lMaxLyrID<GetLayer(i)->GetID())
						m_lMaxLyrID=GetLayer(i)->GetID();
				}
			}
			m_lMaxLyrID++;
			layer->SetID(m_lMaxLyrID);	
		}
		m_vMaps.insert(m_vMaps.begin()+index,layer);
	}
	else InsertLayers(layer);
}

//����һ��ͼ�ε�ĳһͼ��,���index=0����뵽����ͼ��
void CManager::InsertGeometryToLayer(CGeometry* pGeo, int index/*=-1*/)
{
	CLayer* pLayer=NULL;
	if(index<0){//�嵽���в�
		for(int i=0;i<GetLayerNum();i++)
		{
			if(pGeo->GetGeoType() == GetLayer(i)->GetGeometryType())
			{
				pLayer = GetLayer(i);
				break;
			}
		}
		if(pLayer==NULL)
		{
			pLayer=new CLayer;
			pLayer->SetGeometryType(pGeo->GetGeoType());
			InsertLayers(pLayer);
		}
	}
	else 
		pLayer = GetLayer(index);
	pLayer->InsertGeometry(pGeo);
}

CArchive& operator << (CArchive& ar, CManager& mgr)
{
	CString sFileName="";
	for(int i=0; i<mgr.GetLayerNum(); i++)
	{
		mgr.SaveMap(i);
		ar.WriteString(mgr.GetLayer(i)->GetFileName()+"\n");
	}
	return ar;
}
CArchive& operator >> (CArchive& ar, CManager& mgr)
{
	CString sFileName="";
	while(ar.ReadString(sFileName))
	{
		mgr.OpenMap(sFileName);
	}
	return ar;
}


