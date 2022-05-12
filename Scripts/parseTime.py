# Parse <time> command with only the real line
# ex: real 0m0,123s -> 123
# Usage
# input File name, example bootime.txt 
# Warning the script is not safe be sure your file as
# the right syntax

import sys

def parse(texte: str) -> int:
	texte = texte.split()
	texte = texte.pop(1)
	texte = texte.split('m')
	texte[1] = texte[1].split(',')
	texte[1][1] = texte[1][1].replace('s','')

	res = 0
	res += int(texte[0])*60
	res += int(texte[1][0])
	res += int(texte[1][1])/1000
	res *= 1000
	
	return int(res)

def main() -> int:
	fileName = input("File name:")
	file = open(fileName, "r")
	fileNameP = fileName + ".parse"
	file_res =  open(fileNameP, "w")

	print("file name:"+fileName)
	print("parse file name:"+fileNameP)
	print("Start parsing")

	for  x in file:
		res = parse(x) 
		file_res.write(str(res)+"\n")

	print("End parsing")


if __name__ == '__main__':
	sys.exit(main())
