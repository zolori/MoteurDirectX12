#include "EngineTimer.h"

EngineTimer::EngineTimer() : mSecondsPerCount(0.0), mDeltaTime(-1.0), mBaseTime(0), mPausedTime(0), mPrevTime(0), mCurrentTime(0), mStopTime(false) {
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	mSecondsPerCount = 1.0 / (double)countsPerSec;
}

void EngineTimer::Tick() {
	if (isStopped) {
		mDeltaTime = 0.0;
		return;
	}
	__int64 currentTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	mCurrentTime = currentTime;

	mDeltaTime = (mCurrentTime - mPrevTime) * mSecondsPerCount;


}