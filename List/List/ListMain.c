#include <stdio.h>
#include <stdlib.h>

#include "Include/SqList.h"
#include "Include/LinkList.h"

int main()
{
	pLinkList L;
	LNode ccc,ddd;
	SqList *cc;
	SqList a;
	int f = 7;
	int y = 10;
	int *j;
	int c[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ElemType *d = NULL;
	
	cc = &a;
	//cc->elem = &y;
	//cc->elem[1] = f;
	//d = cc->elem[0];

	SqList_Init(&a);
	
	for (int i = 1; i <= 10; i++) {
		SqList_Insert(&a, i, c[i - 1]);
		printf("%d %d\n", cc->elem[i - 1], cc->elem[i]);
	}

	SqList_Insert(&a, 6, 789);
	SqList_Delete(&a, f, &y);
	int ttt = SqList_LocateElem(&a, 10, Compare);

	/*for (int i = 1; i <= 11; i++) {
		//SqList_Insert(&a, i, c[i - 1]);
		printf("%d %d\n", cc->elem[i - 1], cc->elem[i]);
	}*/

	for (int i = 1; i <= 9; i++) {
		printf("delete %d\n", cc->elem[i - 1]);
	}

	printf("ttt:%d  ", ttt);
	ddd.next = NULL;
	ccc.data = 5;
	ddd.data = 3;

	ccc.next = &ddd;
	
	L = &ccc;
	printf("Hello World!\n");
	printf("%x %d\n", L->data, cc->elem[9]);

	
	return 0;
}


// SqList function start>>>
// 2.3
Status SqList_Init(SqList *L){
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L->elem){
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

// 2.4
Status SqList_Insert(SqList *L, int i, ElemType e){
	if(i < 1 || i > L->length + 1){
		return ERROR;
	}
	if(L->length >= L->listsize){
		ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if(!newbase){
			exit(OVERFLOW);
		}
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	ElemType *q = &L->elem[i - 1];
	for(ElemType *p = &L->elem[L->length - 1]; p >= q; --p){
		*(p + 1) = *p;
	}
	*q = e;
	L->length++;
	return OK;
}

// 2.5
Status SqList_Delete(SqList *L, int i, ElemType *e) {
  ElemType *p, *q;
  if (i < 1 || i > L->length) 
	  return ERROR;  
  p = &(L->elem[i - 1]);                   
  *e = L->elem[i - 1];
  q = L->elem + L->length - 1;                
  for (++p; p<=q; ++p) 
	  *(p-1) = *p;
  L->length--;                           
  return OK;
}

// 2.6
int SqList_LocateElem(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType)) {
  int i = 1;
  ElemType *p;        
  p = L->elem;   
  while (i <= L->length && !(*compare)(*p++, e)) 
	  ++i;
  if (i <= L->length) 
	  return i;
  else return 0;
}

Status Compare(ElemType a, ElemType b) {
	return a == b ?  1 : 0;
}

// 2.7
void SqList_Merge(SqList *La, SqList *Lb, SqList *Lc) {

  ElemType *pa,*pb,*pc,*pa_last,*pb_last;
  pa = La->elem;  pb = Lb->elem;
  Lc->listsize = Lc->length = La->length+Lb->length;
  pc = Lc->elem = (ElemType *)malloc(Lc->listsize*sizeof(ElemType));
  if (!Lc->elem)
    exit(OVERFLOW);   
  pa_last = La->elem+La->length-1;
  pb_last = Lb->elem+Lb->length-1;
  while (pa <= pa_last && pb <= pb_last) {  
    if (*pa <= *pb) *pc++ = *pa++;
    else *pc++ = *pb++;
  }
  while (pa <= pa_last) *pc++ = *pa++;      
  while (pb <= pb_last) *pc++ = *pb++;      
}
// SqList function end<<<


// LinkList function start>>>
// 2.8
Status LinkList_GetElem(pLinkList L,int i, ElemType *e) {
  pLinkList p;
  p = L->next;   
  int j = 1;           
  while(p && j < i){   
	  p = p->next;  
	  ++j;
  }
  if(!p || j > i) 
	  return ERROR;
  *e = p->data;  
  return OK;
}

// 2.9
Status LinkList_Insert(pLinkList L, int i, ElemType e) {
	pLinkList p, s;
	p = L;
	int j = 0;
	while(p && j < i - 1) {
	p = p->next;
	++j;
	}
	if (!p || j > i - 1) 
		return ERROR;
	s = (pLinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

// 2.10
Status LinkList_Delete(pLinkList L, int i, ElemType *e) {
	pLinkList p, q;
	p = L;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) 
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

// 2.11 逆向生成单链表
void LinkList_ReverseCreate(pLinkList L, int n) {
	pLinkList p;
	int i;
	L = (pLinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (i = n; i>0; --i) {
		p = (pLinkList)malloc(sizeof(LNode));
		p->data = random(200);
		p->next = L->next;    
		L->next = p;
	}
}

// 2.12 合并两个有序链表
void LinkList_Merge(pLinkList La, pLinkList Lb, pLinkList Lc) {
	pLinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;   pc = pa;   pa = pa->next;
		}
		else { pc->next = pb;   pc = pb;   pb = pb->next; }
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}
// LinkList function end<<<

// Static Linklist function start>>>
// 2.13
int LocateElem_SL(SLinkList S, ElemType e) {
	int i;
	i = S[0].cur;
	while (i && S[i].data != e) i = S[i].cur;
	return i;
}

// 2.14
void InitSpace_SL(SLinkList space) {
	for (int i = 0; i<MAXSIZE - 1; ++i)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}

// 2.15
int Malloc_SL(SLinkList &space) {
	int i = space[0].cur;
	if (space[0].cur) space[0].cur = space[space[0].cur].cur;
	return i;
}

// 2.16
void Free_SL(SLinkList &space, int k) {  // 算法2.16
										 // 将下标为k的空闲结点回收到备用链表
	space[k].cur = space[0].cur;    space[0].cur = k;
} // Free_SL

  // 2.17
void difference(SLinkList &space, int &S) {  // 算法2.17
											 // 依次输入集合A和B的元素，在一维数组space中建立表示集合(A-B)∪(B-A)
											 // 的静态链表, S为头指针。假设备用空间足够大，space[0].cur为头指针。
	int i, j, k, m, n, p, r;
	ElemType b;
	InitSpace_SL(space);          // 初始化备用空间
	S = Malloc_SL(space);         // 生成S的头结点
	r = S;                        // r指向S的当前最后结点
	m = random(2, 8);              // 输入A的元素个数
	n = random(2, 8);              // 输入B的元素个数
	printf("  A = ( ");
	initrandom_c1();
	for (j = 1; j <= m; ++j) {        // 建立集合A的链表
		i = Malloc_SL(space);      // 分配结点
								   //printf("i=%d   ",i);
		space[i].data = random_next_c1();   // 输入A的元素值
		printf("%c ", space[i].data);       // 输出A的元素
		space[r].cur = i;  r = i;  // 插入到表尾
	}
	printf(")\n");
	space[r].cur = 0;
	initrandom_c1();
	printf("  B = ( ");
	for (j = 1; j <= n; ++j) {
		b = random_next_c1();
		printf("%c ", b);
		p = S;   k = space[S].cur;
		while (k != space[r].cur && space[k].data != b) {
			p = k;    k = space[k].cur;
		}
		if (k == space[r].cur) {
			i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}
		else {
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if (r == k)  r = p;
		}
	}
	printf(")\n");
}
// Static Linklist function end<<<

// Circular Linklist function start>>>
// 2.18
DuLinkList GetElemP_DuL(DuLinkList va, int i) {
	DuLinkList p;
	p = va->next;
	int j = 1;
	while (p != va && j<i) {
		p = p->next;
		++j;
	}
	if (p == va && j<i) return NULL;
	else return p;
}

// 2.19
Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
	DuLinkList p, s;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

// 2.20
Status ListInsert_L(NLinkList L, int i, ElemType e) {
	NLink h, s;
	if (!LocatePos(L, i - 1, h))
		return ERROR;
	if (!MakeNode(s, e))
		return ERROR;
	InsFirst(h, s);
	return OK;
}

// 2.21
Status MergeList_L(NLinkList &La, NLinkList &Lb, NLinkList &Lc,
	int(*compare)(ElemType, ElemType)) {  // 算法2.21
										  // 已知单链线性表La和Lb的元素按值非递减排列。
										  // 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
	NLink ha, hb;
	Position pa, pb, q;
	ElemType a, b;
	if (!InitList(Lc)) return ERROR;  // 存储空间分配失败
	ha = GetHead(La);      // ha和hb分别指向La和Lb的头结点
	hb = GetHead(Lb);
	pa = NextPos(La, ha);  // pa和pb分别指向La和Lb中当前结点
	pb = NextPos(Lb, hb);
	while (pa && pb) {     // La和Lb均非空
		a = GetCurElem(pa);  // a和b为两表中当前比较元素
		b = GetCurElem(pb);
		if ((*compare)(a, b) <= 0) {  // a≤b
			DelFirst(ha, q);  Append(Lc, q);  pa = NextPos(La, pa);
		}
		else {   // a＞b
			DelFirst(hb, q);  Append(Lc, q);  pb = NextPos(Lb, pb);
		}
	} // while
	if (pa) Append(Lc, pa);        // 链接La中剩余结点
	else Append(Lc, pb);           // 链接Lb中剩余结点
	FreeNode(ha);   FreeNode(hb);  // 释放La和Lb的头结点
	return OK;
}

// 2.22
Status cmp(PElemType a, PElemType b) {
	if (a.expn >= b.expn) return 1;
	else return 0;
}

void CreatPolyn(PLinkList &P, int m) {  // 算法2.22
										// 输入m项的系数和指数，建立表示一元多项式的有序链表P
	PLink h, q, s;
	PElemType e;
	int i;
	InitList(P);   h = GetHead(P);
	e.coef = 0.0;  e.expn = -1;
	SetCurElem(h, e);       // 设置头结点
	for (i = 1; i <= m; ++i) {  // 依次输入m个非零项
								// scanf ("%f,%d\n",&e.coef, &e.expn);
		e.coef = (float)(random(1, 90) + random(10) / 10.0);
		if (random(2)) e.coef = -e.coef;
		e.expn = e.expn + random(1, 10); //产生随机的数据，但是expn值是递增的
		if (!LocateElem(P, e, q, cmp)) { // 当前链表中不存在该指数项
			if (MakeNode(s, e)) InsFirst(q, s);  // 生成结点并插入链表
			if (q == P.tail) P.tail = s;
		}
		else i--;  //  如果没有产生插入，则将i值减1
	}
} // CreatPolyn

Status PrintfPoly(PLinkList P) {
	int i = 0;
	PLink q = P.head->next;
	while (q) {
		if (fabs(q->data.coef) > 0.005) {
			if (i>0) {
				if (q->data.coef>0.005) printf(" + ");
				else printf(" - ");
				printf("%.2f", fabs(q->data.coef));
			}
			else printf("%.2f", q->data.coef);
			if (q->data.expn >= 1) printf("x");
			if (q->data.expn>1) printf("^%d", q->data.expn);
		}
		q = q->next;
		if (++i % 6 == 0) printf("\n     ");
	}
	printf("\n");
	return OK;
}

// 2.23
int Compare(PElemType a, PElemType b) {
	if (a.expn<b.expn) return -1;
	if (a.expn>b.expn) return 1;
	return 0;
}

void AddPolyn(PLinkList &Pa, PLinkList &Pb) {  // 算法2.23
											   // 多项式加法：Pa = Pa＋Pb，利用两个多项式的结点构成"和多项式"。
	PLink ha, hb, qa, qb;
	PElemType a, b, temp;
	float sum;
	ha = GetHead(Pa);      // ha和hb分别指向Pa和Pb的头结点
	hb = GetHead(Pb);
	qa = NextPos(Pa, ha);   // qa和qb分别指向La和Lb中当前结点
	qb = NextPos(Pb, hb);
	while (qa && qb) {     // Pa和Pb均非空
		a = GetCurElem(qa); // a和b为两表中当前比较元素
		b = GetCurElem(qb);
		switch (Compare(a, b)) {
		case -1:  // 多项式PA中当前结点的指数值小
			ha = qa;
			qa = NextPos(Pa, qa);
			break;
		case 0:   // 两者的指数值相等
			sum = a.coef + b.coef;
			if (sum != 0.0) {  // 修改多项式PA中当前结点的系数值
				temp.coef = sum;
				temp.expn = a.expn;
				SetCurElem(qa, temp);
				ha = qa;
			}
			else {  // 删除多项式PA中当前结点
				DelFirst(ha, qa);
				FreeNode(qa);
			}
			DelFirst(hb, qb);
			FreeNode(qb);
			qb = NextPos(Pb, hb);
			qa = NextPos(Pa, ha);
			break;
		case 1:   // 多项式PB中当前结点的指数值小
			DelFirst(hb, qb);
			InsFirst(ha, qb);
			qb = NextPos(Pb, hb);
			ha = NextPos(Pa, ha);
			break;
		} // switch
	} // while
	if (!Empty(Pb)) Append(Pa, qb);
	FreeNode(hb);
}