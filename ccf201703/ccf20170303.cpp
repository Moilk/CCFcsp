#include <iostream>
#include <string>

using namespace std;

enum{
	B_P,	// 段落
	B_H,	// 标题
	B_UL,	// 无序列表
	I_P,	// 普通文字
	I_EM,	// 强调
	I_A		// 超链接
};

string parse_inline(string str){
	static int __text=I_P;
}

string parse(string line){
	static int __block=B_P;
	if(line.size()==0){

		return line;
	}	
}

int main(void){
	string line;
	while(getline(cin,line)){
		cout<<parse(line)<<endl;
	}




	return 0;
}