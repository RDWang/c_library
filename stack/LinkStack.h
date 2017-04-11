/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  LinkStack.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��28�� 
 *
 *    Description:  // c2-2.h ���Ա�ĵ�����洢�ṹ
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
 
typedef LinkList LinkStack; // LinkStack��ָ��ջ����ָ������

//���������ӿڶ��壬��Ҫ����LinkList.so���ļ�
#define InitStack InitList // InitStack()��InitList()������ͬ����ͬ
#define DestroyStack DestroyList
#define ClearStack ClearList
#define StackEmpty ListEmpty
#define StackLength ListLength
#define GetTop GetFirstElem
#define Push HeadInsert
#define Pop DeleteFirst 
extern Status StackTraverse(LinkStack S,void(*visit)(SElemType));

#endif
