/*
 * =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  RealLinkList.h
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:  // c2-5.h ��ͷ����������������
 *                  ѭ��������
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

#ifndef _INCLUDE_REALLINKLIST_H_
#define _INCLUDE_REALLINKLIST_H_
#include "CdataStruct_type.h"

//�������Ա�����ݽṹ
 typedef struct LNode // �������
 {
   ElemType data;
   struct LNode *next;
 }LNode,*Link,*Position;

 typedef struct linklist // ��������
 {
   Link head,tail; // �ֱ�ָ�����������е�ͷ�������һ�����
   int len; // ָʾ��������������Ԫ�صĸ���
 }LinkList;
//typedef struct linklist LinkList;

 //���������洢��ʽѭ�����Ա�����к����ӿ�
 Status InitList(LinkList *L);
 Status ClearList(LinkList *L);
 Status DestroyList(LinkList *L);
 Status InsFirst(LinkList *L,Link h,Link s);
 Status DelFirst(LinkList *L,Link h,Link *q);
 Status Append(LinkList *L,Link s);
 Link PriorPos(LinkList L,Link p);
 Status Remove(LinkList *L,Link *q);
 Status InsBefore(LinkList *L,Link *p,Link s);
 Status InsAfter(LinkList *L,Link *p,Link s);
 Status SetCurElem(Link p,ElemType e);
 ElemType GetCurElem(Link p);
 Status ListEmpty(LinkList L);
 int ListLength(LinkList L);
 Link GetHead(LinkList L);
 Link GetLast(LinkList L);
 Link NextPos(Link p);
 Status LocatePos(LinkList L,int i,Link *p);
 Link LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType));
 Status ListTraverse(LinkList L,void(*visit)(ElemType));
 Status OrderInsert(LinkList *L,ElemType e,int (*comp)(ElemType,ElemType));
 Status OrderLocateElem(LinkList L,ElemType e,Link *q,int(*compare)(ElemType,ElemType));
 
#endif
