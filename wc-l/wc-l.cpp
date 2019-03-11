#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>


using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq;
	long long kol=0;
	string str;
	
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt"; // << argv[1] << "\n";
	
	//ifstream f("a.txt");
	FILE* f;

	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек
	f = fopen("a.txt", "rb");
	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	char * s = new char[200000000];
	while(!feof(f)){
		fgets(s, 200000000, f);
		kol++;
	}
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла
	fclose(f);
  
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