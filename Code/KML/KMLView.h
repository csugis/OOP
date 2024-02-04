// KMLView.h : CKMLView 类的接口
//


#pragma once


class CKMLView : public CTreeView
{
protected: // 仅从序列化创建
	CKMLView();
	DECLARE_DYNCREATE(CKMLView)

// 属性
public:
	CKMLDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CKMLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // KMLView.cpp 中的调试版本
inline CKMLDoc* CKMLView::GetDocument() const
   { return reinterpret_cast<CKMLDoc*>(m_pDocument); }
#endif

