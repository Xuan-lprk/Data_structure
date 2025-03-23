#include"Slist.h"

//手动构造一个链表
//并且打印链表
void test01()
{
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//打印链表
	SLTNode* plist = node1;
	SLTPrint(plist);
}

void test02()
{
	SLTNode* plist = NULL;
	//往空链表中插入结点
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);//1 2 3 4
	SListDestroy(&plist);

	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 3);
	//SLTPushFront(&plist, 4);
	//SLTPrint(plist);
//
	//SLTPopBack(&plist);
	//SLTPrint(plist);
	//SLTPopBack(&plist);
	//SLTPrint(plist);
	//SLTPopBack(&plist);
	//SLTPrint(plist);
	//SLTPopBack(&plist);
	//SLTPrint(plist);
//
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//
	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTNode* ret = SLTFind(plist, 4);

	//SLTInsert(&plist, ret, 100);
	//SLTInsertAfter(ret, 100);
	//SLTErase(&plist, ret);
	//SLTEraseAfter(ret);
	//SLTPrint(plist);
}
int main()
{
	//test01();
	test02();
	return 0;
}
