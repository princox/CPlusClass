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
    
    void AddMoney(int val){
        balance += val;
    }
    void MinMoney(int val){
        balance -= val;
    }
    char* GetName(){
        return name;
    }
    void ShowData(){
        cout << "계좌ID : " << id << endl;
        cout << "이름 : " << name << endl;
        cout << "잔액 : " << balance << endl;
    }
};

Account* pArray[100];
int idx = 0;

void Printmenu();
void Makeaccount();
void Deposit();
void Withdraw();
void Inquire();

enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main(){
    int choice;
    
    while (1) {
        Printmenu();
        cout << "선택 : ";
        cin >> choice;
        
        switch (choice) {
            case MAKE:
                Makeaccount();
                break;
            case DEPOSIT:
                break;
            case WITHDRAW:
                Withdraw();
                break;
            case INQUIRE:
                Inquire();
                break;
            case EXIT:
                return 0;
            default:
                cout << " illegal selection.. " << endl;
                break;
        }
    }
    return 0;
}

void Printmenu(){
    cout << "----menu----" << endl;
    cout << " 1. 계좌 개설"  << endl;
    cout << " 2. 입금 " << endl;
    cout << " 3. 출금 " << endl;
    cout << " 4. 잔액조회 " << endl;
    cout << " 5. 프로그램 종료" << endl;
}

void Makeaccout(){
    int id;
    char name[NAME_LEN];
    int balance;
    
    cout << " 계좌 개설---" << endl;
    cout << " 계좌 id"; cin >> id;
    cout << " 이름 : "; cin >> balance;
    cout << " 입금액 : "; cin >> balance;
    pArray[idx++] = new Account(id, name, balance);
}

void Deposit(){
    int money;
    int id;
    cout << " 계좌 id : "; cin >> id;
    cout << " 입금액 : "; cin >> money;
    
    for (int i = 0; i < idx; i++) {
        if(pArray[i]->GetID() == id){
            pArray[i]->AddMoney(money);
            cout << " 입금 완료 " << endl;
            return;
        }
    }
    cout << " 유효하지 않은 ID입니다. " << endl;
}

void Inquire(){
    for (int i=0; i<idx; i++) {
        pArray[i]->ShowData();
    }
}
</iostream>


