# ALGHORYTM ANALYSIS COLLEGE SUBJECT

This repo contain 5 college projets and my solutions to them.

## General information
All problems provided here are solved using plain C language. Each file contains a main function and needs to be compiled separately. 
Furthermore, all programs are designed to accept inputs from the keyboard.
It is worth noting that every program has successfully passed all of the tests within the allotted time.

## Problem list:

### Partitions
```
A partition of n is a representation of this number as a sum of positive integers: n=n1+n2+...+nr such that n1≥n2≥...≥nr. 
The numbers n1,n2,...,nr are called parts.

The partition 19=5+3+3+2+2+2+2 can be written as 53224, while 19=5+2+2+2+2+2+2+2 can be written as 527.
Hence the upper indices are 124 and 107, thus 5+3+3+2+2+2+2 is larger than 5+2+2+2+2+2+2+2, 
since 124 is larger than 107.
Starting from the smallest partition, write all partitions of the integer n, which parts are prime numbers and the largest part is equal to k. 
n can be stored in byte.

Input

In the first line: a number of the rest lines
Then, separated by spaces: n and k

Output

Partitions separated by +. If there is no partition, then write nothing.

Example

Input
3
12 5
5 2
27 17

Output:
5+3+2+2
5+5+2
17+2+2+2+2+2
17+3+3+2+2
17+5+3+2
17+5+5
17+7+3
```
### Hypercube
```
Time limit: 0.01-5s
Memory limit: 256MB

Calculate the number of vertex pairs in the hypercube Qn, such that the distance between them is exactly d (d>0, n>0). 
The figure shows small hypercubes Qn for n=0,1,2,3,4:

Input:
The first line contains the number of subsequent lines. In the following lines, there are numbers n and d separated by spaces.

Output:
The number of vertex pairs in the hypercube Qn that are at a distance of d.

Example:
Input:
5
1 1
2 1
2 3
3 3
4 2

Output:
1404
48
```

### Bananas
```
Time limit: 0.1-5s
Memory limit: 256MB

You are a monkey and you are hungry. Due to hunger, you can no longer recognize trees. 
The only thing that can save you from starvation is a good banana algorithm. 
Write a program that can identify a banana tree among the trees. If the tree is a banana tree, 
the program should display the number of bananas, defined as the number of leaves in the tree, i.e., 
the number of vertices with a degree of 1. Otherwise, it should display 0. 
A banana tree Bn,k is defined as n stars with k vertices each (n>0, k>0), where the vertices with 
the highest degree are connected to an additional vertex r (see the figure below, which depicts a banana tree B3,4).

Input:
The first line contains the number of subsequent lines. In the following lines, there are the number of 
vertices in the graph, followed by the adjacency matrix of the input tree (written from left to right, top to bottom without spaces).

Output:
In the subsequent lines, there are the number of bananas in the banana tree, or 0 if the tree is not a banana tree.

Example:
Input:
3
5 0010000110110000100100010
6 010010100000000111001000101000001000
7 0100000100001100011100010000001000001100000100000
Output:
2 bananas :)
0 bananas :(
4 bananas :)
```

### Coloring
```
Vertex coloring of a graph is considered legal if any two connected vertices have different colors.
The minimum number of colors (which can include various shades of pink) required for a (legally) colored graph 
is called the chromatic number of that graph. The degree of a vertex is the number of edges that are connected to it.

Check whether the chromatic number of a graph is greater than its maximum degree. You can use any algorithm, 
including your own, for coloring.

Input:
The first line contains the number of subsequent lines. In the following lines, there are the number of vertices in the graph, 
followed by the adjacency matrix of graph G (written from left to right, top to bottom without spaces).

Output:
True if the chromatic number of the graph is greater than its maximum degree. False otherwise.

Example:
Input:
17
5 0111110111110111110111110
5 0110010000100110010000100
7 0110111101000111011110010100101101010101011110010
6 010001101000010100001010000101100010
4 0111101011001000
6 011111101010110101101011110101101110
7 0111111101111111011111110111111101111111011111110
6 010010101100010000010000100001000010
7 0110111101111111011110110111111101111111011111110
3 011101110
2 0110
4 0111101011001000
4 0111101111011110
4 0101101001011010
2 0110
6 010001101000010100001010000101100010
3 011101110

Output:
True
False
False
False
False
False
True
False
False
True
True
False
True
False
True
False
True
```

## Compiler information
 * gcc (Rev10, Built by MSYS2 project) 11.2.0
 * Copyright (C) 2021 Free Software Foundation, Inc.


## Creator information
 * Miłosz Skobejko - Gdańsk University of Technology - 15.05.2022
