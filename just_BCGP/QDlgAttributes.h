#pragma once
#include "afxdialogex.h"


// QDlgAttributes dialog
class CMyGridCtrl : public CBCGPGridCtrl
{
public:
	void UpdateVirtualGrid(); // demonstares how to update the grid in virtual mode
	void ExpandSelectionToWholeRows(BOOL bRedraw = TRUE);
};


class QDlgAttributes : public CDialog
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
};
