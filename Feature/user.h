#ifndef __USER__
#define __USER__

#define Max 50

typedef struct{
    char Nama[Max];
    char Password[Max];
    int Uang;
}User;

void AddMoney(User *u, int money){
    u->Uang += money;
}

#endif