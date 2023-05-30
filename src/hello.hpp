#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Node.hpp>

using namespace godot;

class Hello : public Node
{
	GODOT_CLASS(Hello, Node)

public:
	static void _register_methods();

	void _init(); // our initializer called by Godot

	void hello();
	void hi();
	void modify_params(Variant data);
};

#endif
