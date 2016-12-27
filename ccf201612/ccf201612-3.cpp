#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct R{
    string name;
    map<string,int> priv;
}Role,User;

vector<Role> roleVec;
vector<User> userVec;

// pair<权限:等级>
pair<string,int> category(string str){
    int lev=-1;
    int len=str.length();
    if(len>=3&&str[len-2]==':'){
        lev=str[len-1]-'0';
        str=str.substr(0,len-2);
    }
    return pair<string,int>(str,lev);
}

int main(void){
    int n;
    string str;

    // 输入权限定义
    // 因为测试用例保证合法所以用不上
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
    }

    // 输入角色定义
    cin>>n;
    int nn;
    for(int i=0;i<n;i++){
        Role role;
        cin>>role.name>>nn;
        map<string,int> &refPriv=role.priv;
        for(int j=0;j<nn;j++){
            cin>>str;
            pair<string,int> t_pair=category(str);
            // 如果权限重复,取最大值
            map<string,int>::iterator it=refPriv.find(t_pair.first);
            if(it!=refPriv.end()){
                it->second=max(t_pair.second,it->second);
            }else{
                refPriv.insert(t_pair);
            }
        }
        roleVec.push_back(role);
    }

    // 输入用户定义
    cin>>n;
    for(int i=0;i<n;i++){
        User user;
        cin>>user.name>>nn;
        map<string,int> &usrPriv=user.priv;
        for(int j=0;j<nn;j++){
            cin>>str;
            int len=roleVec.size();
            int k;
            // 查询角色是否存在
            for(k=0;k<len;k++){
                if(roleVec[k].name==str){
                    break;
                }
            }
            // 角色存在,添加角色下的全部权限
            if(k!=len){
                map<string,int> &rolePriv=roleVec[k].priv;
                for(map<string,int>::iterator it=rolePriv.begin();it!=rolePriv.end();++it){
                    // 权限重复则取最大值
                    map<string,int>::iterator usr_it=usrPriv.find(it->first);
                    if(usr_it!=usrPriv.end()){
                        usr_it->second=max(usr_it->second,it->second);
                    }else{
                        usrPriv.insert(pair<string,int>(it->first,it->second));
                    }
                }
            }
        }
        userVec.push_back(user);
    }

    // 查询
    cin>>n;
    string name;
    for(int i=0;i<n;i++){
        cin>>name>>str;
        int len=userVec.size();
        int j;
        // 用户是否存在
        for(j=0;j<len;j++){
            if(userVec[j].name==name){
                break;
            }
        }
        // 用户存在
        if(j!=len){
            map<string,int> &priv=userVec[j].priv;
            pair<string,int> cgy=category(str);
            // 用户是不是存在这个权限
            map<string,int>::iterator it=priv.find(cgy.first);
            // 权限存在
            if(it!=priv.end()){
                // 不带等级的查询
                if(cgy.second==-1){
                    if(it->second==-1){ // 权限就是不带等级的
                        cout<<"true"<<endl;
                    }else{  // 权限带等级
                        cout<<it->second<<endl;
                    }
                }else{  // 带等级查询
                    if(cgy.second<=it->second){
                        cout<<"true"<<endl;
                    }else{
                        cout<<"false"<<endl;
                    }
                }
            }else{  // 用户没有这个权限
                cout<<"false"<<endl;
            }

        }else{  // 没有这个用户
            cout<<"false"<<endl;
        }
    }

    return 0;
}
