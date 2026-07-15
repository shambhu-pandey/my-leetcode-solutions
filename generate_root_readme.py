import os
import re
from collections import defaultdict

BASE_DIR = "problems/problems"

topics = defaultdict(list)
total = 0

for folder in os.listdir(BASE_DIR):

    path = os.path.join(BASE_DIR, folder)

    if not os.path.isdir(path):
        continue

    readme_path = os.path.join(path, "README.md")

    if not os.path.exists(readme_path):
        continue

    total += 1

    with open(readme_path, "r", encoding="utf-8") as f:
        content = f.read()

    title_match = re.search(r"# (.+)", content)
    title = title_match.group(1) if title_match else folder

    tags_match = re.search(
        r"## Tags\s+([\s\S]*?)\n\n",
        content
    )

    if tags_match:
        tags = [
            x.strip()
            for x in tags_match.group(1).split(",")
        ]

        for tag in tags:
            topics[tag].append(title)

readme = f"""# 🚀 LeetCode Solutions

## 📊 Statistics

- Total Solved: {total}

---

## 📚 Topics Covered

"""

for topic in sorted(topics):

    readme += f"\n### {topic} ({len(topics[topic])})\n\n"

    for problem in sorted(topics[topic]):
        readme += f"- {problem}\n"

readme += """

---

## 📂 Repository Structure

Each problem folder contains:

- solution.cpp
- README.md
- Problem Description
- Examples
- Constraints
- Difficulty

---

⭐ Auto-generated from LeetCode submissions.
"""

with open("README.md", "w", encoding="utf-8") as f:
    f.write(readme)

print("README.md generated successfully!")