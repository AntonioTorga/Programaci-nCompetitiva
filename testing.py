import time
import requests

market_id = 'btc-clp'
url = f'https://www.buda.com/api/v2/markets/{market_id}/trades'
print(time.time())
response = requests.get(url, params={
    'limit': 50,
})
print(response.json())