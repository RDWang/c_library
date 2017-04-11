/*
 * =====================================================================================
 *      
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  LinkStack.c
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月28日 
 *
 *    Description:  // bo3-5.cpp 链栈(存储结构由c2-2.h定义)的基本操作(9个)
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
{ // 从栈底到栈顶依次对栈中每个元素调用函数visit()。
    SElemType e;
    LinkStack temp,p=S;
    InitStack(temp); // 初始化temp栈
    while(p->next)
    {
        GetTop(p,&e);
        Push(temp,e);
        p=p->next;
    }
    ListTraverse(temp,visit);
    return OK;
}
