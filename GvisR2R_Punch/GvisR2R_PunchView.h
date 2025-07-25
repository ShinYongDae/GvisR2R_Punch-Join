
// GvisR2R_PunchView.h : CGvisR2R_PunchView 클래스의 인터페이스
//

#pragma once

#include "Dialog/DlgMyMsg.h"
#include "Dialog/DlgMsgBox.h"
#include "Dialog/DlgFrameHigh.h"
#include "Dialog/DlgInfo.h"
#include "Dialog/DlgMenu01.h"
#include "Dialog/DlgMenu02.h"
#include "Dialog/DlgMenu03.h"
#include "Dialog/DlgMenu04.h"
#include "Dialog/DlgMenu05.h"
#include "Dialog/DlgMenu06.h"
#include "Dialog/DlgUtil01.h"
#include "Dialog/DlgUtil02.h"
// #include "Dialog/DlgUtil03.h"

#include "Device/Motion.h"
#include "Device/Light.h"
#include "Device/Smac.h"
#include "Device/Vision.h"
#include "Device/MpDevice.h"
#include "Device/SR1000W.h"
#include "Device/Engrave.h"
#include "Device/Dts.h"

#include "Process/PtAlign.h"
#include "Process/ThreadTask.h"

#ifdef USE_FLUCK
#include "Device/Fluck.h"
#endif

#include "GvisR2R_PunchDoc.h"

//#include "Process/CamMasterDefine.h"
//#include "Dialog/DlgCammasterinfoMst.h"
//#include "Dialog/DlgCammasterinfoPch.h"
//#include "Dialog/DlgCammasterinfoStrpcs.h"


#define LAMP_DELAY				5	// 5 * 100[mSec]
#define BUZZER_DELAY			2	// 5 * 100[mSec]

#define FROM_DOMARK0			10
#define FROM_DOMARK1			50
#define FROM_DISPDEFIMG			100

#define AT_LP					10
#define MK_DONE_CHECK			30	// m_nStepMk
#define MK_LIGHT_ERR			50	// m_nStepMk
#define MK_END					100	// m_nStepMk

#define MK_ST					100	// m_nMkStAuto
#define ERR_PROC				120	// m_nMkStAuto
#define REJECT_ST				200	// m_nMkStAuto
#define ERROR_ST				250	// m_nMkStAuto

#define MK_VERIFY				200	// m_nSetpAuto
#define MK_REVIEW				220	// m_nSetpAuto
#define LAST_PROC				250	// m_nSetpAuto
#define LAST_PROC_VS_ALL		300	// m_nSetpAuto
#define LAST_PROC_VS_UP			350	// m_nSetpAuto
#define LAST_PROC_VS_DN			400	// m_nSetpAuto
#define LOT_END					500	// m_nSetpAuto

#define ENG_ST					100	// m_nEngStAuto
#define ENG_2D_ST				150	// m_nEngStAuto

#define TIM_INIT_VIEW				0
#define TIM_TOWER_WINKER			10
#define TIM_BTN_WINKER				11
#define TIM_BUZZER_WARN				12
#define TIM_MB_TIME_OUT				13
#define TIM_DISP_STATUS				14
#define TIM_MPE_IO					15
// #define TIM_MK_START				16
#define TIM_SHOW_MENU01				18
#define TIM_SHOW_MENU02				19
#define TIM_CHK_TEMP_STOP			20
#define TIM_SAFTY_STOP				21
#define TIM_CAMMASTER_UPDATE		22
#define TIM_START_UPDATE			100
#define TIM_CHK_RCV_CURR_INFO_SIG	200
#define TIM_CHK_RCV_MON_DISP_MAIN_SIG	201

#define MAX_THREAD				49

#define THICKNESS_0 _T("설정없음")
#define THICKNESS_1 _T("얇은 두께")
#define THICKNESS_2 _T("중간 두께")
#define THICKNESS_3 _T("두꺼운 두께")

namespace Read2dIdx
{
	typedef enum Index {
		Start = 2, ChkSn = 4, InitRead = 10, Move0Cam1 = 12, Move0Cam0 = 14, Align1_0 = 17, Align0_0 = 18,
		Move1Cam1 = 21, Move1Cam0 = 23, Align1_1 = 26, Align0_1 = 27, MoveInitPt = 29, ChkElec = 32, DoRead = 35,
		Verify = 37, DoneRead = 38, LotDiff = 50
	};
}

namespace Mk1PtIdx
{
	typedef enum Index {
		Start = 2, ChkSn = 4, InitMk = 10, Move0Cam1 = 12, Move0Cam0 = 14, Align1_0 = 17, Align0_0 = 18,
		Move1Cam1 = 21, Move1Cam0 = 23, Align1_1 = 26, Align0_1 = 27, MoveInitPt = 29, ChkElec = 32, DoMk = 35,
		Verify = 37, DoneMk = 38, LotDiff = 50
	};
}

namespace Mk2PtIdx
{
	typedef enum Index {
		Start = 2, ChkSn = 4, InitMk = 10, Move0Cam1 = 12, Move0Cam0 = 14, Align1_0 = 17, Align0_0 = 18,
		Move1Cam1 = 21, Move1Cam0 = 23, Align1_1 = 26, Align0_1 = 27, MoveInitPt = 29, ChkElec = 32, DoMk = 35,
		Verify = 38, DoneMk = 39, LotDiff = 50, Shift2Mk = 60
	}; 
}

namespace Mk4PtIdx
{
	typedef enum Index {
		Start = 2, ChkSn = 4, InitMk = 10, Move0Cam1 = 12, Move0Cam0 = 14, Align1_0 = 17, Align0_0 = 18,
		Move1Cam1 = 21, Move1Cam0 = 23, Align1_1 = 26, Align0_1 = 27, Move2Cam1 = 29, Move2Cam0 = 31,
		Align1_2 = 34, Align0_2 = 35, Move3Cam1 = 37, Move3Cam0 = 39, Align1_3 = 42, Align0_3 = 43,
		MoveInitPt = 45, ChkElec = 48, DoMk = 51,
		Verify = 53, DoneMk = 54, LotDiff = 60, Shift2Mk = 70
	};
}

namespace AtLpVsIdx
{
	typedef enum Index {
		ChkShare = 0, ChkShareVs = 4, UpdateReelmap = 8, MakeItsFile = 12, ResetShare = 14
	};
}

typedef struct _DispMain
{
	CString strMsg;
	COLORREF rgb;

	_DispMain()
	{
		Init();
	}
	_DispMain(CString sMsg, COLORREF Rgb)
	{
		strMsg = sMsg;
		rgb = Rgb;
	}

	void Init()
	{
		strMsg = _T("");
		rgb = RGB_WHITE;
	}

}stDispMain;
typedef CArray<stDispMain, stDispMain> CArDispMain;



class CGvisR2R_PunchView : public CFormView
{
	CString m_sAoiUpAlarmReStartMsg, m_sAoiDnAlarmReStartMsg;
	CString m_sAoiUpAlarmReTestMsg, m_sAoiDnAlarmReTestMsg;
	BOOL m_bDestroyedView;
	BOOL m_bBufEmpty[2];

	CDlgMyMsg* m_pDlgMyMsg;
	CCriticalSection m_csMyMsgBox;
	CCriticalSection m_csDispMain;
	int m_nDummy[2], m_nAoiLastSerial[2]; //[0]: Up, [1]: Dn
	BOOL m_bChkLastProcVs;
	int m_nChkBufIdx[2];

	double m_dTempPauseLen;
	DWORD m_dwCycSt, m_dwCycTim;

	BOOL m_bRtnMyMsgBox[4]; 	// [0] mk0, [1] mk1, [2] reject0, [3] reject1
	int m_nRtnMyMsgBox[4]; 	// [0] mk0, [1] mk1, [2] reject0, [3] reject1
	int m_nRtnMyMsgBoxIdx;

	int m_nErrCnt;
	int m_nStepInitView;

	BOOL m_bDispMsg, m_bWaitClrDispMsg;
	BOOL m_bDispMsgDoAuto[10];
	int m_nStepDispMsg[10];
	CString m_sFixMsg[2]; //[0]:up , [1]:dn

