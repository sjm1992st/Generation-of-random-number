#pragma once


// Ccoordinate �Ի���

class CCoordinate : public CDialogEx
{
	DECLARE_DYNAMIC(CCoordinate)

public:
	CCoordinate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCoordinate();

// �Ի�������
	enum { IDD = IDD_DIALOG_Coordinate };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnStnClickedStaticPicture();
	afx_msg void OnBnClickedButtonSavepicture();
};
