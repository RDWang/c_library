/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  SqBiTree.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年04月08日 
 *
 *    Description:  // c6-1.h 二叉树的顺序存储表示
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
#ifndef _INCLUDE_SQBITREE_H_
#define _INCLUDE_SQBITREE_H_

#include "CdataStruct_type.h"

#define MAX_TREE_SIZE 100 // 二叉树的最大结点数
typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0号单元存储根结点

struct position
{
    int level,order; // 结点的层,本层序号(按满二叉树计算)
};

#endif
