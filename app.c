#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

StaticTask_t xIdleTaskTCBBuffer;
StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
    *ppxIdleTaskStackBuffer = &xIdleStack[0];
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

StaticTask_t xTimerTaskTCBBuffer;
StackType_t xTimerStack[configTIMER_TASK_STACK_DEPTH];

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize)
{
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCBBuffer;
    *ppxTimerTaskStackBuffer = &xTimerStack[0];
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

void vApplicationTickHook(void)
{
    // Your custom code to run on each tick interrupt
}

void vApplicationIdleHook() {

}

void vApplicationDaemonTaskStartupHook() {

}

void simpleTask(void* pvParameters)
{
    while (1) {
        printf("hahhhhhhhhhh\r\n");
                
    }
}

int main() {
//    printf("..........\r\n");
    xTaskCreate(
        simpleTask,        /* Task function */
        "SimpleTask",      /* Task name */
        configMINIMAL_STACK_SIZE, /* Stack size */
        NULL,              /* Task input parameter */
        1,                 /* Task priority */
        NULL               /* Task handle */
    );

    vTaskStartScheduler();

    while (1);
    return 0;
}

