#include <iostream>
#include <stdio.h>
#include <time.h>
#include "frogBFSsolve.h"
#include "frogDFSsolve.h"
using namespace std;
int main(int argc, char *argv[])
{   int num;
    cout<<"请输入青蛙总数：";
    cin>>num;
    int state[num+1];//总数加1表示青蛙数和石头数总和 
    for(int i=0;i<num+1;i++){
    	state[i]=i-num/2;
	}
    frogDFSsolve solver1(num+1,state);//深度优先搜索 
    frogDFSsolve solver2(num+1,state);//广度优先搜索 
    time_t start,stop;//计时 
    start = time(NULL);
    solver1.solve();
    solver2.solve();
	stop = time(NULL);
	printf("Use Time:%ld\n",(stop-start));
    return 0;
}
