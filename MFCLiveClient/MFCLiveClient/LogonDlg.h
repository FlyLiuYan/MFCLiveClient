#pragma once


// LogonDlg �Ի���

class LogonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LogonDlg)

public:
	LogonDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LogonDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_LOGON };
	BOOL OnInitDialog();
	void MinDialog();
	void ToTray();
	NOTIFYICONDATA NotifyIcon;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedMin();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	
};
