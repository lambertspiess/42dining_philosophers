all :
	@clang -Wall -Wextra -Werror -lpthread -D_REENTRANT *.c -o philo_two

san:
	@clang -Wall -Wextra -Werror -lpthread -D_REENTRANT -fsanitize=address,undefined *.c -o san_philo_two

val:
	@clang -Wall -Wextra -Werror -lpthread -D_REENTRANT -ggdb3 *.c -o val_philo_two

clean :
	@rm -f *.o

fclean : clean
	@rm -f philo_two san_philo_two val_philo_two

re : fclean
	@make all

sanre : fclean
	@make san

valre : fclean
	@make val
