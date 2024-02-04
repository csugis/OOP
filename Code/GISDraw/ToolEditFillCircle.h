// ToolEditFillCircle.h: interface for the CToolMoveRound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLEDITFILLCIRCLE_H__2A0D4472_8A34_424C_82CF_9C19E49E0462__INCLUDED_)
#define AFX_TOOLEDITFILLCIRCLE_H__2A0D4472_8A34_424C_82CF_9C19E49E0462__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseTool.h"
#include "Geometry.h"

class CToolMoveRound : public CBaseTool  
{
	CLayer*	m_pCurLyr;
	CGeometry* m_pSelected;
public:
	CToolMoveRound(CView * ownerObj);
	virtual ~CToolMoveRound();
	virtual void SetGeometryType(unsigned char type);
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags);
};

#endif // !defined(AFX_TOOLEDITFILLCIRCLE_H__2A0D4472_8A34_424C_82CF_9C19E49E0462__INCLUDED_)
