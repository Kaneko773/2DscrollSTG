#include "PlayerDetail.h"

#include "Square.h"
#include "Triangle.h"
#include "InputManager.h"

PlayerDetail::PlayerDetail()
{
	rotation.z = 90;

	scale.x = scale.y = 50;
}

PlayerDetail::~PlayerDetail()
{

}

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

void PlayerDetail::Update()
{
#if 1
	if (InputManager::getInstance()->input_keyFewSec[KEY_INPUT_W]) {
		transform.y -= 1;
	}
	if (InputManager::getInstance()->input_keyFewSec[KEY_INPUT_A]) {
		transform.x -= 1;
	}
	if (InputManager::getInstance()->input_keyFewSec[KEY_INPUT_S]) {
		transform.y += 1;
	}
	if (InputManager::getInstance()->input_keyFewSec[KEY_INPUT_D]) {
		transform.x += 1;
	}

	if (InputManager::getInstance()->input_keyFewSec[KEY_INPUT_RIGHT]) {
		rotation.z += 1;
	}
	if (InputManager::getInstance()->input_keyFewSec[KEY_INPUT_LEFT]) {
		rotation.z -= 1;
	}

	if (InputManager::getInstance()->input_keyFewSec[KEY_INPUT_UP]) {
		scale.x += 1;
		scale.y += 1;
	}
	if (InputManager::getInstance()->input_keyFewSec[KEY_INPUT_DOWN]) {
		scale.x -= 1;
		scale.y -= 1;
	}
#endif

	Calculation_MATRIX();//子が使うので計算しておく

	//デバッグ
#if 0
	shared_ptr<Primitive> temp = dynamic_pointer_cast<Primitive>(children[3]);
	if (temp != nullptr)temp->Test_Original_Update();
#endif

	for (int i = 0; i < children.size(); ++i) {

		children[i]->Update();
	}
}

void PlayerDetail::Show() const
{
	//絵の表示
	for (int i = 0; i < children.size(); ++i) {
		children[i]->Show();
	}
}

void PlayerDetail::Initialization(shared_ptr<GameObject> player)
{
	shared_ptr<Square> body = make_shared<Square>();
	Set_child(player, body);
	shared_ptr<Triangle> head = make_shared<Triangle>();
	Set_child(player, head);
	head->Set_local_vec({ 0, -0.79 }, { 0, 0, 0 }, { 1, 1 });
	shared_ptr<Triangle> wing1 = make_shared<Triangle>();
	Set_child(player, wing1);
	wing1->Set_local_vec({ -0.79, 0.5 }, { 0, 0, 30 }, { 1, 1 });
	shared_ptr<Triangle> wing2 = make_shared<Triangle>();
	Set_child(player, wing2);
	wing2->Set_local_vec({ 0.79, 0.5 }, { 0, 0, -30 }, { 1, 1 });
}