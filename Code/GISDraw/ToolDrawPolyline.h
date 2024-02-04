// ToolDrawPolyline.h: interface for the CToolDrawPolyline class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDRAWPOLYLINE_H__F019B7A5_BE67_4E28_B84B_5292BA788935__INCLUDED_)
#define AFX_TOOLDRAWPOLYLINE_H__F019B7A5_BE67_4E28_B84B_5292BA788935__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
using namespace std;
#include "BaseTool.h"

class CToolDrawPolyline : public CBaseTool  
{
	vector<CPoint> m_vPoints;
	CPoint* m_pPoints;
	long    m_lSize;
	CPoint* GetVertex(void);
	BOOL    DrawPolyline(CDC* pDC);
public:
	CToolDrawPolyline(CView * ownerObj);
	virtual ~CToolDrawPolyline();
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags);

};

#endif // !defined(AFX_TOOLDRAWPOLYLINE_H__F019B7A5_BE67_4E28_B84B_5292BA788935__INCLUDED_)
