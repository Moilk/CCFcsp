#include <iostream>

using namespace std;

int main(void){
    int n,k,a,g, r=0;
    cin>>n>>k;
    while(n > 0){
        g=0;
        // `g<k`才能`n--`, 所以不要把两个条件顺序弄反了
        while(g < k && n-- > 0){
            cin>>a;
            g+=a;
        }
        r++;
    }
    cout<<r<<endl;

    return 0;
}