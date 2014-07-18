/*
 * H.265 video codec.
 * Copyright (c) 2013-2014 struktur AG, Dirk Farin <farin@struktur.de>
 *
 * This file is part of libde265.
 *
 * libde265 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libde265 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libde265.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ANALYZE_H
#define ANALYZE_H

#include "libde265/nal-parser.h"
#include "libde265/decctx.h"
#include "libde265/encode.h"
#include "libde265/slice.h"
#include "libde265/scan.h"
#include "libde265/intrapred.h"
#include "libde265/transform.h"
#include "libde265/fallback-dct.h"
#include "libde265/quality.h"
#include "libde265/fallback.h"
#include "libde265/configparam.h"


enum IntraPredMode find_best_intra_mode(de265_image& img,int x0,int y0, int blkSize, int cIdx,
                                        const uint8_t* ref, int stride);

void diff_blk(int16_t* out,int out_stride,
              const uint8_t* a_ptr, int a_stride,
              const uint8_t* b_ptr, int b_stride,
              int blkSize);

enc_cb* encode_cb_no_split(encoder_context*, const de265_image* input,
                           int x0,int y0, int log2CbSize, int ctDepth, int qp);

enc_cb* encode_cb_split(encoder_context*, const de265_image* input,
                        int x0,int y0, int Log2CbSize, int ctDepth, int qp);

enc_cb* encode_cb_may_split(encoder_context*, const de265_image* input,
                            int x0,int y0, int Log2CtbSize, int ctDepth, int qp);

double encode_image(encoder_context*, const de265_image* input, int qp);

void encode_sequence(encoder_context*);

#endif