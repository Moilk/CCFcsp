#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<string,string> PAIR;

vector<string> strVec;
map<string,string> vars;

int main(void) {
	int M,N;
	string str,v;
	cin>>M>>N;
	getline(cin,str);
	for(int i=0; i<M; i++) {
		getline(cin,str);
		strVec.push_back(str);
	}
	for(int i=0; i<N; i++) {
		cin>>v;
		getline(cin,str);
		str=str.substr(2,str.length()-3);
		vars[v]=str;
	}
	// mark用于记录上次替换后的末尾位置，避免从头检索导致超时 
	string::size_type pre,post, mark;
	for(int i=0; i<M; i++) {
		string &tmp=strVec[i];
		mark=0;
		while(1) {
			pre=tmp.find("{{ ",mark);
			post=tmp.find(" }}",mark+3);
			if(pre!=string::npos&&post!=string::npos) {
				string sub=tmp.substr(pre+3,post-pre-3);
				tmp.replace(pre,post-pre+3,vars[sub]);
				mark+=vars[sub].length();
			} else {
				break;
			}
		}
		cout<<tmp<<endl;
	}

	return 0;
}
