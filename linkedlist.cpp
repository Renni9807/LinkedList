#include<iostream>
using namespace std;

class LinkedList{

private:
	struct Node {
		int value;
		Node* next;
		Node(int val):value(val),next(nullptr){}
	};

	Node* head;
	Node* tail;

public:

	LinkedList():head(nullptr),tail(nullptr){}
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

	int getTailValue() {
		if(head==nullptr)return -1;
		else return tail->value;
	}
	int getHeadValue() {
		if(head==nullptr) return -1;
		else return head->value;
	}

	int listSize() {
		if(head==nullptr) return 0;
		Node* curr=head;
		int count=0;

		while(curr!=nullptr) {
			curr=curr->next;
			count++;
		}
		return count;
	}

	bool searchItem(int val) {
		if(head==nullptr) return false;

		Node* curr=head;

		while(curr!=nullptr) {
			if(curr->value==val) {
				return true;
			}
			curr=curr->next;
		}
		return false;
	}

	void reverseList() {

		Node* prev=nullptr;
		Node* curr=head;
		tail=head;
		while(curr!=nullptr) {
			Node* next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		head=prev;
	}

	static LinkedList* mergeTwoLists(LinkedList* list1, LinkedList* list2) {
		Node* curr1=list1->head;
		Node* curr2=list2->head;

		LinkedList* res=new LinkedList();
		if(curr1==nullptr&&curr2==nullptr) return res;

		while(curr1!=nullptr&&curr2!=nullptr) {
			if(curr1->value>curr2->value) {
				res->insertBack(curr2->value);
				curr2=curr2->next;
			} else {
				res->insertBack(curr1->value);
				curr1=curr1->next;
			}
 		}
			while(curr1!=nullptr) {
				res->insertBack(curr1->value);
				curr1=curr1->next;
			}
			while(curr2!=nullptr) {
				res->insertBack(curr2->value);
				curr2=curr2->next;
			}
 		return res;
	}

	static LinkedList* addTwoNumbers(LinkedList* list1, LinkedList* list2) {


		LinkedList* dummy=new LinkedList();
		int carry=0;
		Node* curr1=list1->head;
		Node* curr2=list2->head;

		while(curr1!=nullptr || curr2!=nullptr || carry!=0) {
			int sum=carry;
			if(curr1) {
				sum+=curr1->value;
				curr1=curr1->next;
			}

			if(curr2) {
				sum+=curr2->value;
				curr2=curr2->next;
			}

			int digit=sum%10;
			Node* newNode=new Node(digit);
			
			if(dummy->head==nullptr) {
				dummy->head=newNode;
				dummy->tail=newNode;
			} else {
				dummy->tail->next=newNode;
				dummy->tail=dummy->tail->next;
			}
			carry=sum/10;
		}

		return dummy;
	}


};

int main() {

	LinkedList* list=new LinkedList();

	list->getHeadValue();
	list->getTailValue();
	list->printItem();
	list->deleteNode(3);
	
	cout<<"\n\n\n";

	list->insertBack(1);
	cout<<list->getTailValue()<<' ';
	list->insertBack(3);
	cout<<list->getTailValue()<<' ';
	list->insertBack(5);
	cout<<list->getTailValue()<<' ';
	list->insertBack(7);
	cout<<list->getTailValue()<<' ';
	list->insertBack(9);
	cout<<list->getTailValue()<<' '; 
	list->insertBack(11);
	cout<<list->getTailValue()<<' ';
	list->insertBack(13);
	cout<<list->getTailValue()<<' ';

	cout<<"\n\n\n";

	cout<<"All nodes in linkelist: ";
	list->printItem();
	cout<<"head: "<<list->getHeadValue()<<'\n';
	cout<<"tail: "<<list->getTailValue()<<'\n';

	cout<<"\n\n";

	cout<<"After delete some node: ";
	list->deleteNode(1), list->deleteNode(13), list->deleteNode(7);
	list->printItem();
	cout<<"head: "<<list->getHeadValue()<<'\n';
	cout<<"tail: "<<list->getTailValue()<<'\n';

	cout<<"Size of the linkedlist: "<<list->listSize()<<'\n';
	cout<<"Search value 4: "<<list->searchItem(4)<<'\n';
	cout<<"Search value 5: "<<list->searchItem(5)<<'\n';
	cout<<"Reverse list'\n";
	cout<<"Original list: ";
	list->printItem();
	cout<<"Reversed list: ";
	list->reverseList();
	list->printItem();

	cout<<"\n\n\n";
	cout<<"Merge two lists"<<'\n';

	LinkedList* list1=new LinkedList();
	LinkedList* list2=new LinkedList();

	list1->insertBack(1);
	cout<<list1->getTailValue()<<' ';
	list1->insertBack(3);
	cout<<list1->getTailValue()<<' ';
	list1->insertBack(5);
	cout<<list1->getTailValue()<<' ';
	list1->insertBack(7);
	cout<<list1->getTailValue()<<' ';
	list1->insertBack(9);
	cout<<list1->getTailValue()<<' ';
	list1->insertBack(11);
	cout<<list1->getTailValue()<<' ';
	list1->insertBack(13);
	cout<<list1->getTailValue()<<' ';

	cout<<'\n';

	list2->insertBack(2);
	cout<<list2->getTailValue()<<' ';
	list2->insertBack(4);
	cout<<list2->getTailValue()<<' ';	
	list2->insertBack(6);
	cout<<list2->getTailValue()<<' ';
	list2->insertBack(8);
	cout<<list2->getTailValue()<<' ';
	list2->insertBack(9);
	cout<<list2->getTailValue()<<' ';
	list2->insertBack(12);
	cout<<list2->getTailValue()<<' ';
	list2->insertBack(13);
	cout<<list2->getTailValue()<<' ';

	cout<<'\n';
	cout<<"List1: ";
	list1->printItem();
	cout<<'\n';
	cout<<"List2: ";
	list2->printItem();
	cout<<'\n';

	cout<<"After merge: ";
	LinkedList* list3=LinkedList::mergeTwoLists(list1, list2);

	list3->printItem();
	cout<<"\n\n\n";

	LinkedList list4;
	list4.insertBack(5);
	cout<<"head value: "<< list4.getHeadValue()<<' '<<" tail value: " <<list4.getTailValue()<<'\n';
	list4.deleteNode(5);
	cout<<"head value: "<< list4.getHeadValue()<<' '<<" tail value: " <<list4.getTailValue()<<'\n';

	cout<<"\n\n\n";

	LinkedList* list5=new LinkedList();
	LinkedList* list6=new LinkedList();

	list5->insertBack(1),list5->insertBack(3),list5->insertBack(5),list5->insertBack(7),list5->insertBack(9);
	list6->insertBack(9),list6->insertBack(8),list6->insertBack(7),list6->insertBack(6),list6->insertBack(5),

	cout<<"Add two lists"<<'\n';
	cout<<"list5: ";
	list5->printItem();
	cout<<'\n';
	cout<<"list6: ";
	list6->printItem();
	cout<<'\n';

	cout<<"After add two lists: ";
	LinkedList* list7=LinkedList::addTwoNumbers(list5, list6);
	list7->printItem();
	cout<<"\n\n\n";

	delete list;
	delete list1;
	delete list2;
	delete list3;
	delete list5;
	delete list6;
	delete list7;
	return 0;
}

