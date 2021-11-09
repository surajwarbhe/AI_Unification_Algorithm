// UNIFICATION ALGORITHM

#include<stdio.h>

int no_of_expr;         // Count total no. of Expressions
int no_of_arg[10];      // Count total no. of argument
int i, j;
char nouse;
char expr[10];          // Stored Expression
char argument[10][10];  // Stored arguments


void unify();           // Function for unification algorithm
void display();         // Display Expressions
void check_Arg_Expr();  // Check arguments & Expressions


// MAIN FUNCTION
void main() 
{
    char ch;
    do 
    {
        printf("\t=========PROGRAM FOR UNIFICATION=========\n");
        printf("\nEnter Number of Expressions:- [ ]\b\b");      
        scanf("%d", &no_of_expr);

        for(i=0;i<no_of_expr;i++)
        {
            // to accept "enter" as a character
            scanf("%c", &nouse);    
            printf("\nEnter Expression %d:-[ ]\b\b", i+1);
            scanf("%c", &expr[i]);
            printf("\n\tEnter No.of Arguments for Expression %c:-[ ]\b\b",expr[i]);
            scanf("%d", &no_of_arg[i]);
                        for(j=0;j<no_of_arg[i];j++)
                        {
                            scanf("%c",&nouse);
                            printf("\n\tEnter argument %d:( )\b\b",j+1);
                            scanf("%c",&argument[i][j]);
                        }
        }

        display();
        check_Arg_Expr();
            
        printf("Do you want to continue(y/n):   ");
        scanf("%c", &ch);
    } while(ch == 'y');
}


// DISPLAY EXPRESSIONS
void display()
{
    printf("\n\t==========EXPRESSIONS=========");
    for(i=0;i<no_of_expr;i++)
    {
        printf("\n\t%c(", expr[i]);
        for(j=0;j<no_of_arg[i];j++)
        {
            printf("%c", argument[i][j]);
            if(j != no_of_arg[i]-1)
            printf(",");
        }
        printf(")");
    }
}


// CHECK ARGUMENTS & EXPRESSIONS
void check_Arg_Expr()
{
   int expr_flag=0;
   int arg_flag=0;

   /*======Checking Expressions========*/
            for(i=0;i<no_of_expr-1;i++)
            {
                if(expr[i] != expr[i+1])
                {
                    printf("\nExpressions are not same..!");
                    printf("\nUnification FAILS !");
                    expr_flag = 1;
                    break;
                }
            }
   /*=====Checking No of Arguments====*/
     if(expr_flag != 1)
     {
        for(i=0;i<no_of_arg[i]-1;i++)
        {
            if(no_of_arg[i] != no_of_arg[i+1])
            {
                printf("\nArguments are not Same..!");
                arg_flag=1;
                break;
            }
        }
    }
        
    if(arg_flag == 0 && expr_flag != 1)
        unify();
}

// UNIFY FUNCTION
void unify()
{
    int flag = 0;               // Initiliaze flag as 0
    for(i=0;i<no_of_expr-1;i++)
    {
        for(j=0;j<no_of_arg[i];j++)
        {
            if(argument[i][j] != argument[i+1][j])      // When number of arguments are same
            {
                if(flag == 0)
                    printf("\n\t==========SUBSTITUTION==========");
                    printf("\n\t%c/%c", argument[i+1][j], argument[i][j]); // Substitute
                     flag++;
            }
        }
    }
    if(flag == 0)   // when args are identical
    {
        printf("\nArguments are Identical..!");
        printf("\nNo need of Substitution !\n");
    }
}
