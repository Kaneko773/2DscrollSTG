#pragma once

typedef long long LONGLONG;

class FrameRateManager
{
public:
	void FrameRateUpdate();
	float Get_Deltatime() const {
		return deltaTime;
	}

private:
	static FrameRateManager* pInstance;

	LONGLONG nowTime;
	LONGLONG prevTime;
	float deltaTime;



private:
	FrameRateManager();
	virtual ~FrameRateManager() {};

	FrameRateManager(const FrameRateManager&) = delete;
	void operator=(const FrameRateManager&) = delete;

public:
	static FrameRateManager* getInstance();
	static void create();
	static void destroy();
};
