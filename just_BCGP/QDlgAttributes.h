#pragma once
#include "afxdialogex.h"


// QDlgAttributes dialog
class CMyGridCtrl : public CBCGPGridCtrl
{
public:
	void UpdateVirtualGrid(); // demonstares how to update the grid in virtual mode
	void ExpandSelectionToWholeRows(BOOL bRedraw = TRUE);
};


class QDlgAttributes : public CBCGPDialog
{
	DECLARE_DYNAMIC(QDlgAttributes)

public:
	QDlgAttributes(CWnd* pParent = nullptr);   // standard constructor
	virtual ~QDlgAttributes();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QDlgAttributes };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CMyGridCtrl	m_wndGrid;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT QDlgAttributes::OnGridSelChanged(WPARAM, LPARAM lp);

	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);//}}AFX_VIRTUAL

private:
	void ShowContextMenu();
	void Resize_Dialog();
};
