#include "pch.h"
#include "ToolDrawPoint.h"
#include <string>
#include "../KML/tArray.h"
#include "../KML/Point.h"
#include "../KML/Placemark.h"
#include "KMLappDoc.h"

using namespace std;

CToolDrawPoint::CToolDrawPoint(CView* ownerObj):CBaseTool(ownerObj)
{
	
}
CToolDrawPoint::~CToolDrawPoint()
{

}
//�����Ϣ
//����: msg!=WM_RBUTTONUPʱ, 1/0  ��������/ɾ���˹���
//      msg==WM_RBUTTONUPʱ, 1/0  �����Ҽ��˵�/�������Ҽ��˵�
short CToolDrawPoint::ProcMouse(UINT msg, CPoint* xy, UINT keyFlags)
{
	CDC* pdc = m_pView->GetDC();
	CString str("*");
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		pdc->TextOut(xy->x, xy->y, str);
        AddPoint(xy);
		break;
	default:
		break;
	}
	m_pView->ReleaseDC(pdc);
	return 1;
}

long CToolDrawPoint::AddPoint(CPoint* xy)
{
    CKMLAppDoc* pDoc = (CKMLAppDoc*)m_pView->GetDocument();
    KML* pKML = nullptr;
    if(pDoc != nullptr)
        pKML = pDoc->getKML();
    if (pKML == nullptr)
        return -1;

    Placemark& pm = pKML->nextPlacemark();
    //�㣬��װ�ɺ���
    //Placemark�洢һ�ݿ�¡�������Placemark�ͷſռ�
    Point pt;
    pt.setLongitude(xy->x);
    pt.setLatitude(xy->y);
    pm.setGeometry(&pt);
    string des = "<![CDATA[ \n";
    des += "<table border=\"1\" padding=\"3\" width=\"300\">\n";
    //��һ��
    des += "<tr>";
    des += "<td> Name </td>";
    des += "<td> Travel </td>";
    des += "</tr>";
    //�ڶ���
    des += "<tr>";
    des += "<td> Year </td>";
    des += "<td> From 2022 </td>";
    des += "</tr>";

    des += "</table>\n";
    des += "]]>\n";
    string name = "Point Placemark";
    pm.setDescription(des);
    pm.setName(name);
    
    return 1;
}