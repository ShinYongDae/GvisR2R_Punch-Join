// DlgOption01.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "../GvisR2R_Punch.h"
#include "DlgOption01.h"
//#include "afxdialogex.h"


#include "../GvisR2R_PunchDoc.h"
#include "../GvisR2R_PunchView.h"

extern CGvisR2R_PunchDoc* pDoc;
extern CGvisR2R_PunchView* pView;


// CDlgOption01 ��ȭ �����Դϴ�.

//IMPLEMENT_DYNAMIC(CDlgOption01, CDialog)

CDlgOption01::CDlgOption01(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOption01::IDD, pParent)
{
	m_pRect = NULL;
}

CDlgOption01::~CDlgOption01()
{
	if (m_pRect)
	{
		delete m_pRect;
		m_pRect = NULL;
	}
}

BOOL CDlgOption01::Create()
{
	return CDialog::Create(CDlgOption01::IDD);
}

void CDlgOption01::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgOption01, CDialog)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_CHECK1, &CDlgOption01::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CDlgOption01::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CDlgOption01::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CDlgOption01::OnBnClickedCheck4)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgOption01::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CDlgOption01::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_CHECK5, &CDlgOption01::OnBnClickedCheck5)
END_MESSAGE_MAP()


// CDlgOption01 �޽��� ó�����Դϴ�.


void CDlgOption01::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (!m_pRect)
	{
		m_pRect = new CRect;

		this->GetClientRect(m_pRect);
		m_pRect->top = 375;
		m_pRect->bottom += 375 + GetSystemMetrics(SM_CYSIZE);
		m_pRect->left = 3;
		m_pRect->right += 3;
		this->MoveWindow(m_pRect, TRUE);
	}

	if (bShow)
	{
		AtDlgShow();
	}
	else
	{
		AtDlgHide();
	}
}

void CDlgOption01::AtDlgShow()
{
	CString str;

	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(pDoc->m_bOffLogAuto);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(pDoc->m_bOffLogPLC);
	((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(pDoc->m_bDebugGrabAlign);

	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(pDoc->m_bUseRTRYShiftAdjust);
	str.Format(_T("%3.2f"), pDoc->m_dShiftAdjustRatio);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);

	str.Format(_T("%d"), pDoc->m_nDelayShow);
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);	
	((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(pDoc->m_bUseStatus);
}

void CDlgOption01::AtDlgHide()
{

}


BOOL CDlgOption01::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlgOption01::OnBnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	pDoc->m_bOffLogAuto = bOn;

	if(bOn)
	{
		::WritePrivateProfileString(_T("System"), _T("OffLogAuto"), _T("1"), PATH_WORKING_INFO);
	}
	else
	{
		::WritePrivateProfileString(_T("System"), _T("OffLogAuto"), _T("0"), PATH_WORKING_INFO);
	}
}


void CDlgOption01::OnBnClickedCheck2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
	pDoc->m_bOffLogPLC = bOn;

	if (bOn)
	{
		::WritePrivateProfileString(_T("System"), _T("OffLogPLC"), _T("1"), PATH_WORKING_INFO);
	}
	else
	{
		::WritePrivateProfileString(_T("System"), _T("OffLogPLC"), _T("0"), PATH_WORKING_INFO);
	}
}


void CDlgOption01::OnBnClickedCheck3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
	pDoc->m_bDebugGrabAlign = bOn;

	if (bOn)
	{
		::WritePrivateProfileString(_T("System"), _T("DebugGrabAlign"), _T("1"), PATH_WORKING_INFO);
	}
	else
	{
		::WritePrivateProfileString(_T("System"), _T("DebugGrabAlign"), _T("0"), PATH_WORKING_INFO);
	}
}


void CDlgOption01::OnBnClickedCheck4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck();
	pDoc->m_bUseRTRYShiftAdjust = bOn; pDoc->SetStatus(_T("General"), _T("bUseRTRYShiftAdjust"), pDoc->m_bUseRTRYShiftAdjust);

	if (bOn)
	{
		::WritePrivateProfileString(_T("System"), _T("USE_RTR_SHIFT_ADJUST"), _T("1"), PATH_WORKING_INFO);
	}
	else
	{
		::WritePrivateProfileString(_T("System"), _T("USE_RTR_SHIFT_ADJUST"), _T("0"), PATH_WORKING_INFO);
	}
}


void CDlgOption01::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString sPath = PATH_WORKING_INFO;
	CString sData;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sData);
	pDoc->m_dShiftAdjustRatio = _tstof(sData);
	::WritePrivateProfileString(_T("System"), _T("RTR_SHIFT_ADJUST_RATIO"), sData, sPath);
}


void CDlgOption01::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString sPath = PATH_WORKING_INFO;
	CString sData;
	GetDlgItem(IDC_EDIT2)->GetWindowText(sData);
	pDoc->m_nDelayShow = _ttoi(sData);
	::WritePrivateProfileString(_T("System"), _T("RTR_SHIFT_ADJUST_RATIO"), sData, sPath);
}


void CDlgOption01::OnBnClickedCheck5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck();
	pDoc->m_bUseStatus = bOn;

	if (bOn)
	{
		::WritePrivateProfileString(_T("System"), _T("UseStatus"), _T("1"), PATH_WORKING_INFO);
	}
	else
	{
		::WritePrivateProfileString(_T("System"), _T("UseStatus"), _T("0"), PATH_WORKING_INFO);
	}
}
