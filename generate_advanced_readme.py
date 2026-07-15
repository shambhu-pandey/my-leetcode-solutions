import os
import re
import requests
from google import genai

# =========================
# CONFIG
# =========================

BASE_DIR = "problems/problems"

client = genai.Client(
    api_key=os.getenv("GEMINI_API_KEY")
)

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

# =========================
# AI NOTES
# =========================

def generate_ai_notes(title, code):

    prompt = f"""
You are an expert DSA teacher.

Analyze this LeetCode solution.

Problem:
{title}

Code:
{code}

Return markdown only.

## Intuition

## Pattern

## Key Trick

## Approach

## Complexity

Time: O(...)

Space: O(...)

## Interview Tip

## Common Mistake

## Alternative Approach
"""

    response = client.models.generate_content(
        model="gemini-3.5-flash",
        contents=prompt
    )

    return response.text


# =========================
# MAIN LOOP
# =========================

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

        tags = ", ".join(
            [x["name"] for x in data["topicTags"]]
        )

        content = data["content"]

        clean_content = re.sub(
            r"<.*?>",
            "",
            content
        )

        clean_content = clean_content[:3000]

        # =====================
        # READ SOLUTION
        # =====================

        solution_file = os.path.join(
            path,
            "solution.cpp"
        )

        code = ""

        if os.path.exists(solution_file):

            with open(
                solution_file,
                "r",
                encoding="utf-8"
            ) as f:

                code = f.read()

        # =====================
        # AI GENERATION
        # =====================

        ai_notes = ""

        if code.strip():

            print(f"Generating AI notes for {title}...")

            ai_notes = generate_ai_notes(
                title,
                code
            )

        # =====================
        # README
        # =====================

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

{ai_notes}
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