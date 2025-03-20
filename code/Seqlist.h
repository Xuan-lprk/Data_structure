#pragma once //防止头文件重复包含
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//顺序表的结构
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;      //有效数据个数
	int capacity;  //空间大小
}SL;

//typedef struct SeqList SL;

//初始化
void SLInit(SL* ps);
//销毁
void SLDesTroy(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);
//头插
void SLPushFront(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);

//查找
//找到了，返回下标；未找到，返回-1
int SLFind(SL* ps, SLDataType x);

//指定位置之前插⼊数据
void SLInsert(SL* ps, int pos, SLDataType x);
//指定位置删除数据
void SLErase(SL* ps, int pos);
