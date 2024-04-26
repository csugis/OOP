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

	//�����Ϣ
	//����: msg!=WM_RBUTTONUPʱ, 1/0  ��������/ɾ���˹���
	//      msg==WM_RBUTTONUPʱ, 1/0  �����Ҽ��˵�/�������Ҽ��˵�
	virtual short ProcMouse(UINT msg, CPoint* xy, UINT keyFlags) { return -1; }
	//����������Ϣ
	virtual long ProcCommand(UINT id) { return -1; }
	//������Ϣ:ProcKey��KeyDown�д���
	virtual short ProcKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) { return -1; }
	//��KeyUp�д���
	virtual short ProcKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) { return -1; }
	//�����ػ���Ϣ
	virtual void ProcPaint(CDC* pDC) {  }
	virtual short Running() { return -1; }
};

