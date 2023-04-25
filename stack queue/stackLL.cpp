#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node{
	public:
	T data;
	Node<T>* next;
	Node(T data){
	this->data=data;
	next=NULL;
	}
};
template <typename T>
class stack1{
     Node<T>* head;
     Node<T>* tail;
     int size;
	public:
	stack1(){
	head=NULL;
	tail=NULL;
	size=0;
	}
	void push(T element){
		Node<T>* x=new Node<T>(element);
	    x->next=head;
	    head=x;
	    size++;
	}
	T pop(){
		if(isempty()){
			return 0;
		}
		int ans=head->data;
		Node<T>* temp=head;
		head=head->next;
		delete temp;
		size--;
		return ans;
	}
	bool isempty(){
		return size==0;
	}
	T top(){
		if(isempty()){
			return 0;
		}
		return head->data;
	}
	int getsize(){
		return size;
	}
};
int main(){
	stack1<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	cout<<s.top()<<endl;
     s.pop();
     cout<<s.top()<<endl;
	cout<<s.getsize()<<endl;
	cout<<s.isempty()<<endl;
	cout<<s.isempty()<<endl;
}