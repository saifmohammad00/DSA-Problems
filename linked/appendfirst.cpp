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
Node* lastfirst(Node* head,int l){
	Node*temp=head;
	int count=0;
	Node*temp2=head;
	while(temp->next!=NULL){
		count++;
		if(count==l){ 
             temp2=temp;
	   }
		 temp=temp->next;
	}
	Node* x=temp2->next;
	temp2->next=NULL;
	temp->next=head;
	return x;

}
void print(Node* head){
	Node* temp=head;
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
int length(Node* head){
       Node* temp=head;
       int count=0;
       while(temp!=NULL){
       	count++;
       	temp=temp->next;
       }
       return count;
}
int main(){
	Node* head=takeinput();
	print(head);
	int g;
	cin>>g;
	int s=length(head);
	cout<<s<<endl;
	int l=s-g;
	Node* newhead=lastfirst(head,l);
	print(newhead);
}