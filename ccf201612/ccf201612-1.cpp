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
    int head;
    int tail=head=mid;
    for(int i=mid-1;i>=0;i--){
        if(vec[i]==vec[mid]){
            head--;
        }else{
            break;
        }
    }
    for(int i=mid+1;i<N;i++){
        if(vec[i]==vec[mid]){
            tail++;
        }else{
            break;
        }
    }
    if((N-1-tail)!=head){
        cout<<-1<<endl;
    }else{
        cout<<vec[mid]<<endl;
    }

    return 0;
}
