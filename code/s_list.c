#include"s_list.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//向操作系统申请一个新节点
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = SLTBuyNode(x);
	//链表为空，phead直接指向newnode结点
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else {
		//链表不为空，找尾结点，将尾结点和新节点连接起来
		SLTNode* ptail = *pphead;
		while (ptail->next)//等价于ptail->next != NULL
		{
			ptail = ptail->next;
		}
		//ptail newnode
		ptail->next = newnode;
	}
}