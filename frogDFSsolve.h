#include "frogsolve.h"
class frogDFSsolve:public frogsolve{
public:
    frogDFSsolve(int size,int *state){
    	this->_size=size;
    	int *pstate=new int[size]();//���ٿռ� 
    	_state=pstate;
        for(int i=0;i<size;i++){
        	_state[i]=state[i];//��� 
		} 
    }
    ~frogDFSsolve(){}
    void solve();
};