	int m_nCntTowerWinker, m_nCntBtnWinker[4], m_nDlyWinker[4], m_nCntBz;
	BOOL m_bTimTowerWinker, m_bTimBtnWinker, m_bTimBuzzerWarn;
	BOOL m_bTowerWinker[3], m_bBtnWinker[4]; // [R/G/Y] , [Ready/Reset/Run/Stop]
	BOOL m_bTIM_DISP_STATUS, m_bTIM_MPE_IO;

	CString m_sPrevMyMsg;
	CString m_sTick, m_sDispTime;
	DWORD m_dwSetDlySt[10], m_dwSetDlyEd[10];
	DWORD m_dwSetDlySt0[10], m_dwSetDlyEd0[10];
	DWORD m_dwSetDlySt1[10], m_dwSetDlyEd1[10];

	CString m_sShare[2], m_sBuf[2]; // [0]: AOI-Up , [1]: AOI-Dn
	int		m_pBufSerial[2][100], m_nBufTot[2]; // [0]: AOI-Up , [1]: AOI-Dn
	__int64 m_nBufSerialSorting[2][100]; // [0]: AOI-Up , [1]: AOI-Dn
	int		m_nBufSerial[2][2]; // [0]: AOI-Up , [1]: AOI-Dn // [0]: Cam0, [1]:Cam1

	CString m_sDispMsg[10];
	double m_dTotVel, m_dPartVel;
	BOOL m_bTIM_CHK_TEMP_STOP;
	BOOL m_bTIM_SAFTY_STOP;
	BOOL m_bTIM_CAMMASTER_UPDATE;
	CString m_sMyMsg; int m_nTypeMyMsg;
	int m_nVsBufLastSerial[2];

	int m_nStepElecChk;
	BOOL m_bStopFeeding;
	BOOL m_bChkLightErr;

	double m_dElecChkVal;
	CString m_sMsg;


	void InitMyMsg();
	void CloseMyMsg();

	void DispStsBar();
	void UpdateLotTime();

	void SetMainMc(BOOL bOn);
	void ExitProgram();
	void HideAllDlg();
	void DelAllDlg();
	BOOL HwInit();
	BOOL TcpIpInit();
	void DtsInit();
	void InitPLC();
	void HwKill();
	void ThreadInit();
	void ThreadKill();
	//void GetSliceIO();
	//void GetMpeIO();
	//void GetMpeSignal();
	//void GetMpeData();
	//void DispThreadTick();
	void DispTime();
	void Init();
	void InitIO();
	BOOL InitAct();
	void SwJog(int nAxisID, int nDir, BOOL bOn = TRUE);
	int GetVsBufLastSerial();
	int GetVsUpBufLastSerial();
	int GetVsDnBufLastSerial();

	void MarkingWith2PointAlign();
	void Mk2PtReady();
	void Mk2PtChkSerial();
	void Mk2PtInit();
	void Mk2PtAlignPt0();
	void Mk2PtAlignPt1();
	void Mk2PtMoveInitPos();
	void Mk2PtElecChk();
	void Mk2PtDoMarking();
	void Mk2PtShift2Mk();
	void Mk2PtLotDiff();
	void Mk2PtReject();
	void Mk2PtErrStop();

	void MarkingWith4PointAlign();
	void Mk4PtReady();
	void Mk4PtChkSerial();
	void Mk4PtInit();
	void Mk4PtAlignPt0();
	void Mk4PtAlignPt1();
	void Mk4PtAlignPt2();
	void Mk4PtAlignPt3();
	void Mk4PtMoveInitPos();
	void Mk4PtElecChk();
	void Mk4PtDoMarking();
	void Mk4PtLotDiff();
	void Mk4PtReject();
	void Mk4PtErrStop();

	void DoBoxSw();
	void DoEmgSw();
	void DoSens();
	void DoAuto();
	void DoAutoMarking();
	void DoAutoMarkingEngrave();
	void DoAutoChkShareFolder(); // 20170727-잔량처리 시 계속적으로 반복해서 이함수가 호출됨으로 좌우 마킹 인덱스 동일 현상 발생.(case AT_LP + 8:)	
	void DoAutoChkShareVsFolder(); // 잔량처리 시 계속적으로 반복해서 이함수가 호출됨으로 좌우 마킹 인덱스 동일 현상 발생.(case AT_LP + 8:)	
	void DoAutoDispMsg();
	void DoAutoChkCycleStop();
	void DoAutoSetFdOffset();
	void DoAutoSetFdOffsetLastProc();
	void DoAutoSetLastProcAtPlc();
	void DoAtuoGetMkStSignal();
	BOOL DoAutoGetLotEndSignal();
	void DoInterlock();

	void DoSaftySens();
	void DoDoorSens();

	void DoModeSel();		// SliceIo[0]
	void DoMainSw();		// SliceIo[0]
	void DoMkSens();		// SliceIo[2]
	void DoAoiBoxSw();		// SliceIo[3]
	void DoEmgSens();		// SliceIo[4]
	void DoSignal();		// SliceIo[5]

	void DoUcBoxSw();		// MpeIo[0]
	void DoUcSens1();		// MpeIo[1]
	void DoUcSens2();		// MpeIo[2]
	void DoUcSens3();		// MpeIo[3]
	void DoRcBoxSw();		// MpeIo[4]
	void DoRcSens1();		// MpeIo[5]
	void DoRcSens2();		// MpeIo[6]
	void DoRcSens3();		// MpeIo[7]

	void DoEngraveSens();	// MpeIo[28]


	BOOL SetCollision(double dCollisionMargin);
	//BOOL ChkXmpCollision();
	void DispStsMainMsg(int nIdx = 0);
	void SetPlcParam();

	BOOL DoElecChk(CString &sRst);  // TRUE: bDone , FALSE: Doing

	BOOL SortingInUp(CString sPath, int nIndex);
	BOOL SortingOutUp(int* pSerial, int nTot);
	void SwapUp(__int64 *num1, __int64 *num2);
	BOOL SortingInDn(CString sPath, int nIndex);
	BOOL SortingOutDn(int* pSerial, int nTot);
	void SwapDn(__int64 *num1, __int64 *num2);

	BOOL LoadMstInfo();			// Reelmap 초기화

	void DoAutoEng();
	void DoAtuoGetEngStSignal();
	void DoAtuoGet2dReadStSignal();

	void DoAutoSetFdOffsetEngrave();


protected: // serialization에서만 만들어집니다.
	CGvisR2R_PunchView();
	DECLARE_DYNCREATE(CGvisR2R_PunchView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_GVISR2R_PUNCH_FORM };
#endif

// 특성입니다.
public:
	CGvisR2R_PunchDoc* GetDocument() const;

	stGuiRegister Plc;

	BOOL m_bContEngraveF;
	double m_dMkTorqList[2]; // [0] : Left, [1] : Right

	int m_nDebugStep; 	void DispThreadTick();

	int m_nMkStrip[2][MAX_STRIP]; // [nCam][nStrip] - [좌/우][] : 스트립에 펀칭한 피스 수 count
	int m_nStepMk[4], m_nMkPcs[4]; 	// [0] Auto-Left, [1] Auto-Right, [2] Manual-Left, [3] Manual-Right  ; m_nStepMk(마킹Sequence), nMkOrderIdx(마킹한 count)
	int m_nMarkingOrder[2]; 	// [0] Auto-Left, [1] Auto-Right
	int m_nTotMk[2], m_nCurMk[2]; // [0]: 좌 MK, [1]: 우 MK
	int m_nPrevTotMk[2], m_nPrevCurMk[2]; // [0]: 좌 MK, [1]: 우 MK
	int m_nPrevStepAuto, m_nPrevMkStAuto;
	BOOL m_bPcrInShare[2], m_bPcrInShareVs[2];
	BOOL m_bRcvSig[_SigInx::_EndIdx];
	//stRcvSig m_stRcvSig;
	CMpDevice* m_pMpe;
	CPtAlign m_Align[2];	// [0] : LeftCam , [1] : RightCam
#ifdef USE_VISION
	CVision* m_pVision[2];	// [0] : LeftCam , [1] : RightCam
	CVision* m_pVisionInner[2];	// [0] : LeftCam , [1] : RightCam
#endif
	CMotion* m_pMotion;
	CLight* m_pLight;
	//CFluck* m_pFluck;
	CSmac* m_pVoiceCoil[2];	// [0] : LeftCam , [1] : RightCam
	CDlgMsgBox* m_pDlgMsgBox;
	CEvent      m_evtWaitClrDispMsg;

