@addtogroup SPI_DRV

# 1. Аббревиатуры и сокращения

В документе используются следующие аббревиатуры и сокращения:

ПМ – Программный Модуль  
API – Application Program Interface   
CS – Сhip Select   
FIFO – First In First Out   
MCU – MicroController Unit   
MISO – Master Input Slave Output    
MOSI – Master Output Slave Input    
SPI – Serial Peripheral Interface   
 

# 2. Общие положения

Драйвер SPI (далее “программный модуль”) предоставляет набор API для работы c перефирией SPI, входящей в состав микроконтроллеров семейства YTM32B1M.

В состав API типичного программного модуля входят:
- типы данных
- константы
- функции

Типы данных используются для определений параметров и возвращаемых значений API-функций.

Константы используются в двух случаях: для определения значений, которые могут принимать параметры функций и для определения значений, которые могут возвращать функции.

Функции являются непосредственным интерфейсом программного модуля (API) и представляют функционал работы всего программного модуля в целом.

Программный модуль можно статически конфигурировать с помощью констант компиляции (в случае их наличия в текущей реализации программного модуля). Программный модуль также можно динамически конфигурировать с помощью вызовов конфигурационных функций в процессе его работы.

## Основные функции программного модуля

1. Иницилизация и деинициализация SPI-периферии микроконтроллера;
2. Отправка и прием сообщений в режимах master и slave
3. Настройка бодрейта
4. Настройка параметров приема-передачи
5. Формирование событий по отправке/приему новых данных;


# 3. Принцип работы

С помощью ПМ можно отправлять и принимать SPI сообщение в режиме Master и Slave

## Основные характеристики
- 6 SPI модулей
- По 4 CS-пина для SPI 0\1\2 и по 2 CS-пина для SPI 3\4\5
- Настройка режимов выхода (PushPull или OpenDrain) для каждого пина
- Включение и отключение подтяжек к питанию для каждого пина

Каждый канал SPI является ресурсом, который можно занимать только монопольно, т.е. в определенный момент времени прием/передачу может осуществлять только один пользователь. Обмен представляет собой транзакцию со строго определенной последовательностью действий:

    вызов функции SPI_SetBaudrate() (опционально);
    вызов функции SPI_SetTransferFormat() (опционально);
    вызов функции SPI_Write();
    событие приема данных, в контексте которого вызов функции SPI_Read();

Опциональные функции должны быть вызваны при инициализации передачи/приема хотя бы один раз. При наличии нескольких пользователей вызов этих функций обязателен. Причем работа разных пользователей с каналом SPI должна быть разделена по времени. Для этого необходима диспетчеризация. Использование разными каналами SPI не нуждается в обязательном разделении по времени.

# 4. Статическое конфигурирование

