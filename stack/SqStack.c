/*
 * =====================================================================================
 *      
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  SqStack.c
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��28�� 
 *
 *    Description:      // bo3-1.cpp ˳��ջ���洢�ṹ��c3-1.h���壩�Ļ���������9����
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


#include "SqStack.h"

Status InitStack(SqStack *S)
{ // ����һ����ջS
    if(!(S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
        return ERROR; // �洢����ʧ��
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack *S)
{ // ����ջS��S���ٴ���
    free(S->base);
    S->base=NULL;
    S->top=NULL;
    S->stacksize=0;
    return OK;
}

Status ClearStack(SqStack *S)
{ // ��S��Ϊ��ջ
    S->top=S->base;
    return OK;
}

Status StackEmpty(SqStack S)
{ // ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{ // ����S��Ԫ�ظ�������ջ�ĳ���
    return S.top-S.base;
}

Status GetTop(SqStack S,SElemType *e)
{ // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    if(S.top>S.base)
    {
        *e=*(S.top-1);
        return OK;
    }
    else
        return ERROR;
}

Status Push(SqStack *S,SElemType e)
{ // ����Ԫ��eΪ�µ�ջ��Ԫ��
    if(S->top-S->base>=S->stacksize) // ջ����׷�Ӵ洢�ռ�
    {
        S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S->base)
            return ERROR; // �洢����ʧ��
        S->top=S->base+S->stacksize;
        S->stacksize +=STACKINCREMENT;
    }
    *(S->top)++=e;
    return OK;
}

Status Pop(SqStack *S,SElemType *e)
{ // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
    if(S->top==S->base)
        return ERROR;
    *e=*--S->top;
    return OK;
}

Status StackTraverse(SqStack S,Status(*visit)(SElemType))
{ // ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��
    // һ��visit()ʧ�ܣ������ʧ��
    while(S.top>S.base)
        visit(*S.base++);
    printf("\n");
    return OK;
}