
extern "C" __declspec(dllexport) unsigned long K(int t);
extern "C" __declspec(dllexport) unsigned long f(int t);
extern "C" __declspec(dllexport) void binary(int n, char *s);
extern "C" __declspec(dllexport) void turn_ascii(char *str, char *s, int len);
extern "C" __declspec(dllexport) int complement1(char *com, int len);
extern "C" __declspec(dllexport) void complement2(char *str, char *pl, int len, int len1);
extern "C" __declspec(dllexport) void Hex(char *h, char *e, int len);
extern "C" __declspec(dllexport) void inint_M(char **M, int n, char *ch);
extern "C" __declspec(dllexport) void inint_W(char **M, int n);
extern "C" __declspec(dllexport) unsigned long turn_num(int i);
extern "C" __declspec(dllexport) void Hash();
extern "C" __declspec(dllexport) void output_hash(char str[], char *result);
extern "C" __declspec(dllexport) void Hex(char *h, char *e, int len);
extern "C" __declspec(dllexport) int turn_RSA(char str[]);

