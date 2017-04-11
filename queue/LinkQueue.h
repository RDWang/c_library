/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  LinkQueue.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月28日 
 *
 *    Description:  // c3-2.h 单链队列－－队列的链式存储结构
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

#ifndef _INCLUDE_LINKQUEUE_H_
#define _INCLUDE_LINKQUEUE_H_

#include "CdataStruct_type.h"

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct LinkQueue
{
    QueuePtr front,rear; // 队头、队尾指针
}LinkQueue;

//导出函数接口
Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q,QElemType *e);
Status EnQueue(LinkQueue *Q,QElemType e);
Status DeQueue(LinkQueue *Q,QElemType *e);
Status QueueTraverse(LinkQueue Q,void(*vi)(QElemType));

#endif
