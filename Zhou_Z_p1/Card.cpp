#include "Card.h"
using namespace std;

Card::Card(){
    cardName = "";
    cardValue = 0;
}

Card::Card(const std::string &cName, const std::string &cValue) {
   cardName = cName;
   cardValue = std::stoi(cValue);
}

Card::Card(const Card &c1){
    cardName = c1.cardName;
    cardValue = c1.cardValue;
}

Card& Card::operator=(const Card &rhs){
   if(&rhs != this){
      cardName = rhs.cardName;
      cardValue = rhs.cardValue;
   }
   return *this;
}
bool Card::operator==(const Card &c){
    if(cardName == c.cardName){
        return true;
    }
    return false;
}

 bool Card::operator!=(const Card &c){
     if(cardName != c.cardName || cardValue != c.cardValue){
        return true;
    }
    return false;
 }
void Card::print(ofstream& newFile){
    newFile << cardName <<" "<< cardValue << endl;
    cout<< "      CardName: " << cardName;
    cout << "     cardvalue: " << cardValue << endl;
}