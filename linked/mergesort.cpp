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
           if(head1->data<=head2->data){
              tail->next=head1;
              head1=head1->next;
           }
           else{
              tail->next=head2;
              head2=head2->next;
           }
           tail=tail->next;
      }
      if(head1!=NULL){
      tail->next=head1;
      }
      if(head2!=NULL){
      tail->next=head2;
      }
      return head;
}
Node* mergesort(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* temp=head->next;
	Node* s1=head;
	while((temp!=NULL && temp->next!=NULL)){
         temp=temp->next->next;
            s1=s1->next;
	}
	Node* a=s1;
	Node* b=s1->next;
	s1->next=NULL;
	Node* s=merge(mergesort(head),mergesort(b));
	return s;
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
	Node* s=mergesort(head);
	print(s);
}