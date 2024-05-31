
#pragma once

#include <memory>

class QDlgPagePreview;

class QPanel_With_Preview : public CBCGPDockingControlBar
{
public:
	QPanel_With_Preview();

protected:
	DECLARE_MESSAGE_MAP()

	BOOL m_isPaletteVisible;
	bool m_is_preview_created;
	

	CRect m_guardedArea;//if mouse leaves this area, hide the palette

	void ResizePreview();
	bool IsThisDockedOnLeft(const CRect & l_rectMain, const CRect & l_rectThis) const;
	
	afx_msg void OnTimer(UINT nIDEvent);
	LRESULT OnMouseOverListBoxLayers(WPARAM wParam, LPARAM);

	virtual void ShowPreview(int ai_index)=0;

	void ClosePreview();
	void InitPalette();
};

