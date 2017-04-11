/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  AMLGraph.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年04月07日 
 *
 *    Description:  // c7-4.h 无向图的邻接多重表存储表示
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
Boolean visite[MAX_VERTEX_NUM]; // 访问标志数组(全局量)
Status(*VisitFunc)(VertexType v);

typedef struct EBox
{
    VisitIf mark; // 访问标记
    int ivex,jvex; // 该边依附的两个顶点的位置
    struct EBox *ilink,*jlink; // 分别指向依附这两个顶点的下一条边
    InfoType *info; // 该边信息指针
}EBox;

typedef struct VexBox
{
    VertexType data;
    EBox *firstedge; // 指向第一条依附该顶点的边
}VexBox;

typedef struct AMLGraph
{
    VexBox adjmulist[MAX_VERTEX_NUM];
    int vexnum,edgenum; // 无向图的当前顶点数和边数
}AMLGraph;

#endif
