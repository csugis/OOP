#pragma once
#include "BaseTool.h"
class CToolDrawPoint :
    public CBaseTool
{
	long AddPoint(CPoint* xy);
public:
	CToolDrawPoint(CView* ownerObj);
	virtual ~CToolDrawPoint();
	toolType GetToolType(void) const { return toolTypeDrawPoint; }
	//鼠标消息
	//返回: msg!=WM_RBUTTONUP时, 1/0  正常返回/删除此工具
	//      msg==WM_RBUTTONUP时, 1/0  允许右键菜单/不允许右键菜单
	short ProcMouse(UINT msg, CPoint* xy, UINT keyFlags);
	//处理命令消息
	long ProcCommand(UINT id) { return -1; }
	//键盘消息:ProcKey在KeyDown中处理
	short ProcKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) { return -1; }
	//在KeyUp中处理
	short ProcKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) { return -1; }
	//处理重画消息
	void ProcPaint(CDC* pDC) {  }
	short Running() { return -1; }
};

