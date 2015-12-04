#include "lib.h"  
  
  class Gotoh
  {
  public:
  Gotoh();
  
  // Max 3
  int findMax (int a, int b, int c);
  
  //gap penalty
  int AffineGapWeight(int gapOpenPenalty, int gapExtendPenalty,int k);
  
  //Matrix Initialisation M Ix Iy
  void InitMatGotohMax(int** M, int** Ix, int** Iy, string pReference);

  // Matrix Calculation
  void CalculateAllMatrixGotohMax(int** M, int** Ix, int** Iy, int** S, string pReference,int gapOpenPenalty, int gapExtendPenalty);
  }
  
