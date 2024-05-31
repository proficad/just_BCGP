// QDlgAttributes.cpp : implementation file
//

#include "stdafx.h"
#include "just_BCGP.h"
#include "afxdialogex.h"
#include "QDlgAttributes.h"


// QDlgAttributes dialog

IMPLEMENT_DYNAMIC(QDlgAttributes, CDialog)

QDlgAttributes::QDlgAttributes(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_QDlgAttributes, pParent)
{

}

QDlgAttributes::~QDlgAttributes()
{
}

void QDlgAttributes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QDlgAttributes, CDialog)
	ON_NOTIFY(NM_CLICK, (UINT)-1, OnNMClick)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// QDlgAttributes message handlers


BOOL QDlgAttributes::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWaitCursor wait;

	m_wndGrid.CreateOnPlaceHolder(this, MY_GRID, (UINT)-1, WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER);
	m_wndGrid.EnableHeader(TRUE, BCGP_GRID_HEADER_MOVE_ITEMS);
	m_wndGrid.EnableInvertSelOnCtrl();

	/*
	if (theApp.m_Options.m_bUseVisualTheme)
	{
		m_wndGrid.SetVisualManagerColorTheme(TRUE);
		m_wndGrid.SetScrollBarsStyle(CBCGPScrollBar::BCGP_SBSTYLE_VISUAL_MANAGER);
	}
	*/

	//m_wndGrid.SetReadOnly();

	m_wndGrid.InsertColumn(0, _T("A"), globalUtils.ScaleByDPI(70, this));
	m_wndGrid.InsertColumn(1, _T("B"), globalUtils.ScaleByDPI(50, this));
	m_wndGrid.InsertColumn(2, _T("C"), globalUtils.ScaleByDPI(50, this));
	m_wndGrid.InsertColumn(3, _T("D"), globalUtils.ScaleByDPI(50, this));
	m_wndGrid.InsertColumn(4, _T("E"), globalUtils.ScaleByDPI(50, this));

	CString strNoContent(L"no data");

	m_wndGrid.SetNoContentLabel(strNoContent);


	auto l_row = m_wndGrid.CreateRow(5);
	l_row->GetItem(1)->SetValue(_T("Switch:"));
	m_wndGrid.AddRow(l_row);



	m_wndGrid.AddRow();
	m_wndGrid.AddRow();
	auto l_last = m_wndGrid.GetRow(m_wndGrid.GetRowCount() - 1);
	l_last->GetItem(0)->SetValue(_T("Last Row:"));
	l_last->GetItem(2)->SetValue(_T("Middle Col"));


	CBCGPGridCheckItem* pCheckItem = new CBCGPGridCheckItem(TRUE);
	l_last->ReplaceItem(4, pCheckItem, TRUE);

	srand((unsigned)time(NULL));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void QDlgAttributes::OnRButtonDown(UINT nFlags, CPoint point)
{

	CDialog::OnRButtonDown(nFlags, point);
}

void QDlgAttributes::OnNMClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	ShowContextMenu();

}

void QDlgAttributes::ShowContextMenu()
{
	CMenu menu;
	menu.LoadMenu(IDR_CONTEXT_MENU);

	CMenu* pPopup = menu.GetSubMenu(0);
	ASSERT(pPopup != NULL);

	CWnd* pWndPopupOwner = this;

	if (pWndPopupOwner != NULL)
	{
		CPoint pt;
		::GetCursorPos(&pt);

		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, pWndPopupOwner);
	}
}
