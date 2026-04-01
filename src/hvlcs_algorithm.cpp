#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void computeHVLCS(string A, string B, map<char, int> alphabet, ofstream& outfile){
    // initialize 2d vector M
    vector<vector<int>> M(A.length()+1, vector<int> (B.length()+1, 0));

    // base case: i=0 or j=0
    for(int i = 0; i < A.length(); i++){
        M[i][0] = 0;
    }
    for(int j = 0; j < B.length(); j++){
        M[0][j] = 0;
    }

    // recursive case
    for(int i = 1; i < A.length()+1; i++){
        for(int j = 1; j < B.length()+1; j++){
            int value_i = A[i-1] == B[j-1] ? alphabet[A[i-1]] : 0;
            M[i][j] = max({value_i + M[i-1][j-1], M[i-1][j], M[i][j-1]});
        }
    }

    // print max value of common subsequence
    outfile << M[A.length()][B.length()] << endl;
}