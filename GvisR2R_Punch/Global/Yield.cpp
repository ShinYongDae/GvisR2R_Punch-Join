// Yield.cpp: implementation of the CYield class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "../stdafx.h"
//#include "../gvisr2r_punch.h"
#include "Yield.h"

#include "../GvisR2R_PunchView.h"
extern CGvisR2R_PunchView* pView;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CYield::CYield()
{
	bValid = FALSE;
	nCol=0; nRow=0;
	m_nSerial=0;
	dYieldAll = 0.0;
	for(int i=0; i < MAX_STRIP_NUM; i++)
	{ 
		dYield[i]=0.0;
		nTotDef[i]=0;
	}

	nTot=0;
	nAllDef=0;
}

CYield::~CYield()
{
	bValid = FALSE;
}

void CYield::SetDef(int nSerial, int *pDef)	// int pDef[4];
{
	if(nSerial <= 0)
	{
			
		pView->SetAlarmToPlc(UNIT_PUNCH); pView->ClrDispMsg(); AfxMessageBox(_T("Serial Error.66"));
		return;
	}

	if(nSerial>m_nSerial)
	{
		bValid = TRUE;
		m_nSerial = nSerial;
		nTot = nCol*nRow*m_nSerial;
		nAllDef=0;
		int nTotSt = nTot/ MAX_STRIP_NUM;
		for(int i=0; i<MAX_STRIP_NUM; i++)
		{
			nTotDef[i] += pDef[i];
			dYield[i] = 100.0*(double)(nTotSt-nTotDef[i])/(double)nTotSt;
			nAllDef += nTotDef[i];
		}
		dYieldAll = 100.0*(double)(nTot-nAllDef)/(double)nTot;
	}
}

BOOL CYield::IsValid()
{
	return bValid;
}

double CYield::GetYield()
{
	return dYieldAll;
}

double CYield::GetYield(int nStrip)
{
	return dYield[nStrip];
}

int CYield::GetDef()
{
	return nAllDef;
}

int CYield::GetDef(int nStrip)
{
	return nTotDef[nStrip];
}

int CYield::GetGood()
{
	return ((int)(nTot-nAllDef));
}

int CYield::GetGood(int nStrip)
{
	int nTotSt = nTot/ MAX_STRIP_NUM;
	return ((int)(nTotSt-nTotDef[nStrip]));
}