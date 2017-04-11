/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  CSTree.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��04��08�� 
 *
 *    Description:  // c6-5.h ���Ķ�������(���ӣ��ֵ�)�洢��ʾ
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
#ifndef _INCLUDE_CSTREE_H_
#define _INCLUDE_CSTREE_H_

#include "CdataStruct_type.h"

 typedef struct CSNode
 {
   TElemType data;
   CSNode *firstchild,*nextsibling;
 }CSNode,*CSTree;

#endif
