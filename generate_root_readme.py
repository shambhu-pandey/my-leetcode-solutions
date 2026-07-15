import os
import re
from collections import defaultdict

BASE_DIR = "problems/problems"

topics = defaultdict(list)

difficulty_count = {
    "Easy": 0,
    "Medium": 0,
    "Hard": 0
}

total = 0

# =========================
# Read all problem folders
# =========================

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

    # Problem Title
    title_match = re.search(r"# (.+)", content)
    title = title_match.group(1).strip() if title_match else folder

    # Difficulty
    diff_match = re.search(
        r"## Difficulty\s+([A-Za-z]+)",
        content
    )

    difficulty = "Unknown"

    if diff_match:
        difficulty = diff_match.group(1)

        if difficulty in difficulty_count:
            difficulty_count[difficulty] += 1

    # Tags
    tags_match = re.search(
        r"## Tags\s+([\s\S]*?)\n\n",
        content
    )

    tags = []

    if tags_match:
        tags = [
            x.strip()
            for x in tags_match.group(1).split(",")
            if x.strip()
        ]

    for tag in tags:
        topics[tag].append(
            {
                "title": title,
                "difficulty": difficulty,
                "folder": folder
            }
        )

# =========================
# Generate Root README
# =========================

readme = f"""# 🚀 LeetCode Solutions

![Problems](https://img.shields.io/badge/Problems-{total}-brightgreen)
![Easy](https://img.shields.io/badge/Easy-{difficulty_count["Easy"]}-success)
![Medium](https://img.shields.io/badge/Medium-{difficulty_count["Medium"]}-orange)
![Hard](https://img.shields.io/badge/Hard-{difficulty_count["Hard"]}-red)

## 📊 Statistics

| Metric | Count |
|---------|---------|
| Total Solved | {total} |
| Easy | {difficulty_count["Easy"]} |
| Medium | {difficulty_count["Medium"]} |
| Hard | {difficulty_count["Hard"]} |

---

## 📚 Topics Covered

"""

for topic in sorted(topics):

    readme += f"\n## {topic} ({len(topics[topic])})\n\n"

    readme += "| Problem | Difficulty | Solution |\n"
    readme += "|----------|------------|----------|\n"

    for p in sorted(topics[topic], key=lambda x: x["title"]):

        readme += (
            f"| "
            f"[{p['title']}](problems/problems/{p['folder']}/README.md) "
            f"| {p['difficulty']} "
            f"| [Code](problems/problems/{p['folder']}/solution.cpp) |\n"
        )

    readme += "\n"

readme += r"""
---

## 📂 Repository Structure

Each problem folder contains:

- solution.cpp
- README.md
- Problem Description
- Examples
- Constraints
- Difficulty
- Tags

### Example

add_two_numbers/
├── solution.cpp
└── README.md

---

## 🛠 Language

- C++

---

⭐ Auto-generated from LeetCode submissions.
"""

# =========================
# Save README
# =========================

with open("README.md", "w", encoding="utf-8") as f:
    f.write(readme)

print("README.md generated successfully!")