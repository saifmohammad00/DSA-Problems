#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data=0;
	Node* next;
	Node(int data){
	this->data=data;
	next=NULL;
	}
};
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
void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
	cout<<temp->data<<" ";
	temp=temp->next;
	}
	cout<<endl;
}
Node* rev(Node* temp){
	if(temp->next==NULL || temp==NULL){
		return temp;
	}
	Node* s=rev(temp->next);
	temp->next->next=temp;
	temp->next=NULL;
	return s;
}
int palindrome(Node* head){
	// length of the Node
	  Node* temp=head;
	  int len=0;
	  while(temp!=NULL){
	  	len++;
	  	temp=temp->next;
	  }
	  // midelement of the node
	  temp=head;
	  Node* y=NULL;
	  int s=0;
	  while(temp!=NULL){
	  	s++;
          if(s==(len+1)/2){
          	y=temp->next;
          	temp->next=NULL;
           break;
          } 
          	temp=temp->next;
	  }
	  // reverse half elements Node elements
	  Node* u=rev(y);
	  Node*l=head;
	  // palindrome condition
	  while(l!=NULL && u!=NULL){
	  	 if(l->data==u->data){
	  	 	l=l->next;
	  	 	u=u->next;
	  	 	continue;
	  	 }
	  	 else{
	  	 	return 0;
	  	 }
	  }
	  return -1;
}
int main(){
	Node* head=takeinput();
	print(head);
	if(head==NULL || head->next==NULL){
		cout<<"TRUE"<<endl;
	}
	else{
        	if(palindrome(head)){
		      cout<<"TRUE"<<endl;
	    }
	        else{
		    cout<<"FALSE"<<endl;
	    }

	}
}