from google import genai
import os

client = genai.Client(
    api_key=os.getenv("GEMINI_API_KEY")
)

response = client.models.generate_content(
    model="gemini-3.5-flash",
    contents="Explain Two Sum intuition in 3 lines"
)

print(response.text)