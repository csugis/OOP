// BaseTool.h: interface for the CBaseTool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASETOOL_H__153AA50A_394B_47D1_B347_681FA9B12BB4__INCLUDED_)
#define AFX_BASETOOL_H__153AA50A_394B_47D1_B347_681FA9B12BB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum toolType
{
	toolTypeUndefined = 0,
	toolTypeDrawText = 1,
	toolTypeDrawLine = 2,
	toolTypeDrawPolyline = 3,
	toolTypeDrawCircle = 4,
	toolTypeDrawArc = 5,
	toolTypeDrawFillCircle = 6,
	toolTypeDrawPolygon = 7,
	toolTypeMoveText = 8,
	toolTypeMoveLine = 9,
	toolTypeMovePolyline = 10,
	toolTypeMoveCircle = 11,
	toolTypeMoveArc = 12,
	toolTypeMoveFillCircle = 13,
	toolTypeMovePolygon = 14,
	toolTypeDelText = 15,
	toolTypeDelLine = 16,
	toolTypeDelPolyline = 17,
	toolTypeDelCircle = 18,
	toolTypeDelArc = 19,
	toolTypeDelFillCircle = 20,
	toolTypeDelPolygon = 21
};

#define NUM_NEW_POINTS 100

class CBaseTool : public CObject{
public:
	CBaseTool(CView * ownerObj):m_pView(ownerObj),m_toolType(toolTypeUndefined) {};
	virtual ~CBaseTool() {};
protected:
	CView* m_pView;
	toolType m_toolType;
	unsigned char m_geoType;
	void SetToolType(toolType type) {m_toolType=type;};
public:
	toolType GetToolType(void) const {return m_toolType;}
	virtual void SetGeometryType(unsigned char type) {m_geoType=type;}

	virtual void ProcMouse(UINT msg,int x,int y,UINT keyFlags) {}
	//����������Ϣ
	virtual long ProcCommand(UINT id){ return 0;}
	//�����Ϣ
	//����: msg!=WM_RBUTTONUPʱ, 1/0  ��������/ɾ���˹���
	//      msg==WM_RBUTTONUPʱ, 1/0  �����Ҽ��˵�/�������Ҽ��˵�
	virtual short ProcMouse(UINT msg,CPoint * xy,UINT keyFlags) {return 1;}
	//������Ϣ:ProcKey��KeyDown�д���
	virtual short ProcKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {return 1;}
	//��KeyUp�д���
	virtual short ProcKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) {return 1;}
	//�����ػ���Ϣ
	virtual void ProcPaint(CDC *pDC) {}
	virtual short Running() {return 1;}
};

#endif // !defined(AFX_BASETOOL_H__153AA50A_394B_47D1_B347_681FA9B12BB4__INCLUDED_)
