/*
** sudoku.c for sudoku in /home/khoual_s/Documents/Rendu/C_Prog_Elem/RUSH/sudoki-bi
** 
** Made by Khoualdia Sabri
** Login   <khoual_s@pc-sabri-khoualdia>
** 
** Started on  Sat Feb 27 10:44:21 2016 Khoualdia Sabri
** Last update Sun Feb 28 13:27:14 2016 Khoualdia Sabri
*/

#include <stdio.h>
#include <stdlib.h>
#include "sudo.h"

int	missingLine(int k, int **tab, int i)
{
  int	j;

  j = 0;
  while (j < 9)
    {
      if (tab[i][j] == k)
	return (false);
      j++;
    }
  return (true);
}

int	missingCol(int k, int **tab, int j)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      if (tab[i][j] == k)
	return (false);
      i++;
    }
  return (true);
}

int	missingBlock(int k, int **tab, int i, int j)
{
  int	l;
  int	m;

  l = i - (i % 3);
  m = j - (j % 3);
  i = l;
  j = m;
  while (i < (l + 3))
    {
      while (j < (m + 3))
	{
	  if (tab[i][j] == k)
	      return (false);
	  j++;
	}
      i++;
    }
  return (true);
}

int	validate(int **tab, int pos)
{
  int	i;
  int	j;
  int	k;

  if (pos == 81)
    return (true);
  i = pos / 9;
  j = pos % 9;
  if (tab[i][j])
    return (validate(tab, pos + 1));
  k = 1;
  while (k <= 9)
    {
      if (missingLine(k, tab, i) && missingCol(k, tab, j)
	  && missingBlock(k, tab, i, j))
	{
	  tab[i][j] = k;
	  if (validate(tab, pos + 1))
	    return (true);
	}
      k++;
    }
  tab[i][j] = 0;
  return (false);
}
