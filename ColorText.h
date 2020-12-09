#include "BIG.h"
#define IDC_RED         100
#define IDC_GREEN       101
#define IDC_BLUE        102
#define IDC_LOG         103
#define IDC_EQ          104
#define IDC_Notation    105
#define IDC_DOWN        106

class CColorStatic : public CStatic
{
protected:
    COLORREF m_clrText;
    COLORREF m_clrBack;
    CBrush m_brBkgnd;

public:
    CColorStatic ();
    void SetTextColor (COLORREF clrText);
    void SetBkColor (COLORREF clrBack);

protected:
    afx_msg HBRUSH CtlColor (CDC* pDC, UINT nCtlColor);
    DECLARE_MESSAGE_MAP ()
};

class CMyApp : public CWinApp
{
public:
    virtual BOOL InitInstance ();
};

class CMainWindow : public CFrameWnd
{
protected:
    CString notation;
    bool log;
    int m_cxChar;
    int m_cyChar;
    CFont m_font;

    CColorStatic m_wndText;
    CButton m_wndRadioButtonRed;
    CButton m_wndRadioButtonGreen;
    CButton m_wndRadioButtonBlue;
    CButton Notation;


    CButton LOG;
    CButton COMPUTE;
    CButton Down;

    CButton m_wndGroupBox1;
    CButton m_wndGroupBox2;
    CButton m_wndGroupBox3;
    CButton m_wndGroupBox4;

    CEdit NUM[2];
    CEdit Password;
    CEdit Answer;

public:
    CMainWindow ();

protected:
    afx_msg int OnCreate (LPCREATESTRUCT lpcs);
    afx_msg void OnRedButtonClicked ();
    afx_msg void OnGreenButtonClicked ();
    afx_msg void OnBlueButtonClicked ();
    afx_msg void Computing();                       //按=键进行计算
    afx_msg void setNotation();                     //选择加减乘除
    afx_msg void LOGIN();                           //按登录键登录进行操作
    afx_msg void DOWN();
    DECLARE_MESSAGE_MAP ()
};
