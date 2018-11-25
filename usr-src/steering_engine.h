#ifndef _STEERING_ENGINE_H
#define _STEERING_ENGINE_H

typedef struct StreeingEngine
{
	int a;
} StreeingEngine;

void StreeingEngine_positiveRotate(StreeingEngine* o);
void StreeingEngine_reverseRotate(StreeingEngine* o);

#endif
