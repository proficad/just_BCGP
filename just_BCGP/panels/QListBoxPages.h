#pragma once

#define UWM_MOUSE_OVER_LISTBOX_PREVIEW (WM_APP + 14)
#include <BCGPListBox.h>


class QListBoxPages : public CBCGPListBox
{

public:
	typedef struct tagLB_DROPPED {
		NMHDR hdr;
		int   iSource;
		int   iTarget;
	} LB_DROPPED;



	DECLARE_DYNAMIC(QListBoxPages)

	QListBoxPages();

protected:
	void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);


	DECLARE_MESSAGE_MAP()

private:
	UINT m_lastItem;
	void NotifyParent(int ai_msg, UINT li_currItem);
	
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};
