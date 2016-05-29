#include "baza_kontaktow.h"


struct telephone_nr * CreatePhoneList(struct telephone_nr *FrontTelList)
{
    struct telephone_nr *new_node = (struct telephone_nr *)malloc (sizeof (struct telephone_nr));
    unsigned long int NrTel;
    if (NULL != new_node)
    {
        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        puts("Podaj numer telefonu:");
        while(scanf("%lu", &NrTel) != 1 || NrTel<1 || NrTel>999999999) //dopóki nie uda się wczytać
        {
            puts("Niepoprawny format, podaj numer tel jeszcze raz:");
            fflush(stdin);
        }
        new_node->ID_tel=NumID;
        new_node->tel_nr=NrTel;// przypisanie wartosci
        new_node ->next=NULL;
    }
    FrontTelList=new_node;
    return FrontTelList;
}

struct telephone_nr * InsertTelNum(struct telephone_nr *FrontTelList)
{
    struct telephone_nr *new_node = (struct telephone_nr *)malloc (sizeof (struct telephone_nr));
    struct telephone_nr *wsk=FrontTelList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    unsigned long int NrTel;
    while (wsk->next != NULL)
    {
        wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
    }
    if (NULL != new_node)
    {
        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        puts("Podaj numer telefonu:");
        wsk->next = new_node;  // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru
        while(scanf("%lu", &NrTel) != 1 || NrTel<1 || NrTel>999999999) //dopóki nie uda się wczytać
        {
            puts("Niepoprawny format, podaj numer tel jeszcze raz:");
            fflush(stdin);
        }
        new_node->ID_tel=NumID;
        new_node->tel_nr=NrTel;// przypisanie wartosci
        new_node->next=NULL; //przypisanie wskaznikowi next ostatniego elementu na liscie wartosci NULL
    }
    return FrontTelList;
}


struct email_node * CreateEmalList(struct email_node *FrontEmailList)
{
    struct email_node *new_node = (struct email_node *)malloc (sizeof (struct email_node));
    if (NULL != new_node)
    {
        int good=1;
        char email[40];
        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        puts("Podaj email:");
        scanf("%s",email);
        good=check_email(email);
        if(good==0)
            puts("Wprowadzone email jest niepoprawny");
        }while(good==0);
        ChangeToupper(email); //zamiena na duże litery
        strcpy(new_node->em, email);
        new_node->ID_email=NumID;
        new_node ->next=NULL;
    }
    FrontEmailList=new_node;
    return FrontEmailList;
}

struct email_node * InsertEmail(struct email_node *FrontEmailList)
{
    struct email_node *new_node = (struct email_node *)malloc (sizeof (struct email_node));
    struct email_node *wsk;
    wsk=FrontEmailList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy

    while (wsk->next != NULL)
    {
        wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
    }
    if (NULL != new_node)
    {   int good=1;
        char email[40];
        wsk->next = new_node;  // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        puts("Podaj email:");
        scanf("%s",email);
        good=check_email(email);
        if(good==0)
            puts("Wprowadzone email jest niepoprawny");
        }while(good==0);
        ChangeToupper(email); //zamiena na duże litery
        strcpy(new_node->em, email);
        new_node->ID_email=NumID;
        new_node->next=NULL; //przypisanie wartosci NULL dla ostatniego elementu listy
    }
    return FrontEmailList;
}

struct User_Node *create_list(struct User_Node *FrontUserList)
{
    struct User_Node *new_node = (struct User_Node *)malloc (sizeof (struct User_Node));
    if (NULL != new_node)
    {
        char pom[20];
        unsigned int good=1,HouseNr;
        new_node->ID = NumID;

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
       do{
        printf("Podaj imie: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzone imie jest niepoprawne");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->name,pom);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        printf("Podaj nazwisko: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzone nazwisko jest niepoprawne");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->surname,pom);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        printf("Podaj miasto: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzone miasto jest niepoprawne");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->city,pom);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        printf("Podaj ulice: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzona nazwa ulicy jest niepoprawna");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->street,pom);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        printf("Podaj numer domu: \n");
        while(scanf("%u", &HouseNr) != 1) //dopóki nie uda się wczytać
        {
            puts("Niepoprawny format, podaj numer domu jeszcze raz:");
        fflush(stdin);
        }
        new_node->house_number=HouseNr;

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do
        {
        printf("Podaj kod pocztowy (00-000):\n");
        scanf("%s",pom);
        good=check_postal_code(pom);
        if(good==0)
        puts("Wprowadzony kod jest nie poprawny");
        strcpy(new_node->postal_code,pom);
        }while(good==0);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        printf("Podaj poczte: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzona nazwa poczty jest niepoprawna");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->post_office,pom);


        new_node -> next = NULL ;
        FrontUserList=new_node;

    }
    return FrontUserList;
}