	CDlgInfo *m_pDlgInfo;
	CDlgFrameHigh *m_pDlgFrameHigh;
	CDlgMenu01 *m_pDlgMenu01;
	CDlgMenu02 *m_pDlgMenu02;
	CDlgMenu03 *m_pDlgMenu03;
	CDlgMenu04 *m_pDlgMenu04;
	CDlgMenu05 *m_pDlgMenu05;
	CDlgMenu06 *m_pDlgMenu06;
	//CDlgUtil01 *m_pDlgUtil01;
	//CDlgUtil02 *m_pDlgUtil02;
	//CDlgUtil03 *m_pDlgUtil03;


	int m_nLotEndSerial;

	BOOL m_bTIM_INIT_VIEW;
	BOOL m_bCam, m_bReview;

	BOOL m_bTIM_CHK_RCV_CURR_INFO_SIG;
	BOOL m_bTIM_CHK_RCV_MON_DISP_MAIN_SIG;

	DWORD m_dwThreadTick[MAX_THREAD];
	BOOL m_bThread[MAX_THREAD];
	CThreadTask m_Thread[MAX_THREAD];

	double m_dEnc[MAX_AXIS], m_dTarget[MAX_AXIS];
	double m_dNextTarget[MAX_AXIS];
	int m_nSelRmap, m_nSelRmapInner;
	int m_nStepAuto;

	int m_nStop;
	BOOL m_bReMk;
	BOOL m_bChkMpeIoOut;

	BOOL m_bProbDn[2]; // 좌/우 .

	BOOL m_nAoiUpAutoSerial, m_nAoiUpAutoSerialPrev;
	BOOL m_nAoiDnAutoSerial, m_nAoiDnAutoSerialPrev;

	void GetMpeIO();
	void GetMpeSignal();
	void GetMpeData();

	// Auto Sequence
	BOOL m_bAuto, m_bManual;// , m_bOneCycle;
	BOOL m_bMkTmpStop, m_bAoiLdRun, m_bAoiLdRunF;
	BOOL m_bTHREAD_MK[4];	// [0] Auto-Left, [1] Auto-Right, [2] Manual-Left, [3] Manual-Right
	BOOL m_bTHREAD_DISP_DEF;
	int	m_nStepTHREAD_DISP_DEF;
	BOOL m_bTHREAD_UPDATAE_YIELD[2];		// [0] : Cam0, [1] : Cam1
	int	m_nSerialTHREAD_UPDATAE_YIELD[2];	// [0] : Cam0, [1] : Cam1 - 마킹 중인 버퍼의 시리얼
	BOOL m_bTHREAD_SHIFT2MK;// [2];		// [0] : Cam0, [1] : Cam1
	BOOL m_bTHREAD_UPDATE_REELMAP_UP, m_bTHREAD_UPDATE_REELMAP_ALLUP;
	BOOL m_bTHREAD_UPDATE_REELMAP_DN, m_bTHREAD_UPDATE_REELMAP_ALLDN;
	BOOL m_bTHREAD_REELMAP_YIELD_UP, m_bTHREAD_REELMAP_YIELD_ALLUP;
	BOOL m_bTHREAD_REELMAP_YIELD_DN, m_bTHREAD_REELMAP_YIELD_ALLDN;
	BOOL m_bTHREAD_RELOAD_RST_UP, m_bTHREAD_RELOAD_RST_ALLUP;
	BOOL m_bTHREAD_RELOAD_RST_DN, m_bTHREAD_RELOAD_RST_ALLDN;
	BOOL m_bTHREAD_RELOAD_RST_UP_INNER, m_bTHREAD_RELOAD_RST_ALLUP_INNER;
	BOOL m_bTHREAD_RELOAD_RST_DN_INNER, m_bTHREAD_RELOAD_RST_ALLDN_INNER;
	BOOL m_bTHREAD_RELOAD_RST_ITS, m_bTHREAD_REELMAP_YIELD_ITS;

	BOOL m_bTHREAD_UPDATE_YIELD_UP, m_bTHREAD_UPDATE_YIELD_ALLUP;
	BOOL m_bTHREAD_UPDATE_YIELD_DN, m_bTHREAD_UPDATE_YIELD_ALLDN;
	BOOL m_bTHREAD_UPDATE_YIELD_ITS;
	BOOL m_bTHREAD_UPDATE_YIELD_INNER_UP, m_bTHREAD_UPDATE_YIELD_INNER_ALLUP;
	BOOL m_bTHREAD_UPDATE_YIELD_INNER_DN, m_bTHREAD_UPDATE_YIELD_INNER_ALLDN;
	int	m_nSnTHREAD_UPDATAE_YIELD, m_nSnTHREAD_UPDATAE_YIELD_ALL, m_nSnTHREAD_UPDATAE_YIELD_ITS, m_nSnTHREAD_UPDATAE_YIELD_INNER_ALL;

	void UpdateReelmapYieldUp();
	void UpdateReelmapYieldAllUp();
	void UpdateReelmapYieldDn();
	void UpdateReelmapYieldAllDn();
	void UpdateReelmapYieldIts();

	BOOL m_bSwRun, m_bSwRunF;
	BOOL m_bSwStop, m_bSwStopF;
	BOOL m_bSwReset, m_bSwResetF;
	BOOL m_bSwReady, m_bSwReadyF;

	BOOL m_bNewModel;
	DWORD m_dwLotSt, m_dwLotEd;
	long m_lFuncId;
	BOOL m_bDrawGL;
	BOOL m_bDrawGL_Menu01, m_bDrawGL_Menu06;
	BOOL m_bCont;	// 이어가기
	DWORD m_dwStMkDn[2];
	BOOL m_bInit;
	BOOL m_bSwStopNow;
	BOOL m_bShowModalMyPassword;
	// 	BOOL m_bFurgeRun;
	// 	int m_nFurgeRun;

	int m_nRstNum;

	BOOL m_bChkBufIdx[2];
	BOOL m_bBufHomeDone, m_bReadyDone;
	BOOL m_bCollision[2], m_bPriority[4];
	BOOL m_bEngBufHomeDone;

	unsigned long m_Flag;
	unsigned long m_AoiLdRun;
	BOOL m_bDoneDispMkInfo[2][2]; // [nCam][Up/Dn]

	int m_nShareUpS, m_nShareUpSprev;
	int m_nShareUpSerial[2]; // [nCam]
	int m_nShareDnS, m_nShareDnSprev;
	int m_nShareDnSerial[2]; // [nCam]
	int m_nShareUpCnt;
	int m_nShareDnCnt;

	int m_nBufUpSerial[2]; // [nCam]
	int m_nBufDnSerial[2]; // [nCam]
	int m_nBufUpCnt;
	int m_nBufDnCnt;

	BOOL m_bAnswer[10];
	//BOOL m_bFailAlign[2][2]; // [nCam][nPos] 
	//BOOL m_bReAlign[2][2]; // [nCam][nPos] 
	//BOOL m_bSkipAlign[2][2]; // [nCam][nPos] 
	BOOL m_bFailAlign[2][4]; // [nCam][nPos] 
	BOOL m_bReAlign[2][4]; // [nCam][nPos] 
	BOOL m_bSkipAlign[2][4]; // [nCam][nPos] 

	BOOL m_bDoMk[2];			// [nCam] : TRUE(Punching), FALSE(Stop Punching)
	BOOL m_bDoneMk[2];			// [nCam] : TRUE(Punching 완료), FALSE(Punching 미완료)
	BOOL m_bReMark[2];			// [nCam] : TRUE(Punching 다시시작), FALSE(pass)

