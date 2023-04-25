#include<bits/stdc++.h>
using namespace std;
int editdistance(string a,string b){
	if(a.size()==0 || b.size()==0){
		return max(a.size(),b.size());
	}
	if(a[0]==b[0]){
		return editdistance(a.substr(1),b.substr(1));
	}
	else{
		int x=editdistance(a.substr(1),b)+1;
		int y=editdistance(a,b.substr(1))+1;
		int z=editdistance(a.substr(1),b.substr(1))+1;
		return min(x,min(y,z));
	}

}
int editdistance_mem(string a,string b,int **arr){
	int m=a.size();
	int n=b.size();
    if(a.size()==0 || b.size()==0){
		return max(a.size(),b.size());
	}
	if(arr[m][n]!=-1){
		return arr[m][n];
	}
	int ans;
	if(a[0]==b[0]){
		ans=editdistance_mem(a.substr(1),b.substr(1),arr);
	}
	else{
		int x=editdistance_mem(a.substr(1),b,arr)+1;
		int y=editdistance_mem(a,b.substr(1),arr)+1;
		int z=editdistance_mem(a.substr(1),b.substr(1),arr)+1;
		ans=min(x,min(y,z));
	}
	arr[m][n]=ans;
	return editdistance_mem(a,b,arr);
}
int editdistance_dp(string a,string b){
	int m=a.size();
	int n=b.size();
	int **output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
	}
	for(int j=0;j<=n;j++){
       output[0][j]=j;
	}
	for(int i=1;i<=m;i++){
       output[i][0]=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[m-i]==b[n-j]){
               output[i][j]=output[i-1][j-1];
			}
			else{
				int x=output[i-1][j];
				int y=output[i][j-1];
				int z=output[i-1][j-1];
				output[i][j]=min(x,min(y,z))+1;
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
    cout<<editdistance(a,b)<<endl;
    cout<<editdistance_mem(a,b,arr)<<endl;
    cout<<editdistance_dp(a,b)<<endl;
}