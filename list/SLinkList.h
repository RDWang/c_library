/*
 * =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  C2-3.H
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:   ���Ա�ľ�̬������洢�ṹ
 *                   ˳���ʾ
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
#ifndef _INCLUDE_SLINKLIST_H_
#define _INCLUDE_SLINKLIST_H_

#include "CdataStruct_type.h"

#define MAXSIZE 100 // �������󳤶�
typedef struct
{
    ElemType data;
    int cur;
}component,SLinkList[MAXSIZE];

#endif
