#if !defined(AFX_DLGINFO_H__C0EED44D_41A2_4F7C_9326_AE08B3E66AA8__INCLUDED_)
#define AFX_DLGINFO_H__C0EED44D_41A2_4F7C_9326_AE08B3E66AA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInfo.h : header file
//

#include "MyBtn.h"
#include "MyStatic.h"

#define MAX_INFO_STC				82
#define MAX_INFO_STC_DATA			29
#define MAX_INFO_BTN				32

#define TIM_DISP_STS				450

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo dialog

class CDlgInfo : public CDialog
{
	CMyBtn myBtn[MAX_INFO_BTN], myBtnExit;
	CMyStatic myStcTitle[MAX_INFO_STC];
	CMyStatic myStcData[MAX_INFO_STC_DATA];

	BOOL m_bLoadImg;
	BOOL m_bTIM_DISP_STS;

	void LoadImg();
	void DelImg();

	void InitStatic();
	void InitStcTitle();
	void InitStcData();
	void InitBtn();

	BOOL ShowKeypad(int nCtlID, CPoint ptSt=(0, 0), int nDir=TO_NONE);
	void Disp();
	void SetDualTest(BOOL bOn=TRUE);
	void SetFeedDir(int nUnit);
	void SetTestMode(int nMode);
	int GetTestMode();
	int GetTestModeFromPlc();

// Construction
public:
	CDlgInfo(CWnd* pParent = NULL);   // standard constructor
	~CDlgInfo();
	
	//BOOL Create();
	void AtDlgShow();
	void AtDlgHide();

	void UpdateData();
	void InitMkInfo();
	void DispDualTest();

// Dialog Data
	//{{AFX_DATA(CDlgInfo)
	enum { IDD = IDD_DLG_INFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInfo)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual BOOL OnInitDialog();
	afx_msg void OnStc0008();
	afx_msg void OnChk000();
	afx_msg void OnChk001();
	afx_msg void OnChk002();
	afx_msg void OnChk003();
	afx_msg void OnChk004();
	afx_msg void OnChk005();
	afx_msg void OnChk006();
	afx_msg void OnChk007();
	afx_msg void OnChk008();
	afx_msg void OnChk009();
	afx_msg void OnChk010();
	afx_msg void OnChk011();
	afx_msg void OnChk26();
	afx_msg void OnChk28();
	afx_msg void OnStc0012();
	afx_msg void OnStc0016();
	afx_msg void OnStc0020();
	afx_msg void OnStc0024();
	afx_msg void OnStc0030();
	afx_msg void OnStc0034();
	afx_msg void OnStc0037();
	afx_msg void OnStc32();
	afx_msg void OnBtnExit();
	afx_msg void OnStc174();
	afx_msg void OnStc178();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStc61();
	afx_msg void OnChkUseAoiDual();
	afx_msg void OnChkUseAoiSingle();
	afx_msg void OnChkSampleTest();
	afx_msg void OnChkRecoilerCcw();
	afx_msg void OnChkUncoilerCcw();
	afx_msg void OnChkUseAoiInner();
	afx_msg void OnChkUseAoiOuter();
	afx_msg void OnStc181();
	afx_msg void OnStc183();
	afx_msg void OnChk19();
	afx_msg void OnChk23();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChk4PointAlign();
	afx_msg void OnBnClickedChk2PointAlign();
	afx_msg void OnBnClickedChk86();
	afx_msg void OnBnClickedChk85();
	afx_msg void OnBnClickedChk1187();
	afx_msg void OnBnClickedChk1188();
	afx_msg void OnStnClickedStc36();
	afx_msg void OnStnClickedStc17();
	afx_msg void OnStnClickedStc41();
	afx_msg void OnStnClickedStc43();
	afx_msg void OnStnClickedStc82();
	afx_msg void OnStnClickedStc83();
	afx_msg void OnStnClickedStc187();
	afx_msg void OnStnClickedStc189();
	afx_msg void OnBnClickedChkUseAoiMiddle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedStc89();
	afx_msg void OnBnClickedChkUseAoiDualIts();
	afx_msg void OnBnClickedChkUseAoiDual2dIts();
	afx_msg void OnStnClickedStc193();
	afx_msg void OnStnClickedStc195();
	afx_msg void OnStnClickedStc91();
	afx_msg void OnStnClickedStc199();
	afx_msg void OnStnClickedStc218();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINFO_H__C0EED44D_41A2_4F7C_9326_AE08B3E66AA8__INCLUDED_)
