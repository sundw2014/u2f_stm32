/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "stm32f10x.h"
#include "usb_lib.h"
#include "usb_pwr.h"
#include "usart.h"
#include "time.h"
#include "eeprom.h"

#include "sha256.h"
#include "uECC.h"

/*******************************************************************************
* Function Name  : main.
* Description    : main routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int main(void)
{
    time_init();
    DBG_Init
    USBCommon_Init();
    USB_Init();
    u2f_init();

    /* Unlock the Flash Program Erase controller */
    FLASH_Unlock();

    /* EEPROM Init */
    EE_Init();

    while (1)
    {
        // DBG_MSG("alive");
        u2f_loop();
    }
}

#ifdef  USE_FULL_ASSERT
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while(1)
  {
  }
}
#endif
