/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  MGraph.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年04月05日 
 *
 *    Description:  // c7-1.h 图的数组(邻接矩阵)存储表示
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

#define INFINITY INT_MAX // 用整型最大值代替∞
#define MAX_VERTEX_NUM 20 // 最大顶点个数
#define MAX_NAME       56
#define MAX_INFO       256

typedef enum {DG,DN,AG,AN} GraphKind; // {有向图,有向网,无向图,无向网}

typedef struct
{
    VRType adj; // 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否；
    // 对带权图，则为权值类型
    InfoType *info; // 该弧相关信息的指针(可无)
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct MGraph
{
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点向量
    AdjMatrix arcs; // 邻接矩阵
    int vexnum,arcnum; // 图的当前顶点数和弧数
    GraphKind kind; // 图的种类标志
}MGraph;

//导出函数定义
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
