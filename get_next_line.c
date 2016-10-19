/*
** get_next_line.c for dfs in /home/enzo/rendu/prog/sudoki-bi
** 
** Made by Enzo
** Login   <enzo@epitech.net>
** 
** Started on  Sat Feb 27 11:39:42 2016 Enzo
** Last update Sun Feb 28 21:21:58 2016 Enzo
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void    my_strcpy(char *str1, char *str2)
{
  int   i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return;
  while (str2[i])
    {
      str1[i] = str2[i];
      i++;
    }
  str1[i] = '\0';
}

char   *my_realloc(char *str)
{
  char *ret;

  if ((ret = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  my_strcpy(ret, str);
  free(str);
  return (ret);
}

char		*get_next_line(const int fd)
{
  char		buffer;
  char		*res;
  int		i;

  buffer = 0;
  i = 0;
  if ((res = malloc(sizeof(char))) == NULL)
    return (NULL);
  while (buffer != '\n')
    {
      read(fd, &buffer, 1);
      if (buffer != '\n')
	{
	  res[i] = buffer;
	  if ((res = my_realloc(res)) == NULL)
	    return (NULL);
	  i++;
	}
      else
	res[i] = 0;
    }
  return (res);
}

