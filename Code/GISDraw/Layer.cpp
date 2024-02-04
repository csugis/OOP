// Layer.cpp: implementation of the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Layer.h"
#include "Beeline.h"
#include "Curve.h"
#include "Round.h"
#include "Arc.h"
#include "Label.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//从文件中导入图形元素
void CLayer::GetFromFile(ifstream& infile)
{
	int num;
	infile>>m_sLayerID>>m_cType>>num;
	CGeometry* p=NULL;
	for(int i=0; i<num; i++)
	{
		switch(m_cType)
		{
		case geoTypeLine:
			p=new CBeeline;
			break;
		case geoTypePolyline:
			p=new CCurve;
			break;
		case geoTypePolygon:
			p=new CCurve;
			((CCurve*)p)->Fill();
			break;
		case geoTypeCircle:
			p=new CRound;
			break;
		case geoTypeRound:
			p=new CRound;
			((CRound*)p)->Fill();
			break;
		case geoTypeArc:
			p=new CArc;
			break;
		case geoTypeLabel:
			p=new CLabel;
			break;
		default: return;
		}
		p->UnDelete();
		p->SetLayerIndex(m_sLayerID);
		p->GetFromFile(infile);
		InsertGeometry(p);
	}
}
//导出图形元素到文本文件中
void CLayer::PutToFile(ofstream& outfile)
{
	//删除所有已经删除
	int i;
	for(i=GetGeometryNum()-1; i>=0; i--)
		if(GetGeometry(i)->IsDelete())
			DeleteGeometry(i);
	outfile<<m_sLayerID<<" "<<m_cType<<" "<<GetGeometryNum()<<endl;
	for(i=0; i<GetGeometryNum(); i++)
		GetGeometry(i)->PutToFile(outfile);
}

//从文件中导入图形元素
void CLayer::GetFromFile(LPCTSTR pszFileName)
{
	ifstream infile(pszFileName,ios::in);
	m_sFileName=pszFileName;
	GetFromFile(infile);
	infile.close();
}
//导出图形元素到文本文件中
void CLayer::PutToFile()
{
	if(m_sFileName=="")
		m_sFileName.Format("%d.txt",GetID());
	ofstream outfile(m_sFileName,ios::out);
	PutToFile(outfile);
	outfile.close();
}

void CLayer::Draw(CDC *pDC)
{
	for(int i=0; i<GetGeometryNum(); i++)
	{
		if(GetGeometry(i)->IsDelete()) continue;
		GetGeometry(i)->Draw(pDC);
	}
}

//插入图形元素
void CLayer::InsertGeometry(CGeometry* geometry)
{
	if(geometry->GetGeoType()!=GetGeometryType()) return;
	if(geometry->GetID() <= 0)
	{
		if(m_lMaxGeoID==0)
		{
			for(int i=0;i<GetGeometryNum();i++)
			{
				if(m_lMaxGeoID<GetGeometry(i)->GetID())
					m_lMaxGeoID=GetGeometry(i)->GetID();
			}
		}
		m_lMaxGeoID++;
		geometry->SetID(m_lMaxGeoID);	
	}
	m_vGeometry.push_back(geometry);
}
//插入图形元素
void CLayer::InsertGeometry(int index, CGeometry* geometry)
{
	if(geometry->GetGeoType()!=GetGeometryType()) return;
	if(index>=0&&index<GetGeometryNum())
	{
		if(geometry->GetID() <= 0)
		{
			if(m_lMaxGeoID==0)
			{
				for(int i=0;i<GetGeometryNum();i++)
				{
					if(m_lMaxGeoID<GetGeometry(i)->GetID())
						m_lMaxGeoID=GetGeometry(i)->GetID();
				}
			}
			m_lMaxGeoID++;
			geometry->SetID(m_lMaxGeoID);	
		}
		m_vGeometry.insert(m_vGeometry.begin()+index,geometry);
	}
	else InsertGeometry(geometry);
}

CGeometry* CLayer::Search(const PointStruct& pt, double radius, bool bSelDel/*=FALSE*/) const
{
	CGeometry* pGeo=NULL;
	double dist=1.0E8,tempDist=1.0E10;
	for(int i=0; i< GetGeometryNum(); i++)
	{
		if(!bSelDel && GetGeometry(i)->IsDelete()) continue;
		tempDist = GetGeometry(i)->DistanceToPoint(pt);
		if(tempDist < dist)
		{
			pGeo = GetGeometry(i);
			dist = tempDist;
		}
	}
	if(dist > radius)
		pGeo = NULL;
	return pGeo;
}

