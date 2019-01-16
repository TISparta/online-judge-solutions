"""
    > Author: TISparta
    > Description: Script to generate readme files for this repo
"""

# You should modify some parts of the code when adding gym problems

import os
import requests
from pprint import pprint
contests_id = __import__('codeforces-contest-id').contestId

# Extensions to include
extensions = ['cpp', 'py']
# Files to ignore
ignore = ['__pycache__', 'README.md']

# README config
SECTION_NAME = "Codeforces"
LINK_SECTION = "https://codeforces.com/"
ROOT = "https://github.com/TISparta/online-judge-solutions/blob/master/Codeforces/"
HEADERS = ['Problem', 'Difficulty', 'Tags', 'Solution']

# util functions


def parseDate(str):
    str = str[str.find(':') + 1:].strip()
    return str


def parseTags(str):
    str = str[str.find(':') + 1:].strip().split(',')
    str = [tag.strip() for tag in str]
    return ', '.join(tag for tag in str)


def parseDifficulty(str):
    str = str[str.find(':') + 1:].strip().split('/')
    dif = int(str[0].strip())
    return ':red_circle:' * dif + ':black_circle:' * (10 - dif)


def parseName(str):
    str = str[:str.find('.')]
    str = str.replace('-', ' ')
    name = str.replace('_', ' ')
    return name


def getSolutionLink(contest_name, problem_letter):
    return '[:link:](' + ROOT + contest_name + '/' + problem_letter + ')'


def getProblemNames(problem_name, contest_id):
    result = requests.get(
        'https://codeforces.com/api/contest.standings?contestId=' + contest_id)
    problem_name[contest_id] = dict()
    for problem in result.json()['result']['problems']:
        problem_name[contest_id][problem['index']] = problem['name']


def getProblemLink(contest_id, problem_letter, problem_name):
    problem_link = LINK_SECTION + 'contest/' + \
        contest_id + '/problem/' + problem_letter
    return '[%s](%s)' % (problem_name, problem_link)


table = []
table.append(HEADERS)
table.append(['-' * 7 for _ in range(len(HEADERS))])

problem_names = dict()
row_weight = dict()

# Getting files
for contest_name in os.listdir('.'):
    path = os.path.join('.', contest_name)
    if os.path.isdir(path) and contest_name not in ignore:
        for file_name in os.listdir(path):
            if any(file_name.endswith(ext) for ext in extensions):
                if file_name in ignore:
                    continue
                contest_id = contests_id[contest_name]
                if contest_id not in problem_names:
                    # I'll do it in parallel in the future
                    getProblemNames(problem_names, contest_id)
                contest_id = contests_id[contest_name]
                with open(os.path.join(path, file_name)) as file:
                    foo = file.readline()
                    author = file.readline()
                    date = parseDate(file.readline())
                    tags = parseTags(file.readline())
                    difficulty = parseDifficulty(file.readline())
                    solution_link = getSolutionLink(contest_name, file_name)
                    problem_letter = parseName(file_name)
                    name = problem_letter + ' - ' + \
                        problem_names[contest_id][problem_letter]
                    row = [getProblemLink(
                        contest_id, problem_letter, name), difficulty, tags, solution_link]
                    row_weight[solution_link] = (int(contest_id), problem_letter)
                    table.append(row)

table[2:] = sorted(table[2:], key=lambda row: (
    row_weight[row[-1]][0], row_weight[row[-1]][1]))

with open('README.md', 'w') as readme:
    readme.write('# [%s](%s)\n' % (SECTION_NAME, LINK_SECTION))
    readme.write('\n')
    readme.write('\n'.join(' | '.join(c for c in r) for r in table))
