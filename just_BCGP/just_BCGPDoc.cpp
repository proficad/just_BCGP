// just_BCGPDoc.cpp : implementation of the Cjust_BCGPDoc class
//

#include "stdafx.h"
#include "just_BCGP.h"

#include "just_BCGPDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cjust_BCGPDoc

IMPLEMENT_DYNCREATE(Cjust_BCGPDoc, CDocument)

BEGIN_MESSAGE_MAP(Cjust_BCGPDoc, CDocument)
END_MESSAGE_MAP()


// Cjust_BCGPDoc construction/destruction

Cjust_BCGPDoc::Cjust_BCGPDoc()
{
	// TODO: add one-time construction code here

}

Cjust_BCGPDoc::~Cjust_BCGPDoc()
{
}

BOOL Cjust_BCGPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// Cjust_BCGPDoc serialization

void Cjust_BCGPDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// Cjust_BCGPDoc diagnostics

#ifdef _DEBUG
void Cjust_BCGPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cjust_BCGPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cjust_BCGPDoc commands
