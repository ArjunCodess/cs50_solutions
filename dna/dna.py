import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py <database_file> <sequence_file>")
        sys.exit(1)

    # Read database file into a variable
    database_file = sys.argv[1]
    with open(database_file, newline="") as csvfile:
        database_reader = csv.DictReader(csvfile)
        database = list(database_reader)

    # Read DNA sequence file into a variable
    sequence_file = sys.argv[2]
    with open(sequence_file, "r") as dnafile:
        dna_sequence = dnafile.read()

    # Find longest match of each STR in DNA sequence
    for row in database:
        person = row["name"]
        str_counts = {
            str_name: longest_match(dna_sequence, str_name)
            for str_name in row.keys()
            if str_name != "name"
        }

        # Check if the counts match exactly with any individual in the database
        if all(int(row[str_name]) == str_counts[str_name] for str_name in str_counts):
            print(person)
            return

    # If no match is found in the database
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()
