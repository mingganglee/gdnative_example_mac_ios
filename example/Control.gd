extends Control



const hello_native: NativeScript = preload("res://addons/hello/hello.gdns")
onready var hello = hello_native.new()

func _ready():
	add_child(hello)
	hello.connect("hi_callback", self, "hi_callback")
	hello.connect("modify_params_callback", self, "modify_params_callback")


func _on_Hello_pressed():
	hello.hello()


func _on_Hi_pressed():
	hello.hi()


func _on_ModifyParams_pressed():
	var data = {
		"name": "zhangsan",
		"age": 18
	}
	hello.modify_params(data)


func hi_callback(data):
	prints("hi_callback", data)


func modify_params_callback(data):
	prints("modify_params_callback", data)
