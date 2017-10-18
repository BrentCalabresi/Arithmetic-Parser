PROG = expr
SRCS = Driver.c RDP.c Calculator.c TableParser.c
OBJS = ${SRCS:%.c=%.o}

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
