LIB = ar rcs
NAME = libft.a
MY_SOURCES = ft_isalpha.c \
			 	ft_isdigit.c  \
				ft_isalnum.c \
				ft_isprint.c \
				ft_memset.c \
				ft_strlen.c \
				ft_bzero.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memcpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_memmove.c \
				ft_atoi.c \
				ft_isascii.c \
				ft_strdup.c \
				ft_calloc.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_split.c \
				ft_itoa.c \
				ft_strcmp.c \

SRC_BONUS = 	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

BONUS_OBJ= $(SRC_BONUS:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS) libft.h
		$(LIB) $(NAME) $(MY_OBJECTS)
		
%.o: %.c
		gcc $(CFLAGS) -c -o $@ $<
		
all: $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
		ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
		rm -f $(MY_OBJECTS) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re