#include "test_spi.h"
#include "scheduler.h"
#include "spi_drv.h"
#include "gpio_drv.h"
#include "gpio_drv_types.h"


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
    GPIO_Init();
    SPI_Init();
    GPIO_SetPinState(LED5_PORT,
                     LED5_PIN,
                     GPIO_PIN_HIGH);   
}

U32 aRxData[8U];
static U32 nIdleCounter = 0;
void TEST_1ms(void)
{
    nIdleCounter = SCHDL_GetAndResetIdleCounter(); 
    SPI_Read(0U, aRxData, SIZE_OF_ARRAY(aRxData));

    U32 aData[8U];
    SPI_Read(1U, aData, SIZE_OF_ARRAY(aData));
}

void TEST_10ms(void) 
{
    SPI_Write(0U, aRxData, SIZE_OF_ARRAY(aRxData));   
}

void TEST_100ms(void) 
{
    U32 aData[8U] = {0x3U, 0x23U, 0x330U, 0x4300U, 0x53000U, 0x630000U, 0x7300000U, 0x83000000};
    SPI_Write(1U, aData, SIZE_OF_ARRAY(aData));
}

void TEST_1sec(void) 
{
    static U32 nBaudRate = 30000UL; 

    SPI_SetBaudrate(0U, nBaudRate);
    SPI_SetBaudrate(1U, nBaudRate*2);

    // nBaudRate += 10000;

    // if (nBaudRate*2 >= 5000000UL) 
    // {
    //     nBaudRate = 30000UL;
    // }

    // static BOOLEAN bSpiInit = TRUE;
    // if (TRUE == bSpiInit)
    // {
    //     bSpiInit = FALSE;
    //     SPI_DeInit();
    //     GPIO_SetPinState(LED5_PORT,
    //                      LED5_PIN,
    //                      GPIO_PIN_LOW);
    // }
    // else
    // {
    //     SPI_Init();
    //     bSpiInit = TRUE;
    //     GPIO_SetPinState(LED5_PORT,
    //                      LED5_PIN,
    //                      GPIO_PIN_HIGH);
    // }
}