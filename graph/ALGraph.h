/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  ALGraph.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��04��07�� 
 *
 *    Description:  // c7-2.h ͼ���ڽӱ�洢��ʾ
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
#ifndef _INCLUDE_ALGRAPH_H_
#define _INCLUDE_ALGRAPH_H_

#include "CdataStruct_type.h"
#include "LinkQueue.h"

#define MAX_VERTEX_NUM 20
enum GraphKind{DG,DN,AG,AN}; // {����ͼ,������,����ͼ,������}
Boolean visited[MAX_VERTEX_NUM]; // ���ʱ�־����(ȫ����)
void(*VisitFunc)(char* v); // ��������(ȫ����)

typedef struct ArcNode
{
    int adjvex; // �û���ָ��Ķ����λ��
    struct ArcNode *nextarc; // ָ����һ������ָ��
    InfoType *info; // ����Ȩֵָ��
}ArcNode; // ����

typedef struct
{
    VertexType data; // ������Ϣ
    ArcNode *firstarc; // ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MAX_VERTEX_NUM]; // ͷ���

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum,arcnum; // ͼ�ĵ�ǰ�������ͻ���
    int kind; // ͼ�������־
}ALGraph;

#endif
