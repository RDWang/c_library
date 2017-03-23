/*
 * =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  SqList.h
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description: ���Ա�Ķ�̬����˳��洢�ṹ
 *                 ˳��洢���Ա�
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

#ifndef _INCLUDE_SQLIST_H_
#define _INCLUDE_SQLIST_H_

#include "CDataStruct_type.h"

#define LIST_INIT_SIZE 10 // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 2 // ���Ա�洢�ռ�ķ�������

struct SqList
{
    ElemType *elem; // �洢�ռ��ַ
    int length; // ��ǰ����
    int listsize; // ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
};


#endif
