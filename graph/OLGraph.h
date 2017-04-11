/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  OLGraph.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��04��07�� 
 *
 *    Description:  // c7-3.h ����ͼ��ʮ������洢��ʾ
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
#ifndef _INCLUDE_OLGRAPH_H_
#define _INCLUDE_OLGRAPH_H_

#include "CdataStruct_type.h"
#include "SqQueue.h"

#define MAX_VERTEX_NUM 20
Boolean visited[MAX_VERTEX_NUM]; // ���ʱ�־����
Status(*VisitFunc)(VertexType); // ��������

typedef struct ArcBox // �����
{
    int tailvex,headvex; // �û���β��ͷ�����λ��
    ArcBox *hlink,*tlink; // �ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ�������
    InfoType *info; // �û������Ϣ��ָ��(����)
}ArcBox;

typedef struct VexNode // ������
{
    VertexType data;
    ArcBox *firstin,*firstout; // �ֱ�ָ��ö����һ���뻡�ͳ���
}VexNode;

typedef struct OLGraph
{
    VexNode xlist[MAX_VERTEX_NUM]; // ��ͷ����(����)
    int vexnum,arcnum; // ����ͼ�ĵ�ǰ�������ͻ���
}OLGraph;


#endif
