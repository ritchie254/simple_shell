#ifndef ALX_H
#define ALX_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <stdarg.h>
#include <limits.h>
#ifndef BUFF_SIZE
#define BUFF_SIZE 300
#endif
/**
 * struct link - node that contains dirs
 * @dir: directory
 * @next: next node
 */
typedef struct link
{char *dir;
struct link *next;
} link_t;
/**
* struct formats - structucture for formats
* @ch: pointer to firts element.
* @func: The function associated.
*/
typedef struct formats
	{
		char *ch;
		int (*func)();
	} form;

char *execute_command(char *argm);
int puts_char(char c);
int _printf(const char *format, ...);
int p_aux_int(long int n, long int);
int print_str(va_list a);
int print_char(va_list a);
int pint(va_list a);
extern char **environ;
char *_getenv(const char *var_name);
char *str_copy(char *destination, char *source);
char *_strtok(char *string, char *delimeter);
ssize_t _getline(char **bufline, size_t *size, FILE *std);
char **splitline(char *cl);
void signal_ignore(int signals);
int _myexit(char *input);
int str_length(char *s);
int execute_process(char **argm, char **argv, int counter);
link_t *_add_node_at_end(link_t **head, char *n);
size_t _print_listint(link_t *h);
link_t *_link(char *a);
char *str_cat(char *dir, char *slash, char *arg);
char *_which(link_t **head, char *argue);
void release_list(link_t *head);
char *path_check(char *argm);
int _myenv(char *input, int counter, char **argv, char **env);
int get_char(void);
#endif /* ALX_H header file*/
