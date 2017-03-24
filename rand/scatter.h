#pragma once


// scatter 对话框

class scatter : public CDialogEx
{
	DECLARE_DYNAMIC(scatter)

public:
	scatter(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~scatter();

// 对话框数据
	//enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
