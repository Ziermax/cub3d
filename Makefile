#<-------------------------------|VARIABLES|---------------------------------->#

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = -lXext -lX11 -lm -lz

#<---------------------------------|FILES|------------------------------------>#

LIBFT = ./Libft/libft.a
LIBMLX = ./minilibx/libmlx.a

SRC_F = main.c
#	MAXI FILES
SRC_F += drawing.c mlx_events.c mlx_image_utils.c mlx_init.c color.c struct_destroy.c casting.c
#	CAMILA FILES
SRC_F += parser.c
SRC_D = ./sources/

OBJ_F = ${SRC_F:.c=.o}
OBJ_D = ./objects/
OBJ = ${addprefix ${OBJ_D}, ${OBJ_F}}

DEP_F = ${SRC_F:.c=.d}
DEP_D = ./dependencies/
DEP = ${addprefix ${DEP_D}, ${DEP_F}}

#<---------------------------------|COLORS|----------------------------------->#

DF = \033[0;39m#		Default
RED= \033[0;31m#		Red
BRED= \033[1;31m#		Bold Red
BBLUE= \033[1;34m#		Bold Blue
BYELLOW= \033[1;33m#	Bold Yellow
BIPRPL = \033[1;95m#	Purple
BCYAN= \033[1;36m#		Bold Cyan
BIRED= \033[1;91m#		Bold Intense Red
BIGREEN= \033[1;92m#	Bold Intense Green
BBLACK= \033[1;30m#		Bold Black

#<---------------------------------|RULES|------------------------------------>#

all: libmlxmake libftmake ${NAME}

${NAME}: ${OBJ_D} ${DEP_D} ${OBJ} ${LIBFT} 
	@echo "\n${RED}Compiling program:${DF}"
	@echo "${BCYAN}${CC} ${BBLUE}${CFLAGS} ${MLXFLAGS} \
	${BIGREEN}${OBJ_F} ${BIPRPL}${LIBFT} ${LIBMLX} \
	${BCYAN} ${BCYAN}-o ${RED}${NAME}${DF}"
	@${CC} ${CFLAGS} ${MLXFLAGS} ${OBJ} ${LIBFT} ${LIBMLX} -o ${NAME}

libmlxmake:
	@echo "${BCYAN}### LIBMLX ###${BIGREEN}"
	@make -C minilibx --no-print-directory
	@echo "${BCYAN}### ${BIPRPL}libmlx.a ${BCYAN}made ---${DF}\n"

libftmake:
	@echo "${BCYAN}### LIBFT ###${BIGREEN}"
	@make -C Libft --no-print-directory
	@echo "${BCYAN}### ${BIPRPL}libft.a ${BCYAN}made ---${DF}\n"

${OBJ_D}%.o: ${SRC_D}%.c Makefile
	@${CC} ${CFLAGS} -MMD -c $< -o $@
	@mv ${@:.o=.d} ${DEP_D}
	@echo "${BCYAN}${CC} ${BBLUE}${CFLAGS} -MMD ${BCYAN}-c \
	${BIRED}$< ${BCYAN}-o ${BIGREEN}$@${DF}"
	@echo "${BCYAN}mv ${BYELLOW}${@:.o=.d} ${BCYAN}${DEP_D}${DF}"

${OBJ_D}:
	@mkdir ${OBJ_D}
	@echo "${BCYAN}mkdir ${BCYAN}${OBJ_D}${DF}"

${DEP_D}:
	@mkdir ${DEP_D}
	@echo "${BCYAN}mkdir ${BCYAN}${DEP_D}${DF}"

#<---------------------------------|PHONY|------------------------------------>#

clean:
	@echo "${BCYAN}### LIBFT fclean ###${DF}"
	@make fclean -C Libft --no-print-directory
	@echo "${BCYAN}### LIBFT cleaned ---${DF}\n"
	@echo "${BCYAN}### LIBMLX fclean ###${DF}"
	@make clean -C minilibx --no-print-directory
	@echo "${BCYAN}### LIBMLX cleaned ---${DF}\n"
	@rm -rf ${OBJ_D} ${DEP_D}
	@echo "${RED}rm -rf ${BIGREEN}OBJECTS: ${OBJ_F}${DF}"
	@echo "${RED}rm -rf ${BYELLOW}DEPENDENCIES: ${DEP_F}${DF}"

fclean: clean
	@rm -rf ${NAME}
	@rm -rf .rl_confi
	@echo "${RED}rm -rf ${RED}PROGRAM: ${NAME}${DF}\n"

re: fclean all

-include ${DEP}

.PHONY: all clean fclean re
#<---------------------------------------------------------------------------->#

