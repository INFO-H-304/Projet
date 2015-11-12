#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <map> //
#include <set> //
#include <sys/stat.h> //to get the size of a file

using namespace std;
struct stat results; 

class db_info
{
public:
	string title;
	string basename;
	string time;
	
	long seqcount;
	long maxseq;
	long rcount;
	
	string taxid_filename;//
	ifstream taxid_file; //
	
	long offset_phr;//
	long offset_psq;//
	db_info();
	long getnames(); //
};

db_info::db_info()
{
	string title = "";
	string basename = "";
	string time = "";
	
	long seqcount = 0;
	long maxseq = 0;
	long rcount = 0;
}


int main(int argc, char *argv[])
{
	//read a file into memory
	if (argc < 2) 
	{
		cout << "Il n'y a qu'un paramètre" << endl;
		return 1;
	}
	

	ifstream idb(argv[1], ios::in | ios::binary); //mode binaire 
	
	if (idb) {
		//get length to have the whole file into the buffer
		idb.seekg(0,idb.end); //move to the end
		int length = idb.tellg(); //tellg() is the current position
		idb.seekg(0,idb.beg); //move to the beg
		
		char* buffer = new char[length]; 
		
		cout << "Reading " << length << " characters..." << endl;
		
		
		//read data as a block
		
		idb.read(buffer,length); 
		
		/* Now that we have the entire file buffered, 
		 * we can take a look at some binary information*/
		for (int i = 0; i < 3000 ; i++)
			cout << buffer[i] ;
		

		if (idb)
			cout << "success" << endl;
		else 
			cout << "error : only" << idb.gcount() << " could be read";
		idb.close();
	
		delete[] buffer;
		
	}
		
	
	return 0;
}
