/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;



void quick(vector * mine, iterator start, iterator finish);

void quickHelp();

int pivot(vector * mine, iterator start, iterator finish);




int main()
{
    vector<int> mine;
    
    srand (time(nullptr));
    
    for(int i =0; i<3000; i++){
        int b = rand() %3000 + 1;
        mine.push_back(b);
    }
    
    for(int i =0; i<1000;i++){
        cout << mine[i] << endl;
    }
    
    sort(mine.begin(), mine.end());
    
    for(int i =0; i<1000;i++){
        cout << mine[i] << endl;
    }
}


void quick(vector * mine, iterator start, iterator finish){
    if(start == finish){
        return;
    }
    iterator one = start;
    iterator two = finish;
    int pivot = pivot(mine, start, finish);
    
    while(start != finish){
        
    }
    
    quick(mine, start, one);
    quick(mine, two, finish)
    
    
}

int pivot(vector * mine, iterator start, iterator finish){
    return *start;
}



