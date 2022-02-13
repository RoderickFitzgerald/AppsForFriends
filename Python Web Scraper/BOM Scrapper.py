#Scrapes the temprature from the Aussie BOM site.
#I think this doesn't work now but I am literally...
#Yeah it doesn't work due to website changes. But it used too. :)

import requests
from bs4 import BeautifulSoup

URL = 'http://www.bom.gov.au/products/IDN60903/IDN60903.94926.shtml'
page = requests.get(URL)

soup = BeautifulSoup(page.content, 'html.parser')
result = soup.find_all('tr', class_='rowleftcolumn')


for result in result:
    MainBody = result.find(headers='t1-tmp')
    if MainBody is None:
    	MainBody = []
    if None in (MainBody):
        continue
    if len(MainBody) > 0:
    	print(MainBody.text.strip())
    	print()
