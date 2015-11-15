all: database.o query.o
	g++ query.o database.o main.cpp -o main

database.o: database.cpp
	g++ -c database.cpp 

query.o: query.cpp
	g++ -c query.cpp 

clean: 
	rm*.o
	
