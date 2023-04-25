#include<bits/stdc++.h>
using namespace std;
int minstepsto1(int n){
	if(n<=1){
		return 0;
	}
	int a=minstepsto1(n-1);
	int b=INT_MAX,c=INT_MAX;
	if(n%3==0){
		b=minstepsto1(n/3);
	}
	if(n%2==0){
		c=minstepsto1(n/2);
	}
	int ans=min(a,min(b,c))+1;
	return ans;
}
int memominstepsto1(int arr[],int n){
	if(n<=1){
		return 0;
	}
	if(arr[n]!=-1){
	     return arr[n];
	}
	else{
    int a=memominstepsto1(arr,n-1);
	int b=INT_MAX,c=INT_MAX;
	if(n%3==0){
		b=memominstepsto1(arr,n/3);
	}
	if(n%2==0){
		c=memominstepsto1(arr,n/2);
	}
	arr[n]=min(a,min(b,c))+1;
	}
	return arr[n];
	
}
int memominstepsto1(int n){
	int* arr=new int(n+1);
	for(int i=0;i<n+1;i++){
		arr[i]=-1;
	}
	return memominstepsto1(arr,n);
}

int dpminstepsto1(int n){
	int arr[n+1];
	arr[1]=0;
	for(int i=2;i<n+1;i++){
      if(!(i%2) && (i%3)){
      	arr[i]=1+min(arr[i-1],arr[i/2]);
      }
      else if((i%2) && !(i%3)){
      	arr[i]=1+min(arr[i-1],arr[i/3]);
      }
      else if(!(i%2) && !(i%3)){
           arr[i]=1+min(arr[i-1],min(arr[i/2],arr[i/3]));
      }
      else{
      	arr[i]=1+arr[i-1];
      }
	}
	 return arr[n];
}
int main(){
	int n;
	cin>>n;
	cout<<minstepsto1(n)<<endl;
	cout<<memominstepsto1(n)<<endl;
	cout<<dpminstepsto1(n);
}