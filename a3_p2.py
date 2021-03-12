"""
CH-231-A
a3_p2.py
Selection Sort Implementation Code
Yen Ling Wong
ywong@jacobs-university.de
"""

import random
import time

# Random Number Generator
def randnum(lim):
    arr = []
    for i in range(lim):
        arr.append(random.randrange(lim))
    return arr

# Implementing Selection Sort Algorithm
def selection_sort(array) :
    start = time.time()
    array_length = range(0, len(array)-1)

    for i in array_length:
        min_value = i

        for j in range(i+1, len(array)) :
            if array[j] < array[min_value] :
                min_value = j

        if min_value != i:
            array[min_value], array[i] = array[i], array[min_value]
    
    end = time.time()
    return end - start

#function for geting avg,best,worst case
def Cases(arr):
    result = [0,0,0]
    result[0] = selection_sort(arr)
    arr.sort()
    result[1] = selection_sort(arr)
    arr.insert(0,arr.pop())
    result[2]  = selection_sort(arr)
    return result

#Generating cases and calculating avg,best,worst cases
def testCases():
    with open("sortednum.txt","w") as nums:
        for x in range(1000,7001,1000):
            arr1 = randnum(x)
            arr2 = randnum(x)
            arr3 = randnum(x)
            arr4 = randnum(x)
            list1 = Cases(arr1)
            list2 = Cases(arr2)
            list3 = Cases(arr3)
            list4 = Cases(arr4)
            averageCase = (list1[0] + list2[0] + list3[0] + list4[0])/4
            bestCase = (list1[1] + list2[1] + list3[1] + list4[1])/4
            worstCase = (list1[2] + list2[2] + list3[2] + list4[2])/4
            nums.write(str(x) + " " + str(averageCase) + " " + str(bestCase)+ " " + str(worstCase))
            if(x != 7000):
                nums.write("\n")

#execution
testCases()