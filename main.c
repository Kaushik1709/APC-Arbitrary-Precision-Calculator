#include "apc.h"

int main(int argc,char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL,*tailR = NULL;
    char operator;

    int sign1 = 1, sign2 = 1;
    int result_sign = 1;

     /*Validation*/
    if(argc != 4)
    {
        printf("USAGE: %s <operand1> <operator> <operand2>\n",argv[0]);
        return FAILURE;
    }
    /* Extract operator */
    operator = argv[2][0];
    if (!(operator == '+'||operator == '-'||operator == '*'||operator == '/'))
    {
        printf("Invalid Operator\n");
        return FAILURE;
    }

    /* Detect sign of operand1 */
    if(argv[1][0] == '-')
    {
        sign1 = -1;
        argv[1]++;
    }

    /* Detect sign of operand2 */
    if(argv[3][0] == '-')
    {
        sign2 = -1;
        argv[3]++;
    }

    /* Digit Validation */
    if(!is_number(argv[1])||!is_number(argv[3]))
    {
        printf("INVALID...! Operands should be digits\n");
        return FAILURE; 
    }

    /* Convert strings to linked lists */
    if(create_list(argv[1], &head1, &tail1) == FAILURE || create_list (argv[3], &head2, &tail2) == FAILURE)
    {
        printf("MEmory Allocation Failed\n");
        return FAILURE;
    }

    switch (operator)
	{
		case '+':
			/* call the function to perform the addition operation */
            if(sign1 == sign2)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                result_sign = sign1;
            }
            else
            {
                int is_negative =0;
                subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR,&is_negative);
                result_sign = is_negative ? -1 : 1;

            }
            
            break;

		case '-':	
			/* call the function to perform the subtraction operation */
            sign2 = -sign2;
            if(sign1 == sign2)
            {
               addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
               result_sign = sign1; 
            }
            else
            {
                int is_negative = 0;
                subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR,&is_negative);
                result_sign = is_negative ? -1 : 1;
            }
            break;

		case '*':
            /* call the function to perform the multiplication operation */
            multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            result_sign = sign1 * sign2;

            break;

		case '/':	
			/* call the function to perform the division operation */
            division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            result_sign = sign1 * sign2;
			break;
	}

    if(result_sign < 0)
    printf("-");

    print_list(headR);
	return SUCCESS;
}

int create_list(char*str,Dlist **head,Dlist **tail)
{
    int i=0;
    while(str[i] != '\0')
    {
        Dlist *new=malloc(sizeof(Dlist));
        if(new == NULL)
        {
            return FAILURE;
        }
        new->data=str[i]-'0';
        new->prev=NULL;
        new->next=NULL;
        //first node
        if(*head == NULL)
        {
            *head = new;
            *tail = new;
        }
        else
        {
            new->prev = *tail;
            (*tail)->next = new;
            *tail = new;
        }
        i++;
    }
    return SUCCESS;
}

int is_number(char *str)
{
    int i=0;
    if(str == NULL || str[0] == '\0')
    {
        return 0;
    }
    while(str[i] != '\0')
    {
        if(!isdigit(str[i]))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
