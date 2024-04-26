#include "pch.h"
#include "ToolDrawLinearString.h"
#include "KMLAppDoc.h"
#include "..\KML\LineString.h"

CToolDrawLineString::CToolDrawLineString(CView* ownerObj)
	:CBaseTool(ownerObj)
{
}

CToolDrawLineString::~CToolDrawLineString()
{
	m_vPoints.clear();
}

BOOL CToolDrawLineString::DrawPolyline(CDC* pDC) {
	long lSize = m_vPoints.getSize();
	CPoint* pts = m_vPoints.getTs();
	if (lSize == 1) {
		pDC->MoveTo(m_vPoints[0]);
		return pDC->LineTo(m_vPoints[0]);
	}
	else if (lSize == 2) {
		pDC->MoveTo(m_vPoints[0]);
		return pDC->LineTo(m_vPoints[1]);
	}
	else if (lSize > 2)
		return pDC->Polyline(pts, lSize);
	else
		return FALSE;
}

long CToolDrawLineString::AddLineString(tArray<CPoint>& pts)
{
	CKMLAppDoc* pDoc = (CKMLAppDoc*)m_pView->GetDocument();
	KML* pKML = nullptr;
	if (pDoc != nullptr)
		pKML = pDoc->getKML();
	if (pKML == nullptr)
		return -1;

	Placemark& pm = pKML->nextPlacemark();
	//点，封装成函数
	//Placemark存储一份克隆，最后由Placemark释放空间
	LineString ls;
	tArray<Coord>& coords = ls.getCoordinates();
	for(int i=0;i<pts.getSize();i++)
		coords[i] = pts[i];
	pm.setGeometry(&ls);
	string des = "<![CDATA[ \n";
	des += "<table border=\"1\" padding=\"3\" width=\"300\">\n";
	//第一行
	des += "<tr>";
	des += "<td> Name </td>";
	des += "<td> Travel </td>";
	des += "</tr>";
	//第二行
	des += "<tr>";
	des += "<td> Year </td>";
	des += "<td> From 2022 </td>";
	des += "</tr>";

	des += "</table>\n";
	des += "]]>\n";
	string name = "LineString Placemark";
	pm.setDescription(des);
	pm.setName(name);

	return 1;
}
//鼠标消息
//返回: msg!=WM_RBUTTONUP时, 1/0  正常返回/删除此工具
//      msg==WM_RBUTTONUP时, 1/0  允许右键菜单/不允许右键菜单
short CToolDrawLineString::ProcMouse(UINT msg, CPoint* xy, UINT keyFlags)
{
	CDC* pdc = m_pView->GetDC();
	int nOldROP2 = pdc->SetROP2(R2_NOTXORPEN);
	CPen pen, * pOldPen = NULL;
	CBrush brush, * pOldBrush = NULL;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	brush.CreateSolidBrush(RGB(0, 0, 255));
	CPoint ptXY=*xy;
	static bool flagsetcapture = 0;
	switch (msg) {
	case WM_LBUTTONDOWN:
		pOldPen = pdc->SelectObject(&pen);
		pOldBrush = pdc->SelectObject(&brush);
		DrawPolyline(pdc);
		//ptXY = *xy;
		m_vPoints.push_back(ptXY);
		DrawPolyline(pdc);
		pdc->SelectObject(pOldPen);
		pdc->SelectObject(pOldBrush);
		flagsetcapture = 1;
		break;
	case WM_MOUSEMOVE:
		if (flagsetcapture == 1) {
			pOldPen = pdc->SelectObject(&pen);
			pOldBrush = pdc->SelectObject(&brush);
			DrawPolyline(pdc);
			if (m_vPoints.getSize() > 1)
				m_vPoints.pop_back();
			//ptXY = *xy;
			m_vPoints.push_back(ptXY);
			DrawPolyline(pdc);
			pdc->SelectObject(pOldPen);
			pdc->SelectObject(pOldBrush);
		}
		break;
	case WM_RBUTTONDOWN:
		if (flagsetcapture == 1)
		{
			pOldPen = pdc->SelectObject(&pen);
			pOldBrush = pdc->SelectObject(&brush);
			//DrawPolyline(pdc);
			pdc->SelectObject(pOldPen);
			pdc->SelectObject(pOldBrush);
			flagsetcapture = 0;
			//添加到文档
			AddLineString(m_vPoints);
			m_vPoints.clear();
		}
		break;
	}
	pdc->SetROP2(nOldROP2);
	m_pView->ReleaseDC(pdc);
	return 1;
}