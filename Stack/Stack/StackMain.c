#include <stdlib.h>
#include <stdio.h>

#include "DS.h"
#include "Stack.h"

int main(){
	return 0;
}

Status Stack_Init(SqStack *S){
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Stack_Destroy(SqStack *S) {

}

Status Stack_Clear(SqStack *S) {

}

Status Stack_IsEmpty(SqStack *S) {

}

Status Stack_Length(SqStack *S) {

}

Status Stack_GetTop(SqStack *S, SElemType *e) {
	if(S->top == S->base)
		return ERROR;
	e = S->top - 1;
	return OK;
}

Status Stack_Push(SqStack *S, SElemType e) {
	if (S->top - S->base >= S->stacksize) {
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Stack_Pop(SqStack *S, SElemType e) {
	if (S->top == S->base)
		return ERROR;
	e = --S->top;
	return OK;
}

Status Stack_Traverse(SqStack S, Status(*visit)()) {

}

// Example function start >>>
// 3.1
void convertDEC2OCT(int Num) //Only positive decimal number
{
	SElemType e;  
    SqStack S;
    Stack_Init(&S);
    while (Num) {
        Push(S, Num % 8);
        Num = Num/8;
    }
    while (!StackEmpty(S)) {
        Pop(S,e);
        printf ("%d", e);
    }
	printf("\n");
}