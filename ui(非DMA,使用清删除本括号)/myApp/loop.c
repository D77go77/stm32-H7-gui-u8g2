/**
  ******************************************************************************
  * @file           : loop.c
  * @author         : 19816
  * @brief          : None
  * @attention      : None
  * @date           : 2025/1/20
  ******************************************************************************
  */
#include "bsp_system.h"
void loop(void)
{
    myGpio_init();
    button_init_all();
    scheduler_init();
    gui_init();
    while(1)
    {
//        gui_task();
        scheduler_run();
    }
}