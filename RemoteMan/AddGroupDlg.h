#pragma once


// CAddGroupDlg �Ի���

class CAddGroupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddGroupDlg)

public:
	bool m_AddRoot;
	char m_GroupName[64];
	CAddGroupDlg(char const *GroupName, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddGroupDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
