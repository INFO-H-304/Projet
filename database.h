#include <vector>
#include <string>
#include <string.h> 

using namespace std;

class Database
{
private:
	string name;
	int nseq;
	int nres;
	

public:
	Database();
	
	string getName();
	int getNSeq();
	int getNRes(); //à delete qd pin résolu
	//string getDesc();
	//vector<char> getSequence();
	
	void setName(string namedb);
	void icrNSeq();
	//void setNRes(int nresdb);
	//void setDesc(string descq);
	//void addResidue(char residue);
};
