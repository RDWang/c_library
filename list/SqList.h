/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  SqList.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月18日 
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

#include "CdataStruct_type.h"


#define LIST_INIT_SIZE 10 // 线性表存储空间的初始分配量
#define LISTINCREMENT 2 // 线性表存储空间的分配增量

//定义线性表的数据结构
typedef struct sqlist
{
    ElemType *elem; // 存储空间基址
    int length; // 当前长度
    int listsize; // 当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

//导出顺序存储方式线性表的所有函数接口

/************************************************************************************ 
 * Function Name: InitList
 * Function Description:  
 * Inputs:
 * Outputs:
 * Notes:
 * **********************************************************************************/
extern Status InitList(SqList *);
extern Status DestroyList(SqList *L);
extern Status ClearList(SqList *L);
extern Status ListEmpty(SqList L);
extern int ListLength(SqList L);
extern Status GetElem(SqList L,int i,ElemType *e);
extern int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType));
extern Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e);
extern Status NextElem(SqList L,ElemType cur_e,ElemType *next_e);
extern Status ListInsert(SqList *L,int i,ElemType e);
extern Status ListDelete(SqList *L,int i,ElemType *e);
extern Status ListTraverse(SqList L,void(*vi)(ElemType*));
extern void InsertAscend(SqList *L,ElemType e);
extern void InsertDescend(SqList *L,ElemType e);
extern Status HeadInsert(SqList *L,ElemType e);
extern Status EndInsert(SqList *L,ElemType e);
extern Status DeleteFirst(SqList *L,ElemType *e);
extern Status DeleteTail(SqList *L,ElemType *e);
extern Status DeleteElem(SqList *L,ElemType e);
extern Status ReplaceElem(SqList L,int i,ElemType e);
extern Status CreatAscend(SqList *L,int n);
extern Status CreatDescend(SqList *L,int n);

#endif
