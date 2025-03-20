#include"Seqlist.h"

void SListPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}

void test01()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SListPrint(sl);

	//SLPushFront(&sl, 1);
	//SLPushFront(&sl, 2);
	//SLPushFront(&sl, 3);
	//SLPushFront(&sl, 4);
	//SLPushFront(&sl, 5);
	//
	//SLPopBack(&sl);
	//SLPopBack(&sl);
	//SLPopBack(&sl);
	//
	//SLPushBack(&sl, 100);
	//
	//SLPushFront(NULL, 1);
	//
	//SLPopFront(&sl);
	//SLPopFront(&sl);
	//SLPopFront(&sl);
	//SLPopFront(&sl);
	//SLPopFront(&sl);
	//
	//int ret = SLFind(&sl, 3333);
	//if (ret < 0)
	//{
	//	printf("δҵ\n");
	//}
	//else {
	//	printf("ҵˣ\n");
	//}
	//SLInsert(&sl, 0, 11);
	//SListPrint(sl);
	//SLInsert(&sl, 2, 22);
	//SListPrint(sl);
	//SLInsert(&sl, 6, 33);
	//SListPrint(sl);
	SLDesTroy(&sl);
}

int main()
{
	test01();
	return 0;
}