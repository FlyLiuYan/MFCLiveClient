
// MFCLiveClientDlg.h : ͷ�ļ�
//

#pragma once


// CMFCLiveClientDlg �Ի���
class CMFCLiveClientDlg : public CDialogEx
{
// ����
public:
	CMFCLiveClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCLIVECLIENT_DIALOG };

	void MinDialog();
	bool m_bMinDialog;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	NOTIFYICONDATA NotifyIcon;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg LRESULT  OnNotifyIcon(WPARAM wParam, LPARAM IParam);
	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);

};
