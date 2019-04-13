#include "./Player.hpp"
#include "../skills/Jump.hpp"
#include "../skills/Shield.hpp"
#include "../skills/Missile.hpp"


void Player::doSubSkill(std::vector<Bullet*>& bullets){
	if(KeySubSkill.repeat(0)){switch(this->whatSubSkill){
	case JUMP:
			if (GamePad::Move(isLeft, 1) != Vec2(0, 0)) {
				bullets.push_back(new Jump(pos, isLeft));
				coolDownTime = 120;
			}
		break;

	case SHIELD:
			bullets.push_back(new Shield(pos, isLeft));
			coolDownTime = 600;
		break;

	case MISSILE:
			bullets.push_back(new Missile(pos, isLeft));
			coolDownTime = 30;
		break;

	case BOMB:

		break;

	default:
		LOG_ERROR(L"doSubSkillで意図しない値が参照されました。");
	}}

}
