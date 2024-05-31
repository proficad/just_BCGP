#pragma once

#include "../resource.h"

#include "../paint/QCanvas.h"
#include "../paint/QCanvasPainter.h"

class QReportPage;


/*!
 * \class QDlgPagePreview
 *
 * \brief For preview of a layer or a page (when hovering in panel of layers or pages).
 * Added in version 10.2.
 *
 */
class QDlgPagePreview : public CDialog, private QCanvasPainter
{
public:
	QDlgPagePreview(CWnd* pParent);



	enum {IDD = IDD_PAGE_PREVIEW};

	void Reload(preview_type a_preview_type, int ai_index);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	void OnDraw(CDC* pDC, const CRect & rect);
	void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()



private:
	QCanvas	m_canvas;

	int m_index;
	preview_type m_preview_type;
	static void Draw_Preview_Report_Page(CDC* pDC, CRect a_rect, std::shared_ptr<QReportPage> a_pReportPage);
};

