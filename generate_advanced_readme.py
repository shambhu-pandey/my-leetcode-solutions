import os
import requests
import re

BASE_DIR = "problems/problems"

QUERY = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    title
    difficulty
    content
    topicTags {
      name
    }
  }
}
"""

for folder in os.listdir(BASE_DIR):

    path = os.path.join(BASE_DIR, folder)

    if not os.path.isdir(path):
        continue

    slug = folder.replace("_", "-")

    try:

        response = requests.post(
            "https://leetcode.com/graphql",
            json={
                "query": QUERY,
                "variables": {
                    "titleSlug": slug
                }
            }
        )

        data = response.json()["data"]["question"]

        if not data:
            print(f"Skipping {slug}")
            continue

        title = data["title"]
        difficulty = data["difficulty"]
        tags = ", ".join([x["name"] for x in data["topicTags"]])

        content = data["content"]

        # remove html tags
        clean_content = re.sub(r"<.*?>", "", content)
        clean_content = clean_content[:3000]

        readme = f"""# {title}

🔗 Link:
https://leetcode.com/problems/{slug}/

## Difficulty

{difficulty}

## Tags

{tags}

## Problem Description

{clean_content}

## Solution

See `solution.cpp`
"""

        with open(
            os.path.join(path, "README.md"),
            "w",
            encoding="utf-8"
        ) as f:
            f.write(readme)

        print(f"Generated README for {title}")

    except Exception as e:
        print(f"Error: {slug}")
        print(e)

print("\\nDone!")