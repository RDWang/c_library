/*
 * =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  DuLinkList.h
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017年03月18日 
 *
 *    Description:  // c2-4.h 线性表的双向链表存储结构
 *                  双向循环链表
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

typedef struct DuLNode
{
    ElemType data;
    DuLNode *prior,*next;
}DuLNode,*DuLinkList;


#endif
