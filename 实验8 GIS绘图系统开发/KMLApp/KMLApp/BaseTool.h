#pragma once
#include <afx.h>
#include <afxwin.h>
#define NUM_NEW_POINTS 100

enum toolType
{
	toolTypeUndefined = 0,
	toolTypeDrawPoint = 1,
	toolTypeDrawLineString = 2,
	toolTypeDrawPolygon = 3,
	toolTypeMovePoint = 4,
	toolTypeMoveLineString = 5,
	toolTypeMovePolygon = 6,
	toolTypeDelPoint = 7,
	toolTypeDelLineString = 8,
	toolTypeDelPolygon = 9
};

class CBaseTool :
    public CObject
{
public:
	CBaseTool(CView* ownerObj) :m_pView(ownerObj) {};
	virtual ~CBaseTool() {};
protected:
	CView* m_pView;
	unsigned char m_geoType;
public:
	virtual toolType GetToolType(void) const = 0;
	virtual void SetGeometryType(unsigned char type) { m_geoType = type; }

	//鼠标消息
	//返回: msg!=WM_RBUTTONUP时, 1/0  正常返回/删除此工具
	//      msg==WM_RBUTTONUP时, 1/0  允许右键菜单/不允许右键菜单
	virtual short ProcMouse(UINT msg, CPoint* xy, UINT keyFlags) { return -1; }
	//处理命令消息
	virtual long ProcCommand(UINT id) { return -1; }
	//键盘消息:ProcKey在KeyDown中处理
	virtual short ProcKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) { return -1; }
	//在KeyUp中处理
	virtual short ProcKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) { return -1; }
	//处理重画消息
	virtual void ProcPaint(CDC* pDC) {  }
	virtual short Running() { return -1; }
};

