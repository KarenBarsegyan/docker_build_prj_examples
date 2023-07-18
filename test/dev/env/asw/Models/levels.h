/******************************************************************************
 * MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
 * File : levels.h                                                            
 ******************************************************************************/

#ifndef _LEVELS_H_
#define _LEVELS_H_

// Reset Initialization Level
#define LvReset                         1
void _LvReset(void);

// TimeMachine 1 ms Level CSW
#define LvCtrlSW1ms                     2
void _LvCtrlSW1ms(void);

// TimeMachine 10 ms Level CSW
#define LvCtrlSW10ms                    3
void _LvCtrlSW10ms(void);

// TimeMachine 100 ms Level CSW
#define LvCtrlSW100ms                   4
void _LvCtrlSW100ms(void);

// TimeMachine 1 sec Level CSW
#define LvCtrlSW1sec                    5
void _LvCtrlSW1sec(void);

// Start Level (Data loaded)
#define LvStart                         6
void _LvStart(void);

// Stop Level (prepare Data)
#define LvStop                          7
void _LvStop(void);

#endif                                  //_LEVELS_H_
