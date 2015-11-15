#include <vector>
#include <string>
#include <string.h> 

using namespace std;

class Database
{
private:
	string name;
	int nseq;
	int restot;
	int resmax;
	

public:
	Database();
	
	string getName();
	int getNSeq();
	int getResMax(); //à delete qd pin résolu
	int getResTot(); //à delete qd pin résolu
	
	void setName(string namedb);
	void icrNSeq();
	void setResMax(int resmaxdb); //à delete qd pin résolu
	void icrResTot(); //à delete qd pin résolu
};
