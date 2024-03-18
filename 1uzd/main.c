#include <stdio.h>
#include "stack.h"

int main()
{
	printf("------------------------------------\n");
    Stack *s;
	//push(s, 1); //illegal

    s = createStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);

    int a;

    pop(s, &a);
    printf("%d\n", a);

    pop(s, &a);
    printf("%d\n", a);

    pop(s, &a);
    printf("%d\n", a);

    //pop(s, &a); //illegal
    
    destroyStack(&s);
    //push(s, 1); //illegal
	printf("------------------------------------\n");
    return 0;
}