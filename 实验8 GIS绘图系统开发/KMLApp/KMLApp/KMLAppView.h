
// KMLAppView.h: CKMLAppView 类的接口
//

#pragma once
#include "BaseTool.h"
#include "..\KML\Point.h"
#include "..\KML\LineString.h"
#include "..\KML\Polygon.h"

class CKMLAppView : public CView
{
	CBaseTool* m_pCurTool;
protected: // 仅从序列化创建
	CKMLAppView() noexcept;
	DECLARE_DYNCREATE(CKMLAppView)

// 特性
public:
	CKMLAppDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	void DrawKML(CDC* pDC);
	void DrawPoint(CDC* pDC, Point *pt);
	void DrawLineString(CDC* pDC, LineString* ls);
	void DrawPolygon(CDC* pDC, Poly* pg);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CKMLAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPoint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPolyline();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPolygon();
};

#ifndef _DEBUG  // KMLAppView.cpp 中的调试版本
inline CKMLAppDoc* CKMLAppView::GetDocument() const
   { return reinterpret_cast<CKMLAppDoc*>(m_pDocument); }
#endif

