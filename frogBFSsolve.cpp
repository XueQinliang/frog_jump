#include "frogBFSsolve.h"
#include <iostream>
using namespace std;
void frogBFSsolve::solve(){
    static queue<frogstate> states;
    frogstate st0(_size,_state);
    states.push(st0);
    cout<<"BFS program running...\n";
    while(!states.empty()){
        frogstate crntSt = states.front();//�õ�����ͷ���Ķ��� 
        states.pop();
        if(crntSt.iscomplete()){
        	crntSt.reset(_state);
            crntSt.show_way();
            break;
        }
        int stonenum = crntSt.getstone();//�õ�ʯͷ��λ�� 
        int steps[4] = {-2, -1, 1, 2};
        for(int frog=0;frog<4;frog++){//�����ƶ�ʯͷ��Χ����ֻ���� 
        	frogstate Try=crntSt;
        	Try.move(stonenum+steps[frog]);
        	if(!Try.isdeath()){//������״̬û��������� 
                states.push(Try);//�����״̬ѹ��ջ�� 
            }
		}
    }
}
