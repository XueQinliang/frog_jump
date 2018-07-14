#ifndef FROGSOLVE_H
#define FROGSOLVE_H
#include <stack>
#include <queue>
#include "frogstate.h"
#include <iostream>
using namespace std;
class frogsolve{
public:
	frogsolve(){}
    frogsolve(int size,int *state):_size(size){
    	int *pstate=new int[size]();
    	_state=pstate;
        for(int i=0;i<size;i++){
        	_state[i]=state[i];
		} 
    }
    ~frogsolve(){delete[] this->_state;}//析构删除动态数组 
    virtual void solve()=0;//纯虚函数 
protected:
    int _size;
    int *_state;
};

#endif // FROGSOLVE_H
