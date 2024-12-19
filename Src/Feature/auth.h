#include "list.h"
#include "mesinkata.h"
#include "user.h"

extern boolean isLoggedIn;
extern User LoggedInUser;

boolean UsernameTaken(List *L,  char *username);

void registerUser(List *listuser);

int login(List *listuser);

void logout();