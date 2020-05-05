from cs50 import get_string

text = get_string("Text: ").lower()
# Initializing counters
nwords = len(text.split())
nletter = 0
nsent = 0
# Counting alphanumeric char
for c in text:
    if c.isalpha():
        nletter += 1
# Counting sentenses by stopsigns
for c in text:
    if c == "." or c == "?" or c == "!":
        nsent += 1
# Computing index
index = 0.0588 * 100 * nletter / nwords - 0.296 * 100 * nsent / nwords - 15.8
# Printing index results
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {int(round(index))}")