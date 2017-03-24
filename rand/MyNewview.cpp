// MyNewview.cpp : 实现文件
//

#include "stdafx.h"
#include "rand.h"
#include "MyNewview.h"
#include "afxdialogex.h"
#include "randDlg.h"
#include "resource.h"
#include "Cpublic.h"
// CMyNewview 对话框

IMPLEMENT_DYNAMIC(CMyNewview, CDialogEx)

CMyNewview::CMyNewview(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyNewview::IDD, pParent)
	, m_w(0)
	, m_h(0)
{

}

CMyNewview::~CMyNewview()
{
}

void CMyNewview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyNewview, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()
extern int numberf, lenf, maxf;
void CMyNewview::OnPaint()
{
	CPaintDC dc(this);
	RECT rect;
	GetClientRect(&rect);
	int w = rect.right;
	int h = rect.bottom;
	CDC *pDc = GetDC();
	pDc->MoveTo(30, h - 30);
	pDc->LineTo(w - 30, h - 30);
	pDc->MoveTo(30, h - 30);
	pDc->LineTo(30, 30);
	pDc->MoveTo(w - 35, h - 25);
	pDc->LineTo(w - 30, h - 30);
	pDc->LineTo(w - 35, h - 35);
	pDc->MoveTo(25, 35);
	pDc->LineTo(30, 30);
	pDc->LineTo(35, 35);
	int xpro =ceil(1.0*numberf/ 5);
	int ypro = ceil(1.0*maxf/ 5);
	int xlength = xpro * 5;
	int ylength = ypro * 5;
		for (int i = 0; i <=min(5,numberf); i++)
	{
		{
			double x = 30 + i*(w - 60)/5;
			pDc->MoveTo(x, h - 30);
			pDc->LineTo(x, h - 32);
			CString str = "";
			str.Format("%d", i*xpro);
			pDc->TextOut(x - 9, h - 28, str);
		}

	}
	for (int i = 1; i <=min(maxf,5); i++)
	{
		double y = h - 30 - i*(h - 60) / 5;
		pDc->MoveTo(30, y);
		pDc->LineTo(32, y);
		CString str = "";
		str.Format("%d",ypro*i);
		pDc->TextOut(5, y - 6, str);
	}
	CBrush brush, *oldbrush;
	brush.CreateSolidBrush(RGB(0, 0, 0));
	oldbrush = pDc->SelectObject(&brush);
	for (int i = 0; i < numberf; i++)
	{
		double x = 30 + (i + 1) * (w - 60) /xlength;
		double y = h - 30 - CPublic::m_MeanA[i]* double((h - 60))/ylength;
		pDc->Ellipse(x - 2, y - 2, x + 2, y + 2);
	}
	//	int *rf = new int[lenf];
	//	for (int i = 0; i < lenf; i++)
	//	{		rf[i] = int(Cpublic::NormalRandom(maxf / 2, 1, maxf) + 0.5);
	//	double x = 30 + (i + 1) * (w - 60) /  ((ceil(1.0*lenf / 5))*5);
	//	double y = h - 30 - rf[i] * double((h - 60)) / ylength;
	//	pDc->Ellipse(x - 2, y - 2, x + 2, y + 2);
	//}
	pDc->SelectObject(oldbrush);
		ReleaseDC(pDc);
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
}
void CMyNewview::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	m_w = cx; m_h = cy;

	// TODO:  在此处添加消息处理程序代码
}