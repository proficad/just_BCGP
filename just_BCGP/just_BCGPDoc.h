// just_BCGPDoc.h : interface of the Cjust_BCGPDoc class
//


#pragma once


class Cjust_BCGPDoc : public CDocument
{
protected: // create from serialization only
	Cjust_BCGPDoc();
	DECLARE_DYNCREATE(Cjust_BCGPDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~Cjust_BCGPDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


