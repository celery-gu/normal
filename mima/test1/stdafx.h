// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <UIlib.h>
#include <stdlib.h>
#include <cstdlib>
using namespace DuiLib;
#include "data1.h"
#include "des.h"
#include "test_123.h"
#include "resource.h"
#include "ControlEX.h"
#include "SHA.h"
#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif
#pragma comment(lib,"data1.lib")
#pragma comment(lib,"des.lib")
#pragma comment(lib,"test_123.lib")
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