	BOOL m_bJoinContinue;		// 이음매 이어가기
	//BOOL m_bChangeModel, m_bChangeLot, m_bChangeLayer;

	int m_nMonAlmF, m_nClrAlmF;
	BOOL m_bLotEnd, m_bLotEndF, m_bLastProc, m_bLastProcFromUp, m_bLastProcFromEng;
	BOOL m_bMkSt[2], m_bMkStSw[2]; // 0 : Left , 1 : Right
	BOOL m_bEngSt, m_bEngStSw;
	BOOL m_bEng2dSt, m_bEng2dStSw;
	int m_nMkStAuto, m_nEngStAuto, m_nEng2dStAuto;
	int m_nLotEndAuto, m_nLastProcAuto;
	BOOL m_bLoadShare[2]; // [Up/Dn]
	CString m_sNewLotUp, m_sNewLotDn;

	BOOL m_bAoiFdWrite[2], m_bAoiFdWriteF[2]; // [Up/Dn]
	BOOL m_bAoiTest[2], m_bAoiTestF[2];
	//BOOL m_bEngFdWrite, m_bEngFdWriteF; // [Up/Dn]
	//BOOL m_bEngTest, m_bEngTestF;
	BOOL m_bWaitPcr[2]; // [Up/Dn] : FALSE -> 잔량처리시 Share 폴더에 시리얼을 기다리지 않음.

	BOOL m_bEngFdWrite, m_bEngFdWriteF;
	BOOL m_bEngTest, m_bEngTestF;
	BOOL m_bMkFdWrite, m_bMkFdWriteF;

	BOOL m_bCycleStop, m_bContDiffLot;
	CString m_sDispMain;
	BOOL m_bStopF_Verify;
	BOOL m_bInitAuto, m_bInitAutoLoadMstInfo;

	BOOL m_bShowMyMsg;
	CWnd *m_pMyMsgForeground;

	BOOL m_bRejectDone[2][MAX_STRIP_NUM]; // Shot[2], Strip[4] - [좌/우][] : 스트립에 펀칭한 피스 수 count가 스트립 폐기 설정수 완료 여부 

	CString m_sDispSts[2];

	BOOL m_bDispMyMsgBox;
	CArMyMsgBox  m_ArrayMyMsgBox;
	BOOL m_bDispMain;
	CArDispMain  m_ArrayDispMain;

	int m_nWatiDispMain;

	CEngrave* m_pEngrave;
	CSr1000w* m_pSr1000w;
	CDts* m_pDts;

	int m_nNewLot;

	//CString m_sPathRmapUpdate[4];
	int m_nSerialRmapUpdate;

	//CString m_sPathRmapInnerUpdate[4];
	int m_nSerialRmapInnerUpdate;
	int m_nSerialMakeItsFile;

	BOOL m_bIsBuf[2]; // [0]: AOI-Up , [1]: AOI-Dn


// 작업입니다.
public:
	int m_nSaveMk0Img, m_nSaveMk1Img;
	BOOL m_bShift2Mk, m_bUpdateYield, m_bUpdateYieldOnRmap;

	void ReloadYield();
	void SetLastSerialEng(int nSerial);
	int MsgBox(CString sMsg, int nThreadIdx = 0, int nType = MB_OK, int nTimOut = DEFAULT_TIME_OUT, BOOL bEngave = FALSE);		// SyncMsgBox
	int AsyncMsgBox(CString sMsg, int nThreadIdx = 1, int nType = MB_OK, int nTimOut = DEFAULT_TIME_OUT);						// AsyncMsgBox
	int WaitRtnVal(int nThreadIdx = 1);
	afx_msg LRESULT OnMyMsgExit(WPARAM wPara, LPARAM lPara);

	int GetLastBufferSerial(int nAoi); // 0: Up, 1: Dn
	void GetPlcParam();
	BOOL WatiDispMain(int nDelay);

	void RestoreReelmap();
	CString GetProcessNum();

	void DispMain(CString sMsg, COLORREF rgb = RGB(0, 255, 0));
	int DoDispMain();
	void GetDispMsg(CString &strMsg, CString &strTitle);
	void DispMsg(CString strMsg, CString strTitle = _T(""), COLORREF color = RGB(255, 0, 0), DWORD dwDispTime = 0, BOOL bOverWrite = TRUE);
	void ClrDispMsg();
	BOOL WaitClrDispMsg();
	LONG OnQuitDispMsg(UINT wParam, LONG lParam);
	void ShowDlg(int nID);
	void DispIo();
	void DispDatabaseConnection();
	void Option01();
	void CamMasterInfoMst();
	void CamMasterInfoPch();
	void CamMasterInfoStrPcs();

	void TowerLamp(COLORREF color, BOOL bOn, BOOL bWink = FALSE);
	void DispTowerWinker();
	void Buzzer(BOOL bOn, int nCh = 0);
	int MyPassword(CString strMsg, int nCtrlId = 0);

	void GetInput();
	void GetEnc();
	void SetEngFdPitch(double dPitch);
	void SetAoiFdPitch(double dPitch);
	void SetMkFdPitch(double dPitch);

	void DoIO();
	void DispDefImg();
	void DoMark0();
	void DoMark1();
	void DoMark0All();
	void DoMark1All();

	BOOL SaveMk0Img(int nMkPcsIdx);
	BOOL SaveMk1Img(int nMkPcsIdx);

	void InsertPunchingData(int nCam);

	void ChkShareVs();
	void ChkShareVsUp();
	void ChkShareVsDn();
	BOOL ChkShareVs(int &nSerial);
	BOOL ChkShareVsUp(int &nSerial);
	BOOL ChkShareVsDn(int &nSerial);
	//BOOL ChkShareVsIdx(int *pBufSerial, int nBufTot, int nShareSerial);

	void ChkShare();
	void ChkShareUp();
	void ChkShareDn();
	BOOL ChkShare(int &nSerial);
	BOOL ChkShareUp(int &nSerial);
	BOOL ChkShareDn(int &nSerial);
	BOOL ChkShareIdx(int *pBufSerial, int nBufTot, int nShareSerial);
	void ChkBuf();
	void ChkBufUp();
	void ChkBufDn();
	void ChkEmg();
	BOOL ChkBufUp(int* pSerial, int &nTot);
	BOOL ChkBufDn(int* pSerial, int &nTot);
	BOOL ChkBufIdx(int* pSerial, int nTot = 0);
	void ChkMRegOut();


	CString GetTime();
	CString GetTime(stLotTime &LotTime);
	CString GetTime(int &nHour, int &nMinute, int &nSec);
	int GetTime(int nSel);
	void SetBufInitPos(double dPos);
	void SetEngBufInitPos(double dPos);
	void SetBufHomeParam(double dVel, double dAcc);
	void DispLotStTime();
	void SetListBuf();

	void DispMainOnAutoStart();

	static UINT ThreadProc0(LPVOID lpContext); // DoMark0(), DoMark1()
	static UINT ThreadProc1(LPVOID lpContext); // ChkCollision()
	static UINT ThreadProc2(LPVOID lpContext); // DispDefImg()
	static UINT ThreadProc3(LPVOID lpContext); // UpdateYield()
	static UINT ThreadProc4(LPVOID lpContext); // RunShift2Mk()
	static UINT ThreadProc5(LPVOID lpContext); // GetCurrentInfoSignal()

	static UINT ThreadProc6(LPVOID lpContext); // UpdateRMapUp()
	static UINT ThreadProc7(LPVOID lpContext); // UpdateRMapDn()
	static UINT ThreadProc8(LPVOID lpContext); // UpdateRMapAllUp()
	static UINT ThreadProc9(LPVOID lpContext); // UpdateRMapAllDn()

	static UINT ThreadProc10(LPVOID lpContext); // UpdateReelmapYieldUp()
	static UINT ThreadProc11(LPVOID lpContext); // UpdateReelmapYieldDn()
	static UINT ThreadProc12(LPVOID lpContext); // UpdateReelmapYieldAllUp()
	static UINT ThreadProc13(LPVOID lpContext); // UpdateReelmapYieldAllDn()

