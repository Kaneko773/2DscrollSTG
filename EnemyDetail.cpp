#include "EnemyDetail.h"

#include "Primitive.h"

bool EnemyDetail::HitJudge(shared_ptr<GameObject> target)
{
	//自身は判定無し

	for (int i = 0; i < children.size(); ++i) {
		if (children[i]->HitJudge(target)) {//何か１つでも当たれば残りは判定しない
			return true;
		}
	}

	return false;
}

void EnemyDetail::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	upperLimit = lowerLimit = transform.y;//
	rightEnd = leftEnd = transform.x;//

	Calculation_MATRIX();//子が使うので計算しておく

	//デバッグ
#if 0
	shared_ptr<Primitive> temp = dynamic_pointer_cast<Primitive>(children[0]);
	if (temp != nullptr)temp->Test_Check_VEC_Update();
#endif

	for (int i = 0; i < children.size(); ++i) {
		children[i]->Update(gameObjects);
	}
}

void EnemyDetail::Show() const
{
	for (int i = 0; i < children.size(); ++i) {
		children[i]->Show();
	}
}