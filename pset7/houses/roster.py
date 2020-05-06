# The program prints a list of students in a given house
# in alphabetical order
#   *Accept the house name as command-line, otherwise exit
#   * Query the students table in the SQL database
# Print out students fullname, birth and year formatted as:
#   Harry James Potter, born 1980
# Each student in one line
# Ordered by last name


# Loadind libraries
import csv
from sys import argv
from cs50 import SQL

# Getting database
db = SQL("sqlite:///students.db")

# Checking for input error
if not len(argv) == 2:
    print("Incorrect number of in line arguments")
    exit()

house = argv[1]

# Execute query to get list os students

students = db.execute(
    "SELECT first, middle, last, birth FROM students WHERE house = ? ORDER by last ASC, first ASC;", house)

for student in students:
    if student['middle'] != None:
        print(student['first'], student['middle'],
              student['last'] + f", born {student['birth']}")
    else:
        print(student['first'], student['last'] + f", born {student['birth']}")
