/*
 * =====================================================================================
 *      
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  LinkStack.c
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��28�� 
 *
 *    Description:  // bo3-5.cpp ��ջ(�洢�ṹ��c2-2.h����)�Ļ�������(9��)
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


#include "LinkStack.h"

Status StackTraverse(LinkStack S,void(*visit)(SElemType))
{ // ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��
    SElemType e;
    LinkStack temp,p=S;
    InitStack(temp); // ��ʼ��tempջ
    while(p->next)
    {
        GetTop(p,&e);
        Push(temp,e);
        p=p->next;
    }
    ListTraverse(temp,visit);
    return OK;
}
