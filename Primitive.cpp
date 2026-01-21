#include "Primitive.h"
#include "InputManager.h"

Primitive::Primitive()
{
	vertex = nullptr;
	drawPoint = nullptr;
	drawPoint_size = 0;
}

Primitive::~Primitive()
{
	if (drawPoint)
	{
		if (drawPoint_size == 1) {
			delete drawPoint;
		}
		else {
			delete[] drawPoint;
		}
		drawPoint = nullptr;
	}

	if (vertex)
	{
		if (drawPoint_size == 1) {
			delete vertex;
		}
		else {
			delete[] vertex;
		}
		vertex = nullptr;
	}
}

void Primitive::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	Update_drawPoint();

	for (int i = 0; i < children.size(); ++i) {
		children[i]->Update(gameObjects);
	}
}

void Primitive::Set_local_vec(VECTOR_D tr, VECTOR_D rt, VECTOR_D sc)
{
	local_transform = tr;
	local_rotation = rt;
	local_scale = sc;
}

void Primitive::Update_drawPoint()
{
	for (int i = 0; i < drawPoint_size; ++i) {
		drawPoint[i] = vertex[i];
	}

	for (int i = 0; i < drawPoint_size; ++i) {
		drawPoint[i] = vertex[i];
		drawPoint[i] = VTransformD(drawPoint[i], Calculation_MATRIX_Local());
	}

	for (int i = 0; i < drawPoint_size; ++i) {
		drawPoint[i] = VTransformD(drawPoint[i], Calculation_MATRIX());
		Set_Upper_Lower_Limits(drawPoint[i].y);
		Set_Right_Left_Ends(drawPoint[i].x);
	}
}

void Primitive::Test_Check_VEC_Update()
{
#if 1
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_I]) {
		local_transform.y -= 0.01;
	}
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_J]) {
		local_transform.x -= 0.01;
	}
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_M]) {
		local_transform.y += 0.01;
	}
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_K]) {
		local_transform.x += 0.01;
	}

	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_O]) {
		local_rotation.z += 1;
	}
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_U]) {
		local_rotation.z -= 1;
	}

	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_P]) {
		local_scale.x += 0.01;
		local_scale.y += 0.01;
	}
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_L]) {
		local_scale.x -= 0.01;
		local_scale.y -= 0.01;
	}

	printfDx("\nlocal_tr : %f, %f", local_transform.x, local_transform.y);
	printfDx("\nlocal_rt : %f", local_rotation.z);
	printfDx("\nlocal_sc : %f, %f", local_scale.x, local_scale.y);
#endif
}

void Primitive::Show() const
{
	//é©êg
	for (int i = 0; i < drawPoint_size; ++i) {
		int s = i;
		int e = (s < (drawPoint_size - 1) ? s + 1 : 0);
		DrawLine((int)drawPoint[s].x, (int)drawPoint[s].y, (int)drawPoint[e].x, (int)drawPoint[e].y, Get_Color());
	}

	//ìhÇËÇ¬Ç‘Çµ àÍíU
	if (Get_FillFlag()) {
		if (drawPoint_size == 3) {
			DrawTriangle((int)drawPoint[0].x, (int)drawPoint[0].y, (int)drawPoint[1].x, (int)drawPoint[1].y, (int)drawPoint[2].x, (int)drawPoint[2].y, Get_Color(), TRUE);
		}
		else if (drawPoint_size == 4) {
			DrawTriangle((int)drawPoint[0].x, (int)drawPoint[0].y, (int)drawPoint[1].x, (int)drawPoint[1].y, (int)drawPoint[2].x, (int)drawPoint[2].y, Get_Color(), TRUE);
			DrawTriangle((int)drawPoint[0].x, (int)drawPoint[0].y, (int)drawPoint[3].x, (int)drawPoint[3].y, (int)drawPoint[2].x, (int)drawPoint[2].y, Get_Color(), TRUE);
		}
	}

	//éqãü
	for (int i = 0; i < children.size(); ++i) {
		children[i]->Show();
	}
}