/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:56:41 by tdelgran          #+#    #+#             */
/*   Updated: 2022/12/06 23:57:49 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *params, ...)
{
    int i;
    va_list arg;
    int stock;
    
    stock = 0;
    va_start(arg, params);
    i = 0;
    while (params[i])
    {
        if (params[i] == '%')
        {
            stock += printf_conversion(arg, params[i + 1]);
            i++;
        }
        format_char(params[i]);
        i++;
    }
    va_end(arg);
   return (stock); 
}