#ifndef _HELP_H
#define _HELP_H
#include <iostream>
#include <fstream>
#include <regex>
#include <cmath>
#include <vector>
#include <chrono>

#include "Parser.h"
#include "Collection.h"

using namespace std;
using namespace std::chrono;

class Help {
   private:
      string inputFileName;
      Collection market;
      Collection hold;
      Collection finalP;
      int selectedNum = 0, p = 0;
      
   public:
      Help();
      void inputMarketFile(string inputM);
      int inputPriceFile(string inputP, ofstream& newFile);
      int ComputeMaxProfit(int num, int maxSpend);
      bool checkInt(string s);
      bool isMatch(Collection market, Collection hold);
      void ProblemAns(int size, int maxProfit, int numC, long long tc, ofstream& newFile);
     };

#endif // _HELP_H
