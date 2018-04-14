#include "DS.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define MAXSIZE 1000

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;//分别定义了一个简写和列表

typedef struct {
	ElemType data;
	int cur;
}component, SLinkList[MAXSIZE];

typedef struct {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;

/*typedef struct LNode{
ElemType data;
struct LNode *next;
}*Link, *Position;*/

/*typedef struct{
Link head,tail;
int len;
}LinkList;*/