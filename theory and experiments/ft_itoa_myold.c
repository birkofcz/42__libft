/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:49:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/01/29 15:06:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	str_size(int n)
{
	int i;

	i = 0;
	while (n)
    {
        n = n / 10;
        i++;
    }
	return (i);
}
static char *if_intmin(int n)
{
	char *result;

	if (n == -2147483648)
	{
		result = malloc(12 * sizeof(char));
		if (!result)
			return (NULL);
		ft_strlcpy(result, "-2147483648", 12);
	}
	return (result);
}
static char *if_zero(int n)
{
	char *result;

	if (n == 0)
	{
		result = malloc(2 * sizeof(char));
		if (!result)
			return (NULL);
	  	result[0] = '0';
		result[1] = '\0';
	}
	return (result);
}

static char *if_positive(int n)
{
	char *result;
	int size;
	int i;

	i = 0;
	size = str_size(n);
	if (n > 0)
	{
      result = malloc((size + 1) * sizeof(char));
	  if (!result)
	  	return (NULL);
	}	
	result[i + size] = '\0';
    while (size--)
    {
      result[i + size] = (n % 10) + '0';
      n = n / 10;
    }
    return (result);
}
static char *if_negative(int n)
{
	char *result;
	int size;
	int  i; 

	i = 0;
	size = str_size(n);
	if (n < 0)
    {
        result = malloc((size + 2) * sizeof(char));
		if (!result)
			return (NULL);
        n = n * -1;
        result[i] = '-';
        i++;
    }
    result[i + size] = '\0';
    while (size--)
    {
      result[i + size] = (n % 10) + '0';
      n = n / 10;
    }
    return (result);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return(if_intmin(n));
	if (n == 0)
		return (if_zero(n));
	if (n > 0)
		return (if_positive(n));
	if (n < 0)
		return (if_negative(n));
	return (0);
}

/* 
int main()
{
    int n = -2147483648;
    
    printf("Result: %s\n", ft_itoa(n));
    return (0);
} */