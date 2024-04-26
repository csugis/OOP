
// KMLAppView.cpp: CKMLAppView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "KMLApp.h"
#endif

#include "KMLAppDoc.h"
#include "KMLAppView.h"
#include "..\KML\Point.h"
#include "..\KML\LineString.h"
#include "ToolDrawPoint.h"
#include "ToolDrawLinearString.h"
#include "ToolDrawPolygon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKMLAppView

IMPLEMENT_DYNCREATE(CKMLAppView, CView)

BEGIN_MESSAGE_MAP(CKMLAppView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_POINT, &CKMLAppView::OnPoint)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_POLYLINE, &CKMLAppView::OnPolyline)
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_POLYGON, &CKMLAppView::OnPolygon)
END_MESSAGE_MAP()

// CKMLAppView 构造/析构

CKMLAppView::CKMLAppView() noexcept
{
	// TODO: 在此处添加构造代码
	m_pCurTool = nullptr;
}

CKMLAppView::~CKMLAppView()
{
	if (m_pCurTool != nullptr)
		delete m_pCurTool;
}

BOOL CKMLAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CKMLAppView 绘图

void CKMLAppView::OnDraw(CDC* pDC)
{
	CKMLAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	DrawKML(pDC);
	// TODO: 在此处为本机数据添加绘制代码
}


// CKMLAppView 打印

BOOL CKMLAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CKMLAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CKMLAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CKMLAppView 诊断

#ifdef _DEBUG
void CKMLAppView::AssertValid() const
{
	CView::AssertValid();
}

void CKMLAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKMLAppDoc* CKMLAppView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKMLAppDoc)));
	return (CKMLAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CKMLAppView 消息处理程序
void CKMLAppView::DrawPoint(CDC* pDC, Point* pt)
{
	pDC->TextOut(pt->getLongitude(), pt->getLatitude(), _T("*"));
}
void CKMLAppView::DrawLineString(CDC* pDC, LineString* ls)
{
	long lSize = 0;
	CPoint* pts = nullptr;
	tArray<CPoint> tp;
	Coord* pc = nullptr;
	lSize = ls->getCoordinates().getSize();
	pc = ls->getCoordinates().getTs();
	for (int i = 0; i < lSize; i++)
	{
		tp[i].x = ls->getCoordinates()[i].getLongitude();
		tp[i].y = ls->getCoordinates()[i].getLatitude();
	}
	pDC->Polyline(tp.getTs(), lSize);
}

void CKMLAppView::DrawPolygon(CDC* pDC, Poly* pg)
{
	long lSize = 0;
	CPoint* pts = nullptr;
	tArray<CPoint> tp;
	Coord* pc = nullptr;
	LinearRing* lr = &(pg->getOuterBoundary());
	lSize = lr->getCoordinates().getSize();
	pc = lr->getCoordinates().getTs();
	for (int i = 0; i < lSize; i++)
	{
		tp[i].x = lr->getCoordinates()[i].getLongitude();
		tp[i].y = lr->getCoordinates()[i].getLatitude();
	}
	int nOldROP2 = pDC->SetROP2(R2_NOTXORPEN);
	CPen pen, * pOldPen = NULL;
	CBrush brush, * pOldBrush = NULL;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	brush.CreateSolidBrush(RGB(0, 0, 255));
	pOldPen = pDC->SelectObject(&pen);
	pOldBrush = pDC->SelectObject(&brush);
	pDC->Polygon(tp.getTs(), lSize);
	pDC->SetROP2(nOldROP2);
}
void CKMLAppView::DrawKML(CDC* pDC)
{
	CKMLAppDoc* pDoc = GetDocument();
	KML* pKML = nullptr;
	if (pDoc != nullptr)
		pKML = pDoc->getKML();
	if (pKML == nullptr)
		return;
	tArray<Placemark>& pms = pKML->getPlacemarks();
	for (int i = 0; i < pms.getSize(); i++)
	{
		Geometry* pGeo = pms[i].getGeometry();

		switch (pGeo->getGeoType())
		{
		case geoPoint:
			DrawPoint(pDC, (Point*)pGeo);
			break;
		case geoLineString:
			DrawLineString(pDC, (LineString*)pGeo);
			break;
		case geoPolygon:
			DrawPolygon(pDC, (Poly*)pGeo);
			break;
		case geoMulti:
			break;
		default:
			pDC->TextOut(0, 0, _T("Wrong Geometry Type!"));
		}
	}
}

void CKMLAppView::OnPoint()
{
	// TODO: 在此添加命令处理程序代码
	if (m_pCurTool != nullptr)
	{
		if (m_pCurTool->GetToolType() == toolTypeDrawPoint)
			return;
		else
			delete m_pCurTool;
	}
	m_pCurTool = new CToolDrawPoint(this);
}


void CKMLAppView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pCurTool != NULL)
	{
		m_pCurTool->ProcMouse(WM_LBUTTONDOWN, &point, nFlags);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CKMLAppView::OnPolyline()
{
	// TODO: 在此添加命令处理程序代码
	if (m_pCurTool != nullptr)
	{
		if (m_pCurTool->GetToolType() == toolTypeDrawLineString)
			return;
		else
			delete m_pCurTool;
	}
	m_pCurTool = new CToolDrawLineString(this);
}


void CKMLAppView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pCurTool != NULL)
	{
		m_pCurTool->ProcMouse(WM_MOUSEMOVE, &point, nFlags);
	}
	CView::OnMouseMove(nFlags, point);
}


void CKMLAppView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pCurTool != NULL)
	{
		m_pCurTool->ProcMouse(WM_RBUTTONDOWN, &point, nFlags);
	}
	CView::OnRButtonDown(nFlags, point);
}


void CKMLAppView::OnPolygon()
{
	// TODO: 在此添加命令处理程序代码
	if (m_pCurTool != nullptr)
	{
		if (m_pCurTool->GetToolType() == toolTypeDrawPolygon)
			return;
		else
			delete m_pCurTool;
	}
	m_pCurTool = new CToolDrawPolygon(this);
}
