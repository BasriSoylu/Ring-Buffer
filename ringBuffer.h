#include <stdio.h>
#include <stdint.h>

#define RINGBUFFER_LENG 2048
#define RINGBUFFER_TEMP_LENG 512
#define RINGBUFFER_TYPE char

typedef struct{

uint32_t head;
uint32_t tail;

RINGBUFFER_TYPE buffer[RINGBUFFER_LENG];
RINGBUFFER_TYPE temp_Buffer[RINGBUFFER_TEMP_LENG];

uint32_t temp_Buffer_index;

}ringBuffer_t;

void ringBuffer_push(ringBuffer_t *buf, RINGBUFFER_TYPE data);
uint8_t ringBuffer_pull(ringBuffer_t *buf, RINGBUFFER_TYPE stopChar);
uint8_t ringBuffer_not_empty(ringBuffer_t *buf);
uint8_t ringBuffer_clean_tempBuffer(ringBuffer_t *buf);
