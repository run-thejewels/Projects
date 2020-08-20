#include "fdf.h"

int   get_y(char* f_name)
{
  char  *line;
  int   fd;
  int   y;

  fd = open(f_name, O_RDONLY, 0);
  y = 0;
  while(get_next_line(fd, &line))
  {
    y++;
    free(line);
  }
  close(fd);
  return (y);
}

int   get_x(char* f_name)
{
  char  *line;
  int   fd;
  int   x;

  fd = open(f_name, O_RDONLY, 0);
  get_next_line(fd, &line);
  x = x_count(line);
  close(fd);
  free(line);
  return(x);
}

void fill_matrix(int *z, char *line)
{
  char **nums;
  int i;

  nums = ft_strsplit(line, ' ');
  i = 0;
  while (nums[i])
  {
    z[i] = ft_atoi(nums[i]);
    free(nums[i]);
    i++;
  }
  free(nums);
}

void  read_file(char* f_name, fdf* data)
{
  int fd;
  int i;
  char *line;

  data->x = get_x(f_name);
  data->y = get_y(f_name);
  data->z = (int**)malloc(sizeof(int*) * (data->y + 1));
  i = 0;
  while (i <= data->y)
    data->z[i++] = (int*)malloc(sizeof(int) * (data->x +1));
  fd = open(f_name, O_RDONLY, 0);
  i = 0;
  while (get_next_line(fd, &line))
  {
    fill_matrix(data->z[i], line);
    free(line);
    i++;
  }
  close(fd);
  data->z[i] = NULL;
}
