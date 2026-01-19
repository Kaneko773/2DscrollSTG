#pragma once

#include "DxLib.h"

#include <vector>
#include <memory>//shared_ptr
#include <string>

using namespace std;

class GameObject
{
	//親子関係　位置　回転　拡縮

public:
	GameObject();
	~GameObject() {};

	virtual void Update(vector<shared_ptr<GameObject>>* gameObjects) = 0;
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

	VECTOR_D Get_Transform() const {
		return transform;
	}

	virtual bool HitJudge(shared_ptr<GameObject> target) = 0;

	virtual void Summarize(vector<shared_ptr<GameObject>>* targets) {
		for (int i = 0; i < children.size(); ++i) {
			targets->push_back(children[i]);
			children[i]->Summarize(targets);
		}
	}

public:
	string Get_manager() {
		return manager;
	}
	void Set_manager(string _manager) {
		manager = _manager;
	}
	virtual void Get_Damage() {
		hp -= 1;
		hit = true;
	}
	int Get_Hp() const {
		return hp;
	}
	void Set_hp(int _hp) {
		hp = _hp;
	}
	void Reset_Hit() {
		hit = false;
	}
	bool Get_Hit() const {
		return hit;
	}

protected:
	string manager;
	int hp;
	bool hit;


public:
	double Get_upperLimit() const {
		return upperLimit;
	}
	double Get_lowerLimit() const {
		return lowerLimit;
	}
	//ずらす分渡す
	void Shift_transform_y(double shift) {
		transform.y += shift;
	}
	double Get_rightEnd() const {
		return rightEnd;
	}
	double Get_leftEnd() const {
		return leftEnd;
	}

protected:
	void Set_Upper_Lower_Limits(double tr_y) {
		if (parent != nullptr) {
			parent->Set_Upper_Lower_Limits(tr_y);
		}
		else {
			if (tr_y < upperLimit) upperLimit = tr_y;
			if (tr_y > lowerLimit) lowerLimit = tr_y;
		}
	}
	void Set_Right_Left_Ends(double tr_x) {
		if (parent != nullptr) {
			parent->Set_Right_Left_Ends(tr_x);
		}
		else {
			if (tr_x < leftEnd) leftEnd = tr_x;
			if (tr_x > rightEnd) rightEnd = tr_x;
		}
	}
	double upperLimit;
	double lowerLimit;
	double rightEnd;
	double leftEnd;


public:
	void Set_Color(unsigned int _color) {
		color = _color;
	}
	unsigned int Get_Color() const {
		if (parent != nullptr) {
			return parent->Get_Color();
		}
		return color;
	}
	void Set_FillFlag(bool flag) {
		fillFlag = flag;
	}
	bool Get_FillFlag() const {
		if (parent != nullptr) {
			return parent->Get_FillFlag();
		}
		return fillFlag;
	}

protected:
	unsigned int color;
	bool fillFlag;

	
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

