tasked: main.cpp
	g++ -std=c++20 main.cpp -o tasked
	rm -rf list.txt
	./tasked add something
	./tasked add something else
