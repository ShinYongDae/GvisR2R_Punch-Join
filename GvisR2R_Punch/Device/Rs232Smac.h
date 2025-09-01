//Rs232Smac.h
//Rs232Smac�� �ϱ����� Ŭ���� ���
#if !defined(AFX_Rs232SMAC_H__INCLUDED_)
#define AFX_Rs232SMAC_H__INCLUDED_

#include "../Global/GlobalDefine.h"

#ifndef MAXBLOCK
#define MAXBLOCK        80
#endif

#ifndef MAXPORTS
#define MAXPORTS        20
#endif



// global stuff



// function prototypes (private)

/////////////////////////////////////////////////////////////////////////////
// CRs232Smac window

class CRs232Smac : public CObject
{
	CWnd* m_pParent;

	DECLARE_DYNCREATE( CRs232Smac )
public:
	HANDLE      m_hComDev ;//����Ʈ ����̽� ���� �ڵ�
	BOOL        m_bConnected;//����Ʈ�� ����Ǹ� 1�� ����
	//BYTE       m_cRxBuffer[ MAXBLOCK + 1] ;//����Ʈ���� ������ ����Ÿ
	CString       m_cRxBuffer;//����Ʈ���� ������ ����Ÿ
	HWND m_hwnd;//�޼����� ������ ������ �÷���

// Construction
public:
	CRs232Smac();

	void ClearReceive();

	void SetXonOff(BOOL chk);//XonOff ����
	//����Ʈ�� ������
	void SetComPort(int port,DWORD rate,BYTE bytesize,BYTE stop,BYTE parity);
	//Dtr Rts����
	void SetDtrRts(BYTE chk);
	//Rs232 ��Ʈ�� �����.
	BOOL CreateRs232Info();
	//Rs232 ��Ʈ�� �����Ѵ�.
	BOOL DestroyRs232();
	//����Ʈ���� ����Ÿ�� �޴´�.
	int  ReadRs232Block( LPSTR, int ) ;
	//����Ʈ�� ����Ÿ�� �ִ´�.
	BOOL WriteRs232Block( LPSTR, DWORD);
	BOOL OpenComPort() ;//����Ʈ�� ���� ������ �õ��Ѵ�.
	//��Ʈ�� �����Ѵ�.
	BOOL SetupConnection() ;
	//������ �����Ѵ�.
	BOOL CloseConnection() ;
	//���� ����Ÿ�� ���ۿ� �����Ѵ�.
	void SetReadData(LPSTR data);
	//�޼��縦 ���� ������ �÷��� �����Ѵ�.
	void SetHwnd(CWnd* pParent);


// Attributes
public:
	BYTE			m_nPort;
	BOOL			m_bXonXoff;
	BYTE			m_nByteSize, m_nFlowCtrl, m_nParity, m_nStopBits ;
	DWORD			m_dwBaudRate ;
	HANDLE			m_hWatchThread;
	HWND			m_hTermWnd ;
	DWORD			m_dwThreadID ;
	OVERLAPPED		m_osWrite, m_osRead ;

	BOOL			m_bCR, m_bLF;
	BOOL			m_bOnLine;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRs232Smac)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRs232Smac();

	// Generated message map functions
//	DECLARE_MESSAGE_MAP()
protected:
};

#endif
/////////////////////////////////////////////////////////////////////////////
