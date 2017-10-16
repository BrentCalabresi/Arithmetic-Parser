PROG = Driver
SRCS = Driver.c
OBJS = ${SRCS:%.c=%.o}

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
