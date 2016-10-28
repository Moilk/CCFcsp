#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct ListN {
	string op;
	string param;
	ListN *next=NULL;
}*List;

vector<char> noparam;
vector<char>param;

void insert(ListN *head, string op, string param) {
	ListN *newNode=NULL,*pre=NULL,*post=NULL;
	newNode=new ListN;
	newNode->op=op;
	newNode->param=param;
	newNode->next=NULL;
	pre=head;
	post=head->next;
	while(post) {
		if(newNode->op[1]<post->op[1]) {
			break;
		}
		pre=post;
		post=post->next;
	}
	if(pre->op[1]==newNode->op[1]) {	// 如果选项已存在，则仅更新
		pre->param=newNode->param;
	} else {	// 否则插入新元素
		newNode->next=post;
		pre->next=newNode;
	}
}

void getop(string &op) {
	int len=op.size();
	for(int i=0; i<len; i++) {
		if(i==len-1) {
			noparam.push_back(op[i]);
			break;
		}
		if(op[i+1]==':') {
			param.push_back(op[i]);
			i++;
		} else {
			noparam.push_back(op[i]);
		}
	}
}

int whatis(string &str) {
	if(str.size()==0) {
		return -1;
	}
	if(str.size()==2&&str[0]=='-') {
		char c=str[1];
		vector<char>::iterator it=find(noparam.begin(),noparam.end(),c);
		if(it==noparam.end()) {
			it=find(param.begin(),param.end(),c);
			if(it==param.end()) {
				return 0;
			} else {
				return 2;
			}
		} else {
			return 1;
		}
	}
	return 0;
}

void display(ListN *T) {
	if(T) {
		if(T->op!="") {
			cout<<' '<<T->op;
		}
		if(T->param!="") {
			cout<<' '<<T->param;
		}
		display(T->next);
	}
}

void clear(ListN *T) {
	if(T) {
		clear(T->next);
		delete(T);
		T=NULL;
	}
}

void run(string &cmd,ListN*head) {
	vector<string> vec;
	istringstream is(cmd);
	string tmp;
	is>>tmp;
	while(is>>tmp) {
		vec.push_back(tmp);
	}
	int len=vec.size();
	for(int i=0; i<len; i++) {
		switch(whatis(vec[i])) {
			case 2:
				if(i==len-1) {
					return;
				}
				insert(head,vec[i],vec[i+1]);
				i++;
				break;
			case 1:
				insert(head,vec[i],"");
				break;
			default:
				return;
		}
	}
}

int main(void) {
	string op,tmp;
	int N;
	vector<string> cmds;
	cin>>op;
	getop(op);
	cin>>N;
	getline(cin,tmp);
	for(int i=0; i<N; i++) {
		ListN *head=new ListN;
		head->next=NULL;

		getline(cin,tmp);
		run(tmp,head);
		if(head->next==NULL) {
			cout<<"Case "<<i+1<<": ";
		} else {
			cout<<"Case "<<i+1<<':';
		}
		display(head->next);
		cout<<endl;
		clear(head);
	}

	return 0;
}
