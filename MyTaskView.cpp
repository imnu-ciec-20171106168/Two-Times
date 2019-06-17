// MyTaskView.cpp : implementation of the CMyTaskView class
//

#include "stdafx.h"
#include "MyTask.h"

#include "MyTaskDoc.h"
#include "MyTaskView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTaskView

IMPLEMENT_DYNCREATE(CMyTaskView, CView)

BEGIN_MESSAGE_MAP(CMyTaskView, CView)
	//{{AFX_MSG_MAP(CMyTaskView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTaskView construction/destruction

CMyTaskView::CMyTaskView()
{
	// TODO: add construction code here

}

CMyTaskView::~CMyTaskView()
{
}

BOOL CMyTaskView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyTaskView drawing

void CMyTaskView::OnDraw(CDC* pDC)
{
	CMyTaskDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyTaskView printing

BOOL CMyTaskView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyTaskView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyTaskView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyTaskView diagnostics

#ifdef _DEBUG
void CMyTaskView::AssertValid() const
{
	CView::AssertValid();
}

void CMyTaskView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyTaskDoc* CMyTaskView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyTaskDoc)));
	return (CMyTaskDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTaskView message handlers
