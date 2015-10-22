// demo1Dlg.h : header file
//

#if !defined(AFX_DEMO1DLG_H__BF9B7E78_E245_11D4_8AE5_0010A4E6127F__INCLUDED_)
#define AFX_DEMO1DLG_H__BF9B7E78_E245_11D4_8AE5_0010A4E6127F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "mssoap1.h"

/////////////////////////////////////////////////////////////////////////////
// CDemo1Dlg dialog

class CDemo1Dlg : public CDialog
{
// Construction
public:
	CDemo1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDemo1Dlg)
	enum { IDD = IDD_DEMO1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo1Dlg)
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemo1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDivide();
	afx_msg void OnSubtract();
	afx_msg void OnMultiply();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	CString m_strService;
	CString m_strA;
	CString m_strB;
	ISOAPClient * m_pClient;
private:
	void SetResult(double dRes);
	void SetOp(CString strOp);
	BOOL GetAandB();
	BOOL Connect();
	DISPID GetDispid(CString strFxName);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO1DLG_H__BF9B7E78_E245_11D4_8AE5_0010A4E6127F__INCLUDED_)
