#include "input_handler.h"
#include "hvlcs_algorithm.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

void handleInput(string filename){
    cout << "Handling Input From File: " << filename << endl;
    ofstream outfile("./data/output/OUTPUT.txt");
    ifstream infile("./data/input/" + filename);
    string line;

    // get first line k, the number of chars in the alphabet
    if(!getline(infile, line)){
        outfile << "File is empty! Terminating..." << endl;
        return;
    }
    int K = stoi(line);

    // get the values for each char in the alphabet
    map<char, int> alphabet;
    for(int i = 0; i < K; i++){
        if(!getline(infile, line)){
            outfile << "Error: Alphabet information not given." << endl;
            return;
        }
        stringstream ss(line);
        string letter;
        getline(ss, letter, ' ');
        string valueStr;
        getline(ss, valueStr, ' ');
        int value = stoi(valueStr);

        // add letters to alphabet map
        if(letter.length() != 1) {
            outfile << "Error: Alphabet letter not a valid char." << endl;
            return;
        }
        alphabet.insert({letter[0], value});
    }

    // get strings A and B
    if(!getline(infile, line)){
        outfile << "First string not given." << endl;
        return;
    }
    string A = line;

    if(!getline(infile, line)){
        outfile << "Second string not given." << endl;
        return;
    }
    string B = line;

    infile.close();

    computeHVLCS(A, B, alphabet, outfile);

    outfile.close();
}