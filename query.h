#include <vector>
#include <string>

using namespace std;

class Query
{
private:
	string name;
	int length;
	string desc;
	vector<char> sequence;

public:
	Query();
	
	string getName();
	int getLength();
	string getDesc();
	vector<char> getSequence();
	
	void setName(string nameq);
	void setLength(int lengthq);
	void setDesc(string descq);
	void addResidue(char residue);
};
