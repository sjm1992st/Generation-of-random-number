
// randDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CrandDlg �Ի���
class CrandDlg : public CDialogEx
{
// ����
public:
	CrandDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RAND_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
