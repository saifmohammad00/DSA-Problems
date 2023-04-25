#include<bits/stdc++.h>
using namespace std;
knapsack(int weight[],int value[],int n,int maxweight){
    if(n==0 || maxweight==0){
    	return 0;
    }
    if(weight[0]>maxweight){
    	return knapsack(weight+1,value+1,n-1,maxweight);
    }
    int x=knapsack(weight+1,value+1,n-1,maxweight-weight[0])+value[0];
    int y=knapsack(weight+1,value+1,n-1,maxweight);
    return max(x,y);
}
int main(){
	int n;
	cin>>n;
	int weight[n],value[n];
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	for(int i=0;i<n;i++){
		cin>>value[i];
	}
	int maxweight;
	cin>>maxweight;
	cout<<knapsack(weight,value,n,maxweight);
}