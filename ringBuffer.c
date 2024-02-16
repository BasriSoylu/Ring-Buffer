#include "ringBuffer.h"


void ringBuffer_push(ringBuffer_t *buf, RINGBUFFER_TYPE data)
{
    buf->buffer[buf->head] = data;
    buf->head++;

    if(buf->head >= RINGBUFFER_LENG)
    {
        buf->head = 0;
    }
}

uint8_t ringBuffer_pull(ringBuffer_t *buf, RINGBUFFER_TYPE stopChar)
{
    if(ringBuffer_not_empty(buf))
    {
        while (buf->tail != buf->head)
        {
            buf->temp_Buffer[buf->temp_Buffer_index] = buf->buffer[buf->tail];
            buf->temp_Buffer_index++;

            if(buf->buffer[buf->tail] == stopChar)
            {
                buf->tail++;
                break;
            }

            buf->tail++;

            if(buf->tail >= RINGBUFFER_LENG)
            {
                buf->tail = 0;
            }
        }
        return 1;
    }

    else
    {
        return 0;
    }
}

uint8_t ringBuffer_not_empty(ringBuffer_t *buf)
{
    if(buf->head != buf->tail)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

uint8_t ringBuffer_clean_tempBuffer(ringBuffer_t *buf)
{
    for(int i=0; i < buf->temp_Buffer_index ; i++)
    {
        buf->temp_Buffer[i] = 0;
    }
    buf->temp_Buffer_index = 0;
}