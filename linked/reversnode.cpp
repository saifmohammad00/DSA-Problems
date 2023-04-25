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
void printrev(Node* head){
	if(head==NULL){
		return;
	}
	printrev(head->next);
	cout<<head->data<<" ";
}
Node* reverse(Node*head){
	if(head->next==NULL){
		return head;
	}
	Node* re=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return re;
}
void print(Node* head){
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
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
    	Node* newnode=new Node(data);
    	if(head==NULL){
    		head=newnode;
    		tail=newnode;
    	}
        else{
        	tail->next=newnode;
        	tail=newnode;
        }
        cin>>data;
    }
    return head;
}
int main(){
	Node* n1=takeinput();
	print(n1);
	printrev(n1);
	cout<<endl;
	Node* h=reverse(n1);
	print(h);
}