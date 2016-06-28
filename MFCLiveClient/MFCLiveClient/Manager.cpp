#include "stdafx.h"
#include "resource.h"
#include "Manager.h"
#include "MFCLiveClientDlg.h"
#include "LogonDlg.h"

CManager* CManager::m_pInstance = 0;
CManager::CManager()
{
	m_iScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	m_iScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	m_pLogonDlg = new LogonDlg();
	m_pLogonDlg->Create(IDD_DIALOG_LOGON);
	m_pLogonDlg->MoveWindow(m_iScreenWidth / 2 - 200, m_iScreenHeight / 2 - 200, 460, 340, 1);
	m_pLogonDlg->ShowWindow(SW_SHOWNORMAL);
	m_iMinDlg = 0;

	
}


CManager::~CManager()
{
}
void CManager::CloseClient()
{
	delete m_pLogonDlg;
	m_pLogonDlg = NULL;
	delete m_pMsgDlg;
	m_pMsgDlg = NULL;
	delete m_pInstance;
	m_pInstance = NULL;

}
void CManager::SetMin(int numID)
{
	m_iMinDlg = numID;
	m_pMsgDlg->MinDialog();
}
void CManager::SetMinDlgShow()
{
	if (m_iMinDlg == 1)
	{
		m_pLogonDlg->ShowWindow(SW_SHOWNORMAL);
	} 
	else
	{
	}
}