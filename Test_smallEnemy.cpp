#include "Test_smallEnemy.h"

#include "Square.h"
#include "Triangle.h"

Test_smallEnemy::Test_smallEnemy()
{
	//}Œ`‚ğ‘g‚İ‡‚í‚¹‚Ä‘Ì‚ğì‚é
	shared_ptr<Square> body = make_shared<Square>();
	enemy->Set_child(enemy, body);
	shared_ptr<Triangle> head = make_shared<Triangle>();
	enemy->Set_child(enemy, head);
	head->Set_local_vec({ 0, -0.79 }, { 0, 0, 0 }, { 1, 1 });
	shared_ptr<Triangle> wing1 = make_shared<Triangle>();
	enemy->Set_child(enemy, wing1);
	wing1->Set_local_vec({ -0.79, 0.5 }, { 0, 0, 30 }, { 1, 1 });
	shared_ptr<Triangle> wing2 = make_shared<Triangle>();
	enemy->Set_child(enemy, wing2);
	wing2->Set_local_vec({ 0.79, 0.5 }, { 0, 0, -30 }, { 1, 1 });

	//ˆê“I
	enemy->Test_Set_tr_rt_sc({ 0, 0 }, { 0, 0, 90 }, { 50, 50 });
}