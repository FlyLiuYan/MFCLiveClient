
// MFCLiveClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCLiveClient.h"
#include "MFCLiveClientDlg.h"
#include "afxdialogex.h"
#include "Manager.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define  WM_NC  (WM_USER + 1000)

// CMFCLiveClientDlg �Ի���

#include "LogonDlg.h"

CMFCLiveClientDlg::CMFCLiveClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCLiveClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCLiveClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCLiveClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCLiveClientDlg::OnBnClickedOk)
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(WM_NC, &CMFCLiveClientDlg::OnNotifyIcon)
	//ON_MESSAGE(WM_NC, &OnNotifyIcon)
	ON_WM_NCRBUTTONUP()
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()


// CMFCLiveClientDlg ��Ϣ�������

BOOL CMFCLiveClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_bMinDialog = false;//�������
	CManager::GetInstance()->SetMsgDlg(this);
	MoveWindow(-500, -500, 100, 100);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCLiveClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCLiveClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCLiveClientDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CMFCLiveClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nID == SC_RESTORE)
	{
		CManager::GetInstance()->SetMinDlgShow();
		m_bMinDialog = false;
	}
	CDialogEx::OnSysCommand(nID, lParam);
}


void CMFCLiveClientDlg::MinDialog()
{
	m_bMinDialog = true;
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
	return;
	/*����
	NotifyIcon.cbSize = sizeof(NOTIFYICONDATA);
	NotifyIcon.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	NotifyIcon.hWnd = m_hWnd;
	lstrcpy(NotifyIcon.szTip, _T("NotifyIcon Test"));
	NotifyIcon.uCallbackMessage = WM_NC;
	NotifyIcon.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	Shell_NotifyIcon(NIM_ADD, &NotifyIcon);//�����������ͼ��
	ShowWindow(SW_HIDE);//����������
	Shell_NotifyIcon(NIM_ADD, &NotifyIcon);
	*/
}
LRESULT  CMFCLiveClientDlg::OnNotifyIcon(WPARAM wParam, LPARAM IParam)
{
	/*����ģ��ȡ��
	if ((IParam == WM_LBUTTONDOWN) || (IParam == WM_RBUTTONDOWN))
	{
	//  ModifyStyleEx(0, WS_EX_TOPMOST);
		ShowWindow(SW_SHOW);
		//Shell_NotifyIcon(NIM_DELETE, &NotifyIcon);//��������ͼ��
	}
	*/
	return 0;
}

void CMFCLiveClientDlg::OnNcRButtonUp(UINT nHitTest, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnNcRButtonUp(nHitTest, point);
}


void CMFCLiveClientDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}



