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
Node* delnnodes(Node* head,int a,int b){
	Node* temp=head;
	int count1=0;
	int count2=0;
	Node* t=NULL;
	Node* t1=NULL;
	while(temp!=NULL){
        if(count1!=a){
        	count1++; 
            t=temp;
            temp=temp->next;
            continue;
        }
        else if(count2!=b){
        	count2++;
        	t1=temp->next;
        	temp=temp->next;
        	continue;

        }
        t->next=t1;
        count1=0;
        count2=0;
	}
	if(t1==NULL){
		t->next=t1;
	}
	return head;
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
int main(){
	Node* head=takeinput();
	print(head);
	int a,b;
	cin>>a>>b;
	delnnodes(head,a,b);
	print(head);
}