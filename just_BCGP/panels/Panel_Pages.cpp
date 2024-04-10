// workspace.cpp : implementation of the Panel_Pages class
//

#include "../stdafx.h"
#include "../just_BCGP.h"
#include "Panel_Pages.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Panel_Pages

BEGIN_MESSAGE_MAP(Panel_Pages, CBCGPDockingControlBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Panel_Pages construction/destruction

Panel_Pages::Panel_Pages()
{
	// TODO: add one-time construction code here

}

Panel_Pages::~Panel_Pages()
{
}


/////////////////////////////////////////////////////////////////////////////
// Panel_Pages message handlers

int Panel_Pages::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBCGPDockingControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Create tree control:
	const DWORD dwViewStyle =	WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS;

	m_wndTree.m_bVisualManagerStyle = TRUE;

	if (!m_wndTree.Create(dwViewStyle, rectDummy, this, 1))
	{
		TRACE0("Failed to create treeview in the panel Pages\n");
		return -1;      // fail to create
	}

	// Setup tree content:
	HTREEITEM hRoot = m_wndTree.InsertItem(_T("Pages Root"));
	m_wndTree.InsertItem(_T("Pages Item 1"), hRoot);
	m_wndTree.InsertItem(_T("Pages Item 2"), hRoot);

	m_wndTree.Expand(hRoot, TVE_EXPAND);

	return 0;
}

void Panel_Pages::OnSize(UINT nType, int cx, int cy)
{
	CBCGPDockingControlBar::OnSize(nType, cx, cy);

	// Tree control should cover a whole client area:
	m_wndTree.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
}
