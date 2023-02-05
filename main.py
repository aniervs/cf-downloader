import os
import time
import requests
from tqdm import tqdm

from tools import process_submission

user_handle = input('Write the handle of whom you want to download the submissions: ')

response = requests.get("https://codeforces.com/api/contest.list")
contests = response.json()['result']

os.makedirs("submissions", exist_ok=True)

for idx, contest in tqdm(enumerate(contests)):
    if contest['phase'] != 'FINISHED' or contest['type'] != 'CF':
        continue
    contest_id = contest['id']
    response = requests.get(f"https://codeforces.com/api/contest.status?contestId={contest_id}&handle={user_handle}")
    time.sleep(2)
    assert response.status_code == 200

    submissions = response.json()['result']

    if idx % 10 == 0:
        time.sleep(8)

    for submission in submissions:
        problem_id = submission['problem']['index']
        verdict = submission['verdict']
        submission_id = submission['id']
        process_submission(contest_id=contest_id, problem_id=problem_id, verdict=verdict, submission_id=submission_id)

