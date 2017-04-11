/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  C2-3.H
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:   ���Ա�ľ�̬������洢�ṹ
 *                   ˳���ʾ
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

#define MAXSIZE 100 // �������󳤶�

//�������Ա�����ݽṹ
typedef struct
{
    ElemType data;
    int cur;
}component,SLinkList[MAXSIZE];


 //����˳��洢��ʽģ����ʽ���Ա�����к����ӿ�
 void InitList(SLinkList L);
 Status ClearList(SLinkList L);
 Status ListEmpty(SLinkList L);
 int ListLength(SLinkList L);
 Status GetElem(SLinkList L,int i,ElemType *e);
 int LocateElem(SLinkList L,ElemType e);
 Status PriorElem(SLinkList L,ElemType cur_e,ElemType *pre_e);
 Status NextElem(SLinkList L,ElemType cur_e,ElemType *next_e);
 Status ListInsert(SLinkList L,int i,ElemType e);
 Status ListDelete(SLinkList L,int i,ElemType *e);
 Status ListTraverse(SLinkList L,void(*vi)(ElemType));
 
#endif
