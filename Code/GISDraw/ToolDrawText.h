// ToolDrawText.h: interface for the CToolDrawText class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDRAWTEXT_H__7CC2EBDC_B0D3_4115_B07D_989379CA80A9__INCLUDED_)
#define AFX_TOOLDRAWTEXT_H__7CC2EBDC_B0D3_4115_B07D_989379CA80A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseTool.h"

class CToolDrawText : public CBaseTool  
{
public:
	CToolDrawText(CView * ownerObj);
	virtual ~CToolDrawText();
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags);

};

#endif // !defined(AFX_TOOLDRAWTEXT_H__7CC2EBDC_B0D3_4115_B07D_989379CA80A9__INCLUDED_)
