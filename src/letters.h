#pragma once

#include <iostream>
using namespace std;

class Letter {
    private:
        string character;
        int value;
    public:
        Letter(string character, int value);
        string getCharacter();
        int getValue();
};