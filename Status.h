// Status.h: interface for the CStatus class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUS_H__828C1437_87F0_49C1_B98E_E19DDEFADCA5__INCLUDED_)
#define AFX_STATUS_H__828C1437_87F0_49C1_B98E_E19DDEFADCA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Chess.h"
#include "Player.h"
class CStatus : CObject
{
public:
	CStatus();
	virtual ~CStatus();
public:
	CPlayer player[2];
	int nWithComputer;//������Ϊ1,����Ϊ0
	int cursor;//1Ϊ�ڡ�2Ϊ�ס�0Ϊ��׼
	int next;//��һ�����Ӳ�����0Ϊ�ס�1Ϊ��
	int count;//����˳���
	CChess chess[15][15];
public:
	CStatus& operator=(CStatus&);
    virtual void Serialize(CArchive &ar);//��CStatus�����л�����
	DECLARE_SERIAL(CStatus)//�������л���CStatus
};

#endif // !defined(AFX_STATUS_H__828C1437_87F0_49C1_B98E_E19DDEFADCA5__INCLUDED_)
