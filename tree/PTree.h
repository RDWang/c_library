/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  PTree.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年04月08日 
 *
 *    Description:  // c6-4.h 树的双亲表存储表示
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
#ifndef _INCLUDE_PTREE_H_
#define _INCLUDE_PTREE_H_

#include "CdataStruct_type.h"

#define MAX_TREE_SIZE 100
typedef struct PTNode
{
    TElemType data;
    int parent; // 双亲位置域
}PTNode;

typedef struct PTree
{
    PTNode nodes[MAX_TREE_SIZE];
    int n; // 结点数
}PTree;

#endif
