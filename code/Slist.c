#include"Slist.h"

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
	assert(pphead);
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
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//newnode *pphead
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//只有一个结点的情况
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//prev ptail
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	//未找到
	return NULL;
}
//在指定位置之前插⼊数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && pos);
	//pos就是头结点
	if (pos == *pphead)
	{
		//头插
		SLTPushFront(pphead, x);
	}
	else {
		SLTNode* newnode = SLTBuyNode(x);
		//pos在头结点之后--->找pos前驱节点
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//prev newnode  pos
		newnode->next = pos;
		prev->next = newnode;
	}
}

//在指定位置之后插⼊数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos结点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	//要删除的结点刚好就是头结点---头删
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else {
		//prev
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//prev pos pos->next
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//删除pos之后的结点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	//pos del del->next
	SLTNode* del = pos->next;
	pos->next = del->next;

	free(del);
	del = NULL;
}
//销毁链表
void SListDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}