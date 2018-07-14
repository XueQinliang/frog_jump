#ifndef FROGSTATE_H
#define FROGSTATE_H
#include <iostream>
using namespace std;
class frogstate{
public:
    frogstate(int totalnum,int *state);//构造函数 
    frogstate(const frogstate& fr);//复制构造函数 
    void move(int num);//用来移动青蛙的函数 
    void show_way();//展示最后成功的移动方式 
    void show_state();//展示某一个状态所有的青蛙位置 
    void reset(int *state){//将青蛙位置初始化 
	    for(int i=0;i<totalnum;i++){
    	    *(_state+i)=*(state+i);
            if(*(_state+i)==0)
                num0=i;
        }
    }
    int getstep(){//得到当前步数 
        return stepnum;
    }

    int getstone(){//得到石头的位置 
        return num0;
    }

    bool isdeath(){//判断现在是否已经进入死局 
	    if(introuble==true) {
	        return true;
		}
        else return false;
    }
    bool iscomplete(){//判断是否完成目标 
        for(int i=0;i<totalnum/2;i++){//左边不可以有值为负的青蛙 
            if(_state[i]<=0)
                return false;
        }
        for(int i=totalnum/2+1;i<totalnum;i++){//右边不可以有值为正的青蛙 
            if(_state[i]>=0)
                return false;
        }
        return true;
    }

    ~frogstate(){//删除动态生成的数组 
        delete[] _state;
        delete[] jumpnum;
    }

protected:
    int num0;
    int totalnum;
    int stepnum;
    int *_state;
    int *jumpnum;
    bool introuble;//标志现在是否有还可以移动的青蛙的bool变量 
};

#endif // FROGSTATE_H
