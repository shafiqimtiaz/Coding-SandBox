#build a web scaper to get the data from the website
#https://www.rottentomatoes.com/top/bestofrt/top_100_action__adventure_movies/
#and save the data in a csv file

import requests
from bs4 import BeautifulSoup
import csv

#url of the website
url = "https://www.rottentomatoes.com/top/bestofrt/top_100_action__adventure_movies/"

#request the url
page = requests.get(url)

#parse the html
soup = BeautifulSoup(page.content, 'html.parser')

#find the table
table = soup.find('table', class_='table')

#find all the rows
rows = table.find_all('tr')

#open a csv file to write the data
with open('movies.csv', 'w') as csv_file:
    csv_writer = csv.writer(csv_file)
    csv_writer.writerow(['Rank', 'Movie', 'Year', 'Score'])

    #loop through the rows
    for row in rows:
        #find all the columns
        cols = row.find_all('td')
        #loop through the columns
        for col in cols:
            #find the rank
            rank = col.find('span', class_='bold').text
            #find the movie name
            movie = col.find('a', class_='unstyled articleLink').text
            #find the year
            year = col.find('span', class_='secondaryInfo').text
            #find the score
            score = col.find('span', class_='tMeterScore').text
            #write the data in the csv file
            csv_writer.writerow([rank, movie, year, score])

#close the csv file
csv_file.close()

#output
#Rank,Movie,Year,Score
#1,The Shawshank Redemption,1994,100%
#2,The Godfather,1972,100%
#3,The Godfather: Part II,1974,100%
#4,The Dark Knight,2008,100%
#5,12 Angry

#Path: test.py