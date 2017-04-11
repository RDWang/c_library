/*
 * =====================================================================================
 *      
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  GListHead.c
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月27日 
 *
 *    Description:  // bo5-5.cpp 广义表的头尾链表存储(存储结构由c5-5.h定义)的基本操作(11个)
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
#include "GListHead.h"

Status InitGList(GList *L)
{ // 创建空的广义表L
    *L=NULL;
    return OK;
}

void DestroyGList(GList *L) // 广义表的头尾链表存储的销毁操作
{ // 销毁广义表L
    GList q1,q2;
    if(*L)
    {
        if((*L)->tag==ATOM)
        {
            free(*L); // 删除原子结点
            *L=NULL;
        }
        else // 删除表结点
        {
            q1=(*L)->data.ptr.hp;
            q2=(*L)->data.ptr.tp;
            free(*L);
            *L=NULL;
            DestroyGList(&q1);
            DestroyGList(&q2);
        }
    }
}

Status CopyGList(GList *T,GList L)
{ // 采用头尾链表存储结构,由广义表L复制得到广义表T。算法5.6
    if(!L) // 复制空表
        *T=NULL;
    else
    {
        *T=(GList)malloc(sizeof(GLNode)); // 建表结点
        if(!*T)
            return ERROR;
        (*T)->tag=L->tag;
        if(L->tag==ATOM)
            (*T)->data.atom=L->data.atom; // 复制单原子
        else
        {
            CopyGList(&((*T)->data.ptr.hp),L->data.ptr.hp);
            // 复制广义表L->ptr.hp的一个副本T->ptr.hp
            CopyGList(&((*T)->data.ptr.tp),L->data.ptr.tp);
            // 复制广义表L->ptr.tp的一个副本T->ptr.tp
        }
    }
    return OK;
}

int GListLength(GList L)
{ // 返回广义表的长度,即元素个数
    int len=0;
    if(!L)
        return 0;
    if(L->tag==ATOM)
        return 1;
    while(L)
    {
        L=L->data.ptr.tp;
        len++;
    }
    return len;
}

int GListDepth(GList L)
{ // 采用头尾链表存储结构,求广义表L的深度。算法5.5
    int max,dep;
    GList pp;
    if(!L)
        return 1; // 空表深度为1
    if(L->tag==ATOM)
        return 0; // 原子深度为0
    for(max=0,pp=L;pp;pp=pp->data.ptr.tp)
    {
        dep=GListDepth(pp->data.ptr.hp); // 求以pp->a.ptr.hp为头指针的子表深度
        if(dep>max)
            max=dep;
    }
    return max+1; // 非空表的深度是各元素的深度的最大值加1
}

Status GListEmpty(GList L)
{ // 判定广义表是否为空
    if(!L)
        return TRUE;
    else
        return FALSE;
}

GList GetHead(GList L)
{ // 取广义表L的头
    GList h,p;
    if(!L)
    {
        printf("空表无表头!\n");
        exit(0);
    }
    p=L->data.ptr.tp;
    L->data.ptr.tp=NULL;
    CopyGList(&h,L);
    L->data.ptr.tp=p;
    return h;
}

GList GetTail(GList L)
{ // 取广义表L的尾
    GList t;
    if(!L)
    {
        printf("空表无表尾!\n");
        exit(0);
    }
    CopyGList(&t,L->data.ptr.tp);
    return t;
}

Status InsertFirst_GL(GList *L,GList e)
{ // 初始条件: 广义表存在
    // 操作结果: 插入元素e作为广义表L的第一元素(表头,也可能是子表)
    GList p=(GList)malloc(sizeof(GLNode));
    if(!p)
        return ERROR;
    p->tag=LIST;
    p->data.ptr.hp=e;
    p->data.ptr.tp=*L;
    *L=p;
    return OK;
}

Status DeleteFirst_GL(GList *L,GList *e)
{ // 初始条件: 广义表L存在
    // 操作结果: 删除广义表L的第一元素,并用e返回其值
    GList p;
    *e=(*L)->data.ptr.hp;
    p=*L;
    *L=(*L)->data.ptr.tp;
    free(p);
    return OK;
}

void Traverse_GL(GList L,void(*v)(AtomType))
{ // 利用递归算法遍历广义表L
    if(L) // L不空
    {
        if(L->tag==ATOM) // L为单原子
            v(L->data.atom);
        else // L为广义表
        {
            Traverse_GL(L->data.ptr.hp,v);
            Traverse_GL(L->data.ptr.tp,v);
        }
    }
}
