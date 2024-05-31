// workspace.cpp : implementation of the Panel_Layers class
//

#include "../stdafx.h"
#include "../just_BCGP.h"
#include "Panel_Layers.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Panel_Layers

BEGIN_MESSAGE_MAP(Panel_Layers, CBCGPDockingControlBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Panel_Layers construction/destruction

Panel_Layers::Panel_Layers()
{
	// TODO: add one-time construction code here

}

void Panel_Layers::ShowPreview(int ai_index)
{

}

Panel_Layers::~Panel_Layers()
{
}


/////////////////////////////////////////////////////////////////////////////
// Panel_Layers message handlers

int Panel_Layers::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (QPanel_With_Preview::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Create tree control:
	const DWORD dwViewStyle =	WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS;

	m_wndTree.m_bVisualManagerStyle = TRUE;

	if (!m_wndTree.Create(dwViewStyle, rectDummy, this, 1))
	{
		TRACE0("Failed to create treeview in the panel Layers\n");
		return -1;      // fail to create
	}

	// Setup tree content:
	HTREEITEM hRoot = m_wndTree.InsertItem(_T("Layers Root"));
	m_wndTree.InsertItem(_T("Layers Item 1"), hRoot);
	m_wndTree.InsertItem(_T("Layers Item 2"), hRoot);

	m_wndTree.Expand(hRoot, TVE_EXPAND);

	return 0;
}

void Panel_Layers::OnSize(UINT nType, int cx, int cy)
{
	QPanel_With_Preview::OnSize(nType, cx, cy);

	// Tree control should cover a whole client area:
	m_wndTree.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
}
