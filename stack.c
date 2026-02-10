#include <stdio.h> 
#define MAX 5

int a[MAX], x = -1;

int isFull(){
    return (x == MAX-1);
}

int isEmpty(){
    return (x == -1);
}

int push(int n){
    if(isFull()){
        printf("\n[ERROR] Stack Overflow\n");
        return 0;
    }
    a[x++] = n;
    printf("\nPushed %d\n", a[x]);
}

int pop(){
    if(isEmpty()){
        printf("\n[ERROR] Stack Underflow\n");
        return 0;
    }
    int i = x;
    --x;
    printf("\nPopped %d\n", a[i]);
}

int display(){
    if(isEmpty()){
        printf("\nStack is Empty\n");
        return 0;
    }
    printf("\nTop --> ");
    for(int i = x;i >= 0; i--){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void){
    int choose, n;

    do{
        printf("(1)Push (2)Pop (3)Display (4)Exit\n");
        printf("Enterr Choice : ");
        scanf("%d", &choose);

        switch(choose){
            case 1:
                printf("\nEnter the Element: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited!\n");
                break;
            default:
                printf("\nEnter proper Number\n");
        }
    }while(choose != 4);

    return 0;
}