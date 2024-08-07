// workspacebar.h : interface of the Panel_Symbols class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class Panel_Symbols : public CBCGPDockingControlBar
{
public:
	Panel_Symbols();

// Attributes
protected:
	CBCGPButton m_btn_search;
	CBCGPTreeCtrl m_wndTree;

	void On_Search_Symbols();
	void On_Update_Search_Symbols(CCmdUI* pCmdUI);


// Operations
public:

// Overrides

// Implementation
public:
	virtual ~Panel_Symbols();

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
