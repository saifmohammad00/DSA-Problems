#include<bits/stdc++.h>
#include<stack>
using namespace std;
int revbracket(string s){
	stack<int> st;
	int totalrev=0;
	for(int i=0;i<s.size();i++){
		if(st.empty()){
			st.push(s[i]);
		}
		else{
			if(st.top()=='{' && s[i]=='}'){
				st.pop();
			}
			else if(st.top()=='}' && s[i]=='{'){
				st.pop();
				totalrev+=2;
			}
			else{
				st.push(s[i]);
			}
		}
	}
	if(st.size()%2!=0){
		return -1;
	}
	return st.size()/2+totalrev;
}
int main(){
	string s;
	cin>>s;
	cout<<revbracket(s)<<endl;
}