# Algorithms-Course-problem-solving

## Problem #1 String Generation

Given M strings you are required to find the count of all strings of length N that contain at least K strings from the M strings as substrings. You are required to answer the question above using brute force implemented using recursion.

**Input Format**

The first line will contain M, N, and K in this exact order.
The next M lines will contain a string each

**Constraints**

1 <= M <= 7

1 <= N <= 7

1 <= K <= M

1 <= Length of the M strings <= N

All strings will contain capital letters between A and E inclusive.
Output Format

The number of strings satisfying the condition.

**Sample Input 0**

2 3 1

AE

AD

**Sample Output 0**

20

**Explanation 0**

The strings satisfying the condition are: AAD, AAE, ADA, ADB, ADC, ADD, ADE, AEA, AEB, AEC, AED, AEE, BAD, BAE, CAD, CAE, DAD, DAE, EAD, EAE

**Sample Input 1**

2 3 2

AD

AEC

**Sample Output 1**

0

## Problem #2 Robots

In multi-robot task allocation, there are a set of tasks and a set of robots, and the target is to assign robots to tasks. However, there are some constraints that complicate the allocation process. The ordering constraints, for example, specify which tasks must be performed before some other tasks. If task T1 precedes task T2, this means that T1 must be performed first before performing T2.

Assume that we have **N** tasks, and each task Ti has **two** preceding tasks (the two tasks must be executed before Ti). You are required to print all tasks in the order of execution (the one that executed first is printed first). For some tasks, we may not know all the tasks that precede it. There are multiple solutions for that problem. To get a similar solution to HackerRank, when implementing your algorithm iterate on task 0 first.

**Use an adjacency list to represent the graph.**

**Input Format**

The first line contains the integer N.

For the next N lines,

Each line represents the preceding tasks of one task starting from task with index 0 (the first line) to task with index N-1 (the last line)

Each line contains two numbers representing the indices of the two preceding tasks of the current task.

If any preceding task is unknown a -1 is present.

**Constraints**

1 <= N <= 10^6

**Output Format**

One line containing the indices of all tasks in the order of execution.

**Sample Input 0**

9

-1 -1

0 -1

1 3

0 6

-1 -1

-1 -1

-1 5

-1 -1

7 6

**Sample Output 0**

7 5 6 8 4 0 3 1 2

## Problem #3 Obstacles Game

In a 2D game grid, the start cell is the top left corner, and the end cell is the bottom right corner. The grid has obstacles that the player cannot move on. The player is required to move from the start cell to the end cell while avoiding the obstacles such that the two allowed moving direction is either right or down. Grid cells with value -1 mean obstacles, and 0 mean normal cells. It is required to use **dynamic programming** to count the number of ways the player can move from the start cell to the end cell while avoiding the obstacles.

**Input Format**

The first line contains the number of rows R and the number of columns C

For R Lines:

Number of C values are entered in each line representing the values of that row (0 for empty cells, -1 for obstacle cells)

**Constraints**

1 <= R <= 10^3

1 <= C <= 10^3

The start cell and the end cell will be contain obstacles

**Output Format**

one value containing the number of ways the player can move from the start cell to the end cell while avoiding the obstacles.

**Sample Input 0**

4 4

0 0 0 0 

0 -1 0 0 

-1 0 0 0 

0 0 0 0

**Sample Output 0**

4

## Contributors

[Donia Gameel](https://github.com/DoniaGameel).
