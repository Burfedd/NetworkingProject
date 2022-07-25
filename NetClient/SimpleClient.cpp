#include <iostream>
#include "net.h"

enum class CustomMessageTypes : uint32_t {
	Shoot,
	MovePlayer
};

int main() {
	base::net::message<CustomMessageTypes> msg;
	msg.header.id = CustomMessageTypes::MovePlayer;

	int a = 1;
	bool b = false;
	float c = 3.14159f;

	struct {
		float x;
		float y;
	} d[5];

	msg << a << b << c << d;

	a = 0;
	b = true;
	c = 9.99f;

	msg >> d >> c >> b >> a;

	return 0;
}