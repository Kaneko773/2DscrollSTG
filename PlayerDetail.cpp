#include "PlayerDetail.h"

bool PlayerDetail::HitJudge(shared_ptr<GameObject> target)
{
	//自身は判定無し

	for (int i = 0; i < children.size(); ++i) {
		if (children[i]->HitJudge(target)) {//何か１つでも当たれば残りは判定しない
			return true;
		}
	}

	return false;
}

void PlayerDetail::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	upperLimit = lowerLimit = transform.y;
	rightEnd = leftEnd = transform.x;

	Calculation_MATRIX();//子が使うので計算しておく

	for (int i = 0; i < children.size(); ++i) {
		children[i]->Update(gameObjects);
	}
}

void PlayerDetail::Show() const
{
	for (int i = 0; i < children.size(); ++i) {
		children[i]->Show();
	}
}