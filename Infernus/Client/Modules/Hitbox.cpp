#include "Hitbox.h"

void Hitbox::onGmTick() {
	if (Player != nullptr) {
		MultiPlayerLevel* curr = Player->MultiPlayerLevel;
		size_t size = curr->getListSize();
		if (size > 0 && size <= 5000) {
			for (size_t I = 0; I < size; I++) {
				Actor* currPlayer = curr->get(I);
				if (currPlayer != nullptr && currPlayer != Player) {
					currPlayer->setSize(4.f, 4.f);
				}
			}
		}
	}
}

void Hitbox::onDisable() {
	if (Player != nullptr) {
		MultiPlayerLevel* curr = Player->MultiPlayerLevel;
		size_t size = curr->getListSize();
		if (size > 0 && size <= 5000) {
			for (size_t I = 0; I < size; I++) {
				Actor* currPlayer = curr->get(I);
				if (currPlayer != nullptr && currPlayer != Player) {
					currPlayer->setSize(0.6f, 1.8f);
				}
			}
		}
	}
}