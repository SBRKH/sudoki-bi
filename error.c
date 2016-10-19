/*
** error.c for error in /home/khoual_s/Documents/Rendu/C_Prog_Elem/RUSH/sudoki-bi
** 
** Made by Khoualdia Sabri
** Login   <khoual_s@pc-sabri-khoualdia>
** 
** Started on  Sat Feb 27 21:38:37 2016 Khoualdia Sabri
** Last update Sun Feb 28 22:37:55 2016 Enzo
*/

#include <stdio.h>
#include <string.h>

void	sudoku_insolvent()
{
  printf("%s\n", "|------------------|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "| X X X X X X X X X|");
  printf("%s\n", "|------------------|");
}

int	map_isbad(char **str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 9)
    {
      while (j <= 19)
	{
	  if (i == 0 || i == 8)
	    if (str[i][0] != '|' || str[i][19] != '|')
	      return (0);
	  if (str[i][j] != ' ' && str[i][j] != '|' && str[i][j] != '-'
	      && str[i][j] < '1' && str[i][j] > '9' && str[i][j] != '\n'
	      && str[i][j] != '\n')
	    return (0);
	  j++;
	}
      if (strlen(str[i]) != 20)
	return (0);
      i++;
    }
  return (1);
}

int	**complete_cti(char **tab, int **map)
{
  int	i;
  int	j;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  if (tab[i][j] != ' ')
	    map[i][j] = tab[i][j] - 48;
	  else
	    map[i][j] = 0;
	  j++;
	}
      i++;
    }
  return (map);
}
