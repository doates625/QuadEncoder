/**
 * @file QuadEncoder.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "QuadEncoder.h"
#include <CppUtil.h>

/**
 * @brief Constructs quad encoder interface
 * @param channel_A Channel A input
 * @param channel_B Channel B input
 * @param cnt_per_rev Resolution [counts per revolution]
 * @param wrap_angle Wraps angle to range [-pi, +pi] if true
 */
QuadEncoder::QuadEncoder(
	DigitalIn* channel_A,
	DigitalIn* channel_B,
	float cnt_per_rev,
	bool wrap_angle)
{
	this->channel_A = channel_A;
	this->channel_B = channel_B;
	this->rad_per_cnt = 2.0f * M_PI / cnt_per_rev;
	this->wrap_angle = wrap_angle;
	this->counts = 0;
}

/**
 * @brief Returns encoder angle [rad]
 * 
 * Note: Briefly globally disables interrupts
 */
float QuadEncoder::get_angle()
{
	Platform::disable_interrupts();
	int32_t counts_copy = counts;
	Platform::enable_interrupts();
	float angle = counts_copy * rad_per_cnt;
	if (wrap_angle)
	{
		angle = CppUtil::wrap(angle, -M_PI, +M_PI);
	}
	return angle;
}

/**
 * @brief Resets encoder to zero at current angle
 * 
 * Note: Briefly globally disables interrupts
 */
void QuadEncoder::zero()
{
	Platform::disable_interrupts();
	counts = 0;
	Platform::enable_interrupts();
}

/**
 * @brief Pin change ISR for channel A
 */
void QuadEncoder::interrupt_A()
{
	counts = (channel_A == channel_B) ? counts + 1 : counts - 1;
}

/**
 * @brief Pin change ISR for channel B
 */
void QuadEncoder::interrupt_B()
{
	counts = (channel_A == channel_B) ? counts - 1 : counts + 1;
}

/**
 * @brief Shorthand for get_angle()
 */
QuadEncoder::operator float()
{
	return get_angle();
}