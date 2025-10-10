= Hash Function Analysis: Cormen's Multiplication Method vs Most Significant Bits Method

By Joel and Nana.

From our experimental testing, we've determined that Cormen's Multiplication
Method is a more ideal hash function. The theoretically perfect hash function
is independent and uniform. Independent means that one input can't influence a
future input. For MSBM and Cormen's method, they both easily fit being
independent as they take in an input and give an output irrespective of any
state; in other words, both methods are just simple pure functions. Uniformity
of each is a different story. The experimental result of each follows. Note,
the `./README.md` contains instructions on how to choose which hash function
gets compiled so these results are reproducible.

#figure(
  align(left,
raw("===================
Starting Time Tests
For Most Significant Bits Method
===================
Randomized Hashtable insert with 2 elements of size 1 took 313 nanoseconds
The highest load is 1 times the ideal load

Randomized Hashtable insert with 20 elements of size 10 took 3089 nanoseconds
The highest load is 10 times the ideal load

Randomized Hashtable insert with 200 elements of size 100 took 105 nanoseconds
The highest load is 14.5 times the ideal load

Randomized Hashtable insert with 2000 elements of size 1000 took 127 nanoseconds
The highest load is 22 times the ideal load

Randomized Hashtable insert with 20000 elements of size 10000 took 140 nanoseconds
The highest load is 28 times the ideal load"),
),
  caption: [Time Test results for MSBM]
) <MSBM_results>


#figure(
  align(left,
raw("===================
Starting Time Tests
For Cormen's Method
===================
Randomized Hashtable insert with 2 elements of size 1 took 182 nanoseconds
The highest load is 1 times the ideal load

Randomized Hashtable insert with 20 elements of size 10 took 2695 nanoseconds
The highest load is 1.5 times the ideal load

Randomized Hashtable insert with 200 elements of size 100 took 138 nanoseconds
The highest load is 3 times the ideal load

Randomized Hashtable insert with 2000 elements of size 1000 took 106 nanoseconds
The highest load is 3 times the ideal load

Randomized Hashtable insert with 20000 elements of size 10000 took 118 nanoseconds
The highest load is 4 times the ideal load"),
),
  caption: [Time Test results for Cormen's Multiplication Method]
) <cormen_results>

@MSBM_results and @cormen_results don't show much of a difference in runtime
but show a big difference in the highest load. For clarity, the highest load is
the list in the member array of the hashtable that has the longest size. And
the ideal load is $n / m$ where $n$ is the number of elements in the hashtable
and $m$ is the size of hashtable. For the biggest testcase, Cormen's method
only results in a highest load of only 4 times the ideal load while MSBM is
_28_ times the ideal load. Cormen seems obviously superior to the
multiplication method.

While we've determined Cormen is the superior hash function its useful to
remember that this was for keys that were randomly generated integers. The
multiplication method may have been biased towards certain values of
significant bits as a result. Nonetheless, this experimental data provides
strong support for Cormen as the better hash function.
