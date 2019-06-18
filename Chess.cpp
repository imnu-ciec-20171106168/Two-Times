// Chess.cpp: implementation of the CChess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyTask.h"
#include "Chess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChess::CChess()
{
	type=0;
	num=0;
}

CChess::~CChess()
{

}

CChess& CChess::operator=(CChess& p)
{
	num=p.num;
	type=p.type;
	pointB=p.pointB;
	pointW=p.pointW;
	return* this;
}

void CChess::Serialize(CArchive &ar)
{
	if(ar.IsStoring())
	{
		ar<<num;
		ar<<type;
		ar<<pointB;
		ar<<pointW;
	}
	else
	{
		ar>>num;
		ar>>type;
		ar>>pointB;
		ar>>pointW;
	}
}


CPoint CChess::PointToStonePos(CPoint point)
{
	int xGrid=26,yGrid=26;
	int xpt=(int)floor(point.x/xGrid);
	int ypt=(int)floor(point.y/yGrid);
	CPoint pt(xpt,ypt);
	return pt;
}

CPoint CChess::PointToStonePos(int m,int n)
{
	int xGrid=26,yGrid=26;
	int xpt=m*xGrid+7;
	int ypt=n*yGrid+9;
	CPoint pt(xpt,ypt);
	return pt;
}

void CChess::DisplayStone(CDC* pDC,UINT IDResource,CPoint point)
{
	CBitmap Bitmap;
	Bitmap.LoadBitmap(IDResource);//��λͼװ���ڴ�
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC); //�����ڴ��豸����
	CBitmap *OldBitmap=MemDC.SelectObject(&Bitmap);
	BITMAP bm;                    //����BITMAP�ṹ����
	Bitmap.GetBitmap(&bm);        //��ȡλͼ��Ϣ
	if(IDResource==IDB_MASK)
		pDC->BitBlt(point.x,point.y,bm.bmWidth,bm.bmHeight, &MemDC,0,0,SRCAND);//���λͼ
	else
		pDC->BitBlt(point.x,point.y,bm.bmWidth,bm.bmHeight,&MemDC,0,0,SRCPAINT);//���λͼ
	pDC->SelectObject(OldBitmap);//�ָ��豸����
	MemDC.DeleteDC();
}