#include "DS.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define MAXSIZE 1000

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *pLinkList;//分别定义了一个简写和有序链表指针

typedef struct {
	ElemType data;
	int cur;
}component, SLinkList[MAXSIZE];//静态链表

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

// 2.10
Status LinkList_Insert(pLinkList L, int i, ElemType e);

// 2.11
void LinkList_ReverseCreate(pLinkList L, int n);

// 2.12
void LinkList_Merge(pLinkList La, pLinkList Lb, pLinkList Lc);