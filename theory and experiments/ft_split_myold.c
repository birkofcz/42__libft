/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_split_myold.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:48:45 by sbenes            #+#    #+#             */
/*   Updated: 2023/01/28 16:22:39 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Return value The array of new strings resulting from the split.
 * NULL if the allocation fails.
 * External functs. malloc, free
 * Description Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end
 * with a NULL pointer.
*/
#include <stdio.h>
#include "libft.h"
/* 
static char    *ft_strncpy(char *dest, const char *src, unsigned  int n)
{
    unsigned    int i;

    i = 0;

    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return(dest);
}
*/
static	int number_of_c(char const *s, char c)
{
	int number_of_c;
	int x;

	x = 0;
	number_of_c = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
		{
				number_of_c++;
				while (s[x] == c)
					x++;
		}
		x++;
	}
	return (number_of_c);
}

static	int	*find_c_indexes(char const *s, char c)
{
	int	*c_indexes;
	int	i;
	int	x;
	size_t len;

	len = number_of_c(s, c);
	c_indexes = (int *)malloc(len * sizeof(int));
	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			c_indexes[x] = i;
			x++;
			while (s[i+1] == c)
				i++;
		}
		i++;
	}
	
	return(c_indexes);
}

char	**ft_split(char const *s, char c)
{
	char **result;
	int *c_indexes;
	int n_delimiters;
	int	i;
	int start;
	int end;

	n_delimiters = number_of_c(s, c);
	c_indexes = find_c_indexes(s, c);
	result = (char **)malloc((n_delimiters + 2) * sizeof(char *)); //creates a array of strigs (char *ters) of size of n of delimiter chars in s + 2 = making space for NULL pointer at the end
	i = 0;
	start = 0;
	end = 0;

	while (i <= n_delimiters)
	{
		if (i == n_delimiters)
			end = ft_strlen(s);
		else
			end = c_indexes[i];
		result[i] = (char *)malloc((end - start + 1) *sizeof(char));
		ft_strlcpy(result[i], s + start, end - start);
		start = end + 1;
		i++;
	}	
	result[n_delimiters + 1] = NULL;
	return (result);
}


int	main()
{
	char s[] = "Hello  how are you?";
	char c = ' ';
	int *indexes;
	char **result;
	int i = 0;
	int x = 0;
	
	indexes = find_c_indexes(s, c);
	result = ft_split(s, c);

	printf("\n -- ft_split -- \n");
	printf("Original string: %s\n", s);
	printf("Character to be found: '%c'\n", c);
	printf("Number of character '%c' found: %d\n", c, number_of_c(s, c));
	printf("Found on indexes: ");
	while (indexes[x])
	{
		printf("[%d]", indexes[x]);
		x++;
	}
	printf("\nResulting array of strings = ");
	while (result[i])
	{
		printf("[%s] ", result[i]);
		i++;
	}
	printf("\n");


	return (0);
}
