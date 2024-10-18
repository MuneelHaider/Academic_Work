import requests
from bs4 import BeautifulSoup

# Muneel Haider
# 21i-0640
# Assignment 1

url = 'https://www.olx.com.pk/items/q-honda-city'

response = requests.get(url)

if response.status_code == 200:

    soup = BeautifulSoup(response.text, 'html.parser')
    
    ads = soup.find_all('div', class_='fc10b949 _5fdf4379')
    
    prices = soup.find_all('div', class_='_1075545d _52497c97 _96d4439a')
    
    for ad, price in zip(ads, prices):

        ad_name = ad.find('h2').text if ad.find('h2') else 'No Title'
        price_text = price.find('span').text if price.find('span') else 'No Price'
        print(f'Ad Name: {ad_name}, Price: {price_text}')
        print()
else:
    print('Failed to retrieve the webpage')