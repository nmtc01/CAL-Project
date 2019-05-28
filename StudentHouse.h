/*
 * StudentHouse.h
 *
 */

#pragma once

class StudentHouse {
	unsigned houseId;
	unsigned schoolId;
	unsigned numberOfStudents;

public:
	//Constructors
	StudentHouse();
	StudentHouse(unsigned houseId, unsigned schoolId, unsigned numberOfStudents);

	//Get Methods
	unsigned getHouseId() const;
	unsigned getSchoolId() const;
	unsigned getNumberOfStudents() const;

	//Set number of students
	void setHouseId(unsigned id);
	void setSchoolId(unsigned id);
	void setNumberOfStudents(unsigned number);
};
