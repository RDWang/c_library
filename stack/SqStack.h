/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  SqStack.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��28�� 
 *
 *    Description:  // c3-1.h ջ��˳��洢��ʾ
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

#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
#define STACKINCREMENT 2 // �洢�ռ��������

//�������ݽṹ
typedef struct SqStack
{
    SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
    SElemType *top; // ջ��ָ��
    int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack; // ˳��ջ

//���������ӿ�
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
