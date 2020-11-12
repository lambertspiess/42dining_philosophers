all :
	@clang -lpthread -D_REENTRANT -Wall -Wextra -Werror *.c -o philo_one

san:
	@clang -lpthread -D_REENTRANT -Wall -Wextra -Werror -fsanitize=address,undefined *.c -o san_philo_one

val:
	@clang -lpthread -D_REENTRANT -Wall -Wextra -Werror -ggdb3 *.c -o val_philo_one

clean :
	@rm -f *.o

fclean : clean
	@rm -f philo_one san_philo_one val_philo_one

re : fclean
	@make all

sanre : fclean
	@make san

valre : fclean
	@make val
