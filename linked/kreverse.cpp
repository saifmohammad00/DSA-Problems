#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int data){
	this->data=data;
	next=NULL;
	}
};
void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
	cout<<temp->data<<" ";
	temp=temp->next;
	}
	cout<<endl;
}
Node* krev(Node* head,int k){
	if(head==NULL){
		return NULL;
	}
     int s=0;
     Node* prev=NULL;
     Node* front=NULL;
     Node* current=head;
     while(current!=NULL && s!=k){
     	s++;
     	front=current->next;
     	current->next=prev;
     	prev=current;
     	current =front; 
     }
     print(prev);
     if(front!=NULL){
       head->next=krev(front,k);
     }
     return prev;
     
     
}
Node* takeinput(){
	int data;
	cin>>data;
	Node* head=NULL;
	Node* tail=NULL;
	while(data!=-1){
	  Node* x=new Node(data);
	  if(head==NULL){
	  head=x;
	  tail=x;
	  }
	  else{
	  tail->next=x;
	  tail=tail->next;
	  }
	  cin>>data;
	}
	return head;
}
int main(){
	Node* head=takeinput();
	print(head);
	int k;
	cin>>k;
	print(krev(head,k));
}