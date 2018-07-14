#include "frogBFSsolve.h"
#include <iostream>
using namespace std;
void frogBFSsolve::solve(){
    static queue<frogstate> states;
    frogstate st0(_size,_state);
    states.push(st0);
    cout<<"BFS program running...\n";
    while(!states.empty()){
        frogstate crntSt = states.front();//得到队列头部的对象 
        states.pop();
        if(crntSt.iscomplete()){
        	crntSt.reset(_state);
            crntSt.show_way();
            break;
        }
        int stonenum = crntSt.getstone();//得到石头的位置 
        int steps[4] = {-2, -1, 1, 2};
        for(int frog=0;frog<4;frog++){//依次移动石头周围的四只青蛙 
        	frogstate Try=crntSt;
        	Try.move(stonenum+steps[frog]);
        	if(!Try.isdeath()){//如果这个状态没有造成死局 
                states.push(Try);//将这个状态压入栈内 
            }
		}
    }
}
