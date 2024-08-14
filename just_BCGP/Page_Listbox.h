#pragma once
#include "afxdialogex.h"


// Page_Listbox dialog

class Page_Listbox : public CPropertyPage
{
	DECLARE_DYNAMIC(Page_Listbox)

public:
	Page_Listbox(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Page_Listbox();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LISTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