| Название параметра              | Диапазон значений                                     | Описание                                                                                                                                                        |
| ------------------------------- | ----------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| SPI_DEVELOPMENT_ERROR_DETECTION | ON / OFF                                              | Включает / выключает определение и трассировку ошибок на этапе разработки. <br/> Используется для целей отладки. Должна быть выключена в релизной конфигурации. |
| SPI_CHANNEL_RX_FIFO_SIZE        | 1...255                                               | Определяет размер приемного FIFO драйвера.                                                                                                                      |
| SPI_CHANNEL_TX_FIFO_SIZE        | 1...255                                               | Определяет размер передающего FIFO драйвера.                                                                                                                    |
| SPI_CHANNEL_X_IN_USE            | ON / OFF                                              | Разрешает/запрещает использование аппаратного модуля SPI.                                                                                                       |
| SPI_CHANNEL_X_BAUDRATE          | 1000..5000000                                         | Определяет скорость обмена по шине SPI в битах в секунду в режиме мастер.                                                                                       |
| SPI_CHANNEL_X_MOSI_PORT         | SPI_PORT_A..SPI_PORT_E                                | Номер последовательного порта для отправки данных в режиме ведущего и приема данных в режиме ведомого.                                                          |
| SPI_CHANNEL_X_MOSI_PIN          | 0..15                                                 | Номер пина для отправки данных в режиме ведущего и приема данных в режиме ведомого.                                                                             |
| SPI_CHANNEL_X_MOSI_OUTPUT_MODE  | SPI_OUTPUT_MODE_PUSH_PULL, SPI_OUTPUT_MODE_OPEN_DRAIN | Настройка режима работы линии MOSI                                                                                                                              |
| SPI_CHANNEL_X_MOSI_PULLUP_MODE  | SPI_PULLUP_MODE_DISABLE, SPI_PULLUP_MODE_ENABLE       | Включение/выключение подтяжки линии MOSI                                                                                                                        |
| SPI_CHANNEL_X_MISO_PORT         | SPI_PORT_A..SPI_PORT_E                                | Номер последовательного порта для приема данных в режиме ведущего и отправки данных в режиме ведомого.                                                          |
| SPI_CHANNEL_X_MISO_PIN          | 0..15                                                 | Номер пина для приема данных в режиме ведущего и отправки данных в режиме ведомого.                                                                             |
| SPI_CHANNEL_X_MISO_OUTPUT_MODE  | SPI_OUTPUT_MODE_PUSH_PULL, SPI_OUTPUT_MODE_OPEN_DRAIN | Настройка режима работы линии MISO                                                                                                                              |
| SPI_CHANNEL_X_MISO_PULLUP_MODE  | SPI_PULLUP_MODE_DISABLE, SPI_PULLUP_MODE_ENABLE       | Включение/выключение подтяжки линии MISO                                                                                                                        |
| SPI_CHANNEL_X_SCLK_PORT         | SPI_PORT_A..SPI_PORT_E                                | Номер последовательного порта для генерации сигналов тактирования в режиме ведущего и приема сигналов тактирования в режиме ведомого.                           |
| SPI_CHANNEL_X_SCLK_PIN          | 0..15                                                 | Номер пина для генерации сигналов тактирования в режиме ведущего и приема сигналов тактирования в режиме ведомого.                                              |
| SPI_CHANNEL_X_SCLK_OUTPUT_MODE  | SPI_OUTPUT_MODE_PUSH_PULL, SPI_OUTPUT_MODE_OPEN_DRAIN | Настройка режима работы линии SCLK                                                                                                                              |
| SPI_CHANNEL_X_SCLK_PULLUP_MODE  | SPI_PULLUP_MODE_DISABLE, SPI_PULLUP_MODE_ENABLE       | Включение/выключение подтяжки линии SCLK                                                                                                                        |
| SPI_CHANNEL_X_CS_Y_IN_USE       | ON, OFF                                               | Включение/выключение CS порта Y канала X                                                                                                                        |
| SPI_CHANNEL_X_CS_Y_PORT         | SPI_PORT_A..SPI_PORT_E                                | Номер последовательного порта для выбора устройства для общения в режиме ведущего и приема сигналов о начале передачи в режиме ведомого.                        |
| SPI_CHANNEL_X_CS_Y_PIN          | 0..15                                                 | Номер пина для выбора устройства для общения в режиме ведущего и приема сигналов о начале передачи в режиме ведомого.                                           |
| SPI_CHANNEL_X_CS_Y_OUTPUT_MODE  | SPI_OUTPUT_MODE_PUSH_PULL, SPI_OUTPUT_MODE_OPEN_DRAIN | Настройка режима работы линии CS                                                                                                                                |
| SPI_CHANNEL_X_CS_Y_PULLUP_MODE  | SPI_PULLUP_MODE_DISABLE, SPI_PULLUP_MODE_ENABLE       | Включение/выключение подтяжки линии CS                                                                                                                          |

# 5. Встроенная диагностика

В данной реализации программного модуля встроенная диагностика отсутствует.

# 6. Порядок работы
1. Перед началом работы с программным модулем его необходимо статически сконфигурировать.
   - Номер используемого канала  - 0
   - Режим работы канала  - Мастер
   - Скорость обмена данными  - 500000
   - Порт линии MOSI - A
   - Номер пина линии MOSI - 30
   - Тип выхода линии MOSI - push-pull
   - Подтяжка линии MOSI - выключена
   - Порт линии MISO - D
   - Номер пина линии MISO - 116
   - Тип выхода линии MISO - push-pull
   - Подтяжка линии MISO - выключена
   - Порт линии SCLK - D
   - Номер пина линии SCLK - 15
   - Тип выхода линии SCLK - push-pull
   - Подтяжка линии SCLK - выключена
   - Линия CS0 - включена
   - Порт линии CS0 - А
   - Пин линии CS0 - 26
   - Тип выхода линии CS - push-pull
   - Подтяжка линии CS - выключена
   - Линия CS1 - выключена
   - Линия CS2 - выключена
   - Линия CS3 - выключена
    
    Конфигурация для данных условий выглядит следующим образом:

