#include "block.c"
#include "transaction.c"
#include "user.c"
#include "attack_1.c"
#include <ctype.h>

int main()
{
    char buf;
    int i;
    char choice[100] = {'\0'};
    system("clear");
    srand(time(NULL));
    initHash();
    printf("\n\e[0;92m                                                                BITCOIN\n");
    printf("                                                               ---------\n");
    printf("                                                      Project by group number 14\n\n");
user_interface:
    printf("\033[0mPlease enter a number to continue!\n\n");
    printf("\033[31menter \"add user\" to create a add user to the system\n");
    printf("enter \"load users\" to load users\n");
    printf("enter \"transaction\" to do a transaction\n");
    printf("enter \"transaction history\" to display transcation history\n");
    printf("enter \"attack\" to attack a block\n");
    printf("enter \"validate\" to validate block chain\n");
    printf("enter \"clear\" to clear screen\n");
    printf("enter \"exit\" to exit");
    printf("\033[0m\n\n");
    scanf("%[^\n]", choice);
    scanf("%c", &buf);

    for (i = 0; i < 100, choice[i] != '\0';)
    {
        /*if (choice[i] == '\n')
        {
            choice[i] = '\0';
        }
        else*/
        if (choice[i] >= 'A' && choice[i] <= 'Z')
            choice[i] = tolower(choice[i]);
        i++;
    }
    if (strcmp(choice, "add user") == 0)
    {
        makeUser();
        scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }

    else if (strcmp(choice, "load users") == 0)
    {
        printUsers();
        //scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }

    else if (strcmp(choice, "transaction") == 0)
    {
        transaction();
        scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "transaction history") == 0)
    {
        printHistory();
        scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "attack") == 0)
    {
        attack();
        scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "validate") == 0)
    {
        //validate_block_chain();
        //scanf("%c", &buf);
        goto user_interface;
    }
    else if (strcmp(choice, "clear") == 0)
    {
        system("clear");
        goto user_interface;
    }
    else if (strcmp(choice, "exit") == 0)
    {
        system("clear");
        printf("\n\e[0;92m                                                             THANK YOU!\n\n");
        return (0);
    }
    else
    {
        printf("\n\033[31m                                             invalid choice! Please enter a valid choice\n\n");
        goto user_interface;
    }
}