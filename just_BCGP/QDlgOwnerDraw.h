#pragma once
#include "afxdialogex.h"


class OwnerDraw_Grid : public CBCGPGridCtrl
{
public:
	void UpdateVirtualGrid(); // demonstares how to update the grid in virtual mode
	void ExpandSelectionToWholeRows(BOOL bRedraw = TRUE);
};


// QDlgOwnerDraw dialog

class QDlgOwnerDraw : public CBCGPDialog
{
	DECLARE_DYNAMIC(QDlgOwnerDraw)

public:
	QDlgOwnerDraw(CWnd* pParent = nullptr);   // standard constructor



private:
	OwnerDraw_Grid m_wndGrid;


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QDlgOwnerDraw };
#endif

	void Resize_Dialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
