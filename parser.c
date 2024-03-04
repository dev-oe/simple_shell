#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Duplicate characters from a string within a given range.
 * @pathstr: The original string to duplicate from.
 * @start: The starting index.
 * @stop: The ending index.
 *
 * Return: The duplicated string within the specified range.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = start, k = 0;

	while (i < stop)
	{
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
		i++;
	}
	buf[k] = '\0';

	return (buf);
}

/**
 * find_path - Finds the path to a command in a given path string.
 * @info: Pointer to info_t structure.
 * @pathstr: Path string to search for the command.
 * @cmd: Command to find in the path.
 * Return: Pointer to the path of the command if found, NULL otherwise.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			pos = i;
		}
		i++;
	}
	return (NULL);
}
