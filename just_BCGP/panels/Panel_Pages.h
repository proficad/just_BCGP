// workspacebar.h : interface of the Panel_Pages class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class Toolbar_Pages : public CBCGPToolBar
{
public:
	// All commands should be routed via owner window, not via frame:
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CBCGPToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
	}

	// Toolbar should't appear on the customization list
	virtual BOOL AllowShowOnList() const { return FALSE; }
	virtual void AdjustLayout();
};


class Panel_Pages : public CBCGPDockingControlBar
{
public:
	Panel_Pages();
	virtual void AdjustLayout();

// Attributes
protected:
	Toolbar_Pages m_wndToolBar;
	CBCGPTreeCtrl m_wndTree;

	void Create_Toolbar();

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
