#include "Explosion_Animation.h"

#include "FrameRateManager.h"

Explosion_Animation::Explosion_Animation()
{
	ExplosionGraph = LoadGraph("‰æ‘œ/Explosion.png");
	explosion_handle[0] = DerivationGraph(0, 0, 83, 83, ExplosionGraph);
	explosion_handle[1] = DerivationGraph(83, 0, 83, 83, ExplosionGraph);
	explosion_handle[2] = DerivationGraph(166, 0, 83, 83, ExplosionGraph);
	explosion_handle[3] = DerivationGraph(0, 83, 83, 83, ExplosionGraph);
	explosion_handle[4] = DerivationGraph(83, 83, 83, 83, ExplosionGraph);
	explosion_handle[5] = DerivationGraph(166, 83, 83, 83, ExplosionGraph);
	explosion_handle[6] = DerivationGraph(0, 166, 83, 83, ExplosionGraph);
	explosion_handle[7] = DerivationGraph(83, 166, 83, 83, ExplosionGraph);
	explosion_handle[8] = DerivationGraph(166, 166, 83, 83, ExplosionGraph);

	exploding = false;
	timer = 0;
	prevTime = timer;
	nowExplosionHandleNum = 0;

	size = 1;
}

Explosion_Animation::~Explosion_Animation()
{
	for (int i = 0; i < 9; ++i) {
		DeleteGraph(explosion_handle[i]);
	}
	DeleteGraph(ExplosionGraph);
}

void Explosion_Animation::Explosion_Start(float _size)
{
	exploding = true;
	size = _size;
}

bool Explosion_Animation::Explosion_Update()
{
	if (!exploding) return true;

	timer += FrameRateManager::getInstance()->Get_Deltatime();
	if (timer >= prevTime + interval) {
		prevTime = timer;
		if (nowExplosionHandleNum < 8) {
			++nowExplosionHandleNum;
		}
		else {
			return false;
		}
	}

	return true;
}

void Explosion_Animation::Show(VECTOR_D drawPos) const
{
	if (!exploding)return;
	VECTOR_D upperLeftPos = { drawPos.x - size / 2, drawPos.y - size / 2 };
	DrawExtendGraph((int)upperLeftPos.x, (int)upperLeftPos.y, (int)(upperLeftPos.x + size), (int)(upperLeftPos.y + size), explosion_handle[nowExplosionHandleNum], TRUE);
}