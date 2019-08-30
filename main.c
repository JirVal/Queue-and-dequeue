// Module: Foundation to Computer Science
// Name: Jiri Valcikevic
// Student number: 100422488
// Deadline date: 23/03/2018
// Program name: C program to Queue and Deque numbers.

    #include <stdio.h>
    #include <stdlib.h>
    #define RED   "\x1B[31m"
    #define GREEN   "\x1B[32m"
    #define CYAN   "\x1B[36m"
    #define YELLOW   "\x1B[33m"
    #define BLUE   "\x1B[34m"
    #define MAG   "\x1B[35m"
    #define RESET "\x1B[0m"
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int frontelement();
void enque(int data);
void deque();
void empty();
void display();
void create();
void queuesize();
 
int count = 0;
 
void main()
{
    int number;
    int choice; 
    int element;
 
    printf(MAG"Welcome to program for using Queue Data Structure using Linked List"RESET);
    printf(MAG"\n===================================================================\n"RESET);
    printf(CYAN "     Menu   \n"RESET);
    printf(CYAN "--------------\n"RESET);
    printf(CYAN " 1 - Enque\n"RESET);
    printf(CYAN " 2 - Deque\n"RESET);
    printf(CYAN " 3 - Front number\n"RESET);
    printf(CYAN " 4 - Empty\n"RESET);
    printf(CYAN " 5 - Exit\n"RESET);
    printf(CYAN " 6 - Display queue\n"RESET);
    printf(CYAN " 7 - Queue size\n"RESET);
    printf(CYAN "---------------\n"RESET);
    create();
    
    while (1)
    {
        printf(GREEN "---------------\n"RESET);
        printf(GREEN" Enter choice: "RESET);
        scanf("\n%d", &choice);
        printf(GREEN "---------------\n"RESET);
        
        
        switch (choice)
        {
            case 1:
                printf(BLUE "---------------\n"RESET);
                printf(BLUE" Enter the number to store in queue: "RESET);
                scanf("\n%d", &number);
                printf(BLUE "---------------\n"RESET);
                enque(number);
                break;
                
            case 2:
                deque();
                break;
                
            case 3:
                element = frontelement();
                if (element != 0)
                {
                    printf(BLUE"----------------\n"RESET);
                    printf(BLUE" Front number: %d\n"RESET, element);
                    printf(BLUE"----------------\n"RESET);
                }
                else
                {
                    printf(RED"----------------------------------------------------\n"RESET);
                    printf(RED" No front number in Queue because the queue is EMPTY\n"RESET);
                    printf(RED"----------------------------------------------------\n"RESET);
                }
                break;
                
            case 4:
                empty();
                break;
                
            case 5:
                printf(CYAN"---------------------------------\n"RESET);
                printf(CYAN" The program will finish now.\n"RESET);
                printf(CYAN" Thank you for using this program.\n"RESET);
                printf(CYAN"----------------------------------\n"RESET);
                exit(0);
                
            case 6:
                display();
                break;
                
            case 7:
                queuesize();
                break;
                
            default:
                printf(RED"------------------------------------------\n"RESET);
                printf(RED" Wrong choice, Please enter correct choice: \n"RESET);
                printf(RED"------------------------------------------\n"RESET);
                break;
        }
    }
}
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf(MAG"---------------\n"RESET);
    printf(MAG" Queue size: "RESET"%d"MAG" numbers in the queue.\n"RESET, count);
    printf(MAG"---------------\n"RESET);
}
 
/* Enqueing the queue */
void enque(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
// Displaying the queue elements
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf(RED"---------------\n"RESET);
        printf(RED" Queue is empty\n"RESET);
        printf(RED"---------------\n"RESET);
        return;
    }
    while (front1 != rear)
    {
        printf(MAG"---------------\n"RESET);
        printf(MAG" Displayed queue: "RESET"%d\n", front1->info);
        printf(MAG"---------------\n"RESET);
        front1 = front1->ptr;
    }
    if (front1 == rear)
    {
        printf(MAG"---------------\n"RESET);
        printf(MAG" Displayed queue: "RESET"%d\n", front1->info);
        printf(MAG"---------------\n"RESET);
    }
}
 
// Dequeing the queue
void deque()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf(RED"-------------------------------------------------\n"RESET);
        printf(RED" Error: Trying to deque number from empty queue!\n"RESET);
        printf(RED"-------------------------------------------------\n"RESET);
        return;
    }
    else 
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf(RED"---------------\n"RESET);
            printf(RED" Dequed number: "RESET"%d\n", front->info);
            printf(RED"---------------\n"RESET);
            free(front);
            front = front1;
        }
        
        else
        {
            printf(RED"---------------\n"RESET);
            printf(RED" Dequed number: "RESET"%d\n", front->info);;
            printf(RED"---------------\n"RESET);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 
/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 
/* Display if queue is empty or not */
void empty()
{
    if ((front == NULL) && (rear == NULL))
    {
        printf(RED"-----------------\n"RESET);
        printf(RED" Sorry but queue is empty\n"RESET);
        printf(RED"-----------------\n"RESET);
    }    
    else
    {
        printf(RED"--------------------\n"RESET);
        printf(RED" Queue is not empty!\n"RESET);
        printf(RED"--------------------\n"RESET);
    }
}





