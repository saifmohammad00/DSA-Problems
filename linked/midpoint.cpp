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
int length(Node* head){
	Node*temp=head;
	int count=0;
	while(temp!=NULL){
      temp=temp->next;
      count++;
	}
	return count;
}
void midpoint(Node*head){
	Node*temp=head;
	int count=0;
	while(temp->next!=NULL){
         temp=temp->next->next;
         count++;
         if(temp==NULL){
         	count--;
         	break;
         }
	}
	cout<<count+1<<endl;
}
Node* takeinput(){
	int data;
	cin>>data;
	Node*head=NULL;
	Node*tail=NULL;
	while(data!=-1){
		Node* a=new Node(data);
		if(head==NULL){
          head=a;
          tail=a;
		}
		else{
			tail->next=a;
			tail=a;
		}
		cin>>data;
	}
	return head;
}
int main(){
	Node* head=takeinput();
	int l=length(head);
	cout<<l<<endl;
	midpoint(head);
}