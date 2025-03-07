#include<iostream>
using namespace std;

class LinkedList {

private:
	struct Node{
		int value;
		Node* next;
		Node(int val): value(val), next(nullptr){}
	};

	Node* head;
	Node* tail;

public:

	LinkedList(): head(nullptr), tail(nullptr){}
	~LinkedList() {
		Node* curr=head;
		while(curr!=nullptr) {
			Node* next=curr->next;
			delete curr;
			curr=next;
		}
	}

	void insertBack(int val) {
		if(head==nullptr) {
			Node* newNode=new Node(val);
			head=tail=newNode;
			return;
		}

		Node* newNode=new Node(val);
		this->tail->next=newNode;
		tail=newNode;
		return;
	} 

	void deleteNode(int val) {
		if(head==nullptr) {
			cout<<"List is empty"<<'\n';
			return;
		}

		Node* curr=head;
		if(curr->value==val) {
			if(head==tail) {
				head=nullptr,tail=nullptr;
				delete curr;
				return;
			}
			head=head->next;
			delete curr;
			return;
		}

		while(curr->next!=nullptr&&curr->next->value!=val) {
			curr=curr->next;
		}

		if(curr->next==nullptr) {
			cout<<"List does not have such value"<<'\n';
			return;
		} else {
			Node* next=curr->next;	// next points out the node we should delete
			if(next==tail) tail=curr;
			curr->next=curr->next->next;
			delete next;
			return;
		}
	}

	void printItem() {
		if(head==nullptr) {
			cout<<"List is empty"<<'\n';
			return;
		} else {
			Node* curr=head;
			while(curr!=nullptr) {
				cout<<curr->value<<' ';
				curr=curr->next;
			}
		}
		return;
	}

};


int main() {

	LinkedList list;

	cout<<"List created: " <<'\n';


	return 0;
}