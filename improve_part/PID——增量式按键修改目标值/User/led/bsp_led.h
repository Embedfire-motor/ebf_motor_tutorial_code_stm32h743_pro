#ifndef __LED_H
#define	__LED_H

#include "stm32H7xx.h"

//引脚定义
/*******************************************************/

#define LED1_PIN                  GPIO_PIN_0
#define LED1_GPIO_PORT            GPIOB
#define LED1_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()

#define LED2_PIN                  GPIO_PIN_1
#define LED2_GPIO_PORT            GPIOB
#define LED2_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()

#define LED3_PIN                  GPIO_PIN_3
#define LED3_GPIO_PORT            GPIOA
#define LED3_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()

/************************************************************/


/** 控制LED灯亮灭的宏，
	* LED低电平亮，设置ON=0，OFF=1
	* 若LED高电平亮，把宏设置成ON=1 ，OFF=0 即可
	*/
//#define ON  GPIO_PIN_RESET
//#define OFF GPIO_PIN_SET

/* 带参宏，可以像内联函数一样使用 */
#define LED1(a)	HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,a)

#define LED2(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,a)

#define LED3(a)	HAL_GPIO_WritePin(LED3_GPIO_PORT,LED3_PIN,a)


/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)			{p->BSRR=i;}			  //设置为高电平		
#define digitalLo(p,i)			{p->BSRR=(uint32_t)i << 16;}				//输出低电平
#define digitalToggle(p,i)		{p->ODR ^=i;}			//输出反转状态


/* 定义控制IO的宏 */
#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED1_OFF		  digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED1_ON			  digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define LED2_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED2_OFF		  digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define LED2_ON			  digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define LED3_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define LED3_OFF		  digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define LED3_ON			  digitalLo(LED3_GPIO_PORT,LED3_PIN)


/* 基本混色，后面高级用法使用PWM可混出全彩颜色,且效果更好 */
					
//(全部打开)
#define LED_ALLON	\
					LED1_ON;\
					LED2_ON\
					LED3_ON
					
//(全部关闭)
#define LED_ALLOFF	\
					LED1_OFF;\
					LED2_OFF\
					LED3_OFF

#define LED_ALLTOGGLE \
					LED1_TOGGLE;\
					LED2_TOGGLE\
					LED3_TOGGLE

void LED_GPIO_Config(void);

#endif /* __LED_H */
