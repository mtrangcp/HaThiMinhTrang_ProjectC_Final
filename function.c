#include "function.h"

void adminLogin( ){
	int check = 0;
	char adminEmail[] = "test@gmail.com";
	char adminPass[] = "123456";
	
	FILE *fptr = fopen("adminInfo.bin", "wb");
	fwrite(adminEmail, sizeof(char), strlen(adminEmail) + 1, fptr); 
	fwrite(adminPass, sizeof(char), strlen(adminPass) + 1, fptr);
	fclose(fptr);
	
	char inputEmail[30], inputPass[7] ;
	printf("\n\t*** Bank Management System *** ");
	printf("\n\n\t\t ADMIN LOGIN ");
	printf("\n\t============================= ");
	do{
		int test ;
		do {
			test = 0;
			printf("\n\t Enter the Email (11-20 characters, ending with '@gmail.com'): ");
			fgets(inputEmail, sizeof(inputEmail), stdin );
			inputEmail[strcspn(inputEmail, "\n")] = '\0';
		
			if ( strlen(inputEmail) > 25 || strlen(inputEmail) < 11 ){
				printf("\n\tEmail must be between 11-20 characters. Please re-enter!");
				test = 1;continue;
			};
			
		    char *at = strchr(inputEmail, '@');
		    if (at == NULL || strcmp(at + 1, "gmail.com") != 0) {
		        printf("\n\tEmail must end with '@gmail.com'. Please re-enter!");
		        test = 1;
		        continue;
		    }
		}while ( test == 1 );
		
		do {
			fflush(stdin);
			test = 0;
			int index = 0;
    		char ch;
    		
			printf("\t Enter password(6 character): ");
			while (1) {
		        ch = getch(); 
		        if (ch == 13) {  
		            inputPass[index] = '\0';  
		            break;
		        }else if (ch == 8) {  
		            if (index > 0) {
		                index--;                     
		                printf("\b \b");             
		            }
		        }else if (ch == ' ') {  
		            printf("\a");  
		            
		        }else {
		            if (index < sizeof(inputPass) - 1) {  
		                inputPass[index++] = ch;        
		                printf("*");                  
		            }
		        }
		    }
			
			if ( strlen(inputPass) != 6 ){
				printf("\n\tPlease enter correct quantity(6 character)!");
				test = 1 ;
			}
		}while ( test == 1 );
		
		printf("\n\t============================= ");
		FILE *fptrr = fopen("adminInfo.bin", "rb");
		fread(adminEmail, sizeof(char), sizeof(adminEmail), fptrr); 
		fread(adminPass, sizeof(char), sizeof(adminPass), fptrr);
		fclose(fptrr);

		if ( strcmp(adminEmail, inputEmail) == 0 && strcmp(adminPass, inputPass) == 0 ){
			printf("\n\tLogin successful!");
			check = 1;
			break;
		}else{
			printf("\n\tAccount does not exist. Please re-enter!");
		}
	}while( check != 1 );
	getchar();
	system("cls");
}

