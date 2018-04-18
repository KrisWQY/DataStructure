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
	return OK;
}

Status Stack_Clear(SqStack *S) {
	return OK;
}

Status Stack_IsEmpty(SqStack *S) {
	return OK;
}

Status Stack_Length(SqStack *S) {
	return OK;
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
	return OK;
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

// 3.2 P50
void LineEdit() {
	SqStack S;
	Stack_Init(&S);
	ch = getchar();
	while (ch != EOF) {
		while (ch != EOF &&ch != '\n') {
			switch (ch){
				case '#':Pop(S, c); break;
				case '@':Stack_Clear(&S); break;
				default:break;   
			}

			
		}
	}

}

// 3.4
OperandType EvaluateExpression() {
	Stack_Init(OPTR);
	Stack_Push(OPTR, '#');
	Stack_Init(OPND);
	c = getchar();
	while (c != '#' || Stack_GetTop(OPTR) != '#') {
		if (!In(c, OP)) {
			Push((OPND, c);
			c = getchar();
		}
		else {
			switch (Precede(GetTop(OPTR), c)) {
			case'<':
				Stack_Push(OPTR, c);
				c = getchar();
				break;
			case'=':
				Stack_Push(OPTR, x);
				c = getchar();
				break;
			case'>':
				Stack_Pop(OPTR, thera);
				Stack_Pop(OPND, b);
				Stack_Pop(OPND, a);
				Stack_Push(OPND, operate(a, theta, b));
				break;
			}
		}
	}
	return Stack_GetTop(OPND);
}

// 3.5 P55
void Hanoi(int n, char x, char y, char z) {
	int c = 0;
	printf("%i. Move disk %i from %c to %c\n", ++c, n, x, z);
	if (n == 1)
		move(x, 1, z);
	else {
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

// 3.6 P65
void Bank_Simulation(int CloseTime) {
	OpenForDay();
	while (MoreEvent) {
		EventDrived(OccurTime, EventType);
		switch (EventType){
		case'A':CustomerArrived(); break;
		case'D':CustomerDeparture(); break;
		default:Invalid();break;
		}

	}
}

// 3.7 P67
void OpenForDay() {
	TotalTime = 0;
	CustomerNum = 0;
	InitList(ev);
	en.OccurTime = 0;
	en.NType = 0;
	OrderInsert(ev, en, cmp);
	for (i = 1; i <= 4; ++i)
		InitQueue(q[i]);
}

void CustomerArrived() {
	++CustomerNum;
	Random(durtime, intertime);
	t = en.OccurTime + intertime;
	if (t < CloseTime)
		OrderInsert(ev, (t, 0), cmp);
	i = Minimum(q);
	EnQueue(q[i], (en.OccurTime, durtime));
	if (QueueLength(q[i]) == 1)
		OrderInsert(ev, (en.OccurTime + durtime, i), cmp);
}

void CustomerDeparture() {
	i = en.NType;
	DelQueue(q[i], customer);
	TotalTime += en.Occurtime - customer.ArrivalTime;
	if (!QueueEmpty(q[i])) {
		GetHead(q[i], customer);
		OrderInsert(ev, (en.OccurTime + customer.Duration, i), (*cmp)());
	}
} 