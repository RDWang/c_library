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

 typedef struct LNode // 结点类型
 {
   ElemType data;
   LNode *next;
 }*Link,*Position;

 struct LinkList // 链表类型
 {
   Link head,tail; // 分别指向线性链表中的头结点和最后一个结点
   int len; // 指示线性链表中数据元素的个数
 };

#endif
