#pragma once


class CMFCLiveClientDlg;
class LogonDlg;
class CManager
{
public:
	static CManager * GetInstance()
	{
		if (m_pInstance == NULL)  //判断是否第一次调用   
			m_pInstance = new CManager();
		return m_pInstance;
	}
	static CManager *m_pInstance;
private:
	CManager();
	~CManager();
	int m_iScreenWidth;
	int m_iScreenHeight;
	CMFCLiveClientDlg* m_pMsgDlg;//消息对话
	LogonDlg* m_pLogonDlg;//登录对话框
	int m_iMinDlg;
public:
	void SetMsgDlg(CMFCLiveClientDlg* dlg){ m_pMsgDlg = dlg; };
	int GetScreenWidth(){ return m_iScreenWidth; };
	int GetScreenHeight(){ return m_iScreenHeight; };
	void CloseClient();
	void SetMin(int numID);
	void SetMinDlgShow();
};

