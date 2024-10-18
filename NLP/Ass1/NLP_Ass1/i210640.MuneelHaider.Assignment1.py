import pandas as pd
import nltk
from nltk.tokenize import word_tokenize
from collections import defaultdict, Counter
import string
import random

nltk.download('punkt')

# Muneel Haider
# 21i-0640
# Assignment 1 - NLP


# Reading CSV File
def readCSV(file):
    print("Loading csv file.")
    return pd.read_csv(file)

# Cleaning and Tokenizing data read from CSV File
def cleanAndTokenize(textRead):
    textRead = textRead.lower()
    textRead = textRead.translate(str.maketrans('', '', string.punctuation)) 
    
    tokens = word_tokenize(textRead)
    
    return tokens

# This function builds an N-gram model, depending on its parameters.
# If 1 is sent as n, then a Unigram.
# If 2 is sent as n, then a Bigram.
# If 3 is sent as n, then a trigram.
def buildNGramModel(tokensList, n=1):

    print(f"Building {n}-gram model...")
    model = defaultdict(Counter)
    
    for tokens in tokensList:
    
        for i in range(len(tokens) - (n - 1)):
    
            modelDictionary = tuple(tokens[i:i + n - 1])
            model[modelDictionary][tokens[i + n - 1]] += 1
    
    return model

# This function predicts the next word the model will create.
# Same as previous versions, the number of words it predicts will depend on what N gram model it is.
def predictNextWord(model, modelDictionary):
    modelDictionary = tuple(modelDictionary)

    if modelDictionary in model:

        return max(model[modelDictionary], key=model[modelDictionary].get)
    else:

        return None

# This function finds the most frequently used word from the CSV File for the Unigram.
def predictFrequentWord(model):
    return max(model[()], key=model[()].get)

# Depending on its parameters, the following function will create sentences. The model itself is sent as a parameter, and respective sentences are created.
def generateSentence(model, modelDictionary, countWords=10):
    sentence = list(modelDictionary)

    for _ in range(countWords - len(modelDictionary)):
    
        nextWord = predictNextWord(model, modelDictionary)
    
        # The code breaks as soon as it detects that it is not supposed to generate more words for the sentence.
        if not nextWord:
            break
    
        sentence.append(nextWord)
        modelDictionary = tuple(sentence[-len(modelDictionary):])
    
    return ' '.join(sentence)

# Based on tokenization, the reviews from the CSV Files are classified using this function.
# They are classified into either Positive or Negative.
def reviewClassifier(reviewTokens, model):

    print("Classifying review...")
    
    positiveScore = sum(model[()][token] for token in reviewTokens if token in model[()])
    negativeScore = sum(-model[()][token] for token in reviewTokens if token not in model[()])
    
    return "Positive" if positiveScore > negativeScore else "Negative"



# This is my main
# Cleaning data and tokenizing
file = 'IMDB Dataset.csv'
data = readCSV(file)
data['tokens'] = data['review'].apply(cleanAndTokenize)

# Functions made previously to build models are called here.
Unigram = buildNGramModel(data['tokens'], 1)
Bigram = buildNGramModel(data['tokens'], 2)
Trigram = buildNGramModel(data['tokens'], 3)

# The models are then used to generate sentences.
unigramSentence = generateSentence(Unigram, (predictFrequentWord(Unigram),), 10)
bigramSentence = generateSentence(Bigram, (unigramSentence.split()[0],), 10)
trigramSentence = generateSentence(Trigram, tuple(bigramSentence.split()[:2]), 10)

# Output of the generated sentences in console.
print("Generated Unigram Sentence:", unigramSentence)
print()
print("Generated Bigram Sentence:", bigramSentence)
print()
print("Generated Trigram Sentence:", trigramSentence)
print()

# The reviews generated are then classified into either Positive or Negative.
print("Unigram Sentence Classification:", reviewClassifier(unigramSentence.split(), Unigram))
print()
print("Bigram Sentence Classification:", reviewClassifier(bigramSentence.split(), Unigram))
print()
print("Trigram Sentence Classification:", reviewClassifier(trigramSentence.split(), Unigram))
print()