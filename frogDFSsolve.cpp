#include "frogDFSsolve.h"
#include "frogstate.h"
#include <iostream>
#include <vector>
using namespace std;

static stack<frogstate,vector<frogstate> > states;
void frogDFSsolve::solve(){
    frogstate st0(_size,_state);
    states.push(st0);//����ʼ״̬����ջ�� 
    cout<<"DFS program running...\n";
    while(!states.empty()){//���ջ��Ϊ�� 
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
