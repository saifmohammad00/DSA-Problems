#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node{
public:
	T data;
	Node* next;
	Node(T data){
	 this->data=data;
	 next=NULL;
	}
};
template <typename T>
class queued{
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	queued(){
		head=NULL;
		tail=NULL;
		size=0;
	}
	int getsize(){
		return size;
	}
	bool empty(){
		return size==0;
	}
	T front(){
		return head->data;
	}
	void push(T element){
		Node<T>* x=new Node<T>(element);
		if(head==NULL){
			head=x;
			tail=x;
		}
		else{
			tail->next=x;
			tail=tail->next;
		}
		size++;
	}
	T pop(){
		T ans=head->data;
		Node<T>* temp=head->next;
		delete head;
		head=temp;
		size--;
		return ans;
	}
};
int main(){
	queued<char> s;
	s.push(100);
	s.push(101);
    s.push(102);
    s.push(103);
    cout<<s.front()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.front()<<endl;
    cout<<s.empty()<<endl;
    cout<<s.getsize()<<endl;
}