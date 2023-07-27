#include "test_spi.h"
#include "scheduler.h"
#include "spi_drv.h"
#include "gpio_drv.h"


#define LED5_PORT       (GPIO_PORT_B)
#define LED5_PIN        (GPIO_PIN_4)

#define LED6_PORT       (GPIO_PORT_B)
#define LED6_PIN        (GPIO_PIN_5)

#define LED7_PORT       (GPIO_PORT_E)
#define LED7_PIN        (GPIO_PIN_8)

#define LED8R_PORT      (GPIO_PORT_B)
#define LED8R_PIN       (GPIO_PIN_8)

#define LED8G_PORT      (GPIO_PORT_B)
#define LED8G_PIN       (GPIO_PIN_9)

#define LED8B_PORT      (GPIO_PORT_B)
#define LED8B_PIN       (GPIO_PIN_10)

void TEST_Init(void) 
{
    // GPIO_Init();
    SPI_Init();
}


static U32 nIdleCounter = 0;
void TEST_1ms(void)
{
    nIdleCounter = SCHDL_GetAndResetIdleCounter(); 
}



void TEST_10ms(void) 
{
    U8 aData[8U];
    SPI_Write(1U, aData, 1U);
}


void TEST_100ms(void) 
{

}



void TEST_1sec(void) 
{
    static BOOLEAN bState = FALSE;

    if (FALSE == bState){
        GPIO_SetPinState(LED5_PORT,
                         LED5_PIN,
                         GPIO_PIN_LOW);

        GPIO_SetPinState(LED6_PORT,
                         LED6_PIN,
                         GPIO_PIN_LOW);

        GPIO_SetPinState(LED7_PORT,
                         LED7_PIN,
                         GPIO_PIN_LOW);

        GPIO_SetPinState(LED8R_PORT,
                         LED8R_PIN,
                         GPIO_PIN_HIGH);

        GPIO_SetPinState(LED8G_PORT,
                         LED8G_PIN,
                         GPIO_PIN_HIGH);

        GPIO_SetPinState(LED8B_PORT,
                         LED8B_PIN,
                         GPIO_PIN_HIGH);
        
        bState = TRUE;
    }
    else
    {
        GPIO_SetPinState(LED5_PORT,
                         LED5_PIN,
                         GPIO_PIN_HIGH);

        GPIO_SetPinState(LED6_PORT,
                         LED6_PIN,
                         GPIO_PIN_HIGH);

        GPIO_SetPinState(LED7_PORT,
                         LED7_PIN,
                         GPIO_PIN_HIGH);

        GPIO_SetPinState(LED8R_PORT,
                         LED8R_PIN,
                         GPIO_PIN_LOW);

        GPIO_SetPinState(LED8G_PORT,
                         LED8G_PIN,
                         GPIO_PIN_LOW);

        GPIO_SetPinState(LED8B_PORT,
                         LED8B_PIN,
                         GPIO_PIN_LOW);
                        
        bState = FALSE;
    }
}