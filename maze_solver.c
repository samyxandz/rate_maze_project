#include <stdio.h>

int main(void)
{   char choice;
    int maze[6][6];
    int inbuilt[6][6]={{0,1,1,0,0,0},{}};
      int inbuilt[13][13]={{0,1,1,0,0,0},{}};
    //starting the game
    printf("\twelcome to The Maze game\n \n");
    choice:
    printf("Would You like to use Inbuilt maze or Enter your own maze?\nPlease enter I to use Inbuilt and please enter O to use own maze \n"    );
    scanf("%c",&choice);
    if(choice=='I'){
        printf("Great you use the Inbuilt maze\n");
    }
    if(choice=='O'){
        printf("Great you use the Own maze\n");
    }

}