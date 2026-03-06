**Q1. What is the time, space complexity of following code :**

```
    int a = 0, b = 0;
    for (i = 0; i < N; i++) {
        a = a + rand();
    }
    for (j = 0; j < M; j++) {
        b = b + rand();
    }
```

**Assume that rand() is O(1) time, O(1) space function.**
**Ans:**
_The first for loop is from the 0 till N => N elements traversed => Time Complexity: O(N)_
_No extra space is used for the loop => Space Complexity: O(1) or constant_
_Same for the second loop. Traversal from 0 till M => M elements traversed => Time Complexity: O(M)_
_No extra space is used here as well => Space Complexity: O(1) or constant_
**Overall Time Complexity: O(N+M)**
**Overall Space Complexity: O(1)**

**Q2. What is the time, space complexity of following code :**

```
int a = 0, b = 0;
for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
        a = a + j;
    }
}
for (k = 0; k < N; k++) {
    b = b + k;
}
```

**Ans:**
_The first loop is a nested loop. The outer loop is from 0 till N and the inner loop is from 0 till N. Hence,_
_Time Complexity: O(N^2)_
_Space Complexity: O(1) as no extra space has been used for the loop_
_The second loop traverses from 0 till N. Hence,_
_Time Complexity: O(N) and Space Complexity: O(1) since no extra space has been used_
**OVERALL TIME COMPLEXITY: O(N^2 + N) ~= O(N^2)**
**OVERALL SPACE COMPLEXITY: O(1)**

**Q3. What is the time complexity of the following code :**

```
    int a = 0;
    for (i = 0; i < N; i++) {
        for (j = N; j > i; j--) {
            a = a + i + j;
        }
    }
```

**Ans.:**
_To find the time complexity, we need to count exactly how many times the innermost statement (a = a + i + j;) executes._
Outer Loop: i goes from 0 up to $N - 1.
Inner Loop: j starts at N and decrements down to i + 1 (since the condition is j > i).
Let's trace the number of inner loop executions for each value of i:
When i = 0, j goes from N down to 1. -> N iterations
When i = 1, j goes from N down to 2. -> N - 1 iterations
When i = 2, j goes from N down to 3. -> N - 2 iterations...
When i = N - 1, j goes from N down to N. -> 1 iterationTo get the total number of operations, we add them all up:
Total = N + (N-1) + (N-2) + ... + 3 + 2 + 1
This is the sum of the first $ natural numbers (an arithmetic progression).
The formula for this sum is: Sum = N(N + 1)/2
If we expand that formula, we get: 1/2\*N^2 + 1/2N
In Big-O notation, we drop the constants (like 1/2) and only keep the dominant, fastest-growing term. Therefore, the time complexity is strictly O(N^2).
