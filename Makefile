NAME = push_swap

INC = push_swap.h

SRCS = push_swap.c \
	   ps_init.c \
	   ps_next.c \
	   ps_exit.c \
	   ps_presort.c \
	   ps_sort.c \
	   ps_utils.c \
	   ps_push.c \
	   ps_moves.c

SRCDIR = src
OBJDIR = objs
INCDIR = inc

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -MMD -MP
MEM = -fsanitize=address

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})
NORM = $(addprefix ${SRCDIR}/,${SRCS})
NORM += $(addprefix ${INCDIR}/,${INC})

DEP = ${OBJS:.o=.d}

all: ${NAME}

$(NAME): ${OBJS} 
	${CC} ${CFLAGS} ${MEM} ${OBJS} -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@

re: fclean all

norm:
	norminette ${NORM}

clean:
	@echo  "Cleaning push_swap objects\c"
	@rm -rf ${OBJDIR}
	@echo "\033[32m\t[OK]\033[0m"

fclean: clean
	@echo  "Removing push_swap\c"
	@rm -rf ${NAME}
	@echo "\033[32m\t\t[OK]\033[0m"

.PHONY : all clean re fclean norm

-include ${DEP}