	static UINT ThreadProc14(LPVOID lpContext); // ReloadReelmapUp()
	static UINT ThreadProc15(LPVOID lpContext); // ReloadReelmapDn()
	static UINT ThreadProc16(LPVOID lpContext); // ReloadReelmapAllUp()
	static UINT ThreadProc17(LPVOID lpContext); // ReloadReelmapAllDn()
	static UINT ThreadProc18(LPVOID lpContext); // WriteReelmapIts()
	static UINT ThreadProc19(LPVOID lpContext); // DispDefImgInner()
	static UINT ThreadProc20(LPVOID lpContext); // UpdateReelmapYieldIts()
	static UINT ThreadProc21(LPVOID lpContext); // ReloadReelmapUpInner()
	static UINT ThreadProc22(LPVOID lpContext); // ReloadReelmapDnInner()
	static UINT ThreadProc23(LPVOID lpContext); // ReloadReelmapAllUpInner()
	static UINT ThreadProc24(LPVOID lpContext); // ReloadReelmapAllDnInner()
	static UINT ThreadProc25(LPVOID lpContext); // ReloadReelmapIts()

	static UINT ThreadProc26(LPVOID lpContext); // UpdateRMapInnerUp()
	static UINT ThreadProc27(LPVOID lpContext); // UpdateRMapInnerDn()
	static UINT ThreadProc28(LPVOID lpContext); // UpdateRMapInnerAllUp()
	static UINT ThreadProc29(LPVOID lpContext); // UpdateRMapInnerAllDn()

	static UINT ThreadProc30(LPVOID lpContext); // UpdateYieldUp()
	static UINT ThreadProc31(LPVOID lpContext); // UpdateYieldDn()
	static UINT ThreadProc32(LPVOID lpContext); // UpdateYieldAllUp()
	static UINT ThreadProc33(LPVOID lpContext); // UpdateYieldAllDn()

	static UINT ThreadProc34(LPVOID lpContext); // UpdateYieldInnerUp()
	static UINT ThreadProc35(LPVOID lpContext); // UpdateYieldInnerDn()
	static UINT ThreadProc36(LPVOID lpContext); // UpdateYieldInnerAllUp()
	static UINT ThreadProc37(LPVOID lpContext); // UpdateYieldInnerAllDn()
	static UINT ThreadProc38(LPVOID lpContext); // UpdateYieldIts()

	static UINT ThreadProc39(LPVOID lpContext); // MakeItsFileUp()
	static UINT ThreadProc40(LPVOID lpContext); // MakeItsFileDn()

	// RemakeReelmapFromPcr - Start
	static UINT ThreadProc41(LPVOID lpContext); // LoadPcrUpOnOffline()
	static UINT ThreadProc42(LPVOID lpContext); // LoadPcrUpAllOnOffline()
	static UINT ThreadProc43(LPVOID lpContext); // LoadPcrDnOnOffline()
	static UINT ThreadProc44(LPVOID lpContext); // LoadPcrDnAllOnOffline()

	static UINT ThreadProc45(LPVOID lpContext); // m_pReelMapUp->WriteOnOffline()
	static UINT ThreadProc46(LPVOID lpContext); // m_pReelMapDn->WriteOnOffline()
	static UINT ThreadProc47(LPVOID lpContext); // m_pReelMapAllUp->WriteOnOffline()
	static UINT ThreadProc48(LPVOID lpContext); // m_pReelMapAllDn->WriteOnOffline()

	int m_nSerialRmapUpdateOnOffline;
	BOOL m_bTHREAD_LOAD_PCR_UP_OFFLINE, m_bTHREAD_LOAD_PCR_ALLUP_OFFLINE;
	BOOL m_bTHREAD_LOAD_PCR_DN_OFFLINE, m_bTHREAD_LOAD_PCR_ALLDN_OFFLINE;

	BOOL m_bTHREAD_UPDATE_REELMAP_UP_OFFLINE, m_bTHREAD_UPDATE_REELMAP_ALLUP_OFFLINE;
	BOOL m_bTHREAD_UPDATE_REELMAP_DN_OFFLINE, m_bTHREAD_UPDATE_REELMAP_ALLDN_OFFLINE;

	int m_nLastShotOnOffline;
	BOOL m_bTHREAD_WRITE_LAST_INFO_REELMAP_UP_OFFLINE, m_bTHREAD_WRITE_LAST_INFO_REELMAP_ALLUP_OFFLINE;
	BOOL m_bTHREAD_WRITE_LAST_INFO_REELMAP_DN_OFFLINE, m_bTHREAD_WRITE_LAST_INFO_REELMAP_ALLDN_OFFLINE;

	void LoadPcrUpOnOffline();
	void LoadPcrDnOnOffline();
	void LoadPcrUpAllOnOffline();
	void LoadPcrDnAllOnOffline();

	BOOL LoadPcrOnOffline(int nSerial, int nOffline);
	BOOL LoadPcrAllOnOffline(int nSerial, int nOffline);

	BOOL UpdateRMapOnOffline(int nSerial, int nOffline);
	BOOL UpdateRMapAllOnOffline(int nSerial, int nOffline);
	void UpdateRMapUpOnOffline();
	void UpdateRMapDnOnOffline();
	void UpdateRMapUpAllOnOffline();
	void UpdateRMapDnAllOnOffline();

	BOOL RemakeReelmapFromPcr(CString sModel, CString sLot, CString sLayerUp, CString sLayerDn);
	int IsOfflineFolder(); // 0 : Not exist, 1 : Exist only Up, 2 : Exist only Dn, 3 : Exist Up and Dn
	void StartThreadRemakeRmapFromPcr();
	void StartThread();
	void SetLastSerialOnOffline(int nSerial, int nOffline);
	void StopThreadRemakeRmapFromPcr();
	void WriteLastRMapUpInfoOnOffline();
	void WriteLastRMapDnInfoOnOffline();
	void WriteLastRMapUpAllInfoOnOffline();
	void WriteLastRMapDnAllInfoOnOffline();
	void DeleteReelmapOnOffline();
	BOOL WriteLastRmapInfoOnOffline(int nLastShot, int nOffline);
	int GetLastShotFromPcr(int nOffline);
	BOOL RemakeRmapFromPcr(int nLastShot, int nOffline);
	void ResetYield(int nOffline=3); // [nOffline] 0 : Not exist, 1 : Exist only Up, 2 : Exist only Dn, 3 : Exist Up and Dn

	void DeleteYieldOnOffline();
	// RemakeReelmapFromPcr - End


	void UpdateRMapUp();
	void UpdateRMapAllUp();
	void UpdateRMapDn();
	void UpdateRMapAllDn();

	void MakeItsFileUp(int nSerial);
	void MakeItsFileDn(int nSerial);
	void UpdateRMapInnerUp();
	void UpdateRMapInnerAllUp();
	void UpdateRMapInnerDn();
	void UpdateRMapInnerAllDn();


