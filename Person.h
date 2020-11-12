/*
 * Person.h
 *
 *  Created on: Nov 9, 2020
 *      Author: alexjoslin
 */

#ifndef PERSON_H_
#define PERSON_H_

class Person {
private:
	float calcPrintTime();

public:
	int id;
	int pages;
	float printTime;
	static float waitTime;

	Person(int, int);
	Person();
	void request();
	void finished();
	virtual ~Person();
};

#endif /* PERSON_H_ */
