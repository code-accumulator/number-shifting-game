#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void table_array();//Draw game board for random number generated array
void static_table_array ();//Draw game board for statically number generated array
void gotoxy (int ,int );//To set the cursour position in the programm
void int_character_displai(int, int);//Convert generated random number to character to display in the game board;(RESPONSIBLE TO GENERATE DYNAMIC CHARACTER)
void static_int_character_displai(int i, int j);//Convert generated random number to character to display in the game board(RESPONSIBLE TO GENERATE STATIC CHARACTER)
void dynamic_control();//navigaation for players
void display();//Responsible to display starting page fo the programm
void random_number();//Generate random number for an array
void rule();//To display the rule of the game
int wincheck();//To check wheter the player has won the game or not
void warning();//Give warning if player is lack of life
void display_loose();//Escution start when players loose the game
void display_win();//Excutin start when players win the game

int array[4][4];
int static_array[4][4];
int count=20;
char game_stater = ' ';






int main()
{
    system("cls");


    while(game_stater)
    {
        if (game_stater == 27 )
            exit(0);
        count = 20;
        display();
        system("cls");
        rule();
        system("cls");
        random_number();
        int i,j,m=1,n=1,row=3,column=3;
        int swap_1,swap_2,temp_row,temp_column;
        char ch;
        

        do
        {
            dynamic_control();
            table_array();
            warning();

            temp_row = row;
            temp_column = column;
            swap_1 = array[temp_row][temp_column];
            ch = getch();
            Beep(80,300);

            switch (ch)
            {
            case 'a'://left shift
                if ((column <= 3 && column > 0) )
                    column --;
                    Sleep(300);
                    count --;
                break;
            case 'd'://right shift
                if(column < 3 && column >= 0 )
                    column ++; 
                    Sleep(300);
                    count --;   
                break;
            case 'w'://up shift
                if (row <= 3 && row > 0)
                    row--;
                    Sleep(300);
                    count --;
                break;
            case 's'://down shift
                if (row < 3 && row >= 0)
                    row++;
                    Sleep(300);
                    count --;
                break;
            case 'l'://
                    if(count <= 17)
                        count +=3;
                    else
                    {
                        printf(YEL"\n\n\n\t\t\t\t\t\t\tYOU HAVE EXCEED THE LIFE LIMIT"RESET);
                        Sleep(1000);
                    }
                        
                    
                break;
            
            case 27:
                exit(0);
                break;
            }
            system("cls");
            swap_2 = array[row][column];//value
            array[row][column] = swap_1;
            array[temp_row][temp_column] = swap_2;

            if (wincheck())
            {
                 display_win();
            }
        
            //printf("\n\nrow = %d",row);
            //printf("\n\ncolumn = %d",column);
        } while (count);
        display_loose();


    }//End of the  while loop
    

    


    return 0;
}














//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (1)->to generate table along with array
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------


void table_array ()
{
    int a=0,i,j;
    printf("\n\n\n");

    for ( i = 1; i <= 17; i++)
    {
        printf(YEL"\t\t\t\t\t\t\t" RESET);  
        for ( j = 1; j <= 45; j++)
        {
            //#########################################################################
            //                           starting of program to print number in the box            
            if((i == 3 || i == 7 || i == 11 || i == 15) && ((j == 6) || (j == 17) || (j == 28) || (j == 39)))
            {
                switch (a)
                {
                    case 0:
                        int_character_displai(0, 0);
                        a++;
                        break;
                    case 1:
                        int_character_displai(0, 1);
                        a++;
                        break;
                    case 2:
                        int_character_displai(0, 2);
                        a++;
                        break;
                    case 3:
                        int_character_displai(0, 3);
                        a++;
                        break;
                    case 4:
                        int_character_displai(1, 0);
                        a++;
                        break;
                    case 5:
                        int_character_displai(1, 1);
                        a++;
                        break;
                    case 6:
                        int_character_displai(1, 2);
                        a++;
                        break;
                    case 7:
                        int_character_displai(1, 3);
                        a++;
                        break;
                    case 8:
                        int_character_displai(2, 0);
                        a++;
                        break;
                    case 9:
                        int_character_displai(2, 1);
                        a++;
                        break;
                    case 10:
                        int_character_displai(2, 2);
                        a++;
                        break;
                    case 11:
                        int_character_displai(2, 3);
                        a++;
                        break;
                    case 12:
                        int_character_displai(3, 0);
                        a++;
                        break;
                    case 13:
                        int_character_displai(3, 1);
                        a++;
                        break;
                    case 14:
                        int_character_displai(3, 2);
                        a++;
                        break;
                    case 15:
                        
                        int_character_displai(3, 3);
                        a++;
                        break;
                }
                //######################################################################
                //                           ending of program to print number in the box 
            }
            if((i == 3 || i == 7 || i == 11 || i == 15) && ((j >= 6 && j <= 7) || (j >= 17 && j <= 18) || (j >= 28 && j <= 29) ||  (j >= 39 && j <= 40)))
                continue;
            
            if (((i == 1 || i == 5) ||(i == 9 || i == 13 ) || i == 17 ) && ((j >= 2 && j <= 11) || (j >= 13 && j <= 22) || (j >= 24 && j <= 33) || (j >= 35 && j <= 44)) )
            {
                printf(CYN"-"RESET);
            }
            else if (((j == 1 || j == 12) ||(j == 23 || j == 34) || j == 45) && ( (i >= 2 && i <= 4) || (i >= 6 && i <= 8) || (i >= 10 && i <= 12) || (i >= 14 && i <= 16) ) ) 
            {
                printf(CYN"|"RESET);
            }
             else
            printf(" ");
            
        }///End of the second for loop
        printf("\n");
        
        
    }/// End of the first for loop
    
}

