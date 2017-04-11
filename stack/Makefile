#Makefile文件

SHARE-OBJ = SqStack.so LinkStack.so

all:${SHARE-OBJ} mv_obj

include ../Makefile.include

obj += ${SHARE-OBJ}

LinkStack.so:LinkStack.o
	${CC} -shared -L../lib -llinklist -o $@ $<
