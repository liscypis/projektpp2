#ifndef baza_kontaktow_h
#define baza_kontaktow_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

unsigned int NumID; //deklaracja globalnej zmiennej ID
FILE *file;
FILE *file2;
FILE *file3;
struct User_Node
{
    int ID;
    char name[15];
    char surname[20];
    char city[40];
    char street[40];
    unsigned int house_number;
    char postal_code[8];
    char post_office[30];
    struct User_Node *next;
};
struct telephone_nr
{
    unsigned int ID_tel;
    unsigned long int tel_nr;
    struct telephone_nr *next;
};

struct email_node
{
    unsigned int ID_email;
    char em[40];
    struct email_node *next;
};



struct telephone_nr * CreatePhoneList(struct telephone_nr *FrontTelList);
struct telephone_nr * InsertTelNum(struct telephone_nr *FrontTelList);

struct email_node * CreateEmalList(struct email_node *FrontEmailList);
struct email_node * InsertEmail(struct email_node *FrontEmailList);

struct User_Node *create_list(struct User_Node *FrontUserList);
struct User_Node * InsertUser ( struct User_Node *FrontUserList  );

struct User_Node * DeleteUserNode ( struct User_Node *FrontUserList , int data );

struct email_node * DeleteEmailNode ( struct email_node *FrontEmailList , int data );

struct telephone_nr * DeleteTelNode ( struct telephone_nr *FrontTelList , int data );

//wyswietlanie
void print_list(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList);
void print_person(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, int data);
//edycja
void edit_person (struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, unsigned short int data);
//zapis
void save(FILE *file,FILE *file2,FILE *file3, struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList);
//odczyt uzytkownikow
struct User_Node *read(FILE *file, struct User_Node * FrontUserList);
//odczyt telefonow
struct telephone_nr *readTelephone(FILE *file2, struct telephone_nr * FrontTelList);
//odczyt adresow email
struct email_node *readEmail(FILE *file3, struct email_node * FrontEmailList);
// sortowanie listy
void sort_list(struct User_Node *FrontUserList,unsigned int direction,unsigned int what);
// sortowanie pod tel
void sort_list_by_tel(struct telephone_nr *FrontTelList, struct User_Node *FrontUserList,unsigned int direction);
// sortowanie pod emailu
void sort_list_by_email(struct email_node *FrontEmailList, struct User_Node *FrontUserList,unsigned int direction);
//zamiana
void ChangeToupper(char array[]);
//sprawdzanie kodu
int check_postal_code(char array[]);
//sprawdzanie stringow
int check_string(char array[]);
//sprawdzanie poprawnosci emaila
int check_email(char array[]);
//spradza czy jest taki uzytkownic
int user_exist(struct User_Node * FrontUserList,int data);
//sprawdza czy jest taki nr tel
int tel_exist(struct telephone_nr * FrontTelList,int data);
//sprawdza czy jest taki emial
int email_exist(struct email_node * FrontEmailList,char data[]);
//usuwanie listy
void remove_list ( struct User_Node ** temp );
void remove_tel_list ( struct telephone_nr ** temp );
void remove_email_list ( struct email_node ** temp );
//

#endif

