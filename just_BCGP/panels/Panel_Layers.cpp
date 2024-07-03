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

	m_list.m_bVisualManagerStyle = TRUE;
	m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_HSCROLL | WS_VSCROLL | LBS_HASSTRINGS | LBS_NOTIFY | LBS_OWNERDRAWFIXED,
		CRect(0, 0, 0, 0), this, IDC_LIST_OF_OBJECTS);


	m_list.AddString(L"one");
	m_list.AddString(L"two");
	m_list.AddString(L"three");

	return 0;
}

void Panel_Layers::OnSize(UINT nType, int cx, int cy)
{
	QPanel_With_Preview::OnSize(nType, cx, cy);

	// Tree control should cover a whole client area:
	m_list.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
}
