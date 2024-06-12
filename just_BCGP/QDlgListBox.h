#pragma once
#include "afxdialogex.h"


// QDlgListBox dialog

class QDlgListBox : public CBCGPDialog
{
	DECLARE_DYNAMIC(QDlgListBox)
	afx_msg void OnRClick(NMHDR* pNMHDR, LRESULT* pResult);


public:
	QDlgListBox(CWnd* pParent = nullptr);   // standard constructor
	virtual ~QDlgListBox();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QDlgListBox };
#endif

	void Fill_List_Box();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrl_list;
	virtual BOOL OnInitDialog();
private:
	void ShowContextMenu();
};
