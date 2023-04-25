#include<bits/stdc++.h>
using namespace std;
bool isredundant(string s){
	stack<char> st;
    for(int i=0;s[i]!='\0';i++){
    	if(s[i]==')'){
    		bool flag=true;
    		char m=st.top();
    		st.pop();
    		while(st.top()!='('){
    			if(m=='+'||m=='-'||m=='/'||m=='*')
    				flag=false;
    			m=st.top();
    			st.pop();
    		}
    		if(flag==true){
    			return flag;
    		}
    	} 
    	else{
    		st.push(s[i]);
    	}
    }
    return false;
}
int main(){
	string s;
	cin>>s;
	if(isredundant(s)){
		cout<<"true"<<endl;
	}
	else{
         cout<<"false"<<endl;
	}
}