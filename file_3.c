#include "shell.h"

/**
 * _myhistory - Print the history list.
 * @info: Pointer to the info_t structure.
 *
 * Return: Always returns 0.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Unset an alias.
 * @info: Pointer to the info_t structure.
 * @str: Alias string to unset.
 *
 * Return: 1 if the alias is not found, 0 otherwise.
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int back;

	p = _strchr(str, '=');
	if (!p)
		return (1);

	c = *p;
	*p = 0;

	back = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));

	*p = c;
	return (back);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Print aliases or set new aliases.
 * @info: Pointer to the info_t structure.
 *
 * Return: Always returns 0.
 */
int _myalias(info_t *info)
{
	int i;
	char *p;
	list_t *node;

	if (info->argc == 1)
	{
		node = info->alias;
		for (; node; node = node->next)
		{
			print_alias(node);
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
		{
			set_alias(info, info->argv[i]);
		}
		else
		{
			node = node_starts_with(info->alias, info->argv[i], '=');
			print_alias(node);
		}
	}
	return (0);
}
