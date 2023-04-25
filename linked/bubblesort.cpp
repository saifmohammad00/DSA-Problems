#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

void print(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int len(Node* head) {
	int count = 0;
	Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

Node* bubblesort(Node* head) {
	for(int i=0;i<len(head);i++) {
		Node* current=head;
		Node* prev=NULL;
		while (current->next != NULL) {
			Node* front=current->next;
			if (current->data > front->data) {
				if (prev == NULL) {
					current->next = front->next;
					front->next = current;
					prev = front;
					head = prev;
				}
				else {
					prev->next = front;
					current->next = front->next;
					front->next = current;
					prev=front;
				}
				continue;
			}
			prev=current;
			current=current->next;
		}
	}
    return head;
}

Node* takeinput() {
	int data;
	cin >> data;
	Node* head = NULL;
	Node* tail = NULL;
	while (data != -1) {
		Node* x = new Node(data);
		if (head == NULL) {
			head = x;
			tail = x;
		}
		else {
			tail->next = x;
			tail = tail->next;
		}
		cin >> data;
	}
	return head;
}

int main() {
	Node* head = takeinput();
	print(head);
	Node* s = bubblesort(head);
	print(s);
}