```c
    #define SPI_CHANNEL_0_IN_USE                    (ON)
    #define SPI_CHANNEL_0_MODE                      (SPI_MODE_MASTER)
    #define SPI_CHANNEL_0_BAUDRATE                  (50000UL)

    #define SPI_CHANNEL_0_MOSI_PORT                 (SPI_PORT_A)
    #define SPI_CHANNEL_0_MOSI_PIN                  (30U)
    #define SPI_CHANNEL_0_MOSI_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
    #define SPI_CHANNEL_0_MOSI_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

    #define SPI_CHANNEL_0_MISO_PORT                 (SPI_PORT_D)
    #define SPI_CHANNEL_0_MISO_PIN                  (16U)
    #define SPI_CHANNEL_0_MISO_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
    #define SPI_CHANNEL_0_MISO_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

    #define SPI_CHANNEL_0_SCLK_PORT                 (SPI_PORT_D)
    #define SPI_CHANNEL_0_SCLK_PIN                  (15U)
    #define SPI_CHANNEL_0_SCLK_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
    #define SPI_CHANNEL_0_SCLK_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

    #define SPI_CHANNEL_0_CS_0_IN_USE               (ON)
    #define SPI_CHANNEL_0_CS_0_PORT                 (SPI_PORT_A)
    #define SPI_CHANNEL_0_CS_0_PIN                  (26U)
    #define SPI_CHANNEL_0_CS_0_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
    #define SPI_CHANNEL_0_CS_0_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

    #define SPI_CHANNEL_0_CS_1_IN_USE               (OFF)
    #define SPI_CHANNEL_0_CS_1_PORT                 (SPI_PORT_A)
    #define SPI_CHANNEL_0_CS_1_PIN                  (0U)
    #define SPI_CHANNEL_0_CS_1_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
    #define SPI_CHANNEL_0_CS_1_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

    #define SPI_CHANNEL_0_CS_2_IN_USE               (OFF)
    #define SPI_CHANNEL_0_CS_2_PORT                 (SPI_PORT_A)
    #define SPI_CHANNEL_0_CS_2_PIN                  (0U)
    #define SPI_CHANNEL_0_CS_2_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
    #define SPI_CHANNEL_0_CS_2_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

    #define SPI_CHANNEL_0_CS_3_IN_USE               (OFF)
    #define SPI_CHANNEL_0_CS_3_PORT                 (SPI_PORT_A)
    #define SPI_CHANNEL_0_CS_3_PIN                  (0U)
    #define SPI_CHANNEL_0_CS_3_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
    #define SPI_CHANNEL_0_CS_3_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)
```

Также необходимо включить прерывание SPI_0 (вектор IRQ_26) и добавить обработчик SPI_CHANNEL_0_Interrupt() для соответствующего вектора в irq_drv_cfg.h

```c
    // irq_drv.cfg.h
    
    #define IRQ_26_ENABLE                                                  (ON)

    #define IRQ_26_ALIAS_FUN1                                              SPI_LowLevel_0_Interrupt
    #define IRQ_26_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER

    #define IRQ_26_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)

    #define IRQ_26_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)
```

1. Для инициализации  необходимо вызвать функцию `SPI_Init()`:
```c
    void main(void)
    {
        // Set system clock
        MCU_Init();
        // Set interrupts configuration
        IRQ_Init();

        // SPI initialization
        STD_RESULT result = SPI_Init();
    }
```

2. Для деинициализации, необходимо вызвать функцию `SPI_DeInit()` :
```c
    // SPI deinitialization
    SPI_DeInit();
```

3. Для чтения данных из приемного буфера, необходимо вызвать функцию `SPI_Read()` :
```c
    U16 APP_nDataBuffer[APP_BUFFER_SIZE];
    U8 APP_nLength = APP_BUFFER_SIZE;

    // Read SPI data
    STD_RESULT nResult = SPI_Read(SPI_CHANNEL_0, APP_nDataBuffer, APP_nLength);
    switch (nResult)
    {
        case RESULT_NOT_OK:
            // Error
            DoSomeThg();
            break;

        case RESULT_OK:
            DoSomeThg();
            break;

        default:
            DoNothing();
            break;
    }
```

