
#ifndef QUEUE_H_
#define QUEUE_H_
#include "Person.h"
#include "LinkedList.h"

class Queue {
private:
	LinkedList *list;

public:
	Queue();
	void push(Person);
	void pop();
	Person peak();
	void display();
	void clear();
	int size();
	virtual ~Queue();
};

#endif /* QUEUE_H_ */
