#include "Seqlist.h"
 
//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		// 空间扩容一般按照倍数扩容
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//判断空间是否满了
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}
//头插
void SLPushFront(SL* ps, SLDataType x)
{
	////温柔的处理方式
	//if (ps == NULL)
	//{
	//	return;
	//}
	assert(ps);//等价于assert(ps != NULL)

	//判断空间是否满了
	SLCheckCapacity(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	++ps->size;
}
//尾删
void SLPopBack(SL* ps)
{
	//顺序表不为空
	assert(ps && ps->size);
	--ps->size;
}
//头删
void SLPopFront(SL* ps)
{
	//顺序表不为空
	assert(ps && ps->size);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}

	--ps->size;
}
//找到了，返回下标；未找到，返回-1
int SLFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	//未找到
	return -1;
}

//指定位置之前插⼊数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	++ps->size;
}
//指定位置删除数据
void SLErase(SL* ps, int pos)
{
	assert(ps && ps->size);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}

	--ps->size;
}

//销毁
void SLDesTroy(SL* ps)
{
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}