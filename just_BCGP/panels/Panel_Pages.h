// workspacebar.h : interface of the Panel_Pages class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class Panel_Pages : public CBCGPDockingControlBar
{
public:
	Panel_Pages();

// Attributes
protected:
	CBCGPTreeCtrl m_wndTree;

// Operations
public:

// Overrides

// Implementation
public:
	virtual ~Panel_Pages();

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
