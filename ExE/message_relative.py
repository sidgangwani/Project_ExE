from selenium import webdriver
import time

from selenium.webdriver.common.keys import Keys

driver=webdriver.Chrome("C:\\chrome_driver\\chromedriver.exe")  #Enter Location of Chrome Driver
driver.maximize_window()
driver.implicitly_wait(38)
driver.set_page_load_timeout(50)


driver.get("https://whatmylocation.com/")   #URL for getting location
time.sleep(5)
Lat=driver.find_element_by_xpath('//*[@id="latitude"]').text    #Getting Latitude of your Location
Lon=driver.find_element_by_xpath('//*[@id="longitude"]').text   #Getting Longitude of your Location
time.sleep(3)

driver.get("https://messenger.com")  #URL for messenger

#Login Details
loginBox = driver.find_element_by_xpath('//*[@id="email"]')
loginBox.send_keys("emailid.com") #Enter your Email ID
passWordBox = driver.find_element_by_xpath('//*[@id="pass"]')
passWordBox.send_keys("password") #Enter Password for that Email ID

passWordBox.send_keys(Keys.RETURN)

driver.get("https://www.messenger.com/t/100012951366283")   #Copy messenger conversation number URL

mssgBox=driver.find_element_by_xpath('//*[@id="mount_0_0"]/div/div[1]/div/div[2]/div/div/div[1]/div[1]/div[2]/div/div/div/div/div/div[1]/div[2]/div/div/div/div[2]/div/form/div/div[3]/div[2]/div[1]/div/div/div/div/div[2]/div/div/div/div/span/br')
mssgBox.send_keys("I am having a minor seizure. Here is my Location- Latitude: "+Lat+", Longitude: "+Lon)

driver.find_element_by_xpath('//*[@id="mount_0_0"]/div/div[1]/div/div[2]/div/div/div[1]/div[1]/div[2]/div/div/div/div/div/div[1]/div[2]/div/div/div/div[2]/div/form/div/div[3]/span[2]/div').click()
time.sleep(2)

call=driver.find_element_by_xpath('//*[@id="mount_0_0"]/div/div[1]/div/div[2]/div/div/div[1]/div[1]/div[2]/div/div/div/div/div/div[1]/div[1]/div/div[2]/div/div[1]/span/div/div')
call.click()

time.sleep(40)
driver.quit()