#ifndef FROGSTATE_H
#define FROGSTATE_H
#include <iostream>
using namespace std;
class frogstate{
public:
    frogstate(int totalnum,int *state);//���캯�� 
    frogstate(const frogstate& fr);//���ƹ��캯�� 
    void move(int num);//�����ƶ����ܵĺ��� 
    void show_way();//չʾ���ɹ����ƶ���ʽ 
    void show_state();//չʾĳһ��״̬���е�����λ�� 
    void reset(int *state){//������λ�ó�ʼ�� 
	    for(int i=0;i<totalnum;i++){
    	    *(_state+i)=*(state+i);
            if(*(_state+i)==0)
                num0=i;
        }
    }
    int getstep(){//�õ���ǰ���� 
        return stepnum;
    }

    int getstone(){//�õ�ʯͷ��λ�� 
        return num0;
    }

    bool isdeath(){//�ж������Ƿ��Ѿ��������� 
	    if(introuble==true) {
	        return true;
		}
        else return false;
    }
    bool iscomplete(){//�ж��Ƿ����Ŀ�� 
        for(int i=0;i<totalnum/2;i++){//��߲�������ֵΪ�������� 
            if(_state[i]<=0)
                return false;
        }
        for(int i=totalnum/2+1;i<totalnum;i++){//�ұ߲�������ֵΪ�������� 
            if(_state[i]>=0)
                return false;
        }
        return true;
    }

    ~frogstate(){//ɾ����̬���ɵ����� 
        delete[] _state;
        delete[] jumpnum;
    }

protected:
    int num0;
    int totalnum;
    int stepnum;
    int *_state;
    int *jumpnum;
    bool introuble;//��־�����Ƿ��л������ƶ������ܵ�bool���� 
};

#endif // FROGSTATE_H
