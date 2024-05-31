#include "../stdafx.h"
#include "QDlgPagePreview.h"

#include "../QSxeDoc.h"
#include "../QPpdDoc.h"
#include "../QUtilsMFC.h"
#include "../../common/QDocSxe.h"
#include "../../common/QDocPpd.h"
#include "../../common/QReportPage.h"
#include "../../common/QOnePage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE

static char THIS_FILE[] = __FILE__;
#endif


QDlgPagePreview::QDlgPagePreview(CWnd* pParent /*=NULL*/)
	:CDialog(QDlgPagePreview::IDD, pParent)
	,m_preview_type(pt_page)
	,m_index(0)
{
}


void QDlgPagePreview::Reload(preview_type a_preview_type, int ai_index)
{
	if (
			(m_preview_type == a_preview_type) 
					&& 
			(m_index == ai_index)
		)
	{
		return;//no need to refresh preview after each small movement on the same item
	}
	
	m_preview_type = a_preview_type;
	m_index = ai_index;
		
	m_canvas.Invalidate(TRUE);
}


void QDlgPagePreview::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(QDlgPalette)
	DDX_Control(pDX, IDC_CANVAS, m_canvas);

	//}}AFX_DATA_MAP
}


BOOL QDlgPagePreview::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_canvas.SetCanvasPainter(this);

	return TRUE;
}




BEGIN_MESSAGE_MAP(QDlgPagePreview, CDialog)
	//{{AFX_MSG_MAP(QDlgPalette)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()


	//}}AFX_MSG_MAP

END_MESSAGE_MAP()





void QDlgPagePreview::OnDraw(CDC* pDC, const CRect & )
{
	CRect l_rect_window;
	GetClientRect(l_rect_window);
	pDC->FillSolidRect(l_rect_window, RGB(255, 195, 11));

	const int MARGIN_1 = 4;
	l_rect_window.InflateRect(-MARGIN_1, -MARGIN_1);
	pDC->FillSolidRect(l_rect_window, RGB(255, 255, 255));

	const int MARGIN_2 = 6;
	l_rect_window.InflateRect(-MARGIN_2, -MARGIN_2);



	QSxeDoc* pSxeDoc = dynamic_cast<QSxeDoc*>(QUtilsMFC::GetActiveDoc());
	if (pSxeDoc)
	{
		QDocSxe* pDocSxe = nullptr;

		if (m_preview_type == pt_page)
		{
			pDocSxe = pSxeDoc->GetPageAt(m_index);
			if (nullptr == pDocSxe)
			{
				QOnePage pOnePage = pSxeDoc->GetPages()->GetAt(m_index);
				if (pOnePage.m_pReportPage)
				{
					Draw_Preview_Report_Page(pDC, l_rect_window, pOnePage.m_pReportPage);
				}
			}
		}
		else // layer
		{
			pDocSxe = pSxeDoc->GetPageAt(pSxeDoc->GetCurrentPage());
		}

		if (pDocSxe)
		{
			pDocSxe->DrawPreview(pDC, l_rect_window, MARGIN_1, MARGIN_2, m_index, m_preview_type);
		}
	}
	else
	{
		QPpdDoc* pPpdDoc = dynamic_cast<QPpdDoc*>(QUtilsMFC::GetActiveDoc());
		if (pPpdDoc)
		{
			QDocPpd* pDocPpd = pPpdDoc->GetDocPpd();
			if (pDocPpd)
			{
				pDocPpd->DrawPreview(pDC, l_rect_window, MARGIN_1, MARGIN_2, m_index, m_preview_type);

			}
			
		}
	}
}


void QDlgPagePreview::Draw_Preview_Report_Page(CDC* pDC, CRect a_rect, std::shared_ptr<QReportPage> a_pReportPage)
{
	CFont l_font;
	if (l_font.CreatePointFont(200, _T("Arial"), pDC))
	{
		pDC->SetTextColor(RGB(0, 0, 127));
		CFont* l_font_old = pDC->SelectObject(&l_font);
		pDC->DrawText(a_pReportPage->GetName(), a_rect, DT_CENTER | DT_WORDBREAK);
		pDC->SelectObject(l_font_old);
	}
}


void QDlgPagePreview::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	CRect l_rect_dlg;
	GetClientRect(l_rect_dlg);

	if (::IsWindow(m_canvas.GetSafeHwnd()))
	{
		CRect l_rect_canvas;
		m_canvas.GetClientRect(l_rect_canvas);
		l_rect_dlg.DeflateRect(0, 0);
		m_canvas.MoveWindow(l_rect_dlg, TRUE);
	}

}
