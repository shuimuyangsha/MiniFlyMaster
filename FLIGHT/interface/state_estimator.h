#ifndef __STATE_ESTIMATOR_H
#define __STATE_ESTIMATOR_H
#include "stabilizer_types.h"

/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 * ALIENTEK MiniFly
 * ��̬�������	
 * ����ԭ��@ALIENTEK
 * ������̳:www.openedv.com
 * ��������:2017/5/2
 * �汾��V1.0
 * ��Ȩ���У�����ؾ���
 * Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
 * All rights reserved
********************************************************************************/

typedef struct
{
	float estimatedZ; // ��ǰ��Z����ֵ��asl������ͬ��ƫ���� The current Z estimate, has same offset as asl
	float velocityZ; // �ɴ�ֱ���ٶ�(m/s)���ֵõ��Ĵ�ֱ�ٶ�(��������ϵ) Vertical speed (world frame) integrated from vertical acceleration (m/s)
	float estAlpha;
	float velocityFactor;
	float vAccDeadband; // ��ֱ���ٶ����� Vertical acceleration deadband
	float velZAlpha;   // ������ӱ����˴�ֱ�ٶȻ������ Blending factor to avoid vertical speed to accumulate error
	float velocityX;	/* x �����ٶ�(��������ϵ) ��x������ٶȻ��ֵó� ��λ(m/s)*/
	float velocityY;	/* y �����ٶ�(��������ϵ) ��y������ٶȻ��ֵó� ��λ(m/s)*/
} selfState_t;

void stateEstimator(state_t *state, const sensorData_t *sensorData, const u32 tick);

#endif /* __STATE_ESTIMATOR_H */
