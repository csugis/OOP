// ToolDelRound.h: interface for the CToolDelRound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDELROUND_H__E35FCD98_A7FB_4BB2_ACA1_63886B7BF794__INCLUDED_)
#define AFX_TOOLDELROUND_H__E35FCD98_A7FB_4BB2_ACA1_63886B7BF794__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseTool.h"
#include "Layer.h"
class CToolDelRound : public CBaseTool  
{
	CLayer*	m_pCurLyr;
	CGeometry* m_pSelected;
public:
	CToolDelRound(CView * ownerObj);
	virtual ~CToolDelRound();
	virtual void SetGeometryType(unsigned char type);
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags);
};

#endif // !defined(AFX_TOOLDELROUND_H__E35FCD98_A7FB_4BB2_ACA1_63886B7BF794__INCLUDED_)
