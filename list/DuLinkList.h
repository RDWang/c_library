/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  DuLinkList.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:  // c2-4.h ���Ա��˫������洢�ṹ
 *                  ˫��ѭ������
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
#ifndef _INCLUDE_DULINKLIST_H_
#define _INCLUDE_DULINKLIST_H_

#include "CdataStruct_type.h"

//�������Ա�����ݽṹ
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;

//����˫��ѭ�����Ա�����к����ӿ�
Status InitList(DuLinkList *L);
Status DestroyList(DuLinkList *L);
Status ClearList(DuLinkList L);
Status ListEmpty(DuLinkList L);
int ListLength(DuLinkList L);
Status GetElem(DuLinkList L,int i,ElemType *e);
int LocateElem(DuLinkList L,ElemType e,Status(*compare)(ElemType,ElemType));
Status PriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e);
Status NextElem(DuLinkList L,ElemType cur_e,ElemType *next_e);
DuLinkList GetElemP(DuLinkList L,int i);
Status ListInsert(DuLinkList L,int i,ElemType e);
Status ListDelete(DuLinkList L,int i,ElemType *e);
void ListTraverse(DuLinkList L,void(*visit)(ElemType));
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType));

#endif
