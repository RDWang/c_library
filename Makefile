#Makefile文件

SUB-DIR = list stack queue string glist tree graph

all:${SUB-DIR}
	for dir in ${SUB-DIR};do \
	${MAKE} -C $${dir}; \
	done

clean:${SUB-DIR}
	for dir in ${SUB-DIR};do  \
	${MAKE} -C $${dir} clean; \
	done
