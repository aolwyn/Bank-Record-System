
 #include <iostream>
#include <fstream>
#include <stdlib.h>
#include "account.h"

using namespace std;

void account::readData() {
    cout<< "Please enter the following information: "<<endl;
    cout<<"Account Number:"<<endl;
    cin>>account_number;
    cout<<"First Name:"<<endl;
    cin>>first_name;
    cout<<"Last Name:"<<endl;
    cin>>last_name;
    cout<<"and your Balance:"<<endl;
    cin>>account_balance;
}//close readData()

void account::addRecord() {
  ofstream outfile; //i have it sent to a .bank. You can test using .txt, but will have to do it without modes (binary, app)
  outfile.open("bankrecord.bank", ios::binary|ios::app);//creates an output file. uses binary mode and app. app writes at end of whatever is currently in the file
  readData();
  outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
  //alternatively, you can write into the output file using << operator. maybe use a vector if you do it this way.
  //see Shakespearian insult generator repo for alternate file method
  outfile.close();
}//close addRecord()

void account::deleteRecord() {
//you will need to create a temporary file here to store the old data vs new data.
//use keyword continue to keep going through so long as the record to delete hasn't been found.
    int recordNum, record;
    ifstream  infile;
    infile.open("bankrecord.bank",  ios::binary);

    if(!infile){
        cout<<"Could not open file."<<endl;
        return;
    }//close file check

//use an explicit check to see how many records are in the file using .seekg(pos. , direction)
    infile.seekg(0, ios::end);
    recordNum = infile.tellg() / sizeof (*this); //gets amount of records based on the size of file / sizeof check
    string toString = to_string(recordNum);
    cout <<"select 1 of " + toString + "Records to Delete for: "<<endl; //alternately do <<"select 1 of <<recordNum<< "records:" <<endl;
    cin>> record;

    if(record > recordNum || record < 0){
        cout<<"Entered record does not exist."<<endl;
        return;
    }//close record check

    fstream temporaryFile;
    temporaryFile.open("temporaryFile.bank", ios::out|ios::binary); //you should do a check here to see if it opens correctly. I was lazy
    infile.seekg(0); //sets current position to start

    //now to loop through until it comes to the selected record:
    for(int i = 0; i < recordNum; i++){
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i == (recordNum -1)) continue;

        temporaryFile.write(reinterpret_cast<char*>(this), sizeof(*this));

    }//close for loop

    //record has been deleted, now close files:
    temporaryFile.close();
    infile.close();
    remove("bankrecord.bank"); //deletes old version
    rename("temporaryFile.bank", "bankrecord.bank"); //renames the new version the name of the old one

}//close deleteRecord()

void account::showRecord() {
    cout<<"Acount Number: "<<account_number<<endl;
    cout<<"First Name: "<<first_name<<endl;
    cout<<"Last Name: "<<last_name<<endl;
    cout<<"Balance: "<<account_balance<<endl;
    cout<<"end of this record\n";
}//close showRecord();

void account::searchRecord() {
int recordNum, record;
ifstream  infile;
infile.open("bankrecord.bank",  ios::binary);

if(!infile){
    cout<<"Could not open file."<<endl;
    return;
}//close file check

//use an explicit check to see how many records are in the file using .seekg(pos. , direction)
infile.seekg(0, ios::end);
recordNum = infile.tellg() / sizeof (*this); //gets amount of records based on the size of file / sizeof check
string toString = to_string(recordNum);
    cout <<"select 1 of " + toString + "Records to search for: "<<endl; //alternately do <<"select 1 of <<recordNum<< "records:" <<endl;
    cin>> record;

    if(record > recordNum || record < 0){
        cout<<"Entered record does not exist."<<endl;
        return;
    }//close record check

    infile.seekg((record-1)*sizeof (*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    showRecord();

}//close searchRecord()

void account::updateRecord() {
    int recordNum, record;
    fstream  infile;
    infile.open("bankrecord.bank",  ios::binary);

    if(!infile){
        cout<<"Could not open file."<<endl;
        return;
    }//close file check

//use an explicit check to see how many records are in the file using .seekg(pos. , direction)
    infile.seekg(0, ios::end);
    recordNum = infile.tellg() / sizeof (*this); //gets amount of records based on the size of file / sizeof check
    string toString = to_string(recordNum);
    cout <<"select 1 of " + toString + "Records to edit: "<<endl; //alternately do <<"select 1 of <<recordNum<< "records:" <<endl;
    cin>> record;

    if(record > recordNum || record < 0){
        cout<<"Entered record does not exist."<<endl;
        return;
    }//close record check

    infile.seekg((record-1)*sizeof (*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    showRecord();
    //need to close and re-open the file otherwise it may mess with where your current location is in the file.
    infile.close();
    infile.open("bankrecord.bank", ios::out|ios::in|ios::binary);
    infile.seekp((record-1)*sizeof(*this));
    cout<<"above is the old data. enter new data below:"<<endl;
    readData();
    infile.write(reinterpret_cast<char*>(this), sizeof(*this));
    infile.close();
} //close updateRecord();

 void account::quit() {
     exit(0);
 }//close quit();





