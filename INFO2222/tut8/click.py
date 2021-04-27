import time

from selenium import webdriver

url = "https://yuliuu.com/Articles"

driver = webdriver.Chrome("/Users/yu/Downloads/chromedriver")
driver.get(url)

driver.find_element_by_xpath("/html/body/div/p[1]/a/font").click()

time.sleep(10)