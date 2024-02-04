// ToolDrawPolygon.h: interface for the CToolDrawPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDRAWPOLYGON_H__2BB4F3FA_36F6_4926_A7D5_0FD68A415E0A__INCLUDED_)
#define AFX_TOOLDRAWPOLYGON_H__2BB4F3FA_36F6_4926_A7D5_0FD68A415E0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
using namespace std;
#include "BaseTool.h"


class CToolDrawPolygon : public CBaseTool  
{
	vector<CPoint> m_vPoints;
	CPoint* m_pPoints;
	long    m_lSize;
	CPoint* GetVertex(void);
	BOOL    DrawPolygon(CDC* pDC);
public:
	CToolDrawPolygon(CView * ownerObj);
	virtual ~CToolDrawPolygon();
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags);

};

#endif // !defined(AFX_TOOLDRAWPOLYGON_H__2BB4F3FA_36F6_4926_A7D5_0FD68A415E0A__INCLUDED_)
