/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  SqQueue.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��28�� 
 *
 *    Description:  // c3-3.h ���е�˳��洢�ṹ(������ѭ�����кͷ�ѭ������)
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
#ifndef _INCLUDE_SQQUEUE_H_
#define _INCLUDE_SQQUEUE_H_

#include "CdataStruct_type.h"

#define MAXQSIZE 5 // �����г���(����ѭ�����У������г���Ҫ��1)
typedef struct SqQueue
{
    QElemType *base; // ��ʼ���Ķ�̬����洢�ռ�
    int front; // ͷָ��,�����в���,ָ�����ͷԪ��
    int rear; // βָ��,�����в���,ָ�����βԪ�ص���һ��λ��
}SqQueue;

#endif
