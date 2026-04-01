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

    // post-processing
    string result = "";
    int n = A.length();
    int m = B.length();

    while(n > 0 && m > 0) {
        if(A[n-1] == B[m-1]) {
            // letter was taken
            result = A[n-1] + result;
            n--;
            m--;
        } else if(M[n-1][m] >= M[n][m-1]) {
            // letter in A was skipped
            n--;
        } else {
            // letter in B was skipped
            m--;
        }
    }

    // output max value of common subsequence and the common subsequence
    outfile << M[A.length()][B.length()] << endl;
    outfile << result << endl;
}