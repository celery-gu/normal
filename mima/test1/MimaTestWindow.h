#include <exdisp.h>
#include <comdef.h>
#include "stdafx.h"

std::string StringFromLPCTSTR(LPCTSTR str) {
#ifdef _UNICODE
	int size_str = WideCharToMultiByte(CP_UTF8, 0, str, -1, 0, 0, NULL, NULL);

	char* point_new_array = new char[size_str];

	WideCharToMultiByte(CP_UTF8, 0, str, -1, point_new_array, size_str, NULL, NULL);

	std::string return_string(point_new_array);
	delete[] point_new_array;
	point_new_array = NULL;
	return return_string;
#else
	return std::string(str);
#endif
}

class CMimaTestWindow : public CWindowWnd, public INotifyUI,public mmx
{
public:
	CMimaTestWindow() { };
	LPCTSTR GetWindowClassName() const { return _T("UIMainFrame"); };
	UINT GetClassStyle() const { return CS_DBLCLKS; };
	void OnFinalMessage(HWND /*hWnd*/) { delete this; };

	void Init() {
		m_pCloseBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("closebtn")));
		m_pMaxBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("maxbtn")));
		m_pRestoreBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("restorebtn")));
		m_pMinBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("minbtn")));
	}

	void OnPrepare() {
	}

	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("windowinit")) OnPrepare();
		else if (msg.sType == _T("click")) {

			if (msg.pSender->GetName() == _T("gcd_ensure")) {
				MimaGcd(msg.pSender);
			}
			if (msg.pSender->GetName() == _T("mod_ensure")) {
				MimaMod(msg.pSender);
			}
			if (msg.pSender->GetName() == _T("Mod_ensure")) {
				MimaMod_2(msg.pSender);
			}
			if (msg.pSender->GetName() == _T("MOD_jiami")|| msg.pSender->GetName() == _T("MOD_jiemi")) {
				MimaMod_3(msg.pSender);
			}
			if (msg.pSender->GetName() == _T("DES_jiami") || msg.pSender->GetName() == _T("DES_jiemi")) {
				MimaDES(msg.pSender);
			}
			if (msg.pSender->GetName() == _T("RSA_jiami") || msg.pSender->GetName() == _T("RSA_jiemi")) {
				MimaRSA(msg.pSender);
			}
			if (msg.pSender->GetName() == _T("SHA_ensure") ) {
				MimaSHA(msg.pSender);
			}
			if (msg.pSender->GetName() == _T("qm_ensure")) {
				MimaQM(msg.pSender);
			}
			if (msg.pSender == m_pCloseBtn) {
				PostQuitMessage(0);
				return;
			}
			else if (msg.pSender == m_pMinBtn) {
				SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0); return;
			}
			else if (msg.pSender == m_pMaxBtn) {
				SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0); return;
			}
			else if (msg.pSender == m_pRestoreBtn) {
				SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0); return;
			}
		}
		else if (msg.sType == _T("selectchanged"))
		{
			CDuiString name = msg.pSender->GetName();
			CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_pm.FindControl(_T("switch")));
			if (name == _T("gcd"))
				pControl->SelectItem(0);
			else if (name == _T("mod_1"))
				pControl->SelectItem(1);
			else if (name == _T("mod_2"))
				pControl->SelectItem(2);
			else if (name == _T("mod_3"))
				pControl->SelectItem(3);
			else if (name == _T("DES"))
				pControl->SelectItem(4);
			else if (name == _T("RSA"))
				pControl->SelectItem(5);
			else if (name == _T("SHA"))
				pControl->SelectItem(6);
			else if (name == _T("RSA_2"))
				pControl->SelectItem(7);
			else if (name == _T("help"))
				pControl->SelectItem(8);
			else if (name == _T("worker"))
				pControl->SelectItem(9);
		}
	}

	void MimaGcd(CControlUI* pSender)
	{
		mmx one;
		if (pSender->GetName() == _T("gcd_ensure"))
		{
			CControlUI* pbtnTip = static_cast <CControlUI*> (m_pm.FindControl(_T("gcd_ensure")));
			CEditUI* peditCal_1 = static_cast <CEditUI*> (m_pm.FindControl(_T("gcd_input_1")));
			CEditUI* peditCal_2 = static_cast <CEditUI*> (m_pm.FindControl(_T("gcd_input_2")));
			CEditUI* peditCal_3 = static_cast <CEditUI*> (m_pm.FindControl(_T("gcd_output")));

			if (pbtnTip&&peditCal_1 && peditCal_2)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();
				CDuiString strText_3 = peditCal_3->GetText();
				pbtnTip->SetText(_T("确认"));
				if (!(strText_1.IsEmpty() || strText_2.IsEmpty()))
				{
					long a = _ttol(strText_1);
					long b = _ttol(strText_2);
					long c = one.gcd(a,b);
					strText_3.Format(_T("%d"), c);
					peditCal_3->SetText(strText_3);
				}
			}
		}
	}
	
	void MimaMod(CControlUI* pSender)
	{
		mmx two;
		if (pSender->GetName() == _T("mod_ensure"))
		{
			CControlUI* pbtnTip = static_cast <CControlUI*> (m_pm.FindControl(_T("mod_ensure")));
			CEditUI* peditCal_1 = static_cast <CEditUI*> (m_pm.FindControl(_T("mod_input_1")));
			CEditUI* peditCal_2 = static_cast <CEditUI*> (m_pm.FindControl(_T("mod_input_2")));
			CEditUI* peditCal_3 = static_cast <CEditUI*> (m_pm.FindControl(_T("mod_output")));

			if (pbtnTip&&peditCal_1 && peditCal_2)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();
				CDuiString strText_3 = peditCal_3->GetText();
				pbtnTip->SetText(_T("确认"));
				if (!(strText_1.IsEmpty() || strText_2.IsEmpty()))
				{
					int a = _ttoi(strText_1);
					int b = _ttoi(strText_2);
					int c = two.niyuan(b, a);
					strText_3.Format(_T("%d"), c);
					if (c == -1)
						strText_3 = (_T("逆元，不存在的"));
					peditCal_3->SetText(strText_3);
				}
			}
		}
	}

	void MimaMod_2(CControlUI* pSender)
	{
		mmx three;
		if (pSender->GetName() == _T("Mod_ensure"))
		{
			CControlUI* pbtnTip = static_cast <CControlUI*> (m_pm.FindControl(_T("Mod_ensure")));
			CEditUI* peditCal_1 = static_cast <CEditUI*> (m_pm.FindControl(_T("Mod_input_1")));
			CEditUI* peditCal_2 = static_cast <CEditUI*> (m_pm.FindControl(_T("Mod_input_2")));
			CEditUI* peditCal_3 = static_cast <CEditUI*> (m_pm.FindControl(_T("Mod_input_3")));
			CEditUI* peditCal_4 = static_cast <CEditUI*> (m_pm.FindControl(_T("Mod_output")));

			if (pbtnTip&&peditCal_1 && peditCal_2&&peditCal_3)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();
				CDuiString strText_3 = peditCal_3->GetText();
				CDuiString strText_4 = peditCal_4->GetText();
				pbtnTip->SetText(_T("确认"));
				if (!(strText_1.IsEmpty() || strText_2.IsEmpty()|| strText_3.IsEmpty()))
				{
					int a = _ttoi(strText_1);
					int b = _ttoi(strText_2);
					int c = _ttoi(strText_3);
					int d = three.quick(a, b, c);
					strText_4.Format(_T("%d"), d);
					peditCal_4->SetText(strText_4);
				}
			}
		}
	}

	void MimaMod_3(CControlUI* pSender)
	{
		mmx four;
		if (pSender->GetName() == _T("MOD_jiami")|| pSender->GetName() == _T("MOD_jiemi"))
		{
			CControlUI* pbtnTip_1 = static_cast <CControlUI*> (m_pm.FindControl(_T("MOD_jiemi")));
			CControlUI* pbtnTip_2 = static_cast <CControlUI*> (m_pm.FindControl(_T("MOD_jiami")));
			CEditUI* peditCal_1 = static_cast <CEditUI*> (m_pm.FindControl(_T("MOD_input_1")));
			CEditUI* peditCal_2 = static_cast <CEditUI*> (m_pm.FindControl(_T("MOD_input_2")));

			if (pbtnTip_1&& peditCal_2)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();

				pbtnTip_1->SetText(_T("解密"));
				if ((!strText_2.IsEmpty())&&pSender->GetName() == _T("MOD_jiemi"))
				{
					int a = _ttoi(strText_2);
					int b = four.jiemi(a);

					strText_1.Format(_T("%d"), b);
					peditCal_1->SetText(strText_1);
				}
			}
			if (pbtnTip_2&& peditCal_1)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();

				pbtnTip_2->SetText(_T("加密"));
				if ((!strText_1.IsEmpty())&& pSender->GetName() == _T("MOD_jiami"))
				{
					int a = _ttoi(strText_1);
					int b = four.jiami(a);

					strText_2.Format(_T("%d"), b);
					peditCal_2->SetText(strText_2);
				}
			}
		}
	}

	void MimaDES(CControlUI* pSender)
	{
		//mmx four;
		if (pSender->GetName() == _T("DES_jiami") || pSender->GetName() == _T("DES_jiemi"))
		{
			CControlUI* pbtnTip_1 = static_cast <CControlUI*> (m_pm.FindControl(_T("DES_jiami")));
			CControlUI* pbtnTip_2 = static_cast <CControlUI*> (m_pm.FindControl(_T("DES_jiemi")));
			CEditUI* peditCal_1 = static_cast <CEditUI*> (m_pm.FindControl(_T("DES_input_1")));
			CEditUI* peditCal_2 = static_cast <CEditUI*> (m_pm.FindControl(_T("DES_input_2")));
			CEditUI* peditCal_3 = static_cast <CEditUI*> (m_pm.FindControl(_T("DES_output_1")));

			if (pbtnTip_2&& peditCal_2&&peditCal_1)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();
				CDuiString strText_3 = peditCal_3->GetText();

				pbtnTip_1->SetText(_T("加密"));
				if ((!strText_2.IsEmpty()) && (!strText_1.IsEmpty()) && pSender->GetName() == _T("DES_jiami"))
				{
					CDuiString inname = strText_1;
					std::string k = StringFromLPCTSTR(inname.GetData());
					const char *a = k.c_str();
					CDuiString key = strText_2;
					std::string k2 = StringFromLPCTSTR(key.GetData());
					const unsigned char *b = (const unsigned char*)(k2.c_str());

					des_key skey;
					des_setup(b, 8, 0, &skey);
					FILE *fd1 = std::fopen(a, "rb");
					FILE *fd2 = std::fopen("cipertext.txt","wb");
					int count = 0;
					unsigned char p_buf[8];
					unsigned char c_buf[8];
					while (true)
					{
						count = fread(p_buf, sizeof(unsigned char), 8, fd1);
						if (count<8)
							for (int i = count; i <= 7; i++)
								p_buf[i] = '\0';

						des_ecb_encrypt(p_buf, c_buf, &skey);
						fwrite(c_buf, sizeof(unsigned char), 8, fd2);
						if (count<8)
							break;
						count = 0;
					}
					fclose(fd1);
					fclose(fd2);

					peditCal_3->SetText(_T("cipertext.txt"));
				}
			}
			if (pbtnTip_1&& peditCal_2&&peditCal_3)
			{
				CDuiString strText_2 = peditCal_2->GetText();
				CDuiString strText_3 = peditCal_3->GetText();

				pbtnTip_2->SetText(_T("解密"));
				if ((!strText_2.IsEmpty()) && (!strText_3.IsEmpty()) && pSender->GetName() == _T("DES_jiemi"))
				{
					CDuiString outname = strText_3;
					std::string k = StringFromLPCTSTR(outname.GetData());
					const char *a = k.c_str();
					CDuiString key = strText_2;
					std::string k2 = StringFromLPCTSTR(key.GetData());
					const unsigned char *b = (const unsigned char*)(k2.c_str());

					des_key skey;
					des_setup(b, 8, 0, &skey);
					FILE *fd2 = std::fopen(a, "rb");
					FILE *fd3 = std::fopen("plaintext.txt", "wb");
					int count = 8;
					unsigned char p_buf[8];
					unsigned char c_buf[8];
					while (true)
					{
						count = fread(p_buf, sizeof(unsigned char), 8, fd2);
						if (count == 0)
							break;
						des_ecb_decrypt(p_buf, c_buf, &skey);
						fwrite(c_buf, sizeof(unsigned char), 8, fd3);
						count = 0;
					}
					fclose(fd2);
					fclose(fd3);

					peditCal_1->SetText(_T("plaintext.txt"));
				}
			}
		}
	}

	void MimaRSA(CControlUI* pSender)
	{
		mmx six;
		if (pSender->GetName() == _T("RSA_jiami") || pSender->GetName() == _T("RSA_jiemi"))
		{
			CControlUI* pbtnTip_1 = static_cast <CControlUI*> (m_pm.FindControl(_T("RSA_jiemi")));
			CControlUI* pbtnTip_2 = static_cast <CControlUI*> (m_pm.FindControl(_T("RSA_jiami")));
			CEditUI* peditCal_1 = static_cast <CEditUI*> (m_pm.FindControl(_T("RSA_input")));
			CEditUI* peditCal_2 = static_cast <CEditUI*> (m_pm.FindControl(_T("RSA_output")));
			CEditUI* peditCal_3 = static_cast <CEditUI*> (m_pm.FindControl(_T("RSA_key1")));
			CEditUI* peditCal_4 = static_cast <CEditUI*> (m_pm.FindControl(_T("RSA_key2")));

			if (pbtnTip_1&& peditCal_2)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();

				pbtnTip_1->SetText(_T("解密"));
				if ((!strText_2.IsEmpty()) && pSender->GetName() == _T("RSA_jiemi"))
				{
					CDuiString strText_1 = peditCal_1->GetText();
					CDuiString strText_2 = peditCal_2->GetText();
					CDuiString strText_3 = peditCal_3->GetText();
					CDuiString strText_4 = peditCal_4->GetText();

					int key[2];
					CDuiString key2 = strText_4;
					std::string k = StringFromLPCTSTR(key2.GetData());
					const char *a = k.c_str();
					char* tmp = const_cast<char*>(a);
					char* d = "(,)";
					char* p = strtok(tmp, d);
					int i = 0;
					while (p != NULL)
					{
						key[i] = atoi(p);
						p = strtok(NULL, d);
						i++;
					}
					
					int M, C;
					C = _ttoi(strText_2);
					M = quick(C, key[0], key[1]);
					strText_1.Format(_T("%d"), M);
					peditCal_1->SetText(strText_1);
					//peditCal_2->SetText(strText_2);
				}
			}
			if (pbtnTip_2&& peditCal_1)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();
				CDuiString strText_3 = peditCal_3->GetText();
				CDuiString strText_4 = peditCal_4->GetText();

				pbtnTip_2->SetText(_T("加密"));
				if ((!strText_1.IsEmpty()) && pSender->GetName() == _T("RSA_jiami"))
				{
					int p, q, e, n;
					int MIN = 20;
					int MAX=100;
					srand((unsigned)time(NULL));
					int iteration = 5;
					while (1)
					{
						int a = random(MIN, MAX);
						if (Miller(a, iteration))
						{
							p = a;
							break;
						}
					}
					while (1)
					{	
						int a = random(MIN, MAX);
						if (Miller(a, iteration) && a != p)
						{
							q = a;
							break;
						}
					}
					n = p*q;
					while (1)
					{
						long a = random(2, (p - 1)*(q - 1) - 1);
						if (gcd(a, (p - 1)*(q - 1)) == 1)
						{
							e = a;
							break;
						}
					}
					int d;
					d = six.niyuan((p - 1)*(q - 1), e);

					CDuiString E;
					E.Format(_T("%d"),e );
					CDuiString N;
					N.Format(_T("%d"), n);
					strText_3 = (L"(");
					strText_3.Append(E);
					strText_3.Append(_T(","));
					strText_3.Append(N);
					strText_3.Append(_T(")"));
					peditCal_3->SetText(strText_3);

					CDuiString D;
					D.Format(_T("%d"), d);
					strText_4 = (_T("("));
					strText_4.Append(D);
					strText_4.Append(_T(","));
					strText_4.Append(N);
					strText_4.Append(_T(")"));
					peditCal_4->SetText(strText_4);

					int M,C;
					M= _ttoi(strText_1);
					C = quick(M, e, n);
					strText_2.Format(_T("%d"), C);
					//peditCal_1->SetText(strText_1);
					peditCal_2->SetText(strText_2);
				}
			}
		}
	}

	void MimaSHA(CControlUI* pSender)
	{
		//mmx four;
		if (pSender->GetName() == _T("SHA_ensure") )
		{
			CControlUI* pbtnTip_1 = static_cast <CControlUI*> (m_pm.FindControl(_T("SHA_ensure")));
			CEditUI* peditCal_1 = static_cast <CEditUI*> (m_pm.FindControl(_T("SHA_input")));
			CEditUI* peditCal_2 = static_cast <CEditUI*> (m_pm.FindControl(_T("SHA_output")));

			if (pbtnTip_1)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();

				pbtnTip_1->SetText(_T("SHA-1"));
				if ((!strText_1.IsEmpty()) && pSender->GetName() == _T("SHA_ensure"))
				{
					CDuiString k1 = strText_1;
					std::string k2 = StringFromLPCTSTR(k1.GetData());
					const char *a = k2.c_str();
					char *b = const_cast<char*>(a);

					char result[40]="\0";
					output_hash(b, result);
					CDuiString tmp;
					for (int i = 0; i < 40; i++)
					{
						if ((result[i] >= '0'&&result[i] <= '9') || (result[i] >= 'A'&&result[i] <= 'Z'))
						{
							tmp.Format(_T("%c"), result[i]);
							strText_2.Append(tmp);
						}
					}
					peditCal_2->SetText(strText_2);
				}
			}
		}
	}

	void MimaQM(CControlUI* pSender)
	{
		mmx six;
		if (pSender->GetName() == _T("qm_ensure"))
		{
			CControlUI* pbtnTip_1 = static_cast <CControlUI*> (m_pm.FindControl(_T("qm_ensure")));
			CEditUI* peditCal_1 = static_cast <CEditUI*> (m_pm.FindControl(_T("qm_input_1")));
			CEditUI* peditCal_2 = static_cast <CEditUI*> (m_pm.FindControl(_T("qm_input_2")));
			CEditUI* peditCal_3 = static_cast <CEditUI*> (m_pm.FindControl(_T("qm_output")));

			if (pbtnTip_1)
			{
				CDuiString strText_1 = peditCal_1->GetText();
				CDuiString strText_2 = peditCal_2->GetText();
				CDuiString strText_3 = peditCal_3->GetText();

				pbtnTip_1->SetText(_T("确认"));
				if ((!strText_1.IsEmpty()) && pSender->GetName() == _T("qm_ensure"))
				{
					int p, q, e, n;
					int MIN = 20;
					int MAX = 100;
					srand((unsigned)time(NULL));
					int iteration = 5;
					while (1)
					{
						int a = random(MIN, MAX);
						if (Miller(a, iteration))
						{
							p = a;
							break;
						}
					}
					while (1)
					{
						int a = random(MIN, MAX);
						if (Miller(a, iteration) && a != p)
						{
							q = a;
							break;
						}
					}
					n = p*q;
					while (1)
					{
						long a = random(2, (p - 1)*(q - 1) - 1);
						if (gcd(a, (p - 1)*(q - 1)) == 1)
						{
							e = a;
							break;
						}
					}
					int d;
					d = six.niyuan((p - 1)*(q - 1), e);
					CDuiString D;
					D.Format(_T("%d"), d);
					CDuiString N;
					N.Format(_T("%d"), n);
					strText_2 = (L"(");
					strText_2.Append(D);
					strText_2.Append(_T(","));
					strText_2.Append(N);
					strText_2.Append(_T(")"));
					peditCal_2->SetText(strText_2);

					CDuiString k1 = strText_1;
					std::string k2 = StringFromLPCTSTR(k1.GetData());
					const char *a = k2.c_str();
					char *b = const_cast<char*>(a);

					int M, C;
					M = turn_RSA(b);
					C = quick(M, e, n);
					strText_3.Format(_T("%d"), C);

					char result[40];
					output_hash(b, result);
					CDuiString tmp;
					for (int i = 0; i < 40; i++)
					{
						if ((result[i] >= '0'&&result[i] <= '9') || (result[i] >= 'A'&&result[i] <= 'Z'))
						{
							tmp.Format(_T("%c"), result[i]);
							strText_3.Append(tmp);
						}
					}
					peditCal_3->SetText(strText_3);
				}
			}
		}
	}

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		LONG styleValue = ::GetWindowLong(*this, GWL_STYLE);
		styleValue &= ~WS_CAPTION;
		::SetWindowLong(*this, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

		m_pm.Init(m_hWnd);
		CDialogBuilder builder;
		CDialogBuilderCallbackEx cb;
		CControlUI* pRoot = builder.Create(_T("skin.xml"), (UINT)0, &cb, &m_pm);//外观xml引入
		ASSERT(pRoot && "Failed to parse XML");
		m_pm.AttachDialog(pRoot);
		m_pm.AddNotifier(this);//添加控件消息响应，消息会传达到duilib的消息循环，在Notify函数里做消息处理

		Init();
		return 0;
	}

	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		bHandled = FALSE;
		return 0;
	}

	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		::PostQuitMessage(0L);

		bHandled = FALSE;
		return 0;
	}

	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if (::IsIconic(*this)) bHandled = FALSE;
		return (wParam == 0) ? TRUE : FALSE;
	}

	LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		return 0;
	}

	LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		return 0;
	}

	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		POINT pt; pt.x = GET_X_LPARAM(lParam); pt.y = GET_Y_LPARAM(lParam);
		::ScreenToClient(*this, &pt);

		RECT rcClient;
		::GetClientRect(*this, &rcClient);

		// 		if( !::IsZoomed(*this) ) {
		// 			RECT rcSizeBox = m_pm.GetSizeBox();
		// 			if( pt.y < rcClient.top + rcSizeBox.top ) {
		// 				if( pt.x < rcClient.left + rcSizeBox.left ) return HTTOPLEFT;
		// 				if( pt.x > rcClient.right - rcSizeBox.right ) return HTTOPRIGHT;
		// 				return HTTOP;
		// 			}
		// 			else if( pt.y > rcClient.bottom - rcSizeBox.bottom ) {
		// 				if( pt.x < rcClient.left + rcSizeBox.left ) return HTBOTTOMLEFT;
		// 				if( pt.x > rcClient.right - rcSizeBox.right ) return HTBOTTOMRIGHT;
		// 				return HTBOTTOM;
		// 			}
		// 			if( pt.x < rcClient.left + rcSizeBox.left ) return HTLEFT;
		// 			if( pt.x > rcClient.right - rcSizeBox.right ) return HTRIGHT;
		// 		}

		RECT rcCaption = m_pm.GetCaptionRect();
		if (pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right \
			&& pt.y >= rcCaption.top && pt.y < rcCaption.bottom) {
			CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(pt));
			if (pControl && _tcscmp(pControl->GetClass(), DUI_CTR_BUTTON) != 0 &&
				_tcscmp(pControl->GetClass(), DUI_CTR_OPTION) != 0 &&
				_tcscmp(pControl->GetClass(), DUI_CTR_TEXT) != 0)
				return HTCAPTION;
		}

		return HTCLIENT;
	}

	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		SIZE szRoundCorner = m_pm.GetRoundCorner();
		if (!::IsIconic(*this) && (szRoundCorner.cx != 0 || szRoundCorner.cy != 0)) {
			CDuiRect rcWnd;
			::GetWindowRect(*this, &rcWnd);
			rcWnd.Offset(-rcWnd.left, -rcWnd.top);
			rcWnd.right++; rcWnd.bottom++;
			HRGN hRgn = ::CreateRoundRectRgn(rcWnd.left, rcWnd.top, rcWnd.right, rcWnd.bottom, szRoundCorner.cx, szRoundCorner.cy);
			::SetWindowRgn(*this, hRgn, TRUE);
			::DeleteObject(hRgn);
		}

		bHandled = FALSE;
		return 0;
	}

	LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		MONITORINFO oMonitor = {};
		oMonitor.cbSize = sizeof(oMonitor);
		::GetMonitorInfo(::MonitorFromWindow(*this, MONITOR_DEFAULTTOPRIMARY), &oMonitor);
		CDuiRect rcWork = oMonitor.rcWork;
		rcWork.Offset(-oMonitor.rcMonitor.left, -oMonitor.rcMonitor.top);

		LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
		lpMMI->ptMaxPosition.x = rcWork.left;
		lpMMI->ptMaxPosition.y = rcWork.top;
		lpMMI->ptMaxSize.x = rcWork.right;
		lpMMI->ptMaxSize.y = rcWork.bottom;

		bHandled = FALSE;
		return 0;
	}

	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// 有时会在收到WM_NCDESTROY后收到wParam为SC_CLOSE的WM_SYSCOMMAND
		if (wParam == SC_CLOSE) {
			::PostQuitMessage(0L);
			bHandled = TRUE;
			return 0;
		}
		BOOL bZoomed = ::IsZoomed(*this);
		LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);
		if (::IsZoomed(*this) != bZoomed) {
			if (!bZoomed) {
				CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(_T("maxbtn")));
				if (pControl) pControl->SetVisible(false);
				pControl = static_cast<CControlUI*>(m_pm.FindControl(_T("restorebtn")));
				if (pControl) pControl->SetVisible(true);
			}
			else {
				CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(_T("maxbtn")));
				if (pControl) pControl->SetVisible(true);
				pControl = static_cast<CControlUI*>(m_pm.FindControl(_T("restorebtn")));
				if (pControl) pControl->SetVisible(false);
			}
		}
		return lRes;
	}

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		BOOL bHandled = TRUE;
		switch (uMsg) {
		case WM_CREATE:        lRes = OnCreate(uMsg, wParam, lParam, bHandled); break;
		case WM_CLOSE:         lRes = OnClose(uMsg, wParam, lParam, bHandled); break;
		case WM_DESTROY:       lRes = OnDestroy(uMsg, wParam, lParam, bHandled); break;
		case WM_NCACTIVATE:    lRes = OnNcActivate(uMsg, wParam, lParam, bHandled); break;
		case WM_NCCALCSIZE:    lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled); break;
		case WM_NCPAINT:       lRes = OnNcPaint(uMsg, wParam, lParam, bHandled); break;
		case WM_NCHITTEST:     lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled); break;
		case WM_SIZE:          lRes = OnSize(uMsg, wParam, lParam, bHandled); break;
		case WM_GETMINMAXINFO: lRes = OnGetMinMaxInfo(uMsg, wParam, lParam, bHandled); break;
		case WM_SYSCOMMAND:    lRes = OnSysCommand(uMsg, wParam, lParam, bHandled); break;
		default:
			bHandled = FALSE;
		}
		if (bHandled) return lRes;
		if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;
		return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
	}

public:
	CPaintManagerUI m_pm;

private:
	CButtonUI* m_pCloseBtn;
	CButtonUI* m_pMaxBtn;
	CButtonUI* m_pRestoreBtn;
	CButtonUI* m_pMinBtn;
	CButtonUI* m_pbtnGcd;
	//...
};

