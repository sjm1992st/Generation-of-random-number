#pragma once


// CMyNewview �Ի���

class CMyNewview : public CDialogEx
{
	DECLARE_DYNAMIC(CMyNewview)

public:
	CMyNewview(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyNewview();

// �Ի�������
	enum { IDD = IDD_DIALOG_mean };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	HICON m_hIcon;
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int m_w;
	int m_h;
};
