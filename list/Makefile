#Makefile文件

#定义全局变量
SHARE-OBJ = SqList.so SLinkList.so LinkList.so RealLinkList.so DuLinkList.so
#SHARE-OBJ += SLinkListAttr.so

#定义全局的编译选项
CC ?=gcc
CC-CFLAG += -Wall

#处理中间变量
OBJECT-TMP = ${patsubst %.so,%.o,${SHARE-OBJ}}
SRC-TMP = ${patsubst %.so,%.c,${SHARE-OBJ}}

all:${SHARE-OBJ}

#${OBJECT-TMP}:${SRC-TMP}
#	${CC} -I../ -o $@ -c $<

#${SHARE-OBJ}:${OBJECT-TMP}
#	${CC}  -shared -o $@ $<

%.so:%.o
	${CC}  -shared -o $@ $<

%.o:%.c
	${CC} -I../ ${CC-CFLAG} -o $@ -c $<


clean:
	rm -fr *.o ${SHARE-OBJ}

