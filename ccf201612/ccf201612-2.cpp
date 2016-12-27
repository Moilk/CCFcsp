#include <iostream>

using namespace std;

int S[]={0,3500,5000,8000,12500,38500,58500,83500,999999};
int T[]={0,3500,4955,7655,11255,30755,44755,61005,999999};
float f[]={1,0.97,0.9,0.8,0.75,0.7,0.65,0.55,0};

int main(void){
    int N,i,res;
    cin>>N;
    for(i=0;i<9;i++){
        if(T[i]>=N){
            break;
        }
    }
    res=S[i-1]+(N-T[i-1])/f[i-1];
    cout<<res<<endl;

    return 0;
}
