/**
 * @file QuadEncoder.h
 * @brief Quadrature encoder interface and Arduino and Mbed platforms
 * @author Dan Oates (WPI Class of 2020)
 * 
 * This class provides the methods interrupt_A and interrupt_B for each encoder,
 * which must be called on both rising and falling edges for channels A and B
 * (respectively). Because interrupt implementation is very device-specific, it
 * is the responsibility of the user to configure ISRs and call these methods.
 * 
 * Dependencies:
 * - Platform: https://github.com/doates625/Platform.git
 * - DigitalIn: https://github.com/doates625/DigitalIn.git
 * - CppUtil: https://github.com/doates625/CppUtil.git
 * 
 * References:
 * - Quadrature Encoders: http://www.creative-robotics.com/quadrature-intro
 */

#pragma once
#include <DigitalIn.h>

class QuadEncoder
{
public:
	QuadEncoder(
		DigitalIn* channel_A,
		DigitalIn* channel_B,
		float cnt_per_rev,
		bool wrap_angle = false);
	float get_angle();
	void zero();
	void interrupt_A();
	void interrupt_B();
	operator float();
protected:
	DigitalIn* channel_A;
	DigitalIn* channel_B;
	float rad_per_cnt;
	bool wrap_angle;
	int32_t counts;
};