#!/usr/bin/python3
""" Interview algorithm """
import requests

rUrl = 'https://api.reddit.com/r/'
hotUrl = '{}/hot.json?after={}'


def recurse(subreddit, hot_list=[], after=None):
    """ Get list reddit """
    if after is not None:
        url = rUrl + hotUrl.format(subreddit, after)
    else:
        url = rUrl + '{}/hot.json'.format(subreddit)
    header = {'user-agent': 'mr. big'}

    res = requests.get(url, headers=header, allow_redirects=False)
    if res.status_code != 200:
        return None
    try:
        resJson = res.json()
    except Exception:
        return None

    if resJson.get('message') == 'Not Found':
        return

    elements = resJson.get('data').get('children')
    hot_list += [element.get('data').get('title') for element in elements]
    after = resJson.get('data').get('after')
    if after is not None:
        return recurse(subreddit, hot_list, after)
    else:
        return hot_list


def print_words(word_list, hot_list):
    """ Print words (word: value) """
    dictionary = {}
    for word in word_list:
        c = 0
        for title in hot_list:
            t = title.lower().split()
            if word.lower().strip() in t:
                c += t.count(word.lower().strip())

        if word.lower() in dictionary:
            dictionary[word.lower()] += c
        else:
            dictionary.update({word.lower(): c})

    for k, v in sorted(dictionary.items(), key=lambda x: (-x[1], x[0])):
        if dictionary.get(k) != 0:
            print("{}: {}".format(k, v))


def count_words(subreddit, word_list):
    """ Counts words """
    hot_list = recurse(subreddit)
    if hot_list is None:
        return

    print_words(word_list, hot_list)
