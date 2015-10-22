// demo1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo1.h"
#include "demo1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//TODO: Change to the relevant Web Service path and file name
#define SVCNAME "http://www.myserver.com/SoapSamples/CalcVB.wsdl"
#define DEFA "15"
#define DEFB "5"

/////////////////////////////////////////////////////////////////////////////
// CDemo1Dlg dialog

CDemo1Dlg::CDemo1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemo1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemo1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strService = "";
	m_strA = "";
	m_strB = "";
	m_pClient = NULL;
}

BEGIN_MESSAGE_MAP(CDemo1Dlg, CDialog)
	//{{AFX_MSG_MAP(CDemo1Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DIVIDE, OnDivide)
	ON_BN_CLICKED(IDC_SUBTRACT, OnSubtract)
	ON_BN_CLICKED(IDC_MULTIPLY, OnMultiply)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo1Dlg message handlers
BOOL CDemo1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//Give the edit boxes some default values
	CWnd * pWnd = GetDlgItem(IDC_SERVICE);
	if(pWnd) pWnd->SetWindowText(SVCNAME);
	pWnd = NULL;
	pWnd = GetDlgItem(IDC_EDITA);
	if(pWnd) pWnd->SetWindowText(DEFA);
	pWnd = NULL;
	pWnd = GetDlgItem(IDC_EDITB);
	if(pWnd) pWnd->SetWindowText(DEFB);
		
	return TRUE;  // return TRUE  unless you set the focus to a control
}
/////////////////////////////////////////////////////////////////////////////
void CDemo1Dlg::OnDestroy() 
{
	//On destroying the dialog need to free the SoapClient pointer
	if(m_pClient)
	{
		m_pClient->ReleaseDispatch();
		delete m_pClient;
		m_pClient = NULL;
	}

	CDialog::OnDestroy();
	
}
/////////////////////////////////////////////////////////////////////////////
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CDemo1Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemo1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/////////////////////////////////////////////////////////////////////////////
void CDemo1Dlg::OnAdd() 
{
	double dRes = 0;
	DISPID dispid;

	//Connect to server
	if(Connect())
	{
		//Get the values
		if(GetAandB())
		{
			//Set the operation type symbol
			SetOp("+");
			//Get the dispatch id for the function we want to use
			dispid = GetDispid("Add");
			//Call the function
			dRes = m_pClient->Add(atof(m_strA), atof(m_strB), dispid);
			//Set the result in the dialog
			SetResult(dRes);
		}
	}
	else
		MessageBox("Unable to connect to Web Service","Error...",MB_OK | MB_ICONSTOP);
}
/////////////////////////////////////////////////////////////////////////////
void CDemo1Dlg::OnDivide() 
{
	double dRes = 0;
	DISPID dispid;

	if(Connect())
	{
		if(GetAandB())
		{
			SetOp("/");
			dispid = GetDispid("Divide");
			dRes = m_pClient->Divide(atof(m_strA), atof(m_strB), dispid);
			SetResult(dRes);
		}
	}
	else
		MessageBox("Unable to connect to Web Service","Error...",MB_OK | MB_ICONSTOP);}
/////////////////////////////////////////////////////////////////////////////
void CDemo1Dlg::OnSubtract() 
{
	double dRes = 0;
	DISPID dispid;

	if(Connect())
	{
		if(GetAandB())
		{
			SetOp("-");
			dispid = GetDispid("Subtract");
			dRes = m_pClient->Subtract(atof(m_strA), atof(m_strB), dispid);
			SetResult(dRes);
		}
	}
	else
		MessageBox("Unable to connect to Web Service","Error...",MB_OK | MB_ICONSTOP);
}
/////////////////////////////////////////////////////////////////////////////
void CDemo1Dlg::OnMultiply() 
{
	double dRes = 0;
	DISPID dispid;

	if(Connect())
	{
		if(GetAandB())
		{
			SetOp("*");
			dispid = GetDispid("Multiply");
			dRes = m_pClient->Multiply(atof(m_strA), atof(m_strB), dispid);
			SetResult(dRes);
		}
	}
	else
		MessageBox("Unable to connect to Web Service","Error...",MB_OK | MB_ICONSTOP);}
/////////////////////////////////////////////////////////////////////////////
BOOL CDemo1Dlg::Connect()
{
	CWnd * pWnd = NULL;
	CString strTemp;

	//Get the name of the web service to connect to
	pWnd = GetDlgItem(IDC_SERVICE);
	if(pWnd)
	{
		pWnd->GetWindowText(strTemp);
		//If this is different from the last one the reconnect
	    if(strTemp!=m_strService)
		{
			//If SoapClient pointer has already been allocated
			//then delete
			if(m_pClient)
			{
				m_pClient->ReleaseDispatch();
				delete m_pClient;
			}
            //Allocate a new SoapClient pointer
			m_pClient = new ISOAPClient;
			//Now create the SoapClient pointer
			if(m_pClient->CreateDispatch("MSSOAP.SoapClient"))
			{
				//Initialise the SoapClient pointer with the destination WSDL file
				m_pClient->mssoapinit((LPCTSTR)strTemp, "CalcVB", "CalcVBPortType", NULL);
				m_strService = strTemp;
			}
			else
				return FALSE;
		}
		return TRUE;
	}
	return FALSE;
}
/////////////////////////////////////////////////////////////////////////////
BOOL CDemo1Dlg::GetAandB()
{
	CWnd * pWnd = NULL;

	pWnd = GetDlgItem(IDC_EDITA);
	if(pWnd)
	{
		pWnd->GetWindowText(m_strA);
		if(m_strA!="")
		{
			pWnd = NULL;
			pWnd = GetDlgItem(IDC_EDITB);
			if(pWnd)
			{
				pWnd->GetWindowText(m_strB);
				if(m_strB!="")
					return TRUE;
			}
		}
	}
	return FALSE;
}
/////////////////////////////////////////////////////////////////////////////
void CDemo1Dlg::SetOp(CString strOp)
{
	CWnd * pWnd;

	pWnd = GetDlgItem(IDC_OP);
	if(pWnd)
		pWnd->SetWindowText(strOp);
}
/////////////////////////////////////////////////////////////////////////////
void CDemo1Dlg::SetResult(double dRes)
{
	CString strTemp;
	CWnd * pWnd = NULL;

	strTemp.Format("%g", dRes);
	pWnd = GetDlgItem(IDC_RESULT);
	if(pWnd)
		pWnd->SetWindowText(strTemp);
}
/////////////////////////////////////////////////////////////////////////////
DISPID CDemo1Dlg::GetDispid(CString strFxName)
{
	OLECHAR * name = strFxName.AllocSysString();
	DISPID dispid;

	//Using the dispatch pointer member get the dispatch id of the required
	//function from the interface
	m_pClient->m_lpDispatch->GetIDsOfNames(IID_NULL, &name, 1, GetUserDefaultLCID(), &dispid);
    return dispid;
}

