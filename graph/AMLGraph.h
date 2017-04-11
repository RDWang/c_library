/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  AMLGraph.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��04��07�� 
 *
 *    Description:  // c7-4.h ����ͼ���ڽӶ��ر�洢��ʾ
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
#ifndef _INCLUDE_AMLGRAPH_H_
#define _INCLUDE_AMLGRAPH_H_

#include "CdataStruct_type.h"
#include "LinkQueue.h"

#define MAX_VERTEX_NUM 20
enum VisitIf{unvisited,visited};
Boolean visite[MAX_VERTEX_NUM]; // ���ʱ�־����(ȫ����)
Status(*VisitFunc)(VertexType v);

typedef struct EBox
{
    VisitIf mark; // ���ʱ��
    int ivex,jvex; // �ñ����������������λ��
    struct EBox *ilink,*jlink; // �ֱ�ָ�������������������һ����
    InfoType *info; // �ñ���Ϣָ��
}EBox;

typedef struct VexBox
{
    VertexType data;
    EBox *firstedge; // ָ���һ�������ö���ı�
}VexBox;

typedef struct AMLGraph
{
    VexBox adjmulist[MAX_VERTEX_NUM];
    int vexnum,edgenum; // ����ͼ�ĵ�ǰ�������ͱ���
}AMLGraph;

#endif
