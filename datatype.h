#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct{
	int month ;
	int day;
	int year;
}Date;

typedef struct{
	char transferId[11] ;
	char receivingId[11] ;
	double amount ;
	char type[11] ; // deposit / transfer / withdraw
	char message[51] ;
	Date transactionDate ;
} Transaction;

typedef struct{
	char userId[11] ;
	float balance ;
	bool status ; // ( 1: open ; 0: lock )
	char username[11] ;
	char password[11] ;
	Transaction transactionHistory[] ;
} AccountInfo;

typedef struct{
	char userId[11] ;
	char name[31] ;
	Date dateOfBirth ;
	bool gender ;  // Male(0)/Female(1)
	char phone[11] ; 
	char email[50] ;
} User;



