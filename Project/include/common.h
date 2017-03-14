/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  项目的公共函数和参数定义
 *
 *        Version:
 *        Created:
 *       Revision:
 *       Compiler:
 *
 *         Author:  zhangyuxiang
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef __COMMON__H__
#define __COMMON__H__

#include "stm32f10x.h"
#include <stdint.h>

//for NULL and bool
#include "usb_type.h"
#define true TRUE
#define false FALSE

extern void USART_printf(USART_TypeDef* USARTx, char *Data, ...);

#define Debug_USART USART1
#define Debug_BaudRate 115200
#define DBG_Init USART_Config(Debug_USART, Debug_BaudRate);
#define DBG_MSG(format, ...) USART_printf(Debug_USART, "[Debug]%s: " format "\r\n", __func__, ##__VA_ARGS__)
#define ERR_MSG(format, ...) USART_printf(Debug_USART, "[Error]%s: " format "\r\n", __func__, ##__VA_ARGS__)
#define REPORT(info_type, format, ...) USART_printf(BT_USART, "!I#%s#" format "\r\n", info_type, ##__VA_ARGS__)

void RCC_GPIOClockCmd(GPIO_TypeDef* GPIOx, FunctionalState state);
void RCC_USARTClockCmd(USART_TypeDef* USARTx, FunctionalState state);
void Timer_16bit_Calc(int freq, uint16_t *period, uint16_t *prescaler);
float Distance3D(float dx, float dy, float dz);

#endif /* __COMMON__H__ */
