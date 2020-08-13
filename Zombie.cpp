#include "Zombie.h"
#include "TextureHolder.h"

Zombie::Zombie() {
	//m_Sprite = Sprite(TextureHolder::GetTexture(
	//	"graphics/zombie.png"));
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/zombie.png"));
}

// overiden update function


bool Zombie::handleInput() {
	return false;
};

int coun_t = 3;

bool Zombie::update(Grid& grid) {
	bool isCaught = false;
	cout << "The zombie is moving 1" << endl;
	try {
		if (coun_t < 7) {
			this_thread::sleep_for(0.5s);
			FloatRect playerStart = grid.node[11][0].getPosition();
			cout << "The zombie is moving 2" << endl;
			m_Sprite.setPosition(Vector2f(playerStart.left, playerStart.top));
		}

	}
	catch(exception e){
		cout << e.what() << endl;
	}

	coun_t += 1;
	return true;
}

void Zombie::setCurrNode(Vector2i _currNode) {
	currNode.x = _currNode.x;
	currNode.y = _currNode.y;
}

Vector2i Zombie::getCurrNode() {
	return currNode;
}