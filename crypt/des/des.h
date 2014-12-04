#ifndef __DES_H__
#define __DES_H__

typedef unsigned char u8;
void genKey(u8 key[]);
void encMsg(u8 m[], u8 c[], u8 d);

#endif
