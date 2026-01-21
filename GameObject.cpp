#include "GameObject.h"
#include "DxLib.h"

GameObject::GameObject()
{
	transform = { 0, 0 };
	rotation = { 0, 0, 0 };
	scale = { 1, 1 };
	trMat = rtMat = scMat = MGetIdentD();

	local_transform = { 0, 0 };
	local_rotation = { 0, 0, 0 };
	local_scale = { 1, 1 };
	local_trMat = local_rtMat = local_scMat = MGetIdentD();

	manager = "";
	hp = 0;

	upperLimit = lowerLimit = rightEnd = leftEnd = 0;

	color = GetColor(255, 255, 255);
	fillFlag = false;

	hit = false;
	destroy = false;
}

void GameObject::Set_child(shared_ptr<GameObject> _parent, shared_ptr<GameObject> _child)
{
	children.push_back(_child);
	_child->parent = _parent;
}

void GameObject::WorldMatrixD(MATRIX_D& calc)
{
	calc = MMultD(calc, scMat);
	calc = MMultD(calc, rtMat);
	calc = MMultD(calc, trMat);

	if (parent != nullptr) {
		parent->WorldMatrixD(calc);
	}
}

MATRIX_D GameObject::Calculation_MATRIX()
{
	trMat = MGetTranslateD(transform);
	rtMat = MGetRotZD(DX_PI_F * (rotation.z / 180.0f));
	scMat = MGetScaleD(scale);

	MATRIX_D calc = MGetIdentD();//単位行列
	WorldMatrixD(calc);

	return calc;
}

MATRIX_D GameObject::Calculation_MATRIX_Local()
{
	local_trMat = MGetTranslateD(local_transform);
	local_rtMat = MGetRotZD(DX_PI_F * (local_rotation.z / 180.0f));
	local_scMat = MGetScaleD(local_scale);

	MATRIX_D calc = MGetIdentD();//単位行列
	calc = MMultD(calc, local_scMat);
	calc = MMultD(calc, local_rtMat);
	calc = MMultD(calc, local_trMat);

	return calc;
}