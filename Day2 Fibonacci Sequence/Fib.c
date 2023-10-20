#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main(void)
{
    int requested_number;
    //Double long because the numbers will get big fast
    long long int current_number = 0;
    long long int next_number = 1;
    long long int temp;

    printf("Enter in the number for the Fibonacci Sequence: ");

    while(true)
    {
        if(scanf("%d", &requested_number) != 1 || requested_number < 1 || requested_number > INT_MAX)
        {
            printf("Invalid input, please input number between 1 and %d: " , INT_MAX);
            while(getchar() != '\n');
        }
        else
        {
            break;
        }
    }
    //Ternary operators for number suffixes
    printf("Fibonacci Sequence up to the %d%s number: ", requested_number, 
    requested_number == 1 ? "st" : 
    requested_number == 2 ? "nd" : 
    requested_number == 3 ? "rd" : 
    /* Default case */      "th");

    if(requested_number >= 1)
        printf("%lld, ", current_number);
    if(requested_number >= 2)
        printf("%lld, ", next_number);
    
    for (int i = 3; i <= requested_number ; i++)
    {
        //Edge condition that deals with overflow
        if(LLONG_MAX - current_number < next_number)
        {
            printf("\n\nOverflow occured at: %d. Exiting program.\n", i);
            break;
        }
        
            temp = current_number + next_number;
            //QOL, ensures last number doesn't have a comma
            if( i < requested_number)
            {
                printf("%lld, ", temp);
            }
            else
            {
                printf("%lld", temp);
            }

            current_number = next_number;
            next_number = temp;
    }

    printf("\n");

    return 0;
}