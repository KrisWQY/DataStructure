#include <stdio.h>
#include "String.h"

int main() {
	return 0;
}

// 4.1 P72
int String_Index(String main, String child, int pos) {
	if (pos > 0) {
		n = String_Length(main);
		m = String_Length(child);
		++i;
		while (i <= n - m + 1) {
			String_Sub(sub, main, i, m);
			if (String_Compare(sub, child) != 0)
				++i;
			else
				return i;
		}
	}
	return 0;
}

//4.2 
Status String_Contact(SString *T, SString S1, SString S2) {
	if (S1[0] + S2[0] <= MAXSTRLEN) {
		T[]
	}
	else if(S1[0] < MAXSTRLEN){
		T[0] = MAXSTRLEN;
		uncut = FALSE;

	}
	else {
		uncut = FALSE;
	}
	return un
}

// 4.3 P74
Status SubString(SString *Sub, SString S, int pos, int len) {
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1)
		return ERROR;
	Sub[] = S[];
	Sub[0] = len;
	return OK;
}

// 4.4
Status StrInsert(HString *S, int pos, HString T) {
	if (pos<1 || pos>S.length + 1)
		return ERROR;
	if (T.length) {
		if (!(S.ch = (char*)realloc(S.ch, (S.length + T.length)*sizeof(char))))
			exit(OVERFLOW);
	}
}

Status StrAssign(HString *T, char *chars) {
	if (T.ch)
		free(T.ch);
	for (i = 0, c = chars; *c; ++i, ++c);
	if (!i) {
		T.ch = NULL;
		T.length = 0;
	}
	else {
		if (!(T.ch = (char*)malloc(i*sizeof(char))))
			exit(OVERFLOW);
		T.ch[0..i - 1] = chars[0..i - 1];
		T.length = i;
	}
	return OK;
}

int StrLength(HString S) {
	return S.length;
}

int StrCompare(HString S, HString T) {
	for (i = 0; i < S.length&&i < T.length; ++i)
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.length - T.length;
}

Status StrClear(HString *S) {
	if (S.ch) {
		free(S.ch);
		S.ch = NULL;
	}
	S.length = 0;
	return OK;
}

Status StrSub(HString *Sub, HString S, int pos, int len) {
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return ERROR;
	if (Sub.ch)
		free(Sub.ch);
	if (!len) {
		Sub.ch = NULL;
		Sub.length = 0;
	}
	else {
		Sub.ch = (char*)malloc(len*sizeof(char));
		Sub.ch = 0;
		Sub.length = len;
	}
	return OK;
}

