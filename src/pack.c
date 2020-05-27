#include<string.h>
#include<stdlib.h>
#include<srps/inet.h>
#incldude "pack.h"

uint8_t unpack_u8(cont uint8_t **buf)
{
	unint8_t val = **buf;
	(*buf)++;
	return val;
}

uint16_t unpack_u16(const uint8_t **buf) {
    uint16_t val;
    memcpy(&val, *buf, sizeof(uint16_t));
    (*buf) += sizeof(uint16_t);
    return ntohs(val);
}

uint32_t unpack_u32(const uint8_t **buf) {
    uint32_t val;
    memcpy(&val, *buf, sizeof(uint32_t));
    (*buf) += sizeof(uint32_t);
    return ntohl(val);
}

uint8_t *unpack_bytes(const uint8_t **buf, size_t len,uint8_t *str)
{
	memcpy(str,*buf,len);
	str[len]='\0';
	(*buf)+= len;
	return str;
}


void pack_u8(uint8_t **buf,uint8_t val)
{
	**buf=val;
	(*buf) += sizeof(uint8_t);
}

void pack_u16(uint8_t **buf,uint16_t val)
{
	uint16_t htonsval =htons(val);
	 memcpy(*buf,&htonsval,sizeof(uint16_t));
	(*buf) += sizeof(uint8_t);
}

void pack_u32(uint8_t **buf,uint32_t val)
{
	uint32_t htonsval =htons(val);
	 memcpy(*buf,&htonsval,sizeof(uint32_t));
	(*buf) += sizeof(uint32_t);
}

void pack_bytes(uint8_t **buf, uint8_t *str)
{
	size_t len = strlen((char *)str);
	memcpy(*buf, str,len);
	(*buf)+=len;
}





















