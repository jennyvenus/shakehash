// shake.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "xof\\extern_shake.h"

int main(void)
{
	unsigned char tmp[ 0x100 ];

	ShakeContext ctx;
	shakeInit( &ctx, 128 );
	shakeUpdate( &ctx, "", 0 );
	shakeFinal( &ctx );
	shakeSqueeze( &ctx, tmp, 32 );

	shakeInit( &ctx, 256 );
	shakeUpdate( &ctx, "", 0 );
	shakeFinal( &ctx );
	shakeSqueeze( &ctx, tmp, 64 );

	return 0;
}

