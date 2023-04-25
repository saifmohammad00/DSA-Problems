#include<bits/stdc++.h>
using namespace std;
// only these characters (),{},[] in question
bool balanced(string s){
    stack<char> st;
	for(int i=0;s[i]!='\0';i++){
	     if(st.empty() && (s[i]==']' || s[i]==')' || s[i]=='}')){
	     	return 0;
	     }
	     else if(st.empty()){
	     	st.push(s[i]);
	     }
	     else if(st.top()=='(' && s[i]==')' || st.top()=='{' && s[i]=='}' || st.top()=='[' && s[i]==']'){
	     	st.pop();
	     }
	     
	}
    return st.empty();
}
int main(){
	string s;
	cin>>s;
	if(balanced(s)){
	cout<<"True"<<endl;
	}
	else{
	cout<<"false"<<endl;
	}
}