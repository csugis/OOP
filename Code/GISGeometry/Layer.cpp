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

//���ļ��е���ͼ��Ԫ��
//##ModelId=4918445C0148
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
//����ͼ��Ԫ�ص��ı��ļ���
//##ModelId=4918445C014A
void CLayer::PutToFile(ofstream& outfile)
{
	//ɾ�������Ѿ�ɾ��
	int i;
	for(i=GetGeometryNum()-1; i>=0; i--)
	{
		if(GetGeometry(i)->IsDelete())
		{
			DeleteGeometry(i);
		}
	}
	outfile<<m_sLayerID<<" "<<m_cType<<" "<<GetGeometryNum()<<endl;
	for(i=0; i<GetGeometryNum(); i++)
	{
		GetGeometry(i)->PutToFile(outfile);
	}
}
