
// randDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CrandDlg 对话框
class CrandDlg : public CDialogEx
{
// 构造
public:
	CrandDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_RAND_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_rd;
//	afx_msg void OnEnChangeEdit2();
////	int r;
////	int max;
//	afx_msg void OnEnChangeEdit3();
////	int maxA;
////	int numberA;
//	afx_msg void OnEnChangeEdit4();
//	afx_msg void OnBnClickedButton2();
//	int len;
//	int numA;
	//afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonGenerate();
	//afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEditLength();
	afx_msg void OnEnChangeEditMax();
	afx_msg void OnEnChangeEditSequence();
	afx_msg void OnBnClickedButtonMean();
	afx_msg void OnEnChangeEditNumbers();
	int m_len;
	int m_maxA;
	int m_numA;
	CEdit m_editrd;
	afx_msg void OnBnClickedButtonCoordinate();
	int m_max;
	int m_numB;
};
