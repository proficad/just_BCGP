#include "stdafx.h"
#include "QStyleGridItem.h"

void QStyleGridItem::OnDrawValue(CDC* pDC, CRect a_rect)
{
	CBrush l_brush;
	l_brush.CreateSolidBrush(RGB(255, 0, 0));
	CGdiObject* pOld = pDC->SelectObject(&l_brush);


	CRect l_rect = a_rect;
	l_rect.DeflateRect(3, 3);

	pDC->Ellipse(l_rect);

	pDC->SelectObject(pOld);

}