/*
** sudo.h for sudo in /home/enzo/rendu/prog/sudoki-bi
** 
** Made by Enzo
** Login   <enzo@enzo-HP-EliteBook-840-G2>
** 
** Started on  Fri Feb 26 22:33:53 2016 Enzo
** Last update Sun Feb 28 22:25:18 2016 Enzo
*/

#ifndef SUDO_H_
# define SUDO_H_

#define true (1)
#define false (0)

char	*my_realloc(char *str);
char	*get_next_line(const int fd);
void	aff_map(int **map);
int	**fill_map(int fd);
int     validate(int **tab, int pos);
void    sudoku_insolvent();
int     map_isbad(char **str);
int     **complete_cti(char **tab, int **map);

#endif /* !SUDO_H_ */
