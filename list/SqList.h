/*
 * =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  SqList.h
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017年03月18日 
 *
 *    Description: 线性表的动态分配顺序存储结构
 *                 顺序存储线性表
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

#ifndef _INCLUDE_SQLIST_H_
#define _INCLUDE_SQLIST_H_

#include "CDataStruct_type.h"

#define LIST_INIT_SIZE 10 // 线性表存储空间的初始分配量
#define LISTINCREMENT 2 // 线性表存储空间的分配增量

struct SqList
{
    ElemType *elem; // 存储空间基址
    int length; // 当前长度
    int listsize; // 当前分配的存储容量(以sizeof(ElemType)为单位)
};


#endif
