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

// 2.11 �������ɵ�����
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

// 2.12 �ϲ�������������
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
void Free_SL(SLinkList &space, int k) {  // �㷨2.16
										 // ���±�Ϊk�Ŀ��н����յ���������
	space[k].cur = space[0].cur;    space[0].cur = k;
} // Free_SL

  // 2.17
void difference(SLinkList &space, int &S) {  // �㷨2.17
											 // �������뼯��A��B��Ԫ�أ���һά����space�н�����ʾ����(A-B)��(B-A)
											 // �ľ�̬����, SΪͷָ�롣���豸�ÿռ��㹻��space[0].curΪͷָ�롣
	int i, j, k, m, n, p, r;
	ElemType b;
	InitSpace_SL(space);          // ��ʼ�����ÿռ�
	S = Malloc_SL(space);         // ����S��ͷ���
	r = S;                        // rָ��S�ĵ�ǰ�����
	m = random(2, 8);              // ����A��Ԫ�ظ���
	n = random(2, 8);              // ����B��Ԫ�ظ���
	printf("  A = ( ");
	initrandom_c1();
	for (j = 1; j <= m; ++j) {        // ��������A������
		i = Malloc_SL(space);      // ������
								   //printf("i=%d   ",i);
		space[i].data = random_next_c1();   // ����A��Ԫ��ֵ
		printf("%c ", space[i].data);       // ���A��Ԫ��
		space[r].cur = i;  r = i;  // ���뵽��β
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
	int(*compare)(ElemType, ElemType)) {  // �㷨2.21
										  // ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
										  // �鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
	NLink ha, hb;
	Position pa, pb, q;
	ElemType a, b;
	if (!InitList(Lc)) return ERROR;  // �洢�ռ����ʧ��
	ha = GetHead(La);      // ha��hb�ֱ�ָ��La��Lb��ͷ���
	hb = GetHead(Lb);
	pa = NextPos(La, ha);  // pa��pb�ֱ�ָ��La��Lb�е�ǰ���
	pb = NextPos(Lb, hb);
	while (pa && pb) {     // La��Lb���ǿ�
		a = GetCurElem(pa);  // a��bΪ�����е�ǰ�Ƚ�Ԫ��
		b = GetCurElem(pb);
		if ((*compare)(a, b) <= 0) {  // a��b
			DelFirst(ha, q);  Append(Lc, q);  pa = NextPos(La, pa);
		}
		else {   // a��b
			DelFirst(hb, q);  Append(Lc, q);  pb = NextPos(Lb, pb);
		}
	} // while
	if (pa) Append(Lc, pa);        // ����La��ʣ����
	else Append(Lc, pb);           // ����Lb��ʣ����
	FreeNode(ha);   FreeNode(hb);  // �ͷ�La��Lb��ͷ���
	return OK;
}

// 2.22
Status cmp(PElemType a, PElemType b) {
	if (a.expn >= b.expn) return 1;
	else return 0;
}

void CreatPolyn(PLinkList &P, int m) {  // �㷨2.22
										// ����m���ϵ����ָ����������ʾһԪ����ʽ����������P
	PLink h, q, s;
	PElemType e;
	int i;
	InitList(P);   h = GetHead(P);
	e.coef = 0.0;  e.expn = -1;
	SetCurElem(h, e);       // ����ͷ���
	for (i = 1; i <= m; ++i) {  // ��������m��������
								// scanf ("%f,%d\n",&e.coef, &e.expn);
		e.coef = (float)(random(1, 90) + random(10) / 10.0);
		if (random(2)) e.coef = -e.coef;
		e.expn = e.expn + random(1, 10); //������������ݣ�����expnֵ�ǵ�����
		if (!LocateElem(P, e, q, cmp)) { // ��ǰ�����в����ڸ�ָ����
			if (MakeNode(s, e)) InsFirst(q, s);  // ���ɽ�㲢��������
			if (q == P.tail) P.tail = s;
		}
		else i--;  //  ���û�в������룬��iֵ��1
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

void AddPolyn(PLinkList &Pa, PLinkList &Pb) {  // �㷨2.23
											   // ����ʽ�ӷ���Pa = Pa��Pb��������������ʽ�Ľ�㹹��"�Ͷ���ʽ"��
	PLink ha, hb, qa, qb;
	PElemType a, b, temp;
	float sum;
	ha = GetHead(Pa);      // ha��hb�ֱ�ָ��Pa��Pb��ͷ���
	hb = GetHead(Pb);
	qa = NextPos(Pa, ha);   // qa��qb�ֱ�ָ��La��Lb�е�ǰ���
	qb = NextPos(Pb, hb);
	while (qa && qb) {     // Pa��Pb���ǿ�
		a = GetCurElem(qa); // a��bΪ�����е�ǰ�Ƚ�Ԫ��
		b = GetCurElem(qb);
		switch (Compare(a, b)) {
		case -1:  // ����ʽPA�е�ǰ����ָ��ֵС
			ha = qa;
			qa = NextPos(Pa, qa);
			break;
		case 0:   // ���ߵ�ָ��ֵ���
			sum = a.coef + b.coef;
			if (sum != 0.0) {  // �޸Ķ���ʽPA�е�ǰ����ϵ��ֵ
				temp.coef = sum;
				temp.expn = a.expn;
				SetCurElem(qa, temp);
				ha = qa;
			}
			else {  // ɾ������ʽPA�е�ǰ���
				DelFirst(ha, qa);
				FreeNode(qa);
			}
			DelFirst(hb, qb);
			FreeNode(qb);
			qb = NextPos(Pb, hb);
			qa = NextPos(Pa, ha);
			break;
		case 1:   // ����ʽPB�е�ǰ����ָ��ֵС
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