#!/usr/local/bin/python3

#list = [3,5,7,4,2,8,9,1,6]
list = [55,4,5,665,4,34,64,4,2,6,77,556,7765,8,534,5,63,5345,6]

for i in range(1, len(list)):
	j = i
	temp = list[j]
	while (j > 0) and (temp < list[j-1]):
			list[j] = list[j-1]
			j -= 1
	list[j] = temp
	
print(list)
			
				
