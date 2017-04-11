/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  LinkList.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:  ���Ա�ĵ�����洢�ṹ
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

//�������Ա�����ݽṹ
 typedef struct LNode
 {
   ElemType data;
   struct LNode *next;
 }LNode,*LinkList;

// typedef struct LNode * LinkList; // ��һ�ֶ���LinkList�ķ���

//���������洢��ʽ���Ա�����к����ӿ�
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
