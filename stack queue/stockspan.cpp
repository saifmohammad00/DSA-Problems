#include<bits/stdc++.h>
using namespace std;
void stockspan(int *price,int n){
	stack<int> s;
	int output[n];
	output[0]=1;
	s.push(0);
    for(int i=1;i<n;i++){
        if(price[i]<s.top()){
        	output[i]=1;
        }
        else{
              while(!s.empty() && price[i]>price[s.top()]){
              	s.pop();
              }
              if(s.empty()){
                 output[i]=i+1;
              }
              else{
              	output[i]=i-s.top();
              }
        }
        s.push(i);
    }
    for(int i=0;i<n;i++){
    	cout<<output[i]<<" ";
    }
}
int main(){
	int n;
	cin>>n;
	int* price=new int[n];
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	stockspan(price,n);

}