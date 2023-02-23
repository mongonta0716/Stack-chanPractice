// Copyright (c) Shinya Ishikawa. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.
// modified by robo8080

#include "DannMouth.h"

namespace m5avatar {

DannMouth::DannMouth(uint16_t minWidth, uint16_t maxWidth, uint16_t minHeight,
             uint16_t maxHeight)
    : minWidth{minWidth},
      maxWidth{maxWidth},
      minHeight{minHeight},
      maxHeight{maxHeight} {}

void DannMouth::draw(M5Canvas *spi, BoundingRect rect, DrawContext *ctx) {
  Expression exp = ctx->getExpression();
  uint32_t primaryColor = ctx->getColorPalette()->get(COLOR_PRIMARY);
  uint32_t backgroundColor = ctx->getColorPalette()->get(COLOR_BACKGROUND);
  float breath = _min(1.0f, ctx->getBreath());
  float openRatio = ctx->getMouthOpenRatio();
  int h = minHeight + (maxHeight - minHeight) * openRatio;
  int h1 = h/4;
  int w = maxWidth;
  int x = rect.getLeft() - w / 2;
  int y = rect.getTop() - h / 2 + breath * 2;
  int y1 = rect.getTop() - h1 / 2 + breath * 2;

  if (openRatio == 0.0)
  {
//    h = 8;
    spi->fillTriangle(x+w/2, y1+25, x+w/2+21, y1-20, x+w/2-21, y1-20, TFT_BLACK);
    spi->fillTriangle(x+w/2, y1+18, x+w/2+17, y1-15, x+w/2-17, y1-15, TFT_PINK);

    } else {
    spi->fillEllipse(x+w/2, y+h/2, w/10, h/2, (uint16_t)TFT_BLACK);
    spi->fillEllipse(x+w/2, y+h/2, w/11, h/3, (uint16_t)TFT_PINK); 
    }
//o  spi->fillTriangle(x+w/2, y1+25, x+w/2+21, y1-20, x+w/2-21, y1-20, TFT_BLACK);
//o  spi->fillTriangle(x+w/2, y1+18, x+w/2+17, y1-15, x+w/2-17, y1-15, TFT_PINK);

//ほっぺ左
  spi->drawLine(x-w/2, y1+10, x-w/2+5, y1-10, TFT_RED);
  spi->drawLine(x-w/2+10, y1+10, x-w/2+15, y1-10, TFT_RED);
  spi->drawLine(x-w/2+20, y1+10, x-w/2+25, y1-10, TFT_RED);

//ほっぺ右
  spi->drawLine(x+w+10, y1+10, x+w+15, y1-10, TFT_RED);
  spi->drawLine(x+w+20, y1+10, x+w+25, y1-10, TFT_RED);
  spi->drawLine(x+w+30, y1+10, x+w+35, y1-10, TFT_RED);

    }
} // namespace m5avatar