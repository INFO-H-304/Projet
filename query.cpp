#include "query.h"

Query::Query()
{
	name = "";
	length = 0;
	desc = "";
	
	//sequence;
}

string Query::getName()
{
	return name;
}

int Query::getLength()
{
	return length;
}

string Query::getDesc()
{
	return desc;
}

vector<char> Query::getSequence()
{
	return sequence;
}

void Query::setName(string nameq)
{
	name = nameq;
}

void Query::setLength(int lengthq)
{
	length = lengthq;
}

void Query::setDesc(string descq)
{
	desc = descq;
}

void Query::addResidue(char residue)
{
	sequence.push_back(residue);
}
