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

U32 aRxDataMaster[] = {0U, 0U, 0U, 0U};
void SPI0_CALLBACK(void)
{
    U16 nRxCountMaster;
    SPI_GetRXItemsCount(0U, &nRxCountMaster);
    SPI_Read(0U, aRxDataMaster, nRxCountMaster);
}

U32 aRxDataSlave[] = {0U, 0U, 0U, 0U};
void SPI1_CALLBACK(void)
{
    U16 nRxCountSlave;
    SPI_GetRXItemsCount(1U, &nRxCountSlave);
    SPI_Read(1U, aRxDataSlave, nRxCountSlave);
}

void TEST_Init(void) 
{
    GPIO_Init();
    SPI_Init();
    GPIO_SetPinState(LED5_PORT,
                     LED5_PIN,
                     GPIO_PIN_HIGH);   

    SPI_SetCallbackFunction(0U, SPI0_CALLBACK);
    SPI_SetCallbackFunction(1U, SPI1_CALLBACK);
    SPI_SetBaudrate(0U, 50000UL);
    SPI_SetBaudrate(1U, 50000UL);
}

static U32 nIdleCounter = 0;
void TEST_1ms(void)
{
    nIdleCounter = SCHDL_GetAndResetIdleCounter(); 
    // SPI_Read(0U, aRxData, SIZE_OF_ARRAY(aRxData));
}

BOOLEAN bActiveClockPolarity = FALSE;
BOOLEAN bClockPhase = FALSE;
BOOLEAN bBitOrder = FALSE;
U8      nDataFrameSize = 32U;
U8      nCSNum = 0U;

void TEST_10ms(void) 
{

}

void TEST_100ms(void) 
{
    static U8 nCntSend = 0;

    U32 aDataMaster[] = {0x10U    + nCntSend, 
                         0x100U   + nCntSend * 0x10U,
                         0x1000U  + nCntSend * 0x100U,
                         0x10000U + nCntSend * 0x1000U};

    U32 aDataSlave[]  = {0x30U    + nCntSend, 
                         0x300U   + nCntSend * 0x10U,
                         0x3000U  + nCntSend * 0x100U,
                         0x30000U + nCntSend * 0x1000U};

    nCntSend++;
    if (0x10U == nCntSend)
    {
        nCntSend = 0;
    }
    SPI_Purge(1U, TRUE, TRUE);
    SPI_Write(1U, aDataSlave, SIZE_OF_ARRAY(aDataSlave));
    SPI_Write(0U, aDataMaster, SIZE_OF_ARRAY(aDataMaster));
}

void TEST_1sec(void) 
{
    static U32 nBaudRate = 30000UL; 

    SPI_SetBaudrate(0U, nBaudRate);
    SPI_SetBaudrate(1U, nBaudRate*2);
}