#include "letters.h"

Letter::Letter(string character, int value){
    this->character = character;
    this->value = value;
}

string Letter::getCharacter(){
    return character;
}

int Letter::getValue(){
    return value;
}