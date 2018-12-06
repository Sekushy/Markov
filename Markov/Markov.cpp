// Markov.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Student: Draghici Andrei Cosmin, Anul II, Informatica ID - Facultatea de matematica informatica, UNITBV

#include "pch.h"
#include <iostream>
#include "Rule.h"
#include "VocabularyChecker.h"

using namespace std;

bool checkVocabulary(char vocabulary[]) {
	bool isValid = true;

	for (int i = 0; i < strlen(vocabulary) - 1; i++) {
		for (int j = i + 1; j < strlen(vocabulary); j++) {
			if (vocabulary[i] == vocabulary[j]) {
				isValid = false;
			}
		}
	}
	return isValid;
}

bool checkWord(char word[], char vocabulary[]) {
	bool isValid = true;

	for (int i = 0; i < strlen(word); i++) {
		if (strchr(vocabulary, word[i]) == NULL) {
			isValid = false;
		}
	}

	return isValid;
}

bool checkRule(char vocabulary[], char leftMember[], char rightMember[]) {
	bool isValid = true;

	for (int i = 0; i < strlen(leftMember); i++) {
		if (strchr(vocabulary, leftMember[i]) == NULL) {
			isValid = false;
		}
	}

	if (isValid) {
		for (int i = 0; i < strlen(rightMember); i++) {
			if (strchr(vocabulary, rightMember[i]) == NULL && rightMember[i] != '.' && rightMember[i] != 'L') {
				isValid = false;
			}
		}
	}

	return isValid;
}

int main()
{
	VocabularyChecker v1 = VocabularyChecker();
	cout << v1.getVocabulary();

}
