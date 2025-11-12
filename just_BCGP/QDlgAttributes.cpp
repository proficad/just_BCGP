// QDlgAttributes.cpp : implementation file
//

#include "stdafx.h"
#include "just_BCGP.h"
#include "afxdialogex.h"
#include "QDlgAttributes.h"


// QDlgAttributes dialog

IMPLEMENT_DYNAMIC(QDlgAttributes, CBCGPDialog)

QDlgAttributes::QDlgAttributes(CWnd* pParent /*=nullptr*/)
	: CBCGPDialog(IDD_QDlgAttributes, pParent)
{
	EnableLayout();
}

QDlgAttributes::~QDlgAttributes()
{
}

void QDlgAttributes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QDlgAttributes, CBCGPDialog)
	ON_NOTIFY(NM_CLICK, (UINT)-1, OnNMClick)
	ON_WM_RBUTTONDOWN()
	//ON_REGISTERED_MESSAGE(BCGPGN_SELCHANGED, OnGridSelChanged)
END_MESSAGE_MAP()


// QDlgAttributes message handlers


BOOL QDlgAttributes::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();



	CWaitCursor wait;

	m_wndGrid.CreateOnPlaceHolder(this, MY_GRID, MY_GRID, WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, TRUE /* Destroy placeholder */);
	Resize_Dialog();
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


	for (int i = 0; i < 100; i++)
	{
		m_wndGrid.AddRow();

	}
	m_wndGrid.AddRow();
	auto l_last = m_wndGrid.GetRow(m_wndGrid.GetRowCount() - 1);
	l_last->GetItem(0)->SetValue(_T("Last Row:"));
	l_last->GetItem(2)->SetValue(_T("Middle Col"));


	CBCGPGridCheckItem* pCheckItem = new CBCGPGridCheckItem(TRUE);
	l_last->ReplaceItem(4, pCheckItem, TRUE);

	srand((unsigned)time(NULL));


	BOOL lb_result = m_wndGrid.SetCurSel(CBCGPGridItemID(0, 1), SM_SINGLE_ITEM);
	CBCGPGridRow* pSelRow = m_wndGrid.GetCurSel();




	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void QDlgAttributes::OnRButtonDown(UINT nFlags, CPoint point)
{

	CBCGPDialog::OnRButtonDown(nFlags, point);
}

void QDlgAttributes::OnNMClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	ShowContextMenu();

}

BOOL QDlgAttributes::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	NMHDR* pNMHDR = (NMHDR*)(lParam);
	if (pNMHDR != NULL && pNMHDR->code == BCGPGN_SELCHANGED && pNMHDR->hwndFrom == m_wndGrid.GetSafeHwnd())
	{
		BCGPGRID_NOTIFICATION* pII = (BCGPGRID_NOTIFICATION*)pNMHDR;
		if (pII == nullptr)
		{
			return 0;
		}

		const bool lb_is_selecting = (1 == pII->lParam);
		if (!lb_is_selecting)
		{
			return 0;
		}

		CBCGPGridRow* pRow = m_wndGrid.GetRow(pII->nRow);
		if (pRow == nullptr)
		{
			return 0;
		}

		ASSERT_VALID(pRow);


		* pResult = 0L;
		return TRUE;
	}

	return CBCGPDialog::OnNotify(wParam, lParam, pResult);
}

LRESULT QDlgAttributes::OnGridSelChanged(WPARAM, LPARAM lp)
{
	BCGPGRID_NOTIFICATION* pInfo = (BCGPGRID_NOTIFICATION*)lp;

	if (pInfo == nullptr)
	{
		return 0;
	}

	CBCGPGridRow* pRow = m_wndGrid.GetRow(pInfo->nRow);// pInfo->nRow is always 0
	if (pRow == nullptr)
	{
		return 0;
	}


	if (pRow->GetItemCount() == 0)
	{
		return 0;
	}

	CBCGPGridItem* pItem = pRow->GetItem(0);// here it crashes
	if (pItem == nullptr)
	{
		return 0;
	}


	return 0;
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

void QDlgAttributes::Resize_Dialog()
{
	CBCGPStaticLayout* pLayout = (CBCGPStaticLayout*)GetLayout();
	if (pLayout != nullptr)
	{
		pLayout->AddAnchor(IDOK, CBCGPStaticLayout::e_MoveTypeBoth, CBCGPStaticLayout::e_SizeTypeNone);
		pLayout->AddAnchor(IDCANCEL, CBCGPStaticLayout::e_MoveTypeBoth, CBCGPStaticLayout::e_SizeTypeNone);
		
		pLayout->AddAnchor(MY_GRID, CBCGPStaticLayout::e_MoveTypeNone, CBCGPStaticLayout::e_SizeTypeBoth);
	}
}
