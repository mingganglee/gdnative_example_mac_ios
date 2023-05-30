#include "hello.hpp"

void Hello::_register_methods()
{
    register_method("hello", &Hello::hello);
    register_method("hi", &Hello::hi);
    register_method("modify_params", &Hello::modify_params);
    register_signal<Hello>((char *)"hi_callback", "data", GODOT_VARIANT_TYPE_STRING);
    register_signal<Hello>((char *)"modify_params_callback", "data", GODOT_VARIANT_TYPE_DICTIONARY);
}

void Hello::_init()
{
}

void Hello::hello()
{
    Godot::print("hello world!");
}

void Hello::hi()
{
    emit_signal("hi_callback", "hi!!!");
}

void Hello::modify_params(Variant data)
{

    Dictionary res;
    res["code"] = 0;
    res["data"] = data;

    emit_signal("modify_params_callback", res);
}
