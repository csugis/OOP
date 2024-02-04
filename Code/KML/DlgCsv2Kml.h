#pragma once

#include "resource.h"
#include "Field.h"
#include "tArray.h"
// DlgCsv2Kml �Ի���

class DlgCsv2Kml : public CDialog
{
	DECLARE_DYNAMIC(DlgCsv2Kml)

public:
	DlgCsv2Kml(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgCsv2Kml();

// �Ի�������
	enum { IDD = IDD_DIALOG_CSV2KML };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	void AddString(const char*);
public:
	tArray<Field> * pflds;
	int id;
	int name;
	int lon;
	int lat;
	virtual BOOL OnInitDialog();
};
