#pragma once


// QListBoxWithKeyboard
#define UWM_DELETE_SELECTEDITEM (WM_APP + 9)


typedef struct tagLB_DROPPED {
	NMHDR hdr;
	int   iSource;
	int   iTarget;
} LB_DROPPED;


class QListBoxWithKeyboard : public CBCGPListBox
{
	DECLARE_DYNAMIC(QListBoxWithKeyboard)

public:
	QListBoxWithKeyboard();
	virtual ~QListBoxWithKeyboard();

//	BOOL OnEraseBkgnd(CDC* pDC);

protected:
	DECLARE_MESSAGE_MAP()
	//virtual void Dropped(int nSrcIndex,	CPoint pt);


public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
//	CBitmap bitmapBkgnd;



};


