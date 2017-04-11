/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  GListHead.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��27�� 
 *
 *    Description:  c5-5.h ������ͷβ����洢��ʾ
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
#ifndef _INCLUDE_GLISTHEAD_H_
#define _INCLUDE_GLISTHEAD_H_

#include "CdataStruct_type.h"

typedef enum {ATOM,LIST} ElemTag; // ATOM==0:ԭ��,LIST==1:�ӱ�
typedef struct GLNode
{
    ElemTag tag; // ��������,��������ԭ�ӽ��ͱ���
    union // ԭ�ӽ��ͱ�������ϲ���
    {
        AtomType atom; // atom��ԭ�ӽ���ֵ��,AtomType���û�����
        struct
        {
            struct GLNode *hp,*tp;
        }ptr; // ptr�Ǳ����ָ����,prt.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β
    }data;
}*GList,GLNode; // ���������

//���������ӿ�
extern Status InitGList(GList *L);
extern void DestroyGList(GList *L);
extern Status CopyGList(GList *T,GList L);
extern int GListLength(GList L);
extern int GListDepth(GList L);
extern Status GListEmpty(GList L);
extern GList GetHead(GList L);
extern GList GetTail(GList L);
extern Status InsertFirst_GL(GList *L,GList e);
extern Status DeleteFirst_GL(GList *L,GList *e);
extern void Traverse_GL(GList L,void(*v)(AtomType));

#endif
