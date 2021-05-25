/*
 * LinkedList.h
 *
 *  Created on: Aug 27, 2020
 *      Author: alexjoslin
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Person.h"

class Node{
public:
	Node *next;
	Person data;

public:
	Node(Person);
	virtual ~Node();

};


class LinkedList {
private:
	int length;

public:
	Node* head;
	Node* tail;

	LinkedList();
	virtual ~LinkedList();
	void insert_end(Person d);
	void delete_front();
	void display();
	int size();
	void clear();
};


#endif /* LINKEDLIST_H_ */
