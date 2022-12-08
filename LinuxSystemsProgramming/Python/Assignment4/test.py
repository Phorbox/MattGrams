import os
import sys
import glob
import re

def checkArgs():
    numArgs = len(sys.argv)
    if numArgs = 4:
        return
    elif numArgs = 6:
        return
    else:
        print("Usage, 4 or 6 arguments as follows: " + sys.argv[0] + "<./dataDirectory> <yourTemplate.template> <date> <./outputDirectory> <'optionalOpeningDelimiter'> <'optionalEndingDelimiter'>")
        return 0

checkArgs()