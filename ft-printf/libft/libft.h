/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 13:45:49 by wupdegra          #+#    #+#             */
/*   Updated: 2020/07/07 13:07:42 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		ft_putnstr(char *str, int n);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int num);
char	*ft_hextoa(unsigned int num, int letter);
char	*ft_hexlltoa(unsigned long long num);

#endif
