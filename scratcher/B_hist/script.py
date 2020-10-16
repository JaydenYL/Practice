import json
import requests
import time

def read_cookies_file(filename):
	"""read cookie txt file
	:param filename: (str) cookies file path
	:return: (dict) cookies
	"""
	with open(filename, 'r') as fp:
		cookies = fp.read()
		return cookies


def get_header(filename):
	cookie = read_cookies_file(filename)
	headers = {
		'Accept': '*/*',
		'Accept-Encoding': 'gzip, deflate, br',
		'Accept-Language': 'zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7',
		'Connection': 'keep-alive',
		'Cookie': cookie,
		'Host': 'api.bilibili.com',
		'Referer': 'https://www.bilibili.com/account/history',
		'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_2) AppleWebKit/537.36 '
					  '(KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36'
	}
	return headers


def req_get(headers, url):
	resp = requests.get(url, headers=headers)
	return json.loads(resp.text)
	
MAX_PAGE = 1000
def get_all_bili_history(cookie_file):
	headers = get_header(cookie_file)
	history = {'all': []}
	for page_num in range(MAX_PAGE):
		time.sleep(0.6)
		url = 'https://api.bilibili.com/x/v2/history?pn={pn}&ps={ps}&jsonp=jsonp'.format(pn=page_num, ps=PAGE_PER_NUM)
		result = req_get(headers, url)
		print('page = {} code = {} datalen = {}'.format(page_num, result['code'], len(result['data'])))
		if len(result['data']) == 0:
			break
		history['all'].append(result)

	return history
	
#coo = read_cookies_file("cookies.txt")
#hea = get_header("cookies.txt")

f = open("history.txt", "a+")
his = get_all_bili_history("cookies.txt");
f.write(his)
f.close()
