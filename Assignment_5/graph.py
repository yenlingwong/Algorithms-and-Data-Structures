"""
CH-231-A
graph.py
Graph Implementation Code
Yen Ling Wong
ywong@jacobs-university.de
"""

import matplotlib.pyplot as plt
import math

def plotGraph():
    with open("output.txt", "r") as fop:
        xaxis = []
        yaxis1 = []
        yaxis2 = []
        yaxis3 = []
        yaxis4 = []
        lines = fop.readlines()
        for i in range(len(lines)):
            line = lines[i].split("   ")
            print (line)
            xaxis.append(int(line[0]))
            if(line[2].count("e") > 0):
                yaxis1.append(float(line[2][:line[2].index("e")]) / math.pow(10,int(line[2][line[2].index("e") + 3 ])))
            else:
                print(line[2])
                yaxis1.append(float(line[2][: line[2].index(" ")]))
            if(line[3].count("e") > 0):
                yaxis2.append(float(line[3][:line[3].index("e") ]) / math.pow(10,int(line[3][line[3].index("e") + 3 ])))
            else:
                yaxis2.append(float(line[3][ : line[3].index(" ")]))
            if(line[4].count("e") > 0):
                yaxis3.append(float(line[4][:line[4].index("e") ]) / math.pow(10,int(line[4][line[4].index("e") + 3 ])))
            else:
                yaxis1.append(float(line[4] [: line[4].index(" ")]))
            if(line[6].count("e") > 0):
                yaxis4.append(float(line[6][:line[6].index("e") ]) / math.pow(10,int(line[6][line[6].index("e") + 3 ])))
            else:
                if(i == 7):
                    yaxis4.append(float(line[6]))
                else:
                    yaxis4.append(float(line[6][:line[6].index("\n")]))
            
        print(xaxis)
        print(yaxis1)
        print(yaxis2)
        print(yaxis3)
        print(yaxis4)
    plt.plot(xaxis,yaxis1,label = "NaiveRecursive")
    plt.plot(xaxis,yaxis2, label = "BottomUp")
    plt.plot(xaxis,yaxis3, label = "ClosedForm")
    plt.plot(xaxis,yaxis4,label = "MatrixRepresentation")
    plt.yscale("log")
    plt.grid(True)
    
    plt.legend()
    plt.show()

plotGraph()