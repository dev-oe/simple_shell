#include "shell.h"

/**
 * _myexit - Handle the exit command.
 * @info: Pointer to the info_t structure.
 *
 * Return:
 *    - Returns 1 if an illegal number is provided.
 *    - Returns -2 if a valid number is provided.
 */
int _myexit(info_t *info)
{
	int exitcheck;

	switch (info->argv[1] != NULL)
	{
	case 1:
		exitcheck = _erratoi(info->argv[1]);
		switch (exitcheck)
		{
		case (-1):
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		default:
			info->err_num = exitcheck;
			return (-2);
		}
	default:
		info->err_num = -1;
		return (-2);
	}
}

/**
 * _mycd - Handle the cd (change directory) command.
 * @info: Pointer to the info_t structure.
 * Return:
 *     - Returns 1 if an error occurs.
 *     - Returns 0 on success.
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	{	chdir_ret = chdir(info->argv[1]);
	}
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]);
		_putchar('\n');
	}
	else
	{	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **args;

	args = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*args);
	return (0);
}
