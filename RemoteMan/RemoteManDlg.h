
// RemoteManDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

//������ID��
enum {IDC_TOOLER_NEW=10001,IDC_TOOLER_EDIT,IDC_TOOLER_DEL,IDC_TOOLER_ADDGROUP,IDC_TOOLER_ADDROOTGROUP,IDC_TOOLER_DELGROUP,
	IDC_TOOLER_OPEN,IDC_TOOLER_RADMIN,IDC_TOOLER_MSTSC, IDC_TOOLER_SSH, IDC_TOOLER_SET};

// CRemoteManDlg �Ի���
class CRemoteManDlg : public CDialogEx
{
// ����
public:
	CRemoteManDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_REMOTEMAN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON			m_hIcon;
	CToolBar		m_ToolBar;
	CImageList		m_ImageList,m_ToolbarImageList;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void InitToolBar(void);
	CStatic m_Ico;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListCtrl m_List;
};
