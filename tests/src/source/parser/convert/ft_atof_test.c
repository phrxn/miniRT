/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:05:20 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 00:17:57 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atof_test.h"
#include "ft_atof.h"

#include "assertz.h"
#include <string.h>
#include "compare.h"

void	ft_atof_test1()
{
	create_subtitle("ft_atof_test1");

//str com um fracional
   assert_svalue(0, compare_double(.0, ft_atof(".0")), "test: .0");
   assert_svalue(0, compare_double(.1, ft_atof(".1")), "test: .1");
   assert_svalue(0, compare_double(.2, ft_atof(".2")), "test: .2");

//str com dois fracional
   assert_svalue(0, compare_double(.00, ft_atof(".00")), "test: .00");
   assert_svalue(0, compare_double(.01, ft_atof(".01")), "test: .01");
   assert_svalue(0, compare_double(.02, ft_atof(".02")), "test: .02");
   assert_svalue(0, compare_double(.10, ft_atof(".10")), "test: .10");
   assert_svalue(0, compare_double(.11, ft_atof(".11")), "test: .11");
   assert_svalue(0, compare_double(.12, ft_atof(".12")), "test: .12");
   assert_svalue(0, compare_double(.20, ft_atof(".20")), "test: .20");
   assert_svalue(0, compare_double(.21, ft_atof(".21")), "test: .21");
   assert_svalue(0, compare_double(.22, ft_atof(".22")), "test: .22");

//str com um decimal
  assert_svalue(0, compare_double(0, ft_atof("0")), "test: 0");
  assert_svalue(0, compare_double(1, ft_atof("1")), "test: 1");
  assert_svalue(0, compare_double(2, ft_atof("2")), "test: 2");
  assert_svalue(0, compare_double(0., ft_atof("0.")), "test: 0.");
  assert_svalue(0, compare_double(1., ft_atof("1.")), "test: 1.");
  assert_svalue(0, compare_double(2., ft_atof("2.")), "test: 2.");
 assert_svalue(0, compare_double(-0, ft_atof("-0")), "test: -0");
 assert_svalue(0, compare_double(-1, ft_atof("-1")), "test: -1");
 assert_svalue(0, compare_double(-2, ft_atof("-2")), "test: -2");
 assert_svalue(0, compare_double(-0., ft_atof("-0.")), "test: -0.");
 assert_svalue(0, compare_double(-1., ft_atof("-1.")), "test: -1.");
 assert_svalue(0, compare_double(-2., ft_atof("-2.")), "test: -2.");
 assert_svalue(0, compare_double(+0, ft_atof("+0")), "test: +0");
 assert_svalue(0, compare_double(+1, ft_atof("+1")), "test: +1");
 assert_svalue(0, compare_double(+2, ft_atof("+2")), "test: +2");
 assert_svalue(0, compare_double(+0., ft_atof("+0.")), "test: +0.");
 assert_svalue(0, compare_double(+1., ft_atof("+1.")), "test: +1.");
 assert_svalue(0, compare_double(+2., ft_atof("+2.")), "test: +2.");



//str com dois decimal
  assert_svalue(0, compare_double(00, ft_atof("00")), "test: 00");
  assert_svalue(0, compare_double(01, ft_atof("01")), "test: 01");
  assert_svalue(0, compare_double(02, ft_atof("02")), "test: 02");
  assert_svalue(0, compare_double(10, ft_atof("10")), "test: 10");
  assert_svalue(0, compare_double(11, ft_atof("11")), "test: 11");
  assert_svalue(0, compare_double(12, ft_atof("12")), "test: 12");
  assert_svalue(0, compare_double(20, ft_atof("20")), "test: 20");
  assert_svalue(0, compare_double(21, ft_atof("21")), "test: 21");
  assert_svalue(0, compare_double(22, ft_atof("22")), "test: 22");
 assert_svalue(0, compare_double(-00, ft_atof("-00")), "test: -00");
 assert_svalue(0, compare_double(-01, ft_atof("-01")), "test: -01");
 assert_svalue(0, compare_double(-02, ft_atof("-02")), "test: -02");
 assert_svalue(0, compare_double(-10, ft_atof("-10")), "test: -10");
 assert_svalue(0, compare_double(-11, ft_atof("-11")), "test: -11");
 assert_svalue(0, compare_double(-12, ft_atof("-12")), "test: -12");
 assert_svalue(0, compare_double(-20, ft_atof("-20")), "test: -20");
 assert_svalue(0, compare_double(-21, ft_atof("-21")), "test: -21");
 assert_svalue(0, compare_double(-22, ft_atof("-22")), "test: -22");
 assert_svalue(0, compare_double(+00, ft_atof("+00")), "test: +00");
 assert_svalue(0, compare_double(+01, ft_atof("+01")), "test: +01");
 assert_svalue(0, compare_double(+02, ft_atof("+02")), "test: +02");
 assert_svalue(0, compare_double(+10, ft_atof("+10")), "test: +10");
 assert_svalue(0, compare_double(+11, ft_atof("+11")), "test: +11");
 assert_svalue(0, compare_double(+12, ft_atof("+12")), "test: +12");
 assert_svalue(0, compare_double(+20, ft_atof("+20")), "test: +20");
 assert_svalue(0, compare_double(+21, ft_atof("+21")), "test: +21");
 assert_svalue(0, compare_double(+22, ft_atof("+22")), "test: +22");
  assert_svalue(0, compare_double(00., ft_atof("00.")), "test: 00.");
  assert_svalue(0, compare_double(01., ft_atof("01.")), "test: 01.");
  assert_svalue(0, compare_double(02., ft_atof("02.")), "test: 02.");
  assert_svalue(0, compare_double(10., ft_atof("10.")), "test: 10.");
  assert_svalue(0, compare_double(11., ft_atof("11.")), "test: 11.");
  assert_svalue(0, compare_double(12., ft_atof("12.")), "test: 12.");
  assert_svalue(0, compare_double(20., ft_atof("20.")), "test: 20.");
  assert_svalue(0, compare_double(21., ft_atof("21.")), "test: 21.");
  assert_svalue(0, compare_double(22., ft_atof("22.")), "test: 22.");
 assert_svalue(0, compare_double(-00., ft_atof("-00.")), "test: -00.");
 assert_svalue(0, compare_double(-01., ft_atof("-01.")), "test: -01.");
 assert_svalue(0, compare_double(-02., ft_atof("-02.")), "test: -02.");
 assert_svalue(0, compare_double(-10., ft_atof("-10.")), "test: -10.");
 assert_svalue(0, compare_double(-11., ft_atof("-11.")), "test: -11.");
 assert_svalue(0, compare_double(-12., ft_atof("-12.")), "test: -12.");
 assert_svalue(0, compare_double(-20., ft_atof("-20.")), "test: -20.");
 assert_svalue(0, compare_double(-21., ft_atof("-21.")), "test: -21.");
 assert_svalue(0, compare_double(-22., ft_atof("-22.")), "test: -22.");
 assert_svalue(0, compare_double(+00., ft_atof("+00.")), "test: +00.");
 assert_svalue(0, compare_double(+01., ft_atof("+01.")), "test: +01.");
 assert_svalue(0, compare_double(+02., ft_atof("+02.")), "test: +02.");
 assert_svalue(0, compare_double(+10., ft_atof("+10.")), "test: +10.");
 assert_svalue(0, compare_double(+11., ft_atof("+11.")), "test: +11.");
 assert_svalue(0, compare_double(+12., ft_atof("+12.")), "test: +12.");
 assert_svalue(0, compare_double(+20., ft_atof("+20.")), "test: +20.");
 assert_svalue(0, compare_double(+21., ft_atof("+21.")), "test: +21.");
 assert_svalue(0, compare_double(+22., ft_atof("+22.")), "test: +22.");

//str com um decimal e um fracional
  assert_svalue(0, compare_double(0.0, ft_atof("0.0")), "test: 0.0");
  assert_svalue(0, compare_double(0.1, ft_atof("0.1")), "test: 0.1");
  assert_svalue(0, compare_double(0.2, ft_atof("0.2")), "test: 0.2");
  assert_svalue(0, compare_double(1.0, ft_atof("1.0")), "test: 1.0");
  assert_svalue(0, compare_double(1.1, ft_atof("1.1")), "test: 1.1");
  assert_svalue(0, compare_double(1.2, ft_atof("1.2")), "test: 1.2");
  assert_svalue(0, compare_double(2.0, ft_atof("2.0")), "test: 2.0");
  assert_svalue(0, compare_double(2.1, ft_atof("2.1")), "test: 2.1");
  assert_svalue(0, compare_double(2.2, ft_atof("2.2")), "test: 2.2");
 assert_svalue(0, compare_double(0.0, ft_atof("-0.0")), "test: -0.0");
 assert_svalue(0, compare_double(0.1, ft_atof("-0.1")), "test: -0.1");
 assert_svalue(0, compare_double(0.2, ft_atof("-0.2")), "test: -0.2");
 assert_svalue(0, compare_double(-1.0, ft_atof("-1.0")), "test: -1.0");
 assert_svalue(0, compare_double(-1.1, ft_atof("-1.1")), "test: -1.1");
 assert_svalue(0, compare_double(-1.2, ft_atof("-1.2")), "test: -1.2");
 assert_svalue(0, compare_double(-2.0, ft_atof("-2.0")), "test: -2.0");
 assert_svalue(0, compare_double(-2.1, ft_atof("-2.1")), "test: -2.1");
 assert_svalue(0, compare_double(-2.2, ft_atof("-2.2")), "test: -2.2");
 assert_svalue(0, compare_double(+0.0, ft_atof("+0.0")), "test: +0.0");
 assert_svalue(0, compare_double(+0.1, ft_atof("+0.1")), "test: +0.1");
 assert_svalue(0, compare_double(+0.2, ft_atof("+0.2")), "test: +0.2");
 assert_svalue(0, compare_double(+1.0, ft_atof("+1.0")), "test: +1.0");
 assert_svalue(0, compare_double(+1.1, ft_atof("+1.1")), "test: +1.1");
 assert_svalue(0, compare_double(+1.2, ft_atof("+1.2")), "test: +1.2");
 assert_svalue(0, compare_double(+2.0, ft_atof("+2.0")), "test: +2.0");
 assert_svalue(0, compare_double(+2.1, ft_atof("+2.1")), "test: +2.1");
 assert_svalue(0, compare_double(+2.2, ft_atof("+2.2")), "test: +2.2");


//str com um decimal e dois fracional
//*
  assert_svalue(0, compare_double(0.00, ft_atof("0.00")), "test: 0.00");
  assert_svalue(0, compare_double(0.01, ft_atof("0.01")), "test: 0.01");
  assert_svalue(0, compare_double(0.02, ft_atof("0.02")), "test: 0.02");
  assert_svalue(0, compare_double(0.10, ft_atof("0.10")), "test: 0.10");
  assert_svalue(0, compare_double(0.11, ft_atof("0.11")), "test: 0.11");
  assert_svalue(0, compare_double(0.12, ft_atof("0.12")), "test: 0.12");
  assert_svalue(0, compare_double(0.20, ft_atof("0.20")), "test: 0.20");
  assert_svalue(0, compare_double(0.21, ft_atof("0.21")), "test: 0.21");
  assert_svalue(0, compare_double(0.22, ft_atof("0.22")), "test: 0.22");
  assert_svalue(0, compare_double(1.00, ft_atof("1.00")), "test: 1.00");
  assert_svalue(0, compare_double(1.01, ft_atof("1.01")), "test: 1.01");
  assert_svalue(0, compare_double(1.02, ft_atof("1.02")), "test: 1.02");
  assert_svalue(0, compare_double(1.10, ft_atof("1.10")), "test: 1.10");
  assert_svalue(0, compare_double(1.11, ft_atof("1.11")), "test: 1.11");
  assert_svalue(0, compare_double(1.12, ft_atof("1.12")), "test: 1.12");
  assert_svalue(0, compare_double(1.20, ft_atof("1.20")), "test: 1.20");
  assert_svalue(0, compare_double(1.21, ft_atof("1.21")), "test: 1.21");
  assert_svalue(0, compare_double(1.22, ft_atof("1.22")), "test: 1.22");
  assert_svalue(0, compare_double(2.00, ft_atof("2.00")), "test: 2.00");
  assert_svalue(0, compare_double(2.01, ft_atof("2.01")), "test: 2.01");
  assert_svalue(0, compare_double(2.02, ft_atof("2.02")), "test: 2.02");
  assert_svalue(0, compare_double(2.10, ft_atof("2.10")), "test: 2.10");
  assert_svalue(0, compare_double(2.11, ft_atof("2.11")), "test: 2.11");
  assert_svalue(0, compare_double(2.12, ft_atof("2.12")), "test: 2.12");
  assert_svalue(0, compare_double(2.20, ft_atof("2.20")), "test: 2.20");
  assert_svalue(0, compare_double(2.21, ft_atof("2.21")), "test: 2.21");
  assert_svalue(0, compare_double(2.22, ft_atof("2.22")), "test: 2.22");
 assert_svalue(0, compare_double(0.00, ft_atof("-0.00")), "test: -0.00");
 assert_svalue(0, compare_double(0.01, ft_atof("-0.01")), "test: -0.01");
 assert_svalue(0, compare_double(0.02, ft_atof("-0.02")), "test: -0.02");
 assert_svalue(0, compare_double(0.10, ft_atof("-0.10")), "test: -0.10");
 assert_svalue(0, compare_double(0.11, ft_atof("-0.11")), "test: -0.11");
 assert_svalue(0, compare_double(0.12, ft_atof("-0.12")), "test: -0.12");
 assert_svalue(0, compare_double(0.20, ft_atof("-0.20")), "test: -0.20");
 assert_svalue(0, compare_double(0.21, ft_atof("-0.21")), "test: -0.21");
 assert_svalue(0, compare_double(0.22, ft_atof("-0.22")), "test: -0.22");
 assert_svalue(0, compare_double(-1.00, ft_atof("-1.00")), "test: -1.00");
 assert_svalue(0, compare_double(-1.01, ft_atof("-1.01")), "test: -1.01");
 assert_svalue(0, compare_double(-1.02, ft_atof("-1.02")), "test: -1.02");
 assert_svalue(0, compare_double(-1.10, ft_atof("-1.10")), "test: -1.10");
 assert_svalue(0, compare_double(-1.11, ft_atof("-1.11")), "test: -1.11");
 assert_svalue(0, compare_double(-1.12, ft_atof("-1.12")), "test: -1.12");
 assert_svalue(0, compare_double(-1.20, ft_atof("-1.20")), "test: -1.20");
 assert_svalue(0, compare_double(-1.21, ft_atof("-1.21")), "test: -1.21");
 assert_svalue(0, compare_double(-1.22, ft_atof("-1.22")), "test: -1.22");
 assert_svalue(0, compare_double(-2.00, ft_atof("-2.00")), "test: -2.00");
 assert_svalue(0, compare_double(-2.01, ft_atof("-2.01")), "test: -2.01");
 assert_svalue(0, compare_double(-2.02, ft_atof("-2.02")), "test: -2.02");
 assert_svalue(0, compare_double(-2.10, ft_atof("-2.10")), "test: -2.10");
 assert_svalue(0, compare_double(-2.11, ft_atof("-2.11")), "test: -2.11");
 assert_svalue(0, compare_double(-2.12, ft_atof("-2.12")), "test: -2.12");
 assert_svalue(0, compare_double(-2.20, ft_atof("-2.20")), "test: -2.20");
 assert_svalue(0, compare_double(-2.21, ft_atof("-2.21")), "test: -2.21");
 assert_svalue(0, compare_double(-2.22, ft_atof("-2.22")), "test: -2.22");
 assert_svalue(0, compare_double(+0.00, ft_atof("+0.00")), "test: +0.00");
 assert_svalue(0, compare_double(+0.01, ft_atof("+0.01")), "test: +0.01");
 assert_svalue(0, compare_double(+0.02, ft_atof("+0.02")), "test: +0.02");
 assert_svalue(0, compare_double(+0.10, ft_atof("+0.10")), "test: +0.10");
 assert_svalue(0, compare_double(+0.11, ft_atof("+0.11")), "test: +0.11");
 assert_svalue(0, compare_double(+0.12, ft_atof("+0.12")), "test: +0.12");
 assert_svalue(0, compare_double(+0.20, ft_atof("+0.20")), "test: +0.20");
 assert_svalue(0, compare_double(+0.21, ft_atof("+0.21")), "test: +0.21");
 assert_svalue(0, compare_double(+0.22, ft_atof("+0.22")), "test: +0.22");
 assert_svalue(0, compare_double(+1.00, ft_atof("+1.00")), "test: +1.00");
 assert_svalue(0, compare_double(+1.01, ft_atof("+1.01")), "test: +1.01");
 assert_svalue(0, compare_double(+1.02, ft_atof("+1.02")), "test: +1.02");
 assert_svalue(0, compare_double(+1.10, ft_atof("+1.10")), "test: +1.10");
 assert_svalue(0, compare_double(+1.11, ft_atof("+1.11")), "test: +1.11");
 assert_svalue(0, compare_double(+1.12, ft_atof("+1.12")), "test: +1.12");
 assert_svalue(0, compare_double(+1.20, ft_atof("+1.20")), "test: +1.20");
 assert_svalue(0, compare_double(+1.21, ft_atof("+1.21")), "test: +1.21");
 assert_svalue(0, compare_double(+1.22, ft_atof("+1.22")), "test: +1.22");
 assert_svalue(0, compare_double(+2.00, ft_atof("+2.00")), "test: +2.00");
 assert_svalue(0, compare_double(+2.01, ft_atof("+2.01")), "test: +2.01");
 assert_svalue(0, compare_double(+2.02, ft_atof("+2.02")), "test: +2.02");
 assert_svalue(0, compare_double(+2.10, ft_atof("+2.10")), "test: +2.10");
 assert_svalue(0, compare_double(+2.11, ft_atof("+2.11")), "test: +2.11");
 assert_svalue(0, compare_double(+2.12, ft_atof("+2.12")), "test: +2.12");
 assert_svalue(0, compare_double(+2.20, ft_atof("+2.20")), "test: +2.20");
 assert_svalue(0, compare_double(+2.21, ft_atof("+2.21")), "test: +2.21");
 assert_svalue(0, compare_double(+2.22, ft_atof("+2.22")), "test: +2.22");


//str com dois decimal e dois fracional

//*
  assert_svalue(0, compare_double(00.00, ft_atof("00.00")), "test: 00.00");
  assert_svalue(0, compare_double(00.01, ft_atof("00.01")), "test: 00.01");
  assert_svalue(0, compare_double(00.10, ft_atof("00.10")), "test: 00.10");
  assert_svalue(0, compare_double(00.11, ft_atof("00.11")), "test: 00.11");
  assert_svalue(0, compare_double(00.12, ft_atof("00.12")), "test: 00.12");
  assert_svalue(0, compare_double(01.00, ft_atof("01.00")), "test: 01.00");
  assert_svalue(0, compare_double(01.01, ft_atof("01.01")), "test: 01.01");
  assert_svalue(0, compare_double(01.10, ft_atof("01.10")), "test: 01.10");
  assert_svalue(0, compare_double(01.11, ft_atof("01.11")), "test: 01.11");
  assert_svalue(0, compare_double(01.12, ft_atof("01.12")), "test: 01.12");
  assert_svalue(0, compare_double(02.00, ft_atof("02.00")), "test: 02.00");
  assert_svalue(0, compare_double(02.01, ft_atof("02.01")), "test: 02.01");
  assert_svalue(0, compare_double(02.10, ft_atof("02.10")), "test: 02.10");
  assert_svalue(0, compare_double(02.11, ft_atof("02.11")), "test: 02.11");
  assert_svalue(0, compare_double(02.12, ft_atof("02.12")), "test: 02.12");
  assert_svalue(0, compare_double(10.00, ft_atof("10.00")), "test: 10.00");
  assert_svalue(0, compare_double(10.01, ft_atof("10.01")), "test: 10.01");
  assert_svalue(0, compare_double(10.10, ft_atof("10.10")), "test: 10.10");
  assert_svalue(0, compare_double(10.11, ft_atof("10.11")), "test: 10.11");
  assert_svalue(0, compare_double(10.12, ft_atof("10.12")), "test: 10.12");
  assert_svalue(0, compare_double(11.00, ft_atof("11.00")), "test: 11.00");
  assert_svalue(0, compare_double(11.01, ft_atof("11.01")), "test: 11.01");
  assert_svalue(0, compare_double(11.10, ft_atof("11.10")), "test: 11.10");
  assert_svalue(0, compare_double(11.11, ft_atof("11.11")), "test: 11.11");
  assert_svalue(0, compare_double(11.12, ft_atof("11.12")), "test: 11.12");
  assert_svalue(0, compare_double(12.00, ft_atof("12.00")), "test: 12.00");
  assert_svalue(0, compare_double(12.01, ft_atof("12.01")), "test: 12.01");
  assert_svalue(0, compare_double(12.10, ft_atof("12.10")), "test: 12.10");
  assert_svalue(0, compare_double(12.11, ft_atof("12.11")), "test: 12.11");
  assert_svalue(0, compare_double(12.12, ft_atof("12.12")), "test: 12.12");
  assert_svalue(0, compare_double(20.00, ft_atof("20.00")), "test: 20.00");
  assert_svalue(0, compare_double(20.01, ft_atof("20.01")), "test: 20.01");
  assert_svalue(0, compare_double(20.10, ft_atof("20.10")), "test: 20.10");
  assert_svalue(0, compare_double(20.11, ft_atof("20.11")), "test: 20.11");
  assert_svalue(0, compare_double(20.12, ft_atof("20.12")), "test: 20.12");
  assert_svalue(0, compare_double(21.00, ft_atof("21.00")), "test: 21.00");
  assert_svalue(0, compare_double(21.01, ft_atof("21.01")), "test: 21.01");
  assert_svalue(0, compare_double(21.10, ft_atof("21.10")), "test: 21.10");
  assert_svalue(0, compare_double(21.11, ft_atof("21.11")), "test: 21.11");
  assert_svalue(0, compare_double(21.12, ft_atof("21.12")), "test: 21.12");
  assert_svalue(0, compare_double(22.00, ft_atof("22.00")), "test: 22.00");
  assert_svalue(0, compare_double(22.01, ft_atof("22.01")), "test: 22.01");
  assert_svalue(0, compare_double(22.10, ft_atof("22.10")), "test: 22.10");
  assert_svalue(0, compare_double(22.11, ft_atof("22.11")), "test: 22.11");
  assert_svalue(0, compare_double(22.12, ft_atof("22.12")), "test: 22.12");
 assert_svalue(0, compare_double(00.00, ft_atof("-00.00")), "test: -00.00");
 assert_svalue(0, compare_double(00.01, ft_atof("-00.01")), "test: -00.01");
 assert_svalue(0, compare_double(00.10, ft_atof("-00.10")), "test: -00.10");
 assert_svalue(0, compare_double(00.11, ft_atof("-00.11")), "test: -00.11");
 assert_svalue(0, compare_double(00.12, ft_atof("-00.12")), "test: -00.12");
 assert_svalue(0, compare_double(-01.00, ft_atof("-01.00")), "test: -01.00");
 assert_svalue(0, compare_double(-01.01, ft_atof("-01.01")), "test: -01.01");
 assert_svalue(0, compare_double(-01.10, ft_atof("-01.10")), "test: -01.10");
 assert_svalue(0, compare_double(-01.11, ft_atof("-01.11")), "test: -01.11");
 assert_svalue(0, compare_double(-01.12, ft_atof("-01.12")), "test: -01.12");
 assert_svalue(0, compare_double(-02.00, ft_atof("-02.00")), "test: -02.00");
 assert_svalue(0, compare_double(-02.01, ft_atof("-02.01")), "test: -02.01");
 assert_svalue(0, compare_double(-02.10, ft_atof("-02.10")), "test: -02.10");
 assert_svalue(0, compare_double(-02.11, ft_atof("-02.11")), "test: -02.11");
 assert_svalue(0, compare_double(-02.12, ft_atof("-02.12")), "test: -02.12");
 assert_svalue(0, compare_double(-10.00, ft_atof("-10.00")), "test: -10.00");
 assert_svalue(0, compare_double(-10.01, ft_atof("-10.01")), "test: -10.01");
 assert_svalue(0, compare_double(-10.10, ft_atof("-10.10")), "test: -10.10");
 assert_svalue(0, compare_double(-10.11, ft_atof("-10.11")), "test: -10.11");
 assert_svalue(0, compare_double(-10.12, ft_atof("-10.12")), "test: -10.12");
 assert_svalue(0, compare_double(-11.00, ft_atof("-11.00")), "test: -11.00");
 assert_svalue(0, compare_double(-11.01, ft_atof("-11.01")), "test: -11.01");
 assert_svalue(0, compare_double(-11.10, ft_atof("-11.10")), "test: -11.10");
 assert_svalue(0, compare_double(-11.11, ft_atof("-11.11")), "test: -11.11");
 assert_svalue(0, compare_double(-11.12, ft_atof("-11.12")), "test: -11.12");
 assert_svalue(0, compare_double(-12.00, ft_atof("-12.00")), "test: -12.00");
 assert_svalue(0, compare_double(-12.01, ft_atof("-12.01")), "test: -12.01");
 assert_svalue(0, compare_double(-12.10, ft_atof("-12.10")), "test: -12.10");
 assert_svalue(0, compare_double(-12.11, ft_atof("-12.11")), "test: -12.11");
 assert_svalue(0, compare_double(-12.12, ft_atof("-12.12")), "test: -12.12");
 assert_svalue(0, compare_double(-20.00, ft_atof("-20.00")), "test: -20.00");
 assert_svalue(0, compare_double(-20.01, ft_atof("-20.01")), "test: -20.01");
 assert_svalue(0, compare_double(-20.10, ft_atof("-20.10")), "test: -20.10");
 assert_svalue(0, compare_double(-20.11, ft_atof("-20.11")), "test: -20.11");
 assert_svalue(0, compare_double(-20.12, ft_atof("-20.12")), "test: -20.12");
 assert_svalue(0, compare_double(-21.00, ft_atof("-21.00")), "test: -21.00");
 assert_svalue(0, compare_double(-21.01, ft_atof("-21.01")), "test: -21.01");
 assert_svalue(0, compare_double(-21.10, ft_atof("-21.10")), "test: -21.10");
 assert_svalue(0, compare_double(-21.11, ft_atof("-21.11")), "test: -21.11");
 assert_svalue(0, compare_double(-21.12, ft_atof("-21.12")), "test: -21.12");
 assert_svalue(0, compare_double(-22.00, ft_atof("-22.00")), "test: -22.00");
 assert_svalue(0, compare_double(-22.01, ft_atof("-22.01")), "test: -22.01");
 assert_svalue(0, compare_double(-22.10, ft_atof("-22.10")), "test: -22.10");
 assert_svalue(0, compare_double(-22.11, ft_atof("-22.11")), "test: -22.11");
 assert_svalue(0, compare_double(-22.12, ft_atof("-22.12")), "test: -22.12");
 assert_svalue(0, compare_double(+00.00, ft_atof("+00.00")), "test: +00.00");
 assert_svalue(0, compare_double(+00.01, ft_atof("+00.01")), "test: +00.01");
 assert_svalue(0, compare_double(+00.10, ft_atof("+00.10")), "test: +00.10");
 assert_svalue(0, compare_double(+00.11, ft_atof("+00.11")), "test: +00.11");
 assert_svalue(0, compare_double(+00.12, ft_atof("+00.12")), "test: +00.12");
 assert_svalue(0, compare_double(+01.00, ft_atof("+01.00")), "test: +01.00");
 assert_svalue(0, compare_double(+01.01, ft_atof("+01.01")), "test: +01.01");
 assert_svalue(0, compare_double(+01.10, ft_atof("+01.10")), "test: +01.10");
 assert_svalue(0, compare_double(+01.11, ft_atof("+01.11")), "test: +01.11");
 assert_svalue(0, compare_double(+01.12, ft_atof("+01.12")), "test: +01.12");
 assert_svalue(0, compare_double(+02.00, ft_atof("+02.00")), "test: +02.00");
 assert_svalue(0, compare_double(+02.01, ft_atof("+02.01")), "test: +02.01");
 assert_svalue(0, compare_double(+02.10, ft_atof("+02.10")), "test: +02.10");
 assert_svalue(0, compare_double(+02.11, ft_atof("+02.11")), "test: +02.11");
 assert_svalue(0, compare_double(+02.12, ft_atof("+02.12")), "test: +02.12");
 assert_svalue(0, compare_double(+10.00, ft_atof("+10.00")), "test: +10.00");
 assert_svalue(0, compare_double(+10.01, ft_atof("+10.01")), "test: +10.01");
 assert_svalue(0, compare_double(+10.10, ft_atof("+10.10")), "test: +10.10");
 assert_svalue(0, compare_double(+10.11, ft_atof("+10.11")), "test: +10.11");
 assert_svalue(0, compare_double(+10.12, ft_atof("+10.12")), "test: +10.12");
 assert_svalue(0, compare_double(+11.00, ft_atof("+11.00")), "test: +11.00");
 assert_svalue(0, compare_double(+11.01, ft_atof("+11.01")), "test: +11.01");
 assert_svalue(0, compare_double(+11.10, ft_atof("+11.10")), "test: +11.10");
 assert_svalue(0, compare_double(+11.11, ft_atof("+11.11")), "test: +11.11");
 assert_svalue(0, compare_double(+11.12, ft_atof("+11.12")), "test: +11.12");
 assert_svalue(0, compare_double(+12.00, ft_atof("+12.00")), "test: +12.00");
 assert_svalue(0, compare_double(+12.01, ft_atof("+12.01")), "test: +12.01");
 assert_svalue(0, compare_double(+12.10, ft_atof("+12.10")), "test: +12.10");
 assert_svalue(0, compare_double(+12.11, ft_atof("+12.11")), "test: +12.11");
 assert_svalue(0, compare_double(+12.12, ft_atof("+12.12")), "test: +12.12");
 assert_svalue(0, compare_double(+20.00, ft_atof("+20.00")), "test: +20.00");
 assert_svalue(0, compare_double(+20.01, ft_atof("+20.01")), "test: +20.01");
 assert_svalue(0, compare_double(+20.10, ft_atof("+20.10")), "test: +20.10");
 assert_svalue(0, compare_double(+20.11, ft_atof("+20.11")), "test: +20.11");
 assert_svalue(0, compare_double(+20.12, ft_atof("+20.12")), "test: +20.12");
 assert_svalue(0, compare_double(+21.00, ft_atof("+21.00")), "test: +21.00");
 assert_svalue(0, compare_double(+21.01, ft_atof("+21.01")), "test: +21.01");
 assert_svalue(0, compare_double(+21.10, ft_atof("+21.10")), "test: +21.10");
 assert_svalue(0, compare_double(+21.11, ft_atof("+21.11")), "test: +21.11");
 assert_svalue(0, compare_double(+21.12, ft_atof("+21.12")), "test: +21.12");
 assert_svalue(0, compare_double(+22.00, ft_atof("+22.00")), "test: +22.00");
 assert_svalue(0, compare_double(+22.01, ft_atof("+22.01")), "test: +22.01");
 assert_svalue(0, compare_double(+22.10, ft_atof("+22.10")), "test: +22.10");
 assert_svalue(0, compare_double(+22.11, ft_atof("+22.11")), "test: +22.11");
 assert_svalue(0, compare_double(+22.12, ft_atof("+22.12")), "test: +22.12");

 assert_svalue(0, compare_double(-0.7071, ft_atof("-0.7071")), "test: -0.7071");

}


void	ft_atof_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "ft_atof_test") != 0)
		return ;
	create_title("ft_atof_test");
	ft_atof_test1();
}