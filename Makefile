NAME=serverclient.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror
printf= ft_printf/libftprintf.a

SERVER2  = server_bonus
CLİENT2 = client_bonus

CLIENT = client
SERVER = server

all: $(SERVER) $(CLIENT)

$(NAME): $(SERVER) $(CLIENT) $(SERVER2) $(CLİENT2)

$(SERVER):
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(printf) -o $@

$(CLIENT):
	make -C ./ft_printf 
	$(CC) $(CFLAGS) client.c $(printf) -o $@

$(SERVER2):
	make -C ./ft_printf
	$(CC) $(CFLAGS) server_bonus.c $(printf) -o $@

$(CLIENT2):
	make -C ./ft_printf 
	$(CC) $(CFLAGS) client_bonus.c $(printf) -o $@

clean:
	make fclean -C ./ft_printf
	rm server client

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 