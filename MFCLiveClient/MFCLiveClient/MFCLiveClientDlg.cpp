
// MFCLiveClientDlg.cpp : 实现文件
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

// CMFCLiveClientDlg 对话框

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


// CMFCLiveClientDlg 消息处理程序

BOOL CMFCLiveClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_bMinDialog = false;//检测托盘
	CManager::GetInstance()->SetMsgDlg(this);
	MoveWindow(-500, -500, 100, 100);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCLiveClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCLiveClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCLiveClientDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CMFCLiveClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
	/*托盘
	NotifyIcon.cbSize = sizeof(NOTIFYICONDATA);
	NotifyIcon.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	NotifyIcon.hWnd = m_hWnd;
	lstrcpy(NotifyIcon.szTip, _T("NotifyIcon Test"));
	NotifyIcon.uCallbackMessage = WM_NC;
	NotifyIcon.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	Shell_NotifyIcon(NIM_ADD, &NotifyIcon);//在托盘区添加图标
	ShowWindow(SW_HIDE);//隐藏主窗口
	Shell_NotifyIcon(NIM_ADD, &NotifyIcon);
	*/
}
LRESULT  CMFCLiveClientDlg::OnNotifyIcon(WPARAM wParam, LPARAM IParam)
{
	/*托盘模块取消
	if ((IParam == WM_LBUTTONDOWN) || (IParam == WM_RBUTTONDOWN))
	{
	//  ModifyStyleEx(0, WS_EX_TOPMOST);
		ShowWindow(SW_SHOW);
		//Shell_NotifyIcon(NIM_DELETE, &NotifyIcon);//消除托盘图标
	}
	*/
	return 0;
}

void CMFCLiveClientDlg::OnNcRButtonUp(UINT nHitTest, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnNcRButtonUp(nHitTest, point);
}


void CMFCLiveClientDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}



