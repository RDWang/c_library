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

 typedef struct LNode // �������
 {
   ElemType data;
   LNode *next;
 }*Link,*Position;

 struct LinkList // ��������
 {
   Link head,tail; // �ֱ�ָ�����������е�ͷ�������һ�����
   int len; // ָʾ��������������Ԫ�صĸ���
 };

#endif
