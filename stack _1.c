#include <stdio.h>
#include <process.h> // instead you can use stdlib.h
#define STACK_SIZE 5

void push(int item, int* top, int s[]);
int pop(int* top, int s[]);
void display(int top, int s[]);

int main(void){
    int top, s[STACK_SIZE], item, item_deleted, choice;
    top = -1;
    for(;;){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the item to be inserted : ");
                scanf("%d", &item);
                push(item, &top, s);
                break;
            case 2:
                item_deleted = pop(&top, s);
                if(item_deleted == -1)
                    printf("[Stack Underflow]\n\n");
                else
                    printf("[Popped %d Succesfully]\n\n", item_deleted);
                break;
            case 3:
                display(top, s);
                break;
            case 4:
                printf("See You Soon (*_*)");
                exit(0);
            default:
                printf("[Invalid Choice]\n\n");
                break;
        }
    }
    return 0;
}

void push(int item, int* top, int s[]){
    if(*top == STACK_SIZE-1){
        printf("[Stack Overflow]\n\n");
    return;
    }
    *top = *top + 1;
    s[*top] = item;
    printf("[Pushed %d Succesfully]\n\n", s[*top]);
}

int pop(int* top, int s[]){
    int item_deleted;
    if(*top == -1)
        return -1;
    item_deleted = s[(*top)--];
    return item_deleted;
}

void display(int top, int s[]){
    if(top == -1){
        printf("[Stack is Empty]\n\n");
    return;
    }
    printf("Overview Of Your Stack\n");
    printf("top --> ");
    for(int i = top; i>=0; i--)
        printf("%d ", s[i]);
    printf("\n\n");
}
