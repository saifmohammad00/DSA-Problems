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
Node* evenodd(Node* head){
	Node* temp=head;
	Node* odh=NULL;
	Node* odt=NULL;
	Node* evh=NULL;
	Node* evt=NULL;
	while(temp!=NULL){
		if((temp->data)%2!=0){
			if(odh==NULL){
				odh=temp;
				odt=temp;
			}
			else{
				odt->next=temp;
				odt=odt->next;
			}
		}
		else{
			if(evh==NULL){
				evh=temp;
				evt=temp;
			}
			else{
				evt->next=temp;
				evt=evt->next;
			}
		}
		temp=temp->next;
	}
	odt->next=evh;
	evt->next=NULL;

	return odh;
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
	Node* s=evenodd(head);
	print(s);

}