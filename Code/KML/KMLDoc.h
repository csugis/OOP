// KMLDoc.h : CKMLDoc ��Ľӿ�
//


#pragma once


class CKMLDoc : public CDocument
{
protected: // �������л�����
	CKMLDoc();
	DECLARE_DYNCREATE(CKMLDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CKMLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCsv2kml();
};


