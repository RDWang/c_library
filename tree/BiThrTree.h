/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  BiThrTree.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��04��08�� 
 *
 *    Description:  // c6-3.h �������Ķ��������洢��ʾ
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
#ifndef _ICLUDE_BITHRTREE_H_
#define _ICLUDE_BITHRTREE_H_

#include "CdataStruct_type.h"

enum PointerTag // ö��
{Link,Thread}; // Link(0):ָ��,Thread(1):����
struct BiThrNode
{
    TElemType data;
    BiThrNode *lchild,*rchild; // ���Һ���ָ��
    PointerTag LTag,RTag; // ���ұ�־
};
typedef BiThrNode *BiThrTree;

#endif
