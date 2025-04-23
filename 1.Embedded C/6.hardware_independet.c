/*
FreeRTOS Embedded C Program:
Three tasks: FrameCaptureTask, FaceRecognitionTask, LoggerTask
Hardware independent, simulation approach.
*/

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stdio.h"

// Queue handles
QueueHandle_t frameQueue;
QueueHandle_t resultQueue;

// Structures for passing data
typedef struct {
    uint32_t frameNumber;
} FrameData_t;

typedef struct {
    uint32_t frameNumber;
    uint8_t faceDetected; // 1 for detected, 0 for not detected
    TickType_t timestamp;
} ResultData_t;

// Frame Capture Task - Priority High
void FrameCaptureTask(void *pvParameters) {
    uint32_t frameNumber = 0;
    FrameData_t frameData;

    while (1) {
        frameNumber++;
        frameData.frameNumber = frameNumber;

        // Send frame number to frameQueue
        if (xQueueSend(frameQueue, &frameData, portMAX_DELAY) == pdPASS) {
            printf("FrameCaptureTask: Captured Frame %lu\n", frameNumber);
        }

        vTaskDelay(pdMS_TO_TICKS(100)); // Capture every 100ms
    }
}

// Face Recognition Task - Priority Medium
void FaceRecognitionTask(void *pvParameters) {
    FrameData_t receivedFrame;
    ResultData_t result;

    while (1) {
        if (xQueueReceive(frameQueue, &receivedFrame, portMAX_DELAY) == pdPASS) {
            // Simulate face recognition processing delay
            vTaskDelay(pdMS_TO_TICKS(100));

            result.frameNumber = receivedFrame.frameNumber;
            result.faceDetected = (receivedFrame.frameNumber % 2); // Simulate: Even frames - no face, odd frames - face detected
            result.timestamp = xTaskGetTickCount();

            // Send processed result to resultQueue
            xQueueSend(resultQueue, &result, portMAX_DELAY);

            printf("FaceRecognitionTask: Processed Frame %lu\n", receivedFrame.frameNumber);
        }
    }
}

// Logger Task - Priority Low
void LoggerTask(void *pvParameters) {
    ResultData_t logData;

    while (1) {
        if (xQueueReceive(resultQueue, &logData, portMAX_DELAY) == pdPASS) {
            printf("LoggerTask: Frame %lu | Face Detected: %s | Timestamp: %lu ticks\n",
                   logData.frameNumber,
                   logData.faceDetected ? "Yes" : "No",
                   logData.timestamp);
        }
    }
}

int main(void) {
    // Create Queues
    frameQueue = xQueueCreate(10, sizeof(FrameData_t));
    resultQueue = xQueueCreate(10, sizeof(ResultData_t));

    if (frameQueue == NULL || resultQueue == NULL) {
        printf("Failed to create queues.\n");
        while (1);
    }

    // Create Tasks
    xTaskCreate(FrameCaptureTask, "FrameCapture", configMINIMAL_STACK_SIZE + 100, NULL, 3, NULL);
    xTaskCreate(FaceRecognitionTask, "FaceRecognition", configMINIMAL_STACK_SIZE + 100, NULL, 2, NULL);
    xTaskCreate(LoggerTask, "Logger", configMINIMAL_STACK_SIZE + 100, NULL, 1, NULL);

    // Start the scheduler
    vTaskStartScheduler();

    // Should never reach here
    for (;;);
}

/*
Explanation:
- FrameCaptureTask simulates frame capture every 100 ms and sends frame numbers to frameQueue.
- FaceRecognitionTask processes frames (simulated 100 ms processing time) and sends results to resultQueue.
- LoggerTask logs the frame details from resultQueue.
- Synchronization between tasks is safely handled using FreeRTOS queues.
- Priorities ensure that FrameCaptureTask > FaceRecognitionTask > LoggerTask.
*/
