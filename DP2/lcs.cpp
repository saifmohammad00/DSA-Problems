#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b){
	if(a.size()==0 || b.size()==0){
		return 0;
	}
	if(a[0]==b[0]){
		return 1+lcs(a.substr(1),b.substr(1));
	}
	else{
		int x=lcs(a,b.substr(1));
		int y=lcs(a.substr(1),b.substr(1));
		int z=lcs(a.substr(1),b);
		return max(x,max(y,z));
	}
}
int lcs_mem(string a,string b,int **output){
	int m=a.size();
	int n=b.size();
	if(a.size()==0 || b.size()==0){
		return 0;
	}
	if(a[0]==b[0]){
		return 1+lcs_mem(a.substr(1),b.substr(1),output);
	}
	if(output[m][n]!=-1){
		return output[m][n];
	}
	else{
		int x=lcs_mem(a,b.substr(1),output);
		int y=lcs_mem(a.substr(1),b.substr(1),output);
		int z=lcs_mem(a.substr(1),b,output);
		output[m][n]=max(x,max(y,z));
		return max(x,max(y,z));
	}
}
int lcs_dp(string a,string b){
	int m=a.size();
	int n=b.size();
	int **output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
	}
	for(int j=0;j<=n;j++){
       output[0][j]=0;
	}
	for(int i=1;i<=m;i++){
       output[i][0]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[m-i]==b[n-j]){
               output[i][j]=1+output[i-1][j-1];
			}
			else{
				int x=output[i-1][j];
				int y=output[i][j-1];
				int z=output[i-1][j-1];
				output[i][j]=max(x,max(y,z));
			}
		}
	}
	return output[m][n];
}
int main(){
	string a,b;
	cin>>a>>b;
	int m=a.size();
	int n=b.size();
	int **arr=new int*[m+1];
	for(int i=0;i<=m;i++){
		arr[i]=new int[n+1];
		for(int j=0;j<=n;j++){
		    arr[i][j]=-1;
		}
	}
	cout<<lcs(a,b)<<endl;
	cout<<lcs_mem(a,b,arr)<<endl;
	cout<<lcs_dp(a,b)<<endl;
}