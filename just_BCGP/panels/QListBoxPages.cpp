
#include "../stdafx.h"
#include "QListBoxPages.h"
#include "../resource.h"

/*==========================================================================*/


IMPLEMENT_DYNAMIC(QListBoxPages, CBCGPListBox)


BEGIN_MESSAGE_MAP(QListBoxPages, CBCGPListBox)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

/*==========================================================================*/

QListBoxPages::QListBoxPages()
	:m_lastItem((UINT)-1)
{

}

void QListBoxPages::OnMouseMove(UINT nFlags, CPoint point)
{
	if (GetCount() == 1)//no need to show preview if you have just one page
	{
		return;
	}


	if (this != CWnd::GetFocus())
	{
		SetFocus();
	}

	BOOL lb_outside;
	UINT li_currItem = ItemFromPoint(point, lb_outside);

	if (!lb_outside)
	{
		if (m_lastItem != li_currItem)
		{
	

			m_lastItem = li_currItem;


			NotifyParent(UWM_MOUSE_OVER_LISTBOX_PREVIEW, li_currItem);
			//TRACE(_T("OnMouseMove item %d point %d %d \n"), li_currItem, point.x, point.y);
		}
	}

	CListBox::OnMouseMove(nFlags, point);
}
/*==========================================================================*/
BOOL QListBoxPages::OnMouseWheel(UINT nFlags, short zDelta, CPoint point)
{
	BOOL lb_ret = CListBox::OnMouseWheel(nFlags, zDelta, point);
	ScreenToClient(&point);
	OnMouseMove(nFlags, point);
	return lb_ret;
}

/*==========================================================================*/

void QListBoxPages::NotifyParent(int ai_msg, UINT li_currItem)
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		pWnd->PostMessage(ai_msg, li_currItem, 0);
	}
}

/*==========================================================================*/
void QListBoxPages::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_F2)
	{
		int li_currentItem = GetCurSel();
		if (LB_ERR != li_currentItem)
		{
				
			CWnd* pWnd = this->GetParent();
			if (pWnd)
			{
				NMHDR l_nmhdr;
				l_nmhdr.hwndFrom = m_hWnd;
				l_nmhdr.idFrom = GetDlgCtrlID();
				//9l_nmhdr.code = RENAME_LISTBOX_ITEM;
				pWnd->SendMessage(WM_NOTIFY, 0, (LPARAM) &l_nmhdr);
			}
		}

	}


	CBCGPListBox::OnKeyDown(nChar, nRepCnt, nFlags);
}
/*==========================================================================*/
