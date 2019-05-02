/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <ctime>

using namespace std;


clock_t runner();

void quick(vector<int> * mine, vector<int>::iterator front, vector<int>::iterator finish);

int pivot1(vector<int> * mine, vector<int>::iterator start, vector<int>::iterator finish);

int pivot2(vector<int> * mine, vector<int>::iterator start, vector<int>::iterator finish);

int pivot3(vector<int> * mine, vector<int>::iterator start, vector<int>::iterator finish);



int main(){
    clock_t t = 0;
    int count = 1000;
    for(int i = 0; i<count;i++){
        t += runner();
    }
    t = t/count;
    cout <<t;
}


clock_t runner(){
    int count = 10000;
    
    vector<int> mine;
    
    srand (time(nullptr));
    
    for(int i =0; i<count; i++){
        //int b = rand() %3000 + 1;
        //mine.push_back(i);
        mine.insert(mine.begin(), i);
    }
    
    for(int i =0; i<10;i++){
        cout << mine[i] << ", ";
        if(((i+1)%25)==0){
            cout<<endl;
        }
    }
    
    cout << endl;
    clock_t t = clock();
    sort(mine.begin(), mine.end());
    t = clock() - t;
    
    
    for(int i =0; i<10;i++){
        cout << mine[i] << ", ";
    }
        for(int i =10; i>0;i--){
        cout << mine[mine.size() -i] << ", ";
    }
    
    for(int i = 0; i<(count-1); i++){
        if(mine[i]>mine[i+1]){
            cout<<"fail at " << mine[i];
        }
    }
    
    cout<<endl <<endl <<t<<endl ;
    return t;
}


void quick(vector<int> * mine, vector<int>::iterator front, vector<int>::iterator finish){
    if(front == finish){
        return;
    }
    vector<int>::iterator one = front;
    vector<int>::iterator two = finish;
    int piv = pivot1(mine, front, finish);
    
    while((one+1) != two){
        if(*one > piv){
            int temp = *one;
            *one = *two;
            *two = temp;
            two--;
        }else{
            one++;   
        }
    }
    quick(mine, front, one);
    quick(mine, two, finish);
}

int pivot1(vector<int> * mine, vector<int>::iterator start, vector<int>::iterator finish){
    return *(start);
}

int pivot2(vector<int> * mine, vector<int>::iterator start, vector<int>::iterator finish){
    int dist = distance(start, finish);
    dist = dist/2;
    return *(start+dist);
}


int pivot3(vector<int> * mine, vector<int>::iterator start, vector<int>::iterator finish){
    int dist = distance(start, finish);
    srand (time(nullptr));
    int b = rand() % dist;
    return *(start+b);
}
