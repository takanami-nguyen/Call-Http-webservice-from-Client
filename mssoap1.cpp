// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "mssoap1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// ISOAPClient properties

/////////////////////////////////////////////////////////////////////////////
// ISOAPClient operations

void ISOAPClient::mssoapinit(LPCTSTR bstrWSDLFile, LPCTSTR bstrServiceName, LPCTSTR bstrPort, LPCTSTR bstrWSMLFile)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 bstrWSDLFile, bstrServiceName, bstrPort, bstrWSMLFile);
}

CString ISOAPClient::GetFaultcode()
{
	CString result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString ISOAPClient::GetFaultstring()
{
	CString result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString ISOAPClient::GetFaultactor()
{
	CString result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString ISOAPClient::GetDetail()
{
	CString result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

VARIANT ISOAPClient::GetClientProperty(LPCTSTR PropertyName)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60020005, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		PropertyName);
	return result;
}

void ISOAPClient::SetClientProperty(LPCTSTR PropertyName, const VARIANT& newValue)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x60020005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 PropertyName, &newValue);
}

VARIANT ISOAPClient::GetConnectorProperty(LPCTSTR PropertyName)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60020007, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		PropertyName);
	return result;
}

void ISOAPClient::SetConnectorProperty(LPCTSTR PropertyName, const VARIANT& newValue)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x60020007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 PropertyName, &newValue);
}

//////////////////////////////////////////////////////////////////////////////
//User added function bodies
double ISOAPClient::Add(double dblA, double dblB, DISPID dispid)
{
	double result;
	static BYTE parms[] =
		VTS_R8 VTS_R8;
	InvokeHelper(dispid, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		dblA, dblB);
	return result;
}

double ISOAPClient::Subtract(double dblA, double dblB, DISPID dispid)
{
	double result;
	static BYTE parms[] =
		VTS_R8 VTS_R8;
	InvokeHelper(dispid, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		dblA, dblB);
	return result;
}

double ISOAPClient::Multiply(double dblA, double dblB, DISPID dispid)
{
	double result;
	static BYTE parms[] =
		VTS_R8 VTS_R8;
	InvokeHelper(dispid, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		dblA, dblB);
	return result;
}

double ISOAPClient::Divide(double dblA, double dblB, DISPID dispid)
{
	double result;
	static BYTE parms[] =
		VTS_R8 VTS_R8;
	InvokeHelper(dispid, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		dblA, dblB);
	return result;
}
