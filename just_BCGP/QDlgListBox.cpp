// QDlgListBox.cpp : implementation file
//

#include "stdafx.h"
#include "just_BCGP.h"
#include "afxdialogex.h"
#include "QDlgListBox.h"


// QDlgListBox dialog

IMPLEMENT_DYNAMIC(QDlgListBox, CBCGPDialog)

void QDlgListBox::OnRClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	ShowContextMenu();
}

QDlgListBox::QDlgListBox(CWnd* pParent /*=nullptr*/)
	: CBCGPDialog(IDD_QDlgListBox, pParent)
{

}

QDlgListBox::~QDlgListBox()
{
}

void QDlgListBox::Fill_List_Box()
{
	//add some items to the list box
	int nColumnCount =3;
	CString strText;

	// Insert 10 items in the list view control.
	for (int i = 0; i < 10; i++)
	{
		strText.Format(TEXT("item %d"), i);

		// Insert the item, select every other item.
		m_ctrl_list.InsertItem(LVIF_TEXT | LVIF_STATE, i, strText,
			(i % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED, 0, 0);

		// Initialize the text of the subitems.
		for (int j = 1; j < nColumnCount; j++)
		{
			strText.Format(TEXT("sub-item %d %d"), i, j);
			m_ctrl_list.SetItemText(i, j, strText);
		}
	}
}

void QDlgListBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ctrl_list);
}


BEGIN_MESSAGE_MAP(QDlgListBox, CBCGPDialog)
	ON_NOTIFY(NM_RCLICK, IDC_LIST2, OnRClick)
END_MESSAGE_MAP()


// QDlgListBox message handlers


BOOL QDlgListBox::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();

	Fill_List_Box();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void QDlgListBox::ShowContextMenu()
{
	CMenu l_menu;
	l_menu.CreatePopupMenu();

	l_menu.AppendMenu(MF_STRING, ID_FILE_PRINT, L"item 1");
	l_menu.AppendMenu(MF_STRING, ID_FILE_PRINT_PREVIEW, L"item 2");
	l_menu.AppendMenu(MF_STRING, ID_FILE_PRINT_DIRECT, L"item 3");

	CPoint l_point;
	if (!GetCursorPos(&l_point))
	{
		return;
	}



	GetWorkspace()->GetContextMenuManager()->ShowPopupMenu(l_menu, l_point.x, l_point.y, GetParent());
}
