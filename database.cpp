#include "database.h"

Database::Database()
{
	name = "";
	nseq = 0;
	nres = 0;
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

int Database::getNRes()
{
	return nres;
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
	
/*void Database::setDesc(string descq)
{
	desc = descq;
}

void Database::addResidue(char residue)
{
	sequence.push_back(residue);
}*/
