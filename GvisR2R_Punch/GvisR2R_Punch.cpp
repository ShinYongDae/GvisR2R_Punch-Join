
// GvisR2R_Punch.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"


#include "GvisR2R_Punch.h"
#include "MainFrm.h"

#include "GvisR2R_PunchDoc.h"
#include "GvisR2R_PunchView.h"

#include <tlhelp32.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIM_DISP_STS				450

// CGvisR2R_PunchApp

BEGIN_MESSAGE_MAP(CGvisR2R_PunchApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CGvisR2R_PunchApp::OnAppAbout)
	// 표준 파일을 기초로 하는 문서 명령입니다.
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// CGvisR2R_PunchApp 생성

CGvisR2R_PunchApp::CGvisR2R_PunchApp()
{
	// 다시 시작 관리자 지원
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 응용 프로그램을 공용 언어 런타임 지원을 사용하여 빌드한 경우(/clr):
	//     1) 이 추가 설정은 다시 시작 관리자 지원이 제대로 작동하는 데 필요합니다.
	//     2) 프로젝트에서 빌드하려면 System.Windows.Forms에 대한 참조를 추가해야 합니다.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 아래 응용 프로그램 ID 문자열을 고유 ID 문자열로 바꾸십시오(권장).
	// 문자열에 대한 서식: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("GvisR2R_Punch.AppID.NoVersion"));

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.

}

CGvisR2R_PunchApp::~CGvisR2R_PunchApp()
{
	wsaEndup();
	Sleep(300);

	//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);	// 메모리 누수 감지 기능 - 출력 창으로 다시 리디렉션
	//_CrtDumpMemoryLeaks();								// 메모리 누수 감지 기능
}

// 유일한 CGvisR2R_PunchApp 개체입니다.

CGvisR2R_PunchApp theApp;

DWORD CGvisR2R_PunchApp::KillProcess(CString strProcName)
{
	HANDLE         hProcessSnap = NULL;
	DWORD          Return = FALSE;
	PROCESSENTRY32 pe32 = { 0 };
	CString strMsg;
	DWORD nCurPID = GetCurrentProcessId();
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return (DWORD)INVALID_HANDLE_VALUE;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hProcessSnap, &pe32))
	{
		DWORD Code = 0;
		DWORD dwPriorityClass;
		do
		{
			CString name = CString(pe32.szExeFile);

			if (name.CompareNoCase(_T("V3UI.exe")) == 0)
				continue;

			if (name.CompareNoCase(_T("V3APRule.exe")) == 0)
				continue;

			HANDLE hProcess;
			// Get the actual priority class. 
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
			dwPriorityClass = GetPriorityClass(hProcess);

			if (nCurPID == pe32.th32ProcessID)
			{
				CloseHandle(hProcess);
				continue;
			}

			CString Temp = pe32.szExeFile;
			Temp.MakeLower();
			strProcName.MakeLower();
			if (Temp == strProcName)
			{
				int checkval = 0;
#ifndef _WIN64
				DWORD ret;
#else
				DWORD_PTR ret;
#endif
				checkval = SendMessageTimeout((HWND)hProcess, WM_NULL, 0,//널 메세지를 보내본다
					0, SMTO_ABORTIFHUNG | SMTO_BLOCK, 500, &ret);
				if (checkval == 0)
				{
					//타임 아웃이나 기타 문제가 발생시
					int kk = GetLastError();
					strMsg = "Delete ";
					strMsg += strProcName;
					strMsg += " Process";
					//	AfxMessageBox(strMsg);
					if (TerminateProcess(hProcess, 0))
						GetExitCodeProcess(hProcess, &Code);
					else
						return Return;
				}
				else
				{
					CString str;
					str.Format(_T("On running %s Process "), Temp);
					//AfxMessageBox(str);
					OutputDebugString(str);
					if (TerminateProcess(hProcess, 0))
						GetExitCodeProcess(hProcess, &Code);
					else
						return Return;
				}
			}
			if (!Temp.Compare(_T("vcspawn.exe")))
			{	// 이것은 콘솔 창으로 무조건 죽인다
				if (TerminateProcess(hProcess, 0))
					GetExitCodeProcess(hProcess, &Code);
				else
					return GetLastError();
			}
			CloseHandle(hProcess);
		} while (Process32Next(hProcessSnap, &pe32));
		Return = TRUE;
	}
	else
		Return = FALSE; // could not walk the list of processes 

	CloseHandle(hProcessSnap); // Do not forget to clean up the snapshot object. 
	return Return;
}

