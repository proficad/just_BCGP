#pragma once
#include <BCGPDialog.h>
#include <memory>
#include <vector>

#include "Resource.h"


class QTranslator;
class QCables;
class QSxeDoc;
class MyDoc;
class QBillColumn;
class QConfRepCols;



class QDlgCableManager : public CBCGPDialog
{
	class CMyGridCtrl : public CBCGPGridCtrl
	{
	public:

		void ExpandSelectionToWholeRows(BOOL bRedraw = TRUE);
		//void OnSelChanged()
	};


	DECLARE_DYNAMIC(QDlgCableManager)

public:

	QDlgCableManager(CWnd* pParent = NULL);   // standard constructor
	~QDlgCableManager();

	bool IsReady();
	static void TryLoad(MyDoc* pDoc);
	void OnClose();


// Dialog Data
	enum { IDD = IDD_DLG_CABLE_MANAGER };

protected:
	void DoDataExchange(CDataExchange* pDX) override;    // DDX/DDV support
	BOOL OnInitDialog() override;
	void ResetOldValue();
	void SetupGrids();


	DECLARE_MESSAGE_MAP()


private:
	

	CMyGridCtrl m_grid_cables;
	CMyGridCtrl m_grid_wires;


	QSxeDoc* m_doc;

	std::vector<std::shared_ptr<QBillColumn>> m_columns;

	static QDlgCableManager* m_staticList;


	void SetupGrid(CMyGridCtrl& pGrid, bool ab_cables);
	


	afx_msg void OnGetMinMaxInfo( MINMAXINFO* lpMMI );

	struct {int m_row=0; int m_col; CString m_text; } m_old_value;
	bool m_grids_setup;

	void Resize_Dialog();
};
