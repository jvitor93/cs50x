# Getting necessary libraries
from sys import argv
import csv


def main():
    # If argument format is incorrect, prompt error message
    if not len(argv) == 3:
        print("Incorrect number of command-line arguments")

    # Getting files location from argv
    data_loc = argv[1]
    seq_loc = argv[2]

    # Getting STRs from database file
    fhead = open(data_loc, "r")
    header = fhead.readline().replace("\n", "").split(",")
    strs = header[1:len(header)]
    fhead.close()

    # Getting sequence string
    f = open(seq_loc, 'r')
    sequence_string = f.read().replace("\n", "")
    f.close()

    # load database into a dictionary
    database_dict = load_database(data_loc, strs)

    # Counting STRs into a list
    strs_count = []
    for ST in strs:
        strs_count.append(count_strs(sequence_string, ST))
    # Seaching list of string counts in the loaded database dictionary
    name = database_dict.get(tuple(strs_count), 'No match')
    print(name)

# Function definitions

# Function for loading database into a dictionary


def load_database(data_loc, strs):
    # Getting a dictionary structure into memory
    with open(data_loc) as csvfile:
        datareader = csv.DictReader(csvfile)
        # Iterating throught struct to form a dictionary
        data_dict = {}
        for line in datareader:
            key = []
            for st in strs:
                key.append(int(line[st]))
            data_dict[tuple(key)] = line["name"]
    return data_dict

# Function for counting strs


def count_strs(sequence, STR):

    max_occr = 0
    # Looping though sequence
    i = 0
    while i < len(sequence) - len(STR) + 1:
        count = 0
        # Check if strant is equal to STR
        while sequence[i:(i+len(STR))] == STR:
            count += 1
            i += len(STR)
            if i + len(STR) + 1 >= len(sequence):
                break
        if count > max_occr:
            max_occr = count
        i += 1
    return int(max_occr)


# Main definition
if __name__ == "__main__":
    main()