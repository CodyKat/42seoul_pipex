/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:28:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/02 04:14:52 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MALLOC_ERROR 42
# define ERROR 1
# define TRUE 1
# define FALSE 0

typedef struct s_info
{
	int		is_heredoc;
	int		command_count;
	char	*infile_name;
	char	**command_arr;
	char	*outfile_name;
	char	**env_path;
	char	*limiter;
}	t_info;

//main.c
void	parsing(t_info *info, int argc, char *argv[], char *envp[]);

//child_process.c
void	first_child_process(t_info *info, int *fd, char **envp);
void	second_child_process(t_info *info, int *fd, char **envp);

//util_1.c
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *dst, int c, size_t len);
size_t	ft_strlen(const char *s);

// util_2.c
char	**ft_split(const char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// util_3.c
void	ft_error_arguments(void);

// processing.c
void	processing_with_heredoc(t_info *info);
void	processing_with_no_heredoc(t_info *info);
#endif
