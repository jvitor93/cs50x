# This progrm should import houses data from a CSV file
#   * Print error if the incorrect number of command-line arguments is inputed
#   * Assume the CSV file to contain the collumns 'name', 'house' and 'birth'
# For each student in the file, update a SQL database in a file called students.db
#   *Separate name in  the database into 'first', 'middle' and 'last'
#   *For students without middle name, leave this field as NULL in the database

# Loadind libraries
from cs50 import SQL
import csv
from sys import argv, exit


# Checking for input error
if not len(argv) == 2:
    print("Incorrect number of in line arguments")
    exit()
# Initializing database file
db = SQL("sqlite:///students.db")
# Getting data
with open(argv[1], "r") as datafile:
    table = csv.DictReader(datafile)

    #iterating through students
    for student in table:
        #getting birth and house data
        birth = int(student["birth"])
        house = student['house']
        #getting fullname list
        fullname = student['name'].split()
        #separating fullname into first, middle, last
        if len(fullname) == 3:
            first = fullname[0]
            middle = fullname[1]
            last = fullname[2]
        else:
            first = fullname[0]
            middle = None
            last = fullname[1]
        #inserting line into the SQL database
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)",
                   first, middle, last, house, birth)
