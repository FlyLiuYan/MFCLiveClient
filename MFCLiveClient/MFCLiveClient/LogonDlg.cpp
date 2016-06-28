// LogonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCLiveClient.h"
#include "LogonDlg.h"
#include "afxdialogex.h"
#include "Manager.h"
#define  WM_NC  (WM_USER + 1000)
// LogonDlg �Ի���

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


// LogonDlg ��Ϣ�������


void LogonDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void LogonDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
	CManager::GetInstance()->CloseClient();
}


void LogonDlg::OnBnClickedMin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
	CManager::GetInstance()->SetMin(1);
	
}

BOOL LogonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void LogonDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnLButtonUp(nFlags, point);
}
