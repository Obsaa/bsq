NAME	=	bsq
CC		=	gcc

Dir_SOURCES	= 	sources
D_INCLUDES	=	includes
Dir_OBJ	=	objects

OBJETOS_F	=	-O3
Error_W_F	=	-Wall -Wextra -Werror
DEB	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

Flag_Files	:=	$(shell ls -1 $(Dir_SOURCES) | grep .c$$)
Flag_Objects	:=	$(Flag_Files:.c=.o)
Flag_Objects	:=	$(addprefix $(Dir_OBJ)/, $(Flag_Objects))

.PHONY: all clean fclean re

all: $(NAME)

$(Dir_OBJ)/%.o: $(Dir_SOURCES)/%.c $(D_INCLUDES)
	@$(MKDIR) $(Dir_OBJ)
	$(CC) -I$(D_INCLUDES) $(OBJETOS_F) $(Error_W_F) -c $< -o $@ $(DEB)

$(NAME): $(Flag_Objects)
	$(CC) -I$(D_INCLUDES) $(OBJETOS_F) $(Error_W_F) $(Flag_Objects) -o $@ $(DEB)

clean:
	$(RM) $(Dir_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
