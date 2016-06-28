// LogonDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCLiveClient.h"
#include "LogonDlg.h"
#include "afxdialogex.h"
#include "Manager.h"
#define  WM_NC  (WM_USER + 1000)
// LogonDlg 对话框

IMPLEMENT_DYNAMIC(LogonDlg, CDialogEx)

LogonDlg::LogonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogonDlg::IDD, pParent)
{
	
}

LogonDlg::~LogonDlg()
{
}

void LogonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogonDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &LogonDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &LogonDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDCANCEL_MIN, &LogonDlg::OnBnClickedMin)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// LogonDlg 消息处理程序


void LogonDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void LogonDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
	CManager::GetInstance()->CloseClient();
}


void LogonDlg::OnBnClickedMin()
{
	// TODO:  在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
	CManager::GetInstance()->SetMin(1);
	
}

BOOL LogonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void LogonDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnLButtonUp(nFlags, point);
}
