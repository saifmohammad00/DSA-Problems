#include<iostream>
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
Node* swap(Node* head,int a,int b){
	Node* temp=head;
	int count=0;
	if(a==b){
		return head;
	}
	Node* p1=NULL;
	Node* p2=NULL;
	Node* c1=temp;
	Node* c2=temp;
	while(count!=a){
		p1=c1;
		c1=c1->next;
		count++;
	}
	count=0;
	while(count!=b){
		p2=c2;
		c2=c2->next;
		count++;
	}
     if(p1!=NULL){
        p1->next=c2;
     }
     else{
     	head=c2;
     }
     if(p2!=NULL){
     	p2->next=c1;
     }
     else{
     	head=c1;
     }
     temp=c2->next;
     c2->next=c1->next;
     c1->next=temp;
     return head;
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
    Node* newhead=(swap(head,a,b));
    print(newhead);
}


