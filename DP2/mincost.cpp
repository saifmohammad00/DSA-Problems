#include<bits/stdc++.h>
using namespace std;
int mincost(int **arr,int i,int j,int m,int n){
	if(i==m-1 && j==n-1){
		return arr[i][j];
	}
	if(i>=m || j>=n){
		return INT_MAX;
	}
      int x=mincost(arr,i,j+1,m,n);
      int y=mincost(arr,i+1,j,m,n);
      int z=mincost(arr,i+1,j+1,m,n);
      int ans=min(x,min(y,z)) + arr[i][j];
      return ans;
}
int mincost_mem(int **arr,int i,int j,int m,int n,int **output){
	if(i==m-1 && j==n-1){
		return arr[i][j];
	}
	if(i>=m || j>=n){
		return INT_MAX;
	}
	if(output[i][j]!=-1){
		return output[i][j];
	}
      int x=mincost_mem(arr,i,j+1,m,n,output);
      int y=mincost_mem(arr,i+1,j,m,n,output);
      int z=mincost_mem(arr,i+1,j+1,m,n,output);
      int ans=min(x,min(y,z)) + arr[i][j];
      output[i][j]=ans;
      return ans;
}
int mincost_dp(int **arr,int m,int n){
	int **output=new int*[m];
	for(int i=0;i<m;i++){
        output[i]=new int[n];
	}
	output[m-1][n-1]=arr[m-1][n-1];
	for(int j=n-2;j>=0;j--){
		output[m-1][j]=output[m-1][j+1]+arr[m-1][j];
	}
	for(int i=m-2;i>=0;i--){
		output[i][n-1]=output[i+1][n-1]+arr[i][n-1];
	}
	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
             output[i][j]=min(output[i][j+1],min(output[i+1][j],output[i+1][j+1]))+arr[i][j];
		}
	}
	return output[0][0];
}
int main(){
	int m,n;
	cin>>m>>n;
	int **arr=new int*[m];
	for(int i=0;i<m;i++){
		arr[i]=new int[n];
		for(int j=0;j<n;j++){
               cin>>arr[i][j];
		}
	}
	int **output=new int*[m];
	for(int i=0;i<m;i++){
			output[i]=new int[n];
		for(int j=0;j<n;j++){
               output[i][j]=-1;
		}
	}
	cout<<mincost(arr,0,0,m,n)<<endl;
	cout<<mincost_mem(arr,0,0,m,n,output)<<endl;
	cout<<mincost_dp(arr,m,n)<<endl;

}