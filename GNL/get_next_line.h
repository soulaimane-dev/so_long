/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:20:58 by sbouabid          #+#    #+#             */
/*   Updated: 2023/11/22 09:29:57 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 19
# endif

# include <stdlib.h>
# include <fcntl.h> 
# include <unistd.h> 

char	*get_next_line(int fd);
char	*read_buffer(int fd, char *tmp);
char	*read_line(char *tmp);

char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, int len);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
#endif