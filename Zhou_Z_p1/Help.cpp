#include "Help.h"
using namespace std;

Help::Help(){
    inputFileName = "";
}

void Help::inputMarketFile(string inputM){
    string lineM;
    fstream marketFile(inputM);
    string numM, cardName, cardVal;
    Card card;

    if(!marketFile.is_open()){
        cout << "No such file" << endl;
    }else{
        while(!marketFile.eof()){
            getline(marketFile,lineM);
            Parser M(lineM);
            if(lineM == ""){
                if(cin.fail())
                    break;
                continue;
             }
             if(M.numArgs() == 1){
                numM = M.getArg1();
             }else if(M.numArgs() == 2){
                cardName = M.getArg1();
                cardVal = M.getArg2();
                card = Card(cardName, cardVal);
                market.addCard(card);
             }else{
                cout << " worng input " << endl;
             }
        }
    }
     marketFile.close();
}

int Help::inputPriceFile(string inputP, ofstream& newFile){
    string lineP;
    fstream priceFile(inputP);
    string cardName, cardVal;
    Card card;
    int maxSpend = 0, maxProfit = 0, numP = 0, count = 0; 

    if(!priceFile.is_open()){
        cout << "No such file" << endl;
    }else{
        while(!priceFile.eof()){
            getline(priceFile, lineP);
            Parser P(lineP);
            if(lineP == ""){
                if(cin.fail())
                    break;
                continue;
             }
             
             if(checkInt(P.getArg1())){
                numP = stoi(P.getArg1());
                maxSpend = stoi(P.getArg2());
             }else{
                cardName = P.getArg1();
                cardVal = P.getArg2();
                card = Card(cardName, cardVal);
                hold.addCard(card);
                count++;
             }

             if(count == numP){
                p++;
                if(!isMatch(market, hold)){
                    newFile << "Does Not Macth" <<endl;
                    return -1;
                }
                auto start = high_resolution_clock::now();
                maxProfit = ComputeMaxProfit(numP, maxSpend);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                ProblemAns(numP, maxProfit,selectedNum, duration.count(), newFile);
                hold.clear();
                numP = 0;
                count = 0;
                maxSpend = 0;
                maxProfit = 0;
                finalP.clear();
             }     
        }
    }
    priceFile.close();
    return 0;
}

bool Help::checkInt(string s){
    if (regex_match(s, regex("[0-9]+"))){
        return true;
    }
    return false;
}

bool Help::isMatch(Collection market, Collection hold){
    //bool match = true;
    int matchcount = 0;
    for(int i = 0; i < hold.numOfcards(); i++){
        for(int j = 0; j < market.numOfcards(); j++){
            if(hold.getCard(i) == market.getCard(j)){
                matchcount++;
            }  
        }
    }
    if(matchcount != hold.numOfcards() ){
        cout<<"Does not matched!!!!!"<<endl;
        return false;
    }
    return true;
}


int Help::ComputeMaxProfit(int num, int maxSpend){
    int profit = 0, maxProfit = 0, spend = 0, value = 0, mask = 1;
    int subsetNum = pow(2, num);
    vector<Card> tempsubset;

    if(spend <= maxSpend){
        value = market.getTotalVal();
        spend = hold.getTotalVal();
        profit = value - spend;
        maxProfit = profit;
        selectedNum = hold.numOfcards();
        for(int i = 0; i < num; i++){
            finalP.addCard(hold.getCard(i));
        }
    }else{
        //generate subset
        for(int i = 0; i < subsetNum; i++){
            for(int j = 0; j < num; j++){
                if(i & mask != 0){
                    tempsubset.push_back(hold.getCard(i));
                    finalP.addCard(hold.getCard(i));
                }
                mask <<= 1;
            }
            for(int k = 0; k < tempsubset.size(); k++){
                value += market.getVal(tempsubset[i].GetCardName());
                spend += tempsubset[i].GetCardValue();
            }
            profit = value - spend;
            if(spend < maxSpend){
                if(profit > maxProfit){
                    maxProfit = profit;
                }
            }
        }
        selectedNum = tempsubset.size();
    }
    return maxProfit;
}

void Help::ProblemAns(int size, int maxProfit, int numC, long long tc, ofstream& newFile){
    //long long timeC = tc / (1000000);
    cout<<"Problem "<<p<<endl;
    cout<<"     size: "<<size<<" "<<endl;
    cout<<"     maxProfit: "<<maxProfit<<" "<<endl;
    cout<<"     #Cards: "<<numC<<" "<<endl;
    cout<<"     timeComplexity: "<<tc*(0.000001)<<" sec "<<endl;

    newFile << size << " " << maxProfit << " " << numC << " " <<tc*(0.000001) << endl;
    finalP.cardList(newFile);
    // newFile<<"Problem " << p << endl;
    // newFile<<"     size: "<<size<<" "<<endl;
    // newFile<<"     maxProfit: "<<maxProfit<<" "<<endl;
    // newFile<<"     #Cards: "<<numC<<" "<<endl;
    // finalP.cardList(newFile);
    // newFile<<"     timeComplexity: "<<tc*(0.000001)<<" microseconds "<<endl;
}