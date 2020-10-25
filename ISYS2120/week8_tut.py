import psycopg2

user = 'y20s2i2120_liyu0792'
host = 'soit-db-pro-2.ucc.usyd.edu.au'
password = '490095315'
try:
	conn = psycopg2.connect(dbname=user, user=user, host=host, password=password)
	with conn.cursor() as cur:
		cur.execute("SET search_path TO unidb")
except:
	print ("Connection failed")
	
