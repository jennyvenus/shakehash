/**
 * @file shake.h
 * @brief SHAKE128 and SHAKE256 extendable-output functions
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2022 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneCRYPTO Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.1.4
 **/

#ifndef _EXTERN_SHAKE_H
#define _EXTERN_SHAKE_H

//Dependencies
#include "extern_crypto.h"
#include "extern_keccak.h"
#include "stdlib.h"

//C++ guard

/**
 * @brief SHAKE algorithm context
 **/

typedef struct
{
   KeccakContext keccakContext;
} ShakeContext;


//SHAKE related constants
extern const uint8_t shake128Oid[9];
extern const uint8_t shake256Oid[9];

//SHAKE related functions
int shakeCompute(uint_t strength, const void *input, int inputLen,
   uint8_t *output, int outputLen);

int shakeInit(ShakeContext *context, uint_t strength);
void shakeUpdate(ShakeContext *context, const void *input, int length);
void shakeFinal(ShakeContext *context);
void shakeSqueeze(ShakeContext *context, uint8_t *output, int length);

#endif
