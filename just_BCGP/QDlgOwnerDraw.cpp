// QDlgOwnerDraw.cpp : implementation file
//

#include "stdafx.h"
#include "just_BCGP.h"
#include "afxdialogex.h"
#include "QDlgOwnerDraw.h"

#include "QStyleGridItem.h"


// QDlgOwnerDraw dialog

IMPLEMENT_DYNAMIC(QDlgOwnerDraw, CBCGPDialog)

QDlgOwnerDraw::QDlgOwnerDraw(CWnd* pParent /*=nullptr*/)
	: CBCGPDialog(IDD_QDlgOwnerDraw, pParent)
{

}



void QDlgOwnerDraw::Resize_Dialog()
{
	CBCGPStaticLayout* pLayout = (CBCGPStaticLayout*)GetLayout();
	if (pLayout != nullptr)
	{
		pLayout->AddAnchor(IDOK, CBCGPStaticLayout::e_MoveTypeBoth, CBCGPStaticLayout::e_SizeTypeNone);
		pLayout->AddAnchor(IDCANCEL, CBCGPStaticLayout::e_MoveTypeBoth, CBCGPStaticLayout::e_SizeTypeNone);

		pLayout->AddAnchor(MY_GRID, CBCGPStaticLayout::e_MoveTypeNone, CBCGPStaticLayout::e_SizeTypeBoth);
	}
}


void QDlgOwnerDraw::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QDlgOwnerDraw, CDialog)
END_MESSAGE_MAP()


// QDlgOwnerDraw message handlers


BOOL QDlgOwnerDraw::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();

	m_wndGrid.CreateOnPlaceHolder(this, MY_GRID, MY_GRID, WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, TRUE /* Destroy placeholder */);
	Resize_Dialog();
	m_wndGrid.EnableHeader(TRUE, BCGP_GRID_HEADER_MOVE_ITEMS);
	m_wndGrid.EnableInvertSelOnCtrl();

	m_wndGrid.InsertColumn(0, _T("A"), globalUtils.ScaleByDPI(300, this));



	auto l_row = m_wndGrid.CreateRow(1);

	QStyleGridItem* l_item_style = new QStyleGridItem();
	l_row->ReplaceItem(0, l_item_style);

	l_item_style->AllowEdit(FALSE);


	l_row->GetItem(0)->SetValue(L"hi");
	m_wndGrid.AddRow(l_row);




	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
