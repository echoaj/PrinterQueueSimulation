#include "LinkedList.h"
#include <iostream>


Node::Node(Person d){
	data = d;
	next = nullptr;
}

LinkedList::LinkedList() {
	length = 0;
	head = nullptr;
	tail = nullptr;
}

/* Insert item at the end of linked list
 * @param  per Person
 */
void LinkedList::insert_end(Person per){
	if(head == nullptr){
		head = new Node(per);
		tail = head;
	}else{
		tail->next = new Node(per);
		tail = tail->next;
	}
	length++;
}

/* Delete item at the front of linked list */
void LinkedList::delete_front(){
	if(head != nullptr){
		Node* temp = head;
		head = head->next;
		delete temp;
		length--;
	}

}

/* Display linked list */
void LinkedList::display(){
	Node* cur = head;
	while(cur != nullptr){
		std::cout << cur->data.id << " -> ";
		cur = cur->next;
	}
	std::cout << std::endl;
}

/* Clear linked list */
void LinkedList::clear(){
	Node* cur = head;
	while(head != nullptr){
		head = head->next;
		delete cur;
		cur = head;
	}
	length = 0;
}

int LinkedList::size(){
	return length;
}

Node::~Node(){}

LinkedList::~LinkedList() {}


