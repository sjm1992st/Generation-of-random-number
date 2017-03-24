// scatter.cpp : 实现文件
//

#include "stdafx.h"
#include "rand.h"
#include "scatter.h"
#include "afxdialogex.h"
#include "randDlg.h"
#include "resource.h"
// scatter 对话框

IMPLEMENT_DYNAMIC(scatter, CDialogEx)

scatter::scatter(CWnd* pParent /*=NULL*/)
	: CDialogEx(scatter::IDD, pParent)
{

}

scatter::~scatter()
{
}

void scatter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(scatter, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// scatter 消息处理程序

extern int lenf,maxf;
extern double Normal();
void scatter::OnPaint()
{
	CPaintDC dc(this); 
	RECT rect;
	GetClientRect(&rect);
	int w = rect.right;
	int h = rect.bottom;
	CDC *pDc = GetDC();
	pDc->MoveTo(10, h - 10);
	pDc->LineTo(w - 10, h - 10);
	pDc->MoveTo(10, h - 10);
	pDc->LineTo(10, 10);
	double rfC[500] = { 0 };
	for (int i = 0; i < 500; i++)
	{
		rfC[i] =Normal();
	}
   for (int i = 0; i < lenf; i++)
	{
		pDc->SetPixel(10+(i + 1) * 525 / lenf, 352 - rfC[i] * 342/maxf , RGB(0, 0, 0));
	}
	// device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
   ReleaseDC(pDc);
}
