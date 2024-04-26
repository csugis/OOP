#pragma once
#include "BaseTool.h"
class CToolDrawPolygon :
    public CBaseTool
{
	tArray<CPoint> m_vPoints;
	BOOL DrawPolygon(CDC* pDC);
	long AddPolygon(tArray<CPoint>& pts);
public:
	CToolDrawPolygon(CView* ownerObj);
	~CToolDrawPolygon();
	toolType GetToolType(void) const { return toolTypeDrawPolygon; }
	//�����Ϣ
	//����: msg!=WM_RBUTTONUPʱ, 1/0  ��������/ɾ���˹���
	//      msg==WM_RBUTTONUPʱ, 1/0  �����Ҽ��˵�/�������Ҽ��˵�
	short ProcMouse(UINT msg, CPoint* xy, UINT keyFlags);
	//����������Ϣ
	long ProcCommand(UINT id) { return -1; }
	//������Ϣ:ProcKey��KeyDown�д���
	short ProcKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) { return -1; }
	//��KeyUp�д���
	short ProcKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) { return -1; }
	//�����ػ���Ϣ
	void ProcPaint(CDC* pDC) {  }
	short Running() { return -1; }
};

