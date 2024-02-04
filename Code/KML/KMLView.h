// KMLView.h : CKMLView ��Ľӿ�
//


#pragma once


class CKMLView : public CTreeView
{
protected: // �������л�����
	CKMLView();
	DECLARE_DYNCREATE(CKMLView)

// ����
public:
	CKMLDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CKMLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // KMLView.cpp �еĵ��԰汾
inline CKMLDoc* CKMLView::GetDocument() const
   { return reinterpret_cast<CKMLDoc*>(m_pDocument); }
#endif

