#include "frogsolve.h"
class frogDFSsolve:public frogsolve{
public:
    frogDFSsolve(int size,int *state){
    	this->_size=size;
    	int *pstate=new int[size]();//开辟空间 
    	_state=pstate;
        for(int i=0;i<size;i++){
        	_state[i]=state[i];//深复制 
		} 
    }
    ~frogDFSsolve(){}
    void solve();
};
