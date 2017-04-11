/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  GListHead.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月27日 
 *
 *    Description:  c5-5.h 广义表的头尾链表存储表示
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
#ifndef _INCLUDE_GLISTHEAD_H_
#define _INCLUDE_GLISTHEAD_H_

#include "CdataStruct_type.h"

typedef enum {ATOM,LIST} ElemTag; // ATOM==0:原子,LIST==1:子表
typedef struct GLNode
{
    ElemTag tag; // 公共部分,用于区分原子结点和表结点
    union // 原子结点和表结点的联合部分
    {
        AtomType atom; // atom是原子结点的值域,AtomType由用户定义
        struct
        {
            struct GLNode *hp,*tp;
        }ptr; // ptr是表结点的指针域,prt.hp和ptr.tp分别指向表头和表尾
    }data;
}*GList,GLNode; // 广义表类型

//导出函数接口
extern Status InitGList(GList *L);
extern void DestroyGList(GList *L);
extern Status CopyGList(GList *T,GList L);
extern int GListLength(GList L);
extern int GListDepth(GList L);
extern Status GListEmpty(GList L);
extern GList GetHead(GList L);
extern GList GetTail(GList L);
extern Status InsertFirst_GL(GList *L,GList e);
extern Status DeleteFirst_GL(GList *L,GList *e);
extern void Traverse_GL(GList L,void(*v)(AtomType));

#endif
