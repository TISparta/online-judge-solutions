import sys
import os
import requests
import numpy as np
import pandas as pd
from pprint import pprint
contests_id = __import__('codeforces-contest-id').contestId

# Extensions to include
extensions = ['cpp', 'py']
# Files to ignore
ignore = ['__pycache__', 'README.md', 'util']

# README config
OJ_NAME = 'Codeforces'
OJ_LINK = 'https://codeforces.com'
HEADERS = ['Problem', 'Difficulty', 'Rating', 'Tags', 'Solution']
API = 'https://codeforces.com/api/contest.standings?contestId='
DF_COLUMNS = ['contest_id', 'problem_name', 'rating', 'tags', 'difficulty', 'solution_link']
DF_NAME = 'problems.csv'

# Data of problems
df = pd.read_csv(DF_NAME) if os.path.exists(DF_NAME) else pd.DataFrame(columns=DF_COLUMNS)

def parse (line):
    return ', '.join(s.strip() for s in line[line.rfind('/') + 1:].split(','))

def retrieve_data (path, contest_name):
    global df
    contest_id = contests_id[contest_name]
    if df['contest_id'].astype('str').str.contains(contest_id).any():
        return

    data = dict()
    for problem in os.listdir(path):
        with open(os.path.join(path, problem)) as problem_file:
            index = problem[:problem.find('.')]
            tags = parse(problem_file.readline())
            difficulty = parse(problem_file.readline())
            solution_link = contest_name + '/' + problem
            data[index] = (tags, difficulty, solution_link)
    
    print('Getting data from ' + contest_name + ' ' + contest_id)
    result = requests.get(API + contest_id)
    for row in result.json()['result']['problems']:
        df = df.append({
            'contest_id': row['contestId'],
            'problem_name': row['index'] + ' - ' + row['name'],
            'problem_link': 'https://codeforces.com/contest/' + contest_id + '/problem/' + row['index'],
            'rating': row['rating'],
            'tags': data[row['index']][0],
            'difficulty': data[row['index']][1],
            'solution_link': data[row['index']][2]
        }, ignore_index=True)

for contest_name in os.listdir('..'):
    path = os.path.join('..', contest_name)
    if os.path.isdir(path) and contest_name not in ignore:
        retrieve_data(path, contest_name)

df.to_csv(DF_NAME)

with open('../README.md', 'w') as readme:
    readme.write('# [%s](%s)\n\n' % (OJ_NAME, OJ_LINK))
    readme.write(' | '.join(header for header in HEADERS) + '\n')
    readme.write(' | '.join('-' * 7 for _ in HEADERS) + '\n')
    for index, row in df.iterrows():
        problem = '[%s](%s)' %(row['problem_name'], row['problem_link'])
        dif = int(row['difficulty'])
        difficulty = ':red_circle:' * dif + ':black_circle:' * (10 - dif)
        rating = row['rating']
        tags = row['tags']
        solution = '[:link:](./%s)' %(row['solution_link'])
        line = ' | '.join(str(item) for item in [problem, difficulty, rating, tags, solution])
        readme.write(line + '\n')
