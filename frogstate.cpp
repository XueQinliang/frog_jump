#include "frogstate.h"
#include <iostream>
using namespace std;
frogstate::frogstate(int totalnum,int *state){
    this->totalnum=totalnum;
    this->introuble=false;
    this->stepnum=0;
    jumpnum=new int[500]();//�����µĿռ� 
    _state=new int[totalnum](); 
    for(int i=0;i<totalnum;i++){
    	*(_state+i)=*(state+i);
        if(*(_state+i)==0)
            num0=i;//�õ���ʯͷ��λ�� 
    }
}
frogstate::frogstate(const frogstate& fr){
    this->totalnum=fr.totalnum;
    this->stepnum=fr.stepnum;
    this->introuble=fr.introuble;
    jumpnum=new int[500]();
    _state=new int[totalnum]();
    for(int i=0;i<totalnum;i++){//��� 
        _state[i]=fr._state[i];
    }
    for(int i=0;i<stepnum;i++){
        jumpnum[i]=fr.jumpnum[i];
    }
    this->num0=fr.num0;
}
void frogstate::move(int num){
	jumpnum[stepnum]=num;//��¼�ƶ������ܵ�λ�� 
	stepnum ++;//������ 1 
	if(num>=totalnum||num<0) {//��������ڹ涨��Χ�� 
		introuble=true;
		return;
	}
    if(_state[num]<0){//�������ֵΪ�� 
        if(num+1<totalnum&&_state[num+1]==0){//���������ʯͷ���һ�� 
            _state[num+1]=_state[num];
            _state[num]=0;
            num0=num;
        }
		else if(num+2<totalnum&&_state[num+2]==0){//���������ʯͷ������� 
            _state[num+2]=_state[num];
            _state[num]=0;
            num0=num;
        }else {
        	introuble=true;
        	return;
		}
    }
    else if(_state[num]>0){//ͬ������  
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
        cout<<"��"<<i+1<<"����";
        this->show_state();
        if(iscomplete()){
        	cout<<"---------------------����Ϊһ�ַ���---------------------\n\n";
        	break;
		} 
    }
}
void frogstate::show_state(){
	for(int i=0;i<totalnum;i++){//����ֵת������ĸ�����ֵı����� 
		if(_state[i]>0)
		cout<<"B"<<_state[i]<<ends;
		if(_state[i]<0)
		cout<<"A"<<-_state[i]<<ends;
		if(_state[i]==0)
		cout<<"C"<<ends;
	}cout<<endl;
}
