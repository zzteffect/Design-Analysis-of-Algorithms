#include "Collection.h"
using namespace std;

// Collection::Collection(){
//     NumCards = 0;

// }
// Collection::Collection(int numC, vector<Card> c){
//     NumCards = numC;
//     cards = c;
// }

// Collection::Collection(Collection &rhs){
//     NumCards = rhs.NumCards;
//     for(int i = 0; i < NumCards; i++ ){
//         cards[i] = rhs.cards[i];
//     }
// }

void Collection::addCard(Card c){
    cards.push_back(c);
    NumCards++;
}

void Collection::cardList(ofstream& newFile){
    for(int i = 0; i < NumCards; i++){
        cards[i].print(newFile);
    }
}

void Collection::clear(){
    NumCards = 0;
    cards.erase(cards.begin(), cards.end());
}

Card Collection::getCard(int i){
    Card card = Card();
    for(int d = 0; d < NumCards; d++){
        if(d == i){
            return cards[d];
        }
    }
    return card;
}

int Collection::getTotalVal(){
    int totalVal = 0;
    for(int i = 0; i < NumCards; i++){
        totalVal += cards[i].GetCardValue();
    }
    return totalVal;
}

int Collection::getVal(string cardName){
    int val = 0;
    for(int i = 0; i < NumCards; i++){
        if(cards[i].GetCardName() == cardName){
            val = cards[i].GetCardValue();
        }
    }
    return val;
}