	// Auto Sequence
	void SetFeedingEnableToPlc(int nSerial, int nUpDn); // 0(Up), 1(Dn), 2(All)
	BOOL IsReady();
	void DoShift2Mk();
	void RunShift2Mk();
	void Shift2Buf();
	void Shift2DummyBuf();
	void Shift2Mk();
	void CompletedMk(int nCam); // 0: Only Cam0, 1: Only Cam1, 2: Cam0 and Cam1, 3: None
	void SetDelay(int mSec, int nId = 0);
	BOOL WaitDelay(int nId = 0);				// F:Done, T:On Waiting....
	void SetDelay0(int mSec, int nId = 0);
	BOOL WaitDelay0(int nId = 0);				// F:Done, T:On Waiting....
	void SetDelay1(int mSec, int nId = 0);
	BOOL WaitDelay1(int nId = 0);				// F:Done, T:On Waiting....
	BOOL GetDelay(int &mSec, int nId = 0);	// F:Done, T:On Waiting....
	BOOL GetDelay0(int &mSec, int nId = 0);	// F:Done, T:On Waiting....
	BOOL GetDelay1(int &mSec, int nId = 0);	// F:Done, T:On Waiting....
	//BOOL IsMkFdDone();
	//BOOL IsAoiFdDone();
	double GetAoi2InitDist();
	double GetMkInitDist();
	void UpdateWorking();
	double GetRemain();
	void Stop();
	void ShowLive(BOOL bShow = TRUE);
	void SetLotSt();
	void SetLotEd();
	void DispLotTime();
	void SetTest(BOOL bOn);
	void SetTest0(BOOL bOn);
	void SetTest1(BOOL bOn);
	BOOL SetMk(BOOL bRun = TRUE);
	void SetReMk(BOOL bMk0 = FALSE, BOOL bMk1 = FALSE);
	void ResetTargetPos();
	BOOL InitMk();
	void InitAuto(BOOL bInit = TRUE);
	void Mk0();
	void Mk1();
	BOOL IsReMk();
	BOOL IsMkDone();
	BOOL IsAoiTblVac();
	BOOL IsAoiTblVacDone();
	BOOL IsTest();
	BOOL IsTestUp();
	BOOL IsTestDn();
	BOOL IsTestDone();
	BOOL IsTestDoneUp();
	BOOL IsTestDoneDn();
	BOOL IsStop();
	BOOL IsRun();
	int GetSerial();
	void SetMkFdLen();
	double GetMkFdLen();
	double GetTotVel();
	double GetPartVel();
	void SetCycTime();
	int GetCycTime(); // [mSec]
	void CheckCurrentInfoSignal(int nMsgID, int nData);
	void CheckMonDispMainSignal();

	BOOL IsShare();
	BOOL IsShareUp();
	BOOL IsShareDn();
	int GetShareUp();
	int GetShareDn();
	void CheckShareUp(int nSerial);
	void CheckShareDn(int nSerial);

	BOOL IsShareVs();
	BOOL IsShareVsUp();
	BOOL IsShareVsDn();
	int GetShareVsUp();
	int GetShareVsDn();
	void CheckShareVsUp(int nSerial);
	void CheckShareVsDn(int nSerial);

	void TurnLastProc();
	void TurnLastProcVs();

	BOOL IsBuffer(int nNum = 0);
	BOOL IsBufferUp();
	BOOL IsBufferDn();
	int GetBuffer(int *pPrevSerial = NULL);
	int GetBufferUp(int *pPrevSerial = NULL);
	int GetBufferDn(int *pPrevSerial = NULL);

	BOOL IsBuffer0();
	BOOL IsBufferUp0();
	BOOL IsBufferDn0();
	int GetBuffer0(int *pPrevSerial = NULL);
	int GetBufferUp0(int *pPrevSerial = NULL);
	int GetBufferDn0(int *pPrevSerial = NULL);

	BOOL IsBuffer1();
	BOOL IsBufferUp1();
	BOOL IsBufferDn1();
	int GetBuffer1(int *pPrevSerial = NULL);
	int GetBufferUp1(int *pPrevSerial = NULL);
	int GetBufferDn1(int *pPrevSerial = NULL);

	BOOL IsMkTmpStop();
	BOOL IsAuto();
	void Marking();
	void DoReject0();
	void DoReject1();
	BOOL SetSerial(int nSerial, BOOL bDumy = FALSE);

	int GetErrCode(int nSerial);
	int GetErrCodeUp(int nSerial);
	int GetErrCodeDn(int nSerial);

	int GetErrCode0(int nSerial);
	int GetErrCodeUp0(int nSerial);
	int GetErrCodeDn0(int nSerial);

	int GetErrCode1(int nSerial);
	int GetErrCodeUp1(int nSerial);
	int GetErrCodeDn1(int nSerial);

	int GetTotDefPcs(int nSerial);
	int GetTotDefPcsUp(int nSerial);
	int GetTotDefPcsDn(int nSerial);

	int GetTotDefPcs0(int nSerial);
	int GetTotDefPcsUp0(int nSerial);
	int GetTotDefPcsDn0(int nSerial);

	int GetTotDefPcs1(int nSerial);
	int GetTotDefPcsUp1(int nSerial);
	int GetTotDefPcsDn1(int nSerial);

	CfPoint GetMkPnt(int nIdx);						// CamMaster의 피스순서 인덱스
	CfPoint GetMkPnt0(int nIdx);					// CamMaster의 피스순서 인덱스
	CfPoint GetMkPnt1(int nIdx);					// CamMaster의 피스순서 인덱스
	CfPoint GetMkPnt0(int nSerial, int nMkPcs);		// pcr 시리얼, pcr 불량 피스 읽은 순서 인덱스
	CfPoint GetMkPnt1(int nSerial, int nMkPcs);		// pcr 시리얼, pcr 불량 피스 읽은 순서 인덱스

	// 	void Move(CfPoint pt, BOOL bCam=FALSE);
	void Move0(CfPoint pt, BOOL bCam = FALSE, BOOL bWait = NO_WAIT);
	void Move1(CfPoint pt, BOOL bCam = FALSE, BOOL bWait = NO_WAIT);
	BOOL IsMoveDone();
	BOOL IsMoveDone0();
	BOOL IsMoveDone1();

	BOOL UpdateReelmap(int nSerial);
	BOOL UpdateReelmapInner(int nSerial);
	BOOL MakeItsFile(int nSerial);

	void InitInfo();
	void InitReelmap();
	void InitReelmapUp();
	void InitReelmapDn();
	BOOL IsPinMkData();
	BOOL IsPinData();
	BOOL CopyDefImg(int nSerial);
	BOOL CopyDefImg(int nSerial, CString sNewLot);
	BOOL CopyDefImgUp(int nSerial, CString sNewLot = _T(""));
	BOOL CopyDefImgDn(int nSerial, CString sNewLot = _T(""));
	BOOL MovePinPos();
	BOOL MoveAlign0(int nPos);
	BOOL MoveAlign1(int nPos);
	BOOL TwoPointAlign0(int nPos);
	BOOL TwoPointAlign1(int nPos);
	BOOL FourPointAlign0(int nPos);
	BOOL FourPointAlign1(int nPos);
	BOOL OnePointAlign(CfPoint &ptPnt);
	BOOL TwoPointAlign();
	BOOL IsNoMk();
	BOOL IsNoMk0();
	BOOL IsNoMk1();
	BOOL IsHomeDone(int nMsId);
	BOOL GetAoiUpInfo(int nSerial, int *pNewLot = NULL, BOOL bFromBuf = FALSE); // TRUE: CHANGED, FALSE: NO CHANGED
	BOOL GetAoiDnInfo(int nSerial, int *pNewLot = NULL, BOOL bFromBuf = FALSE); // TRUE: CHANGED, FALSE: NO CHANGED
	BOOL ChkLotEnd(int nSerial);
	BOOL ChkLotEndUp(int nSerial);
	BOOL ChkLotEndDn(int nSerial);
	BOOL LoadMySpec();
	BOOL MemChk();
	BOOL GetEngOffset(CfPoint &OfSt);
	BOOL GetAoiUpOffset(CfPoint &OfSt);
	BOOL GetAoiDnOffset(CfPoint &OfSt);
	BOOL GetMkOffset(CfPoint &OfSt);
	BOOL IsAoiLdRun();
	void MoveInitPos0(BOOL bWait=TRUE);
	void MoveInitPos1(BOOL bWait=TRUE);
	void MoveMkEdPos1();
	BOOL IsInitPos0();
	BOOL IsInitPos1();
	BOOL IsMkEdPos1();
	void LotEnd();
	void Winker(int nId, int nDly = 20); // 0:Ready, 1:Reset, 2:Run, 3:Stop
	void ResetWinker(); // 0:Ready, 1:Reset, 2:Run, 3:Stop
	void SetOrigin();
	void SetLotEnd(int nSerial);
	int GetLotEndSerial();
	BOOL StartLive();
	BOOL StartLive0();
	BOOL StartLive1();
	BOOL StopLive();
	BOOL StopLive0();
	BOOL StopLive1();
	void ResetMkInfo(int nAoi = 0); // 0 : AOI-Up , 1 : AOI-Dn , 2 : AOI-UpDn
	void ModelChange(int nAoi = 0); // 0 : AOI-Up , 1 : AOI-Dn
	void UpdateRst();
	void ClrMkInfo();
	int GetAutoStep();
	void MoveMkInitPos();
	void MoveMk0InitPos();
	void MoveMk1InitPos();
	void TimWinker(int nId, int nDly = 5);
	void StopTimWinker(int nId);
	BOOL IsShowLive();
	BOOL IsChkTmpStop();
	BOOL ChkLastProc();
	double GetAoiUpFdLen();
	double GetAoiDnFdLen();
	BOOL IsVerify();
	BOOL IsFixPcsUp(int nSerial);
	BOOL IsFixPcsDn(int nSerial);
	BOOL IsReview();
	BOOL IsReview0();
	BOOL IsReview1();
	BOOL IsJogRtDn();
	BOOL IsJogRtUp();
	BOOL IsJogRtDn0();
	BOOL IsJogRtUp0();
	BOOL IsJogRtDn1();
	BOOL IsJogRtUp1();
	void ResetMotion();
	void ResetMotion(int nMsId);
	unsigned long ChkDoor(); // 0: All Closed , Open Door Index : Doesn't all closed. (Bit3: F, Bit2: L, Bit1: R, Bit0; B)
	BOOL ChkSaftySen();
	BOOL ChkYield();
	BOOL IsVs();
	BOOL IsVsUp();
	BOOL IsVsDn();
	int GetAoiUpSerial();
	int GetAoiDnSerial();
	BOOL GetAoiUpVsStatus();
	BOOL GetAoiDnVsStatus();
	BOOL IsDoneDispMkInfo();
	BOOL IsSetLotEnd();
	void ChkRcvSig();

