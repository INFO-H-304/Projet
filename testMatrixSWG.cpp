#include <iostream>
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
  int gapOpenPenalty = 11;
  int gapExtendPenalty = 1;
	  
  string pReference= "ATGGCGGGGATCGGGACACTCGCCGGTGCGGGTACCCTA";
  string pQuery = "GGGGATCGGGACACTCGCTCTCCGGTGCGGGTA";
  int n = pReference.size();
  int m = pQuery.size();
  cout << "Nombre de colonnes : " << n << endl;
  cout << "Nombre de lignes : " << m << endl;

  int **creatMatrix(string pReference, string pQuery);
  void affiche (string pReference, string pQuery, int **t);
  int CalculateGapWeight(int gapOpenPenalty, int gapExtendPenalty,int k);
  void InitMat(int** D, int** P, int**Q,int gapOpenPenalty, int gapExtendPenalty);
  int getSizeString(string a);
 int ** CalculateMatrixD(int ** D,int ** P, int ** Q,string pReference, string pQuery);
 int ** CalculateMatrixP(int ** D, int ** P, int ** Q, string pReference, string pQuery);
 int ** CalculateMatrixQ(int ** D, int ** P, int ** Q, string pReference, string pQuery);
   void CalculateAllMatrix(int ** D, int ** P, int ** Q, string pReference, string pQuery);
  int w(char x,char y);
   int findMin (int a, int b, int c);
  
  	int **D = creatMatrix(pReference, pQuery) ;
  	int **P = creatMatrix(pReference, pQuery) ;
  	int **Q = creatMatrix(pReference, pQuery) ;
	InitMat(D,P,Q,gapOpenPenalty,gapExtendPenalty);
	affiche (pReference, pQuery, D);
	cout << "lignes : " <<endl;
	cout << "lignes : " <<endl;	
	cout << "lignes : " <<endl;	
	cout << "lignes : " <<endl;
	//CalculateMatrixD(D, P, Q,pReference, pQuery);
	affiche (pReference, pQuery, P);
	affiche (pReference, pQuery, Q);

	CalculateAllMatrix(D,P,Q,pReference,pQuery);
		affiche (pReference, pQuery, D);
		affiche (pReference, pQuery, P);
	affiche (pReference, pQuery, Q);
	
	return 0;
}

  int **creatMatrix(string pReference, string pQuery){
	  int **t;
	  int n = pReference.size();
	  int m = pQuery.size();
	  /* Allocation dynamique */
	  t = new int* [m];
	  for (int i=0; i < m; i++)
		t[i] = new int[n];
	  /* Initialisation */
	  for (int i=0; i < m; i++)
		for (int j=0; j < n; j++)
		  t[i][j] = 0;
	  return t;
 }
 
  /* Affichage */
  void affiche (string pReference, string pQuery, int **t){  
	  int n = pReference.size();
	  int m = pQuery.size();
  	for (int i=0; i < m; i++) {
    	for (int j=0; j < n; j++)
      	cout << t[i][j] << " ";
    cout << endl;
  	}
  	cout << endl;
  }
  
  
    //gap  Weight
  int CalculateGapWeight(int gapOpenPenalty, int gapExtendPenalty,int k){
  	int w_k=gapOpenPenalty + gapExtendPenalty*k;
   	return w_k;
  }
  
  
  //distance weight
  int w(char x,char y){
	  int w = 0;
	  if (x != y)
		w = 1;
	return w;
	}
  
  int getSizeString(string a){
	  int size = a.size();
	  return size;
	  }
	  
  //Matrice Initialisation P Q D
  void InitMat(int** D, int** P, int**Q,int gapOpenPenalty, int gapExtendPenalty){
   	for(int i = 0; i < 33; i++) {
    	D[i][0] = CalculateGapWeight(gapOpenPenalty, gapExtendPenalty,i);
    	Q[i][0] = 99;
  	}
  	for(int j = 0; j < 39; j++) {
  		D[0][j] = CalculateGapWeight(gapOpenPenalty, gapExtendPenalty,j);
  		P[0][j] = 99;
  	}
  	D[0][0]=0;
  }
  

  
//find min
 int findMin (int a, int b, int c){
	 int m = min(a,b);
	 int n= min(m,c);
	 return n;
	 }




//Calcul Matrix D


  int** CalculateMatrixD(int ** D, int ** P, int ** Q, string pReference, string pQuery){
	  for (int i=1; i < 33; i++) {
    	for (int j=1; j < 39; j++){
			 D[i][j] = findMin(D[i-1][j-1] + w(pReference[i],pQuery[j]),P[i][j],Q[i][j]);
			 cout << w(pReference[i],pQuery[j]) << " ";
			 }
 
	 }
	    cout << endl;
	    return D;
	}

  int** CalculateMatrixP(int ** D, int ** P, int ** Q, string pReference, string pQuery){
	  for (int i=1; i < 33; i++) {
    	for (int j=1; j < 39; j++){
			 P[i][j] = min(D[i-1][j] + CalculateGapWeight(11, 1, 1),P[i-1][j] + 11);
			 cout << CalculateGapWeight(11, 1, 1) << " ";
			 }
 
	 }
	    cout << endl;
	    return P;
	}

  int** CalculateMatrixQ(int ** D, int ** P, int ** Q, string pReference, string pQuery){
	  for (int i=1; i < 33; i++) {
    	for (int j=1; j < 39; j++){
			 Q[i][j] = min(D[i][j-1] + CalculateGapWeight(11, 1, 1),Q[i][j-1] + 11);
			 cout << CalculateGapWeight(11, 1, 1) << " ";
			 }
 
	 }
	    cout << endl;
	    return Q;
	}

  void CalculateAllMatrix(int ** D, int ** P, int ** Q, string pReference, string pQuery){
	InitMat(D, P, Q,11, 1) ;
	  for (int i=1; i < 33; i++) {
    	for (int j=1; j < 39; j++){
			 Q[i][j] = min(D[i][j-1] + CalculateGapWeight(11, 1, 1),Q[i][j-1] + 11);
			 P[i][j] = min(D[i-1][j] + CalculateGapWeight(11, 1, 1),P[i-1][j] + 11);
			 D[i][j] = findMin(D[i-1][j-1] + w(pReference[i],pQuery[j]),P[i][j],Q[i][j]);
			 }
 
	 }
	    cout << endl;
	}

  
