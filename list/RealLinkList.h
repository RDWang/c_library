/*
 * =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  RealLinkList.h
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017年03月18日 
 *
 *    Description:  // c2-5.h 带头结点的线性链表类型
 *                  循环单链表
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

//定义线性表的数据结构
 typedef struct LNode // 结点类型
 {
   ElemType data;
   struct LNode *next;
 }LNode,*Link,*Position;

 typedef struct linklist // 链表类型
 {
   Link head,tail; // 分别指向线性链表中的头结点和最后一个结点
   int len; // 指示线性链表中数据元素的个数
 }LinkList;
//typedef struct linklist LinkList;

 //导出单链存储方式循环线性表的所有函数接口
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
