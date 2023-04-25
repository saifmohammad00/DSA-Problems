#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int> &s){
	if(s.empty()){
		return;
	}
	int x=s.front();
	s.pop();
	reverse(s);
	s.push(x);
}
int main(){
	queue<int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	   int t;
	   cin>>t;
	   s.push(t);
	}
	reverse(s);
	while(!s.empty()){
		cout<<s.front()<<" ";
		s.pop();
	}
}