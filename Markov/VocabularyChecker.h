// Student: Draghici Andrei Cosmin, Anul II, Informatica ID - Facultatea de matematica informatica, UNITBV

#pragma once

#include <iostream>
#include <string>

using namespace std;

class VocabularyChecker {
private:
   string vocabulary;

public:
    VocabularyChecker();
    ~VocabularyChecker();

    bool checkVocabulary(string vocabulary);
    void readVocabulary();
    void setVocabulary(string vocabulary);
    string getVocabulary();
};

VocabularyChecker::VocabularyChecker () {
    readVocabulary();
};

VocabularyChecker::~VocabularyChecker () {
};

bool VocabularyChecker::checkVocabulary (string vocabulary) {
    bool isVocabularyOk = true;
    for (int i = 0; i < vocabulary.length(); i++)
        for (int j = i + 1; j < vocabulary.length(); j++)
            if (vocabulary[i] == vocabulary[j])
                isVocabularyOk = false;
    return isVocabularyOk;
}

void VocabularyChecker::readVocabulary () {
    string tempVocabulary;
    cout << "Introduceti vocabularul: ";
    getline(cin, tempVocabulary);

    if (checkVocabulary(tempVocabulary)) {
        cout << "Vocabular acceptat!";
        setVocabulary(tempVocabulary);
    } else {
        cout << "Vocabularul nu este corect! Introduceti un nou vocabular!" << endl;
        readVocabulary();
    }
}

void VocabularyChecker::setVocabulary (string vocabulary) {
    this->vocabulary = vocabulary;
}

string VocabularyChecker::getVocabulary () {
    return this->vocabulary;
}

