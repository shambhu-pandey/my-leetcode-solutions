import os
import requests
import re
import html
import time

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

# Check if directory exists
if not os.path.exists(BASE_DIR):
    print(f"Error: Directory '{BASE_DIR}' does not exist.")
    exit(1)

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
            },
            timeout=20
        )

        response.raise_for_status()
        response_data = response.json()

        if (
            "data" not in response_data
            or not response_data["data"]
            or not response_data["data"]["question"]
        ):
            print(f"Skipping {slug}: No data found")
            continue

        data = response_data["data"]["question"]

        title = data["title"]
        difficulty = data["difficulty"]

        tags = ", ".join(
            tag["name"] for tag in data.get("topicTags", [])
        )

        content = data.get("content") or "No description available."

        # Remove HTML tags
        clean_content = re.sub(
            r"<.*?>",
            "",
            content,
            flags=re.DOTALL
        )

        clean_content = html.unescape(clean_content)
        clean_content = clean_content[:3000]

        # Find solution file
        solution_file = None
        language = "cpp"

        for ext in ["cpp", "java", "py"]:
            temp = os.path.join(path, f"solution.{ext}")

            if os.path.exists(temp):
                solution_file = temp

                if ext == "cpp":
                    language = "cpp"
                elif ext == "java":
                    language = "java"
                else:
                    language = "python"

                break

        code = ""
        if solution_file:
            with open(solution_file, "r", encoding="utf-8") as f:
                code = f.read()
        else:
            code = "// No local solution file found."

        # Building the string template
        readme = f"""# 🚀 {title}

🔗 **LeetCode Link:**  
https://leetcode.com/problems/{slug}/

---

## 🎯 Difficulty

**{difficulty}**

---

## 🏷️ Tags

{tags}

---

## 📖 Problem Description

{clean_content}

---

## 💻 My Solution

```{language}
{code}
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on {time.strftime("%Y-%m-%d %H:%M:%S")}*
"""

        # Write README to the problem directory
        readme_path = os.path.join(path, "README.md")
        with open(readme_path, "w", encoding="utf-8") as f:
            f.write(readme)

        print(f"✅ Generated README for {title}")
        
        # Add delay to avoid rate limiting
        time.sleep(1)

    except requests.exceptions.RequestException as e:
        print(f"❌ Network error for {slug}: {e}")
    except Exception as e:
        print(f"❌ Error processing {slug}: {e}")

print("\n✨ Done! All README files have been generated.")