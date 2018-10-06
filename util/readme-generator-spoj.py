"""
    > Author: TISparta
    > Description: Script to generate readme files for this repo
"""

import os

# Extensions to include
extensions = ['cpp', 'py']
# Files to ignore
ignore = ['readme-generator-spoj.py']

# Mapping problem with urls
urls = {
    'exceeding the speed limit': 'exceeding-speed-limit',
    'interesting trip': 'marmelade-kingdom'
}

SECTION_NAME = "SPOJ"
LINK_SECTION = "https://www.spoj.com/"
ROOT = "https://github.com/TISparta/online-judge-solutions/blob/master/SPOJ/"

HEADERS = ['Problem', 'Difficulty', 'Tags', 'Solution']

fileNames = [file for file in os.listdir('.') if
                os.path.isfile(os.path.join('.', file)) and 
                any(file.endswith(ext) for ext in extensions)]

def parseDate (str):
    str = str[str.find(':') + 1:].strip()
    return str

def parseTags (str):
    str = str[str.find(':') + 1:].strip().split(',')
    str = [tag.strip() for tag in str]
    return ', '.join(tag for tag in str)

def parseDifficulty (str):
    str = str[str.find(':') + 1:].strip().split('/')
    dif = int(str[0].strip())
    return ':red_circle:' * dif + ':black_circle:' * (10 - dif)

def parseName (str):
    str = str[:str.find('.')]
    str = str.replace('-', ' ')
    name = str.replace('_', ' ')
    link = LINK_SECTION + '/problems/' + (urls[name.lower()].upper() if
            name.lower() in urls else '-'.join(w.upper() for w in name.split()))
    return "[%s](%s)" %(name, link)

def parseSolution (str):
    return '[:link:](' + ROOT + str +')'

table = []
table.append(HEADERS)
table.append(['-' * 7 for _ in range(len(HEADERS))])

for file_name in fileNames:
    if file_name in ignore:
        continue
    with open(file_name) as file:
        foo = file.readline()
        author = file.readline()
        date = parseDate(file.readline())
        tags = parseTags(file.readline())
        difficulty = parseDifficulty(file.readline())
        solution = parseSolution(file_name)
        row = [parseName(file_name), difficulty, tags, solution]
        table.append(row)

table[2:] = sorted(table[2:], key = lambda row: row[1])

with open('README.md', 'w') as readme:
    readme.write('# [%s](%s)\n' %(SECTION_NAME, LINK_SECTION))
    readme.write('\n')
    readme.write('\n'.join(' | '.join(c for c in r) for r in table))
