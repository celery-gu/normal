#pragma once
#define EX_PORT __declspec(dllexport)
using namespace std;

class EX_PORT mmx
{
public: 
		long gcd(long a1, long b1);
		int niyuan(int m, int a);
		int quick(int a, int b, int c);
		int jiami(int x);
		int jiemi(int y);
};

