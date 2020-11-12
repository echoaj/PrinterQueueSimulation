/*
 * Queue.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: alexjoslin
 */

#include "Queue.h"

Queue::Queue() {
	list = new LinkedList();
}

void Queue::push(Person d){
	list->insert_end(d);
}

void Queue::pop(){
	list->delete_front();
}

Person Queue::peak(){
	return list->head->data;
}

void Queue::display(){
	list->display();
}

void Queue::clear(){
	list->clear();
}

int Queue::size(){
	return list->size();
}

Queue::~Queue() {}

