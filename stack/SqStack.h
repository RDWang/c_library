/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  SqStack.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月28日 
 *
 *    Description:  // c3-1.h 栈的顺序存储表示
 *
 *    Others:
 *
 *    Function List:
 *
 *      1.
 *
 *    History:(None)
 *
 *      1. Date:
 *         Author:
 *         Modification: 
 *
 *      2. ...
 *
 * =====================================================================================
 */
#ifndef _INCLUDE_SQSTACK_H_
#define _INCLUDE_SQSTACK_H_

#include "CdataStruct_type.h"

#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量

//定义数据结构
typedef struct SqStack
{
    SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack; // 顺序栈

//导出函数接口
extern Status InitStack(SqStack *S);
extern Status DestroyStack(SqStack *S);
extern Status ClearStack(SqStack *S);
extern Status StackEmpty(SqStack S);
extern int StackLength(SqStack S);
extern Status GetTop(SqStack S,SElemType *e);
extern Status Push(SqStack *S,SElemType e);
extern Status Pop(SqStack *S,SElemType *e);
extern Status StackTraverse(SqStack S,Status(*visit)(SElemType));

#endif
