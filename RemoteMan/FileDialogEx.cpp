// FileDialogEx.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RemoteMan.h"
#include "FileDialogEx.h"


// CFileDialogEx

IMPLEMENT_DYNAMIC(CFileDialogEx, CFileDialog)

CFileDialogEx::CFileDialogEx(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	m_GroupName[0]=0;
	m_GroupSel=0;
	m_ofn.Flags |= dwFlags|OFN_EXPLORER|OFN_ENABLETEMPLATE;
	m_dwRef = 1;                  
	m_bVistaStyle = FALSE;
	SetTemplate(0,IDD_DIALOG_FILEDIALOG_SEL_GROUP);
}

CFileDialogEx::~CFileDialogEx()
{
}


BEGIN_MESSAGE_MAP(CFileDialogEx, CFileDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CFileDialogEx::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()



// CFileDialogEx ��Ϣ�������




BOOL CFileDialogEx::OnInitDialog()
{
	CFileDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CComboBox *pBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	pBox->AddString("��Ŀ¼");
	if (m_GroupName[0]!=0)
	{
		pBox->AddString(m_GroupName);
		m_GroupSel=1;
	}
	pBox->SetCurSel(m_GroupSel);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CFileDialogEx::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_GroupSel=((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
}


void CFileDialogEx::SetGroupName(char const * Name)
{
	strcpy_s(m_GroupName,sizeof(m_GroupName),Name);
}
