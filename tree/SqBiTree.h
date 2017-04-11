/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  SqBiTree.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��04��08�� 
 *
 *    Description:  // c6-1.h ��������˳��洢��ʾ
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

#define MAX_TREE_SIZE 100 // ���������������
typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0�ŵ�Ԫ�洢�����

struct position
{
    int level,order; // ���Ĳ�,�������(��������������)
};

#endif
