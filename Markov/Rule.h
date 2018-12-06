// Student: Draghici Andrei Cosmin, Anul II, Informatica ID - Facultatea de matematica informatica, UNITBV
#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class Rule {

private:
	char rightMember[10], leftMember[10];

public:
	Rule();
	Rule(char rightMember[], char leftMember[]);
	~Rule();

	// Setters
	void setLeftMember(char leftMember[]);
	void setRightMember(char rightMember[]);

	// Getters
	char * getRightMember();
	char * getLeftMember();

	friend std::ostream & operator << (ostream &os, Rule &r);
	friend std::istream & operator >> (istream &is, Rule &r);
};

Rule::Rule() {};

Rule::Rule(char rightMember[], char leftMember[]) {
	strcpy(this->rightMember, rightMember);
	strcpy(this->leftMember, leftMember);
}

Rule::~Rule() {
	delete[]this->rightMember;
	delete[]this->leftMember;
}

// Setters
void Rule::setRightMember(char rightMember[]) { strcpy(this->rightMember, rightMember); }
void Rule::setLeftMember(char leftMember[]) { strcpy(this->leftMember, leftMember); }

// Getters
char * Rule::getRightMember() { return this->rightMember; }
char * Rule::getLeftMember() { return this->leftMember; }

// Overload functions
std::ostream & operator << (ostream &os, Rule &r) {
	os << r.leftMember << " -> " << r.rightMember << endl;
	return os;
}


