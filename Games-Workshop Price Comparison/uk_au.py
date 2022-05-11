import requests
import os
import pandas as pd
from bs4 import BeautifulSoup


UK_URL = 'https://www.games-workshop.com/en-GB/Warhammer-40-000?N=1125463923+4197960941&Nr=AND(sku.siteId%3AGB_gw%2Cproduct.locale%3Aen_GB_gw)&Nrs=collection()%2Frecord[product.startDate+%3C%3D+1651676040000+and+product.endDate+%3E%3D+1651676040000]&view=all'
page = requests.get(UK_URL)

soup = BeautifulSoup(page.content, 'html.parser')
UK_Soup_Cooked = soup.prettify()

#result = soup.find_all('tr', class_='attributes')
#print(soup.prettify())
#for result in result:
#    MainBody = result.find(headers='t1-tmp')
#    if MainBody is None:
#    	MainBody = []
#    if None in (MainBody):
#        continue
#    if len(MainBody) > 0:
#    	print(MainBody.text.strip())

def SliceTheHTMLFile():
    #1 Pound Stirling Gets 1.75 Australian Dollars
    ExchangeRate = 1.75
    UK_GW = open("UK_GW.txt", "r")
    UK_Names = []
    UK_Prices = []
    UK_Names_Prices = []
    for Lines in UK_GW:
        if '"product.title": [' in Lines:
            UK_Names.append(Lines[35:-4])
            print(Lines[35:-4])
        if '"sku.price"' in Lines:
            UK_Prices.append(Lines[33:-4])
            print(Lines[33:-4])

    AU_GW = open("AU_GW.txt", "r")
    AU_Names = []
    AU_Prices = []
    AU_Names_Prices = []
    for Lines in AU_GW:
        if '"product.title": [' in Lines:
            AU_Names.append(Lines[35:-4])
            print(Lines[35:-4])
        if '"sku.price"' in Lines:
            AU_Prices.append(Lines[32:-4])
            print(Lines[33:-4])
    
    #lengthbalancing
    while len(UK_Names) > len(AU_Names):
        AU_Names.append("Non-Comparable")
        AU_Prices.append(1)
    
    while len(UK_Names) < len(AU_Names):
        UK_Names.append("Non-Comparable")
        UK_Prices.append(1)

    BetterOrWorse = []
    PriceFromGBPtoAUD = []

    for value in UK_Prices:
        count = 0
        amount = float(value) * ExchangeRate
        if amount > float(AU_Prices[1]):
            BetterOrWorse.append("Cheaper in AUD")
        else:
            BetterOrWorse.append("Worse in AUD")
        PriceFromGBPtoAUD.append(amount)
    
        count = count + 1

    UK_Comparison = []
    AU_Comparison = []

    count = 0
    while count < len(UK_Names):
        appender = str(UK_Names[count]) + str(UK_Prices[count])
        UK_Comparison.append
        count = count + 1

    count = 0
    while count < len(UK_Names):
        appender = str(AU_Names[count]) + str(AU_Prices[count])
        AU_Comparison.append(appender)
        count = count + 1

    data = {
        "UK Model Names: ": UK_Names,
        "UK Prices: ": UK_Prices,
        "AU Model Names: ": AU_Names,
        "AU Prices: ": AU_Prices,
        "Better or Worse Value: ": BetterOrWorse,
        "GBP to AUD converted: ": PriceFromGBPtoAUD
    }

    df = pd.DataFrame(data)
    df.to_csv("ComparedInformation.csv")
    print(df)
    
    
    
    
    
    #print(fileToSlice.read())


SliceTheHTMLFile()
