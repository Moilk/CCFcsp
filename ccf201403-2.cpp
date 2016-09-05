#include <iostream>
#include <vector>

using namespace std;

struct Win {
	int x1;
	int y1;
	int x2;
	int y2;
	int wid;
};

struct Pn2 {
	int x;
	int y;
};

int main(void) {
	vector<Win> vec;
	Pn2 clicks[10];
	Win tmp;
	int N,M;
	cin>>N>>M;
	for(int i=0; i<N; i++) {
		cin>>tmp.x1>>tmp.y1>>tmp.x2>>tmp.y2;
		tmp.wid=i+1;
		vec.push_back(tmp);
	}
	for(int i=0; i<M; i++) {
		cin>>clicks[i].x>>clicks[i].y;
	}
	Pn2 key;
	for(int i=0; i<M; i++) {
		int res=0;
		key=clicks[i];
		for(vector<Win>::iterator it=vec.end()-1; it>=vec.begin();) {
			if(key.x>=it->x1&&key.x<=it->x2&&key.y>=it->y1&&key.y<=it->y2) {
				tmp=*it;
				vec.erase(it);
				vec.push_back(tmp);
				res=tmp.wid;
				break;
			} else {
				it--;
			}
		}
		if(res) {
			cout<<res<<endl;
		} else {
			cout<<"IGNORED"<<endl;
		}
	}

	return 0;
}
