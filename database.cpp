#include "database.h"

Database::Database()
{
	name = "";
	nseq = 0;
	restot = 0;
	resmax = 0;
	//string desc;
	
}

string Database::getName()
{
	return name;
}

int Database::getNSeq()
{
	return nseq;
}

int Database::getResMax()
{
	return resmax;
}

int Database::getResTot()
{
	return restot;
}

/*string Database::getDesc()
{
	return desc;
}

vector<char> Database::getSequence()
{
	return sequence;
}*/

void Database::setName(string namedb)
{
	name = namedb;
}

void Database::icrNSeq()
{
	nseq++;
}
	
void Database::setResMax(int resmaxdb)
{
	resmax = resmaxdb;
}

void Database::icrResTot()
{
	restot++;
}
