#include <bits/stdc++.h>
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
Node* insert(Node*head,int i,int dat){
	if(i==0){
		Node* x=new Node(dat);
		x->next=head;
		return x;
	}
	if(head==NULL)
		return head;
	Node* k=insert(head->next,i-1,dat);
	head->next=k;
	return head;
}
	
Node* del(Node*head,int i){
    if(head==NULL)
    	return head;
    if(i==0){
    	return head->next;
    }
    Node* k=del(head->next,i-1);
    head->next=k;
    return head;
}

void print(Node*head){
     Node*temp=head;
     while(temp!=NULL){
     	cout<<temp->data<<" ";
     	temp=temp->next;
     }
     cout<<endl;
}
Node* takeinput(){
     int data;
     cin>>data;
     Node*head=NULL;
     Node*tail=NULL;
	while(data!=-1){
	Node* newnode=new Node(data);
	if(head==NULL){
      head=newnode;
      tail=newnode;
	}
	tail->next=newnode;
     tail=newnode;
	cin>>data;
}
return head;
}
int main(){
	Node* head=takeinput();
	print(head);
	int i,dat;
	cin>>i>>dat;
	Node* l=insert(head,i,dat);
	print(l);
	int j;
	cin>>j;
	print(del(l,j));
	
}