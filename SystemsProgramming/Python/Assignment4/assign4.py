#!/usr/bin/python3
import os
import sys
import glob
import re

#initializes the struct for .crs files in the data directory
# 0 is deptCode
# 1 is deptName
# 2 is courseName
# 3 is courseStart
# 4 is courseEnd
# 5 is creditHours
# 6 is numStudents
# 7 is courseNum
# 8 is inputDate
def initializeStruct():
    myStruct = []
    i = 0
    while i < 9:
        myStruct.append("")
        i = i+1
    return myStruct

# determines if program was correctly called
def numberOfArguments():
    numArgs = len(sys.argv)
    if numArgs == 5:
        return 1
    if numArgs == 7:
        return 2

# determines if program was correctly called
def checkArgs():
    numArgs = len(sys.argv)

    if numArgs == 5:
        return
    elif numArgs == 7:
        return
    else:
        print("Usage, 4 or 6 arguments as follows: " + sys.argv[0] + " <./dataDirectory> <yourTemplate.template> <date> <./outputDirectory> <'optionalOpeningDelimiter'> <'optionalEndingDelimiter'>")
        exit()
        return

# generates delimiters from arguments
def findDelimiter():
    argValue = numberOfArguments()
    actualDelimiters = ["<<", ">>"]
    if argValue == 1:
        return actualDelimiters
    elif argValue == 2:
        actualDelimiters[0] = sys.argv[5]
        actualDelimiters[1] = sys.argv[6]
        return actualDelimiters

#makes a regex pattern from the specified delimiters
def makeTemplateRegex():
    delimiterList = findDelimiter()
    myReg = re.compile(re.escape(delimiterList[0]) + "[^" + re.escape(delimiterList[1]) + "]*" + re.escape(delimiterList[1]))
    return myReg

#seperates a tempalte line into pieces based on delimiters
def makeLine(lineToSplit):
    myReg = makeTemplateRegex()
    x = myReg.split(lineToSplit)
    y = myReg.findall(lineToSplit)
    x = mergeLines(x,y)
    return x

#collates two lists into a single list
def mergeLines(destination, insertion):
    total = len(insertion)
    i = 0
    destinationIndex = 0    
    while i < total:
        destinationIndex = (i*2) +1
        destination.insert(destinationIndex, insertion.pop(0))
        i += 1
    return destination

#turns a template file into a template list
def makeTemplate():
    # example: assign4.template
    name = sys.argv[2]
    regex = makeTemplateRegex
    infile = open(name,"r")
    lines = infile.readlines()
    tempLine = []
    tempString = ""
    for line in lines:
        tempLine.append(makeLine(line))
    
    return tempLine

#gathers all of the .crs files in a specified directory 
def makeGlob():
    # example: ./data
    dataDirectory = sys.argv[1]
    globbedFiles = os.listdir(dataDirectory)
    return globbedFiles

def operateFiles():
    files = makeGlob()
    template = makeTemplate()
    readDataFiles(files, template)


def readDataFiles(allFiles, template):
    dataStruct = initializeStruct()
    regex = re.compile("[0-9]+")
    for eachFile in allFiles:
        tempFile = open(sys.argv[1] + "/" + eachFile,"r")
        dataStruct = parseFile(tempFile)
        temp = regex.findall(eachFile)
        dataStruct[7] = temp[0]
        if int(dataStruct[6]) > 70:
            makeWarning(dataStruct,template)
        dataStruct.clear


#Interprets data file into a struct
def parseFile(file):
    struct = initializeStruct()
    regex = re.compile(" ")

    # 0 is deptCode
    # 1 is deptName
    line = file.readline()
    line = line.replace("\n","")
    lineList = regex.split(line)
    struct[0] = lineList[0]
    struct[1] = lineList[1]

    # 2 is courseName
    line = file.readline()
    line = line.replace("\n","")
    struct[2] = line

    # 3 is courseStart
    # 4 is courseEnd
    line = file.readline()
    line = line.replace("\n","")
    lineList = regex.split(line)
    struct[3] = lineList[1]
    struct[4] = lineList[2]

    # 5 is creditHours
    line = file.readline()
    line = line.replace("\n","")
    lineList = regex.split(line)
    struct[5] = lineList[0]

    # 6 is numStudents
    line = file.readline()
    line = line.replace("\n","")
    lineList = regex.split(line)
    struct[6] = lineList[0]
    
    # 7 is courseNum
    regex = re.compile("[0-9]+")
    line = sys.argv[2]
    lineList = regex.findall(line)
    struct[7] = lineList[0]

    # 8 is inputDate
    struct[8] = sys.argv[3]
    
    return struct

# 0 is deptCode
# 1 is deptName
# 2 is courseName
# 3 is courseStart
# 4 is courseEnd
# 5 is creditHours
# 6 is numStudents
# 7 is courseNum
# 8 is inputDate
def makeWarning(struct,template):
    height = len(template)
    i=0
    delim = findDelimiter()
    warningRegex = re.compile(re.escape(delim[0]) + ".*")
    fileName = sys.argv[4] + "/" + struct[0] + struct[7] + ".warn" 

    file = open(fileName,"w")

    while i < height:
        j = 0
        width = len(template[i])
        
        while j < width:
            if warningRegex.match(template[i][j]):
                dataIndex = whichData(template[i][j])
                file.write(struct[dataIndex])
            else:
                file.write(template[i][j])
            j += 1
        file.write("\n")
        i += 1

def whichData(string):
    if re.search(".*dept_code", string):
            return 0
    if re.search(".*course_num", string):
            return 7
    if re.search(".*datestamp", string):
            return 8
    if re.search(".*course_name", string):
            return 2
    if re.search(".*course_start", string):
            return 3
    if re.search(".*course_end", string):
            return 4
    if re.search(".*num_students", string):
            return 6
    if re.search(".*dept_name", string):
            return 1
    if re.search(".*credit_hours", string):
            return 5


def makeWarnDirectory():
    path = sys.argv[4]
    isDir = os.path.isdir(path)

    if isDir == False: 
        os.mkdir(path)

checkArgs()
makeWarnDirectory()
operateFiles()