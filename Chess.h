// Chess.h: interface for the CChess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHESS_H__6D1D851C_6CF9_486E_99F8_583D1546FF38__INCLUDED_)
#define AFX_CHESS_H__6D1D851C_6CF9_486E_99F8_583D1546FF38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CChess : public CObject
{
public:
	CChess();
	virtual ~CChess();
public:
	CPoint pointW;//����λ��
	CPoint pointB;//����λ��
	int type;//1Ϊ���塢2Ϊ���塢0Ϊ��
	int num;//����˳��ţ�����Ϊ0
public:
	CPoint PointToStonePos(CPoint point);
	CPoint PointToStonePos(int m,int n);
	void DisplayStone(CDC* pDC,UINT IDResource,CPoint point);
	CChess& operator=(CChess&);
    virtual void Serialize(CArchive &ar);//��CChess�����л�����
	DECLARE_SERIAL(CChess)//�������л���CChess
};

#endif // !defined(AFX_CHESS_H__6D1D851C_6CF9_486E_99F8_583D1546FF38__INCLUDED_)
