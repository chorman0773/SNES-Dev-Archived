/*
 * controller.h
 *
 *  Created on: Mar 18, 2019
 *      Author: chorm
 */

#ifndef INCLUDE_SNES_DEV_CONTROLLER_H_
#define INCLUDE_SNES_DEV_CONTROLLER_H_

#define NORMAL_CONTROLLER_SIGNATURE 0

#include <stdbool.h>

typedef struct __snes_controller{
	bool b:1;
	bool y:1;
	bool select:1;
	bool start:1;
	bool up:1;
	bool down:1;
	bool left:1;
	bool right:1;
	bool a:1;
	bool x:1;
	bool L:1;
	bool R:1;
	unsigned char signature:4;
}__attribute__((packed)) snes_controller;

#ifdef SNES_DEV_WANT_EXTENDED_CONTROLLER
typedef struct __snes_controller_ext{
	snes_controller main;
	signed char axisX;
	signed char axisY;
}__attribute__((packed)) extended_controller;
#endif


#endif /* INCLUDE_SNES_DEV_CONTROLLER_H_ */
