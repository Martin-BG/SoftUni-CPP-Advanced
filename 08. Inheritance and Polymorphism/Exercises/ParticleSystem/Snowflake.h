#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <cstdlib>
#include "Particle.h"

class Snowflake : public Particle {
	bool lastMovedDown;
public:
	Snowflake(Position p, int lifetime) : Particle(p, '*', lifetime), lastMovedDown(false) {}

	virtual void update(std::list<Particle*>& producedParticlesOutput) override {
		Particle::update(producedParticlesOutput);

		if (!this->lastMovedDown) {
			this->position = this->position.nextRow();
		}
		this->lastMovedDown = !this->lastMovedDown;

		switch (rand() % 2) {
		case 0:
			this->position = this->position.prevCol();
			break;
		case 1:
			this->position = this->position.nextCol();
			break;
		}
	}
};

#endif // !SNOWFLAKE_H

