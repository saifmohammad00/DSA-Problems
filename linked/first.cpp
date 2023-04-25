#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void length(Node*head,int *c){
	Node*temp=head;
     int count=0;
     while(temp!=NULL){
     	temp=temp->next;
     	count++;
     }
     *c=count;
     cout<<count<<endl;
}
Node* insertNode(Node* head, int i, int data,int *c){
    Node* newNode = new Node(data);
      int count = 0;
      Node* temp=head;
      if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
       }
      else if(i<0 || i>*c){
          cout<<"invalid operation"<<endl;
      }
      else{
        while(count < i - 1){
        temp = temp -> next;
        count++;
      }
      Node* a=temp->next;
      temp->next=newNode;
      newNode->next=a;
      return head;
      }
}
void delet(Node* head, int i){
	Node* temp=head;
	int count=0;
	while(count<i-1){
		temp=temp->next;
		count++;
	}
	Node* x=temp->next;
	Node* y=temp->next->next;
	temp->next=y;
}
Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

void print(Node* head){
	Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node*head = takeInput();
    int c;
    print(head);
    length(head,&c);
    int i,data;
	cin>>i>>data;
	Node* hel=insertNode(head,i,data,&c);
	print(hel);
    length(hel,&c);
	int j;
	cin>>j;
	delet(hel,j);
	print(hel);
    length(hel,&c);
	return 0;
}