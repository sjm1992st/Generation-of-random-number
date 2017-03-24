#pragma once


// Ccoordinate 对话框

class CCoordinate : public CDialogEx
{
	DECLARE_DYNAMIC(CCoordinate)

public:
	CCoordinate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCoordinate();

// 对话框数据
	enum { IDD = IDD_DIALOG_Coordinate };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnStnClickedStaticPicture();
	afx_msg void OnBnClickedButtonSavepicture();
};
