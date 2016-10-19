/*
** su_load.c for su_load in /home/enzo/rendu/prog/sudoki-bi
** 
** Made by Enzo
** Login   <enzo@enzo-HP-EliteBook-840-G2>
** 
** Started on  Fri Feb 26 22:15:55 2016 Enzo
** Last update Sun Feb 28 22:36:28 2016 Enzo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sudo.h"

char     *pars_and_stack(char *str)
{
  int	i;
  int	j;
  char	*stack;

  j = 0;
  i = 0;
  if (NULL == (stack = malloc(sizeof(int) * 9)))
    return (NULL);
  while (str[i])
    {
      if ((str[i] > '0' || str[i] <= '9') && str[i] != '|')
	{
	  stack[j] = str[i];
	  j++;
	}
      else if (str[i] == ' ')
	{
	  stack[j] = 0;
	  j++;
	}
      i = i + 2;
    }
  return (stack);
}

char	**tab_ofchar(int fd)
{
  int	i;
  char	**tab;

  i = 0;
  if (NULL == (tab = malloc(sizeof(char*) * 9)))
    return (NULL);
  while (i < 8)
    {
      if (NULL == (tab[i] = malloc(sizeof(char) * 9)))
	return (NULL);
      i++;
    }
  get_next_line(fd);
  i = 0;
  while (i < 9)
    {
      tab[i] = get_next_line(fd);
      i++;
    }
  return (tab);
}

int	**from_chartoint(char **tab)
{
  int	i;
  int	**map;
  int   j;

  i = 0;
  if (NULL == (map = malloc(sizeof(int*) * 11)))
    return (NULL);
  while (i < 9)
    {
      if (NULL == (map[i] = malloc(sizeof(int) * 11)))
	return (NULL);
      i++;
    }
  map = complete_cti(tab, map);
  return (map);
}

void	aff_map(int **map)
{
  int	i;
  int	j;

  j = 0;
  printf("|------------------|\n");
  while (j < 9)
    {
      i = 0;
      printf("| ");
      while (i < 9)
	{
	  if (i == 8)
	    printf("%d|\n", map[j][i]);
	  else
	    printf("%d ", map[j][i]);
	  i = i + 1;
	}
      j = j + 1;
    }
  printf("|------------------|\n");
}

int	main()
{
  char	**tab;
  int	**map;
  int	fd;
  int	i;

  i = 0;
  fd = 0;
  tab = tab_ofchar(fd);
  if (map_isbad(tab) == 0)
    {
      printf("MAP ERROR\n");
      return (0);
    }
  while (i < 9)
    {
      tab[i] = pars_and_stack(tab[i]);
      i++;
    }
  map = from_chartoint(tab);
  if (validate(map, 0) == false)
    sudoku_insolvent();
  else
    aff_map(map);
}
