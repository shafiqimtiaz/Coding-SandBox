#include<iostream>
#include<string>

using namespace std;

class Entity {
	int x, y;
public:
	string name;

	Entity(string name, int x = 0, int y = 0)
		:name(name), x(x), y(y) {}

	void Move(int dx, int dy) {
		x += dx;
		y += dy;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	void printData() {
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << "name: " << name << endl;
	}

};

class Something {

public:
	bool visible;
	Something(bool visible = true) :visible(visible) {}

	bool i_can_see_you() { return visible; }
};


class Mesh : public Entity, private Something {
	string texture;
	static int id;
public:
	Mesh(string texture, string name = "mesh" + to_string(id), int x = 0, int y = 0)
		:texture(texture), Entity(name, x, y), Something(true)
	{
		id++;
	}

	void throw_back(Entity e) {
		if (e.getX() == this->getX() && e.getY() == this->getY())
			e.Move(-1, -1);
	}

	void printData() {
		Entity::printData();
		cout << "texture: " << texture << endl;
		cout << "visiblity: " << visible << endl;
	}

};

class RectangleMesh : public Mesh {

public:
	int w, h;
	RectangleMesh(int w, int h) :h(h), w(w), Mesh("sun") {}

	void doSomething() {
		cout << this->name << endl;
	}
};