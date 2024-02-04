#pragma once

#include "resource.h"
#include "Field.h"
#include "tArray.h"
// DlgCsv2Kml 对话框

class DlgCsv2Kml : public CDialog
{
	DECLARE_DYNAMIC(DlgCsv2Kml)

public:
	DlgCsv2Kml(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgCsv2Kml();

// 对话框数据
	enum { IDD = IDD_DIALOG_CSV2KML };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
