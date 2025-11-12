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

	
	m_list.SetWindowPos(NULL, 0, cyTlb, rectClient.Width(), rectClient.Height() - cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
}

void Panel_Pages::ShowPreview(int ai_index)
{

}

void Panel_Pages::Create_Toolbar()
{
	// Create toolbar:
	if (!m_wndToolBar.Create(this, dwDefaultToolbarStyle, IDR_TOOLBAR_PAGES) ||
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

	m_list.m_bVisualManagerStyle = TRUE;
	if (m_list.GetSafeHwnd() == 0)
	{
		m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_HSCROLL | WS_VSCROLL | LBS_HASSTRINGS | LBS_NOTIFY | LBS_OWNERDRAWFIXED,
			CRect(0, 0, 0, 0), this, 2025);
	}

	CFont* pFont = m_list.GetFont();//<-- returns null
	if (pFont)
	{
		//increase the font by 20 %
		LOGFONT lf;
		pFont->GetLogFont(&lf);

		// Increase the font height by 20%.
		// lfHeight is in logical units. A negative value indicates character height.
		// We increase the absolute value to make the font larger.
		if (lf.lfHeight > 0)
		{
			lf.lfHeight = static_cast<LONG>(lf.lfHeight * 1.20);
		}
		else // lf.lfHeight <= 0
		{
			lf.lfHeight = static_cast<LONG>(lf.lfHeight * 1.20); // Increasing the absolute value
		}


		// Create the new font. Delete the old one if it was previously created.
		if (m_listFontLarge.GetSafeHandle())
		{
			m_listFontLarge.DeleteObject();
		}
		m_listFontLarge.CreateFontIndirect(&lf);

		// Set the new font to the list control
		m_list.SetFont(&m_listFontLarge);
	}

	m_list.AddString(_T("Page 1"));
	m_list.AddString(_T("Page 2"));
	m_list.AddString(_T("Page 3"));
	m_list.AddString(_T("Page 4"));
	


	return 0;
}

void Panel_Pages::OnSize(UINT nType, int cx, int cy)
{
	QPanel_With_Preview::OnSize(nType, cx, cy);

	AdjustLayout();

	// Tree control should cover a whole client area:
	AdjustLayout();
}

void Toolbar_Pages::AdjustLayout()
{
	CBCGPToolBar::AdjustLayout();

	((Panel_Pages*)GetParent())->AdjustLayout();
}
