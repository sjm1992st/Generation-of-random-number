#pragma once


// CMyNewview 对话框

class CMyNewview : public CDialogEx
{
	DECLARE_DYNAMIC(CMyNewview)

public:
	CMyNewview(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyNewview();

// 对话框数据
	enum { IDD = IDD_DIALOG_mean };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	HICON m_hIcon;
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int m_w;
	int m_h;
};
