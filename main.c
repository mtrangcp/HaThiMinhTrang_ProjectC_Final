#include "function.h"

//    admin login
//	email: test@gmail.com
//	pass: 123456

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choiceRole;
	int numberOfUsers = 0;
	User user[100];
	AccountInfo accountInfo[100];

	FILE *fptrU = fopen("user.bin", "rb");
	numberOfUsers = fread( &user , sizeof(User), 100, fptrU );
	fclose(fptrU);
	printf("\n\t --%d--", numberOfUsers );

	printf("\n\tList User: ");
	printf("\n|===============|================|========|==============|=======================|");
	printf("\n|\tID\t|\tName\t | Gender |\tPhone\t |\tEmail\t\t |");
	printf("\n|===============|================|========|==============|=======================|");
	int i;
	for (i = 0; i< numberOfUsers; i++){
		printf("\n| %s\t| %s\t | %s | %s\t | %s\t |", user[i].userId, user[i].name, user[i].gender ? "Female" : "Male", user[i].phone, user[i].email );	
	}
	printf("\n\n");
	
	do{
		printf("\n\t*** Bank Management System *** ");
		printf("\n\n\t\t CHOOSE YOUR ROLE ");
		printf("\n\t============================= ");
		printf("\n\t [1] Admin. ");
		printf("\n\t [2] User. ");
		printf("\n\t [0] Exit the Program. ");
		printf("\n\t============================= ");
		printf("\n\tEnter The Choice: ");
		scanf("%d", &choiceRole);
		fflush(stdin);
		
		switch ( choiceRole ){
			case 1: {
				adminLogin();
				adminManagement(user, accountInfo, &numberOfUsers );
				break;
			}
			case 2: {
				userLogin( user,accountInfo, &numberOfUsers );
				userMenu( user, accountInfo, &numberOfUsers );
				break;
			}
			case 0: {
				printf("\n\t========= THANK YOU =========");
				printf("\n\t========= See You Soon ======");
				printf("\n\n\t---------------------------------");
				break;
			}
			default:{
				printf("\n\t Please Choose Correct (0 - 2)!");
				break;
			}
		}
	}while ( choiceRole != 0 );

	return 0;
}

