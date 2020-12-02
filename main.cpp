#include <cstdio>
#include "memman.h"

MM_TYPE_REGISTER(int)
MM_TYPE_REGISTER(char)


int main()
{
	printf("hello world %d %d", MM_TYPEIDNAME(int), MM_TYPEIDNAME(char));
	return 0;
}