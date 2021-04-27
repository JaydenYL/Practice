
from bottle import get, post, run, request

host = '0.0.0.0'
port = 8080

pro_skub = 0
anti_skub = 0

@get('/')
def get_index():
    return '''
<b> Vote today! </b>
<form action='/pro' method='POST'>
<input type="submit" value="Pro Skub!">
</form>

<form action='/anti' method='POST'>
<input type="submit" value="Anti Skub!">
</form>
    '''

@get('/voted')
def you_voted():
    return '''
    <b> Thanks for voting! </b>
    <p>
    Skub: {}
    Anti: {}
    </p >
    '''.format(pro_skub, anti_skub)

@post('/pro')
def pro():
    global pro_skub
    pro_skub += 1
    return you_voted()

@post('/anti')
def anti():
    global anti_skub
    anti_skub += 1
    return you_voted()

run(host=host, port=port)

