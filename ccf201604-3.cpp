#include <iostream>

using namespace std;

string str[10];

string::size_type refind(const string &str,string::size_type pos,const char c) {
	int p=pos;
	while(1) {
		if(p==-1) {
			return (string::npos);
		}
		if(str[p]==c) {
			return p;
		}
		p--;
	}

	return (string::npos);
}

int main(void) {
	int N;
	string pwd,pwdf,tmp;
	cin>>N;
	cin>>pwd;
	getchar();
	string::size_type pre=0;
	string::size_type post;
	while(1) {
		post=pwd.find('/',pre+1);
		if(post==string::npos) {
			break;
		}
		pre=post;
	}
	if(pre==0) {
		pwdf="/";
	} else {
		pwdf=pwd.substr(0,pre);
	}

	for(int i=0; i<N; i++) {
		getline(cin,tmp);
		// 头部的处理
		if(tmp[0]!='/') {
			tmp=pwd+"/"+tmp;
		}
		// 去掉多于斜杠
		pre=0;
		while(1) {
			post=tmp.find('/',pre);
			if(post==string::npos) {
				break;
			}
			pre=post+1;
			post++;
			while(1) {
				if(post>=tmp.size()||tmp[post]!='/') {
					break;
				}
				post++;
			}
			tmp.erase(pre,post-pre);
		}
		// 去掉中间的单点
		pre=0;
		while(1) {
			post=tmp.find("/./",pre);
			if(post==string::npos) {
				break;
			}
			tmp.erase(post+1,2);
			pre=post;
		}
		// 去掉中间的双点
		pre=0;
		while(1) {
			post=tmp.find("/../",pre);
			if(post==string::npos) {
				break;
			}
			pre=refind(tmp,post-1,'/');
			if(pre!=string::npos) {
				pre++;
			} else {
				pre=post+1;
			}
			tmp.erase(pre,post+4-pre);
			pre--;
		}

		//去掉末尾的点
		int len=tmp.size();
		if(len>=2&&tmp[len-1]=='.'&&tmp[len-2]=='/') {
			tmp.erase(len-1,1);
		}
		len=tmp.size();
		if(len>=3&&tmp[len-1]=='.'&&tmp[len-2]=='.'&&tmp[len-3]=='/') {
			pre=refind(tmp,len-4,'/');
			if(pre!=string::npos) {
				pre++;
			} else {
				pre=len-2;
			}
			tmp.erase(pre,len);
		}

		// 去掉末尾的斜杠
		len=tmp.size();
		if(len>1&&tmp[len-1]=='/') {
			tmp.erase(len-1,1);
		}
		cout<<tmp<<endl;
	}

	return 0;
}
