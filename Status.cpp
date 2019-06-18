// Status.cpp: implementation of the CStatus class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyTask.h"
#include "Status.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStatus::CStatus()
{
	nWithComputer=1;//����������
	next=1;//�ڷ�������
	cursor=1;//�Զ���ڷ����ӹ��
	count=0;
	player[0].name=_T(" ");
	player[0].chessType=1;//ѡ��ִ������
	player[1].name=_T("����");
	player[1].chessType=2;//�����ִ�׺���
	//������225�����ӵ�λ�Ĵ������꼰��������
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
		{
			chess[i][j].pointB.x=j;
			chess[i][j].pointB.y=i;
			chess[i][j].pointW.x=j*26+85;
			chess[i][j].pointW.y=i*26+9;			
		}
}

CStatus::~CStatus()
{

}

CStatus& CStatus::operator=(CStatus& p)
{
	int i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			chess[i][j]=p.chess[i][j];
    for(i=0;i<2;i++)
		player[i]=p.player[i];
     nWithComputer=p.nWithComputer;
	 cursor=p.cursor;
	 next=p.next;
	 count=p.count;
	 return* this;
}

void CStatus::Serialize(CArchive &ar)
{
	if(ar.IsStoring())//������������
	{
	int i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			chess[i][j].Serialize(ar);
    for(i=0;i<2;i++)
		player[i].Serialize(ar);
     ar<<nWithComputer<<cursor<<next<<count<<sound;
	}
	else
	{
	int i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			chess[i][j].Serialize(ar);
    for(i=0;i<2;i++)
		player[i].Serialize(ar);
     ar>>nWithComputer>>cursor>>next>>count>>sound;
	}
}
