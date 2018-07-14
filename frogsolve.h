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
    ~frogsolve(){delete[] this->_state;}//����ɾ����̬���� 
    virtual void solve()=0;//���麯�� 
protected:
    int _size;
    int *_state;
};

#endif // FROGSOLVE_H
