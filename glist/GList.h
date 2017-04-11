/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  GList.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��27�� 
 *
 *    Description:  // c5-6.h ��������չ��������洢��ʾ
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
#ifndef _INCLUDE_GLIST_H_
#define _INCLUDE_GLIST_H_

#include "CdataStruct_type.h"
#include "HString.h"

typedef enum {ATOM,LIST} ElemTag; // ATOM==0:ԭ��,LIST==1:�ӱ�
typedef struct GLNode
{
    ElemTag tag; // ��������,��������ԭ�ӽ��ͱ���
    union // ԭ�ӽ��ͱ�������ϲ���
    {
        AtomType atom; // ԭ�ӽ���ֵ��
        struct GLNode *hp; // ����ı�ͷָ��
    }data;
    struct GLNode *tp; // �൱�����������next,ָ����һ��Ԫ�ؽ��
}*GList,GLNode; // ���������GList��һ����չ����������

#endif
