/*
 * StudentHouse.cpp
 *
 */

#include "StudentHouse.h"

//Constructors
StudentHouse::StudentHouse() {
	houseId = 0;
	schoolId = 0;
	numberOfStudents = 0;
}

StudentHouse::StudentHouse(unsigned houseId, unsigned schoolId, unsigned numberOfStudents) : houseId(houseId), schoolId(schoolId), numberOfStudents(numberOfStudents) {}


//Get methods
unsigned StudentHouse::getHouseId() const {
	return houseId;
}

unsigned StudentHouse::getSchoolId() const {
	return schoolId;
}

unsigned StudentHouse::getNumberOfStudents() const {
	return numberOfStudents;
}


//Set methods
void StudentHouse::setHouseId(unsigned id) {
	houseId = id;
}

void StudentHouse::setSchoolId(unsigned id) {
	schoolId = id;
}

void StudentHouse::setNumberOfStudents(unsigned number) {
	numberOfStudents = number;
}