4. Для отправки данных, необходимо вызывать функцию `SPI_Write()`:
```c
    U16 APP_nDataBuffer[APP_BUFFER_SIZE];
    U8 APP_nLength = APP_BUFFER_SIZE;

    // Write SPI data
    STD_RESULT nResult = SPI_Write(SPI_CHANNEL_0, APP_nDataBuffer, APP_nLength);
    switch (nResult)
    {
        case RESULT_NOT_OK:
            // Error
            DoSomeThg();
            break;

        case RESULT_OK:
            DoSomeThg();
            break;

        default:
            DoNothing();
            break;
    }
```

5. Для очистки приемного или передающего буферов, необходимо вызвать функцию `SPI_Purge()`:
```c
    U8 APP_nDataBuffer[APP_BUFFER_SIZE];
    U8 APP_nLength = APP_BUFFER_SIZE;

    // Purge SPI buffers (RX and TX)
    STD_RESULT nResult = SPI_Purge(SPI_MODULE_1, APP_TRUE, APP_TRUE);
    switch (nResult)
    {
        case RESULT_NOT_OK:
            // Error
            DoSomeThg();
            break;

        case RESULT_OK:
            DoSomeThg();
            break;

        default:
            DoNothing();
            break;
    }
```

6. Для получения количества принятых байт, необходимо вызвать функцию `SPI_GetRXItemsCount()`:

```c
    U16 APP_nRxItemsQty;

    // Read number of received bytes from SPI
    STD_RESULT nResult = SPI_GetRXItemsCount(SPI_CHANNEL_0, &APP_nRxItemsQty);
    switch (nResult)
    {
        case RESULT_NOT_OK:
            // Error
            DoSomeThg();
            break;

        case RESULT_OK:
            DoSomeThg();
            break;

        default:
            DoNothing();
            break;
    }    

```

7. Для настройки дополнительных параметров приема и передачи, необходимо вызвать функцию `SPI_SetTransferFormat()`:

```c
    // Set transfer format
    #define SPI_FRAME_LENGTH (16U)
    #define SPI_CS           (0U)

    STD_RESULT nResult = SPI_SetTransferFormat(SPI_CHANNEL_0, 
                                               SPI_CLOCK_POL_LOW,
                                               SPI_PHASE_RISING,
                                               SPI_BIT_ORDER_LSB_FIRST,
                                               SPI_FRAME_LENGTH,
                                               SPI_CS);

    switch (nResult)
    {
        case RESULT_NOT_OK:
            // Error
            DoSomeThg();
            break;

        case RESULT_OK:
            DoSomeThg();
            break;

        default:
            DoNothing();
            break;
    }
```

8. Для изменения скорости передачи, необходимо вызвать функцию `SPI_SetBaudrate()`:

```c
    // Set baud rate
    #define SPI_BAUDRATE (5000000U)

    STD_RESULT nResult = SPI_SetBaudrate(SPI_CHANNEL_0, SPI_BAUDRATE);

    switch (nResult)
    {
        case RESULT_NOT_OK:
            // Error
            DoSomeThg();
            break;

        case RESULT_OK:
            DoSomeThg();
            break;

        default:
            DoNothing();
            break;
    }
```

9. Для задания функции обратного вызова по событию приема пакета, необходимо вызвать функцию `SPI_SetCallbackFunction()`:

```c
    void APP_CallbackSPI(void);

    // Set callback function
    STD_RESULT nResult = SPI_SetCallbackFunction(SPI_CHANNEL_0, APP_CallbackSPI);

    switch (nResult)
    {
        case RESULT_NOT_OK:
            // Error
            DoSomeThg();
            break;

        case RESULT_OK:
            DoSomeThg();
            break;

        default:
            DoNothing();
            break;
    }
```

<br/><br/>

# 7. Ограничения
Не обнаружено

<br/><br/><br/>

# 8. Литература
1. YTM32B1ME0x Reference manual Rev 1.0
2. YTM32B1ME0x Datasheet Rev1.3
<br/><br/><br/>

# 9. Таблица изменений
|  №  | Версия |    Дата    |     Автор     | Описание изменения      |
| :-: | :----: | :--------: | :-----------: | ----------------------- |
|  1  | 1.0.0  | 14.08.2023 | Барсегян К.Р. | Первая версия документа |