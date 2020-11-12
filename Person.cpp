#include "Person.h"
#include <iostream>

Person::Person(int i, int p) {
	id = i;
	pages = p;
	printTime = calcPrintTime();
	waitTime += printTime;
}

Person::Person(){
	id = 0;
	pages = 0;
	printTime = 0;
	waitTime += printTime;
}

/* Calculates print time based on # of pages to print. */
float Person::calcPrintTime(){
	int rate = 10;
	float pageTime = (float) pages / rate;
	float randomness = (float) ((rand() % (50))) / (rate*10);
	return pageTime + randomness;
}

/* Display print requests */
void Person::request(){
	printf("ID: %d \t  Pages: %d  \tPrint Time: %.2fs\tWait Time: %.2fs\n", id, pages, printTime, waitTime);
}

/* Display when job id finished */
void Person::finished(){
	waitTime -= printTime;
	printf("ID: %d    FINISHED\n", id);
}

Person::~Person() {}

float Person::waitTime = 0;
