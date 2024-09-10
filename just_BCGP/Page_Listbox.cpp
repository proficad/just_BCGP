// Page_Listbox.cpp : implementation file
//

#include "stdafx.h"
#include "just_BCGP.h"
#include "afxdialogex.h"
#include "Page_Listbox.h"


// Page_Listbox dialog

IMPLEMENT_DYNAMIC(Page_Listbox, CBCGPPropertyPage)

Page_Listbox::Page_Listbox(CWnd* pParent /*=nullptr*/)
	: CBCGPPropertyPage(IDD_DLG_LISTBOX)
{
	EnableVisualManagerStyle(TRUE);
	
}

Page_Listbox::~Page_Listbox()
{
}

void Page_Listbox::DoDataExchange(CDataExchange* pDX)
{
	CBCGPPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTBOX, m_listbox);
}


BEGIN_MESSAGE_MAP(Page_Listbox, CBCGPPropertyPage)
END_MESSAGE_MAP()


// Page_Listbox message handlers


BOOL Page_Listbox::OnInitDialog()
{
	CBCGPPropertyPage::OnInitDialog();

	const int li_index = m_listbox.AddString(L"test");
	m_listbox.SetItemColorBar(li_index, RGB(255,0,0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
