.PHONY	:	all clean fclean re

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRC		=	sort_more.c sort.c ss_rr_rrr.c stack.c sort_three.c ra_rb_rra_rrb.c digit_utils.c sort_optimizer.c stack_parser.c sort_more_utils.c validation.c list_utils.c sort_three_utils.c sort_utils.c push_swap.c sa_sb_pa_pb.c utils.c

OBJ		=	sort_more.o sort.o ss_rr_rrr.o stack.o sort_three.o ra_rb_rra_rrb.o digit_utils.o sort_optimizer.o stack_parser.o sort_more_utils.o validation.o list_utils.o sort_three_utils.o sort_utils.o push_swap.o sa_sb_pa_pb.o utils.o

all		:	$(NAME)

$(NAME)	:	$(SRC) push_swap.h
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all
