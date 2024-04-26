#include "pch.h"
#include "ToolDrawPolygon.h"
#include "KMLAppDoc.h"
#include "..\KML\LinearRing.h"
#include "..\KML\Polygon.h"

CToolDrawPolygon::CToolDrawPolygon(CView* ownerObj) :CBaseTool(ownerObj)
{

}
CToolDrawPolygon::~CToolDrawPolygon()
{
	m_vPoints.clear();
}

BOOL CToolDrawPolygon::DrawPolygon(CDC* pDC) {
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
		return pDC->Polygon(pts, lSize);
	else
		return FALSE;
}

long CToolDrawPolygon::AddPolygon(tArray<CPoint>& pts)
{
	CKMLAppDoc* pDoc = (CKMLAppDoc*)m_pView->GetDocument();
	KML* pKML = nullptr;
	if (pDoc != nullptr)
		pKML = pDoc->getKML();
	if (pKML == nullptr)
		return -1;

	Placemark& pm = pKML->nextPlacemark();
	//封装成函数
	//Placemark存储一份克隆，最后由Placemark释放空间
	Poly pg;
	LinearRing lr;
	tArray<Coord>& coords = lr.getCoordinates();
	for (int i = 0; i < pts.getSize(); i++)
		coords[i] = pts[i];
	pg.setOuterBoundary(lr);
	pm.setGeometry(&pg);
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
short CToolDrawPolygon::ProcMouse(UINT msg, CPoint* xy, UINT keyFlags)
{
	CDC* pdc = m_pView->GetDC();
	int nOldROP2 = pdc->SetROP2(R2_NOTXORPEN);
	CPen pen, * pOldPen = NULL;
	CBrush brush, * pOldBrush = NULL;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	brush.CreateSolidBrush(RGB(0, 0, 255));
	CPoint ptXY;
	static bool flagsetcapture = 0;
	switch (msg) {
	case WM_LBUTTONDOWN:
		pOldPen = pdc->SelectObject(&pen);
		pOldBrush = pdc->SelectObject(&brush);
		DrawPolygon(pdc);
		ptXY = *xy;
		m_vPoints.push_back(ptXY);
		DrawPolygon(pdc);
		pdc->SelectObject(pOldPen);
		pdc->SelectObject(pOldBrush);
		flagsetcapture = 1;
		break;
	case WM_MOUSEMOVE:
		if (flagsetcapture == 1) {
			pOldPen = pdc->SelectObject(&pen);
			pOldBrush = pdc->SelectObject(&brush);
			DrawPolygon(pdc);
			if (m_vPoints.getSize() > 1)
				m_vPoints.pop_back();
			ptXY = *xy;
			m_vPoints.push_back(ptXY);
			DrawPolygon(pdc);
			pdc->SelectObject(pOldPen);
			pdc->SelectObject(pOldBrush);
		}
		break;
	case WM_RBUTTONDOWN:
		if (flagsetcapture == 1)
		{
			pOldPen = pdc->SelectObject(&pen);
			pOldBrush = pdc->SelectObject(&brush);
			pdc->SelectObject(pOldPen);
			pdc->SelectObject(pOldBrush);
			flagsetcapture = 0;
			//添加到文件
			AddPolygon(m_vPoints);
			m_vPoints.clear();
		}
		break;
	}
	pdc->SetROP2(nOldROP2);
	m_pView->ReleaseDC(pdc);
	return 1;
}