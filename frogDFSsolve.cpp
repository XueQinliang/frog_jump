#include "frogDFSsolve.h"
#include "frogstate.h"
#include <iostream>
#include <vector>
using namespace std;

static stack<frogstate,vector<frogstate> > states;
void frogDFSsolve::solve(){
    frogstate st0(_size,_state);
    states.push(st0);//将初始状态放入栈内 
    cout<<"DFS program running...\n";
    while(!states.empty()){//如果栈不为空 
        frogstate crntSt = states.top(); 
        states.pop();
        if(crntSt.iscomplete()){
        	crntSt.reset(_state);
            crntSt.show_way();
            /*cout<<"clear"<<endl;
            int flag=true;
            while(!states.empty()){
				states.pop();
				if(!flag)cout<<"ccc"<<endl; 
				cout<<states.size()<<endl;
				if(states.size()==229)
					{
					crntSt=states.top();
					crntSt.show_state(); 
					flag=false;
					}
			}*/ 
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
