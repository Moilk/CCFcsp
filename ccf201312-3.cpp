#include <iostream>
#include <vector>

using namespace std;


int main(void){
	int N,tmp;
	vector<int> vec;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		vec.push_back(tmp);
	}
	int max=vec[0];
	for(int i=0;i<N;i++){
		int high=vec[i];
		int sum=high;
		for(int j=i+1;j<N;j++){
			if(high>vec[j]){
				high=vec[j];
			}
			sum=high*(j-i+1);
			if(max<sum){
				max=sum;
			}
		}
	}
	cout<<max<<endl;
	
	return 0;
}
