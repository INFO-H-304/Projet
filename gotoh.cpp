#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "query.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::min;
using std::max;


//	Affine Gap algorithm taken from:
//	gap = d + (k-1)*e;
//	d:	gap opening penalty  (o < 0)
//	k:	length of the gap
//	e:	gap extension penalty (o < e < 0)

//  Matrices
//  S(i,j):  matrice de  BLOSUM62
//  M(i; j) : the best score up to (i; j), given that xi is aligned to yj
//  Ix(i; j) : the best score up to (i; j), given that xi is aligned to a gap
//  Iy(i; j) : the best score up to (i; j), given that yj is aligned to a gap

// Affine Gap
  int AffineGapWeight(int gapOpenPenalty, int gapExtendPenalty,int k){
  	int w_k=-gapOpenPenalty - gapExtendPenalty*(k-1);
   	return w_k;
  }
  
	  
  //Matrice Initialisation M Ix Iy
  void InitMatGotohMax(int** M, int** Ix, int** Iy, string pReference){
	int n =pReference.size();
	int m = Query().getLenght();
   	for(int i = 0; i < m+1; i++) {
    	M[i][0] = -99;
    	Iy[i][0] = -99; // en theorie c'est -l'infini
  	}
  	for(int j = 0; j < n+1; j++) {
  		M[0][j] = -99;
  		Ix[0][j] = -99;
  	}
  	M[0][0]=0;
  }
  

  void CalculateAllMatrixGotohMax(int** M, int** Ix, int** Iy, int** S, string pReference,int gapOpenPenalty, int gapExtendPenalty){
	InitMatGotohMax(M, Ix, Iy,pReference,  pQuery) ;
	int n =pReference.size();
	int m = Query().getLenght();
	  for (int i=1; i <m+1 ; i++) {
    	for (int j=1; j < n+1; j++){
			 Ix[i][j] = max(M[i-1][j] - gapOpenPenalty,Ix[i-1][j] - gapExtendPenalty);
			 Iy[i][j] = max(M[i][j-1] - gapOpenPenalty,Iy[i][j-1] - gapExtendPenalty);
			 M[i][j] = findMax(M[i-1][j-1] + S[j-1][i-1],Ix[i-1][j-1]+S[j-1][i-1],Iy[i-1][j-1]+S[j-1][i-1]);
			 }
	 }
	    cout << endl;
	}
