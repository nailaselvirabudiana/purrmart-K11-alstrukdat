#include "../ADT/list/list.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "user.h"

extern boolean isLoggedIn;
extern User LoggedInUser;

boolean UsernameTaken(List *L,  char *username);

void registerUser(List *listuser);

int login(List *listuser);

void logout();