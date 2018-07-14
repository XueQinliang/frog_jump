#include <iostream>
#include <stdio.h>
#include <time.h>
#include "frogBFSsolve.h"
#include "frogDFSsolve.h"
using namespace std;
int main(int argc, char *argv[])
{   int num;
    cout<<"����������������";
    cin>>num;
    int state[num+1];//������1��ʾ��������ʯͷ���ܺ� 
    for(int i=0;i<num+1;i++){
    	state[i]=i-num/2;
	}
    frogDFSsolve solver1(num+1,state);//����������� 
    frogDFSsolve solver2(num+1,state);//����������� 
    time_t start,stop;//��ʱ 
    start = time(NULL);
    solver1.solve();
    solver2.solve();
	stop = time(NULL);
	printf("Use Time:%ld\n",(stop-start));
    return 0;
}
