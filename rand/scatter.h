#pragma once


// scatter �Ի���

class scatter : public CDialogEx
{
	DECLARE_DYNAMIC(scatter)

public:
	scatter(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~scatter();

// �Ի�������
	//enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
