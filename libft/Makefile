# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharing <fharing@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 14:03:15 by fharing           #+#    #+#              #
#    Updated: 2021/12/14 10:39:37 by fharing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
AR = ar crs
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h
SOURCES =	ft_atoi.c ft_isdigit.c ft_memccpy.c ft_putchar_fd.c ft_strdup.c ft_strncmp.c ft_toupper.c \
			ft_bzero.c ft_isprint.c ft_memchr.c ft_putendl_fd.c ft_strjoin.c ft_strnstr.c \
			ft_calloc.c ft_itoa.c ft_memcmp.c ft_putnbr_fd.c ft_strlcat.c ft_strrchr.c \
			ft_isalnum.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c ft_strtrim.c ft_isspace.c \
			ft_isalpha.c ft_memmove.c ft_split.c ft_strlen.c ft_substr.c ft_print_strlist.c \
			ft_isascii.c ft_memset.c ft_strchr.c ft_strmapi.c ft_tolower.c ft_free_strlist.c \
			ft_lstadd_back.c ft_lstmap.c ft_lstadd_front.c ft_lstnew.c ft_lstclear.c ft_lstsize.c \
			ft_lstlast.c ft_lstdelone.c ft_lstiter.c \

OBJECTS = $(SOURCES:.c=.o)

#build everything
all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

#creates a static library
$(NAME): $(OBJECTS) $(HEADER)
	$(AR) $(NAME) $(OBJECTS)

#removes all *.o files
clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

#removes all *.o files + libft.a
fclean: clean
	$(RM) $(NAME)

#removes all *.o files + libft.a and rebuild everything
re: fclean all
