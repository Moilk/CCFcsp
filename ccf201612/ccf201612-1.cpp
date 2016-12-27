#include <iostream>
#include <algorithm>

using namespace std;

int N;
int vec[1005];

int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>vec[i];
    }

    sort(vec,vec+N);

    int mid=(N-1)/2;
    int co=1;
    for(int i=mid-1;i>=0;i--){
        if(vec[i]==vec[mid]){
            co++;
        }else{
            break;
        }
    }
    for(int i=mid+1;i<N;i++){
        if(vec[i]==vec[mid]){
            co++;
        }else{
            break;
        }
    }
    if((N%2)^(co%2)){
        cout<<-1<<endl;
    }else{
        cout<<vec[mid]<<endl;
    }

    return 0;
}
