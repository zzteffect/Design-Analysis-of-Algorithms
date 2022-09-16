#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include "Help.h"

using namespace std;
using namespace std::chrono;

//$> program1 –m <market-price-file> -p <price-list-file>
int main(int argc , char *argv[]) {
   char opt;
   string mFile, pFile, line;
   Help help;
   int e = 0;

   while ((opt = getopt(argc, argv, "m:p:")) != -1)
    {
        switch (opt){
            case 'm':
                mFile = optarg;
                break;
            case 'p':
                pFile = optarg;
                break;
        }
    }

    if(mFile == ""){
        cout << "Missing Argument for <market-price-file>" << endl;
        return -1;
    }

    if(pFile == ""){
        cout << "Missing Argument for <price-list-file>" << endl;
        return -1;
    }

    ofstream newFile("output.txt");
    help.inputMarketFile(mFile);
    e = help.inputPriceFile(pFile, newFile);
    newFile.close();
    return e;
}