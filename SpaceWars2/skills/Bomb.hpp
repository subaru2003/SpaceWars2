#pragma once
#include <Siv3D.hpp>
#include "Bullet.hpp"
#include "../CommonData.hpp"


class Bomb final : public Bullet {
private:
	bool explosion = false;
	static int numberOfLUsed;
	static int numberOfRUsed;
	int BombUsed;
	static int numberOfBomb;
	const static int EXPLODE_RADIUS = 100;
	Circle getShape() {
		if (explosion) {
			return Circle(pos, EXPLODE_RADIUS);
		}
		else {
			return Circle(pos, 40);
		}

	}
public:
	Bomb(Vec2 _pos, bool _isLeft) : Bullet(_pos, _isLeft) {
		vel = Vec2(bulletSpeed * (isLeft ? 1 : -1), 0);
		if (isLeft) {
			numberOfLUsed++;
		}
		else {
			numberOfRUsed++;
		}
		nowBombNumber = (isLeft ? numberOfLUsed : numberOfRUsed);
		Println(nowBombNumber);
	}
	~Bomb() {

	}
	int nowBombNumber;
	int fuse = 0;
	int bulletSpeed = 20;
	bool update(Vec2 _myPos, Vec2 _oppPos) override;
	void draw() override;
	bool isVisible() override;
	int getDamage(Circle _circle) override;
};
