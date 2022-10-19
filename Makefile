SRCS		= ./complex.c ./draw_fractal.c ./hook.c ./julia.c ./main.c ./mandelbrot.c

INC			= ./fractol.h

OBJS		= $(SRCS:.c=.o)

CC			= gcc -g -O2
RM			= rm -f
CFLAGS		= -I mlx/
LIBS		= -L . -lmlx
MLX			= libmlx.a
NAME		= fractol

all:		$(NAME)

$(NAME):	 $(MLX) $(OBJS) $(INCS)
				@cp mlx/$(MLX) .
				gcc -g -framework AppKit -framework OpenGL ${CFLA2GS} ${OBJS} ${LIBS} ${MLX} -o fractol
				@echo "Done"

$(MLX):
				@make -C mlx 

clean:
				$(RM) $(OBJS)

fclean:
				$(RM) $(NAME) $(MLX) $(OBJS)
				@make clean -C mlx

re:			fclean $(NAME)

.PHONY:			all clean fclean re
