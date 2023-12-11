CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f
NAME = fdf
NAME_BONUS = fdf_bonus
LIBS = -lm -framework OpenGL -framework AppKit

SRCS = minilibx/libmlx.a \
						src/fdf.c \
                        src/algoritm_utils.c \
						src/convert.c \
						src/free_func.c \
						src/read_map.c \
						src/ft_split.c \
						src/conversion_utils.c \
						get_next_line/*.c \
						ft_printf/*.c \
						src/draw_line.c \
						src/gradient_color.c \
						src/draw_utils.c \
						src/front_and_last.c \
						src/handle_keypress.c \
						src/close_win.c 


SRCS_BONUS = minilibx/libmlx.a \
						src_bonus/keyboard_utils_bonus.c \
						src_bonus/fdf_bonus.c \
                        src_bonus/algoritm_utils_bonus.c \
						src_bonus/convert_bonus.c \
						src_bonus/free_func_bonus.c \
						src_bonus/read_map_bonus.c \
						src_bonus/ft_split.c \
						src_bonus/conversion_utils_bonus.c \
						get_next_line/*.c \
						ft_printf/*.c \
						src_bonus/draw_line_bonus.c \
						src_bonus/gradient_color_bonus.c \
						src_bonus/draw_utils_bonus.c \
						src_bonus/front_and_last_bonus.c \
						src_bonus/handle_keypress_bonus.c \
						src_bonus/close_win_bonus.c \
						src_bonus/rotation_matrix_bonus.c \
						src_bonus/print_menu_bonus.c \
						src_bonus/mouse_bonus.c
						


${NAME}: mlx
	@echo "$(BBlue)Compiling $^ -I $(FLAG) -o $(NAME)"
	${CC} ${CFLAGS} ${SRCS} ${LIBS} -o ${NAME}
	@echo ""
	@echo " $(BPink)$(ascii)"

bonus: mlx
	@echo "$(BBlue)Compiling Bonus $^ -I $(FLAG) -o $(NAME_BONUS)"
	${CC} ${CFLAGS} ${SRCS_BONUS} ${LIBS} -o ${NAME_BONUS}
	@echo ""
	@echo " $(BPink)$(ascii)"

BBlue=\033[1;34m
BPink=\033[1;38;5;205m
BRed=\033[1;31m

ascii=███████╗██████╗ ███████╗      ██╗    ██╗██╗██████╗ ███████╗███████╗██████╗  █████╗ ███╗   ███╗███████╗\n\
			██╔════╝██╔══██╗██╔════╝      ██║    ██║██║██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗████╗ ████║██╔════╝\n\
			█████╗  ██║  ██║█████╗  █████╗██║ █╗ ██║██║██████╔╝█████╗  █████╗  ██████╔╝███████║██╔████╔██║█████╗  \n\
			██╔══╝  ██║  ██║██╔══╝  ╚════╝██║███╗██║██║██╔══██╗██╔══╝  ██╔══╝  ██╔══██╗██╔══██║██║╚██╔╝██║██╔══╝  \n\
			██║     ██████╔╝██║           ╚███╔███╔╝██║██║  ██║███████╗██║     ██║  ██║██║  ██║██║ ╚═╝ ██║███████╗\n\
			╚═╝     ╚═════╝ ╚═╝            ╚══╝╚══╝ ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n


all: ${NAME}

mlxClean:
	make clean -C ./minilibx

mlx:
	make all -C ./minilibx

clean: fclean

fclean: mlxClean
	@echo "$(BRed)fclean $(NAME)"
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

re: fclean all

.PHONY: all bonus clean fclean re
