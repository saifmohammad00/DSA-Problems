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
	temp=temp-> next;
	}
	cout<<endl;
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
Node* duplicate(Node* head){
     Node* temp=head;
     while(temp->next!=NULL){
     	Node* temp2=temp->next;
     	Node* temp3=temp->next->next;
     	if(temp->data==temp2->data){
              temp->next=temp3;
              continue;
     	}
     	temp=temp->next;
     }
     return head;
}
int main(){
	Node* head=takeinput();
	print(head);
	Node* y=duplicate(head);
	print(y);
}