#include <iostream>
#include <fstream>
#include <string>
#include <map> //
#include <set> //
#include <sys/stat.h> //to get the size of a file

using namespace std;
struct stat results; 

int main(int argc, char *argv[])
{
	if (argc < 2) 
	{
		cout << "Il n'y a qu'un paramètre" << endl;
		return 1;
	}
	
	ifstream finput(argv[1]);
	if (finput.is_open())
	{
		cout << "Lecture en cours de la database" << endl;
		
		finput.close();
	}
	else
	{
		cout << "Impossible d'ouvrir la database"<< endl;
		return 1;
	} 
	
	return 0;
}
