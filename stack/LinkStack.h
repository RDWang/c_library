/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  LinkStack.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月28日 
 *
 *    Description:  // c2-2.h 线性表的单链表存储结构
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
#ifndef _INCLUDE_LINKSTACK_H_
#define _INCLUDE_LINKSTACK_H_

#include "CdataStruct_type.h"
#include "LinkList.h"
 
typedef LinkList LinkStack; // LinkStack是指向栈结点的指针类型

//导出函数接口定义，需要链接LinkList.so库文件
#define InitStack InitList // InitStack()与InitList()作用相同，下同
#define DestroyStack DestroyList
#define ClearStack ClearList
#define StackEmpty ListEmpty
#define StackLength ListLength
#define GetTop GetFirstElem
#define Push HeadInsert
#define Pop DeleteFirst 
extern Status StackTraverse(LinkStack S,void(*visit)(SElemType));

#endif
