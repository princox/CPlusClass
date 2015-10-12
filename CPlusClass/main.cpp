//
//  main.cpp
//  CPlusClass
//
//  Created by Rhee on 2015. 9. 10..
//  Copyright (c) 2015년 Rhee. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;


class Account {
    int id;
    int balance;
    char *name;
public:
    Account(){}
    Account(int id, char *name, int balance){
        this->id = id;
        this->balance = balance;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        
    }
    ~Account(){
        delete []name;
    }
    int GetID(){ return id;}
    int GetBalance() { return balance; }
    
};
//
//int main(int argc, const char * argv[]) {
//    char password[11];
//    cout << "프로그램을 종료하려면 암호를 입력하세요" << endl;
//    while (true) {
//        cout << "암호 :";
//        cin >> password;
//        if(strcmp(password, "C++")==0){
//            cout<< "프로그램을 정상 종료합니다."<<endl;
//            break;
//        }
//        else cout << "암호가 틀립니다." << endl;
//
//    }
//}