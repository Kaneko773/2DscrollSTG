#pragma once

#include "DxLib.h"

#include <vector>
#include <memory>//shared_ptr

using namespace std;

class GameObject
{
	//親子関係　位置　回転　拡縮

public:
	GameObject();
	~GameObject() {};

	virtual void Update() = 0;
	virtual void Show() const = 0;

	void Set_child(shared_ptr<GameObject> _parent, shared_ptr<GameObject> _child);

	void Test_Set_tr_rt_sc(VECTOR_D tr, VECTOR_D rt, VECTOR_D sc) {//デバッグ
		transform = tr;
		rotation = rt;
		scale = sc;
	}

	void MoveX(double num) {
		transform.x += num;
	}
	void MoveY(double num) {
		transform.y += num;
	}

	virtual bool HitJudge(shared_ptr<GameObject> target) = 0;

	bool hit;//

	virtual void Summarize(vector<shared_ptr<GameObject>>* targets) {
		for (int i = 0; i < children.size(); ++i) {
			targets->push_back(children[i]);
			children[i]->Summarize(targets);
		}
	}


protected:
	shared_ptr<GameObject> parent = nullptr;//親
	vector<shared_ptr<GameObject>> children;//子達

	void WorldMatrixD(MATRIX_D& calc);//自分と親たちの行列をかける
	MATRIX_D Calculation_MATRIX();

	VECTOR_D transform;
	VECTOR_D rotation;
	VECTOR_D scale;
	MATRIX_D trMat;//移動
	MATRIX_D rtMat;//回転
	MATRIX_D scMat;//拡縮

	//primitiveで使用
	MATRIX_D Calculation_MATRIX_Local();

	VECTOR_D local_transform;
	VECTOR_D local_rotation;
	VECTOR_D local_scale;
	MATRIX_D local_trMat;//移動
	MATRIX_D local_rtMat;//回転
	MATRIX_D local_scMat;//拡縮
};