	afx_msg LRESULT OnBufThreadDone(WPARAM wPara, LPARAM lPara);
	int ChkSerial(); // 0: Continue, -: Previous, +:Discontinue
	BOOL ReloadReelmap();
	BOOL IsDoneReloadReelmap(int& nProc);
	void OpenReelmap();
	void OpenReelmapUp();
	void OpenReelmapDn();
	BOOL IsRunAxisX();
	BOOL ChkCollision();
	BOOL ChkCollision(int nAxisId, double dTgtPosX);
	BOOL ChkCollision(int nAxisId, double dTgtPosX, double dTgtNextPos);
	void DoAllMk(int nCam);
	void StopAllMk();
	void EStop();
	void SetPriority();
	void ResetPriority();
	void SetAlignPos();
	void SetAlignPosUp();
	void SetAlignPosDn();
	//void MpeWrite();
	void IoWrite(CString sMReg, long lData);
	BOOL IsRdyTest();
	BOOL IsRdyTest0();
	BOOL IsRdyTest1();
	BOOL LoadPcrUp(int nSerial, BOOL bFromShare = FALSE);
	BOOL LoadPcrDn(int nSerial, BOOL bFromShare = FALSE);
	void MoveAoi(double dOffset);
	void MoveMk(double dOffset);
	BOOL IsMk0Done();
	BOOL IsMk1Done();
	void InitIoWrite();

	void SetLastProc();
	BOOL IsLastProc();
	BOOL IsLastJob(int nAoi); // 0 : AOI-Up , 1 : AOI-Dn , 2 : AOI-UpDn

	void DispContRun(BOOL bOn);
	void DispLotEnd(BOOL bOn);

	void MonPlcSignal();
	void MonPlcAlm();
	void MonDispMain();
	void PlcAlm(BOOL bMon, BOOL bClr);
	void FindAlarm();
	void ResetMonAlm();
	void ClrAlarm();
	void ResetClear();

	void ChkTempStop(BOOL bChk);
	void ChgLot();

	void SetLotLastShot();
	int GetMkStripIdx0(int nDefPcsId); // 0 : Fail , 1~4 : Strip Idx
	int GetMkStripIdx1(int nDefPcsId); // 0 : Fail , 1~4 : Strip Idx
	int GetMkStripIdx0(int nSerial, int nMkPcs); // 0 : Fail , 1~4 : Strip Idx
	int GetMkStripIdx1(int nSerial, int nMkPcs); // 0 : Fail , 1~4 : Strip Idx
	CString GetMkInfo0(int nSerial, int nMkPcs);
	CString GetMkInfo1(int nSerial, int nMkPcs);

	BOOL IsMkStrip(int nStripIdx);
	void CycleStop();
	BOOL ChkLotCutPos();
	BOOL OpenReelmapFromBuf(int nSerial);

	void SetPathAtBuf();
	void SetPathAtBufUp();
	void SetPathAtBufDn();
	BOOL LoadPcrFromBuf();

	BOOL SetSerialReelmap(int nSerial, BOOL bDumy = FALSE);
	BOOL SetSerialMkInfo(int nSerial, BOOL bDumy = FALSE);
	BOOL ChkLastProcFromUp();
	BOOL ChkLastProcFromEng();

	void CntMk();
	void ChkMyMsg();
	BOOL ReloadReelmap(int nSerial);
	BOOL IsSameUpDnLot();
	BOOL ChkStShotNum();
	BOOL ChkContShotNum();
	void SetFixPcs(int nSerial);

	BOOL RemakeReelmap();	// MDS(해성DS) Style의 릴맵으로 재생성
	BOOL IsDoneRemakeReelmap();
	BOOL RemakeReelmapInner();
	BOOL IsDoneRemakeReelmapInner();
	void MakeSapp3();
	void GetResult();
	void MakeResult();
	void MakeResultIts();
	BOOL WriteLastRmapInfo();
	void MakeResultMDS();

	BOOL MoveMeasPos(int nId); // Elec Chk
	void SetReject();

	BOOL ChkLightErr();
	BOOL IsOnMarking0();
	BOOL IsOnMarking1();

	void SetDualTest(BOOL bOn = TRUE);
	void SetTwoMetal(BOOL bSel, BOOL bOn = TRUE);
	void SetFeedDir(int nUnit, BOOL bCcw);

	void DispStsBar(CString sMsg, int nIdx = 0);

	void AdjPinPos();

	BOOL m_bStopFromThread, m_bBuzzerFromThread;
	void StopFromThread();
	void BuzzerFromThread(BOOL bOn, int nCh = 0);

	BOOL IsEngraveFd();
	void MoveEngrave(double dOffset);

	double GetEngraveFdLen();
	double GetAoiInitDist();
	double GetAoiRemain();
	void SetEngraveFdPitch(double dPitch);
	void DestroyView();

	BOOL IsPinPos0();
	BOOL IsPinPos1();

	void UpdateYield();
	void UpdateYield(int nSerial);
	void UpdateYieldUp(int nSerial);
	void UpdateYieldDn(int nSerial);
	void UpdateYieldAllUp(int nSerial);
	void UpdateYieldAllDn(int nSerial);
	void UpdateYieldInnerUp(int nSerial);
	void UpdateYieldInnerDn(int nSerial);
	void UpdateYieldInnerAllUp(int nSerial);
	void UpdateYieldInnerAllDn(int nSerial);
	void UpdateYieldIts(int nSerial);

	//void SetEngFd();
	void MoveEng(double dOffset);
	//BOOL GetEngOffset(CfPoint &OfSt);

	void SetMyMsgYes();
	void SetMyMsgNo();
	void SetMyMsgOk();

	BOOL GetCurrentInfoSignal();
	void InitAutoEngSignal();
	BOOL GetCurrentInfoEng();
	BOOL IsConnectedSr();
	BOOL IsConnectedEng();

	CString m_sGet2dCodeLot;
	int m_nGet2dCodeSerial;
	BOOL Get2dCode(CString &sLot, int &nSerial);
	BOOL Set2dRead(BOOL bRun = TRUE);
	BOOL Is2dReadDone();

	int m_nReloadReelmapSerial;
	void ReloadReelmapUp();
	void ReloadReelmapAllUp();
	void ReloadReelmapDn();
	void ReloadReelmapAllDn();

