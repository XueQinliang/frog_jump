#include "frogsolve.h"
class frogBFSsolve:public frogsolve{
public:
    frogBFSsolve(int size,int *state){
    	this->_size=size;
    	int *pstate=new int[size]();//¿ª±Ù¿Õ¼ä 
    	_state=pstate;
        for(int i=0;i<size;i++){
        	_state[i]=state[i];
		} 
    }
    ~frogBFSsolve(){}
    void solve();
};
