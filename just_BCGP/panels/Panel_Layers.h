// workspacebar.h : interface of the Panel_Layers class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Panel_With_Preview.h"
#include "QListBoxWithKeyboard.h"

class Panel_Layers : public QPanel_With_Preview
{
public:
	Panel_Layers();
	void ShowPreview(int ai_index) override;
// Attributes
protected:
	QListBoxWithKeyboard m_list;

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
