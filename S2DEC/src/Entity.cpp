#include "Entity.h"

using namespace S2D;

Entity::Entity(string name) : id(currentId), name(name){
	currentId++;
}

const int Entity::getId(){
	return id;
}

const string Entity::getName(){
	return name;
}

void Entity::onStart(){
	for(auto& component : components){
		component->onStart();
	}
}

bool Entity::update(sf::Time frameTime){
	iterating = true;
	for(auto& component : components){
		component->update(frameTime);
	}
	iterating = false;
	addQueuedComponents();
	return false;
}

void Entity::draw(sf::RenderTarget& target){
	for(auto& component : components){
		component->draw(target);
	}
}

const bool Entity::isAlive(){
	return alive;
}

void Entity::destroy(){
	alive = false;
}

//TODO: NOT TESTED
void Entity::addQueuedComponents(){
	for(auto component : queuedComponents){
		unique_ptr<Component> uniqueComponentPtr{component};
		components.emplace_back(move(uniqueComponentPtr));
		componentArray[component->id] = component;
		componentBitset[component->id] = true;
		component->init();
	}
	queuedComponents.clear();
}