	void ReloadReelmapUpInner();
	void ReloadReelmapAllUpInner();
	void ReloadReelmapDnInner();
	void ReloadReelmapAllDnInner();
	void ReloadReelmapIts();

	BOOL m_bSetSig, m_bSetSigF, m_bSetData, m_bSetDataF;
	BOOL m_bLoadMstInfo, m_bLoadMstInfoF;
	BOOL m_bTIM_START_UPDATE;


	BOOL m_bEscape;
	// ITS
	BOOL m_bTHREAD_MAKE_ITS_FILE_UP, m_bTHREAD_MAKE_ITS_FILE_DN;
	BOOL m_bTHREAD_UPDATE_REELMAP_INNER_UP, m_bTHREAD_UPDATE_REELMAP_INNER_ALLUP;
	BOOL m_bTHREAD_UPDATE_REELMAP_INNER_DN, m_bTHREAD_UPDATE_REELMAP_INNER_ALLDN;
	BOOL m_bTHREAD_UPDATE_REELMAP_ITS;
	BOOL WriteReelmapIts();

	void SetInnerPathAtBuf();
	void SetInnerPathAtBufUp();
	void SetInnerPathAtBufDn();

	void DoMark0Its();
	void DoMark1Its();

	int GetErrCode0Its(int nSerial); // 1(정상), -1(Align Error, 노광불량), -2(Lot End)
	int GetErrCodeUp0Its(int nSerial); // 1(정상), -1(Align Error, 노광불량), -2(Lot End)
	int GetErrCodeDn0Its(int nSerial); // 1(정상), -1(Align Error, 노광불량), -2(Lot End)

	int GetErrCode1Its(int nSerial); // 1(정상), -1(Align Error, 노광불량), -2(Lot End)
	int GetErrCodeUp1Its(int nSerial); // 1(정상), -1(Align Error, 노광불량), -2(Lot End)
	int GetErrCodeDn1Its(int nSerial); // 1(정상), -1(Align Error, 노광불량), -2(Lot End)

	int GetTotDefPcs0Its(int nSerial);
	int GetTotDefPcsUp0Its(int nSerial);
	int GetTotDefPcsDn0Its(int nSerial);

	int GetTotDefPcs1Its(int nSerial);
	int GetTotDefPcsUp1Its(int nSerial);
	int GetTotDefPcsDn1Its(int nSerial);

	CfPoint GetMkPnt0Its(int nSerial, int nMkPcs); // pcr 시리얼, pcr 불량 피스 읽은 순서 인덱스
	CfPoint GetMkPnt1Its(int nSerial, int nMkPcs); // pcr 시리얼, pcr 불량 피스 읽은 순서 인덱스

	int GetMkStripIdx0Its(int nSerial, int nMkPcs); // 0 : Fail , 1~4 : Strip Idx
	int GetMkStripIdx1Its(int nSerial, int nMkPcs); // 0 : Fail , 1~4 : Strip Idx

	BOOL SetMkIts(BOOL bRun);	// Marking Start
	BOOL CheckMkPnt();

	BOOL m_bTHREAD_DISP_DEF_INNER;
	int	m_nStepTHREAD_DISP_DEF_INNER;

	void InitReelmapInner();
	void InitReelmapInnerUp();
	void InitReelmapInnerDn();
	BOOL ReloadReelmapInner();
	BOOL ReloadReelmapInner(int nSerial);
	BOOL IsDoneReloadReelmapInner(int& nProc);
	void UpdateRstInner();
	void OpenReelmapInner();
	void OpenReelmapInnerUp();
	void OpenReelmapInnerDn();
	void DispDefImgInner();
	BOOL IsDoneDispMkInfoInner();
	BOOL SetSerialReelmapInner(int nSerial, BOOL bDumy = FALSE);
	BOOL SetSerialMkInfoInner(int nSerial, BOOL bDumy = FALSE);

	CString GetTimeIts();

	int GetAoiUpAutoStep();
	void SetAoiUpAutoStep(int nStep);
	int GetAoiUpAutoSerial();
	void SetAoiUpAutoSerial(int nSerial);
	CString GetAoiUpAlarmRestartMsg();
	CString GetAoiUpAlarmReTestMsg();

	int GetAoiDnAutoStep();
	void SetAoiDnAutoStep(int nStep);
	int GetAoiDnAutoSerial();
	void SetAoiDnAutoSerial(int nSerial);
	CString GetAoiDnAlarmRestartMsg();
	CString GetAoiDnAlarmReTestMsg();

	void DelOverLotEndSerialUp(int nSerial);
	void DelOverLotEndSerialDn(int nSerial);
	void ChkReTestAlarmOnAoiUp();
	void ChkReTestAlarmOnAoiDn();
	void ShowMsgBox();
	BOOL FinalCopyItsFiles();

	// DTS
	BOOL m_bSerialDecrese;
	BOOL GetDtsPieceOut(int nSerial, int* pPcsOutIdx, int& nTotPcsOut);
	CString GetCurrentDBName();

	int GetAoiUpCamMstInfo();
	int GetAoiDnCamMstInfo();

	void DuplicateRmap(int nRmap);
	int GetMkStAuto();
	void SetMkStAuto();
	//BOOL GetMkStSignal();
	void LoadSerial();
	BOOL MpeWrite(CString strRegAddr, long lData, BOOL bCheck = FALSE);
	long MpeRead(CString strRegAddr);
	void SetAlarmToPlc(int nFromUnit);

	BOOL IsClampOff();
	void ClampOn();
	void SetMkReStart();
	void ErrorRead2dCode(int nMcId);
	void SetJobEndEngrave();

	BOOL CheckCamMstInfo(int nLayer, int nSerial); // AOI에서 들어오는 PCR정보의 피스 인덱스가 캠정보를 overflow하는 지를 확인 ( FALSE : 비정상, TRUE : 정상 )
	void ClearBuffer();
	BOOL IsDoneReloadReelmap();
	BOOL IsDoneReloadYield();
	void InitVoiceCoil(int nCam);
	BOOL IsSetPinPos();

	BOOL SetMkPcs0(int nSerial, int nMkPcs); // pcr 시리얼, pcr 불량 피스 마킹 순서 인덱스
	BOOL SetMkPcs1(int nSerial, int nMkPcs); // pcr 시리얼, pcr 불량 피스 마킹 순서 인덱스

	BOOL ApplyListTorq();
	BOOL ApplyTorq(double dTorqL, double dTorqR);
	int GetModelThickness(CString sModel);
	int SearchModel(CString sModel);
	BOOL GetTorque(int nUnit, int nThick, double &dTorqL, double &dTorqR);
	CString GetThicknessName(int nIdx); // 설정없음[0], 얇은 두께[1], 중간 두께[2], 두꺼운 두께[3]
	void Mk4PtShift2Mk();

	CString m_sLogAuto[2]; // [nCam] : 0(Left), 1(Right)
	BOOL m_bFailMkJudge[2]; // [nCam] : 0(Left), 1(Right)
	BOOL SetArMkMtRstOnLogAuto(int nCam); // [nCam] : 0(Left), 1(Right)
	BOOL GetArMkMtRst(int nCam, int &nRef, int &nAvg, int &nMin, int &nMax);
	CString GetMarkedPcsList(int nCam); // [nCam] : 0(Left), 1(Right)
	CString GetMkMtInfo0(int nSerial, int nMkPcs);
	CString GetMkMtInfo1(int nSerial, int nMkPcs);

	BOOL ChkRepunching(int nCam);


// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

	afx_msg LRESULT wmClientReceived(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT wmClientReceivedSr(WPARAM wParam, LPARAM lParam);

// 구현입니다.
public:
	virtual ~CGvisR2R_PunchView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg LRESULT OnDlgInfo(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // GvisR2R_PunchView.cpp의 디버그 버전
inline CGvisR2R_PunchDoc* CGvisR2R_PunchView::GetDocument() const
   { return reinterpret_cast<CGvisR2R_PunchDoc*>(m_pDocument); }
#endif