//PART -- 2
//PART -- 2
//PART -- 2
void static_table_array ()
{
    int a=0,i,j;
    printf("\n");

    for ( i = 1; i <= 17; i++)
    {
        printf("\t\t\t\t\t\t\t");
        for ( j = 1; j <= 45; j++)
        {
            //#########################################################################
            //                           starting of program to print number in the box            
            if((i == 3 || i == 7 || i == 11 || i == 15) && ((j == 6) || (j == 17) || (j == 28) || (j == 39)))
            {
                switch (a)
                {
                    case 0:
                        static_int_character_displai(0, 0);
                        a++;
                        break;
                    case 1:
                        static_int_character_displai(0, 1);
                        a++;
                        break;
                    case 2:
                        static_int_character_displai(0, 2);
                        a++;
                        break;
                    case 3:
                        static_int_character_displai(0, 3);
                        a++;
                        break;
                    case 4:
                        static_int_character_displai(1, 0);
                        a++;
                        break;
                    case 5:
                        static_int_character_displai(1, 1);
                        a++;
                        break;
                    case 6:
                        static_int_character_displai(1, 2);
                        a++;
                        break;
                    case 7:
                        static_int_character_displai(1, 3);
                        a++;
                        break;
                    case 8:
                        static_int_character_displai(2, 0);
                        a++;
                        break;
                    case 9:
                        static_int_character_displai(2, 1);
                        a++;
                        break;
                    case 10:
                        static_int_character_displai(2, 2);
                        a++;
                        break;
                    case 11:
                        static_int_character_displai(2, 3);
                        a++;
                        break;
                    case 12:
                        static_int_character_displai(3, 0);
                        a++;
                        break;
                    case 13:
                        static_int_character_displai(3, 1);
                        a++;
                        break;
                    case 14:
                        static_int_character_displai(3, 2);
                        a++;
                        break;
                    case 15:
                        
                        static_int_character_displai(3, 3);
                        a++;
                        break;
                }
                //######################################################################
                //                           ending of program to print number in the box 
            }
            if((i == 3 || i == 7 || i == 11 || i == 15) && ((j >= 6 && j <= 7) || (j >= 17 && j <= 18) || (j >= 28 && j <= 29) ||  (j >= 39 && j <= 40)))
                continue;
            
            if (((i == 1 || i == 5) ||(i == 9 || i == 13 ) || i == 17 ) && ((j >= 2 && j <= 11) || (j >= 13 && j <= 22) || (j >= 24 && j <= 33) || (j >= 35 && j <= 44)) )
            {
                printf(GRN"-"RESET);
            }
            else if (((j == 1 || j == 12) ||(j == 23 || j == 34) || j == 45) && ( (i >= 2 && i <= 4) || (i >= 6 && i <= 8) || (i >= 10 && i <= 12) || (i >= 14 && i <= 16) ) ) 
            {
                printf(GRN"|"RESET);
            }
             else
            printf(" ");
            
        }///End of the second for loop
        printf("\n");
        
        
    }/// End of the first for loop
    
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (2) ->to align the content at the terminal
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------

void gotoxy (int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}



//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (3) ->To display digit as character
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------

void int_character_displai(int i, int j)
{

    if( array[i][j] != 32)
    {

        if(array[i][j] <= 9)
        {
            char c_1;
            c_1 = array[i][j] + '0';
            //printf("%c ",c_1);
            printf("%c ",c_1);
        }
        else
        {
            char c_1, c_2;
            int d1,d2;
            d1 = array[i][j] % 10;
            d2 = array[i][j] / 10;
            c_1 = d1  + '0';
            c_2 = d2 + '0';
            printf("%c",c_2);
            printf("%c",c_1);
        }    
    } 
    else
    {
        char c_1, c_2;
        c_1 = ' ';
        c_2 = ' ';
        printf("%c",c_2);
        printf("%c",c_1);


    }

}
//PART -- 2
void static_int_character_displai(int i, int j)
{

    if( static_array[i][j] != 32)
    {

        if(static_array[i][j] <= 9)
        {
            char c_1;
            c_1 = static_array[i][j] + '0';
            //printf("%c ",c_1);
            printf(YEL"%c "RESET,c_1);
        }
        else
        {
            char c_1, c_2;
            int d1,d2;
            d1 = static_array[i][j] % 10;
            d2 = static_array[i][j] / 10;
            c_1 = d1  + '0';
            c_2 = d2 + '0';
            printf(YEL"%c"RESET,c_2);
            printf(YEL"%c"RESET,c_1);
        }    
    } 
    else
    {
        char c_1, c_2;
        c_1 = ' ';
        c_2 = ' ';
        printf("%c",c_2);
        printf("%c",c_1);


    }

}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (4) ->Dynamic control function
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------

void dynamic_control()
{
    int i,counts = 20,life = 0;
    for(i = 0; i <= 150; i++)
        printf(RED"-"RESET);
    printf("\n\n");
    printf(YEL"\t\t\t\t\t\t\t\tCONTROL  OF  THE  GAME\n" RESET);
    printf("\n\n");
    printf(CYN"\t\t\t\t\t\t\t\tMove Up     : by \'w\' key\n" RESET);
    printf(CYN"\t\t\t\t\t\t\t\tMove Down   : by \'s\' key\n" RESET);
    printf(CYN"\t\t\t\t\t\t\t\tMove Left   : by \'a\' key\n" RESET);
    printf(CYN"\t\t\t\t\t\t\t\tMove Right  : by \'d\' key\n" RESET);
    printf("\n\n");
    printf(CYN"\t Total Move : %d \t\tTotal Move left : %d   \t\t Press \'l\' to get extra life \t\tPress \'esc\' to exit from the game :\n"RESET,counts,count );
    for(i = 0; i <= 150; i++)
        printf(RED"-"RESET);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (5) -> Display starting content  of the game
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------


void display()
{
    int i;
    char str_2[10] = "Hii... ";
    char str_1[30];
    char str_3[30] = " Welcome to the Puzzle world ";
    char str_4[60] = " Use your headphone to get the best experience ....";
    char str_5[50] = "Press Enter key to continue this game ";

    printf("\t\t\t\t\t\t\t\n");
    printf(YEL"\t\t\t\t\t\t\t\t\tNUMBER  SHIFTING  GAME\n"RESET);
    printf("\n\n");


    printf("\nEnter your name :- ");
    gets(str_1);
    system("cls");

    printf("\t\t\t\t\t\t\t\n");
    printf(YEL"\t\t\t\t\t\t\t\t\tNUMBER  SHIFTING  GAME\n"RESET);

    printf("\n\n");
    printf("\t\t\t");
    for ( i = 0; str_2[i]; i++)
    {
        printf(BLU"%c"RESET,str_2[i]);
        Sleep(70);
    }

    for ( i = 0; str_1[i]; i++)
    {
        printf(BLU"%c"RESET,str_1[i]);
        Sleep(70);
    }
    for ( i = 0; str_3[i]; i++)
    {
        printf(BLU"%c"RESET,str_3[i]);
        Sleep(70);
    }
    printf("\n\n\n\t\t\t\t");
    for ( i = 0; str_4[i]; i++)
    {
        
        printf(MAG"%c"RESET,str_4[i]);
        Sleep(80);
    }
    printf("\n\n\n\t\t\t\t");

    for ( i = 0; str_5[i]; i++)
    {
        
        printf(YEL"%c"RESET,str_5[i]);
        Sleep(80);
    }
    getch();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (6) -> Display Rule of the game.
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
void rule()
{
    int i,j,m=1;
    char str_5[50] = "Press Enter key to continue this game ";
    // printf("Display static array");
        
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            static_array[i][j]=m;
            m++;
        }
    }
    static_array[3][3] = 32;

    //Display Rule of the Game



    printf("\n\n");
    printf(YEL"\t\t\t\t\t\t\t\tRules of the Game\n" RESET);
    printf("\n\n");
    printf(CYN"\t\t\t1. You can move only 1 step at a time with the arrow key.\n" RESET);
    printf("\n");
    printf(MAG"\t\t\t\tMove Up     : by \'w\' key\n" RESET);
    printf(MAG"\t\t\t\tMove Down   : by \'s\' key\n" RESET);
    printf(MAG"\t\t\t\tMove Left   : by \'a\' key\n" RESET);
    printf(MAG"\t\t\t\tMove Right  : by \'d\' key\n" RESET);
    printf("\n");
    printf(CYN"\t\t\t2. You can move numbers at an empty position only.\n" RESET);
    printf("\n\n");
    printf(CYN"\t\t\t3. For each valid move : your total number of moves will decrease by 1..\n" RESET);
    printf("\n\n");
    printf(YEL"\t\t\t\t\t\t\tWinning Situation of the Game\n" RESET);
    printf("\n\n");
    printf(CYN"\t\t\tWinning Situation :Number in a 4*4 matrix should be in order from 1 to 15 as shown below.\n" RESET);
    printf("\n\n");
    static_table_array ();   


    printf("\t\t\t\t\t");

    for ( i = 0; str_5[i]; i++)
    {
        
        printf(YEL"%c"RESET,str_5[i]);
        Sleep(80);
    }
    getch();
    for(i = 0; i <= 190; i++)
        printf(RED"-"RESET);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (7) -> Generate distinct random number for an array
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------

void random_number()
{
    int number, lower = 1, Upper = 15;
    int i,j,k;
    int a[15];
    //int array[4][4];
    srand(time(NULL));

    for ( i = 0; i < 15; i++)
    {
     
        number = (rand() % (Upper - lower +1)) + lower;

        for ( j = 0; j <= i-1; j++)
        {
            if (number == a[j])
                break;
        }
        if (i == j)
            a[i]=number;
        else    
            i--;
        
    }


    k=0;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            array[i][j]=a[k];
            k++;

            
        }
        
    }
    array[3][3] = 32;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (8) -> Win check
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------

int wincheck()
{
    int k = 1;
    int i,j;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if(i == 3 && j == 3)
                break;
            else if (array[i][j] == k)
                k++;

            
        }
        
    }
    if (i == 3 && j == 3)
        return 1;
    else    
        return 0;
    

}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (9) ->to give warning about life
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------

