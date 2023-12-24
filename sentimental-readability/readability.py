# TODO

from cs50 import get_string


def count_letters(text):
    return sum(c.isalpha() for c in text)


def count_words(text):
    return len(text.split())


def count_sentences(text):
    sentence_endings = [".", "!", "?"]
    return sum(text.count(end) for end in sentence_endings)


def coleman_liau_index(letters, words, sentences):
    L = (letters / words) * 100
    S = (sentences / words) * 100
    return 0.0588 * L - 0.296 * S - 15.8


def get_grade_level(index):
    rounded_index = round(index)
    if rounded_index >= 16:
        return "Grade 16+"
    elif rounded_index < 1:
        return "Before Grade 1"
    else:
        return f"Grade {rounded_index}"


if __name__ == "__main__":
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    index = coleman_liau_index(letters, words, sentences)
    grade_level = get_grade_level(index)

    print(grade_level)
