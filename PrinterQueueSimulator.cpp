// Name        : PrinterQueueSimulator.cpp
// Author      : Alex Joslin
// Description : This is a printer queue simulator

#include <iostream>
#include <stdlib.h>
#include <thread>
#include "Queue.h"
#include "Person.h"
using namespace std;


Queue q = Queue();
bool start = true;
char input;

/*
 * Newly created jobs are placed in the printer queue.
 * Newly created jobs are created every half second.
 * Each job gets a unique ID
 */
void enqueue(){
	float pages;
	int id = 1;
	while(start){
		pages = (rand() % (21 - 1)) + 1;
		Person p  = Person(id, pages);
		p.request();
		q.push(p);
		id++;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

/*
 * Jobs that have completed their print time are
 * taken off the printer queue.
 */
void dequeue(){
	while(start){
		if(q.size()){
			Person p = q.peak();
			int sleep = (int) (p.printTime * 1000);
			this_thread::sleep_for(chrono::milliseconds(sleep));
			p.finished();
			q.pop();
		}
	}
}

/*
 * Allows the user to stop the simulation at any time.
 */
void stop(){
	cin >> input;
	if(input != 's'){
		start = false;
	}
}


int main() {
	srand(time(NULL));

	/* Introduction */
	cout << "This is program that simulates a printing queue using threads." << endl;
	cout << "One thread continuously adds jobs to the printing queue." << endl;
	cout << "Another thread removes jobs off the queue after their print time is up." << endl;
	cout << "To START press s: " << endl;
	cout << "To QUIT press q: " << endl;
	cin >> input;
	cout << endl;

	/* Begin Simulation */
	if(input == 's'){
		thread t1(enqueue);
		thread t2(dequeue);
		thread t3(stop);
		this_thread::sleep_for(chrono::milliseconds(500));

		t1.join();
		t2.join();
		t3.join();
		printf("\nSIMULATION TERMINATED");
	}

	return 0;
}
