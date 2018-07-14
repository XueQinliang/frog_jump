#include "frogstate.h"
#include <iostream>
using namespace std;
frogstate::frogstate(int totalnum,int *state){
    this->totalnum=totalnum;
    this->introuble=false;
    this->stepnum=0;
    jumpnum=new int[500]();//开辟新的空间 
    _state=new int[totalnum](); 
    for(int i=0;i<totalnum;i++){
    	*(_state+i)=*(state+i);
        if(*(_state+i)==0)
            num0=i;//得到空石头的位置 
    }
}
frogstate::frogstate(const frogstate& fr){
    this->totalnum=fr.totalnum;
    this->stepnum=fr.stepnum;
    this->introuble=fr.introuble;
    jumpnum=new int[500]();
    _state=new int[totalnum]();
    for(int i=0;i<totalnum;i++){//深复制 
        _state[i]=fr._state[i];
    }
    for(int i=0;i<stepnum;i++){
        jumpnum[i]=fr.jumpnum[i];
    }
    this->num0=fr.num0;
}
void frogstate::move(int num){
	jumpnum[stepnum]=num;//记录移动的青蛙的位置 
	stepnum ++;//步数加 1 
	if(num>=totalnum||num<0) {//如果青蛙在规定范围外 
		introuble=true;
		return;
	}
    if(_state[num]<0){//如果青蛙值为负 
        if(num+1<totalnum&&_state[num+1]==0){//如果青蛙在石头左边一格 
            _state[num+1]=_state[num];
            _state[num]=0;
            num0=num;
        }
		else if(num+2<totalnum&&_state[num+2]==0){//如果青蛙在石头左边两格 
            _state[num+2]=_state[num];
            _state[num]=0;
            num0=num;
        }else {
        	introuble=true;
        	return;
		}
    }
    else if(_state[num]>0){//同理如上  
        if(num-1>=0&&_state[num-1]==0){
            _state[num-1]=_state[num];
            _state[num]=0;
            num0=num;
        }
		else if(num-2>=0&&_state[num-2]==0){
            _state[num-2]=_state[num];
            _state[num]=0;
            num0=num;
        }else {
        	introuble=true;
        	return;
		}
    }
}
void frogstate::show_way(){
    for(int i=0;i<stepnum;i++){
    	this->move(jumpnum[i]);
        cout<<"第"<<i+1<<"步、";
        this->show_state();
        if(iscomplete()){
        	cout<<"---------------------以上为一种方法---------------------\n\n";
        	break;
		} 
    }
}
void frogstate::show_state(){
	for(int i=0;i<totalnum;i++){//将数值转换成字母和数字的编号输出 
		if(_state[i]>0)
		cout<<"B"<<_state[i]<<ends;
		if(_state[i]<0)
		cout<<"A"<<-_state[i]<<ends;
		if(_state[i]==0)
		cout<<"C"<<ends;
	}cout<<endl;
}
