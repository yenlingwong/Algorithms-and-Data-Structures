"""
CH-231-A
a5_p1.py
Fibonacci Numbers Implementation Code
Yen Ling Wong
ywong@jacobs-university.de
"""
# Source: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
# Source: https://sahandsaba.com/five-ways-to-calculate-fibonacci-numbers-with-python-code.html

import math
import random
from timeit import default_timer as timer
import numpy as lib

#(1) Naive Recursion
def naive_recursive(n) :
    # Only positive numbers accepted
    if n < 0 :
        print("Enter a positive number!")
    elif n == 0 :
    # Base cases 1 and 0
        return 0
    elif n == 1 :
        return 1
    else :
    # Compute the sum of previous two numbers recursively
        return naive_recursive(n - 1) + naive_recursive(n - 2)

#(2) Bottom Up 

def bottom_up(n) :
    a = 0
    b = 1
    # Base Cases
    if n < 0 :
        print("Enter a positive number!")
    # Only positive numbers allowed
    elif n == 0 :
        return a
    elif n == 1 :
        return b
    else :
        for i in range(1, n) :
    # Loop through until reaching nth fibonacci number
            c = a + b
    # Sum first previous two fibonacci numbers
            a = b
            b = c
    # Shift up by 1
        return b
    # Retun current number

#(3) Closed Form

def closed_form(n) :
    sqrt5 = math.sqrt(5)
    phi = (sqrt5 + 1) / 2
    return int(phi ** n / sqrt5 + 0.5)

# Refer to attached pdf to view Binet's formula
# The answer is type casted to int because of rounding errors
# In fact, the rounding error is very small, being less than 0.1 for n ≥ 4, and less than 0.01 for n ≥ 8.

#(4) Matrix Multiplication

def matrix_multiplication(n) :
    F = [[1, 1], [1, 0]]
    if (n == 0) :
        return 0
    power(F, n - 1)
    # Recursive call to multiply by another [[1, 1], [1, 0]] until n becomes 0
    # This is done via the power function 
     
    return F[0][0]
    # [0][0] refers to the first element of the row and first element of the column
    # The number F[n+1] is stored at that position in the matrix according to the formula
 
def multiply(F, M):
 
    x = (F[0][0] * M[0][0] +
         F[0][1] * M[1][0])
    y = (F[0][0] * M[0][1] +
         F[0][1] * M[1][1])
    z = (F[1][0] * M[0][0] +
         F[1][1] * M[1][0])
    w = (F[1][0] * M[0][1] +
         F[1][1] * M[1][1])
    
    # Computing the elements of each index using standard matrix multiplication
     
    F[0][0] = x
    # First row first column
    F[0][1] = y
    # First row second column
    F[1][0] = z
    # Second row first column
    F[1][1] = w
    # Second row second column
 
def power(F, n):
 
    M = [[1, 1], [1, 0]]
 
    # Refer to pdf for the multiplication formula
    
    for i in range(1, n) :
        multiply(F, M)
    # Multiply m by n times

def testCases():
    with open("output.txt", "w") as file:
        endtime = False
        for i in range(0,40,4):

            file.write(str(i) + "   ")
            begin = timer()
            x= naive_recursive(i)
            file.write(str(x) + "   ")
            end = timer()
            if(end - begin >30):
                endtime  = True
            file.write(str(end - begin) + "  ")

            begin = timer()
            x= bottom_up(i)
            file.write(str(x) + "   ")
            end = timer()
            if(end- begin >25):
                endtime = True
            file.write(str(end - begin) + "  ")

            begin = timer()
            x= closed_form(i)
            file.write(str(x) + "   ")
            end = timer()
            if(end- begin >25):
                endtime = True
            file.write(str(end - begin) + "   ")

            begin = timer()
            x= matrix_multiplication(i)
            file.write(str(x) + "   ")
            end = timer()
            if(end- begin >25):
                endtime = True
            file.write(str(end - begin))

            
            
            if(endtime == True):
                break
            else:
                file.write("\n")

testCases()