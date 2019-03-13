#include "Game.hpp"

void Game::init() {

}

void Game::update() {
	changeScene(Debug::inputFnKey(), 250);
	if (Input::KeyEnter.clicked)
		changeScene(L"Finish", 500);

	m_data->LPlayer.update(bullets);
	m_data->RPlayer.update(bullets);


	/*m_data->RPlayer.receiveDamage(m_data->LPlayer.UpdateMainSkill(m_data->RPlayer.circle()));
	m_data->LPlayer.UpdateSubSkill();
	m_data->LPlayer.UpdateSpecialSkill();

	m_data->LPlayer.receiveDamage(m_data->RPlayer.UpdateMainSkill(m_data->LPlayer.circle()));
	m_data->RPlayer.UpdateSubSkill();
	m_data->RPlayer.UpdateSpecialSkill();*/

	for(auto itr = bullets.begin(); itr != bullets.end();){
		Vec2 myPos = ((**itr).isLeft ? m_data->LPlayer : m_data->RPlayer).circle().center;
		Vec2 oppPos = ((**itr).isLeft ? m_data->RPlayer : m_data->LPlayer).circle().center;
		if((**itr).update(myPos, oppPos)){
			delete *itr;
			itr = bullets.erase(itr);
		}else{
			itr++;
		}
	}

	if(m_data->LPlayer.isHPRunOut() || m_data->RPlayer.isHPRunOut())
		changeScene(L"Finish");
}

void Game::draw() const {
	TextureAsset(L"background").resize(Config::WIDTH, Config::HEIGHT).draw();
	FontAsset(L"CicaR32")(L"I am game scene! Hello!").drawCenter(40, Color(L"#ffffff"));

	/*m_data->LPlayer.DrawMainSkill();
	m_data->LPlayer.DrawSubSkill();
	m_data->LPlayer.DrawSpecialSkill();
	m_data->RPlayer.DrawMainSkill();
	m_data->RPlayer.DrawSubSkill();
	m_data->RPlayer.DrawSpecialSkill();*/
	for(auto bul : bullets){
		bul->draw();
	}

	m_data->LPlayer.drawShip();
	m_data->RPlayer.drawShip();
	m_data->LPlayer.drawGauge();
	m_data->RPlayer.drawGauge();
}
