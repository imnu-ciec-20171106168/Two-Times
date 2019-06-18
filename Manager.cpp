// Manager.cpp: implementation of the CManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyTask.h"
#include "Manager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CManager::CManager()
{
	int i,j,k,count=0;
	p1win=false;//ѡ��δ��ʤ
	p2win=false;
	over=true;//��Ϸδ��ʼ
	pause=false;
	//ѡ�ֵĻ�ʤ�����û������
	for(i=0;i<=1;i++)
		for(j=0;j<572;j++)
			win[i][j]=0;
    //�����ϵ�ÿ�������Ƿ��ڻ�ʤ�����
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			for(k=0;k<572;k++)
			{
				p1table[i][j][k] = false;
				p2table[i][j][k] = false;
			}
    //ˮƽ����
	for(i=0;i<15;i++)        
		for(j=0;j<11;j++)
		{
			for(k=0;k<5;k++)
			{
				p1table[j+k][i][count] = true;
				p2table[j+k][i][count] = true;
			}
			count++;
		}    
    //��ֱ����
	for(i=0;i<15;i++)       
		for(j=0;j<11;j++)
		{
			for(k=0;k<5;k++)
			{
				p1table[i][j+k][count] = true;
				p2table[i][j+k][count] = true;
			}
			count++;
		}
    //��б����
	for(i=0;i<11;i++)        
		for(j=0;j<11;j++)
		{
			for(k=0;k<5;k++)
			{
				p1table[j+k][i+k][count] = true;
				p2table[j+k][i+k][count] = true;
			}
			count++;
		}
    //��б����
	for(i=0;i<11;i++)          
		for(j=14;j>=4;j--)
		{
			for(k=0;k<5;k++)
			{
				p1table[j-k][i+k][count] = true;
				p2table[j-k][i+k][count] = true;
			}
			count++;
		}
}

CManager::~CManager()
{

}

CManager& CManager::operator=(CManager&p)
{
	int i,j,k;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			for(k=0;k<572;k++)
			{
				p1table[i][j][k]=p.p1table[i][j][k];
				p2table[i][j][k]=p.p2table[i][j][k];
			}
    for(i=0;i<2;i++)
		for(k=0;k<572;k++)
			win[i][k]=p.win[i][k];
     p1win=p.p1win;
	 p2win=p.p2win;
	 over=p.over;
	 return* this;
}
void CManager::Serialize(CArchive &ar)
{
	if(ar.IsStoring())//������������
	{
		int i,j,k;
		for(i=0;i<15;i++)
			for(j=0;j<15;j++)
				for(k=0;k<572;k++)
				{
					ar<<p1table[i][j][k];
					ar<<p2table[i][j][k];
				}
		for(i=0;i<2;i++)
			for(k=0;k<572;k++)
				ar<<win[i][k];
		ar<<p1win<<p2win<<over<<pause;
	}
	else//�������������
	{
		int i,j,k;
		for(i=0;i<15;i++)
			for(j=0;j<15;j++)
				for(k=0;k<572;k++)
				{
					ar>>p1table[i][j][k];
					ar>>p2table[i][j][k];
				}
		for(i=0;i<2;i++)
			for(k=0;k<572;k++)
				ar>>win[i][k];
		ar>>p1win>>p2win>>over>>pause;
	}
}