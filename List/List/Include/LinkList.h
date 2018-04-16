#include "DS.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define MAXSIZE 1000

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *pLinkList;//�ֱ�����һ����д����������ָ��

typedef struct {
	ElemType data;
	int cur;
}component, SLinkList[MAXSIZE];//��̬����

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