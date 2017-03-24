
// randDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "rand.h"
#include "randDlg.h"
#include "afxdialogex.h"
#include "MyNewview.h"
#include "Ccoordinate.h"
#include "Cpublic.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CrandDlg 对话框



CrandDlg::CrandDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CrandDlg::IDD, pParent)
	, m_maxA(0)
	, m_len(0)
	, m_numA(0)
	, m_max(0)
	, m_numB(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CrandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT1, m_rd);
	//  DDX_Text(pDX, IDC_EDIT2, row);
	//  DDX_Text(pDX, IDC_EDIT2, r);
	//  DDX_Text(pDX, IDC_EDIT3, max);
	//DDX_Text(pDX, IDC_EDIT3, maxA);
	////  DDX_Text(pDX, IDC_EDIT4, numberA);
	//DDX_Text(pDX, IDC_EDIT2, len);
	//DDX_Text(pDX, IDC_EDIT4, numA);
	DDX_Text(pDX, IDC_EDIT_Length, m_len);
	DDX_Text(pDX, IDC_EDIT_Max, m_maxA);
	DDX_Text(pDX, IDC_EDIT_Numbers, m_numA);
	DDX_Control(pDX, IDC_EDIT_Sequence, m_editrd);
	DDX_Text(pDX, IDC_EDIT_Maxtwo, m_max);
	DDX_Text(pDX, IDC_EDIT_Number, m_numB);
}

BEGIN_MESSAGE_MAP(CrandDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_EN_CHANGE(IDC_EDIT2, &CrandDlg::OnEnChangeEdit2)
	//ON_EN_CHANGE(IDC_EDIT3, &CrandDlg::OnEnChangeEdit3)
	//ON_EN_CHANGE(IDC_EDIT4, &CrandDlg::OnEnChangeEdit4)
	//ON_BN_CLICKED(IDC_BUTTON2, &CrandDlg::OnBnClickedButton2)
//	ON_BN_CLICKED(IDC_BUTTON3, &CrandDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON_GENERATE, &CrandDlg::OnBnClickedButtonGenerate)
//ON_EN_CHANGE(IDC_EDIT1, &CrandDlg::OnEnChangeEdit1)
ON_EN_CHANGE(IDC_EDIT_Length, &CrandDlg::OnEnChangeEditLength)
ON_EN_CHANGE(IDC_EDIT_Max, &CrandDlg::OnEnChangeEditMax)
ON_EN_CHANGE(IDC_EDIT_Sequence, &CrandDlg::OnEnChangeEditSequence)
ON_BN_CLICKED(IDC_BUTTON_Mean, &CrandDlg::OnBnClickedButtonMean)
ON_EN_CHANGE(IDC_EDIT_Numbers, &CrandDlg::OnEnChangeEditNumbers)
ON_BN_CLICKED(IDC_BUTTON_Coordinate, &CrandDlg::OnBnClickedButtonCoordinate)
END_MESSAGE_MAP()


// CrandDlg 消息处理程序

BOOL CrandDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CrandDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CrandDlg::OnPaint()
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

int maxf, numberf, lenf,maxB,cnum;
//void CrandDlg::OnBnClickedButton3()
//{
//	UpdateData(TRUE);
//	lenf = len;
//	maxf = maxA;
//	scatter Dlg;
//	Dlg.DoModal();
//	// TODO:  在此添加控件通知处理程序代码
//}
//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CrandDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CrandDlg::OnBnClickedButtonGenerate()
{
	UpdateData(TRUE);
	lenf = m_len;
	maxf = m_maxA;
	CString tmpA, tmpB;
	int *rf = new int[m_len];
	for (int j = 0; j < m_len; j++)
	{
		rf[j] =int(CPublic::NormalRandom(double(maxf)/2,1, maxf)+0.5);
	}
	tmpB = tmpA = "";
	for (int i = 0; i < m_len; i++)
	{

		tmpB.Format(" %d", rf[i]);
		tmpA += tmpB;
	}
	delete []rf;
	m_editrd.SetWindowText(tmpA);// TODO:  在此添加控件通知处理程序代码
}





void CrandDlg::OnEnChangeEditLength()
{
	UpdateData(TRUE);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CrandDlg::OnEnChangeEditMax()
{
	UpdateData(TRUE);
}


void CrandDlg::OnEnChangeEditSequence()
{
}


void CrandDlg::OnBnClickedButtonMean()
{
	UpdateData(TRUE);
	lenf = m_len;
	numberf = m_numA;
	maxf = m_maxA;
	CPublic::getnorm(numberf, maxf, lenf);
	CMyNewview Dlg;
	Dlg.DoModal();
	// TODO:  在此添加控件通知处理程序代码
}


void CrandDlg::OnEnChangeEditNumbers()
{
	UpdateData(TRUE);
}

void CrandDlg::OnBnClickedButtonCoordinate()
{
	UpdateData(TRUE);
	maxB = m_max;
	cnum = m_numB;
	for (int i = 0; i < cnum; i++)
	{
		CPublic::m_randA[i].x = int(CPublic::NormalRandom(double(maxB)/2, 1, maxB) + 0.5);
		CPublic::m_randA[i].y = int(CPublic::NormalRandom(double(maxB)/2, 1, maxB) + 0.5);
	}
	CCoordinate Dlg;
	Dlg.DoModal();// TODO:  在此添加控件通知处理程序代码
}
