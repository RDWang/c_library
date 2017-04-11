/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  PTree.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��04��08�� 
 *
 *    Description:  // c6-4.h ����˫�ױ�洢��ʾ
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
    int parent; // ˫��λ����
}PTNode;

typedef struct PTree
{
    PTNode nodes[MAX_TREE_SIZE];
    int n; // �����
}PTree;

#endif
