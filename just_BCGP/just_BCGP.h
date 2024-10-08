// just_BCGP.h : main header file for the just_BCGP application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// Cjust_BCGPApp:
// See just_BCGP.cpp for the implementation of this class
//

class Cjust_BCGPApp : public CBCGPWinApp
{
public:
	Cjust_BCGPApp();

	// Override from CBCGPWorkspace
	virtual void PreLoadState();

protected:

	CMultiDocTemplate* m_pDocTemplate;
public:

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	afx_msg void OnFileNewFrame();
	afx_msg void OnFileNew();
	afx_msg void OnFileViewDark();
	afx_msg void OnViewSheets();


	DECLARE_MESSAGE_MAP()


private:
	void Set_Theme_Dark_Or_Light(bool ab_dark);
	bool m_dark;
};

extern Cjust_BCGPApp theApp;
