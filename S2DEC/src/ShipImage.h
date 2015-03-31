#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "ShipPhysics.h"
#include "Game.h"

namespace S2D{

	class ShipImage : public Component{
	private:
		ShipPhysics* shipPhysics{nullptr};
		sf::Sprite sprite;
		sf::Texture texture;	
	public:
		ShipImage(const string filename){
			texture.loadFromFile(filename);
			sprite.setTexture(texture);
			sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
			sprite.setPosition(SCREEN_SIZE.x / 2.0f, SCREEN_SIZE.y / 2.0f);
		}
		
		void init() override{
			if(owner->hasComponent<ShipPhysics>()){
				shipPhysics = &owner->getComponent<ShipPhysics>();
			}else{
				cerr << owner->getName() << ": ShipPhysics component missing" << endl;
			}
		}
		
		bool update(sf::Time frameTime) override{
			if(shipPhysics != nullptr){
				//sprite.setPosition(shipPhysics->getPosition());
			}	
			return false;
		}

		void draw(sf::RenderTarget& target) override{
			target.draw(sprite);
		}
	};
}