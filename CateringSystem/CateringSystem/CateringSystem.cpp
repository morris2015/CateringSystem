
// CateringSystem.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CateringSystem.h"
#include "CateringSystemDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCateringSystemApp

BEGIN_MESSAGE_MAP(CCateringSystemApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCateringSystemApp construction

CCateringSystemApp::CCateringSystemApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CCateringSystemApp object

CCateringSystemApp theApp;


// CCateringSystemApp initialization

BOOL CCateringSystemApp::InitInstance()
{
	if (!AfxOleInit())
	{
		return FALSE;
	}

	HRESULT hr;
	try
	{
		hr = m_pCon.CreateInstance("ADODB.Connection");
		if (SUCCEEDED(hr))
		{
			m_pCon->ConnectionTimeout = 5;
			hr = m_pCon->Open("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=canyin.accdb",
				"", "", adModeUnknown);

		}
	}
	catch (_com_error e)
	{
		CString temp;
		temp.Format(_T("连接数据库错误信息:%s"), e.ErrorMessage());
		::MessageBox(NULL, temp, _T("提示信息"), NULL);
		return FALSE;
	}

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CCateringSystemDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

