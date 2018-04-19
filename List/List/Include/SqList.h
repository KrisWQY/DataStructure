#include "DS.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define MAXSIZE 1000
#define EMPTY 1
#define NOTEMPTY 0

typedef int ElemType;

typedef struct{
	ElemType *elem;
	int length;
	int listsize; //sizeof(int)
}SqList;

//2.1
void SqList_Union(SqList *La, SqList *Lb);

int SqList_Length(SqList *L);

void SqList_GetElem(SqList *L, int i, ElemType *e);

int SqList_IsEmpty(SqList *L);

//2.2
Status SqList_MergeList(SqList *La, SqList *Lb, SqList *Lc);

//2.3
Status SqList_Init(SqList *L);

//2.4
Status SqList_Insert(SqList *L, int i, ElemType e);

//2.5
Status SqList_Delete(SqList *L, int i, ElemType *e);

//2.6
int SqList_LocateElem(SqList *L, ElemType e, Status(*compare)(ElemType, ElemType));

//2.7
void SqList_Merge(SqList *La, SqList *Lb, SqList *Lc);

Status Compare(ElemType a, ElemType b);