import time

from selenium import webdriver


url = "https://canvas.sydney.edu.au/courses/30588/quizzes/142845/take"

driver = webdriver.Chrome("/Users/yu/Downloads/chromedriver")
driver.get(url)
time.sleep(20)
driver.find_element_by_xpath("/html/body/div/p[1]/a/font").click()

time.sleep(10)