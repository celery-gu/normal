#pragma once
extern "C" __declspec(dllexport) int gcd(long a, long b);
extern "C" __declspec(dllexport) int niyuan(int m, int a);
extern "C" __declspec(dllexport) int quick(int a, int b, int c);
extern "C" __declspec(dllexport) int niyuan(int m, int a);
extern "C" __declspec(dllexport) int jiami(int x);
extern "C" __declspec(dllexport) int jiemi(int x);
extern "C" __declspec(dllexport) int  random(int a, int b);
extern "C" __declspec(dllexport) long long mulmod(long long a, long long b, long long mod);
extern "C" __declspec(dllexport) long long modulo(long long base, long long exponent, long long mod);
extern "C" __declspec(dllexport) bool Miller(long long p, int iteration);