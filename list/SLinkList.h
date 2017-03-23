/*
 * =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  C2-3.H
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017年03月18日 
 *
 *    Description:   线性表的静态单链表存储结构
 *                   顺序表示
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
#ifndef _INCLUDE_SLINKLIST_H_
#define _INCLUDE_SLINKLIST_H_

#include "CdataStruct_type.h"

#define MAXSIZE 100 // 链表的最大长度
typedef struct
{
    ElemType data;
    int cur;
}component,SLinkList[MAXSIZE];

#endif
