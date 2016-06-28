#pragma once


class CMFCLiveClientDlg;
class LogonDlg;
class CManager
{
public:
	static CManager * GetInstance()
	{
		if (m_pInstance == NULL)  //�ж��Ƿ��һ�ε���   
			m_pInstance = new CManager();
		return m_pInstance;
	}
	static CManager *m_pInstance;
private:
	CManager();
	~CManager();
	int m_iScreenWidth;
	int m_iScreenHeight;
	CMFCLiveClientDlg* m_pMsgDlg;//��Ϣ�Ի�
	LogonDlg* m_pLogonDlg;//��¼�Ի���
	int m_iMinDlg;
public:
	void SetMsgDlg(CMFCLiveClientDlg* dlg){ m_pMsgDlg = dlg; };
	int GetScreenWidth(){ return m_iScreenWidth; };
	int GetScreenHeight(){ return m_iScreenHeight; };
	void CloseClient();
	void SetMin(int numID);
	void SetMinDlgShow();
};

