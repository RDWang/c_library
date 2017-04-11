/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  LinkList.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月18日 
 *
 *    Description:  线性表的单链表存储结构
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
#ifndef _INCLUDE_LINKLIST_H_
#define _INCLUDE_LINKLIST_H_

#include "CdataStruct_type.h"

//定义线性表的数据结构
 typedef struct LNode
 {
   ElemType data;
   struct LNode *next;
 }LNode,*LinkList;

// typedef struct LNode * LinkList; // 另一种定义LinkList的方法

//导出单链存储方式线性表的所有函数接口
Status InitList(LinkList *L);
Status DestroyList(LinkList *L);
Status ClearList(LinkList L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType *e);
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));
Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e);
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e);
Status ListInsert(LinkList L,int i,ElemType e);
Status ListDelete(LinkList L,int i,ElemType *e);
Status ListTraverse(LinkList L,void(*vi)(ElemType));
void InsertAscend(LinkList L,ElemType e);
void InsertDescend(LinkList L,ElemType e);
Status HeadInsert(LinkList L,ElemType e);
Status EndInsert(LinkList L,ElemType e);
Status DeleteFirst(LinkList L,ElemType *e);
Status DeleteTail(LinkList L,ElemType *e);
Status DeleteElem(LinkList L,ElemType e);
Status ReplaceElem(LinkList L,int i,ElemType e);
Status CreatAscend(LinkList *L,int n);
Status GetFirstElem(LinkList L,ElemType *e);
 
#endif
