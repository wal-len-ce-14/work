#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

class Cust_Infor{
    private:
        /// define node
        struct Data{
            long long int Account;
            bool Type;
            long long int Amount;
            Data *nex, *pre;
            Data(){ nex = this; pre = this; Account = 0;}
            Data(long long int A, bool T, long long int am):
                Account(A), Type(T), Amount(am){};
        };
        /// define variable
        Data *head;

    public:
        /// init
        Cust_Infor(){ head = new Data; };
        /// function
        void Insert(long long int A, bool T, long long int am);
        void Delete(char* Path);
        void Search(char* Path);  // output data NO. if not find, output error
        void Show_all();
        void Read_data(char* Path);
        void Load_data(char* Path);
};

void Cust_Infor::Insert(long long int A, bool T, long long int am){
    Data *nwn = new Data(A, T, am);
    if(head == head-> nex){
        nwn-> nex = head;
        nwn-> pre = head;
        head-> nex = nwn;
        head-> pre = nwn;
    }else{
        Data *cur = head-> nex;
        while(A > cur-> Account && cur != head){
            cur = cur-> nex;
        }
        if(A == cur-> Account && cur != head){
            //printf("Error: Insert duplicate data\n\n");
            return;
        }
        cur-> pre-> nex = nwn;
        nwn-> nex = cur;
        nwn-> pre = cur-> pre;
        cur-> pre = nwn;
    }
}

void Cust_Infor::Delete(char* Path){
    long long int A;
    fstream file;
    file.open(Path, ios::in);
    while(!file.eof()){
        file >> A;
        if(head-> nex == head){
            printf("Account %lld does not exist...\n\n", A);
            return;
        }
        Data *cur = head-> nex;
        long long int NO = 1;
        while(cur-> Account != A){
            cur = cur-> nex;
            NO += 1;
            if(cur == head){
                printf("Account %lld does not exist...\n\n", A);
                break;
            }
        }
        if(cur == head) break;
        printf("\tDelete Number %lld data in the sequence\n", NO);
        printf("\tAccount: %lld\n", cur-> Account);
        if(!cur-> Type) printf("\tType: Personal Account\n");
        else printf("\tType: Company Account\n");
        printf("\tAmount: %lld\n\n", cur-> Amount);

        cur-> pre-> nex = cur-> nex;
        cur-> nex-> pre = cur-> pre;
        delete(cur);
        continue;
    }

}

void Cust_Infor::Search(char* Path){
    long long int A;
    fstream file;
    file.open(Path, ios::in);
    while(!file.eof()){
        file >> A;
        if(head-> nex == head){
            printf("Account %lld does not exist...\n\n", A);
            return;
        }
        Data *cur = head-> nex;
        long long int NO = 1;
        while(cur-> Account != A){
            cur = cur-> nex;
            NO += 1;
            if(cur == head){
                printf("Account %lld does not exist...\n\n", A);
                break;
            }
        }
        if(cur == head) break;
        printf("\tNumber %lld data in the sequence\n", NO);
        printf("\tAccount: %lld\n", cur-> Account);
        if(!cur-> Type) printf("\tType: Personal Account\n");
        else printf("\tType: Company Account\n");
        printf("\tAmount: %lld\n\n", cur-> Amount);
        continue;
    }
}

void Cust_Infor::Show_all(){
    if(head == head-> nex){
        printf("Sequence does not exist...\n\n");
        return;
    }
    Data *cur = head-> nex;
    while(cur != head){
        printf("\tAccount: %lld\n", cur-> Account);
        if(!cur-> Type) printf("\tType: Personal Account\n");
        else printf("\tType: Company Account\n");
        printf("\tAmount: %lld\n\n", cur-> Amount);

        cur = cur-> nex;
    }
}

void Cust_Infor::Read_data(char* Path){
    long long int A, am;
    bool T;
    fstream file;
    file.open(Path, ios::in);
    while(!file.eof()){
        file >> A >> T >> am;
        Insert(A, T, am);
    }
    file.close();
}

void Cust_Infor::Load_data(char* Path){
    Data *cur = head-> nex;
    fstream file;
    file.open(Path, ios::out | ios::trunc);
    while(cur != head){
        file << endl;
        file    << cur-> Account
                << " "
                << cur-> Type
                << " "
                << cur-> Amount;
        cur = cur-> nex;
    }
    file.close();
}

int main(){
    Cust_Infor A1;
    A1.Read_data("customer_information.txt");
    A1.Show_all();
    printf("  ------------------------------\n\n");
    A1.Read_data("insert.txt");
    A1.Show_all();
    printf("  ------------------------------\n\n");
    A1.Search("search.txt");
    printf("  ------------------------------\n\n");
    A1.Delete("delete.txt");
    A1.Show_all();
    printf("  ------------------------------\n\n");
    A1.Read_data("insert2.txt");
    A1.Show_all();
    A1.Load_data("customer_information_loadout.txt");
    return 0;
}

