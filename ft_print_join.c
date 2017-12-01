/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:34:36 by hkang             #+#    #+#             */
/*   Updated: 2017/11/30 13:34:56 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_join(t_arg *pf, char *start, int i)
{
  char *temp;
  if (!pf->res)
  {
    pf->res = ft_strnew(i);
    pf->res = ft_strncpy(pf->res, start, i);
    pf->len = pf->len + i;
  }
  else
  {
  //  temp = pf->res;
  //  printf("{temp0%s}\n", temp);
  //  pf->res = ft_strnew((pf->len) + i);
  //  pf->res = ft_strncpy(pf->res, temp, pf->len);
  //  printf("{temp1%s}\n", pf->res);
    temp = pf->res;
    pf->res = ft_strsub(temp, 0, (pf->len + i));
    pf->res = ft_strncat((pf->res + pf->len), start, (size_t)i) - pf->len;
    pf->len = pf->len + i;
  //  printf("{temp%s}\n", pf->res);
    free (temp);
  }
}

/*void ft_print_alloc(t_arg *pf)
{
  char *temp;
  int l;

  l = pf->width + pf->prec + 10;
  if (!(pf->res))
    pf->res = ft_strnew(l);
  else
  {
    temp = pf->res;
    pf->res = ft_strsub(temp, 0, (pf->len + l));
    free (temp);
  }
}*/
