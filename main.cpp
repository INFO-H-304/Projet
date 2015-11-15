#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <string.h> 
//#include <bitset>
//#include <byteswap.h>
//#include <endian.h>

#include "query.h"
#include "database.h"
#include <time.h>


int main(int argc, char *argv[])
{
	const clock_t begin_time = clock();
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
/////////////////////////////////////////////////////////
//DATABASE
	if (argc < 2) 
	{
		cout << "Il n'y a qu'un paramètre" << endl;
		return 1;
	}
	
	Database db;
	db.setName(argv[1]); 
//FILES
	char files_to_read[strlen(argv[1]) + 4], db_pin[strlen(argv[1]) + 4], db_phr[strlen(argv[1]) + 4], db_psq[strlen(argv[1]) + 4];
	
	for (int j = 0; j < strlen(argv[1]); j++)
		files_to_read[j] = argv[1][j]; //uniprot_sprot.fasta
	files_to_read[strlen(argv[1])] = '.';
	files_to_read[strlen(argv[1]) + 1] = 'p';
	
	strncpy(db_pin, files_to_read, strlen(argv[1]) + 4);
	strncpy(db_phr, files_to_read, strlen(argv[1]) + 4);
	strncpy(db_psq, files_to_read, strlen(argv[1]) + 4);
	
	db_phr[strlen(argv[1]) + 2] = 'h';
	db_phr[strlen(argv[1]) + 3] = 'r';
	db_psq[strlen(argv[1]) + 2] = 's';
	db_psq[strlen(argv[1]) + 3] = 'q';
	db_pin[strlen(argv[1]) + 2] = 'i';
	db_pin[strlen(argv[1]) + 3] = 'n';
	
	ifstream idb_pin(db_pin, ios::in | ios::binary); //lecture en binaire 
	if (idb_pin) 
	{ 
		idb_pin.seekg(0,idb_pin.end); //move to the end
		int length = idb_pin.tellg(); //tellg() is the current position
		idb_pin.seekg(0,idb_pin.beg); //move to the beg
		char* buffer = new char[length]; 
		cout << "Reading " << length << " characters..." << endl;
		
		idb_pin.read(buffer,length); //read the file into memory
		for (int i = 35; i < 54; i++)
			cout << buffer[i];
			
		idb_pin.close();
	
		delete[] buffer;	
	}
	
//	
	vector< vector<char> > seq; 
	vector<char> new_seq; //local
	seq.push_back(new_seq);
	int compteur_seq = 0;
	int compteur_res = 0; //local
	char psq_ascii[28] = {'-','A','B','C','D','E','F','G','H','I','K','L','M','N',
			'P','Q','R','S','T','V','W','X','Y','Z','U','*','O','J'};
	ifstream idb_psq(db_psq, ios::in | ios::binary); //lecture en binaire 
	if (idb_psq) 
	{ //get length to have the whole file into the buffer					
		idb_psq.seekg(0,idb_psq.end); //move to the end
		int length = idb_psq.tellg(); //tellg() is the current position
		idb_psq.seekg(0,idb_psq.beg); //move to the beg
		char* buffer = new char[length]; 
		cout << "Reading " << length << " characters..." << endl;
		
		idb_psq.read(buffer,length); //read the file into memory
		for (int i = 0; i < length; i++)
		{
			if (psq_ascii[(int)buffer[i]] != '-')
			{
				seq[compteur_seq].push_back(psq_ascii[(int)buffer[i]]);
				compteur_res++;
				db.icrResTot();
			}
			else
			{
				compteur_seq++;
				seq.push_back(new_seq);
				if (compteur_res > db.getResMax())
					db.setResMax(compteur_res);
				compteur_res = 0;
			}
		}
		idb_psq.close();
	
		delete[] buffer;	
	}


	map<vector<char>, vector<char> > map_seq;
	
	ifstream idb_phr(db_phr, ios::in | ios::binary); //lecture en binaire 
	if (idb_phr) 
	{ //get length to have the whole file into the buffer					
		idb_phr.seekg(0,idb_phr.end); //move to the end
		int length = idb_phr.tellg(); //tellg() is the current position
		idb_phr.seekg(0,idb_phr.beg); //move to the beg
		char* buffer = new char[length]; 
		cout << "Reading " << length << " characters..." << endl;
		
		idb_phr.read(buffer,length); //read the file into memory
								//now that we have the entire file buffered, we can take a look at some binary information*/
		
		bool getheader = true; //local
		vector<char> current_header; //local
		
		for (int i = 8; i < length; i++)
		{
			if (buffer[i] == 's' && buffer[i+1] == 'p' && buffer[i+2] == '|')
			{ //nouveau header de séquence
				getheader = true;
				db.icrNSeq();
				if (db.getNSeq() != 1)
					map_seq[current_header] = seq[db.getNSeq()];
				current_header.clear();
			}
			if (buffer[i]>=32 && buffer[i]<=126 && getheader == true)
				current_header.push_back(buffer[i]);
			else //on rejete les caractères non-ASCII
				getheader = false;			
		}

		idb_phr.close();
	
		delete[] buffer;	
	}
	
/////////////////////////////////////////////////////////
//QUERY

	if (argc < 3) 
	{
		cout << "Il n'y a que deux paramètres" << endl;
		return 1;
	}

	Query query;
	query.setName(argv[2]);
	ifstream iquery(argv[2]);
	if (iquery)
	{
		string first_line;
		getline(iquery, first_line);
		query.setDesc(first_line.substr(1)); //on retire le >
		
		for (char c; iquery >> c;)
			query.addResidue(c);
		query.setLength(query.getSequence().size());

		iquery.close();
	}
	
/////////////////////////////////////////////////////////
//COUT
	cout << endl;
	/*int id = 0;
	for(map<vector<char>, vector<char> >::iterator it=map_seq.begin(); it!=map_seq.end(); ++it)
    { //CECI PRINT HEADERS+SEQUENCES
		cout << endl << endl << "gnl|BL_ORD_ID|" << id << " ";
		for (int i = 0; i < it->first.size(); i++)
			cout << (it->first)[i]; //chaque 
		cout << endl;
        for (int i = 0; i < it->second.size(); i++)
			cout << (it->second[i]); //chaque char du header
		id++;
    }*/
    
	cout << "Database file: " << db.getName() << endl;
	cout << "Database size: " << db.getResTot() << " residues in " <<db.getNSeq() << " sequences" << endl;
	cout << "Longest db seq: " << db.getResMax() << " residues" << endl;
	cout << "Query file name: " << query.getName() << endl;
	cout << "Query length: " << query.getLength() << " residues" << endl;
	cout << "Query description: " << query.getDesc() << endl;
	
    cout << "Search started: " << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday << ", "<<  now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec<< endl;
	time_t tbis = time(0);
	struct tm * after = localtime( & tbis );
	cout << "Search completed: " << (after->tm_year + 1900) << '-' << (after->tm_mon + 1) << '-'<<  after->tm_mday << ", "<<  after->tm_hour << ':' << after->tm_min << ':' << after->tm_sec<< endl;
	cout << "Time elapsed: " << float( clock () - begin_time ) /CLOCKS_PER_SEC <<"s"<< endl;
	//cout << "Speed: " << float( clock () - begin_time ) << endl;
	
	return 0;
}
