

CFLAGS += -Wall -Werror

TARGET = htbl
HDRS = htbl.h
SRCS = htbl.c htbl_main.c
OBJS = $(patsubst %.c,%.o,$(SRCS))

${TARGET}: ${OBJS}
	${CC} ${LDFLAGS} $^ -o $@ 

%.o: %.c ${HDRS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

test: ${TARGET}
	./${TARGET} 1 2 3 4 5 6