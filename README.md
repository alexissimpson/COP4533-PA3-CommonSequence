# COP4533-PA3-CommonSequence
## Contributors:
| Name           | UFID     |
|:--------------:|:--------:|
| Alexis Simpson | 11302807 |
| Kevin Rhoads   | 21495455 |

## Installation and Usage:
### 1. Clone the repository
```
git clone https://github.com/alexissimpson/COP4533-PA3-CommonSequence.git
```

### 2. Navigate to the project directory
```
cd COP4533-PA3-CommonSequence
```

### 3. Compile source files
```
g++ -std=c++17 src/*.cpp -o HVLCS
```

### 4. Run executable with test input file
#### Other input files will be places in /data/input
```
./HVLCS.exe test_input.txt
```

## Dependencies:
Must have the g++ GNU compiler

## Expected Input / Output:
Example input files are listed under /data/input. The input file will be specified in a command alongside the executable as shown in step 4 above.

Upon execution, the program will compute a common subsequence of A and B that maximizes the total value. It will output the maximum value and then the corresponding subsequence. The result will be written to the OUTPUT.txt file located at /data/output/OUTPUT.txt.

Example output for running test_input.txt is located at /data/output/test_output.txt

## Written Component:
### Question 1: Empirical Comparison
<img width="731" height="443" alt="image" src="https://github.com/user-attachments/assets/92397ff6-d3b7-44df-89ab-b86a02ff182e" />

The 10 test files used are stored in /data/input/ with the names listed.

### Question 2: Recurrence Equation

OPT(i,j) is defined as the maximum value produced by a common subsequence of strings a<sub>1</sub>a<sub>2</sub>...a<sub>i</sub> and b<sub>1</sub>b<sub>2</sub>...b<sub>j</sub>

#### Cases:
 - Base case: i or j = 0
   - Value is zero
 - Case 1: letters a<sub>i</sub> and b<sub>j</sub> match
   - Consider adding the value of the common letter
 - Case 2a: OPT skips letter a<sub>i</sub>
   - Move to OPT(i-1, j)
 - Case 2b: OPT skips letter b<sub>j</sub>
   - Move to OPT(i, j-1)

#### Recurrence Equation:

OPT(i, j) = {

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 0 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp; if i or j = 0

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; max{ OPT(i-1, j), OPT(i, j-1) } &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp; if letters a<sub>i</sub> and b<sub>j</sub> don't match

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; max{ v(a<sub>i</sub>) + OPT(i-1, j-1), OPT(i-1, j), OPT(i, j-1) } &emsp; otherwise


### Question 3: Big-Oh
#### Input Variables:
 - n = length of string A
 - m = length of string B
 - alphabet = map of characters to their values
#### Pseudocode:
Initialize memoization array M[][]\
for i = 0 to n:\
&emsp;M[i][0] = 0\
for j = 0 to m:\
&emsp;M[0][j] = 0\
\
for i = 1 to n:\
&emsp;for j = 1 to m:\
&emsp;&emsp;value = 0\
&emsp;&emsp;if a<sub>i</sub> == b<sub>j</sub>:\
&emsp;&emsp;&emsp;value = alphabet[a<sub>i</sub>]\
&emsp;&emsp;M[i][j] = max{ value + M[i-1][j-1], M[i-1][j], M[i][j-1] }\
\
length = 0\
while n>0 and m>0:\
&emsp;if a<sub>n-1</sub> == b<sub>m-1</sub>:\
&emsp;&emsp;length++\
&emsp;&emsp;n--\
&emsp;&emsp;m--\
&emsp;else if M[n-1][m] >= M[n][m-1]\
&emsp;&emsp;n--\
&emsp;else\
&emsp;&emsp;m--\
\
return length
 
#### Running Time:
 - O(nm) to find max value of HVLCS
 - O(nm) to find length of HVLCS
 - Overall: O(nm)
