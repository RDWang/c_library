/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  BiTree.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年04月08日 
 *
 *    Description:  // c6-2.h 二叉树的二叉链表存储表示
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
#ifndef _INCLUDE_BITREE_H_
#define _INCLUDE_BITREE_H_

#include "CdataStruct_type.h"
#include "LinkQueue.h"
#include "SqStack.h"

//树中的数据定义为字符型
#define CHAR
#define Nil  ""

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild; // 左右孩子指针
}BiTNode,*BiTree;

//导出二叉树的函数接口
extern Status InitBiTree(BiTree *T);
extern void DestroyBiTree(BiTree *T);
extern void CreateBiTree(BiTree *T);
extern Status BiTreeEmpty(BiTree T);
extern int BiTreeDepth(BiTree T);
extern TElemType Root(BiTree T);
extern TElemType Value(BiTree p);
extern void Assign(BiTree p,TElemType value);
extern TElemType Parent(BiTree T,TElemType e);
extern BiTree Point(BiTree T,TElemType s);
extern TElemType LeftChild(BiTree T,TElemType e);
extern TElemType RightChild(BiTree T,TElemType e);
extern TElemType LeftSibling(BiTree T,TElemType e);
extern TElemType RightSibling(BiTree T,TElemType e);
extern Status InsertChild(BiTree p,int LR,BiTree c);
extern Status DeleteChild(BiTree p,int LR);
extern void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType));
extern void InOrderTraverse(BiTree T,Status(*Visit)(TElemType));
extern Status InOrderTraverse1(BiTree T,Status(*Visit)(TElemType));
extern Status InOrderTraverse2(BiTree T,Status(*Visit)(TElemType));
extern void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType));
extern void LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType));

#endif
