/**
 * @file QuadEncoder.h
 * @brief Quadrature encoder interface for Arduino and Mbed platforms
 * @author Dan Oates (WPI Class of 2020)
 */

#pragma once
#include <DigitalIn.h>

class QuadEncoder
{
public:
	QuadEncoder(
		Platform::pin_t pin_channel_A,
		Platform::pin_t pin_channel_B,
		float cnt_per_rev,
		bool wrap_angle = false);
	float get_angle();
	void zero();
	void interrupt_A();
	void interrupt_B();
	operator float();
protected:
	DigitalIn channel_A;
	DigitalIn channel_B;
	float rad_per_cnt;
	bool wrap_angle;
	int32_t counts;
};
