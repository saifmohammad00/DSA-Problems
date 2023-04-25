#include<bits/stdc++.h>
using namespace std;
int dpmincount(int n){
      int arr[n+1];
      arr[0]=0;
      arr[1]=1;
      arr[2]=2;
      arr[3]=3;
      for(int i=4;i<n+1;i++){
      	arr[i]=i;
      	for(int x=1;x<=ceil(sqrt(i));x++){
            int temp=x*x;
      	if(temp>i){
      		break;
      	}
      	else{
      		arr[i]=min(arr[i],1+arr[i-temp]);
      	}
      	}

      }
      return arr[n];
}
int memomincount(int arr[], int n){
    if(sqrt(n)-floor(sqrt(n))==0){
    	arr[n]=1;
		return arr[n];
	}
    if(n<=3){
    	arr[n]=n;
    	return arr[n];
    }
    int ans=n;
    if(arr[n]!=-1){
    	return arr[n];
    }
    for(int x=1;x*x<=n;x++){
    	int temp=x*x;
        arr[n]=ans=min(ans,1+memomincount(arr,n-temp));
    }
    return arr[n];
}
int memomincount(int n){
	int arr[n+1];
	for(int i=0;i<=n;i++){
		arr[i]=-1;
	}
	return memomincount(arr,n);
}
int mincount(int n){
	if(sqrt(n)-floor(sqrt(n))==0){
		return 1;
	}
    if(n<=3){
    	return 3;
    }
    int res=n;
    for(int x=1;x*x<n;x++){
    	int temp=x*x;
        res=min(res,1+mincount(n-temp));
    }
    return res;

}
int main(){
	int n;
	cin>>n;
	cout<<mincount(n)<<endl;
	cout<<memomincount(n)<<endl;
	cout<<dpmincount(n)<<endl;
}