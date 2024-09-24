#pragma once
#include "afxdialogex.h"


// QDlgOwnerDraw dialog

class QDlgOwnerDraw : public CDialog
{
	DECLARE_DYNAMIC(QDlgOwnerDraw)

public:
	QDlgOwnerDraw(CWnd* pParent = nullptr);   // standard constructor
	virtual ~QDlgOwnerDraw();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QDlgOwnerDraw };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
