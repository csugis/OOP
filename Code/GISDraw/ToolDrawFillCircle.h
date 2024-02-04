// ToolDrawFillCircle.h: interface for the CToolDrawFillCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDRAWFILLCIRCLE_H__E33529F8_9FE1_47D8_8E49_64FC4016F76A__INCLUDED_)
#define AFX_TOOLDRAWFILLCIRCLE_H__E33529F8_9FE1_47D8_8E49_64FC4016F76A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseTool.h"

class CToolDrawFillCircle : public CBaseTool  
{
	CPoint m_ptXY;
	double m_dRadius;
public:
	CToolDrawFillCircle(CView * ownerObj);
	virtual ~CToolDrawFillCircle();
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags);

};

#endif // !defined(AFX_TOOLDRAWFILLCIRCLE_H__E33529F8_9FE1_47D8_8E49_64FC4016F76A__INCLUDED_)