// CGvisR2R_PunchApp 초기화

BOOL CGvisR2R_PunchApp::InitInstance()
{
	if (!m_singleInstance.Create(IDR_MAINFRAME))
	{
		AfxMessageBox(_T("GvisR2R is already running!!"));
		return FALSE;
	}

	wsaStartup();

	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다. 
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// OLE 라이브러리를 초기화합니다.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// RichEdit 컨트롤을 사용하려면  AfxInitRichEdit2()가 있어야 합니다.	
	// AfxInitRichEdit2();

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));
	LoadStdProfileSettings(4);  // MRU를 포함하여 표준 INI 파일 옵션을 로드합니다.


	// 응용 프로그램의 문서 템플릿을 등록합니다.  문서 템플릿은
	//  문서, 프레임 창 및 뷰 사이의 연결 역할을 합니다.
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CGvisR2R_PunchDoc),
		RUNTIME_CLASS(CMainFrame),       // 주 SDI 프레임 창입니다.
		RUNTIME_CLASS(CGvisR2R_PunchView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// 표준 셸 명령, DDE, 파일 열기에 대한 명령줄을 구문 분석합니다.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 명령줄에 지정된 명령을 디스패치합니다.
	// 응용 프로그램이 /RegServer, /Register, /Unregserver 또는 /Unregister로 시작된 경우 FALSE를 반환합니다.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 창 하나만 초기화되었으므로 이를 표시하고 업데이트합니다.
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CGvisR2R_PunchApp::ExitInstance()
{

	//TODO: 추가한 추가 리소스를 처리합니다.
	AfxOleTerm(FALSE); // MFC 내부 클래스 메모리 부분 문제 해결

	return CWinApp::ExitInstance();
}

// CGvisR2R_PunchApp 메시지 처리기


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
	BOOL m_bTIM_DISP_STS;

public:
	CAboutDlg();
	~CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	m_bTIM_DISP_STS = FALSE;
}

CAboutDlg::~CAboutDlg()
{
	m_bTIM_DISP_STS = FALSE;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void CGvisR2R_PunchApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CGvisR2R_PunchApp 메시지 처리기


void CGvisR2R_PunchApp::wsaStartup()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	char name[255];
	CString IP;
	PHOSTENT hostinfo;
	wVersionRequested = MAKEWORD(2, 0);

	if (WSAStartup(wVersionRequested, &wsaData) == 0)
	{
		if (gethostname(name, sizeof(name)) == 0)
		{
			if ((hostinfo = gethostbyname(name)) != NULL)
			{
				IP = inet_ntoa(*(struct in_addr*)* hostinfo->h_addr_list);
			}
		}
	}

	m_strHostAddress = IP;
}

void CGvisR2R_PunchApp::wsaEndup()
{
	WSACleanup();
}

CString CGvisR2R_PunchApp::GetHostAddress()
{
	return m_strHostAddress;
}

void CGvisR2R_PunchApp::SetHostAddress(CString sAddr)
{
	m_strHostAddress = sAddr;
}

CString CGvisR2R_PunchApp::GetHostPort()
{
	return m_strHostPort;
}

void CGvisR2R_PunchApp::SetHostPort(CString sPort)
{
	m_strHostPort = sPort;
}



void CAboutDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == TIM_DISP_STS)
	{
		KillTimer(TIM_DISP_STS);
		if (this->IsWindowVisible())
		{
			m_bTIM_DISP_STS = FALSE;
		}
		else
		{
			this->ShowWindow(SW_SHOW);
		}
		if (m_bTIM_DISP_STS)
			SetTimer(TIM_DISP_STS, 100, NULL);
	}


	CDialogEx::OnTimer(nIDEvent);
}


int CAboutDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	m_bTIM_DISP_STS = TRUE;
	SetTimer(TIM_DISP_STS, 100, NULL);

	return 0;
}
