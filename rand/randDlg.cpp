
// randDlg.cpp : ʵ���ļ�
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


// CrandDlg �Ի���



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


// CrandDlg ��Ϣ�������

BOOL CrandDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CrandDlg::OnPaint()
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

int maxf, numberf, lenf,maxB,cnum;
//void CrandDlg::OnBnClickedButton3()
//{
//	UpdateData(TRUE);
//	lenf = len;
//	maxf = maxA;
//	scatter Dlg;
//	Dlg.DoModal();
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}
//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	m_editrd.SetWindowText(tmpA);// TODO:  �ڴ���ӿؼ�֪ͨ����������
}





void CrandDlg::OnEnChangeEditLength()
{
	UpdateData(TRUE);
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	Dlg.DoModal();// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
