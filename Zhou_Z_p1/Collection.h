#ifndef _COLLECTION_H
#define _COLLECTION_H
#include <iostream>
#include <fstream>
#include <vector>

#include "Card.h"

using namespace std;

class Collection {
   private:
      int NumCards = 0;
      vector<Card> cards;

   public:
      int numOfcards(){return NumCards;}
      int getTotalVal();
      int getVal(string cardName);

      void addCard(Card c);
      void cardList(ofstream& newFile);
      void clear();
      Card getCard(int i);
     };

#endif // _COLLECTION_H