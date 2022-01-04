#include <iostream>
#include <fstream>
#include "account.h"
#include <stdlib.h>

using namespace std;

int main() {

int number;
account test;

cout<<"Account Information System"<<endl;

while(1){
    cout<<"Please enter one of the following options:"<<endl;
    cout<<"1: Add a Record "<<endl;
    cout<<"2: Show Record from File "<<endl;
    cout<<"3: Update a Record "<<endl;
    cout<<"4: Delete a Record "<<endl;
    cout<<"5: Search for a Record"<<endl;
    cout<<"6: Exit"<<endl;
    cout<<"---------------------"<<endl;
    cin>> number;

    switch(number) {
        //cout<<"test number entered: "<< number<<endl;
        case 1:
            //cout <<" should show 1":<<endl;
            //cout<<"test number entered: "<< number<<endl;
            test.addRecord();
            break;

        case 2:
            test.showRecord();
            break;

        case 3:
            test.updateRecord();
            break;

        case 4:
            test.deleteRecord();
            break;

        case 5:
            test.searchRecord();
            break;

        case 6:
            test.quit();
            break;
        default:
            cout << "You have entered a number not included in the selection. Please try again." << endl;
            exit(0);
    }//close switch statement


    }//close while loop
    return 0;
}



