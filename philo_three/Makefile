all :
	@clang -Wall -Wextra -Werror -lpthread -D_REENTRANT *.c -o philo_three

san:
	@clang -Wall -Wextra -Werror -lpthread -D_REENTRANT -fsanitize=address,undefined *.c -o san_philo_three

val:
	@clang -Wall -Wextra -Werror -lpthread -D_REENTRANT -ggdb3 *.c -o val_philo_three

clean :
	@rm -f *.o

fclean : clean
	@rm -f philo_three san_philo_three val_philo_three

re : fclean
	@make all

sanre : fclean
	@make san

valre : fclean
	@make val
