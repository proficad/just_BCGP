// workspacebar.h : interface of the Panel_Layers class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class Panel_Layers : public CBCGPDockingControlBar
{
public:
	Panel_Layers();

// Attributes
protected:
	CBCGPTreeCtrl m_wndTree;

// Operations
public:

// Overrides

// Implementation
public:
	virtual ~Panel_Layers();

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
