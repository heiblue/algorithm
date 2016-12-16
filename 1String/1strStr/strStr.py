#!/usr/local/bin/python3

#s = "source"
#t = "sourceee"

s = input("Give source:")
t = input("Give target:")

def strStr(source, target):
	if source is None or target is None:
		return -1

	for i in range(len(source) - len(target) + 1):
		for j in range(len(target)):
			if (source[i+j] != target[j]):
				break;
		else:
			return i
	return -1


print(strStr(s, t))
  
  
 
  
  
  
  
  
  
  
 
 
