#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

extern char **environ;
extern int EXIT_STATUS;

/**
 * struct alias_sh - struct aliases
 * @name: name of alias
 * @value: value of alias
 */
typedef struct alias_sh
{
	char *name;
	char *value;
} alias_sh;
int split_line(char *, char *, alias_sh *, int *);
char **_strtok(char *, char *);
int _getline(char **);
int _read(char **, char **);
void check_fork_error(char *, char **, char *);
int execute_cmd(char **, char *, char *);
void get_cmds(char ***, char *);
void _free(char **);
void *_calloc(unsigned int, unsigned int);
int _fork(char *, char **);
int args_count(char **);
char *valid_cmd(char *, char *, char **);
int args_count(char **);
char *check_ops(char **);
char *_getenv(char *);
int _handalias(alias_sh *, char *, int);
int echo(char **);
int error(char *, char **, char *, int);

/* printer functions */
int to_string(int, unsigned int);
int str_toprint(int, char *);
/* command executers */

/**
 * struct command_exe - structure
 * @cmd: command
 * @function_exe: function
 */
typedef struct command_exe
{
	char *cmd;
	int (*function_exe)(int, char **, char *, alias_sh *, int *, char **, char *);
} command_exe;
int command_select(const char *, char **, char *, alias_sh *,
		int *, char **, char *);
int handle_direc(int, char **, char *, alias_sh *, int *, char **, char *);
int func_exit(int, char **, char *, alias_sh *, int *, char **, char *);
int export(int, char **, char *, alias_sh *, int *, char **, char *);
int _unsetenv(int, char **, char *, alias_sh *, int *, char **, char *);
int env(int, char **, char *, alias_sh *, int *, char **, char *);
int _alias(int, char **, char *, alias_sh *, int *, char **, char *);

/* handle string functions */
char **_strtok(char *, char *);
char *_strpbrk(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
void del(char **);
size_t _strlen(char *);
int _strcmp(const char *, char *);
int _strncmp(const char *, char *, int);
char *_strstr(char *, char *);
char *_memcpy(char *, char *, unsigned int);
void sub_replacing(char *, char *, char *);
int _atoi(char *);
#endif
