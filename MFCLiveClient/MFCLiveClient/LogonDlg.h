#pragma once


// LogonDlg 对话框

class LogonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LogonDlg)

public:
	LogonDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LogonDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_LOGON };
	BOOL OnInitDialog();
	void MinDialog();
	void ToTray();
	NOTIFYICONDATA NotifyIcon;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedMin();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	
};
