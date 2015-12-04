#include <iostream>
//#include <ostream>
#include <stdio.h>
#include <string.h>
#include <fstream>


using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::min;


int main(int argc, char *argv[])
{
	//terminal  g++ -o hello hello.cpp puis ./hello

	//int matchScore = 0;
	//int mismatchScore = 1;
  int gapOpenPenalty = 4;
  int gapExtendPenalty = 1;
	  
  string pReference= "ACCT";
  string pQuery = "CC";
  int n = pReference.size();
  int m = pQuery.size();
  cout << "Nombre de colonnes : " << n << endl;
  cout << "Nombre de lignes : " << m << endl;

  int **creatMatrix(string pReference, string pQuery);
  void affiche (string pReference, string pQuery, int **t);
  int CalculateGapWeight(int gapOpenPenalty, int gapExtendPenalty,int k);
  void InitMatGotohMin(int** D, int** P, int**Q,int gapOpenPenalty, int gapExtendPenalty, string pReference, string pQuery);
  int getSizeString(string a);
// int ** CalculateMatrixD(int ** D,int ** P, int ** Q,string pReference, string pQuery);
// int ** CalculateMatrixP(int ** D, int ** P, int ** Q, string pReference, string pQuery);
 //int ** CalculateMatrixQ(int ** D, int ** P, int ** Q, string pReference, string pQuery);
   void CalculateAllMatrixGotohMin(int ** D, int ** P, int ** Q, string pReference, string pQuery);
  int w(char x,char y);
   int findMin (int a, int b, int c);
  
  	int **D = creatMatrix(pReference, pQuery) ;
  	int **P = creatMatrix(pReference, pQuery) ;
  	int **Q = creatMatrix(pReference, pQuery) ;
	InitMatGotohMin(D,P,Q,gapOpenPenalty,gapExtendPenalty,  pReference,  pQuery);
	affiche (pReference, pQuery, D);
	cout << "lignes : " <<endl;
	cout << "lignes : " <<endl;	
	cout << "lignes : " <<endl;	
	cout << "lignes : " <<endl;
	//CalculateMatrixD(D, P, Q,pReference, pQuery);
	affiche (pReference, pQuery, P);
	//affiche (pReference, pQuery, Q);

	CalculateAllMatrixGotohMin(D,P,Q,pReference,pQuery);
	affiche (pReference, pQuery, D);
	affiche (pReference, pQuery, P);
	affiche (pReference, pQuery, Q);
	
	return 0;
}

  int **creatMatrix(string pReference, string pQuery){
	  int **t;
	  int n = pReference.size()+1;
	  int m = pQuery.size()+1;
	  /* Allocation dynamique */
	  t = new int* [m+1];
	  for (int i=0; i <= m; i++)
		t[i] = new int[n+1];
	  /* Initialisation */
	  for (int i=0; i <= m; i++)
		for (int j=0; j <= n; j++)
		  t[i][j] = 0;
	  return t;
 }
 
  /* Affichage */
  void affiche (string pReference, string pQuery, int **t){  
	  int n = pReference.size();
	  int m = pQuery.size();
  	for (int i=0; i < m+1; i++) {
    	for (int j=0; j < n+1; j++){
			cout << t[i][j] << " ";
			}
    cout << endl;
  	}
  	cout << endl;
  }
  
  
//find min
 int findMin (int a, int b, int c){
	 int m = min(a,b);
	 int n= min(m,c);
	 return n;
	 }


  
    //gap  Weight
  int CalculateGapWeight(int gapOpenPenalty, int gapExtendPenalty,int k){
  	int w_k=gapOpenPenalty + gapExtendPenalty*k;
   	return w_k;
  }
  
  
  //distance weight
  int w(char x,char y){
	  int wl = 1;
	  if (x == y)
		wl= 0;
	return wl;
	}
  
  int getSizeString(string a){
	  int size = a.size();
	  return size;
	  }
	  
  //Matrice Initialisation P Q D
  void InitMatGotohMin(int** D, int** P, int**Q,int gapOpenPenalty, int gapExtendPenalty, string pReference, string pQuery){
	int n =pReference.size();
	int m = pQuery.size();
   	for(int i = 0; i < m+1; i++) {
    	D[i][0] = CalculateGapWeight(gapOpenPenalty, gapExtendPenalty,i);
    	Q[i][0] = 99;
  	}
  	for(int j = 0; j < n+1; j++) {
  		D[0][j] = CalculateGapWeight(gapOpenPenalty, gapExtendPenalty,j);
  		P[0][j] = 99;
  	}
  	D[0][0]=0;
  }
  

  void CalculateAllMatrixGotohMin(int ** D, int ** P, int ** Q, string pReference, string pQuery){
	InitMatGotohMin(D, P, Q,4, 1,  pReference,  pQuery) ;
	int n =pReference.size();
	int m = pQuery.size();
	  for (int i=1; i <m+1 ; i++) {
    	for (int j=1; j < n+1; j++){
			 P[i][j] = min(D[i-1][j] + CalculateGapWeight(4, 1, 1),P[i-1][j] + 1);
			 Q[i][j] = min(D[i][j-1] + CalculateGapWeight(4, 1, 1),Q[i][j-1] + 1);
			 D[i][j] = findMin(D[i-1][j-1] + w(pReference[j-1],pQuery[i-1]),P[i][j],Q[i][j]);
			 }
 
	 }
	    cout << endl;
	}

  


/*

//Calcul Matrix D


  int** CalculateMatrixD(int ** D, int ** P, int ** Q, string pReference, string pQuery){
	  for (int i=1; i < 3; i++) {
    	for (int j=1; j < 5; j++){
			 D[i][j] = findMin(D[i-1][j-1] + w(pReference[i],pQuery[j]),P[i][j],Q[i][j]);
			 cout << w(pReference[i],pQuery[j]) << " ";
			 }
 
	 }
	    cout << endl;
	    return D;
	}

  int** CalculateMatrixP(int ** D, int ** P, int ** Q, string pReference, string pQuery){
	  for (int i=1; i < 3; i++) {
    	for (int j=1; j < 5; j++){
			 P[i][j] = min(D[i-1][j] + CalculateGapWeight(4, 1, 1),P[i-1][j] + 4);
			 cout << CalculateGapWeight(4, 1, 1) << " ";
			 }
 
	 }
	    cout << endl;
	    return P;
	}

  int** CalculateMatrixQ(int ** D, int ** P, int ** Q, string pReference, string pQuery){
	  for (int i=1; i <3 ; i++) {
    	for (int j=1; j < 5; j++){
			 Q[i][j] = min(D[i][j-1] + CalculateGapWeight(4, 1, 1),Q[i][j-1] + 4);
			 cout << CalculateGapWeight(4, 1, 1) << " ";
			 }
 
	 }
	    cout << endl;
	    return Q;
	}
*/
