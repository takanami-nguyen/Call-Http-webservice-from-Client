// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// ISOAPClient wrapper class

class ISOAPClient : public COleDispatchDriver
{
public:
	ISOAPClient() {}		// Calls COleDispatchDriver default constructor
	ISOAPClient(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ISOAPClient(const ISOAPClient& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void mssoapinit(LPCTSTR bstrWSDLFile, LPCTSTR bstrServiceName, LPCTSTR bstrPort, LPCTSTR bstrWSMLFile);
	CString GetFaultcode();
	CString GetFaultstring();
	CString GetFaultactor();
	CString GetDetail();
	VARIANT GetClientProperty(LPCTSTR PropertyName);
	void SetClientProperty(LPCTSTR PropertyName, const VARIANT& newValue);
	VARIANT GetConnectorProperty(LPCTSTR PropertyName);
	void SetConnectorProperty(LPCTSTR PropertyName, const VARIANT& newValue);

	//User added function headers
	double Add(double dblA, double dblB, DISPID dispid);
	double Subtract(double dblA, double dblB, DISPID dispid);
    double Multiply(double dblA, double dblB, DISPID dispid);
    double Divide(double dblA, double dblB, DISPID dispid);
};