void guideline( int *choice ){
	printf("\n\t +++++++++  HUONG DAN SU DUNG  ++++++++++ ");
	printf("\n\t Chon 1: Them moi 1 nguoi dung. ");
	printf("\n\t Chon 2: Xem danh sach nguoi dung. ");
	printf("\n\t Chon 3: Xem thong tin chi tiet 1 nguoi dung ");
	printf("\n\t Chon 4: Khoa(Mo khoa) 1 nguoi dung ");
	printf("\n\t Chon 5: Tim kiem 1 nguoi dung ");
	printf("\n\t Chon 6: Sap xep danh sach nguoi dung ");
	printf("\n\t Chon 8: Thong tin ve he thong ");
	printf("\n\t Chon 0: Thoat Menu hien tai, quay lai Menu chinh! ");
	printf("\n\t =============================================== ");
	
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void aboutUs( int *choice ){
	printf("\n\t============================= ");
    printf("\n\t\t++++++ About Us ++++++");
    printf("\n\tThis Bank Management System was developed by Trang.");
    printf("\n\tIt is designed to help manage user accounts efficiently, ");
    printf("\n\toffering features such as adding, searching, and sorting users.");
    printf("\n\tVersion: 1.0");
    printf("\n\tRelease Date: 8/1/2025");
    printf("\n\tContact: test@gmail.com");
    printf("\n\t============================= \n");
    
    char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void adminManagement( User user[], AccountInfo accountInfo[],  int *n ){
	int choice ;
	do{
		printf("\n\t*** Bank Management System *** ");
		printf("\n\n\t\t USER MANAGEMENT MENU ");
		printf("\n\t============================= ");
		printf("\n\t [1] Add A New User. ");
		printf("\n\t [2] Show All Users. ");
		printf("\n\t [3] Show Detail An User. ");
		printf("\n\t [4] Lock (Unlock) An User. ");
		printf("\n\t [5] Find An User. ");
		printf("\n\t [6] Sort user list. ");
		printf("\n\t [7] User Guideline. ");
		printf("\n\t [8] About Us. ");
		printf("\n\t [0] Exit the Program. ");
		printf("\n\t============================= ");
		printf("\n\tEnter The Choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		
		switch( choice){
			case 1:{
				addUser(user, accountInfo, n, &choice );
				break;
			}
			case 2:{
				showAllUser(user, *n, &choice );
				break;
			}
			case 3:{
				detailUser( user, accountInfo, *n, &choice );
				break;
			}
			case 4:{
				lockOrULUser(user, accountInfo, n, &choice );
				break;
			}
			case 5:{
				searchUser(user, *n, &choice);
				break;
			}
			case 6:{
				sortUser(user, *n, &choice );
				break;
			}
			case 7:{
				guideline(&choice);
				break;
			}
			case 8:{
				aboutUs(&choice);
				break;
			}
			case 0:{
				printf("\n\t========= THANK YOU =========");
				printf("\n\t========= See You Soon ======");
				printf("\n\n\t---------------------------------");
				getchar();
				system("cls");
				break;
			}
			default:{
				printf("\n\t Please Choose Correct (0 - 8)!");
				break;
			}
		}	
	}while ( choice != 0 );
}

void trim(char *str) {
    int start = 0, end = strlen(str) - 1;

    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }

    while (end >= start && (str[end] == ' ' || str[end] == '\t')) {
        end--;
    }

    for (int i = 0; i <= end - start; i++) {
        str[i] = str[start + i];
    }
    str[end - start + 1] = '\0'; 
}

void addUser( User user[], AccountInfo accountInfo[],  int *n, int *choice ){
	int check ;
	char inputID[15] ;
	
	printf("\n\t*** Add A New User *** ");
	
	// ID Input
	do{
		check = 0;
		printf("\n\tEnter the ID(10 character): ");
		fgets(inputID, 15, stdin );
		inputID[strcspn(inputID, "\n")] = '\0';
        trim(inputID);
		
		while( strlen(inputID) != 10 ){
			printf("\n\tPlease enter correct quantity(10 character)!");
			printf("\tEnter the ID(10 character): ");
			fgets(inputID, 15, stdin );
			inputID[strcspn(inputID, "\n")] = '\0';
        	trim(inputID);
		};
		
		int i;
		for ( i = 0; i< strlen(inputID); i++){
			if ( !isdigit(inputID[i]) ){
				printf("\n\tID contains only numeric characters. Please re-enter!");
				check = 1;
				break;
			}
		}
		
		if ( *n > 0 ){
			for ( i = 0; i< *n; i++){
				if ( strcmp( inputID, user[i].userId) == 0 ){
					check = 1;
					printf("\n\tID already exists. Please re-enter!");
					break;
				}
			}
		}
	}while( check == 1);
	strcpy(user[*n].userId, inputID );
//	printf("\n\t -%s-", user[*n].userId);
	
	// name
	char inputName[30];
	do{
		check = 0;
		printf("\n\tEnter the name(1-30 characters): ");
		fgets(inputName, sizeof(inputName), stdin );
		inputName[strcspn(inputName, "\n")] = '\0';
		trim(inputName);
		
		if ( strlen(inputName) == 0 ){
			printf("\n\tName cannot be blank. Please re-enter!");
			check = 1; continue;
			
		} else if ( strlen(inputName) > 30 ){
			printf("\n\tPlease enter correct quantity(1-30). Please re-enter!");
			check = 1; continue;
			
		}else if ( isspace(inputName[0]) ){
			printf("\n\tName must start with a letter. Please re-enter!");
			check = 1;continue;
			
		}else if ( isspace(inputName[strlen(inputName) -1]) ){
			inputName[strlen(inputName) -1] = '\0' ;
		}
		
		int i;
		for ( i = 0; i< strlen(inputName); i++){
			if ( !isspace(inputName[i]) && !isalpha(inputName[i] )){
				printf("\n\tNames containing only letters and spaces. Please re-enter!");
				check = 1;
				break;
			}
		}
		
		for ( i = 0; i< strlen(inputName) -1; i++){
			if ( isspace(inputName[i]) && isspace(inputName[i+1] )){
				printf("\n\tNames cannot contain multiple consecutive spaces. Please re-enter!");
				check = 1;
				break;
			}
		}
	}while( check == 1 );
	strcpy(user[*n].name, inputName );
	
	// email
	char inputEmail[30];
	do{
		check = 0;
		printf("\n\tEnter the Email (11-20 characters, ending with '@gmail.com'): ");
		fgets(inputEmail, sizeof(inputEmail), stdin);
    	inputEmail[strcspn(inputEmail, "\n")] = '\0';
		
		if ( strlen(inputEmail) > 25 || strlen(inputEmail) < 11 ){
			printf("\n\tEmail must be between 11-20 characters. Please re-enter!");
			check = 1;continue;
		};
		
	    char *at = strchr(inputEmail, '@');
	    if (at == NULL || strcmp(at + 1, "gmail.com") != 0) {
	        printf("\n\tEmail must end with '@gmail.com'. Please re-enter!");
	        check = 1;
	        continue;
	    }
		int i;
		if ( *n > 0 ){
			for ( i = 0; i< *n; i++){
				if ( strcmp( inputEmail, user[i].email ) == 0 ){
					printf("\n\tEmail already exists. Please re-enter!");
					check = 1;
					break;
				}
			}
		}
	}while ( check == 1 );
	strcpy(user[*n].email, inputEmail );

	// phone
	char inputPhone[11];
	do {
		check = 0;
        printf("\n\tEnter the Phone (10 numeric characters): ");
        fgets(inputPhone, sizeof(inputPhone), stdin);
        inputPhone[strcspn(inputPhone, "\n")] = '\0';

        if (strlen(inputPhone) != 10) {
            printf("\n\tPhone must be exactly 10 numeric characters. Please re-enter!");
            check = 1;
            continue;
        }

        for (int i = 0; i < strlen(inputPhone); i++) {
            if (!isdigit(inputPhone[i])) {
                printf("\n\tPhone must contain only numeric characters. Please re-enter!");
                check = 1;
                break;
            }
        }

        if (*n > 0) {
            for (int i = 0; i < *n; i++) {
                if (strcmp(inputPhone, user[i].phone) == 0) {
                    printf("\n\tPhone already exists. Please re-enter!");
                    check = 1;
                    break;
                }
            }
        }
	}while ( check == 1 );
	strcpy(user[*n].phone, inputPhone );
	
	// gender
	int inputGender;
    do {
        printf("\n\tEnter the Gender: Male(0)/Female(1): ");
        scanf("%d", &inputGender);
        if (inputGender != 0 && inputGender != 1) {
            printf("\n\tInvalid input. Please enter 0 for Male or 1 for Female.");
        }
    } while (inputGender != 0 && inputGender != 1);
    user[*n].gender = inputGender;
	
	// date of birth
	int day, month, year;
	printf("\n\tEnter the Date of birth: ");
	
	do {
		check = 0;
		printf("\n\t\tEnter the Year(1800-2025): ");
		scanf("%d", &year);
		if ( year < 1800 || year> 2025){
			printf("\n\t\tYear must be between 1800 and 2025! ");
			check = 1;
		}
	}while ( check == 1 );
	user[*n].dateOfBirth.year = year;
	
	do {
		check = 0;
		printf("\t\tEnter the Month(1-12): ");
		scanf("%d", &month);
		if ( month < 1 || month> 12 ){
			printf("\n\t\tMonth must be between 1 and 12! ");
			check = 1;
		}
	}while ( check == 1 );
	user[*n].dateOfBirth.month = month;
	
	do {
		check = 0;
		printf("\t\tEnter the Day(1-31): ");
		scanf("%d", &day);
		if ( day < 1 || day> 31 ){
			printf("\n\t\tDay must be between 1 and 31! ");
			check = 1;
		}
	}while ( check == 1 );
	user[*n].dateOfBirth.day = day;
	
	// username
	char inputUsername[10];
	fflush(stdin);
	do{
		check = 0;
		printf("\n\tEnter the Username (1-10 characters): ");
        fgets(inputUsername, sizeof(inputUsername), stdin);
        inputUsername[strcspn(inputUsername, "\n")] = '\0';
        
		if ( strlen(inputUsername) == 0 ){
			printf("\n\tUserName cannot be blank. Please re-enter!");
			check = 1;
			
		} else if ( strlen(inputUsername) > 10 ){
			printf("\n\tUsername must be between 1-10 characters. Please re-enter!");
            check = 1;
		} 

		if ( *n > 0 ){
			int i;
			for ( i = 0; i< *n; i++){
				if ( strcmp( inputUsername, accountInfo[i].username ) == 0 ){
					printf("\n\tUsername already exists. Please re-enter!");
					check = 1;
					break;
				}
			}
		}
	}while( check == 1 );
	
	strcpy(accountInfo[*n].username, inputUsername );
	strcpy(accountInfo[*n].password, inputPhone );
	accountInfo[*n].status = 1;
	accountInfo[*n].balance = 0;
	strcpy(accountInfo[*n].userId, inputID );
	
	(*n)++;

	// ghi du lieu
	FILE *fptr = fopen("user.bin", "wb");
	FILE *fptrAcc = fopen("accountInfo.bin", "wb");
	
	if (fptr != NULL) {
	    fwrite( user, sizeof(User), *n, fptr);
	    fclose(fptr);
	} else {
	    printf("\n\tError writing to file user!");
	    return;
	}
	
	if (fptrAcc != NULL) {
	    fwrite( accountInfo, sizeof(AccountInfo), *n, fptrAcc);
		fclose(fptrAcc);
	} else {
	    printf("\n\tError writing to file account!");
	    return;
	}

	
	printf("\n\t User added successfully!");
	
	// opt
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void showAllUser( User user[], int n, int *choice ){
	if ( n == 0 ){
		printf("\n\tEmpty user list!");
	}else{
		FILE *fptr = fopen("user.bin", "rb");
		int x = fread( user, sizeof(User), n, fptr);
		fclose(fptr);
		printf("\n\t --%d--%d--\n", x, n);
		
		printf("\n\tList User: ");
		printf("\n|===============|================|========|==============|=======================|");
		printf("\n|\tID\t|\tName\t | Gender |\tPhone\t |\tEmail\t\t |");
		printf("\n|===============|================|========|==============|=======================|");
		int i;
		for (i = 0; i< n; i++){
			printf("\n| %s\t| %s\t | %s | %s\t | %s\t |", user[i].userId, user[i].name, user[i].gender ? "Female" : "Male", user[i].phone, user[i].email );	
		}
	}
	
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void searchUser( User user[], int n, int *choice ){
	if ( n == 0 ){
		printf("\n\tEmpty user list!");
	}else{
		char inputName[20];
		printf("\n\t*** Bank Management System *** ");
		printf("\n\n\t\t SEARCH ");
		printf("\n\t============================= ");
		printf("\n\tEnter name to search: ");
		fgets(inputName, 20, stdin);
		inputName[strlen(inputName) -1] = '\0' ;
		
		FILE *fptr = fopen("user.bin", "rb");
		fread(user, sizeof(User), n, fptr);
		fclose(fptr);
		
		int i, check = 0;
		for ( i = 0; i< n; i++){
			if ( strstr(user[i].name, inputName) ){
				check = 1;
				printf("\n| %s\t| %.20s\t| %.10s\t| %.10s\t| %.20d\t|", user[i].userId, user[i].name, user[i].gender, user[i].phone, user[i].email );	
			}
		}
		if ( check == 0 ) printf("\n\tThe name you are looking for does not exist");
	}
	
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void detailUser( User user[], AccountInfo accountInfo[], int n, int *choice ){
	if ( n == 0 ){
		printf("\n\tEmpty user list!");
	}else{
		int check;
		char inputID[15];
		printf("\n\t*** Bank Management System *** ");
		printf("\n\tDETAILED INFORMATION ");
		printf("\n\t============================= ");
		printf("\n\tEnter ID: ");
		fgets(inputID, sizeof(inputID), stdin);
		inputID[strcspn(inputID, "\n")] = '\0';
		
		do{
			check = 0;
			do{
				printf("\tEnter the ID(10 character): ");
				fgets(inputID, 15, stdin );
				inputID[strcspn(inputID, "\n")] = '\0';
	        	trim(inputID);
			}while( strlen(inputID) != 10 );
			
			int i;
			for ( i = 0; i< strlen(inputID); i++){
				if ( !isdigit(inputID[i]) ){
					printf("\n\tID contains only numeric characters. Please re-enter!");
					check = 1;
					break;
				}
			}
		}while( check == 1);
		
		
		FILE *fptr = fopen("user.bin", "rb");
		fread(user, sizeof(User), n, fptr);
		fclose(fptr);
		
		FILE *fptrAcc = fopen("accountInfo.bin", "rb");
		fread(accountInfo, sizeof(AccountInfo), n, fptrAcc);
		fclose(fptrAcc);

		int i;
		for ( i = 0; i< n; i++){
			if ( strcmp( inputID, user[i].userId ) == 0 ){
				check = 1;
				printf("\n\t ID: %s", user[i].userId);
				printf("\n\t Name: %s", user[i].name);
				printf("\n\t Gender: %s", user[i].gender ? "Female" : "Male");
				printf("\n\t Phone: %s", user[i].phone);
				printf("\n\t Email: %s", user[i].email);
				printf("\n\t Username: %s", accountInfo[i].username );
				printf("\n\t Status: %s", accountInfo[i].status ? "Open" : "Locked");
			}
		}
		if ( check == 0 ) printf("\n\tID does not exist!\n");
	}
	
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void lockOrULUser( User user[], AccountInfo accountInfo[], int *n, int *choice ){
	if ( n == 0 ){
		printf("\n\tEmpty user list!");
	}else{
		char inputID[15];
		printf("\n\t*** Lock( Un Lock ) An User *** ");
		printf("\n\tEnter An UserID: ");
		fgets(inputID, sizeof(inputID), stdin);
		inputID[strcspn(inputID, "\n")] = '\0';

		FILE *fptrAcc = fopen("accountInfo.bin", "rb");
		fread(accountInfo, sizeof(AccountInfo), *n, fptrAcc);
		fclose(fptrAcc);

		int i, check = 0;
		for ( i = 0; i< *n; i++){
			if ( strcmp( inputID, user[i].userId ) == 0 ){
				check = 1;
				printf("\n\tOne user was found for id: %s!\n", inputID);
				if ( accountInfo[i].status ){
					printf("\n\tUser'status was open, lock user!\n" );
				}else{
					printf("\n\tUser'status was lock, unlock user!\n" );
				}
				char opt;
				do{
					printf("\n\tYes(y) or No(n)?: " );
					scanf("%c", &opt);
					fflush(stdin);
				}while( opt!='y' && opt!='Y' && opt!='n' && opt!='N' );
				
				if ( opt == 'y' || opt == 'y' ){
					if ( accountInfo[i].status ){
						accountInfo[i].status = 0;
						printf("\n\tLock user successfully!\n" );
					} else{
						accountInfo[i].status = 1;
						printf("\n\tUnlock user successfully!\n" );
					}
				}
				break;
			}
		}
		if ( check == 0 ) printf("\n\tNo user was found for id: %s!\n", inputID);
		
		FILE *fptr = fopen("accountInfo.bin", "wb");
		if (fptrAcc != NULL) {
		    fwrite( accountInfo, sizeof(AccountInfo), (*n) , fptr);
			fclose(fptr);
			printf("\n\tWriting to file account successfully!");
		} else {
		    printf("\n\tError writing to file account!");
		    return;
		}
	}
	
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void sortUser( User user[], int n, int *choice ){
	if ( n == 0 ){
		printf("\n\tEmpty user list!");
	}else{
		printf("\n\t*** Sort Users *** ");
		FILE *fptr = fopen("user.bin", "rb");
		fread(user, sizeof(User), n, fptr);
		fclose(fptr);
		
		printf("\n\t============================= ");
		printf("\n\t [1]. Sort in Ascending Order ");
		printf("\n\t [2]. Sort in Descending Order ");
		printf("\n\t============================= ");
		int opt;
		int i, j;
		do{
			printf("\n\tEnter The Choice(1 or 2): ");
			scanf("%d", &opt);
			fflush(stdin);
			
			if ( opt == 1 ){
				for (i = 0; i< n; i++){
					for ( j = 0 ; j< n-1-i; j++ ){
						if ( user[j].name > user[j+1].name ){
							User temp = user[j];
							user[j] = user[j+1] ;
							user[j+1] = temp ;
						}
					}
				}
			}else if( opt == 2 ){
				for (i = 0; i< n; i++){
					for ( j = 0 ; j< n-1-i; j++ ){
						if ( user[j].name < user[j+1].name ){
							User temp = user[j];
							user[j] = user[j+1] ;
							user[j+1] = temp ;
						}
					}
				}
			}
		}while ( opt != 1 && opt != 2 );
		
		printf("\n\tSort results: ");
		printf("\n|===============|================|=======|===============|=======================|");
		printf("\n|\tID\t|\tName\t |Gender |\tPhone\t |\tEmail\t\t|");
		printf("\n|===============|================|=======|===============|=======================|");
		for (i = 0; i< n; i++){
			printf("\n| %s\t| %s\t | %d\t | %s\t | %s\t |", user[i].userId, user[i].name, user[i].gender, user[i].phone, user[i].email );	
		}
	}
	
	// ghi du lieu
	FILE *fptr = fopen("user.bin", "wb");
	if (fptr != NULL) {
	    fwrite( user, sizeof(User), n, fptr);
	    fclose(fptr);
	    printf("\n\tWriting to file user successfully!");
	} else {
	    printf("\n\tError writing to file user!");
	    return;
	}
	
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void userLogin( User user[], AccountInfo accountInfo[],  int *n ){
	if ( *n == 0 ){
		printf("\n\t User list is empty. Please register with admin before logging in.\n ");
		getchar();
		system("cls");
		return;
	}
	printf("\n\t*** Bank Management System *** ");
	printf("\n\n\t\t USER LOGIN ");
	printf("\n\t============================= ");
	
	int check = 0;
	
	char inputEmail[30], inputPass[11] ;
	int test ;
		
	do {
		test = 0;
		printf("\n\t Enter the Email (11-20 characters, ending with '@gmail.com'): ");
		fgets(inputEmail, sizeof(inputEmail), stdin );
		inputEmail[strcspn(inputEmail, "\n")] = '\0';
	
		if ( strlen(inputEmail) > 25 || strlen(inputEmail) < 11 ){
			printf("\n\tEmail must be between 11-20 characters. Please re-enter!");
			test = 1;continue;
		};
		
	    char *at = strchr(inputEmail, '@');
	    if (at == NULL || strcmp(at + 1, "gmail.com") != 0) {
	        printf("\n\tEmail must end with '@gmail.com'. Please re-enter!");
	        test = 1;
	        continue;
	    }
	}while ( test == 1 );
	
	do {
		fflush(stdin);
		test = 0;
		int index = 0;
		char ch;
		
		printf("\t Enter password(10 character): ");
		while (1) {
	        ch = getch(); 
	        if (ch == 13) {  
	            inputPass[index] = '\0';  
	            break;
	        }else if (ch == 8) {  
	            if (index > 0) {
	                index--;                     
	                printf("\b \b");             
	            }
	        }else if (ch == ' ') {  
	            printf("\a");  
	            
	        }else {
	            if (index < sizeof(inputPass) - 1) {  
	                inputPass[index++] = ch;        
	                printf("*");                  
	            }
	        }
	    }
	}while ( test == 1 );

	
	printf("\n\t============================= ");
	
	FILE *fptr = fopen("user.bin", "rb");
	if ( fptr == NULL ){
		printf("\n\t Cannot open file user!");
		return;
	}
	fread(user, sizeof(User), *n, fptr);
	fclose(fptr);
	
	int i;
	for (i = 0; i< *n; i++){
		printf("\n\t--%s--%s--", inputEmail, user[i].email );
		printf("\n\t--%s--%s--\n", inputPass, user[i].phone );
		if ( strcmp(inputEmail, user[i].email) == 0 && strcmp(inputPass, user[i].phone) == 0 ){
			if ( accountInfo[i].status == 1 ){
				printf("\n\tLogin successful!");
				check = 1;
			}else{
				printf("\n\tThis account has been locked. Cannot log in!");
				check = 2;
			}
			break;
		}
	}
	if ( check == 0 ) printf("\n\tAccount does not exist!");
		
	getchar();
	system("cls");
}

void userMenu( User user[], AccountInfo accountInfo[], int *n ){
	int choice ;
	do{
		printf("\n\t*** Bank Management System *** ");
		printf("\n\n\t\t ACCOUNT MANAGEMENT MENU ");
		printf("\n\t============================= ");
		printf("\n\t [1] Show account information. ");
		printf("\n\t [2] Edit personal information. ");
		printf("\n\t [3] Deposit money into account. ");
		printf("\n\t [4] Withdraw money from account. ");
		printf("\n\t [5] Change password. ");
		printf("\n\t [6] Transfer money to another account. ");
		printf("\n\t [0] Exit the Program. ");
		printf("\n\t============================= ");
		printf("\n\tEnter The Choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		
		switch( choice){
			case 1:{
				showAccInfo(user, accountInfo, *n, &choice );
				break;
			}
			case 2:{
				updateAcc(user,accountInfo, *n, &choice );
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
				
				break;
			}
			case 6:{
				
				break;
			}
			case 0:{
				printf("\n\t========= THANK YOU =========");
				printf("\n\t========= See You Soon ======");
				printf("\n\n\t---------------------------------");
				getchar();
				system("cls");
				break;
			}
			default:{
				printf("\n\t Please Choose Correct (0 - 6)!");
				break;
			}
		}	
	}while ( choice != 0 );
}

void showAccInfo( User user[], AccountInfo accountInfo[],  int n, int *choice){
	int check;
	char inputID[15];
	printf("\n\t*** Bank Management System *** ");
	printf("\n\t ACCOUNT INFORMATION ");
	printf("\n\t============================= ");

	do{
		check = 0;
		do{
			printf("\tEnter the ID(10 character): ");
			fgets(inputID, 15, stdin );
			inputID[strcspn(inputID, "\n")] = '\0';
        	trim(inputID);
		}while( strlen(inputID) != 10 );
		
		int i;
		for ( i = 0; i< strlen(inputID); i++){
			if ( !isdigit(inputID[i]) ){
				printf("\n\tID contains only numeric characters. Please re-enter!");
				check = 1;
				break;
			}
		}
	}while( check == 1);
	
	FILE *fptr = fopen("user.bin", "rb");
	fread(user, sizeof(User), n, fptr);
	fclose(fptr);
	
	FILE *fptrAcc = fopen("accountInfo.bin", "rb");
	fread(accountInfo, sizeof(AccountInfo), n, fptrAcc);
	fclose(fptrAcc);

	int i;
	for ( i = 0; i< n; i++){
		if ( strcmp( inputID, user[i].userId ) == 0 ){
			check = 1;
			printf("\n\t ID: %s", user[i].userId);
			printf("\n\t Name: %s", user[i].name);
			printf("\n\t Gender: %s", user[i].gender ? "Female" : "Male");
			printf("\n\t Phone: %s", user[i].phone);
			printf("\n\t Email: %s", user[i].email);
			printf("\n\t Username: %s", accountInfo[i].username );
			printf("\n\t Balance: %s", accountInfo[i].balance );
			printf("\n\t Status: %s", accountInfo[i].status ? "Open" : "Locked");
			
			
		}
	}
	if ( check == 0 ) printf("\n\tID does not exist!\n");
	
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
}

void updateAcc( User user[], AccountInfo accountInfo[],  int n, int *choice){
	int check;
	char inputID[15];
	printf("\n\t*** Bank Management System *** ");
	printf("\n\t EDIT ACCOUNT INFORMATION ");
	printf("\n\t============================= ");

	do{
		check = 0;
		do{
			printf("\tEnter the ID(10 character): ");
			fgets(inputID, 15, stdin );
			inputID[strcspn(inputID, "\n")] = '\0';
        	trim(inputID);
		}while( strlen(inputID) != 10 );
		
		int i;
		for ( i = 0; i< strlen(inputID); i++){
			if ( !isdigit(inputID[i]) ){
				printf("\n\tID contains only numeric characters. Please re-enter!");
				check = 1;
				break;
			}
		}
	}while( check == 1);
	
	FILE *fptr = fopen("user.bin", "rb");
	fread(user, sizeof(User), n, fptr);
	fclose(fptr);
	
	FILE *fptrAcc = fopen("accountInfo.bin", "rb");
	fread(accountInfo, sizeof(AccountInfo), n, fptrAcc);
	fclose(fptrAcc);
	
	int i, index;
	for ( i = 0; i< n; i++){
		if ( strcmp( inputID, user[i].userId) == 0 ){
			check = 1;
			index = i;
			break;
		}
	}
	if ( check != 1 ){
		printf("\n\tID does not exist!\n");
	}else{
		char inputName[30];
		do{
			check = 0;
			printf("\n\tEnter the name(1-30 characters): ");
			fgets(inputName, sizeof(inputName), stdin );
			inputName[strcspn(inputName, "\n")] = '\0';
			trim(inputName);
			
			if ( strlen(inputName) == 0 ){
				printf("\n\tName cannot be blank. Please re-enter!");
				check = 1; continue;
				
			} else if ( strlen(inputName) > 30 ){
				printf("\n\tPlease enter correct quantity(1-30). Please re-enter!");
				check = 1; continue;
				
			}else if ( isspace(inputName[0]) ){
				printf("\n\tName must start with a letter. Please re-enter!");
				check = 1;continue;
				
			}else if ( isspace(inputName[strlen(inputName) -1]) ){
				inputName[strlen(inputName) -1] = '\0' ;
			}
			
			int i;
			for ( i = 0; i< strlen(inputName); i++){
				if ( !isspace(inputName[i]) && !isalpha(inputName[i] )){
					printf("\n\tNames containing only letters and spaces. Please re-enter!");
					check = 1;
					break;
				}
			}
			
			for ( i = 0; i< strlen(inputName) -1; i++){
				if ( isspace(inputName[i]) && isspace(inputName[i+1] )){
					printf("\n\tNames cannot contain multiple consecutive spaces. Please re-enter!");
					check = 1;
					break;
				}
			}
		}while( check == 1 );
		strcpy(user[index].name, inputName );
		
		// email
		char inputEmail[30];
		do{
			check = 0;
			printf("\n\tEnter the Email (11-20 characters, ending with '@gmail.com'): ");
			fgets(inputEmail, sizeof(inputEmail), stdin);
	    	inputEmail[strcspn(inputEmail, "\n")] = '\0';
			
			if ( strlen(inputEmail) > 25 || strlen(inputEmail) < 11 ){
				printf("\n\tEmail must be between 11-20 characters. Please re-enter!");
				check = 1;continue;
			};
			
		    char *at = strchr(inputEmail, '@');
		    if (at == NULL || strcmp(at + 1, "gmail.com") != 0) {
		        printf("\n\tEmail must end with '@gmail.com'. Please re-enter!");
		        check = 1;
		        continue;
		    }
			int i;
			for ( i = 0; i< n; i++){
				if ( strcmp( inputEmail, user[i].email ) == 0 ){
					printf("\n\tEmail already exists. Please re-enter!");
					check = 1;
					break;
				}
			}
		}while ( check == 1 );
		strcpy(user[index].email, inputEmail );
	
		// phone
		char inputPhone[11];
		do {
			check = 0;
	        printf("\n\tEnter the Phone (10 numeric characters): ");
	        fgets(inputPhone, sizeof(inputPhone), stdin);
	        inputPhone[strcspn(inputPhone, "\n")] = '\0';
	
	        if (strlen(inputPhone) != 10) {
	            printf("\n\tPhone must be exactly 10 numeric characters. Please re-enter!");
	            check = 1;
	            continue;
	        }
	
	        for (int i = 0; i < strlen(inputPhone); i++) {
	            if (!isdigit(inputPhone[i])) {
	                printf("\n\tPhone must contain only numeric characters. Please re-enter!");
	                check = 1;
	                break;
	            }
	        }
	
	        for (int i = 0; i < n; i++) {
                if (strcmp(inputPhone, user[i].phone) == 0) {
                    printf("\n\tPhone already exists. Please re-enter!");
                    check = 1;
                    break;
                }
            }
		}while ( check == 1 );
		strcpy(user[index].phone, inputPhone );
		
		// gender
		int inputGender;
	    do {
	        printf("\n\tEnter the Gender: Male(0)/Female(1): ");
	        scanf("%d", &inputGender);
	        if (inputGender != 0 && inputGender != 1) {
	            printf("\n\tInvalid input. Please enter 0 for Male or 1 for Female.");
	        }
	    } while (inputGender != 0 && inputGender != 1);
	    user[index].gender = inputGender;
		
		// date of birth
		int day, month, year;
		printf("\n\tEnter the Date of birth: ");
		
		do {
			check = 0;
			printf("\n\t\tEnter the Year(1800-2025): ");
			scanf("%d", &year);
			if ( year < 1800 || year> 2025){
				printf("\n\t\tYear must be between 1800 and 2025! ");
				check = 1;
			}
		}while ( check == 1 );
		user[index].dateOfBirth.year = year;
		
		do {
			check = 0;
			printf("\t\tEnter the Month(1-12): ");
			scanf("%d", &month);
			if ( month < 1 || month> 12 ){
				printf("\n\t\tMonth must be between 1 and 12! ");
				check = 1;
			}
		}while ( check == 1 );
		user[index].dateOfBirth.month = month;
		
		do {
			check = 0;
			printf("\t\tEnter the Day(1-31): ");
			scanf("%d", &day);
			if ( day < 1 || day> 31 ){
				printf("\n\t\tDay must be between 1 and 31! ");
				check = 1;
			}
		}while ( check == 1 );
		user[index].dateOfBirth.day = day;
		
		// username
		char inputUsername[10];
		fflush(stdin);
		do{
			check = 0;
			printf("\n\tEnter the Username (1-10 characters): ");
	        fgets(inputUsername, sizeof(inputUsername), stdin);
	        inputUsername[strcspn(inputUsername, "\n")] = '\0';
	        
			if ( strlen(inputUsername) == 0 ){
				printf("\n\tUserName cannot be blank. Please re-enter!");
				check = 1;
				
			} else if ( strlen(inputUsername) > 10 ){
				printf("\n\tUsername must be between 1-10 characters. Please re-enter!");
	            check = 1;
			} 
			int i;
			for ( i = 0; i< n; i++){
				if ( strcmp( inputUsername, accountInfo[i].username ) == 0 ){
					printf("\n\tUsername already exists. Please re-enter!");
					check = 1;
					break;
				}
			}
	
		}while( check == 1 );
		strcpy(accountInfo[index].username, inputUsername );
	
		// ghi du lieu
		FILE *fptr = fopen("user.bin", "wb");
		FILE *fptrAcc = fopen("accountInfo.bin", "wb");
		
		if (fptr != NULL) {
		    fwrite( user, sizeof(User), n, fptr);
		    fclose(fptr);
		} else {
		    printf("\n\tError writing to file user!");
		    return;
		}
		
		if (fptrAcc != NULL) {
		    fwrite( accountInfo, sizeof(AccountInfo), n, fptrAcc);
			fclose(fptrAcc);
		} else {
		    printf("\n\tError writing to file account!");
		    return;
		}
		printf("\n\t Edit account information successfully!");
	}
	
	
	char option;
	do{
		fflush(stdin);
		printf("\n\n\t Go back(b) or Exit(0) or Continue(c) ?: ");
		scanf("%c", &option);
	}while( option != 'b' && option != 'B' && option != '0' && option != 'c' && option != 'C' );
	
	if ( option == 'b' || option == 'B' ){
		*choice = 0;
	}else if (option == '0' ){
		printf("\n\t You choose exit!");
		printf("\n\t========= THANK YOU =========");
		printf("\n\t========= See You Soon ======");
		printf("\n\n\t---------------------------------");
		exit(0);
	}else{
		printf("\n\t Please continue using the function!");
	}
	getchar();
	system("cls");
	
}

