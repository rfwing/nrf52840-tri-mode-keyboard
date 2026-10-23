/*
 * Copyright (c) 2026 rfw
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <caf/gpio_pins.h>

/* 4 列驱动引脚 (全部在 Port 0) */
static const struct gpio_pin col[] = {
	{ .port = 0, .pin = 5 },   /* COL0: P0.05 */
	{ .port = 0, .pin = 6 },   /* COL1: P0.06 */
	{ .port = 0, .pin = 26 },  /* COL2: P0.26 (已释放 32.768kHz 晶振) */
	{ .port = 0, .pin = 30 },  /* COL3: P0.30 */
};

/* 6 行输入引脚 (注意 ROW4 在 Port 1) */
static const struct gpio_pin row[] = {
	{ .port = 0, .pin = 15 },  /* ROW0: P0.15 (旋钮中键按压) */
	{ .port = 0, .pin = 7 },   /* ROW1: P0.07 */
	{ .port = 0, .pin = 12 },  /* ROW2: P0.12 */
	{ .port = 0, .pin = 4 },   /* ROW3: P0.04 */
	{ .port = 1, .pin = 9 },   /* ROW4: P1.09 (Port 1 跨端口) */
	{ .port = 0, .pin = 8 },   /* ROW5: P0.08 */
};
