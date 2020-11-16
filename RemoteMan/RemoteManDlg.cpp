
// RemoteManDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RemoteMan.h"
#include "RemoteManDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRemoteManDlg �Ի���




CRemoteManDlg::CRemoteManDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRemoteManDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRemoteManDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIC, m_Ico);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CRemoteManDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CRemoteManDlg::OnBnClickedOk)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRemoteManDlg ��Ϣ�������
void CRemoteManDlg::InitToolBar(void)
{
	m_ToolbarImageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
	m_ToolbarImageList.SetBkColor(RGB(255,255,255));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_ADDNODE));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_ADDNODE));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_DELNODE));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_PC));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_EDIT));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_DEL));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_OPEN));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_RADMIN));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_SSH));
	m_ToolbarImageList.Add(AfxGetApp()->LoadIcon(IDI_SET));

	UINT array[14]={IDC_TOOLER_ADDROOTGROUP,IDC_TOOLER_ADDGROUP,IDC_TOOLER_DELGROUP,ID_SEPARATOR,
					IDC_TOOLER_NEW,IDC_TOOLER_EDIT,IDC_TOOLER_DEL,ID_SEPARATOR,
					IDC_TOOLER_OPEN,IDC_TOOLER_MSTSC,IDC_TOOLER_RADMIN,IDC_TOOLER_SSH,ID_SEPARATOR,
					IDC_TOOLER_SET};
	m_ToolBar.Create(this);
	m_ToolBar.SetButtons(array,14);
	m_ToolBar.SetButtonText(0,"��Ӹ�����");
	m_ToolBar.SetButtonText(1,"��ӷ���");
	m_ToolBar.SetButtonText(2,"ɾ������");

	m_ToolBar.SetButtonText(4,"��ӷ�����");
	m_ToolBar.SetButtonText(5,"�༭������");
	m_ToolBar.SetButtonText(6,"ɾ��������");

	m_ToolBar.SetButtonText(8,"����");
	m_ToolBar.SetButtonText(9,"Զ������");
	m_ToolBar.SetButtonText(10,"Radmin");
	m_ToolBar.SetButtonText(11,"SSH");

	m_ToolBar.SetButtonText(13,"����");

	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ToolbarImageList);
	m_ToolBar.SetSizes(CSize(72,56),CSize(20,34));
	m_ToolBar.EnableToolTips(TRUE);

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
}

BOOL CRemoteManDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	HICON hico=(HICON)LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_MSTSC),IMAGE_ICON,64,64,LR_DEFAULTCOLOR);
	m_Ico.SetIcon(hico);

	InitToolBar();
	SetDlgItemText(IDC_EDIT1,"����ӷ�����");

	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_List.InsertColumn(0,"����",LVCFMT_LEFT,72);
	m_List.InsertColumn(1,"����������",LVCFMT_LEFT,160);
	m_List.InsertColumn(2,"����",LVCFMT_LEFT,150);
	m_List.InsertColumn(3,"�˿�",LVCFMT_LEFT,64);
	m_List.InsertColumn(4,"�˻�",LVCFMT_LEFT,120);



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRemoteManDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRemoteManDlg::OnPaint()
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
HCURSOR CRemoteManDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRemoteManDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CDialogEx::OnOK();
} 



HBRUSH CRemoteManDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ����� 
	return hbr;
}
