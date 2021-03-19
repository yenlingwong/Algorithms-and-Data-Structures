all: a6_p1 a6_p2 a6_p3 graph1 graph2 graph3

a6_p1: a6_p1.cpp
	g++ -o a6_p1 a6_p1.cpp

a6_p2: a6_p2.cpp
	g++ -o a6_p2 a6_p2.cpp

a6_p3: a6_p3.cpp
	g++ -o a6_p3 a6_p3.cpp

graph1: graph1.py
	python graph1.py

graph2: graph2.py
	python graph2.py

graph3: graph3.py
	python graph3.py