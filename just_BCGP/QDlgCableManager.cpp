// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// QDlgCableManager.cpp : implementation file
//

#include "stdafx.h"
#include "QDlgCableManager.h"

#include <vector>


#include "Resource.h"


//minimum dimensions of the dialog
const int MIN_DLG_WIDTH = 500;
const int MIN_DLG_HEIGHT = 500;


QDlgCableManager* QDlgCableManager::m_staticList =0;

IMPLEMENT_DYNAMIC(QDlgCableManager, CBCGPDialog)

QDlgCableManager::QDlgCableManager(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(QDlgCableManager::IDD, pParent)
	, m_doc(nullptr)
	,m_grids_setup(false)
{
	m_staticList = this;

	ResetOldValue();

	EnableVisualManagerStyle(TRUE, TRUE);
	EnableLayout();
}


QDlgCableManager::~QDlgCableManager()
{
	m_staticList = 0;
}

void QDlgCableManager::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);

}


BEGIN_MESSAGE_MAP(QDlgCableManager, CBCGPDialog)


	ON_WM_CLOSE()
	/*
	ON_NOTIFY(GVN_BEGINLABELEDIT, IDC_GRID_CABLES, OnGridStartEdit)
	ON_NOTIFY(GVN_ENDLABELEDIT, IDC_GRID_CABLES, OnGridEndEdit)

	ON_REGISTERED_MESSAGE(BCGM_GRID_SEL_CHANGED, OnSelChanged)

	ON_NOTIFY(GVN_BEGINLABELEDIT, IDC_GRID_WIRES, OnGridEditWire_Start)
	ON_NOTIFY(GVN_ENDLABELEDIT, IDC_GRID_WIRES, OnGridEditWire_End)
	*/
	
END_MESSAGE_MAP()


BOOL QDlgCableManager::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();


	// this function breaks the resizing of the grids
	SetupGrids();


	Resize_Dialog();


	return TRUE;
}


void QDlgCableManager::SetupGrid(CMyGridCtrl& pGrid, bool ab_cables )
{
	const UINT li_grid_id = ab_cables ? IDC_GRID_CABLES : IDC_GRID_WIRES;

	pGrid.CreateOnPlaceHolder(this, li_grid_id, li_grid_id, WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, TRUE);
	pGrid.EnableHeader(TRUE, BCGP_GRID_HEADER_MOVE_ITEMS);
	pGrid.EnableInvertSelOnCtrl();


	pGrid.SetVisualManagerColorTheme(TRUE);
	pGrid.SetScrollBarsStyle(CBCGPScrollBar::BCGP_SBSTYLE_VISUAL_MANAGER);


	const CString strNoContent(L"no data");

	pGrid.SetNoContentLabel(strNoContent);
}


void QDlgCableManager::ResetOldValue()
{
	m_old_value.m_col = -1;
	m_old_value.m_row = -1;
	m_old_value.m_text = _T("");
}


void QDlgCableManager::Resize_Dialog()
{
	CBCGPStaticLayout* pLayout = (CBCGPStaticLayout*)GetLayout();
	if (pLayout != nullptr)
	{
		pLayout->AddAnchor(IDC_GRID_CABLES, CBCGPStaticLayout::e_MoveTypeNone, CBCGPStaticLayout::e_SizeTypeBoth);
		pLayout->AddAnchor(IDC_GRID_WIRES, CBCGPStaticLayout::e_MoveTypeVert, CBCGPStaticLayout::e_SizeTypeHorz);
	}
}



void QDlgCableManager::SetupGrids()
{
	SetupGrid(m_grid_cables, true);
	SetupGrid(m_grid_wires, false);
}



void QDlgCableManager::OnClose()
{
	ShowWindow(SW_HIDE);
}

