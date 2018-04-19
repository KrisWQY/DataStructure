#define MAX_ARRAY_DIM 8
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *base; 
	int dim;
	int *bounds;
	int *constants;
}Array;
