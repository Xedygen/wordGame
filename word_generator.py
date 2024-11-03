import random
import requests
from bs4 import BeautifulSoup

url = "https://www.ef.com/wwen/english-resources/english-vocabulary/top-3000-words/"

page = requests.get(url)

soup = BeautifulSoup(page.text, "html.parser")

paragraph = soup.select("div.field-item p")

text = [item.get_text(separator="\n", strip=True).lower() for item in paragraph]
text = text[0].split("\n")


item_dict = dict()
for item in text:
    if item[0] not in item_dict:
        item_dict[item[0]] = [item]

    else:
        item_list = item_dict.get(item[0])
        item_dict[item[0]].append(item)
with open('data.txt', 'w') as file:
    for key, value in item_dict.items():
        if len(value) <= 10:
            for data in value:
                data = data + "\n"
                file.write(data)

        else:
            randint = random.sample(range(1, len(value)), 10)
            for i in randint:
                data = value[i] + "\n"
                file.write(data)
