import os
import sys
import time

import requests
from bs4 import BeautifulSoup


def process_submission(contest_id, problem_id, verdict, submission_id):
    time.sleep(2)
    url = f"https://codeforces.com/contest/{contest_id}/submission/{submission_id}"

    submission_data = requests.get(url)
    assert submission_data.status_code == 200
    submission_data = submission_data.content
    soup = BeautifulSoup(submission_data, features="html.parser")

    source = soup.select("#program-source-text")
    assert source is not None, 'SOURCE is NONE'
    if len(source) == 0:
        print('SOURCE has length 0', contest_id, problem_id, submission_id, file=sys.stderr)
        return

    source = source[0]
    attrs = source.attrs

    language = None
    for a in attrs['class']:
        if a[:5] == 'lang-':
            language = a[5:]
            break

    assert language is not None, 'LANGUAGE is NONE'

    os.makedirs(f"submissions/{contest_id}/{problem_id}", exist_ok=True)

    with open(f"submissions/{contest_id}/{problem_id}/{verdict}-{submission_id}.{language}", "w") as file:
        file.write(str(source.contents[0]))
