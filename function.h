#include "datatype.h"

void userLogin( User user[], AccountInfo accountInfo[], int *n);
void adminLogin(  );
void adminManagement( User user[], AccountInfo accountInfo[], int *n );

void userMenu( User user[], AccountInfo accountInfo[], int *n );

void addUser( User user[], AccountInfo accountInfo[],  int *n, int *choice);
void showAllUser( User user[], int n, int *choice);
void searchUser( User user[], int n, int *choice);
void detailUser( User user[], AccountInfo accountInfo[], int n, int *choice);
void lockOrULUser( User user[], AccountInfo accountInfo[], int *n, int *choice );
void sortUser( User user[], int n, int *choice );

void guideline( int *choice );
void aboutUs( int *choice );

void showAccInfo( User user[], AccountInfo accountInfo[],  int n, int *choice);
void updateAcc( User user[], AccountInfo accountInfo[],  int n, int *choice);




