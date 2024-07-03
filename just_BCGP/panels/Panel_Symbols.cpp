// workspace.cpp : implementation of the Panel_Symbols class
//

#include "../stdafx.h"
#include "../just_BCGP.h"
#include "Panel_Symbols.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Panel_Symbols

BEGIN_MESSAGE_MAP(Panel_Symbols, CBCGPDockingControlBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_BTN_SEARCH_SYMBOLS, On_Search_Symbols)
	ON_UPDATE_COMMAND_UI(ID_BTN_SEARCH_SYMBOLS, On_Update_Search_Symbols)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Panel_Symbols construction/destruction

Panel_Symbols::Panel_Symbols()
{
	// TODO: add one-time construction code here

}


Panel_Symbols::~Panel_Symbols()
{
}


/////////////////////////////////////////////////////////////////////////////
// Panel_Symbols message handlers

int Panel_Symbols::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBCGPDockingControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	CRect rectDummy;
	rectDummy.SetRectEmpty();


	m_btn_search.m_bVisualManagerStyle = TRUE;

	if (!m_btn_search.Create(
		L"Search",
		WS_CHILD | WS_VISIBLE,
		rectDummy,
		this,
		ID_BTN_SEARCH_SYMBOLS
	))
	{
		TRACE(_T("could not create button symbol search\n"));
		return -1;
	}


	// Create tree control:
	const DWORD dwViewStyle =	WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS;

	m_wndTree.m_bVisualManagerStyle = TRUE;

	if (!m_wndTree.Create(dwViewStyle, rectDummy, this, 1))
	{
		TRACE0("Failed to create workspace view\n");
		return -1;      // fail to create
	}

	// Setup tree content:
	HTREEITEM hRoot = m_wndTree.InsertItem(_T("Root 1"));
	m_wndTree.InsertItem(_T("Item 1"), hRoot);
	m_wndTree.InsertItem(_T("Item 2"), hRoot);

	m_wndTree.Expand(hRoot, TVE_EXPAND);
	
	return 0;
}

void Panel_Symbols::OnSize(UINT nType, int cx, int cy)
{
	CBCGPDockingControlBar::OnSize(nType, cx, cy);


	const int li_left = 1;
	int li_padding = 0;



	int nTop = 0;
	int li_height = 50;
	const int li_whoKnowsWhy = 10;





	if (m_btn_search.GetSafeHwnd())
	{
		m_btn_search.MoveWindow(li_left + li_padding,
			nTop + li_padding,
			cx - (2 * li_left) - (2 * li_padding),
			nTop + li_height);

		nTop += li_height + (3 * li_padding);
	}


	// Tree control should cover a whole client area:
	m_wndTree.MoveWindow(li_left + li_padding,
		nTop + li_padding,
		cx - (2 * li_left) - (2 * li_padding),
		nTop + li_height);
}

void Panel_Symbols::On_Search_Symbols()
{

}

void Panel_Symbols::On_Update_Search_Symbols(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}
