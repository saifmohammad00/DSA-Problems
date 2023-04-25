#include<bits/stdc++.h>
using namespace std;
template <typename T>
class queued{
	T* arr;
	int nextindex;
	int capacity;
	int size;
	int firstindex;
public:
	queued(int tsize){
           arr=new T[tsize];
           nextindex=0;
           capacity=tsize;
           size=0;
           firstindex=-1;
	}
	bool empty(){
		return size==0;
	}
	T front(){
		if(empty()){
			cout<<"empty"<<endl;
			return 0;
		}
		return arr[firstindex];
	}

	void push(T element){
	if(capacity==size){
	   T* x=new T[2*capacity];
          int j=0;
          for(int i=firstindex;i<capacity;i++){
             x[i]=arr[i];
             j++;
          }
          for(int i=0;i<firstindex;i++){
          	x[j]=arr[i];
          	j++;
          }
          delete[] arr;
          arr=x;
          firstindex=0;
          nextindex=capacity;
          capacity*=2;

	}
	  arr[nextindex]=element;
	  nextindex=nextindex+1%capacity;
	  if(firstindex==-1){
	  	firstindex=0;
	  }
	  size++;

	}
void pop(){
	firstindex++;
	size--;
}


};
int main(){
	queued<char> s(3);
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	cout<<s.front()<<endl;
	s.pop();
	cout<<s.front()<<endl;
	cout<<s.empty()<<endl;
}