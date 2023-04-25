#include<bits/stdc++.h>
using namespace std;
   class polynomial{
   public:
	int capacity;
    int* arr1;
 public:
    polynomial(){
    	capacity=6;
    	arr1=new int[6];
    	for(int i=0;i<capacity;i++)
    	{
    		arr1[i]=0;
    	}
    }
    	void setcoef(int deg, int coef)
    	{
    		while(deg>=capacity)
    		{
    			int *ne=new int[2*capacity];
    			for(int i=0;i<capacity;i++){
    				ne[i]=arr1[i];
    			}
    			for(int i=capacity;i<2*capacity;i++){
    				ne[i]=0;
    			}
    			delete [] arr1;
    			capacity*=2;
                arr1=ne;
            }
            arr1[deg]=coef;
        }
        void print(){
        	for (int i = 0; i < capacity; ++i)
        	{
        		if(arr1[i]!=0){
                   cout<<arr1[i]<<"x"<<i<<" ";
        		}
        	}
        	cout<<endl;
        }
        polynomial operator+(polynomial &s2){
        	  int *array=new int[capacity];
           for (int i = 0; i < capacity; ++i)
           {
           	 array[i]=arr1[i]+s2.arr1[i];
           }
        }
};
int main()
{
	int n,l;
	cin>>n;
	int *arr=new int[n];
	int *coef=new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>coef[i];
	}
	polynomial s1;
	for(int i=0;i<n;i++){
		s1.setcoef(arr[i],coef[i]);
	}
	s1.print();
	cin>>l;
	int *ar=new int[l];
	int *coe=new int [l];
	for (int i = 0; i < l; ++i)
	{
		cin>>ar[i];
	}
	for (int i = 0; i < l; ++i)
	{
		cin>>coe[i];
	}
	polynomial s2;
	for(int i=0;i<l;i++){
		s2.setcoef(ar[i],coe[i]);
	}
	s2.print();
	polynomial s3;
	s3=s1+s2;
	s3.print();
}