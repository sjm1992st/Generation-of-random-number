// Ccoordinate.cpp : 实现文件
//

#include "stdafx.h"
#include "rand.h"
#include "Ccoordinate.h"
#include "afxdialogex.h"
#include "randDlg.h"
#include "resource.h"
#include "MyNewview.h"
#include <atlimage.h>

// Ccoordinate 对话框

IMPLEMENT_DYNAMIC(CCoordinate, CDialogEx)

CCoordinate::CCoordinate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCoordinate::IDD, pParent)
{

}

CCoordinate::~CCoordinate()
{
}

void CCoordinate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCoordinate, CDialogEx)
	ON_WM_PAINT()
	ON_STN_CLICKED(IDC_STATIC_PICTURE, &CCoordinate::OnStnClickedStaticPicture)
	ON_BN_CLICKED(IDC_BUTTON_SAVEPICTURE, &CCoordinate::OnBnClickedButtonSavepicture)
END_MESSAGE_MAP()


// Ccoordinate 消息处理程序

extern int cnum,maxB;
void CCoordinate::OnPaint()
{
	CPaintDC dc(this); 
	RECT rect;
	CDC *pDc = GetDlgItem(IDC_STATIC_PICTURE)->GetDC();
	GetDlgItem(IDC_STATIC_PICTURE)->GetClientRect(&rect);
	int w = rect.right;
	int h = rect.bottom;
	pDc->MoveTo(30, h-30);
	pDc->LineTo(w-30, h-30);
	pDc->MoveTo(30, h-30);
	pDc->LineTo(30, 30);
	pDc->MoveTo(w - 35, h - 25);
	pDc->LineTo(w - 30, h - 30);
	pDc->LineTo(w - 35, h - 35);
	pDc->MoveTo(25, 35);
	pDc->LineTo(30, 30);
	pDc->LineTo(35, 35);
	int pro = ceil(1.0*maxB / 5);
	int length = pro * 5;
	for (int i = 0; i <= min(maxB, 5); i++)
	{
		double x = 30 + i*(w-60)/5;
		pDc->MoveTo(x, h - 30);
		pDc->LineTo(x, h - 32);
		CString str="";
		str.Format("%d", pro*i);
		pDc->TextOut(x-9,h-28,str);
	}
	for (int i = 1; i <= min(maxB, 5); i++)
	{
		double y = h-30-i*(h - 60) / 5;
		pDc->MoveTo(30, y);
		pDc->LineTo(32, y);
		CString str = "";
		str.Format("%d", pro*i);
		pDc->TextOut(5,y-6,str);
	}
	CBrush brush, *oldbrush;
	brush.CreateSolidBrush(RGB(255, 0, 0));
	oldbrush = pDc->SelectObject(&brush);
	for (int i = 0; i < cnum; i++)
	{
		double x=30+CPublic::m_randA[i].x*(w-60)/length; 
		double y=h-30-CPublic::m_randA[i].y*(h-60)/ length;
		pDc->Ellipse(x-2,y-2,x+2,y+2);
	}
	pDc->SelectObject(oldbrush);
	ReleaseDC(pDc);
	// 不为绘图消息调用 CDialogEx::OnPaint()
}

void CCoordinate::OnStnClickedStaticPicture()
{
}

void CCoordinate::OnBnClickedButtonSavepicture()
{
	char Filter[] = ("图像文件(*.bmp)|*.bmp|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(FALSE, ("bmp"), NULL, 0, Filter, this);
	CString strPath;
	if (IDOK == fileDlg.DoModal())
	{
		strPath = fileDlg.GetPathName();
		RECT rect;
		CDC *pDc = GetDlgItem(IDC_STATIC_PICTURE)->GetDC();
		HDC hdc = pDc->GetSafeHdc();
		GetDlgItem(IDC_STATIC_PICTURE)->GetClientRect(&rect);
		HBITMAP hmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
		HDC hdcmem = CreateCompatibleDC(hdc);
		//BitBlt(hdcmem, 0, 0, rect.right, rect.bottom,hdc, 0, 0, SRCCOPY);
		HBITMAP oldmap = HBITMAP(SelectObject(hdcmem, hmap));
		BitBlt(hdcmem, 0, 0, rect.right, rect.bottom, hdc, 0, 0, SRCCOPY);
		CImage imageA;
		imageA.Attach(hmap);
		imageA.Save(strPath);
		DeleteDC(hdc);
		DeleteDC(hdcmem);
		DeleteObject(hmap);
	}
}
