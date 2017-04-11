/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  BiThrTree.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年04月08日 
 *
 *    Description:  // c6-3.h 二叉树的二叉线索存储表示
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

enum PointerTag // 枚举
{Link,Thread}; // Link(0):指针,Thread(1):线索
struct BiThrNode
{
    TElemType data;
    BiThrNode *lchild,*rchild; // 左右孩子指针
    PointerTag LTag,RTag; // 左右标志
};
typedef BiThrNode *BiThrTree;

#endif
