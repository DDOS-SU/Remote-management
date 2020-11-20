// AddGroupDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RemoteMan.h"
#include "AddGroupDlg.h"
#include "afxdialogex.h"


// CAddGroupDlg �Ի���

IMPLEMENT_DYNAMIC(CAddGroupDlg, CDialogEx)

CAddGroupDlg::CAddGroupDlg(char const *GroupName, CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddGroupDlg::IDD, pParent)
{
	strcpy_s(m_GroupName,sizeof(m_GroupName),GroupName);
}

CAddGroupDlg::~CAddGroupDlg()
{
}

void CAddGroupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddGroupDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddGroupDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddGroupDlg ��Ϣ�������


BOOL CAddGroupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	int sel=0;
	CComboBox *pBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	pBox->AddString("��Ŀ¼");
	if (m_GroupName[0]!=0)
	{
		pBox->AddString(m_GroupName);
		sel=1;
	}
	pBox->SetCurSel(sel);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CAddGroupDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItemText(IDC_EDIT1,str);
	str.Trim();
	if (str.GetLength()==0)
	{
		MessageBox("�������������","����");
		return;
	}
	strcpy_s(m_GroupName,sizeof(m_GroupName),str);

	m_AddRoot = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel()==0;
	CDialogEx::OnOK();
}
