// just_BCGPView.cpp : implementation of the Cjust_BCGPView class
//

#include "stdafx.h"
#include "just_BCGP.h"

#include "just_BCGPDoc.h"
#include "just_BCGPView.h"

#include "QDlgAttributes.h"
#include "QDlgListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cjust_BCGPView

IMPLEMENT_DYNCREATE(Cjust_BCGPView, CView)

BEGIN_MESSAGE_MAP(Cjust_BCGPView, CView)
	ON_WM_CONTEXTMENU()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cjust_BCGPView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_MESSAGE(WM_PRINTCLIENT, &Cjust_BCGPView::OnPrintClient)

	ON_COMMAND(ID_VIEW_ATTRIBUTES, &Cjust_BCGPView::OnViewAttributes)
	ON_COMMAND(ID_VIEW_LISTBOX, &Cjust_BCGPView::OnViewListBox)
END_MESSAGE_MAP()

// Cjust_BCGPView construction/destruction

Cjust_BCGPView::Cjust_BCGPView()
{
	// TODO: add construction code here

}

Cjust_BCGPView::~Cjust_BCGPView()
{
}

BOOL Cjust_BCGPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cjust_BCGPView drawing

void Cjust_BCGPView::OnDraw(CDC* /*pDC*/)
{
	Cjust_BCGPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


// Cjust_BCGPView printing

void Cjust_BCGPView::OnFilePrintPreview()
{
	BCGPPrintPreview (this);
}



BOOL Cjust_BCGPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return BCGPPreparePrinting(this, pInfo);
}

void Cjust_BCGPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cjust_BCGPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cjust_BCGPView diagnostics

#ifdef _DEBUG
void Cjust_BCGPView::AssertValid() const
{
	CView::AssertValid();
}

void Cjust_BCGPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cjust_BCGPDoc* Cjust_BCGPView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cjust_BCGPDoc)));
	return (Cjust_BCGPDoc*)m_pDocument;
}
#endif //_DEBUG


// Cjust_BCGPView message handlers

LRESULT Cjust_BCGPView::OnPrintClient(WPARAM wp, LPARAM lp)
{
	if ((lp & PRF_CLIENT) == PRF_CLIENT)
	{
		CDC* pDC = CDC::FromHandle((HDC)wp);
		ASSERT_VALID(pDC);

		OnDraw(pDC);
	}

	return 0;
}


void Cjust_BCGPView::OnContextMenu(CWnd*, CPoint point)
{
	if (CBCGPPopupMenu::GetSafeActivePopupMenu() != NULL)
	{
		return;
	}

	theApp.ShowPopupMenu(IDR_CONTEXT_MENU, point, this);
}


void Cjust_BCGPView::OnViewAttributes()
{
	QDlgAttributes l_dlg;
	l_dlg.DoModal();
}

void Cjust_BCGPView::OnViewListBox()
{
	QDlgListBox l_dlg;
	l_dlg.DoModal();
}
