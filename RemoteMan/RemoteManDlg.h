
// RemoteManDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "sqlite3.h"
#include "SysSetDlg.h"
#include "AddGroupDlg.h"
#include "AddHostDlg.h"

struct CONFIG_STRUCT{
	int  DatabaseVer;
	int  GroupLastSelId;				//�ϴιػ�ʱ�򿪵���ID
	char SysPassword[66];				//ϵͳ���룬ʹ��AES�������31�ֽ�����
	bool ParentShowHost;				//�������Ƿ���ʾ�ӷ��������
	char RadminPath[256];				//RADMIN·�������Ϊ�գ���ΪͬĿ¼�µ�radmin.exe
	char SSHPath[256];					//SSH·�������Ϊ�գ���ΪͬĿ¼�µ�SecureCRT.exe
	char VNCPath[256];					//VNC·��
	int  CheckOnlineTimeOut;			//���߼�ⳬʱʱ��ms
	bool MstscConsole;					//Զ������ʹ��Console����
	bool MstscUseDrive;					//�Ƿ����ӱ��ط���
	char MstscLocalDrive[24];			//Զ������ӳ�䱾�ط�������ʽ:CDEF
	bool MstscRemoteAudio;				//Զ������ʹ��Զ����Ƶ
	int  MstscColor;					//Զ��������ɫ
	int  MstscWinpos;					//Զ������ֱ���
	bool MstscDeskImg;					//Զ������ʹ�����汳��
	bool MstscFontSmooth;				//Զ������ʹ������ƽ��
	bool MstscThemes;					//Զ�������Ӿ���ʽ
	int  RadminCtrlMode;				//RADMIN����ģʽ
	bool RadminFullScreen;				//RADMINʹ��ȫ������
	int  RadminColor;					//RADMIN��ɫ
};

struct GROUP_STRUCT 
{
	int		Id;
	char	Name[64];
	int		Parent;
};

// CRemoteManDlg �Ի���
class CRemoteManDlg : public CDialogEx
{
//������ID��
enum {IDC_TOOLER_OPENRADMIN=10001,IDC_TOOLER_OPENMSTSC, IDC_TOOLER_OPENSSH, IDC_TOOLER_SET};
// ����
public:
	CRemoteManDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CRemoteManDlg();

// �Ի�������
	enum { IDD = IDD_REMOTEMAN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:    
	int m_nListDragIndex; 
	CImageList *m_pDragImage;

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
	CONFIG_STRUCT SysConfig;
	sqlite3	*m_pDB;
	afx_msg void OnBnClickedOk();
	void InitToolBar(void);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListCtrl m_List;
	void OnToolbarClickedSysSet(void);
	bool OpenUserDb(char const *DbPath);
	CTreeCtrl m_Tree;
	void EnumTreeData(HTREEITEM hItem, int ParentNode);
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	void LoadHostList(HTREEITEM hItem);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	afx_msg LRESULT OnModifyPasswordMessage(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedCheckMstConsole();
	afx_msg void OnBnClickedCheckMstDrive();
	afx_msg void OnBnClickedCheckMstAudio();
	afx_msg void OnCbnSelchangeComboMstWinpos();
	afx_msg void OnBnClickedCheckRadminFullscreen();
	afx_msg void OnCbnSelchangeComboRadminCtrlmode();
	void OnMenuClickedAddGroup(void);
	void OnMenuClickedDelGroup(void);
	void OnMenuClickedAddHost(void);
	void OnMenuClickedEditHost(void);
	void OnMenuClickedDelHost(void);
	void OnToolbarClickedOpenMstsc(void);
	void OnToolbarClickedOpenRadmin(void);
	void OnToolbarClickedOpenSSH(void);
	void OnMenuClickedConnentHost(void);
	void EnumChildGroupId(HTREEITEM hItem,CArray<int ,int>&GroupArray);
protected:
	afx_msg LRESULT OnAddHostMessage(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnNMRClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult);

	void MstscConnent(HOST_STRUCT const *pHost, CONFIG_STRUCT const *pConfig);
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	void OnMenuClickedRadminCtrl(UINT Id);
	void ConnentHost(int RadminCtrlMode);
	afx_msg void OnLvnBegindragList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMenuClickedRenameGroup(void);
	afx_msg void OnTvnEndlabeleditTree1(NMHDR *pNMHDR, LRESULT *pResult);
	void ListAddHost(HOST_STRUCT const * pHost, int Id);
	void OnMenuClickedExportGroup(void);
	void OnMenuClickedImportGroup(void);
	void ImportGroup(HTREEITEM hItem, int ExportId);
	afx_msg void OnBnClickedBtnCheckOnline();
	afx_msg void OnBnClickedBtnSearch();
	void DataBaseConversion(int Ver);
};
