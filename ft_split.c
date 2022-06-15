/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:57:42 by youssama          #+#    #+#             */
/*   Updated: 2022/06/15 23:03:10 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int length_big(char *s, char c)
{
    int i = 0;
    int l = 0;
    if (!s || !*s)
        return 0;
    while (s[i])
    {
        if (s[i] != c && s[i])
            l++;
        while (s[i] && s[i] != c)
            i++;
        i++;
    }
    printf("|%d|\n",l);
    return (l);
}

int length_small(char *s, char c)
{
    int i = 0;
    if (!s)
        return 0;
    while (s[i])
    {
        if (s[i] == c)
            break;
        i++;
    }
    printf("|%d|\n",i);
    return (i);
}

char **fret(char **tmp, int i)
{
    int j = 0;
    if (tmp)
    {
        while (j <= i)
            free(tmp[j++]);
        free (tmp);
    }
    return (0);
}

char **ft_split(char *s, char c)
{
    int i = 0;
    int j = 0;
    char **tmp;
    if (!s)
    {
        tmp = NULL;
        return (tmp);
    }
    while(*s && *s == c)
        s++;
    tmp = (char **)malloc(sizeof(tmp) * length_big(s, c));
    if (!tmp)
        return (0);
    while (*s)
    {
        j = 0;
        if (*s != c)
        { 
            tmp[i] = (char *)malloc(sizeof(char) * (length_small(s, c) + 1));
            if (!tmp[i])
                return (fret(tmp, i));
        }
        while(*s && *s != c)
            tmp[i][j++] = *s++;
        tmp[i++][j] = '\0';
        while (*s && *s == c)
            s++;
    }
    tmp[i] = NULL;
    return (tmp);
}