void warning()
{
    if (count <=3 )
    {
        printf("\n\n");
        Beep(400,1000);
        printf(RED"\t\t\t\t\t\tYOUR LIFE IS JUST ABOUT TO FINISH.\n\n"RESET);
        printf(YEL"\t\t\t\t\t\tPRESS \'l\' to get extra life."RESET);
    }
}


//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (10) ->when you win it displays
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------

void display_win()
{
    system("cls");
    int i;
    char str_5[50] = "CONGRADULATION YOU WON THE GAME.... ";
    char str_6[50] = "PRESS \'ESC\' KEY TO EXIT FROM THE GAME. ";
    char str_7[50] = "PRESS ENTER TO CONTINUE THE GAME";


    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t");
    for ( i = 0; str_5[i]; i++)
    {
        printf(BLU"%c"RESET,str_5[i]);
        Sleep(70);
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t");
    for ( i = 0; str_6[i]; i++)
    {
        printf(BLU"%c"RESET,str_6[i]);
        Sleep(70);
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t");
    for ( i = 0; str_7[i]; i++)
    {
        printf(BLU"%c"RESET,str_7[i]);
        Sleep(70);
    }
    game_stater = getch();
    system("cls");

  
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------
//                          FUNCTION OF THE PROGRAMM (11) ->when you loose it displays
//-----------------------------------------------------------------------------------------------------------------------------------------------
//###############################################################################################################################################
//-----------------------------------------------------------------------------------------------------------------------------------------------


void display_loose()
{
    system("cls");
    int i;
    char str_5[50] = "BETTER LUCK NEXT TIME ";
    char str_6[50] = "PRESS \'ESC\' KEY TO EXIT FROM THE GAME. ";
    char str_7[50] = "PRESS ANY KEY TO CONTINUE THE GAME";


    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t");
    for ( i = 0; str_5[i]; i++)
    {
        printf(BLU"%c"RESET,str_5[i]);
        Sleep(70);
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t");
    for ( i = 0; str_6[i]; i++)
    {
        printf(BLU"%c"RESET,str_6[i]);
        Sleep(70);
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t");
    for ( i = 0; str_7[i]; i++)
    {
        printf(BLU"%c"RESET,str_7[i]);
        Sleep(70);
    }
    game_stater = getch();
    system("cls");

  
}