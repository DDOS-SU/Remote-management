// InputPasswordDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RemoteMan.h"
#include "InputPasswordDlg.h"
#include "afxdialogex.h"


// CInputPasswordDlg �Ի���

IMPLEMENT_DYNAMIC(CInputPasswordDlg, CDialogEx)

CInputPasswordDlg::CInputPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputPasswordDlg::IDD, pParent)
	, m_Password(_T(""))
{

}

CInputPasswordDlg::~CInputPasswordDlg()
{
}

void CInputPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Password);
}


BEGIN_MESSAGE_MAP(CInputPasswordDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInputPasswordDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CInputPasswordDlg ��Ϣ�������


void CInputPasswordDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_Password.GetLength()>0)
		CDialogEx::OnOK();
}