struct User_Node * InsertUser ( struct User_Node *FrontUserList  )
{
    struct User_Node * new_node = ( struct User_Node *)malloc ( sizeof ( struct User_Node ));
    struct User_Node *wsk=FrontUserList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    while (wsk->next != NULL)
    {
        wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
    }
    if ( NULL != new_node )
    {
        char pom[20];
        unsigned int good=1,HouseNr;
        wsk->next = new_node; // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru
        new_node->ID = ++NumID;

         system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
       do{
        printf("Podaj imie: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzone imie jest niepoprawne");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->name,pom);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        printf("Podaj nazwisko: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzone nazwisko jest niepoprawne");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->surname,pom);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        printf("Podaj miasto: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzone miasto jest niepoprawne");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->city,pom);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        printf("Podaj ulice: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzona nazwa ulicy jest niepoprawna");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->street,pom);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        printf("Podaj numer domu: \n");
        while(scanf("%u", &HouseNr) != 1) //dopóki nie uda się wczytać
        {
            puts("Niepoprawny format, podaj numer domu jeszcze raz:");
        fflush(stdin);
        }
        new_node->house_number=HouseNr;

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do
        {
        printf("Podaj kod pocztowy (00-000):\n");
        scanf("%s",pom);
        good=check_postal_code(pom);
        if(good==0)
        puts("Wprowadzony kod jest nie poprawny");
        strcpy(new_node->postal_code,pom);
        }while(good==0);

        system("cls");
        puts("#### DODAWANIE UZYTWONIKA ####");
        do{
        printf("Podaj poczte: \n");
        scanf("%s",pom);
        good=check_string(pom);
        if(good==0)
            puts("Wprowadzona nazwa poczty jest niepoprawna");
        }while(good==0);
        ChangeToupper(pom);
        strcpy(new_node->post_office,pom);

        new_node -> next = NULL ;
    }
    return FrontUserList;
}
struct User_Node * DeleteUserNode ( struct User_Node *FrontUserList , int data )
{
    if ( NULL == FrontUserList )
        return NULL ;
    struct User_Node * prev = FrontUserList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy
    struct User_Node * temp = FrontUserList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy

    while(temp!=NULL)
    {
        if(temp-> ID == data)
            //usuwamy pierwszy element listy
            if(temp==FrontUserList)
            {
                FrontUserList=FrontUserList->next; // zapisane adredu nastepnego elementu (drugiego)
                free(temp);
                temp = FrontUserList;
                prev = FrontUserList;
            }
        //usuwamy element ze srodka listy lub konca
            else
            {
                prev -> next = temp -> next; //wskaznikowi poprzedniego elementu przypisujemy adres nastepnego
                free(temp); //
                temp = prev->next; //przechodzi do nastepnego elementu listy
            }
        else
        {
            prev = temp; // przechowuje wartosc temp, czyli poprzednia
            temp = temp -> next; // przechodzi do nastepnego elementu
        }

    }
    return FrontUserList;
}
struct email_node * DeleteEmailNode ( struct email_node *FrontEmailList , int data )
{
    if ( NULL == FrontEmailList )
        return NULL ;
    struct email_node * prev = FrontEmailList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy
    struct email_node * temp = FrontEmailList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy

    while(temp!=NULL)
    {
        if(temp-> ID_email == data)
            //usuwamy pierwszy element listy
            if(temp==FrontEmailList)
            {
                FrontEmailList=FrontEmailList->next; // zapisane adredu nastepnego elementu (drugiego)
                free(temp);
                temp = FrontEmailList;
                prev = FrontEmailList;
            }
        //usuwamy element ze srodka listy lub konca
            else
            {
                prev -> next = temp -> next; //wskaznikowi poprzedniego elementu przypisujemy adres nastepnego
                free(temp); //
                temp = prev->next; //przechodzi do nastepnego elementu listy
            }
        else
        {
            prev = temp; // przechowuje wartosc temp, czyli poprzednia
            temp = temp -> next; // przechodzi do nastepnego elementu
        }

    }
    return FrontEmailList;
}
struct telephone_nr * DeleteTelNode ( struct telephone_nr *FrontTelList , int data )
{
    if ( NULL == FrontTelList )
        return NULL ;
    struct telephone_nr * prev = FrontTelList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy
    struct telephone_nr * temp = FrontTelList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy

    while(temp!=NULL)
    {
        if(temp-> ID_tel == data)
            //usuwamy pierwszy element listy
            if(temp==FrontTelList)
            {
                FrontTelList=FrontTelList->next; // zapisane adredu nastepnego elementu (drugiego)
                free(temp);
                temp = FrontTelList;
                prev = FrontTelList;
            }
        //usuwamy element ze srodka listy lub konca
            else
            {
                prev -> next = temp -> next; //wskaznikowi poprzedniego elementu przypisujemy adres nastepnego
                free(temp); //
                temp = prev->next; //przechodzi do nastepnego elementu listy
            }
        else
        {
            prev = temp; // przechowuje wartosc temp, czyli poprzednia
            temp = temp -> next; // przechodzi do nastepnego elementu
        }

    }
    return FrontTelList;
}
void remove_list ( struct User_Node ** temp )
{
    struct User_Node * next = NULL ;
    while ( NULL != * temp )
    {
        next = (* temp ) ->next ;
        free (* temp );
        * temp = next ;
    }
}
void remove_tel_list ( struct telephone_nr ** temp )
{
    struct telephone_nr * next = NULL ;
    while ( NULL != * temp )
    {
        next = (* temp ) ->next ;
        free (* temp );
        * temp = next ;
    }
}
void remove_email_list ( struct email_node ** temp )
{
    struct email_node * next = NULL ;
    while ( NULL != * temp )
    {
        next = (* temp ) ->next ;
        free (* temp );
        *temp = next ;
    }
}

