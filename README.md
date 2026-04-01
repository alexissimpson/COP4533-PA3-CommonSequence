# COP4533-PA3-CommonSequence

## Question 2: Recurrence Equation

### Cases:
 - Base case: i or j = 0, OPT(i, j) = 0
 - Case 1: letters i and j match
   - Add the value of the common letter
 - Case 2a: OPT skips letter i
   - OPT(i-1, j)
 - Case 2b: OPT skips letter j
   - OPT(i, j-1)

### Equation:

#### OPT(i, j) = {
#### &emsp; 0 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp; if i or j = 0
#### &emsp; max{ v[i] + OPT(i-1, j-1), OPT(i-1, j), OPT(i, j-1) } &emsp; otherwise
#### }

 
