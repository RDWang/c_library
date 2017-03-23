/*
 * =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  LinkList.h
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:  ���Ա�ĵ�����洢�ṹ
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
#ifndef _INCLUDE_LINKLIST_H_
#define _INCLUDE_LINKLIST_H_

#include CdataStruct_type.h

 struct LNode
 {
   ElemType data;
   LNode *next;
 };

 typedef LNode *LinkList; // ��һ�ֶ���LinkList�ķ���

#endif
