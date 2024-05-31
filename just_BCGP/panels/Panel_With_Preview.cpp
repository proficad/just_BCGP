#include "../stdafx.h"
#include "Panel_With_Preview.h"


#include "QListBoxPages.h"


/*==========================================================================*/

QPanel_With_Preview::QPanel_With_Preview()
	:m_isPaletteVisible(false)
	
, m_is_preview_created(false)
{
}

/*==========================================================================*/

BEGIN_MESSAGE_MAP(QPanel_With_Preview, CBCGPDockingControlBar)
ON_WM_TIMER()
ON_MESSAGE(UWM_MOUSE_OVER_LISTBOX_PREVIEW, OnMouseOverListBoxLayers)
END_MESSAGE_MAP()

/*==========================================================================*/

LRESULT QPanel_With_Preview::OnMouseOverListBoxLayers(WPARAM wParam, LPARAM)
{
	
	//if active view is printSymbols, skip
	/* //9
	QPrntSymView *pView = dynamic_cast<QPrntSymView *>(QUtilsMFC::GetActiveView());
	if (NULL != pView)
	{
		return 0;
	}
	*/
	ShowPreview(wParam);

	return 0;
}

/*==========================================================================*/

void QPanel_With_Preview::ResizePreview()
{
	CWnd* pWndMain = AfxGetMainWnd();
	CRect l_rectMain;
	pWndMain->GetWindowRect(l_rectMain);

	CRect l_rectPanel;
	GetWindowRect(l_rectPanel);

	//docked on the left
	CRect l_rectPalette;
	const int li_margin = 10;

	const int PREVIEW_WIDTH = 300;
	const int PREVIEW_HEIGHT = 200;

	l_rectPalette.top = l_rectPanel.top;
	l_rectPalette.bottom = l_rectPalette.top + PREVIEW_HEIGHT;


	if (IsThisDockedOnLeft(l_rectMain, l_rectPanel))
	{
		l_rectPalette.left = l_rectPanel.right + li_margin;
		l_rectPalette.right = l_rectPalette.left + PREVIEW_WIDTH;
		m_guardedArea = l_rectPalette;
		m_guardedArea.left -= l_rectPanel.Width();
	}
	else
	{
		l_rectPalette.right = l_rectPanel.left - li_margin;
		l_rectPalette.left = l_rectPalette.right - PREVIEW_WIDTH;
		m_guardedArea = l_rectPalette;
		m_guardedArea.right += l_rectPanel.Width();

		m_guardedArea = l_rectPanel;
	}


	

	m_isPaletteVisible = TRUE;

	pWndMain->ClientToScreen(&m_guardedArea);
}

/*==========================================================================*/

bool QPanel_With_Preview::IsThisDockedOnLeft(const CRect & l_rectMain, const CRect & l_rectThis) const
{
	const int li_spaceLeft = abs(l_rectMain.left - l_rectThis.left);
	const int li_spaceRight = abs(l_rectMain.right - l_rectThis.right);

	return li_spaceRight > li_spaceLeft;
}

/*==========================================================================*/

void QPanel_With_Preview::OnTimer(UINT)
{

	if (!m_isPaletteVisible)
	{
		return;
	}
	if ((m_guardedArea.left == 0) && (m_guardedArea.top == 0) && (m_guardedArea.right == 0) && (m_guardedArea.bottom == 0))
	{
		return;
	}


	CPoint l_point;
	::GetCursorPos(&l_point);
	ScreenToClient(&l_point);

	CRect l_rect;
	GetClientRect(l_rect);
	bool lb_is_in = l_rect.PtInRect(l_point);
	if (!lb_is_in)
	{
		ClosePreview();
	}

}

/*==========================================================================*/

void QPanel_With_Preview::ClosePreview()
{
	
}

/*==========================================================================*/

void QPanel_With_Preview::InitPalette()
{
	CWnd* pWndParent = AfxGetMainWnd();
	//m_pDlgPreview = std::make_unique<QDlgPagePreview>(pWndParent);

	//m_is_preview_created = QUtilsConvert::BOOL2bool(m_pDlgPreview.get()->Create(IDD_PAGE_PREVIEW));

	/*
	DWORD li_error = ::GetLastError();
	if (!m_is_preview_created)
	{
		int i = 4545;
	}
	*/
}

/*==========================================================================*/
/*==========================================================================*/
/*==========================================================================*/
/*==========================================================================*/
/*==========================================================================*/
