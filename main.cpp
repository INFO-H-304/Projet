#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <map> //
#include <set> //

using namespace std;

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

//void query_init(const char * queryname, long symtype, long strands)



int main(int argc, char *argv[])
{
	//read a file into memory
	if (argc < 2) 
	{
		cout << "Il n'y a qu'un paramètre" << endl;
		return 1;
	}
	
	string basename = argv[1];
	
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
		
		char psq_ascii[28] = {'-','A','B','C','D','E','F','G','H','I','K','L','M','N',
			'P','Q','R','S','T','V','W','X','Y','Z','U','*','O','J'};
		 
		for (int i = 0; i < 3000 ; i++)
		{
			//printf("%x", buffer[i]);
			//cout << (int)buffer[i];
			//if (argv[1] == basename)
				//cout << psq_ascii[(int)buffer[i]]; //imprime db_sequences
			
		}


		if (idb)
			cout << "success" << endl;
		else 
			cout << "error : only" << idb.gcount() << " could be read";
		idb.close();
	
		delete[] buffer;
		
	}
		
	if (argc < 3) 
	{
		cout << "Il n'y a que deux paramètre" << endl;
		return 1;
	}
	 

	string query_name = argv[2];
	int query_length;
	string query_description;
	
	ifstream iquery(argv[2]);
	if (iquery)
	{
		string description;
		getline(iquery, description);
		description = description.substr(1); //on retire le >
		query_description = description; //QUERY_DESCRIPTION
		
		int beg_seq = iquery.tellg(); 
		char c;
		while (iquery >> noskipws >> c)
			query_length++;
			
		/*iquery.seekg(0,iquery.end);
		query_length = (int)iquery.tellg() - beg_seq; //QUERY LENGTH
		
		vector<char> query_sequence();
		char c;
		while (iquery >> c)
			query_sequence.push_back(c);
		query_length = sizeof(query_sequence);*/
		
		iquery.close();
	}
	
	cout << "Query file name: "<<query_name<<endl;
	cout << "Query length: "<<query_length<<" residues"<<endl;
	cout << "Query description: " <<query_description<<endl;
	
	
	
	return 0;
}
