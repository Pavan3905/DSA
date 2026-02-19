#include <stdio.h>
#include <process.h>
#define STACK_SIZE 5

void push(int item, int* top, int s[]);
int pop(int* top, int s[]);
void display(int top, int s[]);

int main(void){
    int top, s[STACK_SIZE], item, item_deleted, choice;

    top = -1;
    for(;;){
        printf("1. push");
        printf("2. pop\n");
        printf("3. display\n");
        printf("4. exit\n\n");
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
                    printf("Stack is Empty\n");
                else
                    printf("Item deleted = %d\n\n", item_deleted);
                break;
            case 3:
                display(top, s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}

void push(int item, int* top, int s[]){
    if(*top == STACK_SIZE-1){
        printf("Stack overflow\n");
        return;
    }
    *top = *top+1;
    s[*top] = item;
    printf("\n");
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
        printf("Stack is Empty\n");
        return;
    }
    printf("Contents of the stack\n");
    printf("top --> ");
    for(int i = top; i>=0; i--)
        printf("%d ", s[i]);
        printf("\n\n");
}
