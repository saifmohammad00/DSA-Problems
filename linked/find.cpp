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
int find(Node* head,int i){
	 int count=0;
	 Node* temp=head;
      while(temp!=NULL){
      	count++;
       	if(i==temp->data){
      		return count-1;
      	}
      	temp=temp->next;
      }
      return -1;
}

int findrev(Node* head,int val,int count){
	if(head->data==val){
		return count;
	}
	else if(head->next==NULL){
		return -1;
	}
	findrev(head->next,val,count+1);
}

Node* takeinput(){
	int data;
	cin>>data;
	Node*head=NULL;
	Node*tail=NULL;
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
int main(){
	int t;
	cin>>t;
	while(t--){
       Node* head=takeinput();
       print(head);
       int i;
       cin>>i;
       cout<<find(head,i)<<endl;
       int count=0;
       cout<<findrev(head,i,count)<<endl;
	}
}