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

void Panel_Pages::AdjustLayout()
{
	CRect rectClient;
	GetClientRect(rectClient);

	const int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	if (m_wndToolBar.GetSafeHwnd() != NULL)
	{
		m_wndToolBar.SetWindowPos(NULL, 0, 0, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	}

	m_wndTree.SetWindowPos(NULL, 0, cyTlb, rectClient.Width(), rectClient.Height() - cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);

}

void Panel_Pages::ShowPreview(int ai_index)
{

}

void Panel_Pages::Create_Toolbar()
{
	// Create toolbar:
	if (!m_wndToolBar.Create(this, dwDefaultToolbarStyle, AFX_IDW_TOOLBAR + 1) ||
		!m_wndToolBar.LoadToolBar(IDR_TOOLBAR_PAGES, 0, 0, TRUE /* Is locked */, 0, 0, 0))
	{
		TRACE0("Failed to create toolbar\n");
		return; // fail to create
	}


	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);

	m_wndToolBar.SetBarStyle(
		m_wndToolBar.GetBarStyle() &
		~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_wndToolBar.SetOwner(this);

	// All commands will be routed via this control , not via the parent frame:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);
}

Panel_Pages::~Panel_Pages()
{
}


/////////////////////////////////////////////////////////////////////////////
// Panel_Pages message handlers

int Panel_Pages::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (QPanel_With_Preview::OnCreate(lpCreateStruct) == -1)
		return -1;

	Create_Toolbar();

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
	QPanel_With_Preview::OnSize(nType, cx, cy);

	// Tree control should cover a whole client area:
	m_wndTree.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
}

void Toolbar_Pages::AdjustLayout()
{
	CBCGPToolBar::AdjustLayout();

	((Panel_Pages*)GetParent())->AdjustLayout();
}
