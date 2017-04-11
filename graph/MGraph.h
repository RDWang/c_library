/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  MGraph.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��04��05�� 
 *
 *    Description:  // c7-1.h ͼ������(�ڽӾ���)�洢��ʾ
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
#ifndef _INCLUDE_MGRAPH_H_
#define _INCLUDE_MGRAPH_H_

#include "CdataStruct_type.h"
#include "LinkQueue.h"

#define INFINITY INT_MAX // ���������ֵ�����
#define MAX_VERTEX_NUM 20 // ��󶥵����
#define MAX_NAME       56
#define MAX_INFO       256

typedef enum {DG,DN,AG,AN} GraphKind; // {����ͼ,������,����ͼ,������}

typedef struct
{
    VRType adj; // �����ϵ���͡�����Ȩͼ����1(��)��0(��)��ʾ���ڷ�
    // �Դ�Ȩͼ����ΪȨֵ����
    InfoType *info; // �û������Ϣ��ָ��(����)
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct MGraph
{
    VertexType vexs[MAX_VERTEX_NUM]; // ��������
    AdjMatrix arcs; // �ڽӾ���
    int vexnum,arcnum; // ͼ�ĵ�ǰ�������ͻ���
    GraphKind kind; // ͼ�������־
}MGraph;

//������������
extern Status CreateGraph(MGraph *G);
extern void DestroyGraph(MGraph *G);
extern VertexType GetVex(MGraph G,int v);
extern Status PutVex(MGraph *G,VertexType v,VertexType value);
extern int FirstAdjVex(MGraph G,VertexType v);
extern int NextAdjVex(MGraph G,VertexType v,VertexType w);
extern void InsertVex(MGraph *G,VertexType v);
extern Status DeleteVex(MGraph *G,VertexType v);
extern Status InsertArc(MGraph *G,VertexType v,VertexType w);
extern Status DeleteArc(MGraph *G,VertexType v,VertexType w);
extern void DFS(MGraph G,int v);
extern void DFSTraverse(MGraph G,Status(*Visit)(VertexType));
//extern void BFSTraverse(MGraph G,Status(*Visit)(VertexType));
extern void Display(MGraph G);
#endif
