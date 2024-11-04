
#ifndef PHILO_H
# define PHILO_H

//---------------------------------LIBS---------------------------------------
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"

# define	SUCCESS				0
# define	FAILURE				1
# define	PHILO_MAX			250
# define	PHILO_MAX_STR		"250"

# ifndef 	DEBUG_FORMATTING
#  define 	DEBUG_FORMATTING 	0
# endif
//
# define 	MALLOC_ERR			"%s error: Memory allocation failed\n"
# define 	EXIT_FAIL			"%s error: "
# define	MUTEX_ERROR			"%s error: Could not create mutex.\n"
# define	THREAD_ERROR		"%s error: Could not create thread.\n"
//
# define	PARAMS				"%s usage: please use ./philo <number_of_philosophers> \
									<time_to_die> <time_to_eat> <time_to_sleep> \
									[number_of_times_each_philosopher_must_eat]\n"
//
# define	DIGIT_INPUT_ERROR 	"%s invalid input: %s: \
									the range should be between 0 and 2147483647.\n"
//
# define	ERROR_INPUT_FLOW	"%s invalid input: \
									there must be between 1 and %s philosophers.\n"
//


//---------------------------------STRUCT----------------------------------

typedef struct s_philo t_philo;

typedef struct s_table
{
    time_t      start_t;
    int             	number_of_philosophers;
    int             	time_to_die;
    int             	time_to_eat;
    int             	time_to_sleep;
	int					times_must_eat;
    bool				sim_stop;
	pthread_mutex_t		sim_stop_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		*fork_locks;
	t_philo				**philos;
	time_t				start_time;
	pthread_t			grim_reaper;
}	t_table;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	pthread_mutex_t		meal_time_lock;
	time_t				last_meal;
	t_table				*table;
}	t_philo;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}	t_status;

//--------------------------------FUNCTIONS-----------------------------------


//---------------------------------return-------------------------------------
int		error_failure(char *str, char *details, t_table *table);
void    *null_error(char *str, char *details, t_table *table);
int		message(char *str, char *detail, int exit_status);
//--------------------------------output--------------------------------------
void    write_outcome(t_table *table);


#endif