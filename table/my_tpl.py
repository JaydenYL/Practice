from bottle import *


@route('/')
@route('/hello/<name>')
def greet(name = 'Stranger'):
	m_tpl = SimpleTemplate(source = open("./my.tpl"))
	return m_tpl.render(name = name, name_1 = "name_1",name_2 = " 我 行 了 ")

run (host='localhost' , port=8080, debug = True)