#include "./JudgmentTime.hpp"

bool JudgmentTime::update(Vec2 _myPos, Vec2 _oppPos){
	pos = _oppPos;
	--lifeTime;

	return Bullet::update(_myPos, _oppPos);
}

void JudgmentTime::draw(){
	getShape().draw(ColorF(L"#3333ff").setAlpha(0.5));
}

bool JudgmentTime::isVisible() {
	return lifeTime != 0;
}

int JudgmentTime::getDamage(Circle _circle){
	return 0;
}
