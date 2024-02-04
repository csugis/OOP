// ToolDrawCircle.h: interface for the CToolDrawCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDRAWCIRCLE_H__CE5EA5D6_0917_477C_AF1B_340F9BFAE540__INCLUDED_)
#define AFX_TOOLDRAWCIRCLE_H__CE5EA5D6_0917_477C_AF1B_340F9BFAE540__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseTool.h"

class CToolDrawCircle : public CBaseTool  
{
	CPoint m_ptXY;
	double m_dRadius;
public:
	CToolDrawCircle(CView * ownerObj);
	virtual ~CToolDrawCircle();
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags);
};

#endif // !defined(AFX_TOOLDRAWCIRCLE_H__CE5EA5D6_0917_477C_AF1B_340F9BFAE540__INCLUDED_)
