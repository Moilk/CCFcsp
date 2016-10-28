#include <iostream>
#include <queue>

using namespace std;

queue<int> mp[21];
int N;

int main(void){
    for(int i=1,j=1;i<=20;i++){ // 每行用一个队列表示，卖一个位置弹出一个元素
        mp[i].push(j++);
        mp[i].push(j++);
        mp[i].push(j++);
        mp[i].push(j++);
        mp[i].push(j++);
    }
    cin>>N;
    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        bool ok=false;
        // 查找连续座位
        for(int row=1;row<=20;row++){
            if(mp[row].size()>=num){
                for(int j=0;j<num;j++){
                    cout<<mp[row].front()<<' ';
                    mp[row].pop();
                }
                ok=true;
                break;
            }
        }
        // 查找非连续座位
        if(!ok){
            for(int row=1;row<=20&&num>0;row++){
                while(num>0&&!mp[row].empty()){
                    cout<<mp[row].front()<<' ';
                    mp[row].pop();
                    num--;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
