#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//定义链表的结构
//定义结点的结构
typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;//指向下一个结点的指针
}SLTNode;
//typedef struct SListNode SLTNode;

//phead：头（首）结点
void SLTPrint(SLTNode* phead);

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);