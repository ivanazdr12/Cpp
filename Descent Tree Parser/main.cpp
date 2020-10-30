#include <iostream>
#include <cstring>
#include <fstream>
#include <set> 
#include <string>
#include "lex.h"
#include "parse.h"
#include "pt.h"

using namespace std;
int line = 0;
istream *input = &cin;
ifstream inFile;

int main(int argc, char *argv[]) {

    for(int i =1; i<argc; i++){

        string command(argv[i]);

        if (i == argc-1){

            inFile.open(command);

            if( inFile.is_open() == false ) {
                cerr << "CANNOT OPEN "<< command << endl;
                return -1;
            }
            input = &inFile;
        }

        else{            
            cerr << "ONLY ONE FILE NAME ALLOWED" <<endl;
            return -1;
        }               
    }

    Pt *tree = Prog(*input,line);
    if(tree == 0){
        //nothing
    }

    if(tree != 0){
        if(tree->plusCount() != 0 || tree->plusCount() == 0){ 
            cout<<"PLUS COUNT: " << tree->plusCount()<<endl;
        }   
        if(tree->eqCount()!= 0 || tree->eqCount() == 0){ 
            cout<<"EQ COUNT: " << tree->eqCount()<<endl;
        }
        if(tree->maxdepth()!= 0 || tree->maxdepth() == 0){ 
            cout<<"MAX DEPTH: " << tree->maxdepth()<<endl;
        }  
    }
    return 0;
}