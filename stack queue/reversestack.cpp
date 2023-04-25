#include<bits/stdc++.h>
using namespace std;
void reversestack(stack<int> &s1,stack<int> &s2)
	{
		if(s1.empty()){
			return;
		}
             int ans=s1.top();
		     s1.pop();
		     reversestack(s1,s2);
		     while(!s1.empty()){
                 s2.push(s1.top());
                 s1.pop();
		     }
		     s1.push(ans);
		     while(!s2.empty()){
		     	s1.push(s2.top());
		     	s2.pop();
		     } 
}
	int main(){
		stack<int> s1;
		stack<int> s2;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int s;
			cin>>s;
			s1.push(s);
		}
		reversestack(s1,s2);
		while(!s1.empty()){
			cout<<s1.top()<<" ";
			s1.pop();
		}
}