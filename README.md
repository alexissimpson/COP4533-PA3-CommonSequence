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

#### Cases:
 - Base case: i or j = 0, OPT(i, j) = 0
 - Case 1: letters i and j match
   - Add the value of the common letter
 - Case 2a: OPT skips letter i
   - OPT(i-1, j)
 - Case 2b: OPT skips letter j
   - OPT(i, j-1)

#### Equation:

OPT(i, j) = {
&emsp; 0 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp; if i or j = 0

&emsp; max{ v[i] + OPT(i-1, j-1), OPT(i-1, j), OPT(i, j-1) } &emsp; otherwise
}

### Question 3: Big-Oh

 
