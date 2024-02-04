// ToolDrawLine.h: interface for the CToolDrawLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDRAWLINE_H__9D655D78_1AB0_4642_9974_CF5E9098AC60__INCLUDED_)
#define AFX_TOOLDRAWLINE_H__9D655D78_1AB0_4642_9974_CF5E9098AC60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseTool.h"

class CToolDrawLine : public CBaseTool  
{
	CPoint m_ptStart,m_ptEnd;
public:
	CToolDrawLine(CView * ownerObj);
	virtual ~CToolDrawLine();
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags);

};

#endif // !defined(AFX_TOOLDRAWLINE_H__9D655D78_1AB0_4642_9974_CF5E9098AC60__INCLUDED_)
