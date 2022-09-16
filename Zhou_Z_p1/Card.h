#ifndef _CARD_H
#define _CARD_H
#include <iostream>
#include <fstream>

using namespace std;

class Card {
   private:
      string cardName;
      double cardValue;

   public:
      Card();
      Card(const std::string &cName, const std::string &cValue); //, const std::string &cPrice copy assignment 
      Card(const Card &c1);
      Card& operator=(const Card &rhs);
      bool operator==(const Card &c);
      bool operator!=(const Card &c);

      string GetCardName(){return cardName;}
      double GetCardValue(){return cardValue;}
      
      void print(ofstream& newFile);
     };

#endif // _CARD_H
