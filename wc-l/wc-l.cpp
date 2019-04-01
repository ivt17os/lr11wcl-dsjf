#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>
using namespace std;
#define N 4096
int main(int argc, char** argv ) {
    long long t1, t2, freq;
	long long kol=0;
	//string str;
	DWORD nRead;
	BOOL bResult;
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	cout << "Opening file a.txt"; // << argv[1] << "\n";
	//ifstream f("a.txt");
	HANDLE f = CreateFile(L"a.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек
	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	char str [N];
	do {
		bResult=ReadFile(f, str, N, &nRead, NULL);
		for (int i=0; i<nRead; i++)
			if (str[i]=='\n')
				kol++;
	}
	while (!(bResult&&nRead==0));
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла
	CloseHandle(f);
	printf("\nTime spent:%.3f", (t2-t1)/(1.*freq));
	printf("\n%lld", kol);
	/*while (!f.eof()) {
		getline(f, str);
		kol++;
		}
	cout << "\nTime spent:"<<setprecision(3) << (t2-t1)/(1.*freq);
	cout << "\n" << kol << " strok v tekste";*/
	return 0;
}