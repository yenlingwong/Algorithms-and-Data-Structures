"""
CH-231-A
graph.py
Code for Graphing results
Yen Ling Wong
ywong@jacobs-university.de
"""
import matplotlib.pyplot as plt

with open("example1.txt", "r") as datas:
    xaxis = []
    yaxis1 = []
    lines = datas.readlines()
    for i in lines:
        line = i.split(" ")
        xaxis.append(int(line[0]))
        yaxis1.append(int(line[1]))
    
    

    
    plt.plot(xaxis,yaxis1)


    plt.show()