#include<bits/stdc++.h>
using namespace std;
#include<climits>
template <typename T>
class stackarr{
	int nextindex;
	T *arr;
	int capacity;
public:
	stackarr(int tsize){
	   arr=new T[tsize];
	   nextindex=0;
	   capacity=tsize;
	}
void push(T data){
	if(nextindex+1==capacity){
	      T *ar=new T[2*capacity];
	      for(int i=0;i<capacity;i++){
	      	ar[i]=arr[i];
	      }
	      capacity=2*capacity;
	      delete[] arr;
	      arr=ar;
	    }
         arr[nextindex]=data;
	     nextindex++;
}
int size(){
	return nextindex;
}
bool isempty(){
	return nextindex==0;
}
void top(){
	if(nextindex==0){
		cout<<"empty"<<endl;
		return;
	}
	cout<<arr[nextindex-1]<<endl;
}
void pop(){
	if(isempty()){
		cout<<"empty"<<endl;
		return;
	}
	nextindex--;
}
};

int main(){
	stackarr<char> s(4);
	s.push(100);
	s.push(101);
	s.top();
	s.pop();
	s.top();
	cout<<s.isempty()<<endl;
	cout<<s.size()<<endl;
}