#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    int *arr=new int[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    int value=0,secount=1,max=0,sec=0,count=1,sum=0;
	    
	    for(int i=0;i<n-1;i++)
	     {  
	         if(arr[i]!=arr[i+1]){
	             count=1;
	         } 
	         if(arr[i]==arr[i+1])
	         {
	             count++;
	             cout<<"first"<<count<<endl;
	         }
	         if(max<count ){
	             max=count;
	             value=arr[i];
	         }
	         
	     }
	     
	    for(int i=0;i<n-1;i++)
	     {   
	         if(arr[i]==arr[i+1] && arr[i]!=value)
	         {
	             secount++;
	             cout<<"second"<<secount<<endl;
	         }
	         if(sec<secount && arr[i]==arr[i+1] && arr[i]!=value){
	             sec=secount;
	             sum=arr[i];
	         }
	         if(arr[i]!=arr[i+1]){
	             secount==1;
	         }
	     }
	     if(max==sec){
	         cout<<max<<endl;
	     }
	     else{
	         if((max%2)+(max/2)>=sec){
	         cout<<(max%2)+(max/2)<<endl;
	     }
	     else
	     {
	         cout<<sec<<endl;
	     }
	     }
	     
	}
	return 0;
}
