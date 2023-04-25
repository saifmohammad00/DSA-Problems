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
Node* merge(Node* head1,Node* head2){
      Node* head=NULL;
      Node* tail=NULL;
      if(head1->data>head2->data){
       head=head2;
       tail=head2;
       head2=head2->next;
      }
      else{
      head=head1;
      tail=head1;
      head1=head1->next;
      }
      while(head1!=NULL && head2!=NULL){
           if(head1->data<head2->data){
              tail->next=head1;
              tail=tail->next;
              head1=head1->next;
           }
           else{
              tail->next=head2;
              tail=tail->next;
              head2=head2->next;
           }
      }
      if(head1==NULL){
      tail->next=head2;
      }
      else{
      tail->next=head1;
      }
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
	Node* head1=takeinput();
	print(head1);
	Node* head2=takeinput();
	print(head2);
	Node* u=merge(head1,head2);
	print(u);

}